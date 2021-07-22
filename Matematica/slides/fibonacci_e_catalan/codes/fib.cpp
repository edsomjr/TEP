long long recursive_fibonacci(long long n)
{
    if (n == 0 or n == 1)
        return n;

    return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}
