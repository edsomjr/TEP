Programação Dinâmica
====================

Vários problemas relacionados às strings podem ser resolvidos com o uso de
Programação Dinâmica.

Edit Distance
-------------

Sejam `s` e `t` duas strings, com `s != t`. Quando comparadas por meio de um
algoritmo de _matching_, dentre os motivos que levam o algoritmo a retornar 
falso estão:

1. ambas strings tem mesmo tamanho, mas diferem em um ou mais símbolos. Por 
exemplo,

        s = "banana"
        t = "bacana"

onde `s[2] != t[2]`;

1. a primeira string é mais longa que a segunda, e poderíam se tornar iguais se
removidos os caracteres excedentes. Por exemplo, se

        s = 'aspectos'
        r = 'seco'

então `s == r` se removidos os caracteres das posições 0, 2, 4 e 6 de `s`;

1. a primeira string é mais curta do que a segunda, e poderia se igualar a 
primeira se adicionados os caracateres ausentes. Por exemplo,

        s = 'fga'
        r = 'formigas'

se tornariam iguais com a adição dos caracteres `ormis` em `s`, nas devidas 
posições.

Na prática, é possível obter qualquer string `r` a partir de uma string `s` 
dada, usando uma sequência finita das operações descritas acima (alterar um
caractere, adicionar um caractere ou remover um caractere). O problema
denominado _edit distance_ consiste em determinar o número mínimo de operações a
serem feitas (ou, em termos mais gerais, o custo mínimo desta transformação, se
a cada operação for associado um determinado custo).

Se denotarmos `edit(s, t)` como o menor número de operações que transforma
`s` em `t` teremos as seguintes propriedades:

1. `edit(s, t) >= 0`
1. `edit(s, t) = 0` se, e somente se, `s = t`
1. `edit(s, t) = edit(t, s)` (simetria)
1. `edit(s, t) <= edit(s, r) + edit(r, t)` (desigualdade triangular)

Considere que `|s| = m, |t| = n`. Para determinar `edit(s, t)`, devemos 
construir uma tabela auxiliar de estados `st`, onde `st(i, j) = edit(s[1..i],
t[1..j]`, com `0 < i <= m, 0 < j <= n`. O casos bases acontecem quando uma das
duas strings é vazia: nestes casos, o mínimo de operações a serem feitas é igual
um número de inserções correspondente ao tamanho da string não vazia. Em notação
simbólica,

        st(0, j) = j, st(i, 0) = i

Se os custos de inserção, de remoção e de alteração forem `c_i, c_r, c_s`,
respectivamente, então os casos bases devem ser 

        st(0, j) = j*c_i    // j inserções
        st(i, 0) = i*c_r    // i remoções

A transição entre os estados será, dentre as três operações, a de menor custo.
uma transição por inserção seria dada por

        st(i, j) = st(i, j - 1) + c_i,      // Adicionar t[j]

por remoção seria

        st(i, j) = st(i - 1, j) + c_r,      // Remover s[i]

e por alteração seria

        // Mantém s[i] ou substitui s[i] por t[j]
        st(i, j) = st(i - 1, j - 1) + c_s * (s[i] == t[j] ? 0 : 1)   

Assim,

        st(i, j) = min(st(i, j - 1) + c_i,
                       st(i - 1, j) + c_r, 
                       st(i - 1, j - 1) + c_s * (s[i] == t[j] ? 0 : 1)
                   )

Como a tabela tem `mn` estados, e cada transição é feita em `O(1)`, o algoritmo
tem complexidade `O(mn)`.

Abaixo uma implementação _bottom-up_ em C++. Recorde que, em C++, as strings 
são indexadas a partir de zero, e não um, como na notação anterior. Desta
forma, no código abaixo `st[i][j]` significa o custo mínimo para transformar 
`s.substr(i)` em `t.substr(j)`.

