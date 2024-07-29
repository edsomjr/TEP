#include <stdio.h>
#include <string.h>

int main()
{
    char s[16];
    scanf("%s", s);

    int N = strlen(s);

    for (int i = 0; i < N; ++i)
    {
        if ('A' <= s[i] && s[i] <= 'C')
            s[i] = '2';
        else if ('D' <= s[i] && s[i] <= 'F')
            s[i] = '3';
        else if ('G' <= s[i] && s[i] <= 'I')
            s[i] = '4';
        else if ('J' <= s[i] && s[i] <= 'L')
            s[i] = '5';
        else if ('M' <= s[i] && s[i] <= 'O')
            s[i] = '6';
        else if ('P' <= s[i] && s[i] <= 'S')
            s[i] = '7';
        else if ('T' <= s[i] && s[i] <= 'V')
            s[i] = '8';
        else if ('W' <= s[i] && s[i] <= 'Z')
            s[i] = '9';
    } 

    printf("%s\n", s);

    return 0;
}
