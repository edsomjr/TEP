#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cripto.h" 

int main(int argc, char *argv[]) {
    FILE *in, *out;
    byte (*op)(byte, byte) = NULL, key;
    int c;
    
    if (argc < 4) {
        fprintf(stderr, "Uso: %s <entrada> <saida> <chave>\n", argv[0]);
        return -1;
    }

    in = fopen(argv[1], "r");

    if (!in) {
        fprintf(stderr, "Erro ao abrir %s para leitura\n", argv[1]);
        return -2;
    }

    out = fopen(argv[2], "w");

    if (!in) {
        fprintf(stderr, "Erro ao abrir %s para escrita\n", argv[1]);
        fclose(in);
        return -3;
    }

    if (!strcmp(argv[0], "./cipherfile"))
        op = cipher;
    else if (!strcmp(argv[0], "./decipherfile"))
        op = decipher;
    else {
        fprintf(stderr, "Operacao desconhecida\n");
        fclose(in);
        fclose(out);
        
        return -4;
    }

    key = (byte) atoi(argv[3]);
    
    while ((c = fgetc(in)) != EOF)
        fputc(op((byte) c, key), out);

    fclose(in);
    fclose(out);

    return 0;
}
