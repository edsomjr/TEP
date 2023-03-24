ll sigma(int N, int M)
{
    if (N == 0 or M == 1)
        return 1;

    if (M == 0)
        return 0;

    if (dp[N][M] != -1)
        return dp[N][M];

    auto res = sigma(N, M - 1);

    if (N >= M)
        res += sigma(N - M, M);

    return (dp[N][M] = res);
}

ll p(int N) { return sigma(N, N); }
