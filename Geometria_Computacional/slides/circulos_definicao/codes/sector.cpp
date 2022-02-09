template<typename T>
struct Circle
{
    // Membros e construtores

    // A unidade de medida do theta é radianos
    double sector(double theta) const
    {
        return (theta * r * r)/2;
    }
};
