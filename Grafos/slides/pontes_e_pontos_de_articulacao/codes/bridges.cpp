#include <bits/stdc++.h>

using namespace std;
using edge = pair<int, int>;

const int MAX { 100010 }; 
int dfs_num[MAX], dfs_low[MAX];
vector<int> adj[MAX];

void dfs_bridge(int u, int p, int& next, vector<edge>& bridges)
{
    dfs_low[u] = dfs_num[u] = next++;

    for (auto v : adj[u])
        if (not dfs_num[v]) {

            dfs_bridge(v, u, next, bridges);

            if (dfs_low[v] > dfs_num[u])
                bridges.emplace_back(u, v);

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != p)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
}

vector<edge> bridges(int N)
{
    memset(dfs_num, 0, (N + 1)*sizeof(int));
    memset(dfs_low, 0, (N + 1)*sizeof(int));

    vector<edge> bridges;

    for (int u = 1, next = 1; u <= N; ++u)
        if (not dfs_num[u])
            dfs_bridge(u, u, next, bridges);
    
    return bridges;
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

    auto bs = bridges(9);

    cout << "Bridges:\n";

    for (auto [u, v] : bs)
        cout << u << ' ' << v << '\n';

    return 0;
} 
