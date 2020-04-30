#include <stdio.h>
#include "vector_adt.h"
#include "vector_errors.h"

void inserir(vector v) {
    int N, rc;

    printf("Insira o número de passageiros da viagem %d: ", size(v) + 1);

    if (scanf("%d", &N) < 1) {
        fprintf(stderr, "Quantidade inválida!\n");
        return;
    }

    rc = push_back(v, N);

    if (rc == VECTOR_OK)
        printf("Informação inserida com sucesso!\n");
    else
        fprintf(stderr, "Erro na inserção: %d\n", rc);
}

void remover(vector v) {
    int N, rc;

    printf("Insira o número da viagem a ser removida: ");

    if (scanf("%d", &N) < 1 || N < 1 || N > size(v))
        fprintf(stderr, "Número inválido!\n");
    else if ((rc = pop(v, N - 1)) == VECTOR_OK)
        printf("Remoção bem sucedida!\n");
    else
        fprintf(stderr, "Erro na remoção: %d\n", rc);
}

void imprimir(vector v) {
    int i, total = 0;

    for (i = 0; i < size(v); i++) {
        printf("Viagem %02d: %d passageiros\n", i + 1, element_at(v, i));
        total += element_at(v, i);
    }

    printf("Total de passageiros: %d\n", total);
}

int main() {
    vector v = create_vector(10);
    int opcao;

    if (!v) {
        fprintf(stderr, "Falha na criação do vetor!\n");
        return -1;
    }

    while (1) {
        printf("\n\nDigite a opcao desejada: \n");
        printf("1. Inserir informações sobre viagem\n");
        printf("2. Remover informações sobre viagem\n");
        printf("3. Relatório de viagens\n");
        printf("4. Sair\n");

        if (scanf("%d", &opcao) < 1 || opcao < 1 || opcao > 3)
            break;

        switch (opcao) {
        case 1:
            inserir(v);
            break;
        case 2:
            remover(v);
            break;
        case 3:
            imprimir(v);
            break;
        }
    }

    printf("Encerrando o programa...\n");
    free_vector(v);

    return 0;
}
