// Assuma que a função f(double) esteja definida, a < b e que f(a)*f(b) < 0
// N é o número de iterações do algoritmo
double root(double a, double b, int N = 50)
{
    while (N--)
    {
        double c = (a + b)/2;

        // Determina em qual dos intervalos ( (a,c) ou (c,b) ) está o zero
        f(a)*f(c) < 0 ?  b = c : a = c;
    }

    return (a + b)/2;
}
