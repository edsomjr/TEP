// Definição da classe Matrix, com o operador * implementado

Matrix fast_pow_mod(const Matrix& A, int n, int m)
{
    auto res = Matrix(1, 0, 0, 1, m), base = A;

    while (n)
    {
        if (n & 1)
            res = res * base;

        base = base * base;
        n >>= 1;
    }

    return res;
}
