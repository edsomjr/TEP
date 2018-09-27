#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 100010 }, oo { 1000000010 };
int dist[MAX];
vector<ii> adj[MAX];
bitset<MAX> processed;

void dijkstra(int s, int N)
{
    for (int i = 1; i <= N; ++i)
        dist[i] = oo;

    dist[s] = 0;
    processed.reset();

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));

    while (not pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (processed[u])
            continue;

        processed[u] = true;

        for (const auto& [v, w] : adj[u])
        {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push(ii(dist[v], v));
            }
        }
    }
}

int main()
{
    vector<edge> edges { edge(1, 2, 9), edge(1, 3, 7), edge(1, 4, 4), 
        edge(1, 5, 2), edge(2, 3, 1), edge(2, 6, 3), edge(3, 4, 2),
        edge(4, 5, 1), edge(5, 6, 11) };

    for (const auto& [u, v, w] : edges)
    {
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    dijkstra(1, 6);

    for (int u = 1; u <= 6; ++u)
        cout << "Distância minima de 1 a " << u << ": " << dist[u] << '\n';

    return 0;
} 
