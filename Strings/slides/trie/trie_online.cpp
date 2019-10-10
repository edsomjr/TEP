#include <bits/stdc++.h>

using namespace std;
using Node = map<char, int>;
using Trie = vector<Node>;

ostream& operator<<(ostream& os, const Trie& trie);

Trie build_online(const string& s)
{
    int next = 0, deepest = 0;              // deepest = v_(k-1)
    string S = s + '#';                     // adiciona o terminador
    vector<int> suf { -1 };                 // suf[root] = NULL
    Trie trie(1);                           // Instancia o nó raiz vazio

    for (size_t i = 0; i < S.size(); ++i)
    {
cout << "=============\n";
cout << "i = " << i << ", k = " << i + 1 << '\n';
        // Calculo de Tk, com k = i + 1
        char c = S[i];    
        int u = deepest;

        while (u >= 0)
        {
cout << "c = " << c << ", u = " << u << '\n';
            // Procura por c no nó u
            auto it = trie[u].find(c);

            if (it == trie[u].end())
            {
cout << "Caso #1: link não encontrado\n";
                // Adiciona um novo nó, com aresta c
                trie.push_back({ });
                trie[u][c] = ++next;
                suf.push_back(0);               // lazy: será corrigido no próximo loop

                if (u != deepest)
                {
                    suf[next - 1] = next;       // correção atrasada delayed 
                } else
                    deepest = next;             // v_k é o nó recém-criado
cout << "-> novo nó criado (" << next << "), deepest = " << deepest << ", suf[" << next - 1 << "] = " << (next - 1 >= 0 ? suf[next - 1] : -1) << '\n';
            } else
            {
cout << "Caso #2: link encontrado\n";
                // Corner case: se s[k] é encontrado, suf[v_t] aponta para ele
                suf[next] = it->second;
cout << "-> suf[" << next << "] = " << suf[next] << '\n';
                break;
            }

            u = suf[u];                         // v_(r-1) = suf[v_r]
//break;
        }
cout << trie << '\n';
cout << "suf = ";
for (auto x : suf)
    cout << x << ' ';
cout << '\n';

        if (i == 2)
            break;
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

int main()
{
    string s;
    cin >> s;

    build_online(s);

    return 0;
}
