#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD { 998244353 };

ll is_square(ll n)
{
    ll a = 1, b = n;

    while (a <= b) {
        auto m = a + (b - a)/2;

        if (n/m == m and m*m == n)
            return m;
        else if (m < n/m)
            a = m + 1;
        else
            b = m - 1;
    }

    return -1;
}

ll is_cube(ll n)
{
    ll a = 1, b = n;

    while (a <= b) {
        auto m = a + (b - a)/2;

        if ((n/m)/m == m and m*m*m == n)
            return m;
        else if (m < (n/m)/m)
            a = m + 1;
        else
            b = m - 1;
    }

    return -1;
}

ll solve(const vector<ll>& as)
{
    map<ll, ll> fs, uniques;
    vector<ll> pqs;

    for (auto a : as)
    {
        auto s = is_square(a);

        if (s > 0)
        {
            auto p = is_square(s);

            // a = p^4 ou a = p^2
            p > 0 ?  fs[p] += 4 : fs[s] += 2; 
        } 
        else
        {
            auto c = is_cube(a);

            // a = p^3 ou a = pq
            c > 0 ?  (void) (fs[c] += 3) : pqs.push_back(a);
        }
    }

    for (auto x : pqs)
        for (auto y : pqs)
        {
            auto d = gcd(x, y);

            if (d > 1 and d < x and fs.count(d) == 0)
                fs[d] = 0;
        }
 
    for (auto x : pqs)
    {
        bool ok = false;

        for (auto [p, k] : fs)
            if (x % p == 0)
            {
                ++fs[p];
                ++fs[x / p];
                ok = true;
                break;
            }

        if (not ok)
            uniques[x]++;
    }

    ll ans = 1;

    for (auto [p, k] : fs)
        ans = (ans * (k + 1)) % MOD;

    for (auto [x, k] : uniques)
        ans = (ans * (k + 1)*(k + 1)) % MOD;

    return ans; 
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> as(N);

    for (int i = 0; i < N; ++i)
        cin >> as[i];

    auto ans = solve(as);

    cout << ans << '\n';

    return 0;
}
