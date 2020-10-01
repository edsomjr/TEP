#include <bits/stdc++.h>

using namespace std;
struct Edge { int a, b, c; };

const int MAX { 110 }, oo { 1000000010 };
int dist[MAX];

int solve(int s, int N, const vector<Edge>& es)
{
    for (int i = 1; i <= N; ++i)
        dist[i] = oo;

    dist[s] = 0;

    for (int i = 1; i <= N - 1; i++)
        for (const auto& e : es)
            dist[e.b] = min(dist[e.b], dist[e.a] + e.c);

    return dist[N];
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<Edge> es(2*M);

    for (int i = 0; i < M; ++i)
    {
        cin >> es[i].a >> es[i].b >> es[i].c;
        es[M + i] = Edge { es[i].b, es[i].a, es[i].c };
    }

    auto ans = solve(1, N, es);
 
    cout << ans << '\n';

    return 0;
}
