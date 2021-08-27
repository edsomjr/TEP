#include <bits/stdc++.h>

using namespace std;

const int MAX { 110 };

vector<int> adj[MAX];

vector<int> max_dist(int s, int N, int w = 1) {
    vector<int> dist(N + 1, -1);
    queue<int> q;

    dist[s] = 0; q.push(s);

    while (not q.empty())
    {
        auto u = q.front(); q.pop();

        for (auto v : adj[u]) {
            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }

    return dist;
}

pair<int, int> solve(int s, int N)
{
    auto dist = max_dist(s, N);

    auto d = 0, v = s;

    for (int u = 1; u <= N; ++u)
        if (dist[u] > d)
        {
            d = dist[u];
            v = u;
        }

    return { d, v };
}

int main()
{
    ios::sync_with_stdio(false);

    int n, test = 0;

    while (cin >> n, n)
    {
        for (int u = 1; u <= n; ++u)
            adj[u].clear();

        int s;
        cin >> s;

        int p, q;

        while (cin >> p >> q, p | q)
            adj[p].push_back(q);

        auto [dist, u] = solve(s, n);

        cout << "Case " << ++test << ": The longest path from " << s << " has length " 
            << dist << ", finishing at " << u << ".\n\n";
    }

    return 0;
}
