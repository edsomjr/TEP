#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 1000005 };
vector<int> vs[MAX];

vector<int> solve(int N, const vector<int>& xs, const vector<ii>& qs)
{
    for (int i = 0; i < MAX; ++i)
        vs[i].clear();

    for (int i = 1; i <= N; ++i)
        vs[xs[i]].push_back(i);

    vector<int> ans;

    for (auto [k, v] : qs) 
        ans.push_back(k <= (int) vs[v].size() ? vs[v][k - 1] : 0);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;

    while (cin >> N >> M)
    {
        vector<int> xs(N + 1);

        for (int i = 1; i <= N; ++i)
            cin >> xs[i];

        vector<ii> qs(M);

        for (int i = 0; i < M; ++i)
            cin >> qs[i].first >> qs[i].second;

        auto ans = solve(N, xs, qs);

        for (const auto& x : ans)
            cout << x << '\n';
    }

    return 0;
}
