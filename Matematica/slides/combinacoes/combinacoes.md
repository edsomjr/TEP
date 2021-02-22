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

## Caracterização das combinações

- Assim como feito com as permutações e com os arranjos, as combinações também podem ser caracterizadas por meio de uma analogia com um sorteio de bolas

- Neste sentido, uma combinação $C(n, p)$ corresponderia a retira de $p$ bolas dentre as $n$ bolas distintas contidas em uma caixa, sem reposição, onde a ordem das bolas não é relevante

- Assim, as retiradas $123, 321$ e $213$, por exemplo, seriam todas consideradas uma mesma combinações, uma vez que a qualidade das bolas é a mesma, embora tenha sido retiradas em ordens distintas
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

## Implementação dos binomiais por cancelamento

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
- A observação cuidadosa deste triângulo permite definir os coeficientes binomiais recursivamente

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

- Combinações complementares (permite a redução do espaço de memória em 50%):
$$
    \binom{n}{p} = \binom{n}{n - p}
$$

- Soma de uma linha (consequência da expansão do binômio $(1 + 1)^n$):
$$
    \binom{n}{0} + \binom{n}{1} + \ldots + \binom{n}{n} = 2^n
$$

## Propriedades dos coeficientes binomiais

- Soma alternada de uma linha (consequência da expansão do binômio $(1 - 1)^n$):
$$
    \binom{n}{0} - \binom{n}{1} + \ldots + (-1)^n\binom{n}{n} = 0
$$

- Soma de uma coluna, com $n\geq p$ (_Hockey-Stick Identity_):
$$
    \binom{p}{p} + \binom{p + 1}{p} + \binom{p + 2}{p} + \ldots + \binom{n}{p} = \binom{n + 1}{p + 1}
$$

## Identidades úteis

- Soma de uma linha com coeficientes lineares:
$$
    \sum_{k = 0}^n k\binom{n}{k} = n2^{n - 1}
$$

- Soma de uma linha com coeficientes quadráticos:
$$
    \sum_{k = 0}^n k^2\binom{n}{k} = (n^2 + n)2^{n - 2}
$$

## Identidades úteis

- Soma dos quadrados dos coeficientes de uma linha:
$$
    \sum_{k = 0}^n \binom{n}{k}^2 = \binom{2n}{n}
$$

- Se $F(n)$ é o $n$-ésimo número de Fibonacci, vale que
$$
    \sum_{k = 0}^{\lfloor \frac{n}{2}\rfloor} \binom{n - k}{k} = F(n + 1)
$$

## Equações lineares com coeficientes unitários

- Considere, para $r$ natural e $n$ inteiro, a equação linear dada por
$$
        x_1 + x_2 + \ldots + x_r = n
$$

- Quando as variáveis $x_i$ pertencem aos reais, racionais ou inteiros, a equação tem infinitas soluções

- O número de soluções, porém, fica restrito, ou mesmo pode não existir solução, caso as variáveis estejam restritas aos inteiros positivos

## Barras e estrelas

- De fato, se $n < r$, a equação não tem solução nos inteiros positivos

- Para $n \geq r$, o valor $n$ pode ser escrito como
$$
        n = 1 + 1 + 1 + \ldots + 1
$$

- Cada solução pode ser construída substituindo-se $r - 1$ dentre os símbolos `+` da soma anterior por barras verticais

- A soma resultante à esquerda de cada uma das barras, e à direita da última, corresponde aos valores das $r$ variáveis $x_i$

- Esta estratégia é conhecida como barras e estrelas (_Stars and bars_)

## Solução das equações lineares com coeficientes unitários restritas aos positivos

- Cada uma das soluções nos inteiros positivos corresponde a um posicionamento distinto das barras

- Assim, o total de soluções é dado por 
$$
    S = C(n - 1, r - 1) = \binom{n - 1}{r - 1}
$$

- Ou seja, basta tomar $r - 1$ dentre os $n - 1$ símbolos `+`

