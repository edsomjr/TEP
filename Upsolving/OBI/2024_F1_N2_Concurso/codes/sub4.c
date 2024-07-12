#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    int nota2 = 0;

    for (int i = 0; i < N; ++i)
    {
        int A;
        scanf("%d", &A);

        if (A == 2)
            nota2++;
    }

    printf("%d\n", nota2 >= K ? 2 : 1);
 
    return 0;
}
