// Definição da constante PI
template<typename T>
struct Point3D {
    T x, y, z;
};

template<typename T>
struct Sphere {
    Point3D<T> C;
    T r;

    double area() const
    {
        return 4.0*PI*r*r;
    }

    double volume() const
    {
        return 4.0*PI*r*r*r/3.0;
    }
};
