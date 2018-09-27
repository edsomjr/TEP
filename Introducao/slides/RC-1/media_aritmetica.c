#include <stdio.h>

float media = 0.0f;                             /* Variável global */

void atualiza_media(float nota) {               /* Parâmetro de função */
    static int quantidade_notas = 0;            /* Variável estática */
    media = media*quantidade_notas + nota;
    quantidade_notas++;
    media /= quantidade_notas;
}

int main() { 
    float nota1 = 3.8f, nota2 = 4.2f;           /* Variáveis locais */
    
    atualiza_media(nota1);
    atualiza_media(nota2);
    
    printf("A media e igual a %3.2f\n", media);
    
    return 0;
}
