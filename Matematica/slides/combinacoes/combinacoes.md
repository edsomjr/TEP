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

*__Combinações__*

Prof. Edson Alves
Faculdade UnB Gama

## Combinações

Seja $A$ um conjunto com $n$ elementos distintos e $p$ um inteiro não negativo tal que $p \leq n$.  Uma **combinação** deste $n$ elementos, tomados $p$ a $p$, consiste em uma escolha de $p$ elementos distintos dentre os $n$ possíveis, onde cada combinação difere das demais pela qualidade dos elementos, mas não pela ordem.

**Notação**: $C(n, p)$

Por exemplo, se $A = \{1, 2, 3, 4\}$ e $p = 2$, há $6$ combinações distintas, a saber: $12, 13, 14, 23, 24, 34$.

## Cálculo de $C(n, p)$

- Se $p > 0$, então $C(n, p)$ = 0

- Nos demais casos, $C(n,p)$ pode ser computado a partir de $A(n,p)$: basta contar como apenas um todos os arranjos que diferem apenas pela ordem de seus elementos

- Como $p$ elementos distintos geram $p!$ arranjos distintos, segue que
$$
        C(n, p) = \frac{A(n, p)}{p!} = \frac{n!}{(n - p)!p!} = \binom{n}{p}
$$

## Coeficientes binomiais

Sejam  $n$ e $p$ dois inteiros não-negativos tais que $n\geq p$. O coeficiente binomial é dado por
$$
    \binom{n}{p} = \frac{n!}{(n - p)!p!}
$$

## Implementação dos coeficientes binomiais

- Na prática, pode ser que o valor de $\binom{n}{p}$ possa ser armazenado em uma variável inteira, mas os fatoriais envolvidos no numerador e no denominador levar ao _overflow_ nos cálculos intermediários

- Há duas maneiras de contornar este problema: por cancelamento ou por recorrência.

- A ideia do cancelamento é que, embora seja representado na forma de fração, $\binom{n}{p}$ é sempre um número inteiro

- Assim, é possível realizar os cancelamentos devidos antes de multiplicar os fatores restantes

## Implementação dos binomais por cancelamento

```C++
long long binom(int n, int m, const vector<int>& primes)
{
    if (n < m)
        return 0;

    long long res = 1;

    for (auto p : primes) {
        if (p > n)
            break; 

        auto k = E(n, p) - E(m, p) - E(n - m, p);

        while (k--)
            res *= p;
    }

    return res;
}
```

## Triângulo de Pascal

- Os números binomiais surgem nas expansões do monômio $(a + b)^n$, para $n$ não-negativo

- Estas expansões formam o Triângulo de Pascal:

```
1
1  1
1  2  1
1  3  3  1
1  4  6  4  1
1  5 10 10  5  1
...
```
- A observação cuidadosa deste triângulo permite definir os coeficientes binomais recursivamente

## Definição recursiva dos coeficientes binomiais

Sejam $n$ e $m$ inteiros não-negativos. Então
$$
        \binom{n}{0} = \binom{n}{n} = 1
$$
e
$$
        \binom{n}{m} = \binom{n - 1}{m} + \binom{n - 1}{m - 1}
$$

## Implementação dos coeficientes binomiais por DP
```C++
long long binom(int n, int m)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = dp[i][i] = 1;

        for (int j = 1; j < i; ++j)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }

    return dp[n][m];
} 
```

## Redução da complexidade de memória

- A implementação acima tem complexidade $O(n^2)$ para execução e memória

- É possível reduzir o uso de memória para $O(m)$ através de uma implementação cuidadosa, que se vale das propriedades da recorrência

- A ideia central é computar os coeficientes de cada linha da direita para a esquerda, uma vez que o coeficiente da próxima linha é computado a partir do coeficiente que ocupa a mesma posição na linha anterior e o coeficiente da linha anterior na posição anterior

## Implementação dos coeficientes binomiais em $O(nm)$ memória $O(m)$
```C++
long long binom(int n, int m)
{
    if (m > n)
        return 0;

    vector<long long> dp(m+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; ++i)
        for(int j = m; j > 0; --j)
            dp[j] = dp[j] + dp[j - 1];

	return dp[m];
}
```

## Propriedades dos coeficientes binomiais

Uma propriedade dos binomiais, que pode ser utilizada para cortar o tamanho da tabela de
binomiais pela metade, é a sua simetria:

        binom[n][p] = binom[n][n - p]

Assim, basta computar a tabela até o valor _n_/2 e usar a simetria para os demais casos.



Os coeficientes binomiais possuem uma série de propriedades interessantes, que podem ser 
úteis na solução de problemas de contagem. Abaixo listamos algumas delas.

1. _C(n, 0) + C(n, 1) + C(n, 2) + ... + C(n, n) = 2^n_ (consequência da expansão do binômio (1 + 1)^_n_))
1. _C(n, 0) - C(n, 1) + C(n, 2) - ... + (-1)^n C(n, n) = 0_ (consequência da expansão do binômio (1 - 1)^_n_))
1. _C(p, p) + C(p, p + 1) + ... + C(p, p + n) = C(p + 1, p + n + 1)_ (consequência da propriedade _C(n + 1, p + 1) = C(n, p + 1) + C(n, p)_)



Aplicações
----------

### Equações Lineares com Coeficientes Unitários

Considere a equação linear dada por

        x1 + x2 + ... + xr = n

