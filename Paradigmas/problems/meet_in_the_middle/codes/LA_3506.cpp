#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 2510 };

ll as[MAX], bs[MAX], cs[MAX], ds[MAX], xs[MAX*MAX], ys[MAX*MAX];

ll solve(int N)
{
    ll ans = 0;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            xs[j + i*N] = as[i] + bs[j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ys[j + i*N] = cs[i] + ds[j];

    sort(ys, ys + N*N);

    for (int i = 0; i < N*N; i++)
    {
        auto p = equal_range(ys, ys + N*N, -xs[i]);
        ans += (p.second - p.first);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int test = 0; test < T; ++test)
    {
        int N;
        cin >> N;

        for (int i = 0; i < N; ++i)
            cin >> as[i] >> bs[i] >> cs[i] >> ds[i];

        if (test)
            cout << endl;

        cout << solve(N) << endl;
    }

    return 0;
}

