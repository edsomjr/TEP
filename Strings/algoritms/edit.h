/**
 * Implementações do algoritmo _edit distance_
 *
 * Autor: Edson Alves
 * Data: 07/03/2017
 * Licença: LGPL. Sem copyright.
 */
#ifndef STRING_EDIT_H
#define STRING_EDIT_H

#include <string>

using namespace std;

#define MAX_M   1001
#define MAX_N   1001

int st[MAX_M][MAX_N], a[MAX_N], b[MAX_N];
int c_i = 1, c_r = 1, c_s = 1;      // Custos iguais a um

// Implementação _bottom-up_, O(mn), memória O(mn)
int edit(const string& s, const string& t)
{
    int m = s.size();
    int n = t.size();

    for (int i = 0; i <= m; ++i)
        st[i][0] = i*c_r;

    for (int j = 1; j <= n; ++j)
        st[0][j] = j*c_i;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int insertion = st[i][j - 1] + c_i;
            int deletion = st[i - 1][j] + c_r; 
            int substution = st[i - 1][j - 1] + c_s * (s[i - 1] == t[j - 1] ? 0 : 1);
            st[i][j] = min(insertion, deletion);
            st[i][j] = min(st[i][j], substution);
        }

    return st[m][n];
}

// Implementação _bottom-up_, O(mn), memória O(n)
int edit2(const string& s, const string& t)
{
    int m = s.size();
    int n = t.size();

    int *prev = a, *line = b;

    for (int j = 0; j <= n; ++j)
        prev[j] = j*c_i;

    for (int i = 1; i <= m; ++i)
    {
        line[0] = i*c_r;

        for (int j = 1; j <= n; ++j)
        {
            int insertion = line[j - 1] + c_i;
            int deletion = prev[j] + c_r; 
            int substution = prev[j - 1] + c_s * (s[i - 1] == t[j - 1] ? 0 : 1);
            line[j] = min(insertion, deletion);
            line[j] = min(line[j], substution);
        }

        swap(line, prev);
    }

    return prev[n];
}

#endif
