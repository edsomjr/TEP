// Definição da função de comparação equals e da classe Point

template<typename T>
struct Line {
    T m, b;
    bool vertical;

    Line(const Point& P, const Point& Q) : vertical(false)
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
