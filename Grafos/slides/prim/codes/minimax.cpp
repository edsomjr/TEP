#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 100010 }, oo { 1000000010 };

vector<ii> adj[MAX];

int minimax(int u, int N)
{
    set<int> C;
    C.insert(u);

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for (auto [v, w] : adj[u])
        pq.push(ii(w, v));

    int minmax = -oo;

    while ((int) C.size() < N)
    {
        int v, w;

        do {
            w = pq.top().first, v = pq.top().second;
            pq.pop();
        } while (C.count(v));

        minmax = max(minmax, w);
        C.insert(v);

        for (auto [s, p] : adj[v])
            pq.push(ii(p, s));
    }

    return minmax;
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

    auto ans = minimax(6, 6);

    cout << ans << '\n';

    return 0;
}
