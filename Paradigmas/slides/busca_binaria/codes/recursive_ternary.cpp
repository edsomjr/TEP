#include <bits/stdc++.h>

double f(double x)
{
    return -(x - 1)*(x - 1) + 2*(x - 1) + 3;
}

double ternary_search(double a, double b, double eps = 1e-6)
{
    if (fabs(b - a) < eps)
        return f(a + (b - a)/2.0);
    
    auto m1 = a + (b - a)/3.0;
    auto m2 = b - (b - a)/3.0;

    if (f(m1) < f(m2) 
        return ternary_search(m1, b, eps);
    else
        return ternary_search(a, m2, eps);
}

int main()
{
    std::cout << ternary_search(0, 3.5) << '\n';

    return 0;
}
