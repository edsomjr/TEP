template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    double perimeter() const
    {
        auto a = dist(A, B);
        auto b = dist(B, C);
        auto c = dist(C, A);

        return a + b + c;
    }
};
