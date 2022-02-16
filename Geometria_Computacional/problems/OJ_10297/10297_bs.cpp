#include <bits/stdc++.h>

using namespace std;

const double PI { acos(-1.0) }, EPS { 1e-6 };

double solve(double D, double V)
{
    auto L = (PI * D * D * D)/4.0 - V;
    auto a = 0.0, b = D, d = 0.0;

    while (a <= b)
    {
        d = (a + b)/2;
        auto R = 2*((PI/3.0)*((D - d)/2.0)*(D*D + D*d + d*d)/4.0) + PI*(d * d * d)/4.0;

        if (fabs(L - R) < EPS)
            break;
        else if (L > R)
            a = d;
        else
            b = d;
    }

    return d;
}

int main()
{
    int D, V;

    while (cin >> D >> V, D | V)
    {
        auto ans = solve(D, V);

        cout.precision(3);
        cout << fixed << ans << '\n';
    }

    return 0;
}
