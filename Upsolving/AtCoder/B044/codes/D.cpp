#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll oo { 1LL << 62 };

ll sum_digits(ll x, ll base)
{
    ll res = 0;

    while (x)
    {
        res += (x % base);
        x /= base;
    }

    return res;
}

ll solve(ll N, ll S)
{
    if (S > N)
        return -1;

    if (S == N)
        return N + 1;

    // (b - 1) tem que dividir a diferença N - S
    auto diff = N - S, ans = oo;

    for (ll d = 1; d * d <= diff; ++d)
    {
        if (diff % d == 0)
        {
            auto base = d + 1;

            if (sum_digits(N, base) == S)
                ans = min(ans, base);

            auto k = diff / d;

            if (k != d)
            {
                base = k + 1;

                if (sum_digits(N, base) == S)
                    ans = min(ans, base);
            }
        }
    }

    return ans == oo ? -1 : ans;
}

int main() {
    ll N, S;
    cin >> N >> S;

    cout << solve(N, S) << '\n';

    return 0;
}
