Permutações, Arranjos e Combinações 
===================================

Princípio Multiplicativo
------------------------

O **Princípio Multiplicativo** está relacionado ao número de elementos do produto cartesiano de
dois conjuntos. Se A e B são dois conjuntos finitos não vazios, com |A| = _n_, 
|B| = _m_, então  o produto cartesiano AxB terá _nm_ elementos.

Este princípio é útil em contagem de _n_-uplas de elementos, onde cada elemento da _n_-upla vem
de um conjunto distinto, ou de um conjunto já utilizado, subtraído do elemento já utilizado. 
Deste princípio derivam os conceitos de permutação, arranjo e combinação apresentados a seguir.

Permutações
-----------

Seja A um conjunto com _n_ elementos distintos. Uma **permutação** destes elementos é consiste em 
um ordenação destes elementos tal que duas permutações são distintas se dois ou mais elementos 
ocuparem posições distintas. Por exemplo, se A = {1, 2, 3}, há 6 permutações distintas, a saber:
123, 132, 213, 231, 312, 321.

Notamos _P(n)_ o total de permutações distintas de _n_ elementos. Para a primeira posição temos
_n_ escolhas; para a segunda, temos (_n_ - 1) escolhas, uma vez que não podemos repetir o 
primeiro elemento escolhido. Pelo mesmo motivo, há (_n_ - 2) escolhas para o terceiro elemento,
e assim sucessivamente, até termos uma única escolha para o último elemento. Portanto,

        P(n) = n x (n - 1) x (n - 2) x ... x 2 x 1
        P(n) = n!

Para enumerar todas as possíveis permutações de _n_ elementos, podemos utilizar o _backtracking_
ou a função `next_permutation()` da biblioteca `algorithm` do C++. Ela retorna verdadeiro se é
possível gerar a próxima permutação, na ordem lexicográfica, a partir da permutação atual, e 
falso, caso contrário. Neste sentido, devemos começar com a primeira permutação na ordem 
lexicográfica, que consiste em todos os elementos ordenados. Veja o exemplo abaixo.
```C++
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    vector<int> A { 5, 3, 4, 1, 2 };

    sort(A.begin(), A.end());           // Primeira permutação na ordem lexicográfica

    int count = 0;

    do {
        for (size_t i = 0; i < A.size(); ++i)
            printf("%d%c", A[i], " \n"[i + 1 == A.size()]);
    
        ++count;
    } while (next_permutation(A.begin(), A.end()));

    printf("P(%lu) = %d\n", A.size(), count);

    return 0;
}
```

Listar todas as permutações tem ordem de complexidade O((_n_ + 1)!), de modo que só é útil para
valores pequenos de _n_ (por exemplo, _n_ = 8 ou menor). Em problemas que envolvam permutação
sujeitas a uma série de restrições, contudo, podemos listar todas as filtrá-las individualmente,
caso o valor de _n_ permitir tal listagem dentro do tempo limite estabelecido.

Arranjos
--------

Seja A um conjunto com _n_ elementos distintos e _p_ um inteiro não negativo tal que _p <= n_. 
Um **arranjo** deste _n_ elementos, tomados _p_ a _p_, consiste em uma escolha de _p_ elementos
distintos dentre os _n_ possíveis, onde cada arranjo difere dos demais tanto pela qualidade
quanto pela posição dos elementos. Por exemplo, se A = {1, 2, 3, 4} e _p_ = 2, há 12 arranjos
 distintos, a saber: 12, 13, 14, 21, 23, 24, 31, 32, 34, 41, 42, 43.

Usamos a notação _A(n,p)_ para denotar o total de arranjos possíveis de _n_ elementos tomados
_p_ a _p_. Usando a mesma ideia utilizadas nas permutações, temos que

        A(n, p) = n x (n - 1) x (n - 2) x ... x (n - (p - 1))

A lista acima tem _p_ fatores multiplicativos, e se assemelha a um fatorial. Se completarmos o
fatorial, e dividirmos pelo elementos inseridos, obtemos

        A(n, p) = n x (n - 1) x (n - 2) x ... x (n - (p - 1)) x [(n - p) x ... x 2 x 1]/[(n - p) x ... x 2 x 1]
        A(n, p) = n!/(n - p)!

