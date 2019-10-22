#include <cmath>
#include <iostream>

template<typename T>
struct Point {
    T x, y;

    Point(T xv = 0, T yv = 0) : x(xv), y(yv) {}
};

template<typename T>
double dist(const Point<T>& P, const Point<T>& Q)
{
    return hypot(P.x - Q.x, P.y - Q.y);
}

template<typename T>
T dist2(const Point<T>& P, const Point<T>& Q)
{
    return (P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y);
}

template<typename T>
T taxicab(const Point<T>& P, const Point<T>& Q)
{
    if (std::is_floating_point<T>::value)
        return fabs(P.x - Q.x) + fabs(P.y - Q.y);
    else
        return llabs(P.x - Q.x) + llabs(P.y - Q.y);
}

template<typename T>
T max_norm(const Point<T>& P, const Point<T>& Q)
{
    if (std::is_floating_point<T>::value)
        return std::max(fabs(P.x - Q.x), fabs(P.y - Q.y));
    else
        return std::max(llabs(P.x - Q.x), llabs(P.y - Q.y));
}

int main()
{
    Point<int> P, Q(2, 3);

    std::cout << "Euclidiana: " << dist(P, Q) << '\n';
    std::cout << "Quadrado: " << dist2(P, Q) << '\n';
    std::cout << "Motorista de táxi: " << taxicab(P, Q) << '\n';
    std::cout << "Norma do máximo: " << max_norm(P, Q) << '\n';

    return 0;
}
