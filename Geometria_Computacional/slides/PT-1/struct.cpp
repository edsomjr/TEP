#include <iostream>

template<typename T>
struct Point {
    T x, y;

    Point(T xv = 0, T yv = 0) : x(xv), y(yv) {}
};

int main()
{
    Point<int> p(1, 2), q;  // Declaração
    p = q;                  // Atribuição

    if (p < q) {        // Erro de compilação: operador < não definido!
        p.x = q.y;
    }

    return 0;
}
