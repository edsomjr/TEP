#include <iostream>

using Point = std::pair<int, int>;  // C++11

#define x first
#define y second

int main()
{
    Point p(1, 2), q;               // Declaração
    p = q;                          // Atribuição

    if (p < q) {                    // Ok! Operador < para ints utilizado
        p.x = q.y;
    }

    return 0;
}
