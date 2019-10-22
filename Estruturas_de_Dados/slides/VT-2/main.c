#include <stdio.h>
#include "vector_adt.h"

int main()
{
    vector v = create_vector(5);
    int i;

    if (!v) {
        fprintf(stderr, "Falha na criação do vetor!\n");
        return -1;
    }

    printf("Tamanho: %d\n", size(v));

    for (i = 1; i <= 7; ++i)
        push_back(v, i);

    printf("Tamanho após inserções: %d\n", size(v));

    printf("v = ");
    for (i = 0; i < size(v); ++i)
        printf("%d%c", element_at(v, i), " \n"[i + 1 == size(v)]);

    push(v, 10, 2);
    push(v, 20, 5);
    push(v, 30, 1);
    push(v, 40, 8);
    push(v, 50, 8);

    printf("v = ");
    for (i = 0; i < size(v); ++i)
        printf("%d%c", element_at(v, i), " \n"[i + 1 == size(v)]);

    pop(v, 10);
    pop(v, 5);
    pop(v, 2);
    pop(v, 1);

    printf("v = ");
    for (i = 0; i < size(v); ++i)
        printf("%d%c", element_at(v, i), " \n"[i + 1 == size(v)]);

    free_vector(v);

    return 0;
}
