#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };
bitset<MAX> visited;
vector<int> adj[MAX];

void dfs(int u, const function<void(int)>& process)
{
    if (visited[u]) return;
    visited[u] = true;

    process(u);

    for (const auto& v : adj[u])
        dfs(v, process);
}

int connected_components(int N)
{
    visited.reset();

    int ans = 0;

    for (int u = 1; u <= N; ++u) 
    {
        if (not visited[u])
        {
            cout << "Component " << ++ans << ":";
            dfs(u, [](int u) { cout << ' ' << u; });
            cout << '\n';
        }
    }

    return ans;
}

int main()
{
    vector<ii> edges { ii(1, 2), ii(1, 8), ii(2, 10), ii(3, 7), ii(4, 5),
        ii(4, 9), ii(5, 9) };

    for (const auto& [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    connected_components(10);

    return 0;
} 
