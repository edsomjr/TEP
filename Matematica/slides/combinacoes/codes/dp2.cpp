long long binom(int n, int m)
{
    if (m > n)
        return 0;

    vector<long long> dp(m+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; ++i)
        for(int j = m; j > 0; --j)
            dp[j] = dp[j] + dp[j - 1];

	return dp[m];
}
