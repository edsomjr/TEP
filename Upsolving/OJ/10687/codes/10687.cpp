#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int, int>;

const int MAX { 1010 };

set<edge> adj[MAX];
bitset<MAX> visited;

void bfs(int s)
{
    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (not q.empty())
    {
        auto u = q.front(); q.pop();

        for (auto [d2, x, y, v] : adj[u])
        {
            if (not visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

bool solve(int N, const vector<ii>& ps)
{
    for (int p = 1; p <= N; ++p)
        adj[p].clear();

    for (int p = 1; p <= N; ++p)
    {
        auto [px, py] = ps[p];

        for (int q = p + 1; q <= N; ++q)
        {
            auto [qx, qy] = ps[q];
            auto d2 = (px - qx)*(px - qx) + (py - qy)*(py - qy);

            adj[p].insert(edge { d2, qx, qy, q });
            adj[q].insert(edge { d2, px, py, p });

            if (adj[p].size() > 2)
                adj[p].erase(prev(adj[p].end()));

            if (adj[q].size() > 2)
                adj[q].erase(prev(adj[q].end()));
        }
    }

    visited.reset();
    bfs(1);

    return (int) visited.count() == N;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N, N)
    {
        vector<ii> ps(N + 1);

        for (int i = 1; i <= N; ++i)
            cin >> ps[i].first >> ps[i].second;

        auto ans = solve(N, ps);

        cout << (ans ? "All stations are reachable." :
            "There are stations that are unreachable.") << '\n'; 
    }

    return 0;
}
