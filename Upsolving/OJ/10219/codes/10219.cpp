#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k)
{
    auto logn = 0.0, logk = 0.0;

    for (int i = n; i > n - k; i--)
        logn += log10(i);

    for (int i = 2; i <= k; i++)
        logk += log10(i);

    int ans = (int) floor(logn - logk + 1);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, k;

    while (cin >> n >> k)
    {
        auto ans = solve(n, k);
        cout << ans << endl;
    }

    return 0;
}

