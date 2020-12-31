---
theme: gaia
backgroundColor: black
color: lightGray
headingDivider: 2
---

<style>
    section {
        font-size: 30px;
    }

    h1 {
        font-size: 70px;
    }
</style>

<!-- _class: lead -->
# Matemática

*__Funções__*

Prof. Edson Alves
Faculdade UnB Gama

## Produtos Cartesianos

- Sejam $A$ e $B$ dois conjuntos

- O **produto cartesiano** de $A$ por $B$ é dado por
$$
A\times B = \{(a, b)\ |\ a \in A, b\in B\}
$$

- Em outras palavras, é o conjunto de todos os possíveis pares ordenados cujo primeiro elemento pertence a $A$ e o segundo pertence a $B$

- Se $A$ tem $n$ elementos e $B$ tem $m$ elementos, o produto cartesiano terá $nm$ elementos distintos

- Observe que se $A \neq B$ então $A\times B \neq B\times A$

## Relações

- Sejam $A$ e $B$ dois conjuntos

- Dizemos que $R$ é uma **relação** de $A$ em $B$ se $R \subset A\times B$, isto é, se $R$ é um subconjunto do produto cartesiano de $A$ por $B$

- Se $|A| = n$ e $|B| = m$, existem $2^{nm}$ relações de $A$ em $B$

- Se $(a,b) \in R$, dizemos que $a$ se relaciona com $b$

- Observe que $(a, b)\in R$ não implica $(b, a)\in R$

## Funções

Uma relação $f\in A\times B$ é uma **função** de $A$ em $B$ (e escrevemos $f: A \to B$) se os dois critérios abaixo forem atendidos:

1. todo elemento $a$ de $A$ se relaciona com algum elemento $b$ de $B$;
1. cada elemento $a$ de $A$ está relacionado com um único elemento $b$ de $B$.

## Injeção, sobrejeção e bijeção

- Uma função $f: A\to B$ é dita **injetora** se $f(a) = f(b)$ implica em $a = b$, isto é, cada elemento do conjunto $B$ está relacionado com um único elemento do conjunto $A$

- $f$ é dita **sobrejetora** se, para qualquer elemento $b \in B$, existe um elemento $a \in A$ tal que $f(a) = b$, ou seja, todos os elementos de $B$ estão relacionado a ao menos um elemento de $A$

- Uma função que é, ao mesmo tempo, injetora e sobrejetora é dita **bijetora**

## Função inversa

- A classificação de uma função como injetora ou sobrejetora está relacionada diretamente aos dois critérios da definição de funções

- Considere uma função $f: A\to B$ e seja $R\subset B\times A$ uma relação de $B$ em $A$ dada por 
$$
R = \{(b, a)\ |\ a\in A, b\in B, f(a) = b \}
$$

- Se a relação $R$ atender ao primeiro critério, então a função $f$ é sobrejetora; se atender o segundo critério, $f$ é injetora

- Se a relação $R$ atende a ambos critérios, $R$ é uma função, denominada função **inversa** de $f$

## Funções invertíveis

- Uma função $f$ é invertível se for bijetora

- A função inversa de $f: A\times B$, se existir, é grafada como $f^{-1}: B\times A$

- Se for invertível, $f$ estabelece uma relação um-a-um entre os elementos de $A$ e $B$

- Se $A$ e $B$ forem conjuntos finitos, então ambos terão o mesmo número de elementos

## Variáveis independentes

- Na notação $y = f(x)$, $x$ é a variável **independente** e $y$ é a variável **dependente**: dizemos que $y$ é função de $x$, ou que $y$ depende de $x$

- Isto significa que, conhecido o valor de $x$, é possível determinar o valor de $y$

- Uma variável pode ser dependente de mais de uma variável

- Por exemplo, área $A$ de um retângulo depende dos valores das medidas da base $b$ e da altura $h$ do retângulo, ou seja, $A = A(b, h)$

## Zeros de funções

- Seja $f: A \to B$, onde 0 (zero) pertence a $B$

- Dizemos que $x\in A$ é um **zero** de $f$ se $f(x) = 0$

- Uma função pode não ter, ter finitos ou infinitos zeros

- Exemplos:
    - a função $f(x) = 1/x$ não tem zeros nos reais
    - o Teorema Fundamental da Álgebra diz que todo polinômio de grau $n$ tem $n$ raízes complexas
    - a função $f(x) = \mathrm{sen}(x)$ tem infinitos zeros: qualquer múltiplo de $2\pi$

## Método da bisseção

- Seja $f: \mathbb{R}\to \mathbb{R}$ é uma função contínua em um intervalo $I$ dos reais, isto é, para qualquer elemento $a\in I$, o limite de $f(x)$ quanto $x$ tende a $a$ existe e é igual a $f(a)$

- Suponha que existam dois valores $a, b\in I$ tais que $f(a)f(b) < 0$, isto é, $f(a)$ e $f(b)$ tem sinais opostos

- Nestas condições, o Teorema de Valor Intermediário garante que existe ao menos um valor $c \in (a,b)$ tal que $f(c) = 0$

- O método da bisseção consiste em aproximar o valor de $c$ por meio de uma busca binária

---

```C++
// Assuma que a função f(double) esteja definida, que a < b e que f(a)*f(b) < 0
// eps é a tolerância de erro
double root(double a, double b, double eps)
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
```

## Convergência

- Por conta de possíveis erros de precisão, o método da bisseção pode não convergir ou não melhorar sua precisão após um determinado número de iterações 

- Implementações alternativas usam um número $N$ de passos pré-determinado como critério de parada

- Há outros métodos com melhor convergência, como o método de Newton

- Ainda o método da bisseção é notável por sua simplicidade e aplicabilidade

---

```C++
// Assuma que a função f(double) esteja definida, a < b e que f(a)*f(b) < 0
// N é o número de iterações do algoritmo
double root(double a, double b, int N)
{
    while (N--)
    {
        double c = (a + b)/2;

        // Determina em qual dos intervalos ( (a,c) ou (c,b) ) está o zero
        f(a)*f(c) < 0 ?  b = c : a = c;
    }

    return (a + b)/2;
}
```

## Problemas

- AtCoder
    1. [ABC 043B - Be Together](https://atcoder.jp/contests/abc043/tasks/arc059_a)
- Codeforces
    1. [486A - Calculating Function](http://codeforces.com/problemset/problem/486/A)
    1. [1036A - Function Height](https://codeforces.com/problemset/problem/1036/A)
- OJ
    1. [371 - Ackermann Functions](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=307)
    1. [10431 - Solve It](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1282)

## Referências

1. Wikipédia. [Bissection Method](https://en.wikipedia.org/wiki/Bisection_method). Acesso em 15 de agosto de 2017.
