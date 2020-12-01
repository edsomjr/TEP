#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAXN { 110 }, MAXB { 13 }, oo { 1000000010 };

int dist[MAXN][MAXN];
int st[MAXN][1 << MAXB];

int tsp(int i, int mask, int N, int B, const vector<ii>& xs)
{
    if (mask == (1 << N) - 1)
        return dist[i][B];

    if (st[i][mask] != -1)
        return st[i][mask];

    int res = oo;

    for (int j = 0; j < N; ++j)
    {
        if (mask & (1 << j))
            continue;

        auto u = xs[j].first, v = xs[j].second;
        auto cost = dist[i][u] + dist[u][v];

        res = min(res, tsp(v, mask | (1 << j), N, B, xs) + cost);
    }

    st[i][mask] = res;
    return res;
}

void floyd_warshall(int N, const vector<vector<ii>>& adj)
{
    for (int u = 1; u <= N; ++u)
        for (int v = 1; v <= N; ++v)
            dist[u][v] = oo;

    for (int u = 1; u <= N; ++u)
        dist[u][u] = 0;

    for (int u = 1; u <= N; ++u)
        for (const auto& [v, w] : adj[u])
            dist[u][v] = w;

    for (int k = 1; k <= N; ++k)
        for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
}

int
solve(int N, int B, const vector<vector<ii>>& adj, const vector<ii>& xs)
{
    floyd_warshall(N, adj);

    memset(st, -1, sizeof st);
    return tsp(B, 0, (int) xs.size(), B, xs);
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M, B;
        cin >> N >> M >> B;

        vector<vector<ii>> adj(N + 1);

        while (M--)
        {
            int u, v, d;
            cin >> u >> v >> d;

            adj[u].push_back(ii(v, d));
            adj[v].push_back(ii(u, d));
        }

        int Z;
        cin >> Z;

        vector<ii> xs;
        
        for (int i = 0; i < Z; ++i)
        {
            int u, v, b;
            cin >> u >> v >> b;

            while (b--)
                xs.push_back(ii(u, v));
        }

        cout << solve(N, B, adj, xs) << '\n';
    }

    return 0;
}
