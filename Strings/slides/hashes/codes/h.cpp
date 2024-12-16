int f(char c)
{
    return c - 'a' + 1;
}

int h(const string& s)
{
    int N = s.size();
    long long ans = 0, p = 31, q = 1'000'000'007;

    for (int i = N - 1; i >= 0; --i)
    {
        ans = (ans * p) % q;
        ans = (ans + f(c)) % q;
    }

    return ans;
}
