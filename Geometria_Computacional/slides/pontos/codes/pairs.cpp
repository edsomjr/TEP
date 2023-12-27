#include <bits/stdc++.h>

using Point2D = std::pair<int, int>;        // C++11 em diante
using Point3D = std::tuple<int, int, int>;  

int main()
{
    Point3D p { 1, 2, 3 }, q;               // Declaração
    p = q;                                  // Atribuição

    if (p == q) {                           // Ok! Operador == para ints utilizado
        auto [x, y, z] = q;                 // Decomposição estruturada para tuplas
        auto w = x*x + y*y + z*z;
    }

    return 0;
}
