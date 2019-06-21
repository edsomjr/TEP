#include <bits/stdc++.h>

using namespace std;

const int MAX { 1010 }, oo { 1000000010 };

int dist[MAX], soldiers[MAX];
vector<int> adj[MAX];

void solve(int s, int e, int N, const vector<edge>& edges)
{
    for (int i = 1; i <= N; ++i)
        dist[i] = oo;

    dist[s] = 0;

    for (int i = 1; i <= N - 1; i++)
        for (const auto& [u, v, w] : edges)
            dist[v] = min(dist[v], dist[u] + w);
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M, K;
    double P;

    while (cin >> N >> M >> K >> P)
    {
    }

    return 0;
} 
