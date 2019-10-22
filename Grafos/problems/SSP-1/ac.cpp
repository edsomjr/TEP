#include <bits/stdc++.h>

using namespace std;

const int MAX { 1010 }, oo { 1000000010 };
int dist[MAX], soldiers[MAX];
vector<int> adj[MAX];

double
solve(int s, int e, int N, int K, double P)
{
    bitset<MAX> in_queue;

    for (int i = 1; i <= N; ++i)
        dist[i] = oo;

    dist[s] = soldiers[s];

    queue<int> q;
    q.push(s);
    in_queue[s] = true;

    while (not q.empty())
    {
        auto u = q.front(); q.pop();
        in_queue[u] = false;

        for (const auto& v : adj[u])
        {
            auto w = soldiers[v];

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;

                if (not in_queue[v])
                {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }

    if (dist[e] > K)
        return 0.0;

    return pow(P, dist[e]);
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M, K;
    double P;

    while (cin >> N >> M >> K >> P)
    {
        memset(soldiers, 0, sizeof soldiers);

        for (int i = 1; i <= N; ++i)
            adj[i].clear();

        while (M--)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int A;
        cin >> A;

        while (A--)
        {
            int pos;
            cin >> pos;

            soldiers[pos]++;
        }

        int s, e;
        cin >> s >> e;

        auto ans = solve(s, e, N, K, P);

        cout.precision(3);
        cout << fixed << ans << '\n';
    }

    return 0;
} 
