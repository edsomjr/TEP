#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 100010 }, oo { 1000000010 };

vector<ii> adj[MAX];

vector<int> maximin(int s, int N)
{
    set<int> C;
    C.insert(s);

    priority_queue<edge> pq;
    vector<int> ms(N + 1, oo);

    for (auto [v, w] : adj[s])
        pq.push(edge(w, s, v));

    while ((int) C.size() < N)
    {
        auto [w, u, v] = pq.top();
        pq.pop();

        if (C.count(v))
            continue;

        C.insert(v);

        ms[v] = u == s ? w : min(w, ms[u]);

        for (auto [r, c] : adj[v])
            pq.push(edge(c, v, r));
    }

    return ms;
}

int solve(int N, int S, int D, int T)
{
    auto ms = maximin(S, N);
    auto M = ms[D];

    return (T + M - 2)/(M - 1);
}

int main()
{
    int N, R, test = 0;

    while (cin >> N >> R, N || R)
    {
        for (int u = 1; u <= N; ++u)
            adj[u].clear();

        while (R--)
        {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        int S, D, T;
        cin >> S >> D >> T;

        auto ans = solve(N, S, D, T);

        cout << "Scenario #" << ++test << '\n';
        cout << "Minimum Number of Trips = " << ans << "\n\n";
    }

    return 0;
}
