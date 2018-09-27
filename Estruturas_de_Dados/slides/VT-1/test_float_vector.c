#include <stdlib.h>
#include <stdio.h>

#include <float_vector.h>

int main()
{
    FloatVector v;
    int i;
    
    printf("Informe a quantidade de valores a serem inseridos: ");
    scanf("%d", &v.size);
    
    if (v.size < 1) {
        fprintf(stderr, "Nada a fazer!\n");
        return -1;
    }
    
    v.data = (float *) malloc(sizeof(float)*v.size);
    
    if (!v.data) {
        fprintf(stderr, "Sem memoria\n");
        return -2;
    }
    
    for (i = 0; i < v.size; i++) {
        printf("Informe o valor %d: ", i + 1);
        scanf("%f", &v.data[i]);
    }
    
    printf("O maior valor informado foi %3.2f\n", max(&v));
    printf("O menor valor informado foi %3.2f\n", min(&v));
    
    return 0;
}
