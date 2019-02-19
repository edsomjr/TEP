// Definição da classe Point

template<typename T>
struct Vector
{
    T x, y;

    Vector(T xv, T yv) : x(xv), y(yv) {}

    Vector(const Point& A, const Point& B) 
        : x(B.x - A.x), y(B.y - A.y) {}
};
