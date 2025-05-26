#include <bits/stdc++.h>

using namespace std;

constexpr int MAX { 2'010 };
constexpr long long MOD { 1'000'000'007 };

long long a[MAX], b[MAX];

long long binom(int n, int m)
{
    long long *prev = a, *next = b;

    prev[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        next[0] = next[i] = 1;

        for (int j = 1; j < n; ++j)
            next[j] = (prev[j] + prev[j - 1]) % MOD;

        swap(prev, next);
    }

    return prev[m];
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << "binom(" << n << "," << m << ") = " << binom(n, m) << endl;

    return 0;
}
