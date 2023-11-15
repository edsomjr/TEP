#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 100010 };

vector<ii> adj[MAX];

int msg(size_t N, const vector<edge>& es)
{
    set<int> C;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    int cost = 0;

    for (auto [u, v, w] : es)
    {
        cost += w;

        C.emplace(u);
        C.emplace(v);

        for (auto [r, s] : adj[u])
            pq.emplace(s, r);

        for (auto [r, s] : adj[v])
            pq.emplace(s, r);
    }

    while (C.size() < N)
    {
        int v, w;

        do {
            tie(w, v) = pq.top();
            pq.pop();
        } while (C.count(v));

        cost += w;
        C.emplace(v);

        for (auto [s, p] : adj[v])
            pq.emplace(p, s);
    }

    return cost;
}

int main()
{
    vector<edge> es { { 1, 2, 1 }, { 1, 2, 4 }, { 1, 4, 4 }, { 1, 5, 3 }, { 2, 3, 5 }, { 3, 4, 5 },
        { 3, 5, 2 }, { 4, 5, 3 } };

    for (auto [u, v, w] : es)
    {
        adj[u].emplace_back(v, w); 
        adj[v].emplace_back(u, w); 
    }

    vector<edge> E { { 1, 4, 4 }, { 1, 5, 3 }, { 4, 5, 3 } };

    auto ans = msg(5, E);

    cout << ans << '\n';

    return 0;
}
