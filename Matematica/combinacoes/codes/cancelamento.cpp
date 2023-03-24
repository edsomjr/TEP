#include <bits/stdc++.h>

using namespace std;

const int MAX { 10000010 };

vector<long long> sieve(long long N)
{
    bitset<MAX> sieve;
    vector<long long> ps { 2, 3 };

    sieve.set();

    for (long long i = 5, step = 2; i <= N; i += step, step = 6 - step)
    {
        if (sieve[i])
        {
            ps.push_back(i);

            for (long long j = i * i; j <= N; j += 2*i)
                sieve[j] = false;
        }
    }

    return ps;
}

long long E(long long n, long long p)
{
    long long res = 0, base = p;

    while (base <= n)
    {
        res += n / base;
        base *= p;
    }

    return res;
}

long long binom(int n, int m, const vector<long long>& primes)
{
    if (n < m)
        return 0;

    long long res = 1;

    for (auto p : primes) {
        if (p > n)
            break; 

        for (int k = E(n, p) - E(m, p) - E(n - m, p); k > 0; --k)
            res *= p;
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;

    auto primes = sieve(n);

    cout << binom(n, m, primes) << '\n';

    return 0;
}
