#include <stdio.h>
#include <stdlib.h>

// Pares em ordem crescente, seguidos de ímpares em ordem decrescente
int compare(const void *a, const void *b)
{
    int x = *((int *) a);
    int y = *((int *) b);

    int rx = x % 2, ry = y % 2;

    if (rx == ry)
        return rx ? y - x : x - y;
    else
        return rx ? 1 : -1;
}

int main()
{
    int ns[] { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 }, N = 10;

    qsort(ns, N, sizeof(int), compare);

    for (int i = 0; i < N; ++i)
        printf("%d%c", ns[i], " \n"[i + 1 == N]);

    return 0;
}
