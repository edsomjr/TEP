#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 10000010 };

vector<ll> factors(ll N)
{
    bitset<MAX> sieve;
    vector<ll> fs(N + 1, 1);

    sieve.set();

    for (ll i = 2; i <= N; i++)
        if (sieve[i])
            for (ll j = i; j <= N; j += i)
            {
                sieve[j] = false;
                fs[j] = max(fs[j], i);
            }

    return fs;
}

vector<ll> divisors(ll N, const vector<ll>& fs)
{
    vector<ll> tau(N + 1, 1);

    for (ll n = 2; n <= N; ++n)
    {
        ll k = 0, m = n;

        for (auto p = fs[i]; m % p == 0; ++k, m /= p);

        tau[n] = (k + 1)*tau[m];
    }

    return tau;
}

ll solve(ll N)
{
    auto fs = factors(N);
    auto tau = divisors(N, fs);
    ll ans = 0;

    for (ll K = 1; K <= N; ++K)
        ans += (K * tau[K]);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    auto ans = solve(N);

    cout << ans << '\n';

    return 0;
}
