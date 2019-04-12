template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    // Definição dos métodos area() e perimeter()

    double inradius() const
    {
        return (2 * area()) / perimeter();
    }

    Point<T> incenter() const
    {
        auto P = perimeter();
        auto x = (a*A.x + b*B.x + c*C.x)/P;
        auto y = (a*A.y + b*B.y + c*C.y)/P;

        return { x, y };
    }
};
