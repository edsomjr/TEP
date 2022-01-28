// Definição das classes Point e Line, e da função equals()

template<typename T>
struct Segment {
    Point<T> A, B;

    // Verifica se o ponto P da reta r que contém _A_ e _B_ 
    // pertence ao segmento
    bool contains(const Point<T>& P) const
    {
        if (equals(A.x, B.x))
            return min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y);
        else
            return min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
    }

    // Ponto mais próximo de P no segmento AB
    Point<T> closest(const Point<T>& P)
    {
        Line<T> r(A, B);
        auto Q = r.closest(P);

        if (this->contains(Q))
            return Q;

        auto distA = P.distanceTo(A);
        auto distB = P.distanceTo(B);

        if (distA <= distB)
            return A;
        else
            return B;
    }
}
