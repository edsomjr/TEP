// Definição da classe Point e das funções dist e equals()

// Verifica se o ponto P pertence ao segmento de reta AB
template<typename T>
bool contains(const Point<T>& A, const Point<T>& B, const Point<T>& P)
{
    double dAB = dist(A, B);
    double dAP = dist(A, P);
    double dPB = dist(P, B);

    return equals(dAP + dPB, dAB);
}
