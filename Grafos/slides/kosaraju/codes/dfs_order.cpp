#include <bits/stdc++.h>

using namespace std;

constexpr int MAX { 200'010 };

vector<int> adj[MAX];
bitset<MAX> visited;

void dfs(int u, vector<int>& order)
{
    if (visited[u])
        return;

    visited[u] = true;

    for (auto v : adj[u])
        dfs(v, order);

    order.emplace_back(u);
}

vector<int> dfs_order(int N)
{
    vector<int> order;

    for (int u = 1; u <= N; ++u)
        dfs(u, order);

    return order;
}

int main()
{
    int N, M;
    cin >> N >> M;

    while (M--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].emplace_back(v);
    }

    auto order = dfs_order(N);

    for (int i = 0; i < N; ++i)
        cout << order[i] << (i + 1 == N ? '\n' : ' ');

    return 0;
}
