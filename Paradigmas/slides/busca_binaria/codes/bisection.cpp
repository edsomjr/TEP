#include <bits/stdc++.h>

using namespace std;
const double EPS { 1e-7 }, PI = acos(-1.0);

double bisection(const function<double(double)>& f, double a, double b)
{
    auto m = (a + b)/2.0, y = f(m);

    return fabs(y) < EPS ? m :
        (y*f(a) < 0 ? bisection(f, a, m) : bisection(f, m, b));
}

int main()
{
    auto f = [](double x) { return sin(x) - 0.8; };

    cout << setprecision(8) << bisection(f, 0, PI/2) << '\n';

    return 0;
}
