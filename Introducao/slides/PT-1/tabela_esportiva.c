#include <stdio.h>

#define NUMERO_DE_JOGOS 5

int main()
{
    int tabela[NUMERO_DE_JOGOS][2];
    int SG = 0, GC = 0, GP = 0;
    int V = 0, E = 0, D = 0, PG = 0, i;
    float AP;

    for (i = 0; i < NUMERO_DE_JOGOS; i++) {
        printf("Insira o resultado do jogo %02d: ", i + 1);
        scanf("%d x %d", &tabela[i][0], &tabela[i][1]);
    }

    for (i = 0; i < NUMERO_DE_JOGOS; i++) {
        GP += tabela[i][0];
        GC += tabela[i][1];

        if (tabela[i][0] > tabela[i][1])
            V++;
        else if (tabela[i][0] < tabela[i][1])
            D++;
        else 
            E++;
    }

    SG = GP - GC;
    PG = V*3 + E;
    AP = (float) 100*PG / (NUMERO_DE_JOGOS*3);

    printf("\nResumo da campanha: \n");
    printf("%d vitórias, %d empates, %d derrotas\n", V, E, D);

    printf("Gols: pró = %d, contra = %d, saldo = %d\n", GP, GC, SG);
        
    printf("Pontos ganhos: %d (%3.2f%% de aproveitamento)\n", PG, AP);

    return 0;
}
