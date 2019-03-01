#include <iostream>

int fib(int n, int m)
{
    if (n < 2)
        return n;

    int M = (1 << m);
    int a = 0, b = 1;

    for (int i = 2; i <= n; ++i)
    {
        auto temp = (a + b) % M;
        a = b;
        b = temp;
    }

    return b;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n, m;

    while (std::cin >> n >> m)
    {
        auto ans = fib(n, m);

        std::cout << ans << '\n';
    }

    return 0;
}
