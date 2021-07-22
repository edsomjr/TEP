// Com variáveis do tipo `long long` é possível computar até
// o 33º número de Catalan sem overflow.
long long catalan(int n)
{
    if (n == 0)
        return 1;

    if (C[n] != -1)
        return C[n];

    C[n] = (2*(2*n - 1)*catalan(n - 1))/(n + 1);

    return C[n];
}
