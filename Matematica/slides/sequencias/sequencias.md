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

*__Sequências e Séries__*

Prof. Edson Alves
Faculdade UnB Gama

## Definição de sequência e subsequência

Uma sequência $a_n$ é uma função cujo domínio é um subconjunto $A$ dos números naturais.

Uma subsequência $b_n$ de $a_n: A \to X$ é uma sequência $b_n: B\subset A \to X$ tal que $b_i = a_i$ para todos $i\in B$.

## Monotonicidade

Uma sequência $a_n$ é monotamente crescente, ou não-decrescente, se $a_{i + 1} \geq a_i$ para todos $i\in A$.

Uma sequência $a_n$ é monotamente decrescente, ou não-crescente, se $a_{i + 1} \leq a_i$ para todos $i\in A$.

## Sequência aritmética

Uma sequência (ou progressão) aritmética é uma sequência cuja diferença entre dois termos consecutivos é constante. Esta diferença recebe o nome de **razão** da progressão aritmética.

## Termo geral da progressão aritmética

O $k$-ésimo termo de uma progressão aritmética $a_n$ de razão $r$ é dado por
$$
    a_k = a_1 + (k - 1)r,
$$
onde $a_1$ é o primeiro termo da sequência.

De modo geral,
$$
    a_k = a_m + (k - m)r,
$$
onde $a_m$ é o $m$-ésimo elemento.

## Sequência geométrica

Uma sequência (ou progressão) geométrica é uma sequência cuja quociente entre dois termos consecutivos é constante. Este quociente recebe o nome de **razão** da progressão geométrica.

## Termo geral da progressão geométrica

O $k$-ésimo termo da progressão geométrica $a_n$ de razão $q$ é dado por
$$
    a_k = a_1q^{k - 1},
$$
onde $a_1$ é o primeiro termo da progressão.

## Séries

O $k$-ésimo termo da série $S_n$ é determinado pela soma dos primeiros $k$ termos de uma sequência $a_n$, isto é
$$
    S_k = \sum_{i = 1}^k a_i = a_1 + a_2 + \ldots + a_k
$$

## Série da progressão aritmética

O $k$-ésimo termo da série definida pela progressão aritmética $a_n$ de razão $r$ é dado por
$$
    S_k = \frac{k(a_1 + a_k)}{2}
$$

Esta expressão pode ser deduzida através da soma das expressões
$$
\begin{array}{rl}
    S_k\! \! \! \! &= a_1 + (a_1 + r) + (a_1 + 2r) + \ldots + (a_1 + (k - 1)r) \\
    S_k\! \! \! \! &= (a_k - (k - 1)r) + (a_k - (k - 2)r) + \ldots + (a_k - r) + a_k
\end{array}
$$

## Série da progressão geométrica

O $k$-ésimo termo da série definida pela progressão geométrica $a_n$ de razão $q$ é dado por
$$
    S_k = \frac{a_1(1 - q^k)}{1 - q}
$$

Esta expressão pode ser deduzida através da diferença das expressões
$$
\begin{array}{rl}
    S_k\! \! \! \! &= a_1 + a_1q + a_1q^2 + \ldots + a_1q^{k - 1} \\
    qS_k\! \! \! \! &= a_1q + a_1q^2 + a_1q^3 + \ldots + a_1q^k \\
\end{array}
$$

## Soma da progressão geométrica infinita

Se $a_n$ é uma progressão geométrica de razão $|q| = 1$, então a série $S_n$ converge para o limite $S$ quando $n$ tende ao infinito, onde
$$
    S = \sum_{i = 1}^\infty a_i = \lim_{n\to \infty} S_n = \lim_{n\to \infty} \frac{a_1(1 - q^n)}{1 - q} = \frac{a_1}{1 - q}
$$

## Séries notáveis

Soma dos $n$ primeiros naturais:
$$
    S_n = \sum_{i = 1}^n i = 1 + 2 + 3 + \ldots + n = \frac{n(n + 1)}{2}
$$

