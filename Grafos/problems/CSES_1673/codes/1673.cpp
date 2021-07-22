#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 2505 };
const ll oo { 1LL << 62 };

vector<int> adj[MAX];
bitset<MAX> visited;

bool dfs(int u, const set<int>& us)
{
    if (visited[u])
        return false;

    if (us.count(u))
        return true;

    visited[u] = true;

    for (auto v : adj[u])
        if (dfs(v, us))
            return true;

    return false;
}

ll solve(int N, const vector<edge>& es) {
    vector<ll> dist(N + 1, oo);
    dist[1] = 0;

    for (int i = 1; i <= N - 1; ++i)
        for (auto [a, b, x] : es)
            if (dist[a] < oo and dist[b] > dist[a] + x)
                dist[b] = dist[a] + x;

    set<int> us;

    for (auto [a, b, x] : es)
        if (dist[a] < oo and dist[b] > dist[a] + x) {
            us.insert(b); dist[b] = dist[a] + x;
        }

    if (dfs(N, us)) return -1;

    return -dist[N];
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<edge> es;

    while (M--)
    {
        int a, b, x;
        cin >> a >> b >> x;

        es.emplace_back(a, b, -x);
        adj[b].emplace_back(a);
    }

    auto ans = solve(N, es);

    cout << ans << '\n';

    return 0;
}
