long long number_of_divisors(long long n)
{
    long long res = 0;

    for (long long i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            long long j = n / i;

            res += (i == j ? i : i + j);
        }
    }

    return res;
}
