template<typename T>
struct Line {
    bool vertical;
    T m, b;

    Line(const Point<T>& P, const Point<T>& Q) : vertical(false)
    {
        if (equals(P.x, Q.x))
        {
            vertical = true;
            b = P.x;
        } else
        {
            m = (Q.y - P.y)/(Q.x - P.x)
            b = P.y - m * P.x
        }
    }
};
