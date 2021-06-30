// SPOJ SUBMERGE - Submerging Islands (https://www.spoj.com/problems/SUBMERGE/)
#include <bits/stdc++.h>

using namespace std;
using edge = pair<int, int>;

const int MAX { 100010 }; 
int dfs_num[MAX], dfs_low[MAX];
vector<int> adj[MAX];

int dfs(int u, int p, int& next, set<int>& points)
{
    int children = 0;
    dfs_low[u] = dfs_num[u] = next++;

    for (auto v : adj[u])
        if (not dfs_num[v]) {
            ++children; 

            dfs(v, u, next, points);

            if (dfs_low[v] >= dfs_num[u])
                points.insert(u);

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != p)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);

    return children;
}

size_t solve(int N)
{
    memset(dfs_num, 0, (N + 1)*sizeof(int));
    memset(dfs_low, 0, (N + 1)*sizeof(int));

    set<int> points;

    for (int u = 1, next = 1; u <= N; ++u)
        if (not dfs_num[u])
        {
            auto children = dfs(u, u, next, points);

            if (children == 1)
                points.erase(u);
        }
    
    return points.size();
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;

    while (cin >> N >> M, N | M)
    {
        for (int u = 1; u <= N; ++u)
            adj[u].clear();

        while (M--)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto ans = solve(N);

        cout << ans << '\n';
    }

    return 0;
} 
