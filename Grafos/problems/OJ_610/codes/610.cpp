// OJ 610 - Street Directions (https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=551&mosmsg=Submission+received+with+ID+26529110)
#include <bits/stdc++.h>

using namespace std;
using edge = pair<int, int>;

const int MAX { 100010 }; 
int dfs_num[MAX], dfs_low[MAX];
vector<int> adj[MAX];

void dfs(int u, int p, int& next, set<edge>& streets)
{
    dfs_low[u] = dfs_num[u] = next++;

    for (auto v : adj[u]) {
        if (not streets.count(edge(u, v)) and not streets.count(edge(v, u)))
            streets.insert(edge(u, v));

        if (not dfs_num[v]) {

            dfs(v, u, next, streets);

            if (dfs_low[v] > dfs_num[u])
                streets.insert(edge(v, u));

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != p)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

set<edge> solve(int N)
{
    memset(dfs_num, 0, (N + 1)*sizeof(int));
    memset(dfs_low, 0, (N + 1)*sizeof(int));

    set<edge> streets;

    for (int u = 1, next = 1; u <= N; ++u)
        if (not dfs_num[u])
            dfs(u, u, next, streets);
    
    return streets;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M, test = 0;

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

        auto bs = solve(N);

        cout << ++test << "\n\n";

        for (auto [u, v] : bs)
            cout << u << ' ' << v << '\n';
        cout << "#\n";
    }

    return 0;
} 
