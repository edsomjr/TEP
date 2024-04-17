#include <bits/stdc++.h>

template<typename T>
bool equals(T a, T b)
{
    constexpr double EPS { 1e-9 };

    return std::is_floating_point<T>::value ?  fabs(a - b) < EPS : a == b;
}

template<typename T>
struct Point {
    T x = 0, y = 0;

    bool operator==(const Point<T>& p) const noexcept {
        return equals(x, p.x) && equals(y, p.y);
    }

    bool operator!=(const Point<T>& p) const noexcept {
        return not (*this == p);
    }
};

int main()
{
    Point<double> p { 1, 2 }, q { 3*1.0/3, 2 };

    if (p == q)
        p.x = q.y;

    std::cout << "p = (" << p.x << ", " << p.y << ")\n";

    return 0;
}
