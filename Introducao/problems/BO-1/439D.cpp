#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll oo { 1000000010LL };

ll f(ll x, const vector<ll>& as, const vector<ll>& bs)
{
    ll y = 0;

    for (const auto& a : as)
        y += (a < x ? x - a : 0);

    for (const auto& b : bs)
        y += (b > x ? b - x : 0);

    return y;
}

ll solve(const vector<ll>& as, const vector<ll>& bs)
{
    // f(x) é convexa: busca ternária
    ll a = 0, b = oo, ans = 2000000000000000010L;
    
    while (a <= b)
    {
        auto m1 = a + (b - a)/3;
        auto m2 = b - (b - a)/3;

        auto y1 = f(m1, as, bs), y2 = f(m2, as, bs);

        ans = min(ans, y1);
        ans = min(ans, y2);

        y1 > y2 ? a = m1 + 1 : b = m2 - 1;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<ll> as(N), bs(M);

    for (int i = 0; i < N; ++i)
        cin >> as[i];

    for (int j = 0; j < M; ++j)
        cin >> bs[j];

    auto ans = solve(as, bs);

    cout << ans << '\n';

    return 0;
}
