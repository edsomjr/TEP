Introdução
==========

1. Contextualização

* sequências de caracteres, ou _strings_, constituem uma maneira natural de
representar informações.
* As strings aparecem em diversas áreas além da computação, como a Biologia
(estudo das moléculas e DNA), Letras (ortografia, sintaxe e morfologia),
Criptografia (codificação e decodificação de mensagens), etc
* O algoritmo fundamental, _pattern matching_, é usado para localizar 
informações em um texto, tem importância, na teoria dos algoritmos, semelhante
à dada aos algoritmos de ordenação.
* Várias ferramentas do UNIX lidam com textos (grep, cat, more, less, sed, diff), seja para
_string matching_, exibição, busca, identificação, filtragem, manipulação, etc
* Padrões podem ser exatos, ou escrito em uma representação que utiliza 
caracteres especiais para marcar padrões ou repetições, denominado **regex** 
(_regular expressions_).
* A linguagem **awk** (Aho, Weinberger, Kernighan) é interamente baseada em
expressões regulares e é focada na manipulação de strings.
* Definições

1. Alfabeto: conjunto finito de símbolos `A`;
1. Letras, caracteres ou símbolos: elementos de `A`;
1. Textos, palavras ou strings: sequência ordenada `s` de elementos de `A`;
1. Tamanho de uma string: número de elementos na sequência `s` (notação `|s|`;
1. `i`-ésimo elemento da string: elemento que ocupa a posição `i` da sequência. Notação: `s[i]`;
1. Intervalo: subsequência de `s`. Notação: `s[i..j] = s[i]s[i+1]...s[j]`. Observação: `|s[i..j]| = j - i + 1`;
1. Substring: string `b`, com `|b| = n`, tal que `b' = s[i+1..i+n]` para algum inteiro `i`;
1. Subsequência: um string `a` obtida a partir da remoção de zero ou mais elementos de `s` (não necessariamente consecutivos). Notação: `a = s[i1]s[i2]...s[im]`,
onde `i1, i2, ..., im` é uma sequência crescente de índices de `s`;
1. Problema fundamental: dada uma string `P`, que representa um padrão, determinar se `p` ocorre ou não em `s`. Este é um problema de decisão (a resposta é
booleana) e, em geral, `|P| <= |s|`. Notação: `MATCH(P, s)`.
1. Período: o período de uma string `s` é um inteiro `p, 0 <= p <= |s|` tal que
`s[i] = s[i + p]`, para todo `i = {1, ..., |x| - p}`. Para qualquer string, `|s|` é um período, de modo que pode se denotar `period(s)` o menor período de `s`, e dizer que `s` é periódica se `period(sO <= |x|/2`.
1. Borda: a borda de um string `s` é uma substring `B` de `s` que é, simultaneamente, um prefixo (`B = s[1..|B|]`) e um sufixo (`B = s[(|s| - |B|)..|s|]`) de `s`;
1. Como um string vazia (`|s| = 0`) e a própria string `s` são sempre bordas de `s`, definimos `border(s)` a mais longa dentre as bordas não-triviais (isto é, não vazias, nem a própria string) de `s`;
1. O período `0 < p <= |s|` de `s` pode ser caracterizado por 3 condições equivantes:
    * `s` é substring de alguma string `y^k`, com `|y| = p` e `k > 0`;
    * `s` pode ser escrito na forma `(uv)^k` com `|uv| = p`, onde `v` é uma string não nula e `k > 0`;
    * para strings `y, z, w`, `s = yw = wz` e `|y| = |z| = p`.

**Lema da Periodicidade.** Sejam `p` e `q` dois períodos de uma string `s`. Se
`p + q < |s|`, então `mdc(p, q)` também é período de `s`.

**Lema Forte da Periodicidade.** Sejam `p` e `q` dois períodos de uma string `s`. Se 
`p + q - mdc(p, q) <= |s|`, então `mdc(p, q)` também é período de `s`.

1. Strings de Fibonacci: `Fib-n`, com `n >= 0`, é dada por

        Fib-0 = ""
        Fib-1 = b
        Fib-2 = a
        Fib-n = Fib-(n-1)Fib-(n-2), n > 2

Fato: se removida as duas últimas letras de uma string de Fibonacci, o resultado é um palíndromo. Qûalquer string de Fibonacci é prefixo de outra string de Fibonaaci. Todas são prefixos de `Fib-\infty`.

2. Prefixos de Thue-Morse: são os prefixos `T(n)` da string infinita `T_\infty`
definida da seguinte maneira: a contagem inicia em zero, e `g(k)` é o número
de 1s na representação binária de `k`. Daí 

        T_\infty(k) = a, se g(k) é par
        T_\infty(k) = b, caso contrário

Assim as strings de Thue-Morse `T(n)` são os prefixos de `T_\infty` de tamanho
`2^n`. Exemplos:

        T(1) = ab
        T(2) = abba
        T(3) = abbabaab
        T(4) = abbabaabbaababba

Estas strings são livres de _overlaps_, isto é, não existe nenhuma string não
vazia `x` que ocorre em duas posições distintas com distância entre estas
posições menor do que `|x|`. Também são livre de quadrados: não existe um
string `x` tal que `xx` seja substring de `T(n)`.

1. **Palavras binárias Pn**: a palavra `Pn` é dada pela `n`-ésima linha do triângulo de Pascal módulo 2, isto é, `Pn(i) = binom(n, i) mod 2`. Exemplos:

        P0 = 1
        P1 = 1 1
        P2 = 1 0 1
        P3 = 1 1 1 1
        P4 = 1 0 0 0 1

O número de 1s em `Pn` é igual a `2^g(n)`.

1. String de dígitos: considere a string infinita `W` composta pela representação decimal dos números naturais consecutivos, isto é,

        W = 0123456789101112131415161718192021222324252627282930...

Seja `Wn` o prefixo de `w` de tamanho `n`. Defina, para uma string `x`, a 
função `occ_n(x)`, que computa o número de ocorrências de `x` em `Wn`. Para quaisquer duas strings `x, y` de mesmo tamanho, `lim_{n\to\infty} (occ_n(x)/occ_n(y)) = 1`. Esta propriedade dá um sentido "randômico" a esta sequência.

1. Strings de Bruijin: seja `A = {a, b}`. Existem `2^k` strings de tamanho `k` 
formadas por elementos de `A`. Uma pergunta natural que surge é: qual é o 
comprimento mínimo `gamma(k)` de um string que contém todas estas substrings.

Um limite superior é `gamma(k) = 2^k + k - 1` (pois qualquer string menor não
teria `2^k` substrings de tamanho `k`. Efetivamente, `gamma(k) = 2^k + k - 1`.
Esta string é denominada "de Bruijin".

Há uma relação entre strings de Bruijin e ciclos de Euler. Seja `G_k` um grafo 
cujos vértices são strings de tamanho `k - 1` e, para qualquer substring
`x = a1a2...ak-1` temos duas arestas direcionadas:

        a1a2..ak-1 --(a)--> a2a3..ak-1a e
        a1a2..ak-1 --(b)--> a2a3..ak-1b

Este grafo tem um ciclo de Euler direcionado, que contém cada aresta uma única
vez. Seja `a1a2...aN` a sequência de arestas do ciclo de Euler. Temos que
`N = 2^k`. A sequência abaixo forma uma string de Buijin:

        a1a2..aNa1a2...ak-1

Strings não-ASCII
-----------------

página 12

1. Algoritmos de Busca
1. Árvores de Suffixos
1. Subword graphs
1. Algoritmos relacionados à ordenação
1. Simetrias e Repetições
1. Compressão
1. Automatos
1. Matching aproximado, por amostragem e duelo, bidimensionais
1. Periodicidade bidimensional
1. Algoritmos paralelos
1. Outros

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

CROCHEMORE, Maxime; RYTTER, Wojciech. [Jewels of Stringology: Text Algorithms](http://site.ebrary.com/lib/univbrasilia/reader.action?docID=10201155), WSPC, 2002.
