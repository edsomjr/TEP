Divisibilidade
==============

Conceitos Fundamentais
----------------------

Sejam _a_ e _b_ dois números inteiros. Dizemos que _a_ **divide** _b_ (ou que _b_ é divisível por
_a_) se existe um _k_ inteiro tal que _b_ = _ak_. Caso não exista tal inteiro, dizemos que
_a_ não divide _b_. Dizemos também que _b_ é um **múltiplo** de _a_.

Naturalmente, qualquer número _a_ divide a si mesmo (pois _a_ = _a_ x 1) e 1 divide qualquer
número _m_ (pois _m_ =  1 x _m_). Veja que, segundo a definição acima, zero divide zero, pois
0 = _k_ x 0 para qualquer _k_ inteiro.

Agora, observe que, se _a_ é diferente de zero e _a_ divide _b_, então o inteiro _k_ tal que 
_b = ak_ é único: suponha que _b = ak = at_. Como _a_ é diferente de zero, vale o cancelamento
da multiplicação, de modo que _k = t_. O mesmo não acontece com zero: se _s != r_, ainda assim
temos 0 = 0 x _r_ = 0 x _s_. De fato, qualquer inteiro vezes zero é zero. Por isso o _k_ não
fica determinado (por isso que 0/0 é uma indeterminação). Para todos os demais valores _a != 0_,
podemos definir o **quociente** _k_ de _b_ por _a_ o inteiro _k_ tal que
_b = ak_.

A relação de divisibilidade _a|b_ (_a_ divide _b_) tem uma série de propriedades:

1. _a_|0;
1. se _a|b_ e _b|c_ então _a|c_ (propriedade transitiva);
1. _a|a_ (propriedade reflexiva);
1. se _a|b_ e _b|a_, então _a = +- b_;
1. se _a|b_ então _|a| <= |b|_;
1. se _a|b_ e _a|c_ então _a|(bx + cy)_, para quaisquer _x,y_ inteiros.

Divisão de Euclides
-------------------

Sejam _a,b_ inteiros, com _b != 0_. A **Divisão de Euclides** nos diz que existem únicos inteiros
_q,r_, com _0 <= r < |b|_, tais que _a = bq + r_. O número _q_ é o **quociente** da divisão,
e _r_ é o **resto**.

A divisão euclidiana não é uma divisão de menor resto, o que pode levar a alguma dúvida quando
utilizado o operador `%` da linguagem C/C++. Por exemplo, veja o código abaixo:
```C++
#include <iostream>

int main()
{
    int a = 11;
    int b = 7;

    std::cout << (a % b) << '\n';       // 4
    std::cout << (a % -b) << '\n';      // 4
    std::cout << (-a % b) << '\n';      // -4
    std::cout << (-a % -b) << '\n';     // -4

    return 0;
}
```

Segundo a divisão euclidiana, teríamos:

        11 = 7 x 1 + 4                // q = 1, r = 4
        11 = (-7) x (-1) + 4          // q = 1, r = 4
        -11 = 7 x (-2) + 3            // q = 1, r = 3
        -11 = (-7) x 2 + 3            // q = 1, r = 3

Observe que, nos casos em que _a < 0_, o operador `%` retorna um resto negativo, o que viola a
condição _0 <= r < |b|_ da divisão de Euclides. Para determinar o resto euclidiano nestes casos,
basta somar _b_ ao resto negativo.

Importante notar também que, se _r == 0_, então _b_ divide _a_.

Maior Divisor Comum
-------------------

