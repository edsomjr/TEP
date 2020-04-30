#include <stdio.h>
#include "vector_adt.h"
#include "vector_errors.h"

int main()
{
    vector v = create_vector(10);
    int N, rc;

    if (!v) {
        fprintf(stderr, "Falha na criação do vetor!\n");
        return -1;
    }

    while (1) {
        printf("Informe o número de passageiros na viagem (Ctrl-D para"
            " encerrar): ");

        if (scanf("%d", &N) < 1)
            break;

        rc = push_back(v, N);

        if (rc != VECTOR_OK)
        {
            fprintf(stderr, "Erro na inserção de passageiros: %d\n", rc);
            free_vector(v);
            return rc;
        }
    }

    printf("\n\nRelatório de passageiros a cada viagem: ");

    for (int i = 0; i < size(v); ++i)
        printf("%d%c", element_at(v, i), " \n"[i + 1 == size(v)]);

    free_vector(v);

    return 0;
}
