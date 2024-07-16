#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int V[N];

    for (int i = 0; i < N; ++i)
        scanf("%d", &V[i]);

    int v = V[0], consecutivos = 1, resposta = 1;

    for (int i = 1; i < N; ++i)
    {
        if (V[i] == v)
            ++consecutivos;
        else
        {
            if (consecutivos > resposta)
                resposta = consecutivos;

            v = V[i];
            consecutivos = 1;
        }
    }

    if (consecutivos > resposta)
        resposta = consecutivos;
    
    printf("%d\n", resposta);

    return 0;
}
