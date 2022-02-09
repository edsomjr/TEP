// Definição das estruturas Point e Line

template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    double area() const
    {
        Line<T> r(A, B);

        auto b = dist(A, B);
        auto h = r.distance(C);
        
        return (b * h)/2;
    }
};
