#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAXN { 60 }, MAXP { 15 }, oo { 1000000010 };

int dist[MAXN][MAXN];
int st[MAXN][1 << MAXP];

int tsp(int i, int mask, int N, const vector<ii>& xs)
{
    if (st[i][mask] != -1)
        return st[i][mask];

    int res = -dist[i][0];

    for (int j = 0; j < N; ++j)
    {
        if (mask & (1 << j))
            continue;

        auto u = xs[j].first, c = xs[j].second;
        auto cost = -dist[i][u] + c;

        res = max(res, tsp(u, mask | (1 << j), N, xs) + cost);
    }

    st[i][mask] = res;
    return res;
}

void floyd_warshall(int N)
{
    for (int u = 0; u <= N; ++u)
        dist[u][u] = 0;

    for (int k = 0; k <= N; ++k)
        for (int u = 0; u <= N; ++u)
            for (int v = 0; v <= N; ++v)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
}

int solve(int N, const vector<ii>& xs)
{
    floyd_warshall(N);

    memset(st, -1, sizeof st);

    return tsp(0, 0, (int) xs.size(), xs);
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        for (int u = 0; u <= N; ++u)
            for (int v = 0; v <= N; ++v)
                dist[u][v] = oo;

        while (M--)
        {
            int u, v, d, c;
            char sep;

            cin >> u >> v >> d >> sep >> c;

            dist[u][v] = min(dist[u][v], 100*d + c);
            dist[v][u] = min(dist[u][v], 100*d + c);
        }

        int P;
        cin >> P;

        vector<ii> xs;
        
        for (int i = 0; i < P; ++i)
        {
            int u, d, c;
            char sep;
            cin >> u >> d >> sep >> c;

            xs.push_back(ii(u, 100*d + c));
        }

        auto ans = solve(N, xs);

        if (ans)
            cout << "Daniel can save $" << ans / 100 << "." 
                << setw(2) << setfill('0') << ans % 100 << endl;
        else
            cout << "Don't leave the house\n";
    }

    return 0;
}
