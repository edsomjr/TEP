#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 100010 };

vector<ii> adj[MAX];

int prim(int u, size_t N)
{
    set<int> C;
    C.emplace(u);

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for (auto [v, w] : adj[u])
        pq.emplace(w, v);

    int mst = 0;

    while (C.size() < N)
    {
        int v, w;

        do {
            tie(w, v) = pq.top();
            pq.pop();
        } while (C.count(v));

        mst += w;
        C.emplace(v);

        for (auto [s, p] : adj[v])
            pq.emplace(p, s);
    }

    return mst;
}

int main()
{
    vector<edge> es { { 2, 3, 1 }, { 4, 5, 1 }, { 4, 1, 2 }, { 1, 5, 2 }, { 3, 4, 3 },
        { 2, 1, 4 }, { 3, 1, 5 }, { 3, 6, 7 }, { 6, 5, 8 } };

    for (auto [u, v, w] : es)
    {
        adj[u].emplace_back(v, w); 
        adj[v].emplace_back(u, w); 
    }

    auto ans = prim(6, 6);

    cout << ans << '\n';

    return 0;
}
