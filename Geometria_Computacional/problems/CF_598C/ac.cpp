#include <iostream>

using ll = long long;

ll ext_gcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1, d = ext_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1*(a / b);

    return d;
}

int main()
{
    ll A, B, C;
    std::cin >> A >> B >> C;

    ll x, y, d = ext_gcd(A, B, x, y);

    if (C % d)
    {
        std::cout << -1 << '\n';
        return 0;
    }

    ll k = -C / d;
    x *= k;
    y *= k;

    std::cout << x << " " << y << '\n';

    return 0;
}
