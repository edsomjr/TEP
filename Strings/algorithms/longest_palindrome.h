/**
 * Implementações do algoritmo _longest palindrome_
 *
 * Determina o maior palíndromo que pode ser obtido de s removendo 0 ou mais
 * caracteres.
 *
 * Autor: Edson Alves
 * Data: 21/03/2017
 * Licença: LGPL. Sem copyright.
 */
#ifndef STRING_LONGEST_PALINDROME_H
#define STRING_LONGEST_PALINDROME_H

#include <sstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define MAX_N   1001

int st[MAX_N][MAX_N];
char ps[MAX_N][MAX_N];

// Implementação top-down O(n^2), memória O(n^2)
int lp_dp(const string& s, int i, int j)
{
    if (i > j)
    {
        ps[j][i] = 'f';
        return 0;
    }

    if (i == j)
    {
        ps[i][j] = 'f';
        return 1;
    }

    if (st[i][j] != -1)
        return st[i][j];

    int res = max(lp_dp(s, i + 1, j), lp_dp(s, i, j - 1));

    if (lp_dp(s, i + 1, j) >= lp_dp(s, i, j - 1))
        ps[i][j] = '+';
    else
        ps[i][j] = '-';

    if (s[i] == s[j])
        res = max(res, lp_dp(s, i + 1, j - 1) + 2);

    if (s[i] == s[j] and lp_dp(s, i + 1, j - 1) + 2 >= res)
        ps[i][j] = 'k';

    st[i][j] = res;

    return res;
}

// Implementação _top-down_, O(mn), memória O(mn)
int longest_palindrome(const string& s)
{
    int n = s.size();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        st[i][j] = -1;

    return lp_dp(s, 0, n - 1);
}

// Implementação _top-down_, O(mn), memória O(mn)
string longest_palindrome_str(const string& s)
{
    int n = s.size();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        st[i][j] = -1;

    lp_dp(s, 0, n - 1);

    int i = 0, j = n - 1;
    vector<char> v;
    stack<char> S;

    while (i <= j)
    {
        switch (ps[i][j]) {
        case '+':
            ++i;
            break;

        case '-':
            --j;
            break;

        case 'k':
            v.push_back(s[i]);
            S.push(s[i]);
            ++i;
            --j;
            break;

        case 'f':
            v.push_back(s[i]);

            i++;
            --j;
            break;
        }
    }

    ostringstream os;

    for (auto c : v)
        os << c;

    while (not S.empty())
    {
        os << S.top();
        S.pop();
    }

    return os.str();
}

#endif
