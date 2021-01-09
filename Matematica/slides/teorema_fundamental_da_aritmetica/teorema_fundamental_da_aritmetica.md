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

*__Teorema Fundamental da Aritmética__*

Prof. Edson Alves
Faculdade UnB Gama

## Teorema Fundamental da Aritmética

- O Teorema Fundamental da Aritmética apresenta a relação fundamental dos números primos com todos os números naturais

- Ele afirma que todo $n > 1$ natural ou é primo ou é escrito de forma única (a menos de ordem) como o produto de primos

- Seja $n > 1$, $p_i$ o $i$-ésimo número primo e $\alpha_i \geq 0$, para todo $i\in [1, k]$. Então
$$
    n = p_1^{\alpha_1}p_2^{\alpha_2}\ldots p_k^{\alpha_k}
$$

## Fatoração de inteiros

- O conhecimento da fatoração (decomposição) de um natural $n$ como produto de primos permite o cálculo de várias funções importantes, como MDC, MMC, número de divisores, soma dos divisões, função $\varphi$ de  Euler, etc

- A fatoração serve como alternativa para a representação do número, principalmente quando o número é muito grande (maior do que a capacidade de um `long long`, por exemplo)

- A fatoração pode ser implementada em $O(\pi(\sqrt{n})\log n)$, se forem conhecidos os primos 

---

```C++
map<int, int> factorization(int n, const vector<int>& primes)
{
    map<int, int> fs;

    for (auto p : primes)
    {
        if (p * p > n)
            break;

        int k = 0;

        while (n % p == 0)
        {
            n /= p;
            ++k;
        }
        
        if (k)
            fs[p] = k;
    }

    if (n > 1)
        fs[n] = 1;

    return fs;
}
```

## Fatoração de Fatoriais

- Uma aplicação importante da fatoração é a fatoração de fatoriais

- Os fatoriais crescem rapidamente, e mesmo para valores relativamente pequenos de $n$, o número $n!$ pode ser computacionalmente intratável

- A fatoração de $n!$ permite trabalhar com tais números e realizar algumas operações com os mesmos (multiplicação, divisão, MMC e MDC, etc)

- A função $E(n,p)$ retorna um inteiro $k$ tal que $p^k$ é a maior potência do primo $p$ que divide $n!$

## Exemplo de cálculo de $E(n, p)$

Para ilustrar o cálculo de $E(n,p)$ considere $n = 12$ e $p = 2$. A expansão de $12!$ é 
```
        1 x 2 x 3 x 4 x 5 x 6 x 7 x 8 x 9 x 10 x 11 x 12
```

É fácil observar que todos os múltiplos de $2$ contribuem com um fator $2$. Cancelando estes fatores obtém-se
```
        1 x 1 x 3 x 2 x 5 x 3 x 7 x 4 x 9 x 5 x 11 x 6
```

## Exemplo de cálculo de $E(n, p)$

Ainda restam ainda fatores $2$ no produto, onde haviam originalmente os números $4, 8$ e $12$. Isto acontece por, além de serem múltiplos de $2$, os números $4, 8$ e $12$ também são múltiplos de $2^2$. 

Eliminando os fatores $2$ associados a $2^2$ resulta em
```
        1 x 1 x 3 x 1 x 5 x 3 x 7 x 2 x 9 x 5 x 11 x 3
```

## Exemplo de cálculo de $E(n, p)$

Mais $3$ fatores foram eliminados, e sobrou ainda um fator, onde estava o $8$. Isto acontece também porque 8 é múltiplo de $2^3$. Eliminando este último fator, eliminamos um total de $6 + 3 + 1 = 10$.  Portanto $E(12,2) = 9$.

O exemplo acima fornece a expressão para o cálculo de $E(n,p)$, onde $p^r \leq n$:
$$
E(n, p) = \left\lfloor \frac{n}{p}\right\rfloor + \left\lfloor \frac{n}{p^2}\right\rfloor + \ldots + \left\lfloor \frac{n}{p^r}\right\rfloor,
$$
onde $\left\lfloor \frac{a}{b}\right\rfloor$ é a divisão inteira de $a$ por $b$.

## Implementação de $E(n, p)$ em $O(\log n)$

```C++
int E(int n, int p)
{
    int res = 0, base = p;

    while (base <= n)
    {
        res += n / base;
        base *= p;
    }

    return res;
}
```

## Fatoração de $n!$ em $O(\pi(n)\log n)$

```C++
map<int, int> factorial_factorization(int n, const vector<int>& primes)
{
    map<int, int> fs;

    for (const auto& p : primes)
    {
        if (p > n)
            break;

        fs[p] = E(n, p);
    }

    return fs;
}
```

## MDC, MMC e fatoração

Seja $a = p_1^{\alpha_1}p_2^{\alpha_2}\ldots p_k^{\alpha_k}$ e $b = p_1^{\beta_1}p_2^{\beta_2}\ldots p_k^{\beta_k}$, com $\alpha_i, \beta_j \geq 0$ para todos $i, j\in [1,k]$. Então
$$
    (a, b) = p_1^{\min\{\alpha_1, \beta_1\}}p_2^{\min\{\alpha_2, \beta_2\}}\ldots p_k^{\min\{\alpha_k, \beta_k\}}
$$
e
$$
    [a, b] = p_1^{\max\{\alpha_1, \beta_1\}}p_2^{\max\{\alpha_2, \beta_2\}}\ldots p_k^{\max\{\alpha_k, \beta_k\}}
$$

