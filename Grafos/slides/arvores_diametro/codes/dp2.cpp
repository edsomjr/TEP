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

        ds2 = max(ds2, to_leaf[v]);
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
    vector<ii> edges { ii(1, 7), ii(3, 7), ii(7, 4), ii(4, 2), 
        ii(4, 5), ii(5, 6) };

    for (const auto& [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 4
    cout << diameter(4, 7) << endl;

    // 0 0 0 2 1 0 1
    for (int u = 1; u <= 7; ++u)
        cout << to_leaf[u] << (u == 7 ? '\n' : ' ');

    // 0 0 0 4 1 0 2
    for (int u = 1; u <= 7; ++u)
        cout << max_length[u] << (u == 7 ? '\n' : ' ');

    return 0;
} 
