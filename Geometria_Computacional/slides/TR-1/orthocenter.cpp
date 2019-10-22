#include <iostream>

using namespace std;

template<typename T>
struct Point {
    T x, y;
};

template<typename T>                                                                                
struct Line {                                                                                       
    T a, b, c;                                                                                      
                                                                                                    
    Line(T av, T bv, T cv) : a(av), b(bv), c(cv) {}

    Line(const Point<T>& P, const Point<T>& Q)                                                      
        : a(P.y - Q.y), b (Q.x - P.x), c(P.x * Q.y - Q.x * P.y)                                     
    {                                                                                               
    }                                                                                               
}; 

template<typename T>
struct Triangle {
    Point<T> A, B, C; 

    Point<T> orthocenter() const
    {
        Line<T> r(A, B), s(A, C);

        Line<T> u { r.b, -r.a, -(C.x*r.b - C.y*r.a) };
        Line<T> v { s.b, -s.a, -(B.x*s.b - B.y*s.a) };

        auto det = u.a * v.b - u.b * v.a;  
        auto x = (-u.c * v.b + v.c * u.b) / det;                                                    
        auto y = (-v.c * u.a + u.c * v.a) / det;  

        return { x, y };
    }
};

int main()
{
    Point<double> A { 0, 0 }, B { 3, 6 },  C { 9, 1 };
    Triangle<double> T { A, B, C };

    auto O = T.orthocenter();

    cout << "(" << O.x << ", " << O.y << ")\n";

    return 0;
}
