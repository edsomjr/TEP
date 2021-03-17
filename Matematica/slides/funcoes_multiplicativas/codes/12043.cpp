#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 100010 };

pair<vector<ll>, vector<ll>> tau_and_sigma(ll N)
{
    vector<ll> tau(N + 1, 1), sigma(N + 1, 1);

    for (ll m = 2; m <= N; ++m)
    {
        tau[m] = 2;
        sigma[m] = m + 1;
    }

    for (ll d = 2; d <= N; ++d)
    {
        for (ll m = d*d; m <= N; m += d)
        {
            ll k = m / d;

            tau[m] += (d == k ? 1 : 2);
            sigma[m] += (d == k ? d : d + k);
        }
    }

    return { tau, sigma };
}

pair<ll, ll>
solve(int a, int b, int k, const vector<ll>& tau, const vector<ll>& sigma)
{
    int t = (a + k - 1)/k, m = k*t;
    ll x = 0, y = 0;

    for (int i = m; i <= b; i += k)
    {
        x += tau[i];
        y += sigma[i];
    }

    return { x, y };
}

int main()
{
    auto [tau, sigma] = tau_and_sigma(100000);

    int T;
    cin >> T;

    while (T--)
    {
        int a, b, k;
        cin >> a >> b >> k;

        auto [x, y] = solve(a, b, k, tau, sigma);

        cout << x << ' ' << y << '\n';
    }
    
    return 0;
}
