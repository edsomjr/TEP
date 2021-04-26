#include <bits/stdc++.h>

using namespace std;
using ll = long long;

pair<ll, ll> solve(ll n, ll m)
{
    auto A = n - (m - 1);
    auto kmax = A*(A - 1)/2;

    auto B = n / m, r = n % m;
    auto kmin = (m - r)*(B*(B - 1)/2) +
                r*((B + 1)*B/2);

    return {kmin, kmax};
}

int main()
{
    ll n, m;
    cin >> n >> m;

    auto [kmin, kmax] = solve(n, m);

    cout << kmin << ' ' << kmax << '\n';

    return 0;
}
