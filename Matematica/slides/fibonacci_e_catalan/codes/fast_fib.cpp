#include <iostream>

using namespace std;

class Matrix {
    long long _a, _b, _c, _d;

public:
    Matrix(long long a = 1, long long b = 0, long long c = 0, long long d = 1)
        : _a(a), _b(b), _c(c), _d(d) {}

    Matrix operator*(const Matrix& m) const
    {
        auto a = _a * m._a + _b * m._c;
        auto b = _a * m._b + _b * m._d;
        auto c = _c * m._a + _d * m._c;
        auto d = _c * m._b + _d * m._d;

        return Matrix(a, b, c, d);
    }

    long long b() const { return _b; }
};

long long fast_fibonacci(long long n)
{
    Matrix res, A(1, 1, 1, 0);

    while (n)
    {
        if (n & 1)
            res = res * A;

        A = A * A;
        n >>= 1;
    }

    return res.b();
}

