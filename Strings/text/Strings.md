Strings
=======

Sequências de caracteres, ou _strings_, constituem uma maneira natural de
representar informações. As strings aparecem em diversas áreas além da
computação, como a Biologia (estudo das moléculas e DNA), Letras (ortografia,
sintaxe e morfologia), Criptografia (codificação e decodificação de mensagens),
dentre outras.

O algoritmo fundamental para o estudo e entendimento de _strings_ é o
_pattern matching_, que consiste na localização informações (padrões) em um texto
(_string_). A importância do _pattern matching_ para o estudo das _strings_
equivale à importância dos algoritmos de ordenação no estudo de algoritmos.

Os padrões a serem localizados podem ser exatos, ou escritos em uma
representação que utiliza caracteres especiais para marcar sequências ou
repetições, denominada **regex** (_regular expressions_).  A linguagem **awk** 
(Aho, Weinberger, Kernighan) é interamente baseada em
expressões regulares e é focada na manipulação de strings.

O ambiente UNIX dispõe de várias ferramentas para textos (`grep`, `cat`, `more`,
`less` `sed`, `diff`, etc), que permitem _pattern matching_, exibição, busca,
identificação, filtragem, manipulação, dentre outros. Estas ferramentas podem
ser utilizadas isoladamente
ou em conjunto, oferecendo uma grande gama de opções aos seus usuários.

Definições
----------

Um **alfabeto** `A` é um conjunto finito de símbolos. Os elementos de um alfabeto
`A` são denominados **letras**, **caracteres** ou **símbolos**. Exemplos de
alfabeto comumente utilizados são as letras maiúsculas e minúsculas, os dígitos
decimais e a tabela ASCII.

Uma _string_ `s` (ou **texto** ou **palavra**) é uma sequência ordenada
`s = {a1, a2, ..., aN}` de caracteres `ai` de um dado alfabeto `A`. O `i`-ésimo
termo de `s` também é denotado por `s[i]`. O número `N` de elementos da
sequência `s` pode ser notado como `|s|`.

Um **intervalo** é uma subsequência contígua `s[i..j] = s[i]s[i+1]...s[j]` de
elementos de `s`. Observe que `|s[i..j]| = j - i + 1`. Uma **substring** `b` de
`s`, com `|b| = M`, é uma string `b` tal que `b = s[i+1..i+M]` para algum
inteiro `i`.

Uma **subsequência** `a = s[i1]s[i2]...s[iM]` de uma _string_ `s` pode ser
obtida a partir da
remoção de zero ou mais elementos de `s`, não necessariamente consecutivos.
Os inteiros `i1, i2, ..., iM` formam uma sequência crescente de índices de `s`
(isto é, `iu < iv` para `u < v`).

Um **prefixo** de uma string `s` é uma substring `px`, de tamanho
`|px| = M`, tal que `px = s[1..M]`; um **sufixo** `sx` de `s`, de tamanho
`|sx| = T`, é uma substring de `s` tal que `sx = s[(N - T + 1)..N]`, onde
`|s| = N`. Uma **borda** `B` de uma string `s` é uma substring que é,
simultaneamente, prefixo e sufixo de `s`. Por exemplo, as strings
`"ame", "rica"` e `"a"` são exemplos de prefixo, sufixo e borda da string
`"america"`.

Uma vez que a string **vazia** (isto é, `|s| = 0`) e a própria string `s` são
sempre bordas (triviais) de `s`, define-se `border(s)` como a mais longa
(de maior tamanho) dentre as bordas de `s` que são distintas da própria string
`s`.

O **período** de uma string `s` é um inteiro `p, 0 < p <= |s|` tal que
`s[i] = s[i + p]`, para todo `i = {1, ..., |s| - p}`. Para qualquer string,
`|s|` é um período, de modo que define-se
`period(s)` como o menor período de `s`. A _string_ `s` é dita
**periódica** se `period(s) <= |s|/2`. Por exemplo, para as strings
`s1 = "marítima", s2 = "ticotico"` e `s3 = "Brasilia"`, temos `period(s1) = 6,
period(s2) = 4` e `period(s3) = 8`; dentre as três, apenas `s2` é períodica.

Os diferentes períodos de uma mesma string `s` se relacionam de uma maneira
não trivial, que pode ser expressa pelos dois lemas a seguir:

**Lema da Periodicidade.** Sejam `p` e `q` dois períodos de uma string `s`. Se
`p + q < |s|`, então `mdc(p, q)` também é período de `s`.

**Lema Forte da Periodicidade.** Sejam `p` e `q` dois períodos de uma string `s`. Se
`p + q - mdc(p, q) <= |s|`, então `mdc(p, q)` também é período de `s`.

Há uma interessante relação entre bordas e períodos: a sequência

        |s| - |border(s)|, |s| - |border^2(s)|, ..., |s| - |border^k(s)|

é a sequência crescente de todos os possíveis períodos de `s`, onde `k` é o
menor inteiro positivo tal que `border^k(s)` é uma string vazia. Por exemplo,
para a string `s = "teteatete"`, temos `|s| = 9` e

        border(s) = "tete"
        border^2(s) = border("tete") = "te"
        border^3(s) = border("te") = "",

os quais formam a sequência de períodos 9 - 4 = 5, 9 - 2 = 7, 9 - 0 = 9.

O problema fundamental de _strings_ é o _pattern matching_: dada uma string `P`,
que representa um padrão, determinar se `P` ocorre ou não em `s`. O
_pattern matching_ é um problema de decisão, isto é, a resposta é booleana: o
padrão ocorre ou não. Em geral, `|P| <= |s|`. Uma notação possível é  
`MATCH(P, s)`.

