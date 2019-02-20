// Definição da função equals()

template<typename T>
struct Line
{
    // Membros e construtores (equação reduzida)

    bool orthogonal(const Line& r) const // Verdadeiro se perpendiculares
    {
        if (vertical && r.vertical)
            return false;

        if ((vertical && equals(r.m, 0)) || (equals(m, 0) && r.vertical))
            return true;

        if (vertical || r.vertical)
            return false;

        return equals(m * r.m, -1.0);
    }
};
