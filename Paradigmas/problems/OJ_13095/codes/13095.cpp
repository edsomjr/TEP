#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

vector<int>
solve(int N, const vector<int>& xs, vector<ii>& qs)
{
    vector<vector<int>> ps(10, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; ++i)
    {
        for (int d = 0; d <= 9; ++d)
            ps[d][i] += ps[d][i - 1];

        ps[xs[i]][i] += 1;
    }
    
    vector<int> ans;

    for (auto [L, R] : qs)
    {
        int res = 0;

        for (int d = 0; d <= 9; ++d)
            res += (ps[d][R] - ps[d][L - 1] > 0 ? 1 : 0);

        ans.push_back(res);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int N;
    
    while (cin >> N) {
        vector<int> xs(N + 1);

        for (int i = 1; i <= N; ++i)
            cin >> xs[i];

        int Q;
        cin >> Q;

        vector<ii> qs(Q);

        for (int i = 0; i < Q; ++i)
            cin >> qs[i].first >> qs[i].second;

        auto ans = solve(N, xs, qs);

        for (auto x : ans)
            cout << x << '\n'; 
    }

    return 0;
}
