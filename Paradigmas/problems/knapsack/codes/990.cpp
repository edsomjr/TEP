#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

pair<int, vector<int>> solve(int T, int W, int N, vector<ii>& cs)
{
    vector<vector<int>> st(N + 1, vector<int>(T + 1, 0));
    vector<vector<int>> ps(N + 1, vector<int>(T + 1, -1));

    for (int i = 1; i <= N; ++i)
        cs[i].first *= 3*W;

    for (int i = 1; i <= N; ++i)
    {
        for (int t = 1; t <= T; ++t)
        {
            st[i][t] = st[i - 1][t];
            ps[i][t] = 0;

            auto [d, v] = cs[i];

            if (d <= t and st[i - 1][t - d] + v > st[i][t])
            {
                st[i][t] = st[i - 1][t - d] + v;
                ps[i][t] = 1;
            }
        }
    }

    int t = T;
    vector<int> is;

    for (int i = N; i >= 1; --i)
    {
        if (ps[i][t])
        {
            is.push_back(i);
            t -= cs[i].first;
        }
    }

    reverse(is.begin(), is.end());

    return { st[N][T], is };
}

int main()
{
    ios::sync_with_stdio(false);

    int T, W, first = 1;

    while (cin >> T >> W)
    {
        int N;
        cin >> N;

        vector<ii> cs(N + 1);

        for (int i = 1; i <= N; ++i)
            cin >> cs[i].first >> cs[i].second;

        auto [ans, is] = solve(T, W, N, cs);

        if (not first)
            cout << '\n';

        cout << ans << '\n';
        cout << is.size() << '\n';

        for (auto i : is)
            cout << cs[i].first / (3*W) << ' ' << cs[i].second << '\n';

        first = 0;
    }

    return 0;
}
