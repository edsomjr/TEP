// Assuma que a função f(double) esteja definida, que a < b e que f(a)*f(b) < 0
// eps é a tolerância de erro
double root(double a, double b, double eps = 1e-6)
{
    while (fabs(a - b) > eps)
    {
        auto c = (a + b)/2;
        auto y = f(c);

        // c é uma boa aproximação para o zero
        if (fabs(y) < eps)
            return c;

        // Determina em qual dos intervalos ( (a,c) ou (c,b) ) está o zero
        f(a)*y < 0 ?  b = c : a = c;
    }

    return (a + b)/2;
}
