#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;

    ll p = b / x, q = (a - 1)/x;

    auto ans = a > 0 ? p - q : p + 1;

    cout << ans << '\n';

    return 0;
}
