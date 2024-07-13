#include <stdio.h>
#include <algorithm>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    int As[N];

    for (int i = 0; i < N; ++i)
        scanf("%d", &As[i]);

    std::sort(As, As + N);

    printf("%d\n", As[N - K]);

    return 0;
}
