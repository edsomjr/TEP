#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    int As[N];

    for (int i = 0; i < N; ++i)
        scanf("%d", &As[i]);

    for (int C = 100; C >= 1; --C)
    {
        int aprovados = 0;

        for (int i = 0; i < N; ++i)
        {
            if (As[i] >= C)
                aprovados++;
        }

        if (aprovados >= K)
        {
            printf("%d\n", C);
            break;
        }
    }

    return 0;
}
