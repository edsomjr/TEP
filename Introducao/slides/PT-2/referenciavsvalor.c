#include <stdio.h>
#include <time.h>

typedef struct _Registro {
    char nome[128];
    char sexo;
    float peso;
    int idade;
} Registro;

void por_valor(Registro registro) {}
void por_referencia(Registro *registro) {}

static const unsigned long quantidade_chamadas = 1e8;

int main()
{
    Registro registro;
    time_t inicio, fim;
    unsigned long i;
    
    inicio = clock();

    for (i = 0; i < quantidade_chamadas; i++)
        por_valor(registro);
    
    fim = clock();
    
    printf("Valor: %.8f s\n", 1.0*(fim - inicio)/CLOCKS_PER_SEC);
    
    inicio = clock();

    for (i = 0; i < quantidade_chamadas; i++)
        por_referencia(&registro);
    
    fim = clock();
    
    printf("Referência: %.8f s\n", 1.0*(fim - inicio)/CLOCKS_PER_SEC);
    
    return 0;
}
