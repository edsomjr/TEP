#include <bits/stdc++.h>

using namespace std;

const int MAX { 52 };

long long st[MAX][MAX][MAX];

long long dp(int k, int a, int b)
{
    if (a < 0 || b < 0)
        return 0;

    if (k == 0)
        return 1;

    if (st[k][a][b] != -1)
        return st[k][a][b];

    auto res = dp(k - 1, a - 1, b) + dp(k - 1, a, b - 1);

    st[k][a][b] = res;
    return res;
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    memset(st, -1, sizeof st);

    cout << dp(k, a, b) << '\n';

    return 0;
}