com _r_ natural e _n_ inteiro. Quando as variáveis _xi_ pertencem aos reais, racionais ou 
inteiros, a equação tem infinitas soluções. O número de soluções, porém, fica restrito, ou mesmo
pode não haver solução, caso as variáveis estejam restritas aos inteiros positivos.

De fato, se _n < r_, a equação não tem solução nos inteiros positivos. Para _n >= r_, escrevamos
o valor _r_ como uma soma de uns:

        r = 1 + 1 + 1 + ... + 1

Podemos montar cada solução usando _r - 1_ barras verticais, posicionadas antes dos _n - 1_ 
símbolos '+': a soma resultante à esquerda de cada uma das barras, e à direita da última, 
corresponde aos valores das _n_ variáveis _xi_. Cada uma das soluções nos inteiros positivos
corresponde a um posicionamento distinto das barras. Assim, o total de soluções é dado por
_C(n - 1, r - 1)_, isto é, uma combinação das _r - 1_ barras nas _n - 1_ posições disponíveis.

Se permitirmos que as variáveis assumam também o valor zero, podemos encontrar o novo total de
soluções através de uma mudança de variáveis. Faça _yi = xi - 1_. Assim, _xi = yi + 1_ e teremos

        x1 + x2 + ... + xr = n,                             xi >= 0
        (x1 + 1) + (x2 + 1) + ... + (xr + 1) = n + r
        y1 + y2 + ... + yr = n + r,                         yi >= 1

Assim, o número de soluções da equação original, restrito aos inteiros não-negativos, é dado por
_C(n + r - 1, r - 1)_, ou sua combinação complementar, = _C(n + r - 1, n)_.

Por exemplo,

        x1 + x2 + x3 = 10

tem _C(10 - 1, 3 - 1)_ = _C(9, 2)_ = 36 soluções nos inteiros positivos, e _C(10 + 3 - 1, 3 - 1)_
= _C(12, 2)_ = 66 soluções nos inteiros não-negativos.

### Combinações com repetição

Uma combinação com repetição de _n_ elementos distintos, tomados _p_ a _p_, é uma escolha de _p_ 
dentre os _n_, é um escolha de p objetos, dentre os _n_ possíveis, onde cada objeto pode ser
escolhido até _p_ vezes.

O total _CR(n, p)_ de combinações com repetições pode ser determinado a partir do seguinte
raciocínio: seja _xi_ a quantidade de vezes que o objeto _i_ foi escolhido, com 0 &8804; _xi_
&8804; _p_). Então o número de combinações com repetição de _n_ elementos tomados _p_ a _p_ será
igual ao número de soluções da equação

        x1 + x2 + ... + xn = p,

isto é,

        CR(n, p) = C(p + n - 1, n - 1) = C(p + n - 1, p)


### Permutações com repetição

Um permutação com repetição consiste em uma ordenação de _n_ elementos, não necessariamente
distintos. Se há _k_ elementos distintos, e cada um deles ocorre _ni_ vezes (com i = 1, 2, ...,
_k_), de forma que _n1 + n2 + ... + nk_ = _n_, temos que o número de permutações com repetição
será igual a 

        PR(n; n1, n2, ..., nk) = n!/(n1!n2!...nk!)

Os fatores no denominador compensam as possíves duplicatas nas permutações devido a repetição de
um ou mais elementos. Veja que se _ni = 1_, para todo valor de _i_, então

        PR(n; 1, 1, ..., 1) = n!/(1!1!....1!) = n! = P(n)

### Arranjos com repetição


Um arranjo com repetição de _n_ elementos, tomados _p_ a _p_, tomado até _p_ vezes, é uma 
ordenação destes elementos onde cada elemento pode aparecer até _p_ vezes.

Se _AR(n,p)_ é o total de arranjos com repetição de _n_ elementos, tomados _p_ a _p_, o 
princípio multiplicativo nos diz que há, para cada posição, _n_ escolhas. Como há _p_ posições a
serem preenchidas, temos que

        AR(n, p) = n x n x ... x n = n^r

Observe que a técnica da exponenciação rápida pode ser utilizada para determinar o valor de
_AR(n, p)_.

### Permutações circulares

Se, em uma permutação, os objetos devem ser dispostos em uma formação circular, sem uma marcação
clara de início de fim, algumas permutações se tornam idênticas, a menos de uma rotação. Para
discernir apenas as permutações que não podem ser geradas a partir de rotações das demais,
é preciso fixar um elemento em uma dada posição, e permutar os demais nas posições restantes.

Deste modo, o total de permutações circulares de _n_ elementos distintos é dado por

        PC(n) = P(n - 1) = (n - 1)!


Exercícios
----------

<!-- 10219 - Combinações -->
<!-- 11115 - Arranjo com repetição -->
<!-- 11401 - Combinações com restrições, DP -->
<!-- 11955 - Binômios -->

1. UVA
    1. [10219 - Find the ways!](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1160)
    1. [11115 - Uncle Jack](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2056)
    1. [11401 - Triangle Counting](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2396)
    1. [11955 - Binomial Theorem](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3106)

Referências
-----------

SANTOS, José Plínio O., MELLO, Margarida P., MURARI, Idani T. [Introdução à Análise Combinatória](http://www.vestseller.com.br/matematica/introduc-o-a-analise-combinatoria-jose-plinio-margarida-mello-idani-murari), Editora Ciência Moderna, 2007.

Dinamic Programming Binomial Coeficient:[Geeks for Geeks](http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/)
