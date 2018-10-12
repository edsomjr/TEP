Funções
=======

Conceitos Fundamentais
----------------------

Sejam A e B dois conjuntos. O **produto cartesiano** de A por B é dado por AxB = {(_a_, _b_) \| 
_a_ &#8712; A, _b_ &#8712; B}, isto é, o conjunto de todos os possíveis pares ordenados cujo 
primeiro 
elemento pertence a A e o segundo pertence a B.  Se A tem _n_ elementos e B tem _m_ elementos, o 
produto cartesiano terá _nm_ elementos distintos. Observe que se A &#8800; B então AxB &#8800; BxA.

Dizemos que R é uma **relação** de A em B se R &#8838; AxB, isto é, se R é um subconjunto do 
produto cartesiano de A por B. Desta forma, existem 2^{nm} possíveis relações de A em B. Se
(_a_,_b_) &#8712; R, dizemos que _a_ se relaciona com _b_.

Uma relação _f_ é uma **função** de A em B (e escrevemos _f_: _A_ -> _B_) se os dois critérios 
abaixo forem atendidos:

1. todo elemento _a_ de _A_ se relaciona com algum elemento _b_ de _B_;
1. cada elemento _a_ de _A_ está relacionado com um único elemento _b_ de _B_.

Uma função _f_ é dita **injetora** se _f(a) = f(b)_ implica em _a = b_ (isto é, cada elemento do
conjunto _B_ está relacionado com um único elemento do conjunto _A_); _f_ é dita **sobrejetora**
se, para qualquer elemento _b_ &#8712; _B_, existe um elemento _a_ &#8712; _A_ tal que _f(a) = b_.
Uma função que é, ao mesmo tempo, injetora e sobrejetora é dita **bijetora**.

Veja que a classificação anterior está relacionada diretamente aos dois critérios da definição
de funções. Seja _R_ a relação de _B_ em _A_ definida por 
_R_ = {(_b, a_) | _b_ &#8712; _B_, _a_ &#8712; _A_, e _f(a) = b_}. Se a relação _R_ atender ao 
primeiro critério, então a função _f_ é sobrejetora; se atender o segundo, _f_ é injetora. Se
a relação _R_ atende a ambos critérios, efetivamente _R_ é uma função, denominada função inversa
de _f_.

Assim, uma função é inversível se for bijetora, e esta função estabelece uma relação um-a-um 
entre os elementos de _A_ e _B_. Se _A_ e _B_ forem conjuntos finitos, então ambos terão o
mesmo número de elementos.

Na notação _y = f(x)_, _x_ é a variável **independente** e _y_ é a variável **dependente**: 
dizemos que _y_ é função de _x_, ou que _y_ depende de _x_. Isto significa que, conhecido o valor 
de _x_, é possível determinar o valor de _y_. Uma variável pode ser dependente de mais de uma
variável: por exemplo, área _A_ de um retângulo depende dos valores das medidas da base _b_ e da
altura _h_ do retângulo, ou seja, _A = A(b, h)_.

Zeros de funções
----------------

Seja _f_: _A_ -> _B_, onde 0 (zero) pertence a _B_. Dizemos que _x_ &#8712; _A_ é um **zero** de
_f_ se _f(x) = 0_. Uma função pode não ter, ter finitos ou infinitos zeros. Por exemplo, a 
função _f(x) = 1/x_ não tem zeros nos reais; o Teorema Fundamental da Álgebra diz que todo
polinômio de grau _n_ tem _n_ raízes complexas; e a função _f(x) = sen(x)_ tem infinitos zeros:
qualquer múltiplo de 2&#120587;.

Se _f_ é uma função contínua em um intervalo _I_ dos reais (isto é, para qualquer elemento 
_a_ &#8712; I, o limite de _f(x)_ quanto _x_ tende a _a_ existe e é igual a _f(a)_) tal que,
para dois valores _a, b_ &#8712; I, _f(a)f(b) < 0_ (isto é, _f(a)_ e _f(b)_ tem sinais opostos),
então existe um valor _c_ &#8712; (_a,b_) tal que _f(c) = 0_. O valor de _c_ pode ser 
aproximado por busca binária, conforme mostra o código abaixo. Tal método é conhecido como
método da bisseção.
```C++
// Assuma que a função f(double) esteja definida, a < b e que f(a)*f(b) < 0
// eps é o erro esperado
double root(double a, double b, double eps)
{
    while (fabs(a - b) > eps)
    {
        double c = (a + b)/2;
        y = f(c);

        // c é uma boa aproximação para o zero
        if (fabs(y) < eps)
            return c;

        // Determina em qual dos intervalos ( (a,c) ou (c,b) ) está o zero
        if (f(a)*y < 0)
            b = c;
        else
            a = c;
    }

    return (a + b)/2;
}
```

Por conta de possíveis erros de precisão, este algoritmo pode não convergir ou não melhorar
sua precisão após _N_ passos. Implementações alternativas usam um número de passos _N_
pré-determinado como critério de parada.
```C++
// Assuma que a função f(double) esteja definida, a < b e que f(a)*f(b) < 0
// N é o número de iterações do algoritmo
double root(double a, double b, int N)
{
    while (N--)
    {
        double c = (a + b)/2;
        y = f(c);

        // Determina em qual dos intervalos ( (a,c) ou (c,b) ) está o zero
        if (f(a)*y < 0)
            b = c;
        else
            a = c;
    }

    return (a + b)/2;
}
```

Exercícios
----------

<!-- 486A - Function evaluation -->
<!-- 10341 - Método de Newton -->

1. Codeforces
    1. [486A - Calculating Function](http://codeforces.com/problemset/problem/486/A)
1. UVA
    1. [10431 - Solve It](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1282)

Referências
-----------

WIKIPEDIA. [Bissection Method](https://en.wikipedia.org/wiki/Bisection_method). Acesso em 15 de agosto de 2017.

