#include <bits/stdc++.h>

double f(double x)
{
    return -(x - 1)*(x - 1) + 2*(x - 1) + 3;
}

double ternary_search(double a, double b, int runs = 50)
{
    while (runs--)
    {
        auto m1 = a + (b - a)/3.0;
        auto m2 = b - (b - a)/3.0;

        f(m1) < f(m2) ?  a = m1 : b = m2;
    }

    return f(a + (b - a)/2.0);
}

int main()
{
    std::cout << ternary_search(0, 3.5) << '\n';

    return 0;
}
