#include <stdio.h>
#include <stdlib.h>

void imprimir_edicoes(const int *edicoes, int N)
{
    int i;
    const char msg[][16] = { ", ", "\n" };

    for (i = 0; i < N; i++)
        printf("%d%s", edicoes[i], msg[i + 1 == N]);
}

int buscar_edicao(int edicao, const int *edicoes, int N)
{
    int a = 0, b = N - 1, m;

    while (a <= b) {
        m = a + (b - a)/2;

        if (edicoes[m] == edicao)
            return 1;
        else if (edicoes[m] > edicao)
            b = m - 1;
        else
            a = m + 1;
    }

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
