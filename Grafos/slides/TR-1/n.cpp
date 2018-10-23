#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 1010 };
vector<int> adj[MAX];
int n[MAX];

void dfs(int u, int p)
{
    n[u] = 1;

    for (const auto& v : adj[u])
    {
        if (v == p) continue;

        dfs(v, u);
        n[u] += n[v];
    }
}

int main()
{
    vector<ii> edges { ii(1, 7), ii(3, 7), ii(7, 4), ii(4, 2), 
        ii(4, 5), ii(5, 6) };

    for (const auto& [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(4, 0);

    // 1 1 1 7 2 1 3
    for (int u = 1; u <= 7; ++u)
        cout << n[u] << (u == 7 ? '\n': ' ');

    return 0;
} 