Soma dos quadrados dos $n$ primeiros naturais:
$$
    S_n = \sum_{i = 1}^n i^2 = 1^2 + 2^2 + 3^2 + \ldots + n^2 = \frac{n(n + 1)(2n + 1)}{6}
$$

## Séries notáveis

Soma dos cubos dos $n$ primeiros naturais:
$$
    S_n = \sum_{i = 1}^n i^3 = 1^3 + 2^3 + 3^3 + \ldots + n^3 = \left[\frac{n(n + 1)}{2}\right]^2
$$

Soma dos $n$ primeiros ímpares:
$$
    S_n = \sum_{i = 1}^n  2i - 1 = 1 + 3 + 5 + \ldots + (2n - 1) = n^2
$$

## Série de Newton

A série de Newton é formada pelos termos da equação de diferenças finitas de Newton. Ela consiste em uma versão discreta da série de Taylor:
$$
    f(x) = \sum_{k = 0}^\infty \frac{\Delta^k[f](a)}{k!}(x - a)_k,
$$
onde
$$
    \Delta^k[f](a) = \Delta(\Delta^{k - 1}[f](a)), \ \ \ \ \Delta^1[f](a) = \Delta[f](a) = f(x + 1) - f(x)
$$
e
$$
    x_k = x(x - 1)(x - 2)\ldots (x - k + 1)
$$

## Representação de sequências arbitrárias por meio de polinômios

A série de Newton pode ser utilizada para obter um polinômio $p(x)$ que gera uma sequência finita $a_n$ qualquer. Por exemplo, seja $a_n = 3, 7, 13, 21, 31$. O quadro abaixo computa as diferenças finitas para esta sequência.

| $x$ | $f = \Delta^0$ | $\Delta^1$ | $\Delta^2$ | $\Delta^3$ |
| --- | --- | --- | --- | --- |
| 1 | *3* | | | |
| 2 | 7 | *4* | | |
| 3 | 13 | 6 | *2* | |
| 4 | 21 | 8 | 2 | *0* |
| 5 | 31 | 10 | 2 | 0 |

## Exemplo de representação de sequências arbitrárias por meio de polinômios

Conforme pode ser observado, $\Delta^k = 0$ para todo $k > 2$. Isto significa que a sequência $a_n$ pode ser representada por um polinômio de grau 2. Este polinômio pode ser obtido por meio da substituição dos termos $\Delta$ da fórmula apresentada (em itálico na tabela):
$$
\begin{array}{rl}
    f(x)\! \! \! \! &= \Delta^0 \cdot 1 + \Delta^1 \cdot \dfrac{(x - 1)_1}{1!} + \Delta^2\cdot \dfrac{(x - 1)_2}{2!} \\
    &= 3\cdot 1 + 4(x - 1) + 2\cdot \dfrac{(x - 1)(x - 2)}{2} \\
    &= x^2 + x  + 1
\end{array}
$$

## Problemas

- Codeforces
    1. [51D - Geometrical Problem](https://codeforces.com/problemset/problem/51/D)
    1. [255C - Almost Arithmetic Progression](https://codeforces.com/problemset/problem/255/C)
    1. [382C - Arithmetic Progression](https://codeforces.com/problemset/problem/382/C)
    1. [567C - Geometric Progression](https://codeforces.com/problemset/problem/567/C)
    1. [789B - Masha and Geometric Depression](https://codeforces.com/problemset/problem/789/B)

## Referências

1. Byju's Classes. [Sequence And Series](https://byjus.com/maths/sequence-and-series/). Acesso em 03/02/2021.

1. Wikipédia. [Arithmetic progression](https://en.wikipedia.org/wiki/Arithmetic_progression). Acesso em 03/02/2021.

1. Wikipédia. [Finite Difference](https://en.wikipedia.org/wiki/Finite_difference). Acesso em 03/02/2021.

1. Wikipédia. [Geometric progression](https://en.wikipedia.org/wiki/Geometric_progression). Acesso em 03/02/2021.

1. Wikipédia. [Sequence](https://en.wikipedia.org/wiki/Sequence). Acesso eme 03/02/2021.
