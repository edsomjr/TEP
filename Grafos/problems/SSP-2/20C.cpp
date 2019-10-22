#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const ll MAX { 100010 }, oo { 1000000000000000010LL };
ll dist[MAX], pred[MAX];
vector<ii> adj[MAX];
bitset<MAX> processed;

void dijkstra(int s, int N)
{
    for (int i = 1; i <= N; ++i) {
        dist[i] = oo;
        pred[i] = -1;
    }

    dist[s] = 0;
    pred[s] = s;
    processed.reset();

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));

    while (not pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (processed[u])
            continue;

        processed[u] = true;

        for (const auto& [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push(ii(dist[v], v));
                pred[v] = u;
            }
        }
    }
}

vector<int> solve(int N)
{
    dijkstra(1, N);

    vector<int> path;
    auto p = N;

    while (p != 1) {
        path.push_back(p);
        p = pred[p];

        if (p < 0)
            return vector<int> {};
    } 

    path.push_back(1);
    reverse(path.begin(), path.end());

    return path;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    auto ans = solve(N);

    if (ans.empty())
        cout << -1 << '\n';
    else
        for (size_t i = 0; i < ans.size(); ++i)
            cout << ans[i] << (i + 1 == ans.size() ? "\n" : " ");    

    return 0;
} 
