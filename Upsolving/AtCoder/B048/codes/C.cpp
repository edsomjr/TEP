#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(int N, ll x, vector<ll>& xs)
{
    ll ans = 0;

    for (int i = 1; i < N; ++i)
    {
        auto sum = xs[i] + xs[i - 1];
        auto diff = max(0LL, sum - x);

        ans += diff;
        xs[i] -= min(diff, xs[i]);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, x;
    cin >> N >> x;

    vector<ll> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, x, xs);

    cout << ans << '\n';

    return 0;
}