## Equações lineares com coeficientes unitários restritas aos não-negativos

- Caso as variáveis $x_i$ possam assumir também o valor zero, o novo total de soluções pode ser determinado por meio de uma mudança de variáveis

- Considere a equação abaixo, com $r$ e $n$ positivos e $x_i\geq 0$:
$$
        x_1 + x_2 + \ldots + x_r = n
$$
- Fazendo $y_i = x_i + 1$, isto é, $x_i = y_i - 1$, obtém-se a equação equivalente
$$
        y_1 + y_2 + \ldots + y_r = n + r, \ \ \ \ y_i\geq 1
$$

## Solução das equações lineares com coeficientes unitários restritas aos não-negativos

Assim, o número de soluções da equação original, restrito aos inteiros não-negativos, é dado por $C(n + r - 1, r - 1)$, ou sua combinação complementar, = $C(n + r - 1, n)$.

Por exemplo,
$$
        x_1 + x_2 + x_3 = 10
$$
tem $C(10 - 1, 3 - 1) = C(9, 2) = 36$ soluções nos inteiros positivos, e $C(10 + 3 - 1, 3 - 1) = C(12, 2) = 66$ soluções nos inteiros não-negativos.

## Combinações com repetição

Uma combinação com repetição de $n$ elementos distintos, tomados $p$ a $p$, é um escolha de $p$ objetos, dentre os $n$ possíveis, onde cada objeto pode ser escolhido até $p$ vezes.  

**Notação**: $CR(n, p)$

## Cálculo de $CR(n, p)$

- Seja $x_i$ a quantidade de vezes que o objeto $i$ foi escolhido em uma combinação, com $0 \leq x_i\leq p$

- Então o número de combinações com repetição de $n$ elementos tomados $p$ a $p$ será igual ao número de soluções da equação
$$
    x_1 + x_2 + \ldots + x_n = p
$$

- Conforme visto anteriormente,
$$
    CR(n, p) = C(p + n - 1, n - 1) = C(p + n - 1, p)
$$

## Caracterização das combinações com repetições

- A combinação com repetição é o primeiro de quatro problemas fundamentais de contagem

- Estes problemas tratam da questão de se distribuir $n$ bolas em $p$ caixas

- Na combinação com repetições, as $n$ bolas são idênticas e as $p$ caixas são distintas

- Observe que, nesta analogia, uma ou mais caixas podem ficar vazias ($x_i\geq 0$)

## Problemas

<!-- 10219 - Combinações -->
<!-- 11115 - Arranjo com repetição -->
<!-- 11401 - Combinações com restrições, DP -->
<!-- 11955 - Binômios -->

- AtCoder
    1. [ABC 094D - Binomial Coefficients](https://atcoder.jp/contests/abc094/tasks/arc095_b)
    1. [ABC 132D - Blue and Red Balls](https://atcoder.jp/contests/abc132/tasks/abc132_d)
- Codeforces
    1. [478B - Random Teams](https://codeforces.com/problemset/problem/478/B)
- OJ
    1. [10219 - Find the ways!](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1160)
    1. [11955 - Binomial Theorem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3106)

## Referências

1. GeeksForGeeks. [Dinamic Programming Binomial Coeficient](http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/). Acesso em 14/01/2021.

1. **SANTOS**, José Plínio O., **MELLO**, Margarida P., **MURARI**, Idani T. _Introdução à Análise Combinatória_, Editora Ciência Moderna, 2007.

1. Wikipédia. [Binomial coefficient](https://en.wikipedia.org/wiki/Binomial_coefficient). Acesso em 14/01/2021.

1. Wikipédia. [Hockey-stick identity](https://en.wikipedia.org/wiki/Hockey-stick_identity). Acesso em 14/01/2021.

1. Wikipédia. [Stars and bars](https://en.wikipedia.org/wiki/Stars_and_bars_(combinatorics)). Acesso em 14/01/2021.