## Implementação do MDC
```C++
int gcd(int a, int b, const vector<int>& primes)
{
    auto ps = factorization(a, primes);
    auto qs = factorization(b, primes);

    int res = 1;

    for (auto p : ps) {
        int k = min(ps.count(p) ? ps[p] : 0, qs.count(p) ? qs[p] : 0);

        while (k--)
            res *= p;
    }

    return res;
}
```

## Implementação do MMC

```C++
int lcm(int a, int b, const vector<int>& primes)
{
    auto ps = factorization(a, primes);
    auto qs = factorization(b, primes);

    int res = 1;

    for (auto p : ps) {
        int k = max(ps.count(p) ? ps[p] : 0, qs.count(p) ? qs[p] : 0);

        while (k--)
            res *= p;
    }

    return res;
}
```

Número de Divisores
-------------------

A fatoração de um número _n_ também permite computar o número de divisores deste número: basta
fazer o produto de todos os expoentes da fatoração, somados cada um de uma unidade. Veja 
o código abaixo.
```C++
long long number_of_divisors(int n, const vector<int>& primes)
{
    auto fs = factorization(n, primes);
    long long res = 1;

    for (const auto& f : fs)
    {
        int k = f.second;

        res *= (k + 1);
    }

    return res;
}
```
Intuitivamente, imagine que temos uma fatoração prima de um número por exemplo fat(30) = 2^2*5. Qualquer múltiplo desse número teria os mesmos fatores com expoentes diferentes, assim os múltiplos de 30 seriam [2^0, 2^1, 2^2, 2^0x5, 2^1x5, 2^2x5] usando essa intuição podemos resolver o problema por combinatória, cada expoente pode aparece n vezes além de não aparecer na fatoração, ou seja, n+1 vezes. Utilizando o [principio multiplicativo](https://github.com/edsomjr/TEP/blob/master/Matematica/text/Permutacoes.md#princípio-multiplicativo) chegamos ao resultado: (exp1+1)x(exp2+1)x(exp3+1)x...x(exp_n+1).

Uma variante deste código, semelhante ao código da fatoração, é dado abaixo:
```C++
long long number_of_divisors(int n)
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
A primeira versão tem complexidade _O(sqrt(pi(n)))_, se a lista de primos já tiver sido 
pré-computada. A segunda versão tem complexidade _O(sqrt(n))_, mas leva vantagem pela simplicidade
e pelo fato de não exigir uma lista de primos.

Soma dos Divisores
------------------

Um problema semelhantes ao anterior é determinar a soma de todos os divisores de _n_. Há dois
algoritmos possíveis, variantes dos dois anteriores. O primeiro deles é baseado na fatoração,
e é apresentado a seguir.
```C++
long long sum_of_divisors(int n, const vector<int>& primes)
{
    auto fs = factorization(n, primes);
    long long res = 1;

    for (const auto& f : fs)
    {
        int p = f.first;
        int k = f.second + 1;

        long long temp = 1;

        while (k--)
            temp *= p;

        res *= (temp - 1)/(p - 1);
    }

    return res;
}
```

Veja que, para cada fator _p^k_ da fatoração de _n_, o número de divisores é multiplicado
por um fator _(p^{k + 1} - )/(p - 1)_. A segunda versão dispensa o número de primos:
```C++
long long number_of_divisors(int n)
{
    long long res = 0;

    for (long long i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int j = n / i;

            res += (i == j ? i : i + j);
    }

    return res;
}
```

Função Phi de Euler
-------------------

A função Phi de Euler (`phi(n)`) retorna o número de inteiros positivos menores ou iguais a _n_ 
que são coprimos com _n_. É fácil ver que `phi(1) = 1` e que `phi(p) = p - 1`, se `p` é primo.
Menos óbvio são os fatos de que `phi(mn) = phi(m)phi(n)`, se (_m, n_) = 1 e que `phi(p^k) = 
p^{k - 1}(p - 1)`. Este dois últimos fatos nos permitem computar o valor de `phi(n)` a partir
 da fatoração de _n_.
```C++
int phi(int n, const vector<int>& primes)
{
    if (n == 1)
        return 1;

    auto fs = factorization(n, primes);

    int res = n;

    for (const auto& f : fs)
    {
        int p = f.first;

        res /= p;
        res *= (p - 1);
    }

    return res;
}
```
Se for preciso computar `phi(n)` para um intervalo de valores, o melhor a se fazer é usar 
uma variante do crivo de Erastótenes, e a manipulação feita no código acima.
```C++
bitset<MAX> sieve;
int phi[MAX];

void precomp()
{
    for (int i = 1; i < MAX; ++i)
        phi[i] = i;

    sieve.set();

    for (int p = 2; p < MAX; p += 2)
        phi[p] /= 2;

    for (long long p = 3; p < MAX; p += 2)
    {
        if (sieve[p])
        {
            for (long long j = p; j < MAX; j += p)
            {
                sieve[j] = false;
                phi[j] /= p;
                phi[j] *= (p - 1);
            }
        }
    }
}
```

Referências
-----------

PRIMES.UTM.EDU. [How Many Primes Are There?](https://primes.utm.edu/howmany.html). Acesso eme 08/11/2017.

WIKIPEDIA. [Harmonic Number](https://en.wikipedia.org/wiki/Harmonic_number). Acesso em 08/11/2017.

WIKIPEDIA. [Mertens' theorems](https://en.wikipedia.org/wiki/Mertens%27_theorems). Acesso eme 08/11/2017.
