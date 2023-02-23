long long number_of_divisors(long long n)
{
    long long res = 0;

    for (long long d = 1; d * d <= n; ++d)
    {
        if (n % d == 0)
            res += (d == n/d ? 1 : 2);
    }

    return res;
}
