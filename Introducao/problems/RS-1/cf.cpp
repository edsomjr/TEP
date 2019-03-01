#include <iostream>
#include <map>

using ll = long long;

std::map<ll, ll> fibs;

ll fib(ll n, ll M)
{
    if (fibs.count(n))
        return fibs[n];

    ll k = (n + 1)/2;

    fibs[n] = n & 1 ? 
        (fib(k, M)*fib(k, M) + fib(k - 1, M)*fib(k - 1, M)) % M : 
        ((2*fib(k - 1, M) + fib(k, M))*fib(k, M)) % M;

    return fibs[n];
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n, m;

    while (std::cin >> n >> m)
    {
        fibs.clear();
        auto M = (1LL << m);

        fibs[0] = 0;
        fibs[1] = 1 % M;

        std::cout << fib(n, M) << '\n';
    }

    return 0;
}
