Representação de Strings
========================

Embora uma string seja definida como uma sequência de caracteres de um dado
alfabeto, cada linguagem de programação implementa strings de uma forma
particular, com determinadas vantagens e desvantagens. Em geral, as bibliotecas
padrão das linguagens oferecem várias funções para manipulação de strings.

### C

Em C, uma string é implementada como um array de caracteres terminado em zero
(`\0`). Esta implementação é a mais sintética o possível em termos de memória:
é reservado espaço apenas para armazenar os caracteres da string mais o
terminador `\0`. Em contrapartida, a ausência deste marcador pode levar a
execução errônea de várias das funções de strings, além de que rotinas simples,
como determinar o tamanho da string, tem complexidade `O(n)`,
contrastando com as implementações que utilizam memória adicional e que podem
retornar o tamanho em `O(1)`.

Abaixo segue um exemplo de declaração e inicialização de um string em C.

```C
char s1[101];
char s2[] = "Test";
```

A strings `s1`, não inicializada, comporta até 100 caracteres (mais o terminador); já a string `s2`, inicializada com o valor `"Test"`, não exige que seja
informado o número de caracteres (o compilador completa esta informação
automaticamente).

Importante notar que, devido a aritmética de ponteiros da linguagem, as strings
em C tem como primeiro elemento indexado em zero, não em um. Assim, `s[2]`
representa o terceiro, e não o segundo, elemento da string.

A biblioteca padrão do C oferece o cabeçalho `string.h`, onde são declaradas
várias funções para a manipulação de strings, e o cabeçalho `stdlib.h`, que
traz funções para conversão de strings para valores numéricos. Algumas destas
funções são ilustradas no código abaixo.
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[50] = "Test";
    char b[] = "TEP";
    char *p;

    double d;
    int i;
    long long ll;

    // Tamanho da string
    int s = strlen(a);      // s = 4, zero terminador não é computado
    s = strlen(b);          // s = 3

    // Comparação
    s = strcmp(a, b);       // s > 0, "Test" sucede "TEP" na ordem lexicográfica
    s = strcmp(b, a);       // s < 0, "TEP" precede "Test" na ordem lexicográfica

    s = strncmp(a, b, 1);   // s = 0, as strings são iguais no primeiro caractere
    s = strncmp(a, b, 2);   // s > 0, "Te" sucede "TE" na ordem lexicográfica

    // Cópia
    strcpy(a, b);           // a = "TEP"
    strncpy(a, "SA", 2);    // a = "SAP"

    // Acesso aos elementos individuais
    a[2] = 'T';             // a = "SAT"
    a[0] = b[2];            // a = "PAT"

    // Conversão de string para valores numéricos
    strcpy(a, "123.45");
    d = atof(a);            // d = 123.45
    i = atoi(a);            // i = 123

    strcpy(a, "10000000000000000000000000000000000000000");
    ll = strtoll(a, NULL, 2);   // ll = 1099511627776, conversão de base binária

    // Concatenação
    strcpy(b, "xyz");       // b = "xyz"
    strcpy(a, "abcba");     // a = "abcba"

    strcat(a, b);           // a = "abcbaxyz"
    strncat(a, a, 3);       // a = "abcbaxyzabc"

    // Busca de caracteres
    p = strchr(a, 'b');     // p - a = 1, índice da primeira ocorrência de 'b'
    p = strrchr(a, 'b');    // p - a = 9, índice da última ocorrência de 'b'
    p = strstr(a, "cba");   // p - a = 2, índice da primeira coorrência de "cba"
    p = strstr(a, "dd");    // p = NULL, "dd" não é substring de a

    i = strspn(a, "abc");   // i = 5, a[0..4] contém apenas caracteres em "abc"
    i = strcspn(a, "z");    // i = 7, a[0..6] contém caracteres diferentes de "z"

    return 0;
}
```

Interessante notar que, neste mesmo cabeçalho, são definidas três funções que
permitem manipular a memória (`memcmp(), memset(), memcpy()`), através de
comparações, atribuições e cópia, respectivamente.

Outro cabeçalho útil para a manipulação de strings em C é o `ctype.h`, onde
são definidas funções para a manipulação de caracteres. Algumas destas funções
são ilustradas abaixo.

```C
#include <stdio.h>
#include <ctype.h>

