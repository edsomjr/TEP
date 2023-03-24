long long sum_of_divisors(int n, const vector<int>& primes)
{
    auto fs = factorization(n, primes);
    long long res = 1;

    for (auto [p, k] : fs)
    {
        long long pk = p;

        while (k--)
            pk *= p;

        res *= (pk - 1)/(p - 1);
    }

    return res;
}