```C++
#define MAX_M   1000
#define MAX_N   1000

int st[MAX_M][MAX_N];
int c_i = 1, c_r = 1, c_s = 1;      // Custos iguais a um

int edit(const string& s, const string& r)
{
    int m = s.size();
    int n = r.size();

    for (int i = 0; i <= m; ++i)
        st[i][0] = i*c_r;

    for (int j = 1; j <= n; ++j)
        st[0][j] = j*c_i;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int insertion = st[i][j - 1] + c_i;
            int deletion = st[i - 1][j] + c_r; 
            int change = st[i - 1][j - 1] + c_s * (s[i - 1] == t[j - 1] ? 0 : 1);
            st[i][j] = min(insertion, deletion);
            st[i][j] = min(st[i][j], change);
        }
                       
    return st[m][n];
}
```

Observe que a implementação acima tem custo de memória `O(mn)`. É possível
implementar o mesmo algoritmo usando apenas `O(n)` de memória, uma vez que
é necesário apenas a linha anterior para computar os valores da próxima
linha.
```C++
#define MAX_N   1000

int a[MAX_N], b[MAX_N];
int c_i = 1, c_r = 1, c_s = 1;      // Custos iguais a um

// Implementação _bottom-up_, O(mn), memória O(n)
int edit2(const string& s, const string& t)
{
    int m = s.size();
    int n = t.size();

    int *prev = a, *line = b;

    for (int j = 0; j <= n; ++j)
        prev[j] = j*c_i;

    for (int i = 1; i <= m; ++i)
    {
        line[0] = i*c_r;

        for (int j = 1; j <= n; ++j)
        {
            int insertion = line[j - 1] + c_i;
            int deletion = prev[j] + c_r; 
            int change = prev[j - 1] + c_s * (s[i - 1] == t[j - 1] ? 0 : 1);
            line[j] = min(insertion, deletion);
            line[j] = min(line[j], change);
        }

        swap(line, prev);
    }

    return prev[n];
}
```

Esta segunda implementação pode ser necessária em competições com limites de
memória restritos. Porém, esta implementação torna deveras mais complicado 
determinar as operações necessárias para se obter `t` a partir de `s`: na 
primeira implementação, basta manter um registro da operação responsável pela
atualização de cada elemento da tabela `st`, conforme apresentado no código 
abaixo.
```C++
// x        Deletion
// c        Insertion of char c
// -        Keep
// [c->d]   Change (c to d)
string edit_operations(const string& s, const string& t)
{
    int m = s.size();
    int n = t.size();

    for (int i = 0; i <= m; ++i)
    {
        st[i][0] = i*c_r;
        ps[i][0] = 'r';
    }

    for (int j = 1; j <= n; ++j)
    {
        st[0][j] = j*c_i;
        ps[0][j] = 'i';
    }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int insertion = st[i][j - 1] + c_i;
            int deletion = st[i - 1][j] + c_r; 
            int change = st[i - 1][j - 1] + c_s * (s[i - 1] == t[j - 1] ? 0 : 1);

            st[i][j] = min(insertion, deletion);
            st[i][j] = min(st[i][j], change);

            if (insertion <= deletion and insertion <= change)
                ps[i][j] = 'i';
            else if (deletion <= change)
                ps[i][j] = 'r';
            else
                ps[i][j] = 's';
        }

    int i = m, j = n;
    stack<string> S;
    char buffer[128];
    string subs = "[x->y]";

    while (i or j)
    {
        switch (ps[i][j]) {
        case 'i':
            sprintf(buffer, "%c", t[j - 1]);
            --j;
            break;

        case 'r':
            sprintf(buffer, "x");
            --i;
            break;

        case 's':
            if (s[i-1] == t[j-1])
                sprintf(buffer, "-");
            else
                sprintf(buffer, "[%c->%c]", s[i - 1], t[j - 1]);

            --i;
            --j;
        }

        S.push(buffer);
    }

    ostringstream os;

    while (not S.empty())
    {
        os << S.top();
        S.pop();
    }

    return os.str();
}
```

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

CROCHEMORE, Maxime; RYTTER, Wojciech. [Jewels of Stringology: Text Algorithms](http://site.ebrary.com/lib/univbrasilia/reader.action?docID=10201155), WSPC, 2002.
