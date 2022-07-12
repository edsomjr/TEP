/**
 * Implementações do algoritmo _longest common subsequence - LCS_
 *
 * Autor: Edson Alves
 * Data: 21/03/2017
 * Licença: LGPL. Sem copyright.
 */
#ifndef STRING_LCS_H
#define STRING_LCS_H

#include <sstream>
#include <string>
#include <stack>

using namespace std;

#define MAX_M   1001
#define MAX_N   1001

#define INF 1000000010

int st[MAX_M][MAX_N], a[MAX_N], b[MAX_N];
int c_i = 0, c_r = 0, c_s = 1;      // Custos adaptados
char ps[MAX_M][MAX_N];

// Implementação _bottom-up_, O(mn), memória O(mn)
int lcs(const string& s, const string& t)
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
            int change = st[i - 1][j - 1] + c_s * (s[i - 1] == t[j - 1] ? 1 : -INF);
            st[i][j] = max(insertion, deletion);
            st[i][j] = max(st[i][j], change);
        }

    return st[m][n];
}

// Implementação _bottom-up_, O(mn), memória O(n)
int lcs2(const string& s, const string& t)
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
            int change = prev[j - 1] + c_s * (s[i - 1] == t[j - 1] ? 1 : -INF);
            line[j] = max(insertion, deletion);
            line[j] = max(line[j], change);
        }

        swap(line, prev);
    }

    return prev[n];
}

string lcs_str(const string& s, const string& t)
{
    int m = s.size();
    int n = t.size();

    for (int i = 0; i <= m; ++i)
    {
        st[i][0] = i*c_r;
        ps[i][0] = 'r';
    }

    for (int j = 1; j <= n; ++j)
    {
        st[0][j] = j*c_i;
        ps[0][j] = 'i';
    }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int insertion = st[i][j - 1] + c_i;
            int deletion = st[i - 1][j] + c_r; 
            int change = st[i - 1][j - 1] + c_s * (s[i - 1] == t[j - 1] ? 1 : -INF);

            st[i][j] = max(insertion, deletion);
            st[i][j] = max(st[i][j], change);

            if (insertion >= deletion and insertion >= change)
                ps[i][j] = 'i';
            else if (deletion >= change)
                ps[i][j] = 'r';
            else
                ps[i][j] = 's';
        }

    int i = m, j = n;
    stack<char> S;

    while (i or j)
    {
        switch (ps[i][j]) {
        case 'i':
            --j;
            break;

        case 'r':
            --i;
            break;

        case 's':
            if (s[i-1] == t[j-1])
                S.push(s[i-1]);

            --i;
            --j;
        }
    }

    ostringstream os;

    while (not S.empty())
    {
        os << S.top();
        S.pop();
    }

    return os.str();
}

#endif
