// Definição da classe Point

template<typename T>
struct Line {
    T a, b, c;

    Line(const Point& P, const Point& Q)
        : a(P.y - Q.y), b (Q.x - P.x), c(P.x * Q.y - Q.x * P.y)
    {
    }
};
