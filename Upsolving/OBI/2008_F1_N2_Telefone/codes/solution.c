// NEPS 235 - Telefone (P1) (https://neps.academy/br/exercise/235)
#include <stdio.h>
#include <string.h>

int main()
{
    char telefone[16];
    scanf("%s", telefone);

    int N = strlen(telefone);

    for (int i = 0; i < N; ++i)
    {
        if ('A' <= telefone[i] && telefone[i] <= 'C')
            telefone[i] = '2';
        else if ('D' <= telefone[i] && telefone[i] <= 'F')
            telefone[i] = '3';
        else if ('G' <= telefone[i] && telefone[i] <= 'I')
            telefone[i] = '4';
        else if ('J' <= telefone[i] && telefone[i] <= 'L')
            telefone[i] = '5';
        else if ('M' <= telefone[i] && telefone[i] <= 'O')
            telefone[i] = '6';
        else if ('P' <= telefone[i] && telefone[i] <= 'S')
            telefone[i] = '7';
        else if ('T' <= telefone[i] && telefone[i] <= 'V')
            telefone[i] = '8';
        else if ('W' <= telefone[i] && telefone[i] <= 'Z')
            telefone[i] = '9';
    } 

    printf("%s\n", telefone);

    return 0;
}
