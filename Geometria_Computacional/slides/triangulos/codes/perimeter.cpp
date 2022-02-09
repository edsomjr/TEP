template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    double perimeter() const
    {
        auto a = dist(A, B), b = dist(B, C), c = dist(C, A);

        return a + b + c;
    }
};
