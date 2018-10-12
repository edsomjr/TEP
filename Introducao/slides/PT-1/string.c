#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "UnB - FGA";
    char s2[] = "EDA";
    
    printf("%s = %lu caracteres\n", s1, strlen(s1));

    printf("Primeira string, na ordem alfabética: %s\n", 
        (strcmp(s1, s2) > 0 ? s2 : s1));

    printf("Localização do F: %ld\n", strchr(s1, 'F') - s1);

    printf("Cópia: %s\n", strcpy(s1, s2));

    printf("Concatenação: %s\n", strcat(s1, s2));

    return 0;
}
