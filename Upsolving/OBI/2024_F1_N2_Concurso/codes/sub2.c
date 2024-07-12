#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    int C = 0;

    for (int i = 0; i < N; ++i)
    {
        int A;
        scanf("%d", &A);

        if (A > C)
            C = A;
    }

    printf("%d\n", C);
 
    return 0;
}
