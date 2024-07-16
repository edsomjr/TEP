#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int V[N];

    for (int i = 0; i < N; ++i)
        scanf("%d", &V[i]);

    int resposta = 0, L = 0;

    while (L < N)
    {
        int R = L + 1;

        while (R < N && V[R] == V[L])
            ++R;

        if (R - L > resposta)
            resposta = R - L;

        L = R;
    }
    
    printf("%d\n", resposta);

    return 0;
}