Strings Notáveis
----------------

### Strings de Fibonacci

As strings de **Fibonacci** `Fib-n`, com `n >= 0`, são definidas recursivamente
como

        Fib-0 = ""
        Fib-1 = "b"
        Fib-2 = "a"
        Fib-n = Fib-(n-1)Fib-(n-2), n > 2

onde a expressão `Fib-(n-1)Fib-(n-2)` significa a concatenação das últimas duas
strings de Fibonacci. Por exemplo, `Fib-3 = "ab", Fib-4 = "aba"` e
`Fib-5 = "abaab"`.

Há 3 fatos notáveis a respeito das strings de Fibonacci:

1. removidas as duas últimas letras de uma string de Fibonacci, o resultado é um palíndromo;
1. qualquer string de Fibonacci é prefixo de outra string de Fibonacci;
1. todas strings de Fibonacci são prefixos de `Fib-\infty`.

Há muitos outros fatos notáveis sobre tais strings: veja a referência para
maiores informações.

### Prefixos de Thue-Morse

Considere a string infinita `T_\infty`, definida da seguinte maneira, onde
`g(k)` é o número de 1s na representação binária do inteiro positivo `k`. Daí

        T_\infty(k) = a, se g(k) é par
        T_\infty(k) = b, caso contrário

Os **prefixos de Thue-Morse** `T(n)` são os prefixos de `T_\infty` de tamanho
`2^n`. Exemplos:

        T(1) = ab
        T(2) = abba
        T(3) = abbabaab
        T(4) = abbabaabbaababba

Estas strings são livres de _overlaps_, isto é, não existe nenhuma string não
vazia `s` que ocorre em duas posições distintas de `T(n)` com distância entre 
estas posições menor do que `|s|`. Também são livre de quadrados: não existe um
string `s` tal que a concatenação de `s` consigo mesma `ss` seja substring de 
`T(n)`.

## Palavras binárias Pn

A **palavra binária** `Pn` é obtida a partir da `n`-ésima linha do triângulo de 
Pascal, onde seu `i`-ésimo caractere é dado por `Pn(i) = binom(n, i) mod 2`. 
As primeias 5 palavras binárias `Pn` são

        P0 = "1"
        P1 = "11"
        P2 = "101"
        P3 = "1111"
        P4 = "10001"

O número de ocorrências do caractere '1' em `Pn` é igual a `2^g(n)`, onde
`g(k)` tem a mesma definição dada anteriormente nos prefixos de Thue-Morse.

### String de dígitos 

Considere a string infinita `W` composta pela representação decimal dos números 
naturais consecutivos, isto é,

        W = 0123456789101112131415161718192021222324252627282930...

Seja `Wn` o prefixo de `w` de tamanho `n`. Defina, para uma string `s`, a
função `occ_n(s)`, que computa o número de ocorrências de `s` em `Wn`. Para 
quaisquer duas strings `s, t` de mesmo tamanho, 
`lim_{n\to\infty} (occ_n(s)/occ_n(t)) = 1`. Esta propriedade dá um sentido 
"randômico" a esta sequência.

### Strings de Bruijin 

Seja `A = {a, b}`. Existem `2^k` strings de tamanho `k`
formadas por elementos de `A`. Uma pergunta natural que surge é: qual é o
comprimento mínimo `gamma(k)` de uma string que contenha todas estas substrings?

Um limite inferior é `gamma(k) = 2^k + k - 1` (pois qualquer string menor não
teria `2^k` substrings de tamanho `k`. Efetivamente, `gamma(k) = 2^k + k - 1`.
Uma string com este tamanho, contendo todas as substrings de tamanho `k` 
formadas por elementos de `A` é denominada **string de Bruijin**.

Há uma relação entre strings de Bruijin e ciclos de Euler. Seja `G_k` um grafo
cujos vértices são strings de tamanho `k - 1` e, para qualquer substring
`x = a1a2...ak-1` temos duas arestas direcionadas:

        a1a2..ak-1 --(a)--> a2a3..ak-1a
        a1a2..ak-1 --(b)--> a2a3..ak-1b

Este grafo tem um ciclo de Euler direcionado, que contém cada aresta uma única
vez. Seja `a1a2...aN` a sequência de arestas do ciclo de Euler. Temos que
`N = 2^k`. A sequência abaixo forma uma string de Bruijin:

        a1a2..aNa1a2...ak-1

### Exercícios

<!--- 133A - find -->
<!--- 177G1 - Strings de Fibonacci -->
<!--- 266A - sets -->
<!--- 153 - permutations -->
<!--- 263 - strings, digits, sorting -->
<!--- 11483 - string formatting -->
<!--- 12243 - tokenizing, read lines and words -->

1. Codeforces
    1. [133A - HQ9+](http://codeforces.com/problemset/problem/133/A)
    1. [177G1 - Fibonacci Strings](http://codeforces.com/problemset/problem/177/G1)
    1. [266A - Stones on the Table](http://codeforces.com/problemset/problem/266/A)
1. UVA
    1. [153 - Permalex](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=89)
    1. [263 - Number Chains](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=199)
    1. [11483 - Code Creator](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2478)
    1. [12243 - Flowers Flourish from France](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3395)

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

CROCHEMORE, Maxime; RYTTER, Wojciech. [Jewels of Stringology: Text Algorithms](http://site.ebrary.com/lib/univbrasilia/reader.action?docID=10201155), WSPC, 2002.

WIKIPEDIA. [ASCII](https://pt.wikipedia.org/wiki/ASCII), acesso em 06/02/2017.

WIKIPEDIA. [Fibonacci Word](https://en.wikipedia.org/wiki/Fibonacci_word), acesso
em 07/02/2017.

