#include <bits/stdc++.h>

using namespace std;
using edge = pair<int, int>;

const int MAX { 100010 }; 
int dfs_num[MAX], dfs_low[MAX];
vector<int> adj[MAX];

int dfs_articulation_points(int u, int p, int& next, set<int>& points)
{
    int children = 0;
    dfs_low[u] = dfs_num[u] = next++;

    for (auto v : adj[u])
        if (not dfs_num[v]) {
            ++children; 

            dfs_articulation_points(v, u, next, points);

            if (dfs_low[v] >= dfs_num[u])
                points.insert(u);

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != p)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);

    return children;
}

set<int> articulation_points(int N)
{
    memset(dfs_num, 0, (N + 1)*sizeof(int));
    memset(dfs_low, 0, (N + 1)*sizeof(int));

    set<int> points;

    for (int u = 1, next = 1; u <= N; ++u)
        if (not dfs_num[u])
        {
            auto children = dfs_articulation_points(u, u, next, points);

            if (children == 1)
                points.erase(u);
        }
    
    return points;
}

int main()
{
    vector<edge> edges { {1, 2}, {2, 3}, {2, 5}, {3, 4}, {4, 5}, {4, 6},
        {6, 7}, {6, 8}, {7, 8}, {8, 9} };

    for (auto [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto points = articulation_points(9);

    cout << "Articulation points:";

    for (auto u : points)
        cout << ' ' << u;
    cout << '\n';

    return 0;
} 
