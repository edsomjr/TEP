#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char s[16];
    scanf("%s", s);

    int N = strlen(s);

    char keyboard [27] = "22233344455566677778889999";

    for (int i = 0; i < N; ++i)
        if (isalpha(s[i]))
            s[i] = keyboard[s[i] - 'A'];

    printf("%s\n", s);

    return 0;
}
