#include <stdio.h>

int main()
{
    int X, Y;
    
    while (scanf("%d %d", &X, &Y), X != -1 && Y != -1)
    {
        printf("%d\n", X + Y);
    }

    return 0;
}
