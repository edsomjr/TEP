#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 1010 };
vector<int> adj[MAX];

void dfs(int u, int p, vector<int>& ns)
{
    for (auto v : adj[u])
    {
        if (v == p)
            continue;

        dfs(v, u, ns);
        ns[u] += ns[v];
    }
}

vector<int> nodes(int u, int N)
{
    vector<int> ns(N + 1, 1);

    dfs(u, 0, ns);

    return ns;
}

int main()
{
    vector<ii> edges { ii(1, 7), ii(3, 7), ii(7, 4), ii(4, 2), 
        ii(4, 5), ii(5, 6) };

    for (const auto& [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto ns = nodes(4, 7);

    // 1 1 1 7 2 1 3
    for (int u = 1; u <= 7; ++u)
        cout << ns[u] << (u == 7 ? '\n': ' ');

    return 0;
} 
