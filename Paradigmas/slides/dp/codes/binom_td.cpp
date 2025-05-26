#include <bits/stdc++.h>

using namespace std;
constexpr int MAX { 1'010 };

long long st[MAX][MAX];

long long binom(int n, int m)
{
    if (m > n) return 0;

    if (m == 0 or m == n) return 1;

    if (st[n][m] != -1)
        return st[n][m];

    st[n][m] = binom(n - 1, m) + binom(n - 1, m - 1);

    return st[n][m];
}

int main()
{
    int n, m;
    cin >> n >> m;

    memset(st, -1, sizeof st);

    cout << "binom(" << n << "," << m << ") = " << binom(n, m) << endl;

    return 0;
}
