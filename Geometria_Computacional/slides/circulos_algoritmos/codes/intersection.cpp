#include <variant>
#include <vector>

const int oo { 2000000000 };

template<typename T> std::variant<int, std::vector<Point<T>>>
intersection(const Circle<T>& c1, const Circle<T>& c2)
{
    double d = distance(c1.C, c2.C);

    if (d > c1.r + c2.r or d < fabs(c1.r - c2.r))
        return 0;

    if (equals(d, 0.0) and equals(c1.r, c2.r))
        return oo;

    auto a = (c1.r * c1.r - c2.r * c2.r + d * d)/(2 * d);
    auto h = sqrt(c1.r * c1.r - a * a);

    auto x = c1.C.x + (a/d)*(c2.C.x - c1.C.x);
    auto y = c1.C.y + (a/d)*(c2.C.y - c1.C.y);

    auto P = Point<T> { x, y };

    x = P.x + (h/d)*(c2.C.y - c1.C.y);
    y = P.y - (h/d)*(c2.C.x - c1.C.x);

    auto P1 = Point<T> { x, y };

    x = P.x - (h/d)*(c2.C.y - c1.C.y);
    y = P.y + (h/d)*(c2.C.x - c1.C.x);

    auto P2 = Point<T> { x, y };

    return P1 == P2 ? std::vector<Point<T>> { P1 } : std::vector<Point<T>> { P1, P2 };
}