Dados dois inteiros _a_ e _b_, o **maior divisor comum** (MDC) de _a_ e _b_ (notamos _d_ = 
(_a, b_) é o inteiro não-negativo _d_ tal que

1. _d_ divide _a_ e _d_ divide _b_;
1. se _c_ divide _a_ e _c_ divide _b_, então _c_ divide _d_.

A pŕimeira condição apresentada garante que _d_ é divisor comum; já a segunda garante que ele é o
maior dentre os divisores comuns de _a_ e _b_. Da definição pode-se observar que

1. _d == 0_ se, e somente se, _a = b = 0_;
1. (_a_, 0) = |_a_|, para todo inteiro _a_.

Como (_a, b_) = (_-a, b_) = (_a, -b_) = (_-a,-b_), podemos restringir o problema de se determinar
o MDC aos números não-negativos.

Sejam _a_ e _b_ dois inteiros não-negativos, com _b !=  0_. A divisão de Euclides garante a 
existência de inteiros _q_ e _r_ tais que _a = bq + r_, com _0 <= r < b_. Escrevendo
_r = a - bq_, é possível mostrar que _(a, b) = (b, r)_. Este resultado, atribuído a Euclides,
juntamente com o caso base apresentado anteriormente, nos permite implementar o cálculo do
 MDC de maneira eficiente e sintética.
```C++
long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}
```

Também é possível mostrar que o MDC entre _a_ é _b_ é o menor número não-negativo que pode
ser escrito como uma combinação _ax + by_. Esta interpretação é fundamental para a demonstração
de várias propriedades associadas ao MDC. Para se determinar tais inteiros _x_ e _y_ (os quais
não são únicos), podemos usar uma versão estendida do algoritmo do MDC, mostrada abaixo.
```C++
long long ext_gcd(long long a, long long b, long long& x, long long& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long d = ext_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1*(a/b);

    return d;
}
```

Uma importante aplicação do MDC e do algoritmo de Euclides estendido é a solução de Equações
Diofantinas Lineares, isto é, equações da forma _ax + by = c_, com _a, b, c, x, y_ inteiros.
Tais equações tem solução se, e somente se, _(a, b)_ divide _c_. Se isto acontecer, procedemos
da seguinte maneira

1. usando o algoritmo estendido de Euclides, determinamos _x1_ e _y1_ tais que _ax1 + by1 = d_
1. Faça _k = c / d_
1. Multiplicando a equação do passo 1 por _k_, obtemos _x0 = k x x1_ e _y0 = k * y1_, e 
_ax0 + by0 = d * k = c_.

A solução encontrada acima não é única: o conjunto completo das soluções da equação diofantina
é dado por _x = x0 + at_, _y = y0 - bt_, para qualquer _t_ inteiro. Estas expressões nos permitem
determinar, por exemplo, soluções específicas, como a de menor _x_ (ou _y_), menor diferença entre
_x_ e _y_, menor solução com _x_ e _y_ positivos, e assim por diante (se existirem).

Dois números _a_ e _b_ são dito **coprimos** se (_a, b_) = 1. Observe que, para dois inteiros
_a_ e _b_ quaisquer, se _d_ = (_a, b_), então (_a/d_, _b/d_) = 1.

Menor Múltiplo Comum
--------------------

Sejam _a_ e _b_ dois inteiros. O **menor múltiplo comum** (MMC) de _a_ e _b_ (notamos 
_m_ = [_a,b_]) é o inteiro _m_ tal que

1. _a_ divide _m_ e _b_ divide _m_;
1. se _a_ divide _n_ e _b_ divide _n_, então _m_ divide _n_.

De forma similar ao MDC, a primeira propriedade torna _m_ um múltiplo comum de _a_ e _b_; já a 
segundo o torna o menor dentre os múltiplos comuns. 

Uma importante relação entre o MDC e o MMC é que _ab = (a,b)[a,b]_. Esta relação nos permite 
computar o MMC entre dois números de forma direta, uma vez conhecido o MDC.
```C++
long long lcm(long long a, long long b)
{
    return (a/gcd(a, b))*b;
}
```

Veja que, na implementação acima, a divisão é feita antes do produto: esta ordem pode evitar 
_overflow_ em alguns casos.

Exercícios
----------

1. UVA
    1. [10407 - Simple division](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1348)
    1. [10892 - LCM Cardinality](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1833)
    1. [11827 - Maximum GCD](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2927)

Referências
-----------

HEFEZ, Abramo. [Aritmética](https://loja.sbm.org.br/index.php/sbm/colecao-profmat/aritmetica.html).

