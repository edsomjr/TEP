// Definição da classe Point

template<typename T>
struct Vector
{
    T x, y;

    Vector(T xv, T yv) : x(xv), y(yv) {}

    Vector(const Point<T>& A, const Point<T>& B) 
        : x(B.x - A.x), y(B.y - A.y) {}
};
