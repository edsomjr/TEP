#include <bits/stdc++.h>

using namespace std;

const double eps { 1e-6 };

double f(double x, int p, int q, int r, int s, int t, int u)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
    int p, q, r, s, t, u;

    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) > 0)
    {
        auto a = 0.0, b = 1.0;
        auto ya = f(a, p, q, r, s, t, u);
        auto yb = f(b, p, q, r, s, t, u);

        if (ya * yb > 0)
        {
            printf("No solution\n");
            continue;
        }

        while (fabs(ya - yb) > eps)
        {
            auto c = (a + b)/2;
            auto yc = f(c, p, q, r, s, t, u);

            if (yc * ya > 0)
            {
                a = c;
                ya = yc;
            } else
            {
                b = c;
                yb = yc;
            }
        }

        printf("%.4f\n", a);
    }

    return 0;
}
