long long solve(long long N)
{
    long long m = 1, a = 1, b = N;

    while (a <= b)
    {
        long long c = a + (b - a)/2;

        if (c*(c + 1)/2 <= N)
        {
            m = c;
            a = c + 1;
        } else
            b = c - 1;
    }

    return m;
}
