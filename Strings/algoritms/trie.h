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

#endif
