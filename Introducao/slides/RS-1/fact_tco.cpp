int factorial(int n, int ans = 1)
{
    if (n == 0)
        return ans;

    return factorial(n - 1, n * ans);
}
