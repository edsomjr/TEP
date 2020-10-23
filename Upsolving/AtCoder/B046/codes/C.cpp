#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

ll solve(int N, const vector<ii>& xs)
{
    ll T1 = xs.front().first, A1 = xs.front().second;

    for (int i = 1; i < N; ++i)
    {
        auto T2 = xs[i].first, A2 = xs[i].second;
        auto k = max((T1 + T2 - 1)/T2, (A1 + A2 - 1)/A2);

        T1 = k*T2;
        A1 = k*A2;
    }

    return T1 + A1;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ii> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i].first >> xs[i].second;

    auto ans = solve(N, xs);

    cout << ans << '\n';

    return 0;
}
