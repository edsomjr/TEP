#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 55 };

ll st[MAX][MAX][MAX*MAX];

ll dp(int i, int m, int sum, int N, const vector<int>& xs)
{
    if (i == N)
        return (sum == 0 and m == 0 ? 1 : 0);

    if (st[i][m][sum] != -1)
        return st[i][m][sum];

    auto res = dp(i + 1, m, sum, N, xs);

    if (m and xs[i] <= sum)
        res += dp(i + 1, m - 1, sum - xs[i], N, xs);

    st[i][m][sum] = res;

    return res;
}

long long solve(int N, int A, const vector<int>& xs)
{
    memset(st, -1, sizeof st);

    long long ans = 0;

    for (int i = 1; i <= N; ++i)
        ans += dp(0, i, i*A, N, xs);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, A;
    cin >> N >> A;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, A, xs);

    cout << ans << '\n';

    return 0;
}
