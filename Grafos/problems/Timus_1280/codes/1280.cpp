// Times 1280 - Topological Sorting (https://acm.timus.ru/problem.aspx?space=1&num=1280)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

enum State { NOT_FOUND, FOUND, PROCESSED };
const int MAX { 200010 };

vector<int> adj[MAX];

bool dfs(int u, vector<int>& o, vector<int>& state)
{
    if (state[u] == PROCESSED)
        return true;

    if (state[u] == FOUND)
        return false;

    state[u] = FOUND;

    for (auto v : adj[u])
        if (not dfs(v, o, state))
            return false;

    state[u] = PROCESSED;
    o.emplace_back(u);

    return true;
}

vector<int> topological_sort(int N)
{
    vector<int> o, state(N + 1, NOT_FOUND);

    
    for (int u = 1; u <= N; ++u)
        if (state[u] == NOT_FOUND and not dfs(u, o, state))
            return { };

    reverse(o.begin(), o.end());

    return o;
}

string solve(int N, const vector<int>& xs)
{
    unordered_map<int, int> is;

    for (int i = 0; i < N; ++i)
        is[xs[i]] = i;

    for (int u = 1; u <= N; ++u)
        for (auto v : adj[u])
            if (is[u] > is[v])
                return "NO";

    return "YES";
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    while (M--)
    {
        int s, u;
        cin >> s >> u;

        adj[s].emplace_back(u);
    }

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, xs);

    cout << ans << '\n';

    return 0;
}
