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

*__Logaritmos__*

Prof. Edson Alves
Faculdade UnB Gama

## Definição de logaritmo

Sejam $a, x$ dois números reais tais que $a > 1$. Dizemos que $y$ é o logaritmo de $x$ na base $a$ se $a^y = x$. **Notação**: $y = \log_a x$.

Duas importantes propriedades decorrente diretamente desta definição:

1. Como a base $a$ é estritamente maior do que 1, o logaritmo não está definido para valores de $x$ menores ou iguais a zero;
1. $\log_a 1 = 0$, qualquer que seja a base $a > 1$.

## Propriedades dos logaritmos

Sejam $a, x, y$ três números reais tais que $a > 1$. Vale que

1. $\log_a xy = \log_a x + \log_a y$
1. $\log_a \left(\dfrac{x}{y}\right) = \log_a x - \log_a y$
1. $\log_a x^y = y\log_a x$

Essas três propriedades são consequências diretas das propriedades da exponenciação.

## Mudança de base 

Sejam $a, b$ dois números reais com maiores do que 1. Então, para qualquer $x$ real, vale que
$$
    \log_a x = \frac{\log_b x}{\log_b a}
$$

Em outras palavras, os logaritmos de um real $x$ em duas bases distintas são proporcionais a uma constante definida por ambas bases.

## Logaritmos e representações numéricas

Seja $n, b$ dois inteiros positivos com $b > 1$. A representação de $n$ na base $b$ é dada por
$$
    n = d_0 + d_1b + d_2b^2 + \ldots + d_kb^k
$$

Das propriedades dos logaritmos,
$$
    \log_b n \geq \log_b d_kb^k \geq \log_b b^k = k
$$

## Logaritmos e representações numéricas

Por outro lado,
$$
\log_b n < \log_b b^{k + 1} = k + 1
$$

Seja $D(n, b)$ o número de dígitos de $n$ na base $b$. Assim
$$
    D(n, b) = k + 1 = \lfloor \log_b n\rfloor + 1,
$$
onde $\lfloor x \rfloor$ é o maior inteiro menor ou igual a $x$.

## Logaritmos em C/C++

- A biblioteca `math.h` de C ou a biblioteca `cmath` do C++ oferecem funções para o cálculo de logaritmos
- A função `log(x)` computa o valor do logaritmo de $x$ na base $e$ ($\ln x$)
- A função `log2(x)` computa o valor do logaritmo de $x$ na base 2
- A função `log10(x)` computa o valor do logaritmo de $x$ na base 10
- Essas funções recebem e retornam valores do tipo `double`

## Problemas

- OJ
    1. [113 - The Power of Cryptography](http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=49)
    1. [701 - The Archeologists' Dilemma](http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=642)
    1. [1185 - Big Number](http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3626)
    1. [11384 - Help is needed for Dexter](http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2379)
    1. [11847 - Cut the Silver Bar](http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2947)

## Referências

CppReference. [Common mathematical functions](https://en.cppreference.com/w/cpp/numeric/math). Acesso em 05/01/2021.

Wikipédia. [Logarithm](https://en.wikipedia.org/wiki/Logarithm#:~:text=In%20mathematics%2C%20the%20logarithm%20is,to%20produce%20that%20number%20x.). Acesso em 05/01/2021.
