#include <bits/stdc++.h>

using namespace std;
using Node = map<char, int>;
using Trie = vector<Node>;

Trie build_naive(const string& s)
{
    int root = 0, next = 0;

    Trie trie(1);       // Instancia o nó raiz vazio

    for (int i = s.size() - 1; i >= 0; --i)
    {
        string suffix = s.substr(i);
        int v = root;

        for (auto c : suffix)
        {
            auto it = trie[v].find(c);

            if (it != trie[v].end())
            {
                v = it->second;
            } else
            {
                trie.push_back({ });
                trie[v][c] = ++next;
                v = next;
            }
        }
    }

    return trie;
}

ostream& operator<<(ostream& os, const Trie& trie)
{
    using cii = tuple<char, char, int, int>;

    queue<cii> q;
    q.push(cii('-', '-', 0, 0));
    int level = 0;

    while (not q.empty())
    {
        auto [c, p, n, l] = q.front();
        q.pop();

        if (l > level)
        {
            os << '\n';
            level = l;
        }

        os << "[" << n << ", " << c << " (" << p << ")] ";

        if (c != '#')
            for (const auto& p : trie[n])
                q.push(cii(p.first, c, p.second, l + 1));
    }

    return os;
}

bool search(const Trie& trie, const string& s)
{
    int v = 0;

    for (auto c : s)
    {
        auto it = trie[v].find(c);

        if (it == trie[v].end())
            return false;

        v = it->second;
    }

    return true;
}

Trie build_naive_with_marker(const string& s)
{
    int root = 0, next = 0;

    Trie trie(1);       // Instancia o nó raiz vazio

    for (int i = s.size() - 1; i >= 0; --i)
    {
        string suffix = s.substr(i) + '#';
        int v = root;

        for (auto c : suffix)
        {
            if (c == '#')
            {
                trie[v][c] = i;
                break;
            }

            auto it = trie[v].find(c);

            if (it != trie[v].end())
            {
                v = it->second;
            } else
            {
                trie.push_back({ });
                trie[v][c] = ++next;
                v = next;
            }
        }
    }

    return trie;
}

int main()
{
    string s;
    cin >> s;

/*    auto trie = build_naive(s);
    cout << trie << '\n';

    string p;
    cin >> p;

    cout << p << " é substring de " << s << "? " << search(trie, p) << '\n';
*/
    auto trie2 = build_naive_with_marker(s);
    cout << trie2 << '\n';


    return 0;
}
