Teoria dos Conjuntos
====================

Conceitos Fundamentais
----------------------

O principal axioma da Teoria dos Conjuntos, que relaciona os termos primitivos **elemento** e
**conjunto** diz que a afirmação "Um elemento pertence a um conjunto" é uma proposição. A 
simplicidade aparente deste axioma esconde dois importante fatos: ao considerar como proposição
a afirmação dada, decorre que 

1. a pertinência estabelece a relação entre elementos e conjuntos: dado um elemento qualquer e
um conjunto qualquer, este elemento pertence (ou não) ao conjunto;
1. a Teoria dos Conjuntos fica edificada sobre a Lógica, uma vez que o que vale para proposições
valerá para este axioma também.

Em geral, elementos são representados por letras minúsculas e conjuntos por letras maiúsculas.
Dizer que "um elemento está contido no conjunto A" ou que "o conjunto A pertence ao conjunto B"
não só é impreciso como é logicamente falso: a relação de pertinência se dá entre conjuntos e
elementos (a relação de subconjunto, associada ao termo "contido", se dá entre conjuntos; 
elementos se relacionam entre si por relação de igualdade).

Este axioma permite também definir precisamente um conjunto especial, denominado **conjunto
vazio**: &#8709; é um conjunto vazio se, para qualquer elemento _a_, _a_ não pertence a 
&#8709;. Veja que esta definição não é baseada na ideia de cardinalidade (número de elementos
de um conjunto), a qual nem mesmo foi definida ainda, e ainda permite provar fatos importantes,
como o que o conjunto vazio é único e que todo conjunto contém o conjunto vazio.

Caracterização de Conjuntos
---------------------------

Uma vez definida a relação entre conjuntos e elementos, torna-se fundamental definir como um
conjunto pode ser descrito. A Teoria do Conjunto nos fornece duas formas:

1. a enumeração de todos os seus elementos;
1. descrição das propriedades comuns a todos os elementos do conjunto. Mais formalmente, se
_P(x)_ é uma sentença aberta em _x_ (isto é, uma sentença tal que, uma vez atribuí um valor
específico para a variável _x_, tal sentença se torna uma proposição), então 
{_x_ &#8712; X \| _P(x)_ é verdadeira} é um conjunto, onde _X_ é o conjunto de  todos os possíveis
valores de _x_.

Usando as duas formas acima, podemos descrever o conjunto _A_ dos números pares positivos menores 
ou iguais a 10 como

1. A = {2, 4, 6, 8, 10}, ou
1. A = {_x_ &#8712; N \| 2 &#8804; _x_ &#8804; 10}

Operações em Conjuntos
----------------------

Dados dois conjuntos A e B, é possível definir três novos conjuntos:

1. conjunto **união** A &#8746; B = {_x_ \| _x_ &#8712; A ou _x_ &#8712; B}
1. conjunto **interseção** A &#8745; B = {_x_ \| _x_ &#8712; A e _x_ &#8712; B}
1. conjunto **diferença** A \ B = {_x_ &#8712; A \| _x_ &#8713; B}

Observe que os três operadores acima são definidos em termos dos conectivos lógicos fundamentais: 

* disjunção, na união;
* conjunção, na interseção; e
* negação na diferença.

Esta relação permite a verificação das propriedades destes operadores e a relação entre eles
(como o equivalente das Leis de Morgan para união e interseção).

C e C++
-------

Há três maneiras de se representar conjuntos em C++: as classes `set` e `bitset`, e o tipo primitivo
`int`, sendo que a última também é válida em C.


A biblioteca padrão do C++ traz a implementação da classe `set` (`#include <set>`), que abstrai
a ideia de conjuntos, e provê operações elementares (como inserção e remoção de elementos, 
através dos métodos `insert()` e `erase()`, ou relações de pertinência, com o método 
`count()`). Nesta classe os elementos são únicos, e armazenados ordenadamente (uma travessia
padrão é feita do menor para o maior elemento). Contudo, as operações de união, interseção e
diferença de conjuntos são feitas em qualquer contêiner ordenado, através das funções
`set_union(), set_intersection()` e `set_difference()`, disponíveis na biblioteca de
algoritmos (`#include <algorithm>`) e exemplificadas abaixo.
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> A { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };    // Conjunto A
    vector<int> B { 2, 3, 5, 7, 11, 13 };               // Conjunto A

    vector<int> C;
    
    set_union(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));

    cout << "union = ";
    for (auto x : C)
        cout << x << " ";
    cout << endl;                 // C = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13 }

    C.clear();
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));

    cout << "intersection = ";
    for (auto x : C)
        cout << x << " ";
    cout << endl;                 // C = { 2, 3, 5, 7 }

    C.clear();
    set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));

    cout << "difference = ";
    for (auto x : C)
        cout << x << " ";
    cout << endl;                 // C = { 1, 4, 6, 8, 9, 10 }

    return 0;
}
```

O tipo de dados primitivo `int` (ou sua variante `long long`, com maior capacidade de 
armazenamento) também pode ser usado para uma interpretação mais compacta e eficiente de
conjuntos. Em geral o tipo `int` tem 32 _bits_ de tamanho, e podemos cada elemento do conjunto
universo (que contém todos os elementos possíveis, numa quantidade menor ou igual a 32) 
com cada _bit_, de modo que, se o bit está 
ligado, o elemento pertence ao conjunto; e se desligado, não pertence. 

Fora a restrição em relação ao número de elementos do conjunto universo, esta representação tem
várias vantagens:

* ocupa pouco espaço em memória (4 _bytes_ a cada 32 elementos);
* permite responder relações de pertinência em complexidade O(1);
* permite operações de união, interseção e diferença também em O(1).

A última característica se dá por conta da definição de tais operações em termos dos conectivos
lógicos, e pelo fato das linguagens C e C++ disponibilizarem tais operações _bit_ a _bit_.
Veja o exemplo anterior reescrito em termos desta nova representação. Considere que o 
conjunto universo U = {1, 2, 3, ..., 32}.
```C++
#include <iostream>

