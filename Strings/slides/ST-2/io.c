#include <stdio.h>
#include <string.h>

// Assuma que será inserida em uma linha, via console, a mensagem
// "Teste de I/O em C"
int main()
{
    char s[1024], line[1024];

    scanf("%s", s);
    printf("s = [%s]\n", s);    // s = [Teste]

    fgets(line, 1024, stdin);
    line[strlen(line) - 1] = 0;

    printf("line = [%s]\n", line); // line = [Teste de I/O em C\n]

    return 0;
}
