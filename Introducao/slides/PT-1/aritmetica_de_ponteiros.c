#include <stdio.h>

int main() {
    int ns[] = {4, 8, 15, 16, 23, 42}, *p = ns, *q = 0;

    printf("Endereços: p = %p, q = %p\n", p, q);

    q = p + 6; p++;

    printf("Valores e endereços: p = %d (%p), q = %d (%p)\n", 
        *p, p, *q, q);

    q -= 2;

    printf("Novos valores e endereços: p = %d (%p), q = %d (%p)\n", 
        *p, p, *q, q);
        
    printf("Diferença: %ld\n", q - p);

    return 0;
}
