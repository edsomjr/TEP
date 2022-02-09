// Interseção entre o círculo c e a reta que passa por P e Q
template<typename T> std::vector<Point<T>>
intersection(const Circle<T>& c, const Point<T>& P, const Point<T>& Q)
{
    auto a = pow(Q.x - P.x, 2.0) + pow(Q.y - P.y, 2.0);
    auto b = 2*((Q.x - P.x) * (P.x - c.C.x) + (Q.y - P.y) * (P.y - c.C.y));
    auto d = pow(c.C.x, 2.0) + pow(c.C.y, 2.0) + pow(P.x, 2.0) 
        + pow(P.y, 2.0) + 2*(c.C.x * P.x + c.C.y * P.y);
    auto D = b * b - 4 * a * d;

    if (D < 0)
        return { };
    else if (equals(D, 0))
    {
        auto u = -b/(2*a);
        auto x = P.x + u*(Q.x - P.x);
        auto y = P.y + u*(Q.y - P.y);
        return { Point { x, y } };
    }

    auto u = (-b + sqrt(D))/(2*a);

    auto x = P.x + u*(Q.x - P.x);
    auto y = P.y + u*(Q.y - P.y);

    auto P1 = Point { x, y };

    u = (-b - sqrt(D))/(2*a);

    x = P.x + u*(Q.x - P.x);
    y = P.y + u*(Q.y - P.y);

    auto P2 = Point { x, y };

    return { P1, P2 };
}
