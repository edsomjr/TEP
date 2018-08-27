#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };
bitset<MAX> visited;
vector<int> adj[MAX];

void dfs(int u)
{
    if (visited[u]) return;
    visited[u] = true;

    cout << " " << u;

    for (const auto& v : adj[u])
        dfs(v);
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
            dfs(u);
            cout << endl;
        }
    }

    return ans;
}

int main()
{
    ii edges[] { ii(1, 2), ii(1, 8), ii(2, 10), ii(3, 7), ii(4, 5),
        ii(4, 9), ii(5, 9) };

    for (const auto& [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    connected_components(10);

    return 0;
} 
