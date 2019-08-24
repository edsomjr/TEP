#include <bits/stdc++.h>

using namespace std;

const int MAX_M { 1000 }, MAX_N { 1000 };

int st[MAX_M + 1][MAX_N + 1];

int edit(const string& s, const string& t)
{
    const int c_i = 1, c_r = 1, c_s = 1;      // Custos iguais a um
    int m = s.size(), n = t.size();

    for (int i = 0; i <= m; ++i)
        st[i][0] = i*c_r;

    for (int j = 1; j <= n; ++j)
        st[0][j] = j*c_i;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            int insertion = st[i][j - 1] + c_i;
            int deletion = st[i-1][j] + c_r;
            int change = st[i-1][j-1] + c_s*(s[i-1] == t[j-1] ? 0 : 1);
            st[i][j] = min({ insertion, deletion, change });
        }

    return st[m][n];
}

int main()
{
    string s { "TEP" }, t { "ACCEPTED" };

    cout << edit(s, t) << '\n';

    for (size_t i = 0; i <= s.size(); i++)
    {
        for (size_t j = 0; j <= t.size(); j++)
            printf("%4d", st[i][j]);

        printf("\n");
    }

    return 0;
}
