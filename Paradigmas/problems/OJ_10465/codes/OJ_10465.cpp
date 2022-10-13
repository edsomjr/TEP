#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 10010 };

ii st[MAX];

ii dp(int t, int N, int M)
{
    if (t == 0)
        return { 0, 0 };

    if (st[t] != ii(-1, -1))
        return st[t];

    auto res = ii(-t, 0);

    if (t >= N)
    {
        auto [beer, sol] = dp(t - N, N, M);
        res = max(res, ii(beer, sol + 1));
    }

    if (t >= M) 
    {
        auto [beer, sol] = dp(t - M, N, M);
        res = max(res, ii(beer, sol + 1));
    }

    return (st[t] = res);
}

ii solve(int N, int M, int T)
{
    memset(st, -1, sizeof st);
    return dp(T, N, M);
}

int main()
{
    ios::sync_with_stdio(false);

    int M, N, T;

    while (cin >> M >> N >> T)
    {
        auto [beer, ans] = solve(M, N, T);

        cout << ans;

        if (beer)
            cout << ' ' << -beer;

        cout << '\n';
    }

    return 0;
}
