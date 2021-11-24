#include <iostream>

using Point2D = std::pair<int, int>;          // C++11 em diante
using Point3D = std::tuple<int, int, int>;  

#define x first
#define y second

int main()
{
    Point2D p(1, 2), q;                     // Declaração
    p = q;                                  // Atribuição

    if (p == q) {                           // Ok! Operador == para ints utilizado
        p.x = q.y + 1;
    }

    return 0;
}
