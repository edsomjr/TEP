#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using is = pair<int, string>;

vector<string> fs { "front", "back", "left", "right", "top", "bottom" };

vector<is> solve(int N, const vector<vector<int>>& xs)
{
    vector<vector<int>> lis(N, vector<int>(6, 1));
    vector<vector<ii>> ps(N, vector<ii>(6, ii(0, 0)));

    int size = 1;
    auto best = ii(N - 1, 0);

    for (int i = N - 2; i >= 0; --i)
    {
        for (int t = 0; t < 6; ++t)
        {
            auto b = t % 2 ? t - 1 : t + 1;

            for (int j = i + 1; j < N; ++j)
            {
                for (int s = 0; s < 6; ++s)
                {
                    if (xs[i][b] == xs[j][s] and lis[j][s] + 1 > lis[i][t])
                    {
                        lis[i][t] = lis[j][s] + 1;
                        ps[i][t] = ii(j, s);

                        if (lis[i][t] > size)
                        {
                            size = lis[i][t];
                            best = ii(i, t);
                        }
                    }
                }
            }
        }
    }

    vector<is> ans(size);

    for (int k = 0; k < size; ++k)
    {
        auto [i, s] = best;

        ans[k] = is(i + 1, fs[s]);
        best = ps[i][s];
   }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int N, test = 0;

    while (cin >> N, N)
    {
        vector<vector<int>> xs(N, vector<int>(6));

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < 6; ++j)
                cin >> xs[i][j];

        auto ans = solve(N, xs);

        if (test)
            cout << '\n';

        cout << "Case #" << ++test << '\n';

        cout << ans.size() << '\n';

        for (auto [i, side] : ans)
            cout << i << ' ' << side << '\n';
    }

    return 0;
}
