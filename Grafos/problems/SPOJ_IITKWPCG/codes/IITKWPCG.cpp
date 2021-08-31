#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };

vector<ii> adj[MAX];

int prim(int u, int N)
{
    set<int> C;
    C.insert(u);

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for (auto [v, w] : adj[u])
        pq.push(ii(w, v));

    int mst = 0;

    while ((int) C.size() < N)
    {
        int v, w;

        do {
            w = pq.top().first, v = pq.top().second;
            pq.pop();
        } while (C.count(v));

        mst += w;
        C.insert(v);

        for (auto [s, p] : adj[v])
            pq.push(ii(p, s));
    }

    return mst;
}

int solve(int N)
{
    auto cost = prim(1, N);

    return cost + 1;
}

int log2int(long long x)
{
    int res = 0;

    while (x > 1)
    {
        ++res;
        x >>= 1;
    }

    return res;
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

        for (int u = 1; u <= N; ++u)
            adj[u].clear();

        while (M--)
        {
            int a, b;
            long long c;
            cin >> a >> b >> c;

            auto k = log2int(c);

            adj[a].emplace_back(b, k);    
            adj[b].emplace_back(a, k);    
        }

        auto ans = solve(N);

        cout << ans << '\n';
    }

    return 0;
}
