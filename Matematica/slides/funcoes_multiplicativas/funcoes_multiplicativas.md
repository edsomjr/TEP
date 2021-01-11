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

*__Funções Multiplicativas__*

Prof. Edson Alves
Faculdade UnB Gama

## Funções Multiplicativas

Uma função é denominada função **aritmética** (ou **número-teórica**) se ela tem como domínio o conjunto dos inteiros positivos e, como contradomínio, qualquer subconjunto dos números complexos.

Uma função $f$ aritmética é denominada função **multiplicativa** se

1. $f(1) = 1$
1. $f(mn) = f(m)f(n)$ se $(m, n) = 1$

## Número de Divisores

Seja $n$ um inteiro positivo. A função $\tau(n)$ retorna o número de divisores positivos de $n$.

## Cálculo de $\tau(n)$

- Segue diretamente da definição que $\tau(1) = 1$

- Se $n = p^k$, para algum primo $p$ e um inteiro positivo $k$, $d$ será um divisor de $n$ se, e somente se, $d = p^i$, com $i\in [0, k]$

- Assim, $\tau(p^k) = k + 1$

- Se $(a, b) = 1$ e $p$ é um primo que divide $ab$, então ou $p$ divide $a$ ou $p$ divide $b$

## Cálculo de $\tau(n)$

- Se $d$ divide $ab$, então ele pode ser escrito como $d = mn$, com $(m, n) = 1$

- Logo, $\tau(ab) = \tau(a)\tau(b)$, ou seja, $\tau(n)$ é uma função multiplicativa

- Considere a fatoração
$$
    n = p_1^{\alpha_1}p_2^{\alpha_2}\ldots p_k^{\alpha_k}
$$

- Portanto,
$$
    \tau(n) = \prod_{i = 1}^k (\alpha_i + 1) = (\alpha_1 + 1)(\alpha_2 + 1)\ldots (\alpha_k + 1)
$$

## Implementação de $\tau(n)$ em C++
```C++
long long number_of_divisors(int n, const vector<int>& primes)
{
    auto fs = factorization(n, primes);
    long long res = 1;

    for (auto [p, k] : fs)
        res *= (k + 1);

    return res;
}
```

## Cálculo de $\tau(n)$ em competições

- Em competições, é possível computar $\tau(n)$ em $O(\sqrt{n})$ diretamente, sem recorrer à fatoração de $n$

- Isto porque, se $d$ divide $n$, então $n = dk$ e ou $d\leq \sqrt{n}$ ou $k \leq \sqrt{k}$

- Assim só é necessário procurar por divisores de $n$ até $\sqrt{n}$

- Caso um divisor $d$ seja encontrado, é preciso considerar também $k = n/d$

- Esta abordagem tem implementação mais simples e direta, sendo mais adequada em um contexto de competição

## Implementação $O(\sqrt{n})$ de $\tau(n)$
```C++
long long number_of_divisors(long long n)
{
    long long res = 0;

    for (long long i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
            res += (i == n/i ? 1 : 2);
    }

    return res;
}
```
## Soma dos Divisores

Seja $n$ um inteiro positivo. A função $\sigma(n)$ retorna a soma dos divisores positivos de $n$.

## Caracterização dos divisores de $n = ab$

- Sejam $a$ e $b$ dois inteiros positivos tais que $(a, b) = 1$ e $n = ab$

- Se $c$ e $d$ são divisores positivos de $a$ e $b$, respectivamente, então $cd$ divide $n$

- Por outro lado, se $k$ divide $n$ e $d = (k, a)$, então
$$
    k = d\left(\frac{k}{d}\right)
$$


## Caracterização dos divisores de $n = ab$

- Como $d = (k, a)$, em particular $d$ divide $a$

- Uma vez que $(k/d, a) = 1$ e $k$ divide $n = ab$, então $k/d$ divide $b$

- Isso mostra que qualquer divisor $c = d_ie_j$ de $n$ será o produto de um divisor $d_i$ de $a$ por um divisor $e_j$ de $b$

## Cálculo de $\sigma(n)$

- Da caracterização anterior segue que
$$
    \sigma(n) = \sum_{i = 1}^r \sum_{j = 1}^s d_ie_j
$$
- Daí,
$$
    \sigma(n) = d_1e_1 + \ldots + d_1e_s + d_2e_1 + \ldots + d_2e_s + \ldots + d_re_1 + \ldots + d_re_s
$$

## Cálculo de $\sigma(n)$

- Esta expressão pode ser reescrita como
$$
    \sigma(n) = (d_1 + d_2 + \ldots + d_r)(e_1 + e_2 + \ldots + e_s)
$$

- Portanto
$$
    \sigma(n) = \sigma(ab) = \sigma(a)\sigma(b)
$$

- Como $\sigma(1) = 1$, a função $\sigma(n)$ é multiplicativa

## Cálculo de $\sigma(n)$

- Deste modo, para se computar $\sigma(n)$ basta saber o valor de $\sigma(p^k)$ para um primo $k$ e um inteiro positivo $k$

- O divisores de $p^k$ são as potências $p^i$, para $i\in [0, k]$