O cálculo do total de arranjos assemelha-se, portanto, ao cálculo de um fatorial. 
```C++
long long A(long long n, long long p)
{
    if (n < p)
        return 0;

    long long res = 1;

    for (long long i = n; i > p; --i)
        res *= i;

    return res;
}
```

É preciso tomar cuidado, porém, com o fato de que, assim como as permutações, o total de arranjos
cresce rapidamente, e pode resultar em um _overflow_. Nestes casos, é preciso trabalhar com
aritmética modular ou usar aritmética estendida, conforme for o caso de cada problema.

Combinações
-----------

Seja A um conjunto com _n_ elementos distintos e _p_ um inteiro não negativo tal que _p <= n_. 
Uma **combinação** deste _n_ elementos, tomados _p_ a _p_, consiste em uma escolha de _p_ elementos
distintos dentre os _n_ possíveis, onde cada combinação difere das demais pela qualidade dos
elementos, mas não pela ordem.  Por exemplo, se A = {1, 2, 3, 4} e _p_ = 2, há 6 combinações
distintas, a saber: 12, 13, 14, 23, 24, 34.

Usamos a notação _C(n, p)_ para denotar o total de combinações possíveis de _n_ elementos
tomados _p_ a _p_. Convencionamos _C(n, p)_ = 0 quando _p > n_. Nos demais casos, podemos
computar _C(n,p)_ a partir de _A(n,p)_: basta contar como apenas um todos os arranjos que diferem
apenas pela ordem de seus elementos. Como _p_ elementos distintos geram _p!_ arranjos distintos,
temos que

        C(n, p) = [A(n, p)]/p! = n!/[(n - p)!p!] = binom(n, p)

onde `binom(n, p)` representa o número binomial.

Na prática, pode ser que o valor de `binom(n, p)` possa ser armazenado em uma
variável inteira, mas os fatoriais envolvidos no numerador e no denominador podem dar _overflow_
nos cálculos intermediários, comprometendo o resultado final. Há duas maneiras de contornar 
este problema: por cancelamento ou por recorrência.

A ideia do cancelamento é que, embora seja representado na forma de fração, `binom(n, p)` é 
sempre um número inteiro. Assim, podemos fazer os cancelamentos devidos antes de multiplicar os
fatores restantes. Veja o código abaixo.
```C++
long long gcd(long long a, long long b)     // Maior divisor comum de a e b
{
    return a ? gcd(b, a % b) : b;
}

long long binom(long long n, long long p)
{
    if (n < p)
        return 0;

    auto m = min(p, n - p);
    auto M = min(p, n - p);

    vector<long long> num;

    for (long long i = n; i > M; ++i)       // Cancelamos pelo maior valor possível
        num.push_back(i);

    vector<long long> den;                  

    for (long long i = 2; i <= m; ++i)       // Fica o denominador o menor valor possível
        den.push_back(i);

    for (auto y : den)
    {
        for (int i = num.size() - 1; i >= 0; --i)
        {
            auto d = gcd(y, num[i]);
            
            y /= d;                         
            num[i] /= d;                    // Cancelamento possível
            
            if (y == 1)
                break;
        }

        while (not num.empty() and num.back() == 1)
            num.pop_back();                             // Remova os 1's que não contribuem para a resposta 
    }

    long long res = 1;

    for (auto x : num)
        res *= x;

    return res;
}
```

Outra maneira é utilizar a recorrência dos binomiais, derivadas do triângulo de Pascal, dada a 
seguir:

        binom(n, 0) = binom(n, n) = 1       // Caso base
        binom(n, m) = binom(n - 1, m) + binom(n - 1, m - 1)

Com esta recorrência é possível pre-computar, eficientemente, os valores dos binomiais.
```C++
#define MAX 201

long long binom[MAX][MAX];

void precomp()
{
    for (int i = 0; i < MAX; ++i)
    {
        binom[i][0] = binom[i][i] = 1;

        for (int j = 1; j < i; ++j)
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
    }
} 
```

Uma propriedade dos binomiais, que pode ser utilizada para cortar o tamanho da tabela de
binomiais pela metade, é a sua simetria:

        binom[n][p] = binom[n][n - p]

Assim, basta computar a tabela até o valor _n_/2 e usar a simetria para os demais casos.

<!--- Adicionar: Equações lineares com coeficientes unitários, combinações com repetição,
permutação com repetição, arranjo com repetição, permutações circulares, coeficientes binomiais -->

