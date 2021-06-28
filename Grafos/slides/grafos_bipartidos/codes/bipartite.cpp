#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 }; 
int color[MAX];
vector<int> adj[MAX];

bool bfs(int s)
{
    const int NONE = 0, BLUE = 1, RED = 2;
    queue<int> q;
    q.push(s);
    color[s] = BLUE;
    
    while (not q.empty())
    {
        auto u = q.front(); q.pop();

        for (auto v : adj[u])
            if (color[v] == NONE) {
                color[v] = 3 - color[u];
                q.push(v);
            } else if (color[v] == color[u])
                return false;
    }

    return true;
}

bool is_bipartite(int N)
{
    for (int u = 1; u <= N; ++u) 
        if (color[u] == NONE and not bfs(u))
            return false;

    return true;
}

int main()
{
    vector<ii> edges { ii(1, 2), ii(1, 3), ii(1, 4), ii(1, 5), ii(2, 6), 
        ii(3, 6), ii(4, 8), ii(5, 7), ii(6, 9), ii(7, 9), ii(8, 9), 
        ii(9, 10) };

    for (const auto& [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << (is_bipartite(edges.size()) ? "Sim" : "Nao") << '\n';

    return 0;
} 
