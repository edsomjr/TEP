#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };

bitset<MAX> visited;
vector<int> adj[MAX];

bool dfs(int u, int p = -1)
{
    if (visited[u])
        return false;

    visited[u] = true;

    for (auto v : adj[u])
    {
        if (visited[v] and v != p)
            return true;

        if (dfs(v, u))
            return true;
    }

    return false;
}

bool has_cycle(int N)
{
    visited.reset();

    for (int u = 1; u <= N; ++u) 
        if (not visited[u] and dfs(u))
            return true;

    return false;
}

int main()
{
    vector<ii> edges { ii(1,2), ii(2,3), ii(2,4), ii(2,6),
        ii(4,5), ii(4,6) };

    for (const auto& [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Tem ciclo? " << (has_cycle(6) ? "Sim" : "Nao") << '\n';

    return 0;
}
