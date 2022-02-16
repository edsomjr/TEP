#include <bits/stdc++.h>

using namespace std;

double solve(double r1, double r2, double r3)
{
    auto a = r2 + r3;
    auto b = r1 + r3;
    auto c = r1 + r2;
    auto s = (a + b + c)/2.0;
    auto T = sqrt(s*(s - a)*(s - b)*(s - c));

    auto oa = acos((a*a - b*b - c*c)/(-2*b*c));
    auto Sa = 0.5*oa*r1*r1;
    auto ob = acos((b*b - a*a - c*c)/(-2*a*c));
    auto Sb = 0.5*ob*r2*r2;
    auto oc = acos((c*c - b*b - a*a)/(-2*b*a));
    auto Sc = 0.5*oc*r3*r3;

    auto G = T - Sa - Sb - Sc;

    return G;
}

int main()
{
    int k;
    scanf("%d", &k);

    while (k--)
    {
        double r1, r2, r3;
        scanf("%lf %lf %lf", &r1, &r2, &r3);

        printf("%.6f\n", solve(r1, r2, f3));
    }

    return 0;
}
