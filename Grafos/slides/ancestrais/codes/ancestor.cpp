#include <bits/stdc++.h>

using namespace std;

constexpr int MAX { 200'010 };

vector<int> adj[MAX];
bitset<MAX> visited;

void dfs(int u, int p, vector<int>& ps)
{
    ps[u] = p;

    for (auto v : adj[u])
        if (v != p)
            dfs(v, u, ps);
}

auto precomp(int root, int N)
{
    int M = 0;

    while ((1 << (M + 1)) <= N)
        ++M;

    vector<vector<int>> as(N + 1, vector<int>(M + 1, 0));

    vector<int> ps(N + 1, 0);
    dfs(root, 0, ps);

    for (int u = 1; u <= N; ++u)
        as[u][0] = ps[u];

    for (int i = 1; i <= M; ++i)
        for (int u = 1; u <= N; ++u)
            as[u][i] = as[as[u][i - 1]][i - 1];

    return as;
}

int ancestor(int u, int k, int N, const vector<vector<int>>& as)
{
    if (k >= N)
        return 0;

    int level = 0;

    while (k)
    {
        if (k & 1)
            u = as[u][level];

        k >>= 1;
        ++level;
    }

    return u;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto as = precomp(3, N);

    cout << "ancestor(5, 3) = " << ancestor(5, 3, 9, as) << '\n';

    return 0;
}
