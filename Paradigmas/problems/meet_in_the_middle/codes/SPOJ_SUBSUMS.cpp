#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> subset_sum(const vector<ll>& xs)
{
    vector<ll> s;

    for (size_t i = 0; i < (1ul << xs.size()); ++i) {
        ll sum = 0;

        for (size_t j = 0; j < xs.size(); ++j)
            if ((1 << j) & i)
                sum += xs[j];

       s.push_back(sum);
    }

    return s;
}

ll solve(ll N, ll A, ll B, const vector<ll>& xs)
{
    vector<ll> g1(xs.begin(), xs.begin() + N/2);
    vector<ll> g2(xs.begin() + N/2, xs.end());

    auto s1 = subset_sum(g1), s2 = subset_sum(g2);
    sort(s2.begin(), s2.end());

    ll ans = 0;

    for (auto s : s1)
    {
        auto it = lower_bound(s2.begin(), s2.end(), A - s);
        auto jt = upper_bound(s2.begin(), s2.end(), B - s);
        ans += (jt - it);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    ll N, A, B;
    cin >> N >> A >> B;

    vector<ll> xs(N);

    for (ll i = 0; i < N; ++i)
        cin >> xs[i];

    cout << solve(N, A, B, xs) << endl;

    return 0;
}

