long long solve(long long N)
{
    long long m = 1;

    for (long long i = 2; i * i <= 2*N; ++i)
        if (i*(i + 1)/2 <= N)
            i = m;

    return m;
}
