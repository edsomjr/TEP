#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 1010 }, oo { 1000000010 };
vector<int> adj[MAX];
int to_leaf[MAX], max_length[MAX];

pair<int, int> bfs(int s, int N)
{
    vector<int> dist(N + 1, oo); dist[s] = 0;
    queue<int> q; q.push(s);
    int last = s;

    while (not q.empty()) {
        auto u = q.front(); q.pop();
        last = u;

        for (auto v : adj[u]) {
            if (dist[v] == oo) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
   }

    return { last, dist[last] };
}

int diameter(int N)
{
    auto [v, _] = bfs(1, N);
    auto [w, D] = bfs(v, N);

    return D;
}

int main()
{
    vector<ii> edges { ii(1, 7), ii(3, 7), ii(7, 4), ii(4, 2), 
        ii(4, 5), ii(5, 6) };

    for (const auto& [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << diameter(7) << endl;

    return 0;
} 
