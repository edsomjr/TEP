#include <bits/stdc++.h>

using namespace std;

const int MAX = 210;
int color[MAX];
vector<int> adj[MAX];

int coloring(int s) {
    int blue = 0, green = 0;
    queue<int> q; q.push(s);
    color[s] = 1; ++blue;
    
    while (not q.empty()) {
        auto u = q.front(); q.pop();

        for (auto v : adj[u])
            if (color[v] == -1)
            {
                color[v] = 1 - color[u];
                blue += color[v]; green += (1 - color[v]);
                q.push(v);
            } else if (color[v] == color[u])
                return 0;
    }

    return max(blue, green);
}

int solve(int N)
{
    auto ans = 0;

    for (int u = 1; u <= N; ++u) 
        if (color[u] == -1) 
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

        memset(color, -1, sizeof(color));

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
