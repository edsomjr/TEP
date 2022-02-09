template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    double inradius() const
    {
        return (2 * area()) / perimeter();
    }

    Point<double> incenter() const
    {
        auto a = dist(B, C), b = dist(A, C), c = dist(A, B);
        auto P = perimeter();
        auto x = (a*A.x + b*B.x + c*C.x)/P;
        auto y = (a*A.y + b*B.y + c*C.y)/P;

        return { x, y };
    }
};
