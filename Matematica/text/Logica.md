Lógica Proposicional Booleana
=============================

Conceitos Fundamentais
----------------------

A Lógica Proposicional Booleana é construída a partir de dois axiomas fundamentais, que relacional
os termos primitivos **proposição**, **verdadeiro** e **falso**:

* **Princípio do Terceiro Excluído:** toda proposição ou é verdadeira ou é falsa;
* **Princípio da Não Contradição:** uma proposição não poder ser, simultaneamente, verdadeira e
falsa.

As proposições são representadas por letras minúsculas (por exemplo, _p, q, r, ..._). Duas ou
mais proposições simples podem ser combinadas por meio dos conectivos abaixo para formar 
proposições compostas (representadas por letras maiúsculas):

1. **Conjunção** (e): _p_ &#8743; _q_ (verdadeira apenas quando ambas _p_ e _q_ são verdadeiros);
1. **Disjunção** (ou): _p_ &#8744; _q_ (falsa apenas quando ambas _p_ e _q_ são falsas);
1. **Disjunção exclusiva** (_xor_): _p_ &#8891; _q_ (verdadeira apenas quando _p_ e _q_ tem valores 
lógicos opostos);
1. **Condicional** (se, então): _p_ &#8594; _q_ (falsa apenas quando _p_ é verdadeira e _q_ é 
falsa);
1. **Bicondicional** (se, e somente se): _p_ &#8596; _q_ (verdadeira apenas quando _p_ e _q_ tem
mesmo valor lógico).

Além dos conectivos acima listados, a **negação** (&#172; ou ~) inverte o valor lógico de uma 
proposição: proposições verdadeiras se tornam falsas e vice-versa.


C e C++
-------

As linguagens C e C++ tem, em sua sintaxe, operadores lógicos relacionais, que representam os
conectivos citados anteriormente, e operadores lógicos _bit_ a _bit_, que aplicam cada operação
lógica aos pares de _bits_ correspondentes. Importante notar que, embora a linguagem C++ tenha
um tipo de dado booleano, ambas linguagens interpretam como verdadeiro qualquer valor inteiro
diferente de zero, e o zero como falso.

| Operador | Símbolo em C | Palavra reservada em C++ |
| :---     |    :---:     |         :---:            |
|   e      |     &&       |         `and`            |
|   ou     |     \|\|     |         `or`             |
|   não    |     !        |         `not`            |

Observe que apenas 3 dos conectivos apresentados tem símbolos ou palavras reservadas equivalentes
em C e C++: isto se dá porque é possível, a partir destes três, definir quaisquer um dos demais
conectivos. Por exemplo, _p_ &#8594; _q_ é logicamente equivalente a &#172; _p_ &#8744; _q_.

Outro ponto importante é que estes operadores, em C/C++, são curto-circuito: se a primeira das
duas proposições é verdadeira em uma disjunção, a segunda não será avaliada (pois o valor lógico
já está definido como verdadeiro); se a primeira das duas proposições for falsa em uma conjunção,
a segunda não será executada pelo mesmo motivo.

A tabela abaixo apresenta os operadores _bit_ a _bit_ em C/C++:

| Operador | Símbolo | 
| :---     |  :---:  |
|   e      |    &    |
|   ou     |    \|   |
|   não    |    ~    |
|   xor    |    ^    |

O código abaixo ilustra o uso dos operadores _bit_ a _bit_.
```C++
int main()
{
    unsigned char a = 46;         //  46 = 00101110
    unsigned char b = 151;        // 150 = 10010111

    unsigned char c = a & b;      //   6 = 00000110
    unsigned char d = a | b;      // 191 = 10111111
    unsigned char e = a ^ b;      // 185 = 10111001
    unsigned char f = ~a;         // 209 = 11010001
    unsigned char g = ~b;         // 104 = 01101000

    return 0;
}
```

Exercícios
----------

<!-- 276D - Guloso -->
<!-- 1026 - Xor -->
<!-- 1743 - Xor -->
<!-- 10718 - Guloso -->

1. Codeforces
    1. [276D - Little Girl and Maximum XOR](http://codeforces.com/problemset/problem/276/D)
1. URI
    1. [1026 - Carrega ou não Carrega?](https://www.urionlinejudge.com.br/judge/pt/problems/view/1026)
    1. [1743 - Máquina de Verificação Automatizada](https://www.urionlinejudge.com.br/judge/pt/problems/view/1743)
1. UVA
    1. [10718 - Bit Mask](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1659)

Referências
-----------

**ALENCAR FILHO**, Edgard de. _Iniciação à Lógica Matemática_. São Paulo, Nobel, 2002.

**HALE**, Margie. _Essentials of Mathematics: Introduction to Theory, Proof, and the Professional
Culture_. Mathematical Association of America, 2003.
