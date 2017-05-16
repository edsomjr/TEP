/**
 * Implementação da Trie (Retrievel Tree).
 *
 * Autor: Edson Alves
 * Data: 27/04/2017
 * Licença: LGPL. Sem copyright.
 */
#ifndef STRING_TRIE_H
#define STRING_TRIE_H

#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define MAX 1000010

map<char, int> trie[MAX];

void build_naive(const string& s)
{
    for (int i = 0; i < MAX; ++i)
        trie[i].clear();

    int root = 0, next = 0;

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
            }else
            {
                trie[v][c] = ++next;
                v = next;
            }
        }
    }
}

bool trie_search(const string& s)
{
    int v = 0;
    size_t pos = 0;

    while (pos < s.size())
    {
        auto it = trie[v].find(s[pos]);

        if (it == trie[v].end())
            return false;

        ++pos;
        v = it->second;
    }

    return true;
}


void build_naive_with_marker(const string& s)
{
    for (int i = 0; i < MAX; ++i)
        trie[i].clear();

    int root = 0, next = 0;

    for (int i = s.size() - 1; i >= 0; --i)
    {
        string suffix = s.substr(i) + "#";
        int v = root;

        for (auto c : suffix)
        {
            if (c == '#')
            {
                trie[v]['#'] = i;
                break;
            }

            auto it = trie[v].find(c);

            if (it != trie[v].end())
            {
                v = it->second;
            }else
            {
                trie[v][c] = ++next;
                v = next;
            }
        }
    }
}

vector<int> trie_search_positions(const string& s)
{
    int v = 0;
    size_t pos = 0;
    vector<int> positions;

    while (pos < s.size())
    {
        auto it = trie[v].find(s[pos]);

        if (it == trie[v].end())
            return positions;

        ++pos;
        v = it->second;
    }

    queue<int> q;
    q.push(v);

    while (not q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto p : trie[u])
        {
            auto c = p.first;
            auto v = p.second;

            if (c == '#')
                positions.push_back(v);
            else
                q.push(v);
        }
    }

    return positions;
}

size_t unique_substrings()
{
    queue<int> q;
    q.push(0);
    int count = 0;

    while (not q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto p : trie[u])
        {
            auto c = p.first;
            auto v = p.second;

            if (c != '#')
            {
                ++count;
                q.push(v);
            }
        }
    }    

    return count;
}

void build_online(const string& s)
{
    for (int i = 0; i < MAX; ++i)
        trie[i].clear();

    int root = 0, next = 0, deepest = 0;
    string S = s + '#';
    vector<int> suf { -1 };

    for (size_t i = 0; i < S.size(); ++i)
    {
        int c = S[i];
        int u = deepest;

//        printf("-- new trie (%s) (deepest = %d):\n", S.substr(0, i + 1).c_str(), u);

        while (u >= 0)
        {
            auto it = trie[u].find(c);

            if (it == trie[u].end())
            {
                trie[u][c] = ++next;
//printf("'%c' not in %d: creating a new node %d\n", c, u, next);
                suf.push_back(0);       // lazy: will be corrected in next loop

                if (u != deepest)
                {
//printf("updating suffix of node %d to %d\n", next - 1, next);
                    suf[next - 1] = next;
                } else
                    deepest = next;
            } else
            {
//printf("'%c' found in %d: updating suffix of %d to %d\n", c, u, next, it->second);
                suf[next] = it->second;
                break;
            }

            u = suf[u];
//printf("advancing to u = %d\n", u);
        }

 /*       printf("suf = ");
        for (size_t v = 0; v < suf.size(); ++v)
            printf("%3lu", v);

        printf("\n      ");
        for (size_t v = 0; v < suf.size(); ++v)
            printf("%3d", suf[v]);

        printf("\nvks = ");
        for (int v = i + 1; v >= 0; --v)
            printf("%3lu", v);

        printf("\n      ");
        u = deepest;
        for (size_t v = 0; v <= i + 1; ++v)
        {
            printf("%3d", u);
            u = suf[u];
        }

        printf("\nnodes: \n");
        for (size_t v = 0; v <= next; ++v)
            for (auto p : trie[v])
                printf("node %d: (%c, %d)\n", v, p.first, p.second);
    */
    }        
}


#endif

