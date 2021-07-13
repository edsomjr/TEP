#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 210 }, oo { 1000000010 };
double dist[MAX][MAX];

double solve(int N, const vector<ii>& ps) {
    for (int i = 1; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j)
        {
            auto [x, y] = ps[i];
            auto [a, b] = ps[j];

            dist[i][j] = dist[j][i] = hypot(x - a, y - b);
        }

    vector<double> jump(N + 1, oo);
    jump[1] = 0.0;

    for (int k = 1; k <= N - 1; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                jump[j] = min(jump[j], max(jump[i], dist[i][j]));

    return jump[2];
}

int main()
{
    ios::sync_with_stdio(false);

    int N, test = 0;

    while (cin >> N, N)
    {
        vector<ii> ps(N + 1);

        for (int i = 1; i <= N; ++i)
            cin >> ps[i].first >> ps[i].second;

        auto ans = solve(N, ps);

        cout << "Scenario #" << ++test << '\n';
        cout << "Frog Distance = " << setprecision(3) << fixed << ans << "\n\n";
    }

    return 0;
}
