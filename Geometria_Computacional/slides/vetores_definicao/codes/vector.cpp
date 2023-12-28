template<typename T>
struct Vector
{
    T x = 0, y = 0;

    Vector(const Point<T>& A, const Point<T>& B) 
        : x(B.x - A.x), y(B.y - A.y) {}
};
