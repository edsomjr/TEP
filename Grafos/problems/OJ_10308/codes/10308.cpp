#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 10010 }, oo { 1000000010 };
vector<ii> adj[MAX];

ii bfs(int s, int N)
{
    vector<int> dist(N + 1, oo); dist[s] = 0;
    queue<int> q; q.push(s);

    while (not q.empty()) {
        auto u = q.front(); q.pop();

        for (auto [v, w] : adj[u]) {
            if (dist[v] == oo) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }

    auto w = (int) (max_element(dist.begin() + 1, dist.end()) - dist.begin());

    return { w, dist[w] };
}

int diameter(int N)
{
    auto [v, _] = bfs(1, N);
    auto [w, D] = bfs(v, N);

    return D;
}

int solve(int N)
{
    auto D = diameter(N);

    return D;
}

int main()
{
    ios::sync_with_stdio(false);

    string line;
    int N = 0;

    while (getline(cin, line))
    {
        if (line.empty())
        {
            auto d = solve(N);

            cout << d << '\n';

            for (int u = 1; u <= N; ++u)
                adj[u].clear();

            N = 0;
        } else
        {
            istringstream iss(line);

            int u, v, w;
            iss >> u >> v >> w;

            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);

            N = max(N, u);
            N = max(N, v);
//    cout << "--- u = " << u << ", v = " << v << ", w = " << w << '\n';
 //   cout << "    N = " << N << '\n';
        }
    }

    auto d = solve(N);

    cout << d << '\n';


    return 0;
} 