using namespace std;

int main()
{
    int A = 2046;       // A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, bits correspondentes ligados
    int B = 10412;      // B = { 2, 3, 5, 7, 11, 13 }, mesmo motivo

    int C = A | B;      // C = 12286

    cout << "union = ";
    for (int x = 1; x <= 16; ++x)
        if (C & (1 << x))
            cout << x << " ";
    cout << endl;                 // C = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13 }

    C = A & B;          // C = 172

    cout << "intersection = ";
    for (int x = 1; x <= 16; ++x)
        if (C & (1 << x))
            cout << x << " ";
    cout << endl;                 // C = { 2, 3, 5, 7 }

    C = A & ~B;       // C = 1874

    cout << "difference = ";
    for (int x = 1; x <= 16; ++x)
        if (C & (1 << x))
            cout << x << " ";
    cout << endl;                 // C = { 1, 4, 6, 8, 9, 10 }

    return 0;
}
```

Para conjuntos universos com mais de 32 elementos (ou 64, no caso de variáveis `long long`), ou
se usa um vetor de inteiros, ou a classe `bitset` (`#include <bitset>`), que pode armazenar 
uma quantidade arbitrária de _bits_ (que deve ser conhecida em tempo de compilação) e que 
traz em sua interface as operações básicas dos conjuntos e suporte para os operadores lógicos
_bit_ a _bit_.

A linguagem C++ também oferece, em sua biblioteca padrão, a classe `multiset` 
(`#include <multiset>`), que permite o armazenamento de elementos repetidos (embora seja uma
extrapolação da ideia básica de um conjunto, tal representação pode ser útil em alguns
contextos).

Exercícios
----------

<!-- 228A - elementar, elementos únicos -->
<!-- 236A - int, set, elementos únicos -->
<!-- 501 - multiset -->
<!-- 11849 - classe set ou bitset -->

1. Codeforces
    1. [228A - Is your horseshoe on the other hoof?](http://codeforces.com/problemset/problem/228/A)
    1. [236A - Boy or Girl](http://codeforces.com/problemset/problem/236/A)
1. UVA
    1. [501 - Black Box](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=442)
    1. [11849 - CD](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2949)

Referências
-----------

**HALE**, Margie. _Essentials of Mathematics: Introduction to Theory, Proof, and the Professional
Culture_. Mathematical Association of America, 2003.
