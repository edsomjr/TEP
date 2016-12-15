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

http://site.ebrary.com/lib/univbrasilia/reader.action?docID=10201155&ppg=1
página 12

1. Representação de strings
1. Bibliotecas (C, C++ e Python)
1. Algoritmos elementares (histograma, conversões para/de inteiros, filtros,
tabelas de substituição)
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
