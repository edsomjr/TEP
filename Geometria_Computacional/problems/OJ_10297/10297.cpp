#include <bits/stdc++.h>

const double PI { acos(-1.0) };

double solve(double D, double V)
{
    return cbrt(D*D*D - 6.0*V/PI);
}

int main()
{
    int D, V;

    while (std::cin >> D >> V, D | V)
    {
        std::cout.precision(3);
        std::cout << std::fixed << solve(D, V) << '\n';
    }

    return 0;
}
