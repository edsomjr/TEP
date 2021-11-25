#include <bits/stdc++.h>

template<typename T>
struct Point {
    T x, y;

    Point(T xv = 0, T yv = 0) : x(xv), y(yv) {}
};

template<typename T>
T absolute_value(T x)
{
    if constexpr (std::is_floating_point_v<T>)
        return fabs(x);
    else
        return llabs(static_cast<long long>(x));
}

template<typename T>
double dist(const Point<T>& P, const Point<T>& Q) {
    return hypot(static_cast<double>(P.x - Q.x), static_cast<double>(P.y - Q.y));
}

template<typename T>
T dist2(const Point<T>& P, const Point<T>& Q) {
    return (P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y);
}

template<typename T>
T taxicab(const Point<T>& P, const Point<T>& Q) {
    return absolute_value(P.x - Q.x) + absolute_value(P.y - Q.y);
}

template<typename T>
T max_norm(const Point<T>& P, const Point<T>& Q) {
    return std::max(absolute_value(P.x - Q.x), absolute_value(P.y - Q.y));
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
