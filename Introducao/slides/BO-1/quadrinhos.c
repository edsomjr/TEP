#include <stdio.h>

int i;

void imprimir_edicoes(const int *edicoes, int N) {
    const char msg[][16] = { ", ", "\n" };

    for (i = 0; i < N; i++)
        printf("%d%s", edicoes[i], msg[i + 1 == N]);
}

int buscar_edicao(int edicao, const int *edicoes, int N) {
    for (i = 0; i < N; i++)
        if (edicoes[i] == edicao)
            return 1;

    return 0;
}

int main() {
    int edicoes[] = {23, 44, 35, 10, 23, 99, 10, 23}, N = 8, edicao;

    do {
        printf("\nColecao disponivel: ");
        imprimir_edicoes(edicoes, N);

        printf("Insira o numero da edicao a ser localizada: ");

        if (scanf("%d", &edicao) != 1 || edicao < 0)
            break;

        if (buscar_edicao(edicao, edicoes, N))
            printf("Edicao %d encontrada\n", edicao);
        else
            printf("A edicao %d nao faz parte da colecao\n", edicao);
    } while (1);

    printf("Finalizando o programa...\n");

    return 0;
}
