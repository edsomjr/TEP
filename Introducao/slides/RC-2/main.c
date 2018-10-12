#include <stdio.h>
#include "primes.h"

int main() {
    long xs[] = {2, 3, 5, 7, 11, 13}, ys[] = {-1, 0, 1, 4, 10}, i;
    
    for (i = 0; i < 6; i++) 
        if (!is_prime(xs[i])) {
            printf("Erro: %ld identificado como nao-primo!\n", xs[i]);
            return -1;
        }

    for (i = 0; i < 5; i++) 
        if (is_prime(ys[i])) {
            printf("Erro: %ld identificado como primo!\n", ys[i]);
            return -1;
        }
    
    printf("Test OK!\n");
    return 0;
}
