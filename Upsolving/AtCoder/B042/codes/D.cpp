#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fast_exp(ll a, ll n, ll m)
{
    ll res = 1, base = a;

    while (n)
    {
        if (n & 1)
            res = (res * base) % m;

        base = (base * base) % m;
        n >>= 1;
    }

    return res;
}

const ll MOD { 1000000007 };
const int MAX { 200010 };

ll fact[MAX], inv[MAX];

ll binom(int n, int m)
{
    ll res = (fact[n] * inv[m]) % MOD;
    return (res * inv[n - m]) % MOD;
}

void precomp()
{
    fact[0] = inv[0] = 1;

    for (int n = 1; n < MAX; ++n)
        fact[n] = (n * fact[n - 1]) % MOD;

    for (int n = 1; n < MAX; ++n)
        inv[n] = fast_exp(fact[n], MOD - 2, MOD);
}

ll solve(int H, int W, int A, int B)
{
    ll ans = 0;

    for (int x = B + 1; x <= W; ++x)
    {
        auto m1 = x - 1, n1 = H - A - 1;
        auto m2 = W - x + 1 - 1, n2 = A - 1;
        auto ways = (binom(m1 + n1, m1) * binom(m2 + n2, m2)) % MOD;

        ans = (ans + ways) % MOD;
    }

    return ans;
}

int main()
{
    precomp();

    int H, W, A, B;
    cin >> H >> W >> A >> B;

    auto ans = solve(H, W, A, B);

    cout << ans << '\n';

    return 0;
}
