#include <bits/stdc++.h>

using namespace std;

struct Edge { int u, v; };

const int MAX { 1010 }, oo { 1000000010 };
int dist[MAX], soldiers[MAX];

double
solve(int s, int e, int N, int K, double P, const vector<Edge>& edges)
{
    for (int i = 1; i <= N; ++i)
        dist[i] = oo;

    dist[s] = soldiers[s];

    for (int i = 1; i <= N - 1; i++)
    {
        bool updated = false;

        for (const auto& edge : edges)
            if (dist[edge.v] > dist[edge.u] + soldiers[edge.v])
            {
                dist[edge.v] = dist[edge.u] + soldiers[edge.v];
                updated = true;
            }

        if (not updated)
            break;
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

        vector<Edge> edges;

        while (M--)
        {
            int u, v;
            cin >> u >> v;

            edges.push_back(Edge { u, v });
            edges.push_back(Edge { v, u });
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

        auto ans = solve(s, e, N, K, P, edges);

        cout.precision(3);
        cout << fixed << ans << '\n';
    }

    return 0;
} 
