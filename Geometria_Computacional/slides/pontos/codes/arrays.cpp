#include <iostream>

using Point = double[2];

int main()
{
    Point p, q {0, 0};      // Declaração
    p = q;                  // Erro de compilação: a atribuição não está definida

    if (p < q) {            // Perigo: comparação entre endereços de ponteiros
        p[0] = q[1];        // O código compila sem erros
    }

    return 0;
}
