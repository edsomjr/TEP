#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 100010 }, oo { 1000000010 };
vector<ii> adj[MAX];
set<int> in[MAX];
bitset<MAX> processed;

vector<int> dijkstra_order(int s, int N)
{
    vector<int> dist(N + 1, oo), order;
    dist[s] = 0;

    processed.reset();

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, s);

    while (not pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (processed[u])
            continue;

        order.emplace_back(u);
        processed[u] = true;

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
                in[v] = { u };
            } else if (dist[v] == d + w)
                in[v].emplace(u);
        }
    }

    return order;
}

vector<int> min_paths(int s, int N)
{
    vector<int> ps(N + 1, 0);
    ps[s] = 1;

    auto o = dijkstra_order(s, N);

    for (auto x : o)
        for (auto v : in[x])
            ps[x] += ps[v];

    return ps;
}

int main()
{
    vector<edge> es { { 1, 2, 3 }, { 1, 3, 2 }, { 1, 4, 5 }, { 2, 5, 3 } , { 3, 2, 1 }, { 3, 4, 2 },
        { 3, 5, 5 }, { 4, 5, 2 } };

    for (auto [u, v, w] : es)
        adj[u].emplace_back(v, w);

    auto ps = min_paths(1, 5);

    for (int u = 1; u <= 5; ++u)
        cout << 1 << " -> " << u << ": " << ps[u] << '\n';

    return 0;
}
