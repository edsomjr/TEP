Algoritmos de Busca
===================

* Algoritmo fundamental de strings
* Consiste em determinar se uma substring `pat`, de tamanho `m`, ocorre ou não
em uma string `s`, de tamanho `n`.
* Os principais algoritmos são: a busca completa, o Knuth-Morris-Pratt (KMP) e o Boyer-Moore (BM)
* Os últimos dois algoritmos são divididos em duas etapas:
    1. pré-processamento do padrão, que envolve a construção de certas tabelas
    1. busca, onde se determinar a primeira (ou todas) ocorrência de `pat` em `s`.

Busca Completa
--------------

A busca completa compara cada uma das `n - m + 1` substrings de tamanho `m` de
`s` com `pat`, reportando cada igualdade. Como a comparação tem complexidade
`O(m)` e o número de substrings é `O(n)`, temos um algoritmo com complexidade
quadrática `O(mn)`.

Uma implementação em C++ é ilustrada abaixo.

```C++
int occurrences(const string& s, const string& pat)
{
    int n = s.size();
    int m = pat.size();

    if (m > n)      // Caso especial: o padrão é maior do que s
        return 0;

    int occ = 0;    // Número de ocorrências de pat em s

    for (int i = 0; i <= n - m; ++i) 
        occ += (pat == s.substr(i, m) ? 1 : 0);

    return occ;
}
```

O único cuidado a ser tomado, na implementação, é se certificar que todas as
substrings foram verificadas (atentar para o `<=` na condição do laço).

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

CROCHEMORE, Maxime; RYTTER, Wojciech. [Jewels of Stringology: Text Algorithms](http://site.ebrary.com/lib/univbrasilia/reader.action?docID=10201155), WSPC, 2002.
