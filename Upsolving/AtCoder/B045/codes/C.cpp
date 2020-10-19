#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(const string& s)
{
    ll ans = 0;

    for (int p = 0; p < (1 << (s.size() - 1)); ++p)
    {
        ll res = 0, x = 0;

        for (size_t i = 0; i < s.size(); ++i)
        {
            x *= 10;
            x += (s[i] - '0');

            if (p & (1 << i) or i == s.size() - 1)
            {
                res += x;
                x = 0;
            }
        }

        ans += res;
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    auto ans = solve(s);

    cout << ans << '\n';

    return 0;
}
