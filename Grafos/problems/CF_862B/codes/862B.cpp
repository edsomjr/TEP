// Codeforces Round #435 (Div. 2) - Problem B: Mahmoud and Ehab and the bipartiteness (http://codeforces.com/problemset/problem/862/B)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 100010 };

vector<int> adj[MAX], color(MAX, -1);

ll solve(int N)
{
    queue<int> q; q.push(1);
    color[1] = 1;

    while (not q.empty()) {
        auto u = q.front(); q.pop();

        for (auto v : adj[u])
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            }
    }

    auto blue = accumulate(color.begin() + 1, color.begin() + N + 1, 0LL);
    auto green = N - blue, ans = (blue * green) - (N - 1);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    } 

    auto ans = solve(N);

    cout << ans << '\n';

    return 0;
}
