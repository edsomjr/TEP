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
# Fundamentos

*__Lógica Proposicional Booleana__*

Prof. Edson Alves
Faculdade UnB Gama

## Termos primitivos e axiomas

A Lógica Proposicional Booleana é construída a partir de dois axiomas fundamentais, que relaciona os termos primitivos **proposição**, **verdadeiro** e **falso**:

1. **Princípio do Terceiro Excluído:** toda proposição ou é verdadeira ou é falsa;
1. **Princípio da Não Contradição:** uma proposição não poder ser, simultaneamente, verdadeira e falsa.

## Proposições simples e compostas

- As proposições são representadas por letras minúsculas (por exemplo, $p, q, r, \ldots$)

- Duas ou mais proposições simples podem ser combinadas por meio de conectivos lógicos para formar proposições compostas 

- Proposições compostas são representadas por letras maiúsculas (por exemplo, $P, Q, R, \ldots$)

- Proposições compostas também podem ser combinadas por meio de conectivos lógicos

## Conectivos lógicos

| Conectivo | Notação | Valor Lógico |
| :--- | :---: | :--- |
| **Conjunção** (e) | $p \land q$ | verdadeira apenas quando ambas $p$ e $q$ são verdadeiras |
| **Disjunção** (ou) | $p \lor q$ |  falsa apenas quando ambas $p$ e $q$ são falsas |
| **Disjunção exclusiva** (_xor_) | $p \veebar q$ | verdadeira apenas quando $p$ e $q$ tem valores lógicos opostos |

## Conectivos lógicos

| Conectivo | Notação | Valor Lógico |
| :--- | :---: | :--- |
| **Condicional** (se, então) | $p \to q$ | falsa apenas quando $p$ é verdadeira e $q$ é falsa |
| **Bicondicional** (se, e somente se) | $p \leftrightarrow q$ | verdadeira apenas quando $p$ e $q$ tem mesmo valor lógico |
| **Negação** (não) | $\lnot p$ | inverte o valor lógico de $p$ |

## Leis de Morgan

Sejam $p$ e $q$ duas proposições. Vale que
$$
    \lnot (p \land q) = \lnot p\ \lor \lnot q
$$
e que
$$
    \lnot (p \lor q) = \lnot p\ \land \lnot q
$$

## C e C++

- As linguagens C e C++ tem, em sua sintaxe, operadores lógicos relacionais, que representam os conectivos lógicos

- Também há suporte para operadores lógicos _bit_ a _bit_, que aplicam cada operação lógica aos pares de _bits_ correspondentes 

- Importante notar que, embora a linguagem C++ tenha um tipo de dado booleano, ambas linguagens interpretam como verdadeiro qualquer valor inteiro diferente de zero, e o zero como falso

## Operadores lógicos em C/C++

| Operador |    Aridade   | Símbolo em C | Palavra reservada em C++ |
| :---:    |    :---:     |   :---:      |         :---:            |
|   e      |    binário   |   `&&`       |         `and`            |
|   ou     |    binário   |   `\|\|`     |         `or`             |
|   não    |    unário    |   `!`        |         `not`            |

## Operadores lógicos em C/C++

- Observe que apenas 3 dos conectivos lógicos tem símbolos ou palavras reservadas equivalentes em C e C++

- Isto se dá porque é possível, a partir destes três, definir quaisquer um dos demais conectivos

- Por exemplo, $p \to q$ é logicamente equivalente a $\lnot p \lor q$

- Estes operadores são curto-circuito: se o valor lógico da primeira proposição é suficiente para definir o valor da expressão, a segunda proposição não é avaliada

## Operadores _bit_ a _bit_ em C/C++
         
| Operador          | Aridade   | Símbolo | 
| :---              |  :---:    |  :---:  |
|   e               |  binário  |    `&`  |
|   ou              |  binário  |    `\|` |
|   ou exclusivo    |  binário  |    `^`  |
|   não             |  unário   |    `~`  |

## Exemplo de operadores _bit_ a _bit_ em C/C++

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

## Problemas

- AtCoder
    1. [ABC 097A - Colorful Transceivers](https://atcoder.jp/contests/abc097/tasks/abc097_a)
    1. [ABC 117D - XXOR](https://atcoder.jp/contests/abc117/tasks/abc117_d)
    1. [ABC 148A - Round One](https://atcoder.jp/contests/abc148/tasks/abc148_a)
- Codeforces
    1. [276D - Little Girl and Maximum XOR](http://codeforces.com/problemset/problem/276/D)
- OJ
    1. [10718 - Bit Mask](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1659)

## Referências

1. **ALENCAR FILHO**, Edgard de. _Iniciação à Lógica Matemática_. São Paulo, Nobel, 2002.

1. **HALE**, Margie. _Essentials of Mathematics: Introduction to Theory, Proof, and the Professional Culture_. Mathematical Association of America, 2003.

1. **MORTARI**, Cezar A. _Introdução à Lógica_. Editora Unesp, 2ª edição, 2017.
