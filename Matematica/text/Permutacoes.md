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

Com esta recorrência é possível pré-computar, eficientemente, os valores dos binomiais.
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

A implementação acima tem complexidade O(n*k) para execução e espaço utilizado, para casos onde o limite de espaço é muito restritivo podemos implementar o algoritmo com uso de espaço O(k).

```C++
int binom(int n, int k){

	vector<int> dp(k+1,0);
	dp[0]=1;

	for(int i=1; i<=n; ++i)
		for(int j=min(i,k); j>0; --j)
			dp[j] = dp[j] + dp[j-1];

	return dp[k];
}
```

Uma propriedade dos binomiais, que pode ser utilizada para cortar o tamanho da tabela de
binomiais pela metade, é a sua simetria:

        binom[n][p] = binom[n][n - p]

Assim, basta computar a tabela até o valor _n_/2 e usar a simetria para os demais casos.



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


### Propriedades dos coeficientes binomiais

Os coeficientes binomiais possuem uma série de propriedades interessantes, que podem ser 
úteis na solução de problemas de contagem. Abaixo listamos algumas delas.

1. _C(n, 0) + C(n, 1) + C(n, 2) + ... + C(n, n) = 2^n_ (consequência da expansão do binômio (1 + 1)^_n_))
1. _C(n, 0) - C(n, 1) + C(n, 2) - ... + (-1)^n C(n, n) = 0_ (consequência da expansão do binômio (1 - 1)^_n_))
1. _C(p, p) + C(p, p + 1) + ... + C(p, p + n) = C(p + 1, p + n + 1)_ (consequência da propriedade _C(n + 1, p + 1) = C(n, p + 1) + C(n, p)_)


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
