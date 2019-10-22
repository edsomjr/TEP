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
    cout << u << " ";
    for (const auto& v : adj[u])
        dfs(v);
}
int main()
{
    ii edges[] { ii(1, 2), ii(1, 3), ii(2, 4), ii(2, 5), ii(3, 6),
                 ii(5, 6), ii(5, 8), ii(5, 9), ii(6, 7), ii(6, 10), ii(8, 11),
                 ii(9, 10), ii(11, 12), ii(11, 13)
               };
    for (const auto& [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.reset();
    dfs(1);
    cout << endl;
    return 0;
}