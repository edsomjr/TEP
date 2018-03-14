# C++

## Tipos Nativos

A linguagem C++ conta com todos os tipos nativos da linguagem C, e alguns outros
tipos implementados nas bibliotecas pardões do C++. Dentre os
[tipos básicos](http://en.cppreference.com/w/cpp/language/types), vamos
encontrar os tipos:

* `void`: é um tipo vazio, sem elementos que possam representar ele. Não se pode
ter algum objeto do tipo `void`, pois ele é um tipo incompleto. Porém há a possibilidade
de utilizar o `void *` (ponteiro para void) como um tipo genérico de ponteiro. Assim como
o [malloc](http://en.cppreference.com/w/c/memory/malloc) faz.
* `bool`: é um tipo que pode assumir os valores `true` ou `false`, veradedeiro ou
falso, respectivamente.
* `char`: tipo integral que representa um caractere. Os valores dos caracteres
pertencem a [tabela ASCII](http://en.cppreference.com/w/cpp/language/ascii).
Podem ter os modificadores de `signed char` e `unsigned char`.
* `int`: tipo integral que representa números inteiros, sem parte fracionária. É
possível extender o seu tamanho com os modificadores: `long` e `long long`. E modificar
o seu sinal com: `unsigned` e `signed`.
* `float`: tipo ponto flutuante que representa números fracionários, com +-6 casas
de precisão. Este tipo não possui modificadores.
* `double`: tipo ponto flutuante que representa números fracionários, com +-15 casas
de precisão. O tamanho, e sua precisão, deste tipo podem ser expandidos pelo
modificador de tamanho: `long double`.

Além dos tipos básicos, o C++ conta com outros tipos que facilitam a elaboração
e implementação de alguns algoritmos. Como o tipo `string` e outros tipos da
[STL](STL.md).

### Limites

Assim como no C, as representações nos tipos básicos do C++ possuem limites. Quando
estes limites são desobedecidos, o comportamento não é definido. Por isso o C++
oferece dois meios para descobrir quais são os limites dos tipo na programação.

O primeiro meio é utilizando o [numeric_limits](http://en.cppreference.com/w/cpp/types/numeric_limits).
Que é uma classe genérica, que consegue inferir os valores de mínimo e máximo de
cada tipo. As funções utilizadas para saber o mínimo e máximo de um tipo, são a
funções `lowest` e `max`.

```cpp
// Limites do int
numeric_limits<int>::lowest();
numeric_limits<int>::max();

// Limites do unsigned long long int
numeric_limits<unsigned long long int>::lowest();
numeric_limits<unsigned long long int>::max();

// Limites do unsigned double
numeric_limits<double>::lowest();
numeric_limits<double>::max();
```

Outra função que pode ser utilizada com tipos de ponto flutante, `float` e `double`,
é a `epsilon`. A qual diz o quanto deve ser somado ao número para que ele alcance o
próximo número representavel para aquele tipo.

```cpp
1.0 + numeric_limits<double>::epsilon() > 1.0;
```

E caso seja necessário representar o infinito, para variáveis de ponto fluante,
existe a função `infinity`, que retorna o infinito positivo.

Os mesmos limites, variações e representações podem ser encontrados na biblioteca
`climits` da linguagem C. A qual possui várias macros para cada tipo. Consulte
a [documentação](http://en.cppreference.com/w/cpp/types/climits) para um maior
detalhamento das macros.

|          Tipo          |                          Limites                         |  Aproximação 10 |
|:----------------------:|:--------------------------------------------------------:|:---------------:|
|          char          |                       -127 até 127                       | 10<sup>2</sup>  |
|      unsigned char     |                         0 até 255                        | 10<sup>2</sup>  |
|           int          |             -2,147,483,647 até 2,147,483,647             | 10<sup>9</sup>  |
|      unsigned int      |                    0 até 4,294,967,295                   | 10<sup>9</sup>  |
|      long long int     | -9,223,372,036,854,775,807 até 9,223,372,036,854,775,807 | 10<sup>19</sup> |
| unsigned long long int |             0 até 18,446,744,073,709,551,615             | 10<sup>20</sup> |
|          float         |               -3.40282e+38 até 3.40282e+38               |                 |
|         double         |              -1.79769e+308 até 1.79769e+308              |                 |
|       long double      |             -1.18973e+4932 até 1.18973e+4932             |                 |

### Dicas

#### Dê preferencia ao inteiro

Ao realizar operações aritiméticas com um ponto flutuante, a cada operação um erro
associado a precisão do tipo modifica o resultado real da operação. Por isso deve
se evitar tipos ponto fluantes, e utilizar, sempre que possível, tipos integrais.

Problemas que trabalham com ponto fluantes, por exemplo, problemas que falam de
distância, peso, altura, dinheiro, entre outros. Podem ser resolvidos com uma
conversão para a menor unidade. Por exemplo, se o problema pediu para você ler o
valor do dinheiro `123.45`, tudo pode ser lido como inteiro e convertido para
centavos, que é a menor unidade neste contexto.

```cpp
// Lendo como inteiro e convertendo para centavos
scanf("%d.%d", &reais, &centavos);
centavos += reais * 100;
```

#### Utilize a maior precisão possivel

Para tipos ponto fluante, nunca utilize o `float`, pois a precisão dele é muito
baixa. Dê preferência para o `double` ou `long double`, pois os erros de precisão
vão te afetar menos. Ambos não estão livres de erros de precisão, porém como possuem
uma precisão maior, estes erros não efetam muito a resposta final.



### String

O tipo [string](http://en.cppreference.com/w/cpp/string/basic_string) do C++ é
uma implementação alto nível do array de caracteres do C. Ele possui várias métodos
prontos para a manipulação das strings.

A string oferece vários métodos para criar uma string, este são chamados de métodos
construtores. Dentre estes métodos, existem 3 que são mais utilizados em maratonas
de programação.

```cpp
// Construtor Padrão
string nome("Nome Completo");
string nome = "Nome Completo";

// Construtor de Cópia
string nome2(nome);
string nome2 = nome;

// Construtor via array de char
char curso_em_c[] = "Linguagem C";
string curso(curso_em_c);

// Construtor de repetição
string ddd(3, 'D'); // Gera a string "DDD"

```

* Construtor Padrão: o seu argumento é a string desejada entre aspas duplas.
O mesmo resultado pode ser atingido com o operador de atribuição `=`.
* Construtor de Cópia: o seu argumento é outra string, a qual é copiada para a
string nova. O que também pode ser feito com o operador de atribuição `=`.
* Construtor via array de char: neste construtor você passa uma array de char,
ou seja, uma string na linguagem C, e ele cria uma string em C++.
* Construtor de repetição: neste Construtor você passa 2 argumentos, o número de
vezes que você quer que repita o `char` do segundo argumento. Isso faz com que
uma string com aquele `char` repetido `n` vezes seja criada.

Para modificar uma string, pode-se utilizar diversos métodos.

```cpp
// Mudando o quinto caractere da string para 'a'
nome[4] = 'a';

// Removendo o ultimo caractere da string
nome.pop_back();

// Adicionando um caractere ao final da string
nome.push_back('a')

// Somando string
nome += "Completo";
nome = nome + "Completo";
nome.append("Completo");
```

Para saber o tamanho da string, existe o método `size`. Com ele você pode iterar
sob a string.

```cpp
for (int i = 0; i < nome.size(); ++i)
    cout << nome[i] << endl;
```

Você também pode comparar duas strings, para saber se elas são iguais ou diferentes.
E também para saber se uma string é menor que outra em ordem lexicográfica. Todos os
operadores relacionais funcionam com a string.

```cpp
nome == sobrenome;
nome != sobrenome;

nome < sobrenome;
nome > sobrenome;
```

Para converter uma string em inteiro e outros tipos, existem as funções:

```cpp
stoi("123");     // string para int
stoll("123");    // string para long long int
stoull("123");   // string para unsigned long long int
stof("123.45");  // string para float
stod("123.45");  // string para double
stold("123.45"); // string para long double
```

Já para converter de qualqer tipo para string, pode ser usar a função `to_string`.
Se o tipo tiver uma representação em string, então ele será convertido. Por exemplo,
`to_string(123)`, será convertido para a string `"123"`.

### Criando o seus próprios tipos

O C++ 11 introduziu uma semantica para a criação de tipo, além de classes e structs.
Utilizando a palavra reservada `using`, é possível criar um tipo com nome
customizado, baseado em um tipo existente. Com isso você pode ter código mais
claros e objetivos, sem tipos muito longos atrapalhando a leitura.

```cpp
using lld = long long int;
using ld = long double;
using meu_tipo = unsigned long long int;

lld y = 32;
ld z = 32.45;
meu_tipo x = 123678;
```

### Inferindo tipos

Outra __feature__ adicionada no C++ 11 foi o uso da palavra reservada `auto`.
Que permite que você infira qual o tipo da variável dada a expressão. Com isso
você não precisa escrever o tipo dela, você só declara ela como `auto`.

```cpp
auto nome = "Roberto"; // nome é inferido como um tipo string

vector<int> v;
auto it = v.begin(); // it é inferido como um tipo vector<int>::iterator
```

O uso da inferência de tipos ajuda a escrita e flexibilização do seu código.
Ajuda na escrita, pois você não precisa lembrar e escrever tipo muito grandes e
verbosos demais. E ajuda na flexibilização, pois se você precisar alterar, por exemplo,
o `vector<int>` para `vector<string>`, o auto já vai inferir o novo tipo para você,
ao invês de você ter que trocar de `vector<int>::iterator` para
`vector<string>::iterator`.


## Exercícios

1. UVA
    1. [694 - The Collatz Sequence](https://uva.onlinejudge.org/external/6/694.pdf)
    1. [10591 - Happy Number](https://uva.onlinejudge.org/external/105/10591.pdf)
    1. [490 - Rotating Sentences](https://uva.onlinejudge.org/external/4/490.pdf)
    1. [10260 - Soundex](https://uva.onlinejudge.org/external/102/10260.pdf)
1. URI
    1. [1768 - Christmas Tree](https://www.urionlinejudge.com.br/judge/en/problems/view/1768)
    1. [1196 - WERTYU](https://www.urionlinejudge.com.br/judge/en/problems/view/1196)

## Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

C++ Reference [Basic String](http://en.cppreference.com/w/cpp/string/basic_string)

C++ Reference [Fundamental Types](http://en.cppreference.com/w/cpp/language/types)
