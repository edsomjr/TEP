/**
 * Implementações do algoritmo _edit distance_
 *
 * Autor: Edson Alves
 * Data: 07/03/2017
 * Licença: LGPL. Sem copyright.
 */
#ifndef STRING_EDIT_H
#define STRING_EDIT_H

#include <sstream>
#include <string>
#include <stack>

using namespace std;

#define MAX_M   1001
#define MAX_N   1001

int st[MAX_M][MAX_N], a[MAX_N], b[MAX_N];
int c_i = 1, c_r = 1, c_s = 1;      // Custos iguais a um
char ps[MAX_M][MAX_N];

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
            int change = st[i - 1][j - 1] + c_s * (s[i - 1] == t[j - 1] ? 0 : 1);
            st[i][j] = min(insertion, deletion);
            st[i][j] = min(st[i][j], change);
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
            int change = prev[j - 1] + c_s * (s[i - 1] == t[j - 1] ? 0 : 1);
            line[j] = min(insertion, deletion);
            line[j] = min(line[j], change);
        }

        swap(line, prev);
    }

    return prev[n];
}

// x        Deletion
// c        Insertion of char c
// -        Keep
// [c->d]   Change (c to d)
string edit_operations(const string& s, const string& t)
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
            int change = st[i - 1][j - 1] + c_s * (s[i - 1] == t[j - 1] ? 0 : 1);

            st[i][j] = min(insertion, deletion);
            st[i][j] = min(st[i][j], change);

            if (insertion <= deletion and insertion <= change)
                ps[i][j] = 'i';
            else if (deletion <= change)
                ps[i][j] = 'r';
            else
                ps[i][j] = 's';
        }

    int i = m, j = n;
    stack<string> S;
    char buffer[128];
    string subs = "[x->y]";

    while (i or j)
    {
        switch (ps[i][j]) {
        case 'i':
            sprintf(buffer, "%c", t[j - 1]);
            --j;
            break;

        case 'r':
            sprintf(buffer, "x");
            --i;
            break;

        case 's':
            if (s[i-1] == t[j-1])
                sprintf(buffer, "-");
            else
                sprintf(buffer, "[%c->%c]", s[i - 1], t[j - 1]);

            --i;
            --j;
        }

        S.push(buffer);
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
