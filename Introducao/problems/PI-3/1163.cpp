#include <iostream>
#include <cmath>

using namespace std;

const double PI { 3.14159 };
const double g { 9.80665 };

double zero(double h, double v)
{
    double c = h;
    double b = v;
    double a = -g/2;

    double delta = b*b - 4*a*c;

    double t1 = (-b + sqrt(delta))/(2*a);
    double t2 = (-b - sqrt(delta))/(2*a);

    return t1 > 0 : t1 : t2;
}

double dist(double h, double vy, double vx)
{
    double t = zero(h, vy);
    return vx*t;
}

int main()
{
    double h, alpha, v;
    int p1, p2, n;

    while (cin >> h >> p1 >> p2 >> n)
    {
        while (n--)
        {
            cin >> alpha >> v;

            double vy = sin(alpha*PI/180.0)*v;
            double vx = cos(alpha*PI/180.0)*v;
            double d = dist(h, vy, vx);

            printf("%.5f -> ", d);

            if (d >= p1 and d <= p2)
                printf("DUCK\n");
            else
                printf("NUCK\n");
        }
    }

    return 0;
}

