#include <iostream>

template<typename T>
struct Point {
    T x = 0, y = 0;
};

int main() {
    Point<int> p { 1, 2 }, q;   // Declaração
    p = q;                      // Atribuição

    if (p == q) {               // Erro de compilação: o operador == não está definido!
        p.x = q.y + 1;
    }

    return 0;
}
