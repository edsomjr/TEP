// Definição da estrutura Vector3D

template<typename T>
struct Parallelepiped {
    Vector3D<T> u, v, w;

    double volume() const
    {
        return fabs(u.x*v.y*w.z + u.y*v.z*w.x + u.z*v.x*w.y 
                - (u.x*v.z*.wy + u.y*v.x*w.z + u.z*v.y*w.x);
    }

    double volume2() const
    {
        double a = u.lenght();
        double b = v.length();
        double c = w.length();

        double m = angle(u, v);
        double n = angle(u, w);
        double p = angle(v, w);

        return a*b*c*sqrt(1 + 2*cos(m)*cos(n)*cos(p) - cos(m)*cos(m)
            - cos(n)*cos(n) - cos(p)*cos(p));
    }
    
    double volume3() const
    {
        return fabs(dot_product(u, cross_product(v, w)));
    }

    double area() const
    {
        double uv = cross_product(u, v).length();
        double uw = cross_product(u, w).length();
        double vw = cross_product(v, w).length();

        return 2*(uv + uw + vw);
    }
};

