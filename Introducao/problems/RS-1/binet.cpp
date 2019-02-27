#include <iostream>
#include <cmath>

int fib(int n)
{
    auto L = pow((1 + sqrt(5))/2, n);
    auto R = pow((1 - sqrt(5))/2, n);

    return (L - R)/sqrt(5);
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n, m;

    while (std::cin >> n >> m)
    {
        int M = (1 << m);
        auto ans = fib(n) % M;

        std::cout << ans << std::endl;
    }

    return 0;
}
