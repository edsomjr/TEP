#include <bits/stdc++.h>

using namespace std;

const int MAX { 1010 };

bitset<MAX> found;

int dfs(int u, const vector<int>& ps)
{
    if (found[u])
        return u;

    found[u] = true;

    return dfs(ps[u], ps);
}

vector<int> solve(int N, const vector<int>& ps)
{
    vector<int> ans(N + 1);

    for (int u = 1; u <= N; ++u)
    {
        found.reset();
        ans[u] = dfs(u, ps);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> ps(N + 1);

    for (int i = 1; i <= N; ++i)
        cin >> ps[i];

    auto ans = solve(N, ps);

    for (int i = 1; i <= N; ++i)
        cout << ans[i] << (i == N ? '\n' : ' ');

    return 0;
}
