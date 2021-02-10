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
*__Polinômios__*

Prof. Edson Alves
Faculdade UnB Gama

## Definição de polinômios

Seja $A$ o conjuntos dos coeficientes e $V$ o conjuntos das variáveis. Um polinômio é definido por meio de elementos de $A$ e de um subconjunto de variáveis de $V$ atráves de operações ariméticas de adição, subtração, multiplicação e divisão.

## Polinômios univariados

Um polinômio univariado, isto é, definido em uma única variável $x$, pode ser escrito como
$$
a_0 + a_1x + a_2x^2 + \ldots + a_Nx^N
$$

Em forma de somatório,
$$
\sum_{i = 0}^N a_ix^i
$$

O maior expoente da variávei $x$ na expressão que define o polinômio ($N$ nas notações acima, se $a_N\neq 0$) é denominado __grau__ do polinômio.

## Polinômios em C/C++

Polinômios podem ser representados em C/C++ através de _arrays_ ou de vetores:
```C++
    using polynomial = vector<int>;
```

Observe que um polinômio de grau $N$ tem $N + 1$ coeficientes:
```C++
    int degree(const polynomial& p) { return p.size() - 1; }
```

Em geral, os coeficientes são armazenados do termo constante ao termo que determina o grau do polinômio.

```C++
    polynomial p { 6, -5, 1 };         // p(x) = x^2 - 5x + 6
```

## Função polinomial

- Todo polinômio está associado a uma função $p(x)$ dada por
$$
p(x) = a_0 + a_1x + a_2x^2 + \ldots + a_Nx^N
$$

- Para computar o valor $y_0$ associado ao valor $x_0$ por $p(x)$, basta substituir todas as ocorrências de $x$ no polinômio por $x_0$, isto é,
$$
y_0 = a_0 + a_1x_0 + a_2x_0^2 + \ldots + a_Nx_0^N
$$

- O cálculo de $y_0$ tem complexidade $O(N^2)$, se cada termo $x^i$ for computado por meio de somas repetidas

## Algoritmo de Horner

- O algoritmo de Horner computa $y_0 = p(x_0)$ com complexidade $O(N)$

- Este algoritmo é baseado na regra de Horner:
$$
a_0 + a_1x + a_2x^2 + \ldots + a_Nx^N = a_0 + x(a_1 + x(a_2 + \ldots + x(a_N) + \ldots))
$$

- O algoritmo inicia fazendo $y_0 \leftarrow 0$ e $i \leftarrow N$

- Para cada $i$ ele atualiza o valor de $y$ por meio de duas operações:

    1. $y_0 \leftarrow y_0 \times x_0$
    1. $y_0 \leftarrow y_0 + a_i$

- Em seguida, o valor de $i$ é decrementado

## Implementação do algoritmo de Horner

```C++
int evaluate(const polynomial& p, int x)
{
    int y = 0, N = degree(p);

    for (int i = N; i >= 0; --i)
    {
        y *= x;
        y += p[i];
    }

    return y;
}
```

## Zeros de polinômios

- Se $p(x_0) = 0$, dizemos que $x_0$ é um __zero__ (ou raiz) de $p(x)$

- O Teorema Fundamental da Álgebra afirma que um polinômio de grau $N$ tem $N$ raizes complexas (não necessariamente distintas)

- O polinômio $p(x) = a_0 + a_1x$, com $a_1\neq 0$, tem um único zero, a saber:
$$
    x = - \frac{a_0}{a_1}
$$

## Zeros de polinômios

- O polinômio $p(x) = a_0 + a_1x + a_2x^2$, com $a_2\neq 0$, tem duas raizes complexas, que podem ser obtidas por meio da fórmula de Báskara:
$$
    x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}
$$

- Há expressões semelhantes para polinômios de grau 3 (Formula de Cardano/Tartaglia) e 4 (Fórmula de Ferrari), porém não são de fácil memorização

- Para polinômios de grau 5 ou maior, Galois mostrou, usando a Teoria dos Grupos, que não há expressão racional para computar suas raizes

## Adição de polinômios

A adição de dois polinômios $p(x) = a_0 + a_1x + \ldots, a_Nx^N$ e $q(x) = b_0 + b_1x + \ldots + b_Mx^M$ resulta em um polinômio
$$
r(x) = p(x) + q(x) = (a_0 + b_0) + (a_1 + b_1)x + \ldots + (a_R + b_R)x^R,
$$
onde $R \leq \max\{N, M\}$, $a_i = 0$, se $i > N$ e $b_j = 0$, se $j > M$.

## Implementação da adição de polinômios

```C++
polynomial operator+(const polynomial& p, const polynomial& q)
{
    int N = degree(p), M = degree(q);
    polynomial r(max(N, M) + 1, 0);

    for (int i = 0; i <= N; ++i)
        r[i] += p[i];

    for (int i = 0; i <= M; ++i)
        r[i] += q[i];

    while (not r.empty() and r.back() == 0)
        r.pop_back();

    return r;
}
```

## Multiplicação de polinômios

## Divisão de polinômios

## Fatoração de polinômios
## Relações de Girard

## Referências

1. Wikipédia. [Horner's method](https://en.wikipedia.org/wiki/Horner%27s_method). Acesso em 10/02/2021.

1. Wikipédia. [Polynomial](https://en.wikipedia.org/wiki/Polynomial). Acesso em 10/02/2021.

1. WolframMathWorld. [Cubic Formula](https://mathworld.wolfram.com/CubicFormula.html). Acesso em 10/02/2021.

1. WolframMathWorld. [Polynomial](https://mathworld.wolfram.com/Polynomial.html). Acesso em 10/02/2021.

1. WolframMathWorld. [Quartic Equation](https://mathworld.wolfram.com/QuarticEquation.html). Acesso em 10/02/2021.
