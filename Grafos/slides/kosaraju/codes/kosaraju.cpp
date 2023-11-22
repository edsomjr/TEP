#include <bits/stdc++.h>

using namespace std;

constexpr int MAX { 200'010 };

vector<int> adj[MAX], rev[MAX];
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

void dfs_cc(int u, vector<int>& cc)
{
    if (visited[u])
        return;

    visited[u] = true;
    cc.emplace_back(u);

    for (auto v : rev[u])
        dfs_cc(v, cc);
}

vector<vector<int>> kosaraju(int N) {
    auto order = dfs_order(N);
    reverse(order.begin(), order.end());

    for (int u = 1; u <= N; ++u)
        for (auto v : adj[u])
            rev[v].emplace_back(u);

    vector<vector<int>> cs;
    visited.reset();

    for (auto u : order) {
        if (visited[u])
            continue;

        cs.emplace_back(vector<int>());
        dfs_cc(u, cs.back());
    }
        
    return cs;
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

    auto cs = kosaraju(N);
    int number = 1;

    for (auto c : cs)
    {
        cout << "== #" << number++ << ": ";
        
        for (size_t i = 0; i < c.size(); ++i)
            cout << c[i] << (i + 1 == c.size() ? '\n' : ' ');
    }

    return 0;
}
