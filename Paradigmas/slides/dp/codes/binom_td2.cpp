#include <bits/stdc++.h>

using namespace std;

constexpr int MAX { 1'010 };
constexpr long long MOD { 1'000'000'007 };

long long st[2*MAX][MAX];

long long binom(int n, int m)
{
    if (m > n or m < 0)
        return 0;

    if (m > n - m)
        m = n - m;

    if (m == 0 or m == n)
        return 1;

    if (st[n][m] != -1)
        return st[n][m];

    auto res = (binom(n - 1, m) + binom(n - 1, m - 1)) % MOD;

    st[n][m] = res;
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;

    memset(st, -1, sizeof st);

    cout << "binom(" << n << "," << m << ") = " << binom(n, m) << endl;

    return 0;
}
