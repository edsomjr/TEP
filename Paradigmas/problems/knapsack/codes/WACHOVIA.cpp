#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using ll = long long;

const int MAXN { 60 }, MAXM { 1010 };

ll st[MAXN][MAXM];

ll dp(int i, int m, int M, const vector<ii>& cs)
{
    if (i < 0)
        return 0;

    if (st[i][m] != -1)
        return st[i][m];

    auto res = dp(i - 1, m, M, cs);
    auto w = cs[i].first, v = cs[i].second;

    if (w <= m)
        res = max(res, dp(i - 1, m - w, M, cs) + v);

    st[i][m] = res;
    return res;
}

ll knapsack(int M, const vector<ii>& cs)
{
    memset(st, -1, sizeof st);

    return dp((int) cs.size() - 1, M, M, cs);
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int M, N;
        cin >> M >> N;

        vector<ii> cs(N);

        for (int i = 0; i < N; ++i)
            cin >> cs[i].first >> cs[i].second;

        cout << "Hey stupid robber, you can get " 
             << knapsack(M, cs) << ".\n";
    }

    return 0;
}
