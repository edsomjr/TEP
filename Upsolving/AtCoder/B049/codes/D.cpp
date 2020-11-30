#include <bits/stdc++.h>

using namespace std;

const int MAX { 200010 };

vector<int> adj_c[MAX], adj_r[MAX];
bitset<MAX> found;

void dfs(int u, int color, vector<int>& cs)
{
    if (found[u])
        return;

    found[u] = true;
    cs[u] = color;

    for (auto v : adj_c[u])
        dfs(v, color, cs);
}

void dfs2(int u, map<int, vector<int>>& xs, const vector<int>& cs)
{
    if (found[u])
        return;

    found[u] = true;
    xs[cs[u]].push_back(u);

    for (auto v : adj_r[u])
        dfs2(v, xs, cs);
}

vector<int> solve(int N)
{
    vector<int> ans(N + 1), colors(N + 1);
    int color = 1;

    for (int u = 1; u <= N; ++u)
        if (not found[u])
            dfs(u, color++, colors);
    
    found.reset();
    
    for (int u = 1; u <= N; ++u)
    {
        if (not found[u])
        {
            map<int, vector<int>> xs;

            dfs2(u, xs, colors);

            for (auto& [c, ys] : xs)
                for (auto y : ys)
                    ans[y] = (int) ys.size();
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, K, L;
    cin >> N >> K >> L;

    while (K--)
    {
        int p, q;
        cin >> p >> q;

        adj_c[p].push_back(q);
        adj_c[q].push_back(p);
    }

    while (L--)
    {
        int p, q;
        cin >> p >> q;

        adj_r[p].push_back(q);
        adj_r[q].push_back(p);
    }

    auto ans = solve(N);

    for (int i = 1; i <= N; ++i)
        cout << ans[i] << (i == N ? '\n' : ' ');

    return 0;
}
