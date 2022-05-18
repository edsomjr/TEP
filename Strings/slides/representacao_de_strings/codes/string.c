#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[50] = "Test", b[] = "TEP";

    // Tamanho da string
    int s = strlen(a);      // s = 4, o zero terminador não é computado
    s = strlen(b);          // s = 3

    // Comparação
    s = strcmp(a, b);       // s > 0, "Test" sucede "TEP" na ordem lexicográfica
    s = strcmp(b, a);       // s < 0, "TEP" precede "Test" na ordem lexicográfica

    s = strncmp(a, b, 1);   // s = 0, as strings são iguais no primeiro caractere
    s = strncmp(a, b, 2);   // s > 0, "Te" sucede "TE" na ordem lexicográfica

    // Cópia
    strcpy(a, b);           // a = "TEP"
    strncpy(a, "SA", 2);    // a = "SAP"

    // Acesso aos elementos individuais
    a[2] = 'T';             // a = "SAT"
    a[0] = b[2];            // a = "PAT"

    // Conversão de string para valores numéricos
    strcpy(a, "123.45");
    double d = atof(a);             // d = 123.45
    int i = atoi(a);                // i = 123

    strcpy(a, "10000000000000000000000000000000000000000");
    long long ll = strtoll(a, NULL, 2);   // ll = 1099511627776, conversão em base binária

    // Concatenação
    strcpy(b, "xyz");       // b = "xyz"
    strcpy(a, "abcba");     // a = "abcba"

    strcat(a, b);           // a = "abcbaxyz"
    strncat(a, a, 3);       // a = "abcbaxyzabc"

    // Busca de caracteres
    char *p;

    p = strchr(a, 'b');     // p - a = 1, índice da primeira ocorrência de 'b'
    p = strrchr(a, 'b');    // p - a = 9, índice da última ocorrência de 'b'

    p = strstr(a, "cba");   // p - a = 2, índice da primeira coorrência de "cba"
    p = strstr(a, "dd");    // p = NULL, "dd" não é substring de a

    i = strspn(a, "abc");   // i = 5, a[0..4] contém apenas caracteres em "abc"
    i = strcspn(a, "z");    // i = 7, a[0..6] contém caracteres diferentes de "z"

    return 0;
}
