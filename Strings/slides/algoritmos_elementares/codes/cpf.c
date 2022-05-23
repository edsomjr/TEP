#include <stdio.h>
#include <string.h>

int main() {
    char cpf[] = "123.456.789-10", *token = NULL;

    token = strtok(cpf, ".");
    printf("token = [%s]\n", token);    /* token = [123] */

    token = strtok(NULL, ".");
    printf("token = [%s]\n", token);    /* token = [456] */

    token = strtok(NULL, "-");
    printf("token = [%s]\n", token);    /* token = [798] */

    token = strtok(NULL, "\0");
    printf("token = [%s], cpf = [%s]\n", token, cpf);    /* token = [10], cpf = [123] */

    return 0;
}
