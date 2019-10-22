// Definição da classe Point e da função de comparação equals

template<typename T>
struct Line {
    // Membros e construtor

    bool contains(const Point<T>& P) const
    {
        return equals(a*P.x + b*P.y + c, 0);
    }
};
