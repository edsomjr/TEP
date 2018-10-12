#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };
bitset<MAX> visited;
vector<int> adj[MAX];
int parent[MAX];

bool dfs(int u)
{
    if (visited[u]) return false;
    visited[u] = true;

    for (const auto& v : adj[u])
    {
        parent[v] = parent[v] ? parent[v] : u;

        if (visited[v] and parent[u] != v) 
            return true;
        else
            if (dfs(v)) return true;
    }

    return false;
}

bool has_cycle(int N)
{
    visited.reset();
    memset(parent, 0, sizeof parent);

    for (int u = 1; u <= N; ++u) 
        if (not visited[u] and dfs(u))
            return true;

    return false;
}

int main()
{
    ii edges[] { ii(1,2), ii(2,3), ii(2,4), ii(2,6), ii(4,5), ii(4,6) };

    for (const auto& [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Tem ciclo? " << (has_cycle(6) ? "Sim" : "Nao") << endl;

    return 0;
}
