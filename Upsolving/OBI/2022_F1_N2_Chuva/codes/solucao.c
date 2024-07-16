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

    int hist[1000001];
    hist[0] = 1;

    for (int v = 1; v <= 1000000; ++v)
        hist[v] = 0;

    long long resposta = 0;

    for (int b = 1; b <= N; ++b)
    {
        if (ps[b] >= S)
            resposta += hist[ps[b] - S];

        hist[ps[b]]++;
    }

    printf("%lld\n", resposta);

    return 0;
}
