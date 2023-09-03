long long sum_of_divisors(long long n)
{
    long long res = 0;

    for (long long d = 1; d * d <= n; ++d)
    {
        if (n % d == 0)
        {
            long long k = n / d;

            res += (d == k ? d : d + k);
        }
    }

    return res;
}
