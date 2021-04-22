#include <bits/stdc++.h>

using namespace std;

struct Point { int x, y; };

struct Answer {
    double min_dist;
    vector<int> ps;
    vector<vector<double>> dist;
};

Answer solve(int N, const vector<Point>& ps) {
    vector<vector<double>> dist(N, vector<double>(N));
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dist[i][j] = hypot(ps[i].x - ps[j].x, ps[i].y - ps[j].y) + 16.0;

    vector<int> is(N), ans;
    iota(is.begin(), is.end(), 0);

    double min_dist = 1e30;

    do {
        double d = 0.0;

        for (int i = 1; i < N; ++i)
            d += dist[is[i - 1]][is[i]];

        if (d < min_dist)
        {
            min_dist = d;
            ans = is;
        } 
    } while (next_permutation(is.begin(), is.end()));

    return { min_dist, ans, dist };
}

int main()
{
    ios::sync_with_stdio(false);

    int N, test = 0;

    while (cin >> N, N)
    {
        vector<Point> ps(N);

        for (int i = 0; i < N; ++i)
            cin >> ps[i].x >> ps[i].y;
    
        auto [min_dist, ans, dist] = solve(N, ps);

        cout << "**********************************************************\n";
        cout << "Network #" << ++test << '\n';

        for (int i = 1; i < N; ++i)
        {
            double d = dist[ans[i - 1]][ans[i]];

            cout << "Cable requirement to connect (" << ps[ans[i - 1]].x << "," << ps[ans[i - 1]].y
                << ") to (" << ps[ans[i]].x << "," << ps[ans[i]].y << ") is " << setprecision(2)
                << fixed << d << " feet.\n";
        }

        cout << "Number of feet of cable required is " << fixed << min_dist << ".\n";
    }

    return 0;
}
