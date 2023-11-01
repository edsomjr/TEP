#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 2 * 1'00'000 + 1 };
vector<int> adj[MAX];
int to_leaf[MAX], max_length[MAX];

void dfs(int u, int p)
{
    int  ds1, ds2;
    ds1 = ds2 = -1;

    for (auto v : adj[u])
    {
        if (v == p)
            continue;

        if (ds1 < ds2) swap(ds1, ds2);

        dfs(v, u);

        ds1 = max(ds2, to_leaf[v]);
    }


    to_leaf[u] = max(ds1, ds2) + 1;
    max_length[u] = 2 + ds1 + ds2;
}

int diameter(int root, int N)
{
    dfs(root, 0); 

    int d = 0;

    for (int u = 1; u <= N; ++u)
        d = max(d, max_length[u]);

    return d;
}

int main()
{
    vector<ii> edges;
    int N;
    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        int u, v;
        cin >> u >> v; 
        edges.emplace_back(u, v);
    }

    for (const auto& [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 4
    cout << diameter(1, N) << endl;

    return 0;
} 
