#include <iostream>
#include <cmath>

const double EPS { 1e-9 };

template<typename T>
bool equals(T a, T b)
{
    if (std::is_floating_point<T>::value)
        return fabs(a - b) < EPS;
    else
        return a == b;
}

template<typename T>
struct Point {
    T x, y;

    Point(T xv = 0, T yv = 0) : x(xv), y(yv) {}

    bool operator==(const Point& p) const {
        return equals(x, p.x) && equals(y, p.y);
    }

    bool operator!=(const Point& p) const {
        return not (*this == p);
    }
};

int main() {
    Point<double> p(1, 2), q(3*1.0/3, 2);

    if (p == q)
        p.x = q.y;

    std::cout << "p = (" << p.x << ", " << p.y << ")\n";

    return 0;
}
