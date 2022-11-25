int solve(int N)
{
    int m = 1;

    for (int i = 2; i <= N; ++i)
        if (i*(i + 1)/2 <= N)
            m = i;

    return m;
}
