#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i;
    float *notas = NULL, media = 0;
    
    printf("Insira o número de notas: ");
    scanf("%d", &N);
    
    if (N < 1) {
        printf("Nada a ser feito!\n");
        return 0;
    }
    
    notas = (float *) malloc(N*sizeof(float));
    
    if (!notas) {
        fprintf(stderr, "Sem memória!\n");
        return -1;
    }
    
    for (i = 0; i < N; i++)
    {
        printf("Insira a nota %d: ", i + 1);
        scanf("%f", notas + i);
    }
    
    for (i = 0; i < N; i++)
        media += notas[i]/N;
    
    printf("A média das notas é igual a %.2f\n", media);
    
    free(notas);
    
    return 0;
}
