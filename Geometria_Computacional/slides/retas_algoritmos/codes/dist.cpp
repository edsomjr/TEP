#include <cmath>
#include <iostream>

template<typename T>
struct Point {
    T x, y;
};

template<typename T>
struct Line {
    T a, b, c;

    double distance(const Point<T>& p) const        // Distância de p à reta
    {
        return fabs(a*p.x + b*p.y + c)/hypot(a, b);
    }

    Point<T> closest(const Point<T>& p) const       // Ponto mais próximo de p
    {
        auto den = (a*a + b*b);

        auto x = (b*(b*p.x - a*p.y) - a*c)/den;
        auto y = (a*(-b*p.x + a*p.y) - b*c)/den;

        return Point<T> { x, y };
    }
};

int main()
{
    Point<double> P { 1.0, 4.0 };
    Line<double> r { 1.0, -1.0, 0 };

    std::cout << "Distance: " << r.distance(P) << '\n';

    auto Q = r.closest(P);

    std::cout << "Closest: Q = (" << Q.x << ", " << Q.y << ")\n";

    return 0;
}
