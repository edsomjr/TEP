#include <bits/stdc++.h>

using namespace std;

const int MAX { 1010 };

vector<int> adj[MAX];
bitset<MAX> found;

vector<int> solve(int N)
{
    vector<int> ans(N);
    queue<int> q;

    q.push(0);
    found[0] = true;
    ans[0] = 0;

    while (not q.empty())
    {
        auto u = q.front();
        q.pop();

        for (const auto& v : adj[u])
        {
            if (not found[v])
            {
                found[v] = true;        
                ans[v] = ans[u] + 1;
                q.push(v);
            }
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int test = 0; test < T; ++test)
    {
        found.reset();

        for (int i = 0; i < MAX; ++i)
            adj[i].clear();

        int P, D;
        cin >> P >> D;

        while (D--)
        {
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        auto ans = solve(P);

        if (test)
            cout << '\n';

        for (int i = 1; i < P; ++i)
            cout << ans[i] << '\n';
    }

    return 0;
}
