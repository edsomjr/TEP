#include <stdio.h>

int main()
{
    int N, S;
    scanf("%d %d", &N, &S);

    int X[N + 1];

    for (int i = 1; i <= N; ++i)
        scanf("%d", &X[i]);

    int ps[N + 1];
    ps[0] = 0;

    for (int i = 1; i <= N; ++i)
        ps[i] = ps[i - 1] + X[i]; 

    int resposta = 0;

    for (int a = 1; a <= N; ++a)
        for (int b = a; b <= N; ++b)
            if (ps[b] - ps[a - 1] == S)
                ++resposta;

    printf("%d\n", resposta);

    return 0;
}
