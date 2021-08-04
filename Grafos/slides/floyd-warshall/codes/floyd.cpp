#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 210 }, oo { 1000000010 };
int dist[MAX][MAX];
vector<ii> adj[MAX];

vector<vector<int>> floyd_warshall(int N)
{
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, oo));

    for (int u = 1; u <= N; ++u)
        dist[u][u] = 0;

    for (int u = 1; u <= N; ++u)
        for (auto [v, w] : adj[u])
            dist[u][v] = w;

    for (int k = 1; k <= N; ++k)
        for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                if (dist[u][k] < oo and dist[k][v] < oo)
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);

    return dist;
}

int main() {
    vector<edge> edges { edge(1, 2, 9), edge(1, 3, 7), edge(1, 4, 4), 
        edge(1, 5, 2), edge(2, 3, 1), edge(2, 6, 3), edge(3, 4, 2),
        edge(4, 5, 1), edge(5, 6, 11) };

    for (const auto& [u, v, w] : edges) {
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    floyd_warshall(6);

    return 0;
} 
