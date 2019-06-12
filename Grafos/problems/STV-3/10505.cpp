#include <bits/stdc++.h>

using namespace std;

const int MAX = 210, NONE = 0, BLUE = 1, RED = 2;
int color[MAX];
vector<int> adj[MAX];

int coloring(int s)
{
    int blue = 0, red = 0;
    bool bipartite = true;
    queue<int> q;

    q.push(s);
    color[s] = BLUE;
    ++blue;
    
    while (not q.empty())
    {
        auto u = q.front(); q.pop();

        for (const auto& v : adj[u])
            if (color[v] == NONE)
            {
                color[v] = 3 - color[u];
                color[v] == BLUE ? ++blue : ++red;
                q.push(v);
            } else if (color[v] == color[u])
                bipartite = false;
    }

    return bipartite ? max(blue, red) : 0;
}

int solve(int N)
{
    auto ans = 0;

    for (int u = 1; u <= N; ++u) 
        if (color[u] == NONE) 
            ans += coloring(u);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int M;
    cin >> M;

    while (M--)
    {
        int N, p, e;
        cin >> N;

        memset(color, 0, sizeof(color));

        for (int u = 1; u <= N; ++u)
            adj[u].clear();

        for (int u = 1; u <= N; ++u)
        {
            cin >> p;

            while (p--)
            {
                cin >> e;

                if (e < 1 or e > N)
                    continue;

                adj[u].push_back(e);
                adj[e].push_back(u);
            }
        }

        cout << solve(N) << '\n';
    }

    return 0;
}
