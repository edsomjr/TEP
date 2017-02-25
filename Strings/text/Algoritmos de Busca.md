A busca é o algoritmo fundamental dentre os algoritmos de strings e, conforme
dito anteriormente, se equivalente, em importância, aos algoritmos de ordenação
no estudo de algoritmos.

A busca em strings consiste em determinar se uma string `pat`, de tamanho `m`, 
ocorre ou não em uma string `text`, de tamanho `n` (ou o número de tais 
ocorrências).

Os principais algoritmos de busca em strings são: a busca completa, o 
algoritmo de Knuth-Morris-Pratt (KMP) e o algoritmo de Boyer-Moore (BM).
O primeiro deles é de fácil entendimento e codificação; os dois últimos são
conceitualmente divididos em duas etapas:

1. **pré-processamento do padrão**, que envolve a construção de certas tabelas;
1. **busca**, onde se determina a primeira (ou todas) ocorrência(s) de `pat` em 
`text`.

Um outro algoritmo de busca, baseado no uso de funções _hash_, é o algoritmo
de Rabin Karp.

Busca Completa
--------------

A busca completa compara cada uma das `n - m + 1` substrings de tamanho `m` de
`text` com `pat`, reportando cada igualdade. Como a comparação tem complexidade
`O(m)` e o número de substrings é `O(n)`, temos um algoritmo com complexidade
`O(mn)`.

Uma possível implementação em C++ é ilustrada abaixo.

```C++
int occurrences(const string& text, const string& pat)
{
    int n = text.size();
    int m = pat.size();

    int occ = 0;    // Número de ocorrências de pat em text

    for (int i = 0; i <= n - m; ++i) 
        occ += (pat == text.substr(i, m) ? 1 : 0);

    return occ;
}
```

O único cuidado a ser tomado, na implementação, é se certificar que todas as
substrings foram verificadas (atentar para o `<=` na condição do laço). 

Outro ponto importante a se notar é que a comparação entre `pat` e a subtring
pode ser feita tanto da esquerda para direita quanto em sentido oposto, e estas
duas alternativas constituem as ideias fundamentais para os outros dois
algoritmos: KMP e BM.

Algoritmo de Morris-Pratt
-------------------------

Na função `occurrences()` descrita acima, as comparações feitas entre a 
substring em questão e o padrão são independentes, o que resulta em várias
comparações sendo feitas mais de uma vez e desnecessáriamente. 

Por exemplo, considere `text = "xyzabcdfgh"` e `pat = "abcde"`. A comparação
entre a substring com início no índice 3 (a saber, `abcdf`) e o padrão falha
no último caractere (`'f' != 'e'`), localizado no índice 7. Como todos 
os caracteres do padrão são distintos, é possível identificar que o padrão não
pode ocorrer a partir dos índices de 4 a 6, mas `occurrences()` ainda assim 
realiza tais comparações.

O algoritmo de Morris-Pratt explora justamente as comparações entre caracteres
já feitas, movendo o índice de ínicio das comparações entre as substrings e o
padrão para a posição mais distante possível. Para melhor explicar o 
funcionamento de tal algoritmo, precisamos de algumas definições preliminares.

Chamamos **salto seguro** `s` ao inteiro positivo tal que há garantias de que
o padrão não pode acontecer entre as posições `i` e `i + s` do texto, mas que
pode-se iniciar o padrão em `i+s`.

Quando o padrão contém caracteres distintos, é seguro saltar para a posição onde
aconteceu a falha. Contudo, devemos ter cuidado quando há repetições de letras
no padrão. Mais precisamente, para que o salto seja seguro, devemos identificar
a maior borda possível para `pat[1..j]`: devemos saltar para a posição onde
esta borda se inicia. Assim, o **salto seguro de Morris-Pratt** para o padrão
 `pat[1..j], j = 1, 2, ..., m` é dado por

        MP_shift[j] = j - |border(pat[1..j])|

Lembre-se de que `border(s)` é a maior substring `x` de `s` que é, ao mesmo 
tempo, sufixo e prefixo de `s`. No caso especial de uma string vazia, o 
salto deve assumir o valor mínimo de 1, de modo que devemos fazer
`MP_shift[0] = 1`.

De posse do vetor `MP_shift`, temos uma possível implementação do algoritmo de
Morris-Pratt.
```C++
int MP(const string& text, const string& pat)
{
    int n = text.size();
    int m = pat.size();
    int i = 0, j = 0, occ = 0;

    vector<int> bords = borders(pat);

    while (i <= n - m)
    {
        while (j < m and pat[j] == text[i + j])
            ++j;

        if (j == m)
            ++occ;

        int MP_shift = j - bords[j];

        i += MP_shift;
        j = max(0, j - MP_shift);
    } 

    return occ;
}
```

