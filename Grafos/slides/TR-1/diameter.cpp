#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 1010 };
vector<int> adj[MAX];
int dist[MAX];

void dfs(int u, int p) {

    dist[u] = dist[p] + 1;

    for (const auto& v : adj[u]) {
        if (v == p)
            continue;

        dfs(v, u);
    }
}

int diameter(int u, int N)
{
    dist[0] = -1;

    // dist = 1 2 1 1 2 3 0
    dfs(u, 0); 

    auto it = max_element(dist + 1, dist + 1 + N);
    int w = it - dist;

    // dist = 4 3 4 2 1 0 3
    dfs(w, 0); 

    it = max_element(dist + 1, dist + 1 + N);

    return *it;
}

int main()
{
    vector<ii> edges { ii(1, 7), ii(3, 7), ii(7, 4), ii(4, 2), 
        ii(4, 5), ii(5, 6) };

    for (const auto& [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 4
    cout << diameter(7, 7) << endl;

    return 0;
} 
