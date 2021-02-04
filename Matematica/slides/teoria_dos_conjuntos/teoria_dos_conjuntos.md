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

*__Teoria dos Conjuntos__*

Prof. Edson Alves
Faculdade UnB Gama

## Axioma Fundamental

- O principal axioma da Teoria dos Conjuntos, que relaciona os termos primitivos **elemento** e **conjunto** diz que a afirmação "_Um elemento pertence a um conjunto_" é uma proposição

- A simplicidade aparente deste axioma esconde dois importante fatos
    1. a pertinência estabelece a relação entre elementos e conjuntos: dado um elemento qualquer e um conjunto qualquer, este elemento pertence (ou não) ao conjunto
    1. a Teoria dos Conjuntos fica edificada sobre a Lógica, uma vez que o que vale para proposições valerá para este axioma também

## Notação

- Em geral, elementos são representados por letras minúsculas ou símbolos (por exemplo, $a, b, x, \pi, \ldots$)

- Os conjuntos são representados, em geral, por letras maiúsculas, possivelmente cursivas ou estilizadas (por exemplo, $A, B, \mathbb{N}, \mathcal{F}, \ldots$)

- A notação $x\in A$ indica que o elemento $x$ pertence ao conjunto $A$

- Caso $x$ não pertença ao conjunto $A$, a notação é $x\not\in A$

## Subconjuntos

- Um conjunto $B$ é **subconjunto** do conjunto $A$ se, para qualquer elemento $b\in B$, vale que $b\in A$

- A notação para subconjuntos é $B\subset A$, a qual também pode ser lida como "$B$ está contido em $A$"

- Dizer que "o elemento $x$ está contido no conjunto $A$" ou que "o conjunto $A$ pertence ao conjunto $B$" não só é impreciso como é logicamente falso

- A relação de pertinência se dá entre conjuntos e elementos (a relação de subconjunto, associada ao termo "contido", se dá entre conjuntos; elementos se relacionam entre si por relação de igualdade)

## O Conjunto Vazio

- O axioma fundamental permite definir precisamente um conjunto especial, denominado **conjunto vazio**

- $\emptyset$ é o conjunto vazio se, para qualquer elemento $x$, $x\not\in \emptyset$

- Veja que esta definição não é baseada na ideia de cardinalidade (número de elementos de um conjunto)

- Ainda assim, ela permite provar fatos importantes, como o fato de que o conjunto vazio é único ou que qualquer conjunto contém o conjunto vazio

## Caracterização de Conjuntos

Duas possíveis formas de se caracterizar um conjunto são:

1. a enumeração de todos os seus elementos
1. descrição das propriedades comuns a todos os elementos do conjunto

Formalmente, se $P(x)$ é uma sentença aberta em $x$ (isto é, uma sentença tal que, uma vez atribuí um valor específico para a variável $x$, tal sentença se torna uma proposição), então $\{ x\in X\ |\ P(x)$ é verdadeira} é um conjunto, onde $X$ é o conjunto de  todos os possíveis valores de $x$.

## Exemplos de conjuntos

- Conjunto de constantes notáveis
$$
    C = \{ e, \pi, 0, -1 \}
$$

- Conjunto dos números ímpares
$$
    I = \{ 2x + 1 \ |\ x\in \mathbb{Z}\}
$$

- Conjunto dos números primos
$$
    P = \{ p\in \mathbb{N}\ |\ p\ \mathrm{é}\ \mathrm{primo}\}
$$

## Operações em Conjuntos

Dados dois conjuntos $A$ e $B$, é possível definir três novos conjuntos:

1. conjunto **união** $A \cup B = \{x\ |\ x \in A \lor x\in B\}$
1. conjunto **interseção** $A \cap B = \{x \ |\ x \in A \land x \in B\}$
1. conjunto **diferença** $A - B = \{x \in A \ |\ x \not\in B\}$

## Operações em Conjuntos

Observe que as três operações em conjuntos são definidos em termos dos conectivos lógicos fundamentais: 

- disjunção, na união;
- conjunção, na interseção; e
- negação na diferença.

Esta relação permite a verificação das propriedades destes operadores e a relação entre eles (como o equivalente das Leis de Morgan para união e interseção).

## Conjuntos em C e C++

- Há três maneiras de se representar conjuntos em C e C++: as classes `set`, `multiset` e `bitset`, e o tipo primitivo `int`, sendo que a última representação também é válida em C

- A biblioteca padrão do C++ traz a implementação da classe `set` (`#include <set>`), que abstrai a ideia de conjuntos

- Esta classe provê operações elementares (como inserção e remoção de elementos, através dos métodos `insert()` e `erase()`, ou relações de pertinência, com o método `count()`)

## Conjuntos em C e C++

- Na classe `set` os elementos são únicos e armazenados ordenadamente (uma travessia padrão é feita do menor para o maior elemento)

- A classe `multiset` permite a repetição de um mesmo elemento, porém o processo de remoção deve ser feito de forma mais cuidadosa

- As operações de união, interseção e diferença de conjuntos podem ser feitas em qualquer contêiner ordenado, através das funções `set_union()`, `set_intersection()` e `set_difference()`, disponíveis na biblioteca de algoritmos (`#include <algorithm>`)