int main()
{
    char a[] = "Test with numbers: 0x1234";
    int r;

    a[0] = tolower(a[0]);       // a = "test with numbers: 0x1234"
    a[10] = toupper(a[10]);     // a = "test with Numbers: 0x1234"

    r = isalpha(a[0]);          // r > 0, 't' é alfabético
    r = isalpha(a[19]);         // r = 0, '0' não é alfabético
    r = isalnum(a[19]);         // r > 0, '0' não é alfanumérico
    r = isblank(a[18]);         // r = 0, ' ' é um espaço em branco
    r = isdigit(a[1]);          // r = 0, 'e' não é um dígito decimal
    r = isxdigit(a[1]);         // r > 0, 'e' é um dígito hexadecimal

    return 0;
}
```

C++
---

Embora seja possível utilizar a abordagem e as bibliotecas citadas anteriormente
para a linguagem C em C++, existe uma representação em C++ de strings baseada
em classes. O uso de classes para representar strings traz a vantagem de poder
manter outras informações sobre a string sempre atualizadas e com acesso em
`O(1)`; por outro lado, esta representação demanda mais memória do que a 
representação em C. Existem técnicas para tentar reduzir a memória utilizada,
como a _Small String Optimization_.

A classe fundamental dentre as várias classes que representam strings em C++
é a `std::string`. O seu comportamento e seus principais métodos são ilustrados
no código abaixo.
```C
#include <iostream>

using namespace std;

int main()
{
    string a = "Test";
    string b = "TEP";

    // Tamanho da string
    auto s = a.size();      // s = 4, zero terminador não é computado
    s = b.size();           // s = 3

    // Comparação
    auto r = (a == b);      // r = false, "Test" e "TEP" são distintas
    r = (a != b);           // r = true, "Test" e "TEP" são distintas
    r = (a < b);            // r = false, "Test" sucede "TE" na ordem lexicográfica
    r = (a > b);            // r = true, "Test" sucede "TE" na ordem lexicográfica

    s = strncmp(a, b, 1);   // s = 0, as strings são iguais no primeiro caractere
    s = strncmp(a, b, 2);   // s > 0, "Te" sucede "TE" na ordem lexicográfica

    // Cópia
    a = b;                  // a = "TEP"

    // Acesso aos elementos individuais
    a[1] = 'A';             // a = "TAP"
    auto c = a.front();     // c = 'T', primeiro elemento
    c = a.back();           // c = 'P', último elemento

    // Conversão de string para valores numéricos
    a = "123.45";
    auto d = stod(a);       // d = 123.45;
    auto i = stoi(a);       // i = 123

    a = "10000000000000000000000000000000000000000";
    auto ll = stoll(a, NULL, 2);   // ll = 1099511627776, conversão de base binária

    // Conversão de valores numéricos para strings
    a = to_string(999);     // a = "999"
    a = to_string(9.99);    // a = "9.99"

    // Concatenação
    b = "xyz";              // b = "xyz"
    a = "abcba";            // a = "abcba"

    a +=  b;                // a = "abcbaxyz"
    a += a.substr(0, 3);    // a = "abcbaxyzabc"

    // Busca de caracteres
    auto p = a.find('b');   // p = 1, índice da primeira ocorrência de 'b'
    p = a.rfind('b');       // p = 9, índice da última ocorrência de 'b'
    p = a.find("cba");      // p = 2, índice da primeira coorrência de "cba"
    p = a.find("dd");       // p = string::npos, "dd" não é substring de a

    p = a.find_first_not_of("abc");     // i = 5, a[0..4] contém apenas caracteres em "abc"
    p = a.find_first_of("z");           // i = 7, a[0..6] contém caracteres diferentes de "z"

    return 0;
}
```

O método `c_str()` permite obter, a partir de uma string C++, uma representação 
compatível com a utilizada em C. Deste modo, é possível utilizar funções 
escritas para strings em C a partir de instâncias C++, como no exemplo abaixo.
```C++
#include <iostream>

using namespace std;

