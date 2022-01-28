template<typename T>
struct Line
{
    // Membros e construtores (equação geral)

    bool orthogonal(const Line& r) const  // Verdadeiro se perpendiculares
    {
        return equals(a * r.a + b * r.b, 0);
    }
};
