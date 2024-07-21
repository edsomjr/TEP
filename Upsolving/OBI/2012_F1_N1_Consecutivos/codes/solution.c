#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int anterior;
    scanf("%d", &anterior);

    int consecutivos = 1, resposta = 1;

    for (int i = 1; i < N; ++i)
    {
        int proximo;
        scanf("%d", &proximo);

        if (proximo == anterior)
            ++consecutivos;
        else
        {
            if (consecutivos > resposta)
                resposta = consecutivos;

            anterior = proximo;
            consecutivos = 1;
        }
    }

    if (consecutivos > resposta)
        resposta = consecutivos;
    
    printf("%d\n", resposta);

    return 0;
}
