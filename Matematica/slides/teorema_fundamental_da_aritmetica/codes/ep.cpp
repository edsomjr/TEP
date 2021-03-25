int E(int n, int p)
{
    int k = 0, base = p;

    while (base <= n)
    {
        k += n / base;
        base *= p;
    }

    return k;
}
