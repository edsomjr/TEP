template<typename T>
struct Circle
{
    // Membros e construtores

    // A unidade de medida do theta é radianos
    double arc(double theta) const
    {
        return theta * r;
    }
};
