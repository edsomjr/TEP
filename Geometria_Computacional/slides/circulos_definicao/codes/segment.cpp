
template<typename T>
struct Circle
{
    // Membros e construtores

    // Método sector()

    // A unidade de medida do theta é radianos
    double segment(double a) const
    {
        auto c = chord(a);
        auto s = (r + r + c)/2.0;                               // Semiperímetro
        auto T = sqrt(s)*sqrt(s - r)*sqrt(s - r)*sqrt(s - c);   // Área do triângulo

        return sector(a) - T;
    }
};
