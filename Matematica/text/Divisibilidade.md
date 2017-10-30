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

