#include <iostream>
#include <vector>

using ll = long long;
const int MAX { 40 };

std::vector<ll> fibs(MAX + 1), calls(MAX + 1);

void precomp()
{
    fibs[0] = 0;
    fibs[1] = 1;

    calls[0] = calls[1] = 0;

    for (int i = 2; i <= MAX; ++i)
    {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
        calls[i] = calls[i - 1] + calls[i - 2] + 2;
    }
}

int main()
{
    precomp();

    int N;
    std::cin >> N;

    while (N--)
    {
        int X;
        std::cin >> X;

        std::cout << "fib(" << X << ") = " << calls[X]
            << " calls = " << fibs[X] << '\n';
    }

    return 0;
}
