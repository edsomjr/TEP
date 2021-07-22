#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 100010 }, oo { 1000000010 };
vector<ii> adj[MAX];
bitset<MAX> processed;

pair<vector<int>, vector<int>> dijkstra(int s, int N)
{
    vector<int> dist(N + 1, oo), pred(N + 1, oo);
    dist[s] = 0;
    pred[s] = s;

    processed.reset();

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, s);

    while (not pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (processed[u])
            continue;

        processed[u] = true;

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pred[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }

    return { dist, pred };
}

vector<ii> path(int s, int u, const vector<int>& pred)
{
    vector<ii> p;
    int v = u;

    do {
        p.push_back(ii(pred[v], v));
        v = pred[v];
    } while (v != s);

    reverse(p.begin(), p.end());

    return p;
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

    auto [dist, pred] = dijkstra(1, 6);

    for (int u = 1; u <= 6; ++u)
    {
        cout << "dist(1," << u << ") = " << dist[u] << ", pred[" << u << "] = " << pred[u] << endl;

        auto p = path(1, u, pred);

        for (size_t i = 0; i < p.size(); ++i)
            cout << "(" << p[i].first << ", " << p[i].second << ")" << (i + 1 == p.size() ? "\n" : " -> ");
    }

    return 0;
} 
