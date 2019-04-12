// Definição da estrutura Point

template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    double area() const
    {
        double det = (A.x*B.y + A.y*C.x + B.x*C.y) 
                   - (C.x*B.y + C.y*A.x + B.x*A.y);

        return 0.5 * fabs(det);
    }
};
