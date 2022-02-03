template<typename T>
struct Segment {
    Point<T> A, B;

    // Verifica se o ponto P da reta r que contém A e B  pertence ao segmento
    bool contains(const Point<T>& P) const
    {
        return equals(A.x, B.x) ?  min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y) 
            : min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
    }

    // Esta abordagem não exige que P esteja sobre a reta AB
    bool contains2(const Point<T>& P) const
    {
        double dAB = dist(A, B), dAP = dist(A, P), dPB = dist(P, B);

        return equals(dAP + dPB, dAB);
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
