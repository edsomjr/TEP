ll rho(int N, int K)
{
    if (N == 0 and K == 0)
        return 1;

    if (N <= 0 or K <= 0)
        return 0;

    if (state[N][K] != -1)
        return state[N][K];

    auto res = rho(N - K, K) + rho(N - 1, K - 1);

    return (state[N][K] = res);
}

ll p(int N)
{
    ll count = 0;

    for (int i = 1; i <= N; ++i)
        count += rho(N, i);

    return count;
}
