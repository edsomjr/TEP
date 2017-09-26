Permutações, Combinações e Arranjos
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
long long A(ll n, ll p)
{
    if (n < p)
        return 0;

    long long res = 1;

    for (ll i = n; i > p; --i)
        res *= i;

    return res;
}
```

É preciso tomar cuidado, porém, com o fato de que, assim como as permutações, o total de arranjos
cresce rapidamente, e pode resultar em um _overflow_. Nestes casos, é preciso trabalhar com
aritmética modular ou usar aritmética estendida, conforme for o caso de cada problema.

