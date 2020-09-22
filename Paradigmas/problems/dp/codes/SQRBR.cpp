#include <bits/stdc++.h>

using namespace std;

const int MAX { 25 };

int st[2*MAX][2*MAX];

int dp(int i, int open, int N, const set<int>& xs)
{
    if (i == N)
        return open ? 0 : 1;

    if (st[i][open] != -1)
        return st[i][open];

    auto res = dp(i + 1, open + 1, N, xs);

    if (xs.count(i) == 0 and open)
        res += dp(i + 1, open - 1, N, xs);

    st[i][open] = res;
    return res;
}

int solve(int N, const set<int>& xs)
{
    memset(st, -1, sizeof st);

    return dp(0, 0, 2*N, xs);
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int N, K;
        cin >> N >> K;

        set<int> xs;

        for (int i = 0; i < K; ++i)
        {
            int x;
            cin >> x;

            xs.insert(x - 1);
        }

        auto ans = solve(N, xs);

        cout << ans << '\n';
    }

    return 0;
}
