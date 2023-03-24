long long binom(int n, int m)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = dp[i][i] = 1;

        for (int j = 1; j < i; ++j)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }

    return dp[n][m];
} 
