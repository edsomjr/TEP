#include <iostream>
#include <cmath>

using namespace std;

const int R { 6440 };
const double PI = acos(-1.0);

double arc(double s, double a)
{
    auto r = s + R;

    return r*a;
}

double chord(double s, double a)
{
    auto r = s + R;

    return 2*r*sin(a/2);
}

int main()
{
    double s, a;
    string unit;

    while (cin >> s >> a >> unit)
    {
        if (unit[0] == 'm')
            a /= 60;

        if (a > 180)
            a = 360 - a;

        a *= (PI/180.0);

        printf("%.6f %.6f\n", arc(s, a), chord(s, a));
    }

    return 0;
}
