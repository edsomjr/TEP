#include <stdio.h>
#include <string.h>

struct Cadastro {
    char nome[128];
    unsigned int idade;
    char sexo;
    float altura;
};

int main() {
    struct Cadastro cadastro;
    strcpy(cadastro.nome, "Maria");
    cadastro.idade = 40;
    cadastro.sexo = 'F';
    cadastro.altura = 1.68f;

    printf("Tamanho da estrutura: %lu\n", sizeof(cadastro));

    return 0;
}
