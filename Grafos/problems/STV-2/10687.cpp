#include <bits/stdc++.h>

using namespace std;

struct Point { int x, y; };

struct Edge
{
    int d, x, y, i;

    bool operator<(const Edge& e) const
    {
        if (d != e.d)
            return d < e.d;

        if (x != e.x)
            return x < e.x;

        return y < e.y;
    }
};

const int MAX { 1010 };

vector<Edge> adj[MAX];
bitset<MAX> visited;

void bfs(size_t u)
{
    queue<int> q;

    q.push(u);
    visited[u] = true;

    while (not q.empty())
    {
        auto v = q.front();
        q.pop();

        for (int k = 0; k < 2; ++k)
        {
            auto w = adj[v][k].i;

            if (not visited[w])
            {
                visited[w] = true;
                q.push(w);
            }
        }
    }
}

bool solve(int N, const vector<Point>& ps)
{
    for (int p = 1; p <= N; ++p)
        adj[p].clear();

    for (int p = 1; p <= N; ++p)
    {
        auto P = ps[p];

        for (int q = p + 1; q <= N; ++q)
        {
            auto Q = ps[q];

            auto d2 = (P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y);
            adj[p].push_back(Edge { d2, Q.x, Q.y, q });
            adj[q].push_back(Edge { d2, P.x, P.y, p });
        }
    }

    for (int P = 1; P <= N; ++P)
        sort(adj[P].begin(), adj[P].end());

    visited.reset();
    bfs(1);

    return (int) visited.count() == N;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N, N)
    {
        vector<Point> ps(N + 1);

        for (int i = 1; i <= N; ++i)
            cin >> ps[i].x >> ps[i].y;

        auto ans = solve(N, ps);

        cout << (ans ? "All stations are reachable." :
            "There are stations that are unreachable.") << '\n'; 
    }

    return 0;
}
