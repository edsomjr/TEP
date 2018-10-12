#include <stdio.h>

typedef enum {II, SR, MI, MM, MS, SS} Mencao;

Mencao calcula_mencao(float nota1, float nota2)
{
    float media = (nota1 + nota2)/2.0f;
    
    if (!media)
        return SR;
    else if (media < 2)
        return II;
    else if (media < 5)
        return MI;
    else if (media < 7)
        return MM;
    else if (media < 9)
        return MS;
    else 
        return SS;
}

int main()
{
    float nota1, nota2;
    Mencao mencao;
    
    printf("Insira duas notas: ");
    scanf("%f %f", &nota1, &nota2);
    
    switch (calcula_mencao(nota1, nota2)) {
    case II:
    case SR:
    case MI:
        printf("Aluno reprovado\n");
        break;

    default:
        printf("Aluno aprovado\n");    
    }
    
    return 0;
}
