#include <bits/stdc++.h>

using namespace std;

const int MOD { 1000000007 };

int solve(int x, int y, int n)
{
    vector<int> seq { -y + x, x, y, y - x, -x, -y };

    auto res = seq[n % seq.size()] % MOD;

    return res < 0 ? res + MOD : res;
}

int main()
{
    int x, y, n;
    cin >> x >> y >> n;

    cout << solve(x, y, n) << '\n';

    return 0;
}
