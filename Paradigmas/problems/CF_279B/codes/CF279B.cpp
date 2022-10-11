#include <bits/stdc++.h>

using namespace std;

int solve(int N, int T, const vector<int>& xs) {
    auto ans = 0, L = 0, R = 0, t = T;

    while (L < N) {
        R = max(L, R);
        
        while (R < N and xs[R] <= t)
            t -= xs[R++];

        ans = max(ans, R - L);
        t = min(T, t + xs[L]);
        ++L;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, T;
    cin >> N >> T;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, T, xs);

    cout << ans << '\n';

    return 0;
}
