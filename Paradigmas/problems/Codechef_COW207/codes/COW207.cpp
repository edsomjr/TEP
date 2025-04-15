#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
const int oo { 2'000'000'010 };

int solve(int N, const vector<int>& xs)
{
    vector<ii> ps(N);

    for (int i = 0; i < N; ++i)
        ps[i] = ii(xs[i], i);

    sort(ps.begin(), ps.end(), greater<ii>());

    auto L = oo, R = -oo, ans = 0;

    for (auto p : ps)
    {
        auto [x, i] = p;

        if (L < i)
            ans = max(ans, (i - L)*min(x, xs[L]));

        if (R > i)
            ans = max(ans, (R - i)*min(x, xs[R]));

        L = min(L, i);
        R = max(R, i);
    }

   return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> xs(N);

        for (int i = 0; i < N; ++i)
            cin >> xs[i];

        auto ans = solve(N, xs);

        cout << ans << '\n';
    }

    return 0;
}
