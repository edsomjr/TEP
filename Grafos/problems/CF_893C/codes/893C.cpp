#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAX { 100010 };
const ll oo { 2000000000000000000LL };

vector<int> adj[MAX];
bitset<MAX> visited;

void dfs(int u, const function<void(int)>& process)
{
    if (visited[u])
        return;

    visited[u] = true;
    process(u);

    for (auto v : adj[u])
        dfs(v, process);
}

ll solve(int N, const vector<ll>& cs)
{
    ll ans = 0;

    for (int u = 1; u <= N; ++u)
    {
        if (visited[u])
            continue;

        ll cost = oo;

        dfs(u, [&](int u) { cost = min(cost, cs[u]); });

        ans += cost;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<ll> cs(N + 1);

    for (int u = 1; u <= N; ++u)
        cin >> cs[u];

    while (M--)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    auto ans = solve(N, cs);

    cout << ans << '\n';

    return 0;
}
