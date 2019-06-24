#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 110 }, oo { 2000000010 };
int dist[MAX][MAX];

void floyd_warshall(int N, const vector<edge>& edges)
{
    for (int u = 1; u <= N; ++u)
        for (int v = 1; v <= N; ++v)
            dist[u][v] = oo;

    for (int u = 1; u <= N; ++u)
        dist[u][u] = 0;

    for (const auto& [u, v, w] : edges)
        dist[u][v] = w;

    for (int k = 1; k <= N; ++k)
        for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                dist[u][v] = min(dist[u][v], max(dist[u][k], dist[k][v]));
}

vector<int>
solve(int N, const vector<edge>& es, const vector<ii>& qs)
{
    floyd_warshall(N, es);
    vector<int> ans;

    for (const auto& [u, v] : qs)
        ans.push_back(u == v ? 0 : dist[u][v]);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M, test = 0;

    while (cin >> N >> M, N | M)
    {
        vector<edge> es;

        while (M--)
        {
            int u, v, w;
            cin >> u >> v >> w;

            es.push_back(edge(u, v, w));
            es.push_back(edge(v, u, w));
        }

        int K;
        cin >> K;

        vector<ii> qs;

        while (K--)
        {
            int u, v;
            cin >> u >> v;

            qs.push_back(ii(u, v));
        }

        auto ans = solve(N, es, qs);

        cout << "Instancia " << ++test << '\n';

        for (const auto& x : ans)
            cout << x << '\n';

        cout << '\n';
    }
    
    return 0;
} 
