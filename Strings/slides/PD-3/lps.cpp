#include <bits/stdc++.h>

using namespace std;

const int MAX { 1001 };
int st[MAX][MAX];

int dp(const string& s, int i, int j)
{
    if (i > j)
        return 0;

    if (i == j)
        return 1;

    if (st[i][j] != -1)
        return st[i][j];

    st[i][j] = max(dp(s, i + 1, j), dp(s, i, j - 1));

    if (s[i] == s[j])
        st[i][j] = max(st[i][j], dp(s, i + 1, j - 1) + 2);

    return st[i][j];
}

int lps(const string& s)
{
    memset(st, -1, sizeof st);

    return dp(s, 0, s.size() - 1);
}

int main()
{
    string s;
    cin >> s;

    cout << lps(s) << '\n';

    return 0;
}
