Sequências Notáveis
===================

Nos problemas de contagem, o conhecimento dos termos e do comportamento de determinadas 
sequências numéricas é fundamental na identificação de padrões e propriedades dos elementos a
serem contados. Abaixo são listadas algumas destas sequências.

Sequência de Fibonacci
----------------------

A sequência de Fibonacci _F(n)_ é definida pela recorrência abaixo:

        F(0) = F(1) = 1
        F(n) = F(n - 1) + F(n - 2),     n >= 2

Os primeiros termos da sequência de Fibonacci são:

        0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, ...

Como podemos observar, os valores da sequência crescem rapidamente, de modo que o número de
termos que podem ser computados em tipos inteiros de C/C++ é bastante restrito: para variáveis
de 32-_bits_, podemos calcular o valor exato de _F(n)_ para _n_ &#8805; 46 (_F(46)_ = 1836311903);
para variáveis de 64-_bits_, temos _n_ &#8805; 92 (_F(92)_ = 7540113804746346429. Para valores
de _n_ superiores a 92, é necessário ou trabalhar com aritmética estendida ou com aritmética
modular.

### Implementação

Nesta seção trataremos do problema de se determinar o _n_-ésimo termo da sequência de Fibonacci.
Uma abordagem inicial seria o uso de recursão:
```C++
long long recursive_fibonacci(long long n)
{
    if (n == 0 or n == 1)
        return n;

    return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}
```

A implementação acima tem como vantagem a simplicidade, uma vez que mapeia diretamente a definição
da sequência no código, mas tem complexidade assintótica de _O(2^n)_. Em compiladores mais 
antigos tal código teria dificuldades de computar o valor de _F(16)_, porém os compiladores 
modernos conseguem otimizar tais recursão (_tail recursion optimization_), o que permite usar
tal implementação em casos menores. A título de curiosidade, em um teste realizado em um 
notebook com processador i7 e 8 GB de RAM, _F(46)_ foi computado em 6,6 segundos.

Para melhorar o tempo de execução e reduzir a complexidade assintótica, podemos fazer uma
implementação iterativa. Abaixo um exemplo de tal implementação em Python:
```Python
def iterative_fibonacci(n):

    if n < 2:
        return n

    a = 0
    b = 1

    for x in xrange(n):
        a, b = b, a + b

    return a
```

Esta nova versão tem complexidade assintótica igual a _O(n)_. Um teste na mesma máquina permitiu
o cálculo de _F(46)_ em apenas 0,012s. Outra vantagem desta implementação é o fato da linguagem
Python trabalhar nativamente com aritmética estendida.

Outra melhoria possível no código anterior é armazenar, em memória, os termos já computados, e
retornar diretamente caso o valor já seja conhecido, e computar apenas os valores necessários
para a resposta.
```Python
fib = [0, 1]

def fibonacci(n):

    if n < len(fib):
        return fib[n]

    next = len(fib)

    while next <= n:
        fib.append(fib[next - 1] + fib[next - 2])
        next += 1

    return fib[n]
```

É possível reduzir ainda mais a complexidade assintótica do problema, modelando o problema
como uma equação de diferenças lineares. Considere _u(n)_ um vetor cujas duas componentes são
os números de Fibonacci _F(n + 1)_ e _F(n)_. Temos então a seguinte equação de diferenças:


        u(n + 1) = Au(n)

onde

        A = |  1   1  |
            |  1   0  |

Podemos observar que _u(1) = Au(0), u(2) = Au(1) = A²u(0)_, etc, e assim por diante, que nos leva
a
        u(n) = A^nu(0)

e que o termo _F(n)_ seria igual ao termo _c_ (segunda linha, primeira coluna) da matriz.

Usando exponenciação rápida para computar a potência _n_ésima, temos um algoritmo com ordem de
complexidade _O(log n)_ para determinar o _n_-ésimo termo da sequência de Fibonacci.
```C++
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
```

### Propriedades da sequência de Fibonacci

A sequência de Fibonacci tem várias propriedades interessantes:

1. a razão entre dois termos consecutivos da série tende à razão áurea (1 + &#8730;5)/2;
1. a soma dos _n_ primeiros termos da sequência é igual a _F(n + 2) - 1_ (soma telescópica);
1. a soma dos quadrados dos _n_ primeiros termos da sequência é igual a _F(n)F(n+1)_ (indução);
1. para um _m > 1_ fixo, a sequência dos restos r(n) = F(n) % m é cíclica. O tamanho destes período é denominado Período de Pisano _&#120587;(m)_. Alguns valores comuns:
    1. _&#120587;(2)_ = 3
    1. _&#120587;(10)_ = 60
    1. _&#120587;(100)_ = 300
    1. &#120587;(10^k) = 15 * 10^{k - 1}, k &#8805; 3
1. Exceto para o caso _m_ = 2, o período de Pisano é sempre par.

<!-- Criar um arquivo com as sequências especiais: Fibonacci, Catalan, Stirling, etc -->

Exercícios
----------
1. UVA
    1. [763 - Fibinary Numbers](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=704)
    1. [948 - Fibonaccimal Base](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=889)
    1. [10689 - Yet another Number Sequence](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1630)

Referências
-----------

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

WOLFRAM Math World. [Pisano Period](http://mathworld.wolfram.com/PisanoPeriod.html). Acesso em 28/09/2017.

WIKIPEDIA. [Pisano Period](https://en.wikipedia.org/wiki/Pisano_period). Acesso em 28/09/2017.

WIKIPEDIA. [Sequência de Fibonacci](https://pt.wikipedia.org/wiki/Sequência_de_Fibonacci). Acesso em 28/09/2017.
