#include <stdio.h>
#include <ctype.h>

int main()
{
    char a[] = "Test with numbers: 0x1234";
    int r;

    a[0] = tolower(a[0]);       // a = "test with numbers: 0x1234"
    a[10] = toupper(a[10]);     // a = "test with Numbers: 0x1234"

    r = isalpha(a[0]);          // r != 0, 't' é alfabético
    r = isalpha(a[19]);         // r = 0, '0' não é alfabético
    r = isalnum(a[19]);         // r != 0, '0' é alfanumérico
    r = isblank(a[18]);         // r != 0, ' ' é um espaço em branco
    r = isdigit(a[1]);          // r = 0, 'e' não é um dígito decimal
    r = isxdigit(a[1]);         // r != 0, 'e' é um dígito hexadecimal

    return 0;
}
