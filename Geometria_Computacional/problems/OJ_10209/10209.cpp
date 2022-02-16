#include <bits/stdc++.h>

using namespace std;

const double PI { acos(-1.0) };

struct Circle
{
    double r;

    double arc(double theta) const
    {
        return theta * r;
    }

    double chord(double a) const
    {
        return 2 * r * sin(a/2);
    }

    double sector(double theta) const
    {
        return (theta * r * r)/2;
    }

    double segment(double a) const
    {
        auto c = chord(a);
        auto s = (r + r + c)/2.0;
        auto T = sqrt(s*(s - r)*(s - r)*(s - c));

        return sector(a) - T;
    }
};

int main()
{
    double a;

    while (scanf("%lf", &a) == 1)
    {
        Circle circle { a };

        double c = circle.chord(PI/6);
        double g = circle.segment(PI/6);

        double stripped = c * c + 4*g;
        double dotted = 4*(-stripped + (PI/2.0 - 1.0)*a*a)/2.0;
        double rest = a*a - stripped - dotted;

        printf("%.3f %.3f %.3f\n", stripped, dotted, rest);
    }

    return 0;
}
