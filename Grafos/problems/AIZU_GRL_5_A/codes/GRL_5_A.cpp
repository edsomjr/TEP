#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };

vector<ii> adj[MAX];

void dfs(int u, int p, vector<int>& dist)
{
    for (auto [v, w] : adj[u])
    {
        if (v != p)
        {
            dist[v] = dist[u] + w;
            dfs(v, u, dist);
        }
    }
}

int solve(int n)
{
    vector<int> dist(n + 1, 0);

    dfs(0, -1, dist);

    auto v = (int) (max_element(dist.begin(), dist.end()) - dist.begin());

    dist[v] = 0;

    dfs(v, -1, dist);

    return *max_element(dist.begin(), dist.end());
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    auto ans = solve(n);

    cout << ans << '\n';

    return 0;
}