O algoritmo de Morris-Pratt realiza, no máximo, um número de comparações linear 
em termos dos tamanhos de `text` e `pat`, a saber, `2n - m` comparações. Isto 
pode ser observado da seguinte maneira: serão feitas, no máximo, a comparação
`pat[j] == text[i + j]` pode falhar, no máximo, `n - m + 1` vezes (o primeiro
laço é executado `n - m + 1`  vezes) e pode ter sucesso, no máximo, `n` vezes
(quando o padrão e o texto são idênticos). Caso a primeira comparação seja 
bem sucedida, ela não pode falhar no índice 0. Daí o máximo de comparações será
igual a `n + (n - m) = 2n - m`.

Assim, o algoritmo MP é linear em relação ao tamanho do texto.
Porém, para determinar sua complexidade, falta determinar a complexidade da
construção do vetor `MP_shift`. Este vetor pode ser construído a partir de uma
variação do próprio MP, de modo que teremos uma construção também linear em 
relação ao tamanho do texto. Daí, a complexidade do algoritmo MP é  `O(n)`.

Para construir `MP_shift`, determinaremos os valores de `border(pat[1..j])` a
partir de uma variante do algoritmo MP, onde `text == pat`, 
apresentada a seguir.
```C++
// Computa o tamanho das bordas de pat: bord[j] é o tamanho da borda da
// substring pat[0..(j-1)]
vector<int>
borders(const string& pat)
{
    int m = pat.size();
    int i = 1, j = 0;

    vector<int> bord(m + 1, -1);    // Inicialmente, bord[j] = -1 para todo j

    while (i < m + 1)
    {
        while (i + j < m and pat[j] == pat[i + j])
        {
            ++j;

            if (bord[i + j] == -1)
                bord[i + j] = j;
        }

        i += j - bord[j]; 
        j = max(0, bord[j]);
    } 

    // Ajuste para compatibilidade entre os dois algoritmos de borda
    for (int i = 1; i <= m; ++i)
        if (bord[i] == -1)
            bord[i] = 0;

    return bord;
}
```

Vale notar que, no momento das atualizações de `i`  e `j`, ao final do primeiro
laço, os valores de `bord[j]` já estão devidamente computados, e que `i` 
inicia em 1, não em zero (`bord[0] = -1`: uma string de tamanho 1 não tem 
bordas não triviais e o valor -1 faz com que a atualização de `i` seja igual a,
no mínimo, um).

Contudo, o algoritmo mais comum para o cálculo das bordas é apresentado abaixo.
Assim como a variação do MP, também é linear em relação ao tamanho de `pat`.
```C++
// Computa o tamanho das bordas de pat: bord[j] é o tamanho da borda da
// substring pat[0..(j-1)]
vector<int> borders2(const string& pat)
{
    int m = pat.size();
    int t = -1;

    vector<int> bord(m + 1);
    bord[0] = -1;

    for (int j = 1; j <= m; ++j)
    {
        while (t >= 0 and pat[t] != pat[j - 1])
            t = bord[t];

        ++t;
        bord[j] = t;
    }

    return bord;
}
```


Algoritmo de Knuth-Morris-Pratt
-------------------------------

O algoritmo de Morris-Pratt tem como invariante

        inv(i, j) = (pat[1..j] = text[i + 1, i + j + 1]),

