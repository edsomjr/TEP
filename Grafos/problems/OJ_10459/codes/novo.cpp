#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 5010 };

vector<int> adj[MAX];

int dfs(int u, int p, vector<int>& hs, vector<int>& ps)
{
    int h = 0;

    for (auto v : adj[u])
        if (v != p)
            h = max(h, dfs(v, u, hs, ps));

    ps[u] = p;

    return hs[u] = h + 1;
}
    
pair<vector<int>, vector<int>> solve(int N)
{
    vector<int> hs(N + 1), ps(N + 1);
    hs[1] = 1;

    dfs(1, 0, hs, ps);

    queue<int> q;
    map<ii, int> ys;
    vector<set<ii>> opt(N + 1);

    map<int, vector<int>> ans;

    q.push(1);

    while (not q.empty())
    {
        auto u = q.front();
        q.pop();

        int H = 0;

        for (auto v : adj[u])
        {
            if (v != ps[u])
            {
                ys[ii(u, v)] = 1 + hs[v];
                q.push(v);
            } else
            {
                auto [y, w] = *opt[v].rbegin();

                if (w == u)
                {
                    if (opt[v].size() > 1lu)
                    {
                        auto [z, _] = *opt[v].begin();
                        ys[ii(u, v)] = 1 + z;
                    } else
                        ys[ii(u, v)] = 1;
                } else
                {
                    ys[ii(u, v)] = 1 + y;
                }
            }

            opt[u].emplace(ys[ii(u, v)], v);

            if (opt[u].size() > 2lu)
                opt[u].erase(opt[u].begin());

            H = max(H, ys[ii(u, v)]);
        }

        ans[H].emplace_back(u);
    }
    
    auto best = ans.begin()->second;
    auto worst = ans.rbegin()->second;

    sort(best.begin(), best.end());
    sort(worst.begin(), worst.end());

    return { best, worst };
}

int main()
{
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N)
    {
        for (int u = 1; u <= N; ++u)
            adj[u].clear();

        for (int u = 1; u <= N; ++u)
        {
            int K;
            cin >> K;

            while (K--)
            {
                int v;
                cin >> v;

                adj[u].push_back(v);
            }
        }

        auto [best, worst] = solve(N);

        cout << "Best Roots  :";

        for (auto u : best)
            cout << ' ' << u;

        cout << "\nWorst Roots :";

        for (auto u : worst)
            cout << ' ' << u;

        cout << '\n';
    }

    return 0;
}
