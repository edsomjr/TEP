#include <iostream>

struct Matrix
{
    long long a, b, c, d, m;
    
    Matrix(int av = 1, int bv = 0, int cv = 0, int dv = 1, int mv = 0)
        : a(av), b(bv), c(cv), d(dv), m(mv) {}

    Matrix operator*(const Matrix& A) const
    {
        long long M = (1 << m);
        auto ra = (a * A.a + b * A.c) % M;
        auto rb = (a * A.b + b * A.d) % M;
        auto rc = (c * A.a + d * A.c) % M;
        auto rd = (c * A.b + d * A.d) % M;

        return Matrix(ra, rb, rc, rd, m);
    }
};

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

int fib(int n, int m)
{
    auto A = Matrix(1, 1, 1, 0, m);
    auto F = fast_pow_mod(A, n, m);

    return F.b;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n, m;

    while (std::cin >> n >> m)
    {
        auto ans = fib(n, m);

        std::cout << ans << std::endl;
    }

    return 0;
}
