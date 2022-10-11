#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(int N, const vector<int>& xs)
{
    ll ans = 0;
    auto L = 0, R = 0, x = 0;

    while (L < N)
    {
        R = max(L, R);
        
        while (R < N and (x & xs[R]) == 0) {
            x |= xs[R];
            ++R;
        }

        ans += (R - L);

        x &= ~xs[L];
        ++L;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, xs);

    cout << ans << endl;

    return 0;
}
