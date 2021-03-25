#include <bits/stdc++.h>

using namespace std;

vector<int> composite(int m)
{
    vector<int> cs;

    for (int n = 2; n < m; ++n)
        for (int d = 2; d * d <= n; ++d)
            if (n % d == 0)
            {
                cs.push_back(n);
                break;
            }

    return cs;
}

unsigned long long power(int a, int n)
{
    unsigned long long res = 1;

    while (n--)
        res *= a;

    return res;
}

set<unsigned long long> solve()
{
    auto cs = composite(64);
    set<unsigned long long> ans;
 
    for (int n = 1; n < (1 << 16); ++n)
    {
        for (auto c : cs)
            if (c*log2(n) < 64)
                ans.insert(power(n, c));
    }

    return ans;
}

int main()
{
    auto ans = solve();

    for (auto n : ans)
        cout << n << '\n';

    return 0;
}
