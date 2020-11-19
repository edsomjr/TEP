#include <bits/stdc++.h>

using namespace std;

const int MAXN { 2010 }, MAXM { 2010 };

int st[MAXN][MAXM];

int dp(int i, int m, int M, const vector<int>& xs)
{
    if (i < 0)
        return m == 0 ? 1 : 0;

    if (st[i][m] != -1)
        return st[i][m];

    auto res = dp(i - 1, m, M, xs);

    if (xs[i] <= m)
        res |= dp(i - 1, m - xs[i], M, xs);

    st[i][m] = res;
    return res;
}

bool subset_sum(int S, const vector<int>& xs)
{
    memset(st, -1, sizeof st);

    return dp((int) xs.size() - 1, S, S, xs);
}

int main()
{
    vector<int> xs { 1, 4, 5, 8, 10 };

    cout << subset_sum(7, xs) << '\n';
    cout << subset_sum(13, xs) << '\n';

    return 0;
}
