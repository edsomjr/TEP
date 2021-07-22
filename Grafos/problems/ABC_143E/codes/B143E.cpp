// AtCoder Beginner Contest 143 - Problem E: Travel by Car (https://atcoder.jp/contests/abc143/tasks/abc143_e)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using iii = tuple<ll, ll, ll>;

const int MAX { 310 };
const ll oo { 1LL << 62 };

ll dist[MAX][MAX], fuel[MAX];

vector<ii> adj[MAX];
bitset<MAX> processed;

void dijkstra(int s, ll N, ll L)
{
    for (ll i = 1; i <= N; ++i)
        dist[s][i] = fuel[i] = oo;

    dist[s][s] = 0;
    fuel[s] = L;
    processed.reset();

    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push(iii(0, -L, s));

    while (not pq.empty())
    {
        auto [d, f, u] = pq.top(); pq.pop();

        if (processed[u])
            continue;

        processed[u] = true;

        for (const auto& [v, c] : adj[u]) {
            if (c <= fuel[u] and (dist[s][v] > dist[s][u] or
                (dist[s][v] == dist[s][u] and fuel[u] - c > fuel[v])))
            {
                    dist[s][v] = dist[s][u];
                    fuel[v] = fuel[u] - c;
                    pq.push(iii(dist[s][v], -fuel[v], v));
                    continue;
            }

            if (c <= L and (dist[s][v] > dist[s][u] + 1 or
                (dist[s][v] == dist[s][u] + 1 and L - c > fuel[v])))
            {
                    dist[s][v] = dist[s][u] + 1;
                    fuel[v] = L - c;
                    pq.push(iii(dist[s][v], -fuel[v], v));
            }
        }
    }
}
    
vector<ll> solve(ll N, ll L, const vector<ii>& qs)
{
    vector<ll> ans(qs.size());

    for (int s = 1; s <= N; ++s)
        dijkstra(s, N, L);
 
    for (size_t i = 0; i < qs.size(); ++i)
    {
        auto [s, t] = qs[i];
        ans[i] = (dist[s][t] == oo ? -1 : dist[s][t]);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M, L;
    cin >> N >> M >> L;

    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(ii(b, c));
        adj[b].push_back(ii(a, c));
    }

    int Q;
    cin >> Q;

    vector<ii> qs(Q);

    for (int i = 0; i < Q; ++i)
        cin >> qs[i].first >> qs[i].second;

    auto ans = solve(N, L, qs);

    for (auto x : ans)
        cout << x << endl;

    return 0;
}

