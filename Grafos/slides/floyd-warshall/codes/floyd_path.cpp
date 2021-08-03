#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int oo { 1000000010 }, MAX { 200010 };
vector<ii> adj[MAX];

pair<vector<vector<int>>, vector<vector<int>>>
floyd_warshall(int N)
{
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, oo));
    vector<vector<int>> pred(N + 1, vector<int>(N + 1, oo));

    for (int u = 1; u <= N; ++u)
    {
        dist[u][u] = 0;
        pred[u][u] = u;
    }

    for (int u = 1; u <= N; ++u)
        for (auto [v, w] : adj[u]) {
            dist[u][v] = w;
            pred[u][v] = u;
        }

    for (int k = 1; k <= N; ++k)
    {
        for (int u = 1; u <= N; ++u)
        {
            for (int v = 1; v <= N; ++v)
            {
                if (dist[u][k] < oo and dist[k][v] < oo 
                    and dist[u][v] > dist[u][k] + dist[k][v]) {
                        dist[u][v] = dist[u][k] + dist[k][v];
                        pred[u][v] = pred[k][v];
                }
            }
        }
    }

    return { dist, pred };
}

vector<ii> path(int u, int v, const vector<vector<int>>& pred)
{
    vector<ii> p;

    do {
        p.push_back(ii(pred[u][v], v));
        v = pred[u][v];
    } while (v != u);

    reverse(p.begin(), p.end());

    return p;
}

int main() {
    vector<edge> edges { edge(1, 2, 9), edge(1, 3, 7), edge(1, 4, 4), 
        edge(1, 5, 2), edge(2, 3, 1), edge(2, 6, 3), edge(3, 4, 2),
        edge(4, 5, 1), edge(5, 6, 11) };

    int N = 6;

    for (const auto& [u, v, w] : edges) {
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    auto [dist, pred] = floyd_warshall(N);

    for (int u = 1; u <= N; ++u)
    {
        for (int v = 1; v <= N; ++v)
        {
            auto p = path(u, v, pred);

            cout << "dist[" << u << "][" << v << "] = " << dist[u][v] 
                << '\n';

            for (size_t i = 0; i < p.size(); ++i)
                cout << "(" << p[i].first << ", " << p[i].second << ")" << (i + 1 == p.size() ? "\n" : " -> ");
        }
    }

    return 0;
} 
