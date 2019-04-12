// Definição da estrutura Point

template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    double area() const
    {
        auto a = dist(A, B);
        auto b = dist(B, C);
        auto c = dist(C, A);

        auto s = (a + b + c)/2

        return sqrt(s)*sqrt(s - a)*sqrt(s - b)*sqrt(s - c);
    }
};
