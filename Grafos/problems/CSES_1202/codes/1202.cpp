// CSES 1202 - Investigation (https://cses.fi/problemset/task/1202/)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 100010 };
const ll oo { 1LL << 62 }, MOD { 1000000007 };
vector<ii> adj[MAX];
vector<ll> in[MAX];
bitset<MAX> processed;

pair<vector<ll>, vector<ll>> dijkstra(int s, int N)
{
    vector<ll> dist(N + 1, oo), order;
    dist[s] = 0;

    processed.reset();

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, s);

    while (not pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (processed[u])
            continue;

        order.emplace_back(u);
        processed[u] = true;

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
                in[v].clear();
                in[v].push_back(u);
            } else if (dist[v] == d + w)
            {
                in[v].push_back(u);
            }
        }
    }

    return { dist, order };
}

tuple<vector<ll>, vector<ll>, vector<ll>>
min_paths(int s, int N, const vector<ll>& order)
{
    vector<ll> ps(N + 1, 0), ms(N + 1, oo), Ms(N + 1, 0);

    ps[s] = 1;
    ms[s] = 0;

    for (auto x : order)
        for (auto v : in[x])
        {
            ps[x] = (ps[x] + ps[v]) % MOD;
            ms[x] = min(ms[x], 1 + ms[v]);
            Ms[x] = max(Ms[x], 1 + Ms[v]);
        }

    return { ps, ms, Ms };
}

vector<ll> solve(int N)
{
    auto [dist, order] = dijkstra(1, N);
    auto [ps, ms, Ms] = min_paths(1, N, order);

    return { dist[N], ps[N], ms[N], Ms[N] };
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    while (M--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a].emplace_back(b, c);
    }

    auto ans = solve(N);

    for (int i = 0; i < 4; ++i)
        cout << ans[i] << (i + 1 == 4 ? '\n' : ' ');

    return 0;
}
