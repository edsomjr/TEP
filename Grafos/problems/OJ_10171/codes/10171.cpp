#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int oo { 1000000010 }, MAX { 26 };

vector<vector<int>> floyd_warshall(int N, const vector<edge>& edges)
{
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, oo));

    for (const auto& [u, v, w] : edges)
        dist[u][v] = w;

    for (int u = 0; u < N; ++u)
        dist[u][u] = 0;

    for (int k = 0; k < N; ++k)
        for (int u = 0; u < N; ++u)
            for (int v = 0; v < N; ++v)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);

    return dist;
}

vector<int>
solve(int m, int r, const vector<edge>& ys, const vector<edge>& ms)
{
    auto distM = floyd_warshall(MAX, ys);
    auto distS = floyd_warshall(MAX, ms);

    int min_cost = oo;
    vector<int> ans;

    for (int u = 0; u < MAX; ++u)
    {
        if (distM[r][u] == oo or distS[m][u] == oo)
            continue;

        auto cost = distM[r][u] + distS[m][u];

        if (cost > min_cost)
            continue;

        if (cost == min_cost)
            ans.push_back(u);
        else
        {
            min_cost = cost;
            ans = vector<int> { min_cost, u };
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N, N)
    {
        vector<edge> ms, ys;

        while (N--)
        {
            string type, dir, x, y;
            int w;
            cin >> type >> dir >> x >> y >> w; 

            auto u = x[0] - 'A', v = y[0] - 'A';

            if (type == "Y")
            {
                ys.push_back(edge(u, v, w));

                if (dir == "B")
                    ys.push_back(edge(v, u, w));
            } else
            {
                ms.push_back(edge(u, v, w));

                if (dir == "B")
                    ms.push_back(edge(v, u, w));
            }
        }

        string M, R;
        cin >> M >> R;

        auto m = M[0] - 'A', r = R[0] - 'A';
        auto ans = solve(m, r, ys, ms);

        if (ans.empty())
            cout << "You will never meet.\n";
        else
        {
            cout << ans.front() << " ";

            for (size_t i = 1; i < ans.size(); ++i)
                cout << (char) (ans[i] + 'A') << (i + 1 == ans.size() ? '\n' : ' ');
        }
    }
    
    return 0;
} 
