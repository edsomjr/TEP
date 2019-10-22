// Definição da função equals()

template<typename T>
struct Line {
    // Membros e construtores (equação reduzida)

    bool operator==(const Line& r) const    // Verdadeiro se coincidentes
    {
        if (vertical != r.vertical || !equals(m, r.m)) return false;

        return equals(b, r.b);
    }

    bool parallel(const Line& r) const // Verdadeiro se paralelas
    {
        if (vertical && r.vertical) return b != r.b;
        if (vertical || r.vertical) return false;

        return equals(m, r.m) && !equals(b, r.b);
    }
};
