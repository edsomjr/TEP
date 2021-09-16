#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };

vector<ii> adj[MAX];

void dfs(int u, int color, vector<int>& cs)
{
    if (cs[u] > -1)
        return;

    cs[u] = color;

    for (auto [v, w] : adj[u])
    {
        if (w % 2 == 0)
            dfs(v, color, cs);
        else
            dfs(v, 1 - color, cs);
    }
}

vector<int> solve(int N)
{
    vector<int> cs(N + 1, -1);
    
    dfs(1, 0, cs);

    return cs;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int u, v, w;

    for (int i = 0; i < N; ++i)
    {
        cin >> u >> v >> w;

        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    auto ans = solve(N);

    for (int i = 1; i <= N; ++i)
        cout << ans[i] << '\n';

    return 0;
}

