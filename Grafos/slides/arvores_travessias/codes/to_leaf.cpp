#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 1010 };
vector<int> adj[MAX];

void dfs(int u, int p, vector<int>& tl)
{
    for (auto v : adj[u])
    {
        if (v == p)
            continue;

        dfs(v, u, tl);
        tl[u] = max(tl[u], 1 + tl[v]);
    }
}

vector<int> to_leaf(int u, int N)
{
    vector<int> tl(N + 1, 0);

    dfs(u, 0, tl);

    return tl;
}

int main()
{
    vector<ii> edges { ii(1, 7), ii(3, 7), ii(7, 4), ii(4, 2), 
        ii(4, 5), ii(5, 6) };

    for (const auto& [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto tl = to_leaf(4, 7);

    // 0 0 0 2 1 0 1
    for (int u = 1; u <= 7; ++u)
        cout << tl[u] << (u == 7 ? '\n': ' ');

    return 0;
} 
