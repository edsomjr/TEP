#include <stdio.h>

int main()
{
    int X, Y;
    
    while (scanf("%d %d", &X, &Y) == 2)
    {
        printf("%d\n", X + Y);
    }

    return 0;
}
