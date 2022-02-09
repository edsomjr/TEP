
template<typename T>
struct Circle
{
    // Membros e construtores

    // A unidade de medida do theta é radianos
    double chord(double theta) const
    {
        return 2 * r * sin(theta/2);
    }
};
