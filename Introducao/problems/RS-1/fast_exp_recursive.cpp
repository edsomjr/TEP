// Definição da classe Matrix, com o operador * implementado

Matrix fast_mod_pow(const Matrix& A, int n, int M)
{
    if (n == 1)
        return A;

    auto B = fast_mod_pow(A, n / 2, M);

    return n & 1 ? B * B * A : B * B;
}