- Logo
$$
    \sigma(p^k) = 1 + p + p^2 + \ldots + p^k = \left(\frac{p^{k + 1} - 1}{p - 1}\right)
$$

## Implementação de $\sigma(n)$ em C++
```C++
long long sum_of_divisors(int n, const vector<int>& primes)
{
    auto fs = factorization(n, primes);
    long long res = 1;

    for (auto [p, k] : fs)
    {
        long long temp = p;

        while (k--)
            temp *= p;

        res *= (temp - 1)/(p - 1);
    }

    return res;
}
```

## Cálculo de $\sigma(n)$ em competições

- De forma semelhante à função $\tau(n)$, é possível computar $\sigma(n)$ sem necessariamente fatorar $n$

- A estratégia é a mesma: listar os divisores de $n$, por meio de uma busca completa até $\sqrt{n}$, e totalizar os divisores encontrados

- Esta rotina tem complexidade $O(\sqrt{n})$

## Cálculo de $\sigma(n)$ sem fatorar $n$

```C++
long long number_of_divisors(long long n)
{
    long long res = 0;

    for (long long i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int j = n / i;

            res += (i == j ? i : i + j);
        }
    }

    return res;
}
```

## Função $\varphi$ de Euler

A função $\varphi(n)$ de Euler retorna o número de inteiros positivos menores ou iguais a $n$ que são coprimos com $n$.

## Cálculo de $\varphi(n)$

- É fácil ver que $\varphi(1) = 1$ e que $\varphi(p) = p - 1$, se $p$ é primo

- A prova que $\varphi(mn) = \varphi(m)\varphi(n)$ se $(a, b) = 1$ não é trivial (uma prova possível utiliza os conceitos de sistemas reduzidos de resíduos)

- Assim, $\varphi(n)$ é uma função multiplicativa

- Para $p$ primo e $k$ inteiro positivo, no intervalo $[1, p^k]$ apenas os múltiplos de $p$ não são coprimos como $p$

## Cálculo de $\varphi(n)$

- Os múltiplos de $p$ são
$$
    p, 2p, 3p, \ldots, p^k
$$

- Observe que $p^k = p\times p^{k - 1}$

- Assim são $p^{k - 1}$ múltiplos de $p$ em $[1, p^k]$ e portanto
$$
    \varphi(p^k) = p^k - p^{k - 1} = p^{k - 1}(p - 1)
$$

## Cálculo de $\varphi(n)$

- Seja $n$ um inteiro positivo tal que
$$
    n = p_1^{\alpha_1}p_2^{\alpha_2}\ldots p_k^{\alpha_k}
$$

- O valor de $\varphi(n)$ será dado por
$$
    \varphi(n) = \prod_{i = 1}^k p_i^{\alpha_i - 1}\left(p_i - 1\right) = n \prod_{i = 1}^k \left(1 - \frac{1}{p_i}\right)
$$

## Implementação de $\varphi(n)$ em C++
```C++
int phi(int n, const vector<int>& primes)
{
    if (n == 1)
        return 1;

    auto fs = factorization(n, primes);
    auto res = n;

    for (auto [p, k] : fs)
    {
        res /= p;
        res *= (p - 1);
    }

    return res;
}
```

## Cálculo de $\varphi$ em $[1, n]$

- É possível computar $\varphi(k)$ para todos inteiros $k$ no intervalo $[1, n]$ em $O(n\log n)$

- Para tal, basta utilizar uma versão modificada do crivo de Erastótenes

- Inicialmente, `phi[k] = k`

- Para todos os primos $p$, os múltiplos $i$ de $p$ devem ser atualizados de duas formas:
    1. `phi[i] /= p`
    1. `phi[i] *= (p - 1)`

---
```C++
vector<int> range_phi(long long n)
{
    bitset<MAX> sieve;                      // MAX deve ser maior do que n
    vector<int> phi(n + 1);

    iota(phi.begin(), phi.end(), 0);
    sieve.set();

    for (long long p = 2; p <= n; p += 2)
        phi[p] /= 2;

    for (long long p = 3; p <= n; p += 2) {
        if (sieve[p]) {
            for (long long j = p; j <= n; j += p) {
                sieve[j] = false;
                phi[j] /= p;
                phi[j] *= (p - 1);
            }
        }
    }

    return phi;
}
```

## Problemas


## Referências

1. Mathematics LibreTexts. [4.2 Multiplicativa Number Theoretic Functions](https://math.libretexts.org/Bookshelves/Combinatorics_and_Discrete_Mathematics/Book%3A_Elementary_Number_Theory_(Raji)/04%3A_Multiplicative_Number_Theoretic_Functions/4.02%3A_Multiplicative_Number_Theoretic_Functions#:~:text=The%20number%20of%20divisors%20function%20%CF%84(n)%20is%20multiplicative.,pa22...). Acesso em 10/01/2021.

1. Wikipédia. [Arithmetic function](https://en.wikipedia.org/wiki/Arithmetic_function). Acesso em 10/01/2021.

1. Wikipédia. [Multiplicative function](https://en.wikipedia.org/wiki/Multiplicative_function). Acesso em 10/01/2021.
