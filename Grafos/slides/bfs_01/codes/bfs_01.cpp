#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 10010 };
const int oo { 1000000010 };

vector<ii> adj[MAX];

vector<int> bfs_01(int s, int N) {
    vector<int> dist(N + 1, oo);
    dist[s] = 0;

    deque<int> q;
    q.emplace_back(s);

    while (not q.empty()) {
        auto u = q.front();
        q.pop_front();

        for (auto [v, w] : adj[u])
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                w == 0 ? q.emplace_front(v) : q.emplace_back(v);
            }
    }

    return dist;
}

int main()
{
    vector<edge> edges { { 1, 2, 0 }, { 1, 4, 1 }, { 1, 6, 1 }, { 1, 7, 0 },
        { 2, 3, 0 }, { 2, 7, 1 }, { 3, 4, 0 }, { 5, 4, 1 }, { 5, 7, 1 },
        { 6, 5, 1 }, { 7, 6, 1 } };

    for (auto [u, v, w] : edges)
        adj[u].emplace_back(v, w);

    auto dist = bfs_01(1, 7);

    for (int u = 1; u <= 7; ++u)
        cout << "Distância minima de 1 a " << u << ": " << dist[u] << '\n';

    return 0;
} 
