// Definição da constante PI
template<typename T>
struct Cylinder {
    T r, h;

    double area() const
    {
        return 2*PI*r*(r + h);
    }

    double volume() const
    {
        return PI*r*r*h;
    }
};
