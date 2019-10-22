#include <bits/stdc++.h>

using namespace std;
using Node = map<char, int>;
using Trie = vector<Node>;

ostream& operator<<(ostream& os, const Trie& trie);

Trie build_online(const string& s)
{
    int next = 0, deepest = 0;  // deepest = v_(k-1)
    string S = s + '#';         // adiciona o terminador
    vector<int> suf { -1 };     // suf[root] = NULL
    Trie trie(1);               // Instancia o nó raiz vazio

    for (size_t i = 0; i < S.size(); ++i)
    {
        // Calculo de Tk, com k = i + 1
        char c = S[i];    
        int u = deepest;

        while (u >= 0)
        {
            // Procura por c no nó u
            auto it = trie[u].find(c);

            // Caso #1: link não encontrado
            if (it == trie[u].end())
            {
                // Adiciona um novo nó, com aresta c
                trie.push_back({ });
                trie[u][c] = ++next;

               // valor sentinela: será corrigido na próxima iteração
                suf.push_back(0);

                if (u != deepest)
                {
                    suf[next - 1] = next;   // correção atrasada
                } else
                    deepest = next;         // v_k é o nó recém-criado
            } else
            {
                // Caso #2: link encontrado: suf[v_t] aponta para ele
                suf[next] = it->second;
                break;
            }

            u = suf[u];     // v_(r-1) = suf[v_r]
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

int main()
{
    string s;
    cin >> s;

    cout << build_online(s) << '\n';

    return 0;
}
