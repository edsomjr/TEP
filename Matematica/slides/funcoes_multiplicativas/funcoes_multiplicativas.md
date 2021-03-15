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

- AtCoder
    1. [ABC 114D - 756](https://atcoder.jp/contests/abc114/tasks/abc114_d)
    1. [ABC 170D - Not Divisible](https://atcoder.jp/contests/abc170/tasks/abc170_d)
- Codeforces
    1. [837D - Round Subset](https://codeforces.com/problemset/problem/837/D)
- OJ
    1. [10299 - Relatives](http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1240)
    1. [12043 - Divisors](http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3194)

