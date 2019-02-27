#include <iostream>

int fib(int n)
{
    if (n < 2)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n, m;

    while (std::cin >> n >> m)
    {
        int M = (1 << m);
        auto ans = fib(n) % M;

        std::cout << ans << '\n'
    }

    return 0;
}
