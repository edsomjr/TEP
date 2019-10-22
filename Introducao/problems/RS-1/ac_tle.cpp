#include <iostream>

int fibonacci(int X, long long& calls)
{
    if (X == 0 || X == 1)
        return X;

    auto A = fibonacci(X - 1, calls);
    auto B = fibonacci(X - 2, calls);

    calls += 2;

    return A + B;
}

int main()
{
    int N;
    std::cin >> N;

    while (N--)
    {
        int X;
        std::cin >> X;

        long long calls = 0;
        auto ans = fibonacci(X, calls);

        std::cout << "fib(" << X << ") = " << calls 
            << " calls = " << ans << '\n';
    }

    return 0;
}
