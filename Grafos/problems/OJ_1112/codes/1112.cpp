#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 }, oo { 1000000010 };
vector<ii> adj[MAX];

vector<int> dijkstra(int s, int N)
{
    vector<int> dist(N + 1, oo);
    dist[s] = 0;

    set<ii> U;
    U.emplace(0, s);

    while (not U.empty())
    {
        auto [d, u] = *U.begin();
        U.erase(U.begin());

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > d + w)
            {
                if (U.count(ii(dist[v], v)))
                    U.erase(ii(dist[v], v));

                dist[v] = d + w;
                U.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int solve(int N, int E, int T)
{
    auto dist = dijkstra(E, N);

    auto ans = 0;

    for (int u = 1; u <= N; ++u)
        ans += (dist[u] <= T ? 1 : 0);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int C;
    cin >> C;

    for (int test = 0; test < C; ++test)
    {
        int N, E, T;
        cin >> N >> E >> T;

        for (int u = 1; u <= N; ++u)
            adj[u].clear();

        int M;
        cin >> M;

        while (M--)
        {
            int a, b,  t;
            cin >> a >> b >> t;

            adj[b].emplace_back(a, t);
        }

        auto ans = solve(N, E, T);

        if (test)
            cout << '\n';

        cout << ans << '\n';
    }

    return 0;
} 
