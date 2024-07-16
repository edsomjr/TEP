#include <stdio.h>

int main()
{
    int N, S;
    scanf("%d %d", &N, &S);

    int X[N];

    for (int i = 0; i < N; ++i)
        scanf("%d", &X[i]);

    int resposta = 0;

    for (int a = 0; a < N; ++a)
        for (int b = a; b < N; ++b)
        {
            int soma = 0;

            for (int i = a; i <= b; ++i)
                soma += X[i];

            if (soma == S)
                ++resposta;
        }

    printf("%d\n", resposta);

    return 0;
}