---

```C++
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> A { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };        // Conjunto A
    vector<int> B { 2, 3, 5, 7, 11, 13 };                   // Conjunto B
    vector<int> C;
    
    set_union(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));

    cout << "union = ";
    for (size_t i = 0; i < C.size(); ++i)
        cout << C[i] << (i + 1 == C.size() ? '\n' : ' ');   // C = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13 }

    C.clear();
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));

    cout << "intersection = ";
    for (size_t i = 0; i < C.size(); ++i)
        cout << C[i] << (i + 1 == C.size() ? '\n' : ' ');   // C = { 2, 3, 5, 7 }

    C.clear();
    set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));

    cout << "difference = ";
    for (size_t i = 0; i < C.size(); ++i)
        cout << C[i] << (i + 1 == C.size() ? '\n' : ' ');   // C = { 1, 4, 6, 8, 9, 10 }

    return 0;
}
```

## Conjuntos e inteiros

- O tipo de dados primitivo `int` (ou sua variante `long long`, com maior capacidade de armazenamento) também pode ser usado para uma interpretação mais compacta e eficiente de conjuntos

- Em geral o tipo `int` tem 32 _bits_ de tamanho

- É possível associar cada elemento do conjunto universo (que contém todos os elementos possíveis, numa quantidade menor ou igual a 32) a cada _bit_, de modo que, se o _bit_ está ligado, o elemento pertence ao conjunto; e se desligado, não pertence

## Conjuntos e inteiros

- A principal restrição desta representação é o número de elementos do conjunto universo (limitado pelo número de _bits_ do tipo escolhido)

- Contudo esta representação tem várias vantagens, dentre elas:

    1. ocupa pouco espaço em memória (4 _bytes_ a cada 32 elementos);
    1. permite responder relações de pertinência em complexidade $O(1)$;
    1. permite operações de união, interseção e diferença também em $O(1)$.


## Conjuntos e inteiros

- A última vantagem listada se dá por conta da definição de tais operações em termos dos conectivos lógicos

- Lembre que as linguagens C e C++ disponibilizarem tais conectivos tanto em relação à variáveis booelanas quanto em versões _bit_ a _bit_

- A seguir o exemplo anterior é reescrito em termos desta nova representação

- No código, considere o conjunto universo $U = \{1, 2, 3, \ldots, 32\}$

--- 

```C++
#include <iostream>

using namespace std;

int main()
{
    int A = 2046;                   // A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
    int B = 10412;                  // B = { 2, 3, 5, 7, 11, 13 }
    int C = A | B;                  // C = 12286

    cout << "union = ";
    for (int x = 0; x < 32; ++x)
        if (C & (1 << x))
            cout << x << " ";
    cout << endl;                   // C = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13 }

    C = A & B;                      // C = 172

    cout << "intersection = ";
    for (int x = 0; x < 32; ++x)
        if (C & (1 << x))
            cout << x << " ";
    cout << endl;                   // C = { 2, 3, 5, 7 }

    C = A & ~B;                     // C = 1874

    cout << "difference = ";
    for (int x = 0; x < 32; ++x)
        if (C & (1 << x))
            cout << x << " ";
    cout << endl;                   // C = { 1, 4, 6, 8, 9, 10 }

    return 0;
}
```

## Classe `bitset`

- Para conjuntos universos com mais de 32 elementos (ou 64, no caso de variáveis `long long`), as alternativas são o uso de um vetor de inteiros, ou da classe `bitset` (`#include <bitset>`)

- Esta classe pode armazenar uma quantidade arbitrária de _bits_ (que deve ser conhecida em tempo de compilação)

- Ela traz em sua interface as operações básicas dos conjuntos e suporte para os operadores lógicos _bit_ a _bit_

---

```C++
#include <bits/stdc++.h>

using namespace std;

int main()
{
    bitset<35> A(2046), B(10412);

    cout << A.to_string() << '\n';
    cout << B.to_string() << '\n';

    auto C = A | B;
    cout << "union = " << C.to_string() << '\n';

    C = A & B;
    cout << "interseção = " << C.to_string() << '\n';

    C = A & ~B;
    cout << "diferença = " << C.to_string() << '\n';

    return 0;
}
```

## Problemas

1. AtCoder
    1. [ABC 128E - Roadwork](https://atcoder.jp/contests/abc128/tasks/abc128_e)
1. Codeforces
    1. [228A - Is your horseshoe on the other hoof?](http://codeforces.com/problemset/problem/228/A)
    1. [236A - Boy or Girl](http://codeforces.com/problemset/problem/236/A)
1. OJ
    1. [501 - Black Box](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=442)
    1. [11849 - CD](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2949)

## Referências

1. CppReference. [std::bitset](https://en.cppreference.com/w/cpp/utility/bitset), acesso em 31/12/2020.

1. CppReference. [std::multiset](https://en.cppreference.com/w/cpp/utility/multiset), acesso em 31/12/2020.

1. CppReference. [std::set](https://en.cppreference.com/w/cpp/utility/set), acesso em 31/12/2020.

1. **HALE**, Margie. _Essentials of Mathematics: Introduction to Theory, Proof, and the Professional Culture_. Mathematical Association of America, 2003.
