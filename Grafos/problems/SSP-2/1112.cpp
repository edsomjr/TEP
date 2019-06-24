#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const ll MAX { 1010 }, oo { 1000000000000000010LL };
ll dist[MAX];
vector<ii> adj[MAX];
bitset<MAX> processed;

void dijkstra(int s, int N)
{
    for (int i = 1; i <= N; ++i)
        dist[i] = oo;

    dist[s] = 0;
    processed.reset();

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));

    while (not pq.empty()) {
        auto p = pq.top();
        pq.pop();

        auto d = p.first, u = p.second;

        if (processed[u])
            continue;

        processed[u] = true;

        for (const auto& q : adj[u]) {
            auto v = q.first, w = q.second;

            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push(ii(dist[v], v));
            }
        }
    }
}

int solve(int N, int E, int T)
{
    dijkstra(E, N);

    auto ans = 0;

    for (int i = 1; i <= N; ++i)
        ans += (dist[i] <= T ? 1 : 0);

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

        for (int i = 0; i < MAX; ++i)
            adj[i].clear();

        int M;
        cin >> M;

        while (M--)
        {
            int u, v, w;
            cin >> u >> v >> w;

            adj[v].push_back(ii(u, w));
        }

        auto ans = solve(N, E, T);

        if (test)
            cout << '\n';

        cout << ans << '\n';
    }

    return 0;
} 
