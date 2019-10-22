// Definição da estrutura Point

template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    Point<T> barycenter() const
    {
        auto x = (A.x + B.x + C.x) / 3.0;
        auto y = (A.y + B.y + C.y) / 3.0;

        return Point<T> { x, y };
    }
};
