#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    int x = 0, y = 0, z = 0;

    for (int i = 0; i < N; ++i)
    {
        int A;
        scanf("%d", &A);

        int a = A, b = z;

        z = a > b ? a : b;
        a = a < b ? a : b;

        b = y;
        y = a > b ? a : b;
        a = a < b ? a : b;

        b = x;
        x = a > b ? a : b;
    }

    printf("%d\n", x);
 
    return 0;
}