que permite os saltos seguros e que leva a complexidade `O(n + m)`. Contudo,
este invariante pode ser melhorada, ao se incorporar a propriedade da diferença,
isto é,

        inv2(i, j) = (pat[1..j] = text[i + 1, j + 1]) and (pat[j + 1] != text[i + j + 1]
    
Para entender o porque da melhora, considere o seguinte exemplo: seja
`pat = "abcabc"` e `text = "abcabdabc"`. Os 5 primeiros caracteres de ambos
coincidem, e a diferença ocorre no sexto caractere: `pat[5] = 'c' != text[5] = 'd'`. Mas `border[5] = 2 ("ab")`, o que deslocaria a próxima comparação para 
`pat[2]` e `text[5]`. Contudo, esta comparação é idêntica a anterior, pois a
borda "ab" não é própria, isto é, o próximo caractere ('c') gera uma nova
borda "abc". A contribuição de Knuth para o algoritmo de Morris-Pratt é essa:
incorporar a propriedade da diferença e definir as **bordas estritas**, onde
o próximo caractere não gera uma nova borda.

Ao definirmos `Strong_Bord[j]` como o menor inteiro `k` que satisfaz a condição

        `cond(j, k) = (pat[1..k] é sufixo próprio de pat[1..j]) and
            (pat[k + 1] != pat[j + 1])

(ou -1, caso não exista tal inteiro) e

        KMP_Shift[j] = j - Strong_Bord[j],

a implementação do KMP é praticamente idêntica ao do MP:
```C++
int KMP(const string& text, const string& pat)
{
    int n = text.size();
    int m = pat.size();
    int i = 0, j = 0, occ = 0;

    vector<int> bords = strong_borders(pat);

    while (i <= n - m)
    {
        while (j < m and pat[j] == text[i + j])
            ++j;

        if (j == m)
            ++occ;

        int KMP_shift = j - strong_bords[j];

        i += KMP_shift;
        j = max(0, j - KMP_shift);
    } 

    return occ;
}
```

Para o cálculo das bordas estritas basta observar que uma borda estrita é uma
borda cujo próximo caractere do prefixo e do sufixo diferente. Caso estes
caracteres sejam iguais, a borda estrita então deve ser avaliada novamente
no prefixo encontrado. 

Abaixo segue uma implementação em C++ para o cálculo das 
bordas estritas, que é uma variação do segundo algoritmo de bordas apresentado
para o algoritmo de Morris-Pratt. Atente ao fato de que a primeira condição
do `if` (isto é, `j == m`) subentende um caractere sentinela concatenado ao 
final do padrão.

```C++
vector<int>
strong_borders(const string& pat)
{
    int m = pat.size();
    int t = -1;

    vector<int> sbord(m + 1);
    sbord[0] = -1;

    for (int j = 1; j <= m; ++j)    // t é igual a bord[j - 1]
    {
        while (t >= 0 and pat[t] != pat[j - 1])
            t = sbord[t];

        ++t;

        if (j == m or pat[t] != pat[j])
            sbord[j] = t;
        else
            sbord[j] = sbord[t];
    }

    return sbord;
}
```

Algoritmo de Karp-Rabin
-----------------------

O algoritmo de Karp-Rabin é baseado no uso de funções _hash_ para a comparação
entre strings. Uma função _hash_ é uma função `f: A -> B` entre dois conjuntos 
`A` e `B` com as seguintes propriedades:

1. `f(a)` pode ser computada "eficientemente" para todos elementos `a` de `A`;
2. é altamente provável que `f(x) != f(y)` se `x != y`.

Vale observar mais atentamente a segunda propriedade: sendo função, temos que
`f(x) != f(y)` implica em `x != y`. Porém, a definição de funções não veda a
possibilidade de termos `f(x) = f(y)` com `x != y`. Esta situação é denominada
**colisão**, e uma boa função _hash_ tem uma baixa probabilidade de ocorrência
de colisões. Se `f` for construída de tal forma que não exista a possibilidade
de colisões, a função `f` é dita uma função de _hash_ perfeita.

No contexto de strings, o conjunto `A` é o conjunto `S` de todas as strings 
possíveis de um alfabeto fixo, e `B` é, em geral, o conjunto dos números 
inteiros.

A ideia central do algoritmo de Karp-Rabin é computar o hash `f(pattern)` do
padrão e compará-lo com os _hashes_ `f(text[i+1..i+m]` de todas as `n - m + 1`
substrings de tamanho `m` de `text` (`n = |text|, m = |pattern|`). Contudo,
o algoritmo necessita de uma propriedade adicional para `f`: `f(i+2..i+m+1)` deve
ser "facilmente computável" a partir de `f(i+1..i+m)`. Por conta desta 
propriedade o algoritmo de Karp-Rabin também é conhecido como _rolling hash_.

Um exemplo de _hash_ com as três propriedades necessárias é o seguinte: 
considere o alfabeto `A` e seja `id(a)` um inteiro entre 1 e `|A|` que 
representa o índice (posição) do caractere `a` em `A`. Seja

        f: S -> Z(p)
            s -> f(s[1..m]) = (id(s[m]) + id(s[m-1])*(|A| + 1) + ... +  id(s[1])*(|A| + 1)^{m-1}) % p 

onde `p` é um número primo. Se `t = s[2..m+1]` então

        f(t) = f(s[2..m+1]) 
        = (id(s[m+1]) + id(s[m])*(|A| + 1) + ... +  id(s[2])*(|A| + 1)^{m-1}) % p 
        = ((f(s) - id(s[1])*(|A| + 1)^{m-1})*(|A| + 1) + id(s[m + 1]) % p 

Assim, `f(s[2..m+1])` pode ser obtido a partir de `f(s[1..m])` em `O(1)` se
o valor de `(|A|+1)^{m-1}` for precomputado.

Uma implementação possível desta função em C/C++ é dada a seguir, com um 
exemplo de seu uso.
```C++
#include <iostream>

using namespace std;
using ll = long long;

// res = a^n (mod p)
ll fast_mod_exp(ll a, ll n, ll p)
{
    ll res = 1, base = a;

    while (n)
    {
        if (n & 1)
        {
            res *= base;
            res %= p;
        }

        base *= base;
        base %= p;

        n >>= 1;
    }

    return res;
}

const string A { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" };
const ll size = A.size();
const ll P = 1000000007;    // P = 10^9 + 7

ll idA(char c)
{
    return A.find(c);
}

// res = f(s[pos..pos + m - 1]), size = |A|, prev = f(s[pos-1..pos+m])
ll f(const string& s, int pos, ll prev, int m)
{
    ll res = 0;

    if (pos == 0)
    {
        for (int i = 0; i < m; ++i)
            res = (size*res + idA(s[pos + i])) % P;
    } else
    {
        ll SM = fast_mod_exp(size, m - 1, P);

        res = (prev - idA(s[pos - 1])*SM)*size + idA(s[pos+m-1]);
        res %= P;
    }

    return res;
}

int main()
{
    string s = "abcdef", pattern = "cde";

    int m = pattern.size();
    ll h = f(pattern, 0, 0, m); 

    printf("pattern (%s) hash = %lld\n", pattern.c_str(), h);

    h = f(s, 0, 0, m); 
    printf("s[0..2] (%s) hash = %lld\n", s.substr(0, m).c_str(), h);
    
    h = f(s, 1, h, m); 
    printf("s[1..3] (%s) hash = %lld\n", s.substr(1, m).c_str(), h);

    h = f(s, 2, h, m); 
    printf("s[2..4] (%s) hash = %lld\n", s.substr(2, m).c_str(), h);

    h = f(s, 3, h, m); 
    printf("s[3..5] (%s) hash = %lld\n", s.substr(3, m).c_str(), h);

    return 0;
}
```

As funções apresentadas acima permitem uma implementação do algoritmo de 
Karp-Rabin em C/C++:
```C++
int Karp_Rabin(const string& text, const string& pattern)
{
    int m = pattern.size(), n = text.size(), count = 0;
    ll r = f(pattern, 0, 0, m), h = 0;

    for (int i = 0; i < n - m + 1; ++i)
    {
        h = f(text, i, h, m);

        if (h == r and text.substr(i, m) == pattern)
            ++count;
    }

    return count;
}
```

Se o padrão for pequeno (entre 8 e 12 caracteres), é possível definir uma
função de hash `g` perfeita, que evita a necessidade de verificar se a 
igualdade entre os _hashes_ são ou não uma colisão. Considere que o número de 
caracteres `|A|` do alfabeto pode ser representado por `n` bits, e que uma
variável do tipo `long long` tenha 64 _bits_ de tamanho. Se o tamanho `m` do
padrão for menor ou igual a `64/n`, então a função `g` abaixo é um _hash_
perfeito.
```C++
ll g(const string& s, int pos, ll prev, int m, int n)
{
    ll res = 0;

    if (pos == 0)
    {
        for (int i = 0; i < m; ++i)
        {
            res <<= n;
            res |= idA(s[i]);
        }
    } else
    {
        ll mask = (1 << n*m) - 1;

        res = ((prev << n) | idA(s[pos + m - 1])) & mask;
    }

    return res;
}
```

No pior caso (por exemplo, onde o padrão e o texto consistem na repetição de
um mesmo caractere), o algoritmo de Karp-Rabin tem complexidade `O(nm)`. Se 
um _hash_ perfeito for utilizado, o algoritmo tem complexidade `O(n + m)`.
Na prática, para padrões grandes, é melhor utilizar o KMP: o algoritmo de
Rabin-Karp é uma alternativa mais adequada a padrões pequenos.

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

CROCHEMORE, Maxime; RYTTER, Wojciech. [Jewels of Stringology: Text Algorithms](http://site.ebrary.com/lib/univbrasilia/reader.action?docID=10201155), WSPC, 2002.
