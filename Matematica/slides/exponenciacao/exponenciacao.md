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

*__Exponenciação__*

Prof. Edson Alves
Faculdade UnB Gama

## Exponenciação nos naturais

Sejam $a, n$ dois números naturais. A exponenciação $a^n$ (lê-se "$a$ elevado a $n$") é definida pela relação de recorrência, onde 

- $a^1 = a$, e
- $a^n = a \times a^{n - 1}$,

onde $a$ é denominada **base** e $n$ é denominado **expoente**.

Em termos mais simples, a exponenciação nos naturais é uma multiplicação repetida: basta multiplicar $a$ por ele mesmo $n$ vezes. 

## Propriedades da exponenciação

- Como a multiplicação nos naturais é associativa, vale que
$$
a^{n + m} = a^{n} \times a^{m}
$$

- Também são decorrentes da multiplicação nos naturais as propriedades
$$
(a^{n})^{m} = a^{nm}
$$
e
$$
(ab)^n = a^n \times b^n
$$

## Expoente zero

- Na exponenciação nos naturais é definido que, para qualquer $a$ natural, $a^0 = 1$ 

- De fato, esta definição é consistem com a exponenciação nos inteiros e nos demais conjuntos numéricos, como se verá a seguir

- $0^0$ é uma indeterminação (para qualquer natural $n$, $0^n = 0$)

- A exponenciação nos naturais é ensinada no ensino fundamental e médio, e serve para observar e aprender as propriedades fundamentais da exponenciação

- Porém é útil, na prática, conhecer as definições de exponenciação para outros conjuntos numéricos

## Expoentes inteiros

Sejam $a, n$ dois números inteiros, com $a > 0$. Vale que

- $a^1 = a$, e 
- $a^{n - 1} = a^n / a$

Partindo do caso base, segue que

- $a^0 = a^1 / a = 1$
- $a^{-1} = a^0 / a  = 1 / a$
- $a^{-n} = (a^{-1})^n = 1 / a^n$

## Expoentes inteiros

- As propriedades da exponenciação nos naturais permanecem todas verdadeiras para a exponenciação nos inteiros

- A reescrita da relação de recorrência permite expoentes negativos

- Esta recorrência justifica a notação $a^{-1}$ para o inverso multiplicativo de $a$, uma vez que 
$$
a^{-1} \times a = \left(\frac{1}{a}\right) \times a = 1
$$

## Raízes $n$-ésimas

- Sejam $a, n$ dois números inteiros, com $a > 0$. Qual seria o significado de $a^{1/n}$? 

- Segundo as propriedades já descritas, seria um número $x$ tal que $x^n = a$

- Cada solução desta equação recebe o nome de **raiz $n$-ésima de $a$**

## Exponenciação nos racionais

Sejam $n, m$ números inteiros com $m$ diferente de zero e $a$ um número racional positivo. Então
$$
a^{n/m} = (a^{1/m})^n
$$

## Bases negativas

- A definição de exponenciação nos racionais pode ser estendida para bases negativas, desde que o **radical** (o fator $1/m$ do expoente) seja ímpar

- Isto porque não há soluções para $x^n = 1$ quando $n$ e par

- Por exemplo, $x^3 = -1$ tem solução nos racionais, mas $x^2 = -1$ não

- Bases negativas, em geral, podem violar propriedades da exponenciação 

- Por exemplo, calcule $((-2)^{3/4})^{4/3}$ usando e não usando as propriedades e veja o resultado!

- Tais exemplos justificam a restrição comum de bases positivas

## Exponenciação rápida

- A implementação direta da definição de exponenciação nos naturais leva a uma rotina com complexidade $O(n)$

- Contudo, é possível implementar um algoritmo $O(n\log n)$ para computar $a^n$, por meio da divisão e conquista, denominado **exponenciação rápida**

- Para tal, basta observar que, se $n$ é par, então
$$
    a^n = a^{n/2}\times a^{n/2}
$$

## Exponenciação rápida

- Se $n$ é impar, vale que
$$
    a^n = a\times a^{\lfloor n/2\rfloor}\times a^{\lfloor n/2\rfloor}
$$

```C++
long long fast_exp(long long a, int n)
{
    if (n == 1)
        return a;

    auto x = fast_exp(a, n / 2);

    return x * x * (n % 2 ? a : 1);
}
```

## Problemas

- AtCoder
    - [ABC 097B - Exponential](https://atcoder.jp/contests/abc097/tasks/abc097_b)
- Codeforces
    - [284A - Cows and Primitive Roots](https://codeforces.com/problemset/problem/284/A)
- OJ
    - [107 - The Cat in The Hat](http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=43)
    - [11556 - Best Compression Ever](http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2592)

Referências
-----------

Wikipédia. [Exponentiation](https://en.wikipedia.org/wiki/Exponentiation). Acesso em 22 de agosto de 2017.

Wikipédia. [Exponentiation by squaring](https://en.wikipedia.org/wiki/Exponentiation_by_squaring). Acesso em 04/01/2021.
