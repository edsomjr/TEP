
template<typename T>
struct Circle
{
    // Membros e construtores

    // A unidade de medida do ângulo a é radianos
    double segment(double a) const
    {
        return ((a - sin(a))*r*r)/2.0;
    }
};
