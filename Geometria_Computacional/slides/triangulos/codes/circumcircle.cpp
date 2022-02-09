// Definição da estrutura Point e da função de distância
// entre pontos dist()

template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    // Definição do método area()

    double circumradius() const
    {
        auto a = dist(B, C);
        auto b = dist(A, C);
        auto c = dist(A, B);

        return (a * b * c)/(4 * area());
    }

    Point<T> circumcenter() const
    {
        auto D = 2*(A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y));

        auto A2 = A.x*A.x + A.y*A.y;
        auto B2 = B.x*B.x + B.y*B.y;
        auto C2 = C.x*C.x + C.y*C.y;

        auto x = (A2*(B.y - C.y) + B2*(C.y - A.y) + C2*(A.y - B.y))/D;
        auto y = (A2*(C.x - B.x) + B2*(A.x - C.x) + C2*(B.x - A.x))/D;

        return { x, y };
    }
};