int main()
{
    string a = "Test";

    printf("%s\n", a.c_str());

    return 0;
}
```

Python
------

Embora as strings em Python também sejam implementadas através de classes,
elas podem ser vistas informalmente como listas de caracteres. Para maratonas
de programação, o módulo `string` do python traz constantes bastantes úteis,
que trazem listagens de caracteres comuns. O trecho abaixo ilustra algumas delas.
```Python
import string

a = string.lowercase        // a = 'abcdefghijklmnopqrstuvwxyz'
b = string.uppercase        // b = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
c = string.letters          // c = a + b
d = string.digits           // d = '0123456789'
x = string.hexdigits        // x = '0123456789abcdefABCDEF'
```

Mesmo que a solução proposta pela equipe seja escrita em outra linguagem,
estas constantes podem ser facilmente acessadas via terminal, importando o módulo
e usando o comando (ou função, no Python 3) `print`.

Outra particularidade do Python é que, ao contrário das linguagens C e C++, ele
suporta índices negativos para strings. Por exemplo, `s[-1]` se refere ao
último caractere, `s[-2]` ao penúltimo, e assim por diante. Outra notação útil
é `s[::-1]`, que indica o reverso da string `s` (isto é, `s` lida do fim para o
começo).

A API para strings em Python contempla ainda muitas outras funções úteis, como
`strip(), join()` e `split()`, cuja exemplificação foge ao escopo deste texto.

I/O
---

Cada linguagem tem mecanismos apropriados para a leitura e escritas de 
strings a partir do terminal. Em C, são utilizadas as funções `printf()` e
`scanf()`:
```C
#include <stdio.h>

int main()
{
    char s[1024];

    scanf("%s", s);

    printf("s = [%s]\n", s);

    return 0;
}
```

A função `scanf()` fará a leitura da entrada até encontrar um caractere de 
espaço (quebra de linha, tabulações, espaço em branco, etc). Se a intenção é
ler uma linha na íntegra, deve ser utilizada a função `fgets()`.
```C
#include <stdio.h>

int main()
{
    char line[1024];

    fgets(line, 1024, stdin);

    printf("s = [%s]\n", s);

    return 0;
}
```

A função `fgets()` é mais segura que a `scanf()`, pois utiliza o segundo
parâmetro como limite máximo de caracteres (mais o zero terminador) a serem
lidos e escritos no primeiro parâmetro. Vale notar que a função `fgets()` 
insere, no primeiro parâmetro, o caractere de nova linha, se o encontrar 
(a função também termina se for encontrado o caractere `EOF`, que indica o fim 
do arquivo).

Em C++, strings podem ser lidas e escritas com os operadores `<<`  e `>>` das
classes `cin` e `cout`, respectivamente:
```C++
#include <iostream>

using namespace std;

int main()
{
    string s;

    cin >> s;
    cout << s;

    return 0;
}
```

A classe `cin` se comporta de forma semelhante à função `scanf()`, lendo a 
entrada até encontrar um caractere que indique um espaço em branco. Para ler
linhas inteiras, de forma semelhante à `fgets()`, basta usar a função
`getline()`:
```C++
#include <iostream>

using namespace std;

int main()
{
    string line;

    getline(cin, line);

    cout << line;

    return 0;
}
```

Porém, diferentemente da função `fgets()`, a função `getline()` despreza o 
caractere de fim de linha, e não o insere na string apontada pelo segundo
parâmetro.

### Referências

AHLGREN, John. [Small String Optimization and Move Operations](http://john-ahlgren.blogspot.com.br/2012/03/small-string-optimization-and-move.html). Acesso em 16/12/2016.

CPPREFERENCE. [Null-terminated byte strings](http://en.cppreference.com/w/cpp/string/byte). Acesso em 21/12/2016.

CPPREFERENCE. [std::basic_string](http://en.cppreference.com/w/cpp/string/basic_string). Acesso em 21/12/2016.

CROCHEMORE, Maxime; RYTTER, Wojciech. [Jewels of Stringology: Text Algorithms](http://site.ebrary.com/lib/univbrasilia/reader.action?docID=10201155), WSPC, 2002.

DAVID. [A look at std::string implementations in C++](http://info.prelert.com/blog/cpp-stdstring-implementations). Acesso em 22/12/2016.

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

PYTHON DOCUMENTATION. [Common string operations](https://docs.python.org/2/library/string.html). Acesso em 26/12/16.

