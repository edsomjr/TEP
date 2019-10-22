template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    enum Sides { EQUILATERAL, ISOSCELES, SCALENE };

    Sides classification_by_sides() const
    {
        auto a = dist(A, B);
        auto b = dist(B, C);
        auto c = dist(C, A);

        if (equals(a, b) and equals(b, c))
            return EQUILATERAL;

        if (equals(a, b) or equals(a, c) or equals(b, c))
            return ISOSCELES;

        return SCALENE;
    }
};
