# Standard Template Library

A **STL** (Standard Template Library) é a biblioteca padrão do C++, que conta com
implementações genéricas de vários algoritmos, estruturas de dados, iteradores e
__functors__. Esta implementação genérica permite utilizar a biblioteca para qualquer
tipo nativo do C++, assim como qualquer tipo definido pelo usuário com o mínimo de
__overhead__. Pois a STL realiza o polimorfismo durante a compilação, evitando
realizar durante a execução, para que uma maior performance seja extraída da biblioteca.

Ela possui a implementação nativa de vários
[containers](http://en.cppreference.com/w/cpp/container) (estruturas de dados).
Eles servem para guardar e organizar os dados de maneira eficiente. Cada __container__
vai ter uma complexidade diferente para: inserção, procura, __query__, remoção e atualização.
Eles são classificados em:

1. Estruturas Lineares
   1. [Vector](#vector)
   1. [Stack](#stack)
   1. [Queue](#queue)
   1. [Pair](#pair)
   1. [Bitset](#bitset)
   1. [List](#list)
   1. Deque
   1. Array
1. Estruturas Não-Lineares
   1. [Map](#map)
   1. [Set](#set)
   1. [Priority Queue](#priority-queue)
   1. [Unordered Map](#unordered-map)
   1. [Unordered Set](#unordered-set)
   1. Multimap
   1. Multiset

A STL também possui a implementação genérica de vários
[algoritmos](http://en.cppreference.com/w/cpp/algorithm). Onde a ordem
de complexidade destes pode ser achada na documentação de cada um. A seguir há
uma breve lista de alguns que existe na STL.

1. [Algoritmos de Min e Max: min, max, minmax](#algoritmos-de-min-e-max)
1. [Algoritmos de Modificação: swap, reverse](#algoritmos-de-modificação)
1. [Algoritmos de Busca: lower_bound, upper_bound, binary_search](#algoritmos-de-busca)
1. [Algoritmos de Ordenação: sort, stable_sort](#algoritmos-de-ordenação)
1. [Algoritmos de Permutação: next_permutation, prev_permutation](#algoritmos-de-permutação)

## Estruturas Lineares

### Vector

O [vector](http://en.cppreference.com/w/cpp/container/vector) é uma estrutura de
dados muito semelhante ao `array`. Ele guarda todos os seus elementos de forma
contínua na memória. O que diferencia ele do `array` é que ele lida melhor com
a expanção do seu próprio tamanho. Se o seu tamanho chegar a capacidade máxima,
ele irá expandir sua capacidade automaticamente para poder guardar mais elementos.

A construção de um `vector` pode ser feita de várias maneiras.

```cpp
// vector vazio
vector<double> v_fracoes;

// Lista de Inicialização
vector<int> v_numeros {4, 8, 15, 16, 23, 42};

// Criação por repetição
vector<string> v_str (5, "casa"); // v_str = {"casa", "casa", "casa", "casa", "casa"}

// Criação por cópia
vector<string> v_str_copy = v_str;
```

Para acessar um elemento em seu vector, existem a funções: `front`, `back` e `[]`.

```cpp
vector<int> v_numeros {4, 8, 15, 16, 23, 42};

v_numeros.front(); // 4
v_numeros.back();  // 42

for(int i = 0; i < v_numeros.size(); ++i) {
    cout << v[i] << " ";
}

// Range-based for - Passa por todos os elementos do vector também
for(auto v_numero: v_numeros) {
    cout << v_numero << " ";
}
```

Para modificar o vector, pode-se utilizar as funções: `clear`, `push_back` e `pop_back`.
Todos eles possuem complexidades constantes, `O(1)`. Existem outras funções de modificação
como o `insert` e o `erase`, porém eles possuem uma complexidade linear, `O(n)`.

```cpp
vector<int> v_numeros {4, 8, 15, 16, 23, 42};

// Adicionar um elemento no fim do vector
v_numeros.push_back(108); // v = {4, 8, 15, 16, 23, 42, 108};

// Remover um elemento no fim do vector
v_numeros.pop_back(); // v = {4, 8, 15, 16, 23, 42};
v_numeros.pop_back(); // v = {4, 8, 15, 16, 23};

// Remover todos os elementos de vector
v_numeros.clear(); // v = {}
```

Existem alguns métodos de comparação e perguntas que podem ser utilizados no
vector.

```cpp
vector<int> v_numeros {4, 8, 15, 16, 23, 42};
vector<int> v_idades {20, 40, 12, 13, 12, 44};
vector<string> nomes;

// Checar se dois vectors são iguais
v_numeros == v_idades;
v_numeros != v_idades;

// Tamanho do vector
v_numeros.size();
v_idades.size();
nomes.size();

// Checar se um vector está vazio ou não;
v_numeros.empty();
v_idades.empty();
nomes.empty();
```

### Stack

A [stack](http://en.cppreference.com/w/cpp/container/stack) é uma estrutura de dados
do tipo **LIFO** (Last-In First-Out), o último que entrou é o primeiro a sair. Ela
funciona como uma pilha de elementos. Quando um elemento é colocado na `stack` ele
é inserido no topo desta. Se outro elemento for inserido, ele vai ser inserido sobre
o elemento anterior, impossibilitando que o elemento anterior seja removido antes
deste novo. Na remoção de elementos, o último elemento inserido é o **único** que
pode ser removido. Após a remoção deste, o penúltimo pode ser removido agora.

O único elemento conhecido de uma `stack` é o topo, pois é o elemento que está "visível".
Todos os outros estão embaixo deste, por isso não podem ser vistos.

![Stack](stack.jpg)

```cpp
// Contrução de uma stack
stack<string> nomes;

// Empilhamento de um elemento
nomes.push("Ola");
nomes.push("Mundo");
nomes.push("!");
// Estado da pilha: [Fundo] Ola Mundo ! [Topo]

// Acessando o topo da pilha
cout << nomes.top(); // "!"

// Desempilhamento de um elemento
nomes.pop(); // Saindo o "!"
nomes.pop(); // Saindo o "Mundo"
// Estado da pilha: [Fundo] Ola [Topo]

// Tamanho da stack
nomes.size();

// A stack esta vazia?
nomes.empty();
```

### Queue

A [queue](http://en.cppreference.com/w/cpp/container/queue) é uma estrutura de dados
do tipo **FIFO** (First-In First-Out), o primeiro a entrar é o primeiro a sair.
Ela funciona como uma fila de elementos. Quando um elemento é enfileirado (adcionado)
na `queue` ele ocupa a primeira posição. Quando o próximo elemento for colocado,
ele vai ser enfileirado após o primeiro.Na remoção, o primeiro elemento a sair,
é o primeiro elemento que foi enfileirado. O segundo elemento enfileirado, só
pode sair após o primeiro ter sido removido.

Os elementos que podem ser vistos de uma fila, são a frente e as costas da fila.
Todos os elementos do meio da fila não podem ser visualizados.

![Queue](queue.png)

```cpp
// Construção da queue
queue<string> nomes;

// Enfileirando um elemento
nomes.push("Ola");
nomes.push("Mundo");
nomes.push("!");
// Estado da fila: [Costas] ! Mundo Ola [Frente]

// Vendo as costas e a frente
nomes.back();   // "!"
nomes.front();  // "Ola"

// Desenfileirando elementos
nomes.pop();
nomes.pop();
// Estado da fila: [Costas] ! [Frente]

// Tamanho da fila
nomes.size();

// A fila está vazia?
nomes.empty();
```

### Pair

O [pair](http://en.cppreference.com/w/cpp/utility/pair) é uma estrutra que guarda
dois valores de qualquer tipo. O tipo do primeiro valor, pode ser diferente do tipo
do segundo valor.

Para construir um `pair`, ou se usa o método construtor do `pair` ou se usa a função
`make_pair`.

```cpp
// Criação via método construtor
pair<string, double> nome_peso("Carlos", 65.6);

// Criação via make_pair
pair<string, double> nome_altura;
nome_altura = make_pair("Jhon", 2.0);

// Criação via método construtor do tipo
nome_altura = pair<string, double>("Maria", 1.8);
```

Para abreviar a criação do `pair`, é comum em maratonas utilizar o `using` para
criar um novo tipo. E então utilizar o construtor do tipo para criar o `pair`.

```cpp
using ii = pair<int, int>;

ii indice_peso; // Tipo pair<int, int>

// Criação via método construtor do tipo
indice_peso = ii(32, 40);
// Igual a indice_peso = pair<int, int>(32, 40);
```

O `pair` possui dois membros públicos: `first` e `second`. Que acessam o primeiro
e o segundo elemento do `pair`, respectivamente.

```cpp
using ii = pair<int, int>;
ii indice_peso(32, 40);

indice_peso.first;  // 32
indice_peso.second; // 40

// Alterando o primeiro elemento
indice_peso.first = 50;
```

### Bitset

O [bitset](http://en.cppreference.com/w/cpp/utility/bitset) representa um número
fixo de N bits. Ele guarda a representação em bits de algum número. Ele é muito
útil para operçaões e conversões binárias, pois ele suporta não só a conversão
para binário, mas a conversão de binário para `unsigned long int`. E ele pode ser
utilizado nativamente em qualquer operação binária.

Para criar um `bitset` você deve indicar quantos bits ele vai guardar.

```cpp
// Construtor vazio
bitset<8> b1;   // [0,0,0,0,0,0,0,0]
bitset<10> b10; // [0,0,0,0,0,0,0,0,0,0]
bitset<15> b11; // [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

// Construtor com um unsigned long long
bitset<8> b2(42); // [0,0,1,0,1,0,1,0]

// Construtor com uma string
string binario = "110010";
bitset<8> b3(binario); // [0,0,1,1,0,0,1,0]

// Construtor com bits customizados
bitset<8> b4("XXXXYYYY", 8, 'X', 'Y'); // [0,0,0,0,1,1,1,1]
```

Para acessar os bits existem dois métodos, o operador de `[]` e o método `test`.
No operador de `[]` você indica a posição do bit que você quer acessar. Sendo
`0` o bit menos significativo. Com ele, você também pode modificar o valor do bit
naquela posição. O outro método, é o `test`, ele diz se o bit da posição está
ligado, `true`, ou desligado, `false`.

```cpp
bitset<8> b(42); // [0,0,1,0,1,0,1,0]

b[0]; // 0
b[1]; // 1
b[2]; // 0
b[3]; // 1
b[4]; // 0
b[5]; // 1
b[6]; // 0
b[7]; // 0

b[5] = false; // 00001010

b.test(1); // true
b.test(0); // false
```

Também é possível modificar o `bitset` com os métodos: `set`, `reset` e `flip`.
O `set` liga todos os bits, ou liga uma posição específica. O `reset` desliga
todos os bits, ou desliga uma posição específica. O `flip` inverte todos os bits,
ou inverte uma posição específica.

```cpp
bitset<8> b(42); // [0,0,1,0,1,0,1,0]

b.flip();   // 11010101
b.flip(0);  // 11010100

b.set();    // 11111111
b.reset();  // 00000000

b.set(1);   // 00000010
b.set(3);   // 00001010
b.reset(1); // 00001000
```

Existe alguns métodos que permitem fazer perguntas ao bitset. O método `all`
pergunta se todos os bits estão ligados. O método `none` pergunta se todos os
bits estão deligados. O método `any` checa se algum bit está ligado. Além destes
métodos, existe o método `count`, que conta quantos bits estão ligados.

```cpp
bitset<8> b(42); // [0,0,1,0,1,0,1,0]

b.all();   // false
b.any();   // true
b.none();  // false
b.count(); // 3

b.set();   // 11111111
b.all();   // true
b.any();   // true
b.none();  // false
b.count(); // 8

b.reset(); // 00000000
b.all();   // false
b.any();   // false
b.none();  // true
b.count(); // 0
```

Para obter uma representação do número binário em `string`, o método `to_string`
deve ser utilizado. Porém, se você utilizar o `bitset` no `cout`, ele já possui
uma representação binária também, sem a necessidade de nenumha conversão de tipo.
Já se você quer extrair o número inteiro que os bits do `bitset` formam, existe o
método `to_ullong`, que retorna um `unsigned long long`.

```cpp
bitset<8> b(42); // [0,0,1,0,1,0,1,0]
string bits = b.to_string();

cout << b << "\n";
cout << bits << "\n";
cout << b.to_ullong() << "\n";
```

#### Operações Binárias

A linguagem C, possui operadores que executam as operçães binárias bit a bit.
Os operadores disponíveis são.

* `&` (and): operação "E" binária. Exemplo: 10011 & 10101 == 10001
* `|` (or): operação "OU" binária. Exemplo: 10011 | 10101 == 10111
* `^` (xor): operação "XOR" binária. Exemplo: 10011 ^ 10101 == 00110
* `~` (not): operação de negação binária. Exemplo: ~10011 == 01100
* `<<` (left shift): operador de deslocamento para a esquerda. Exemplo 10011 << 2 == 1001100.
O número que está depois do operador, é o número de bits que ele vai deslocar.
* `>>` (right shift): operador de deslocamento para a direita. Exemplo 10011 >> 3 == 10.
O número que está depois do operador, é o número de bits que ele vai deslocar.

Todos estes operadores podem ser utilizados com os tipos integrais, e com o
container `bitset` do C++.

```cpp
bitset<4> b1("0110");
bitset<4> b2("0011");
b1 & b2; // 0010
b1 | b2; // 0111
b1 ^ b2; // 0101
~b1;     // 1001

int a = 6, b = 3;
a & b; // 0010  -->  2
a | b; // 0111  -->  7
a ^ b; // 0101  -->  5
~a;    // 1001  --> -7
```

### List

A [list](http://en.cppreference.com/w/cpp/container/list) e a
[forward_list](http://en.cppreference.com/w/cpp/container/forward_list)
são estruturas que implementam listas duplamente e simplesmente encadeadas,
respectivamente. Tais estruturas possuem um grande facilidade de alteração
no início e no final, com complexidades constantes.

```cpp
// Criação de uma lista duplamente encadeada vazia
list<int> my_list;

// Inserção e remoção de elementos na frente
my_list.push_front(32);
my_list.pop_front();

// Inserção e remoção de elementos atrás
my_list.push_back(32);
my_list.pop_back();

// Acesso
my_list.front(); // Primeiro elemento
my_list.back();  // Último elemento

// Tamanho
my_list.size();

// Checar se está vazia
my_list.empty();

// Limpar todos os elementos
my_list.clear();
```

A interface da `forward_list` é igual a da `list`, porém sem os métodos de
inserção e remoção de trás da lista, pois ambos não possuem complexidade
constante. Também não possue o método `size`, que diz o tamanho da lista.

```cpp
// Criação de uma lista duplamente encadeada vazia
forward_list<int> my_list;

// Inserção e remoção de elementos na frente
my_list.push_front(32);
my_list.pop_front();

// Acesso
my_list.front(); // Primeiro elemento

// Checar se está vazia
my_list.empty();

// Limpar todos os elementos
my_list.clear();
```

## Estruturas Não Lineares

### Map

O [map](http://en.cppreference.com/w/cpp/container/map) é uma estrutura da dados
que faz relações entre chaves e valores, onde para cada chave há um valor correspondente.
Por exemplo, se você falar que a chave `"casa"` representa o valor `3`, toda vez
que você referenciar a chave `"casa"` com o seu mapa `mapa["casa"]` ele irá te
retornar `3`.

Sua implementação interna é uma árvore binária de busca auto-balanceável, o que
garante uma ótima complexidade para a busca de dados.

A criação de um `map` recebe dois tipos, um tipo para indicar o tipo das chaves
e outro para indicar o tipo dos valores. E a consulta dos valores é dada utilizando
o operador de `[]` ou o método `find`.

```cpp
// Construtor vazio
map<string, int> estados;

// Inserção de itens
estados["Mato Grosso"] = 66;
estados["Bahia"] = 75;
estados["Amazonas"] = 97;
estados["Sergipe"] = 79;

// Consulta de itens

cout << estados["Mato Grosso"] << "\n";
cout << estados["Bahia"] << "\n";

// Remoção de itens
estados.erase("Sergipe");

// Procura de itens
if (estados.find("Amazonas") != estados.end()) {
    cout << "Estado encontrado!\n";
}

// Iteração sobre todos os itens
for(auto chave_valor: estados)
    cout << chave_valor.first << " => " << chave_valor.second << "\n";

// Tamanho do mapa
estados.size();

// O mapa está vazio?
estados.empty();

// Limpar o mapa
estados.clear();
```

### Set

O [set](http://en.cppreference.com/w/cpp/container/set) é uma estrutura de dados
que representa um conjunto de elementos. Ele possui as mesmas propriedades que um
conjunto da matemática. Dentro dele não haverá a repetição de nenhum elemento.

Assim como o `map`, o `set` é implementado como uma árvore binária de busca
auto-balanceavel. O que faz dele uma ótima estrutra de dados para buscas.

```cpp
// Construtor vazio
set<int> identificadores;

// Inserção de itens
identificadores.insert(68);
identificadores.insert(33);
identificadores.insert(108);
identificadores.insert(42);

// Remoção de itens
identificadores.erase(33);

// Checar se um item está no set
if (identificadores.count(108) != 0) {
    cout << "Encontrado!\n";
}

// Iteração sobre todos os itens
for(auto item: identificadores)
    cout << item << "\n";

// Tamanho do set
identificadores.size();

// O set está vazio?
identificadores.empty();

// Limpar o set
identificadores.clear();
```

### Priority Queue

A [priority_queue](http://en.cppreference.com/w/cpp/container/priority_queue),
fila de prioridades, constrói uma fila ordenada por um critério. Onde o primeiro
lugar da fila é ocupado pelo elemento com a maior prioridade. Se um elemento que
possui mais prioridade que os outros for inseridos nesta fila, ele passa a frente
de todos os elementos com prioridade mais baixa que ele.

A implementação da `priority_queue` é feita com a estrutura de dados `heap` que
é uma árvore binária linearizada e ordenada pelo critério de ordenação. É uma ótima
estrutra para ordenação de dados e consumo de dados com alta prioridade. Ela não serve
para consultas extensivas, pois você só pode acessar o seu primeiro elemento,
assim como a `queue`.

```cpp
// Construtor Vazio
priority_queue<int> fila;

// Inserção de elementos
fila.push(4);
fila.push(32);
fila.push(10);
fila.push(60);
fila.push(27);

// Consulta do primeiro elemento
// No caso o elemento 60, pois a ordem padrão é a decrescente
fila.top();

// Remoção de um elemento
fila.pop();

// A fila está vazia
fila.empty();

// Tamanho da fila
fila.size();
```

A ordem padrão da `priority_queue` é do maior para o menor. Caso seja necessário
a ordem inversa, você pode utilizar o seguinte construtor, que ele vai fazer a ordem
ir do menor para o maior.

```cpp
priority_queue<int, vector<int>, greater<int> > fila;
```

Qualquer tipo pode ser utilizado na `priority_queue`, desde que este tenha implentado
o operador de `<` (menor que). Os tipos string, pair, int, double e char já possuem
este operador implementado por padrão. Se você possui um tipo/classe/struct que você
criou, você pode implementar o operador de `<` para este tipo.

```cpp
class Pessoa {
public:
    // Campos da pessoa
    string nome;
    int idade;
    char sexo;

    // Método construtor da pessoa
    Pessoa(string n, int i, char s) {
        nome = n;
        idade = i;
        sexo = s;
    }

    // Operador <
    bool operator<(const Pessoa &p) const {
        if (idade == p.idade) {
            if (sexo == p.sexo) {
                // Menor nome tem mais prioridade
                return nome > p.nome;
            }

            // Menor sexo tem mais prioridade
            return sexo > p.sexo;
        }

        return idade < p.idade;
    }
};

int main() {
    priority_queue<Pessoa> pessoas;

    pessoas.push(Pessoa("Jorge", 35, 'M'));
    pessoas.push(Pessoa("Joana", 60, 'F'));
    pessoas.push(Pessoa("Amanda", 60, 'F'));
    pessoas.push(Pessoa("Mario", 61, 'M'));
    pessoas.push(Pessoa("Fabiana", 61, 'F'));

    while(!pessoas.empty()) {
        auto p = pessoas.top();
        pessoas.pop();

        printf("[%s, %d, %c]\n", p.nome.c_str(), p.idade, p.sexo);
    }

    return 0;
}
```

Na definição do operador de `<` é necessária a seguinte assinatura:
`bool operator<(const T &p) const;`, onde `T` é o tipo sendo implementado e
`p` é o nome do paramêtro do tipo `T`. `p` vai assumir o valor do elemento que você
esta comparando, ou seja, se houverem duas pessoas `Pessoa a` e `Pessoa b`, quando
fizer a operação `a < b`, o operador `<` da pessoa `a` será chamado com o parâmetro
`p` igual a pessoa `b`.

### Unordered Map

O [unordered_map](http://en.cppreference.com/w/cpp/container/unordered_map) é uma
estrutura de dados que funciona de um jeito similar ao `map`. Ela possui as mesmas
funções que o `map` possui, porém a sua consulta é mais eficiente que a do `map`.
A maior diferença entro o `map` e o `unordered_map` é que o map guarda seu dados
ordenados pela chave, e o `unordered_map` não possui ordem específica.

A implementação do `unordered_map` é uma estrutura de `hash`, a qual é muito eficiente
para consulta.

```cpp
// Construtor vazio
unordered_map<string, int> estados;

// Inserção de itens
estados["Mato Grosso"] = 66;
estados["Bahia"] = 75;
estados["Amazonas"] = 97;
estados["Sergipe"] = 79;

// Consulta de itens

cout << estados["Mato Grosso"] << "\n";
cout << estados["Bahia"] << "\n";

// Remoção de itens
estados.erase("Sergipe");

// Procura de itens
if (estados.find("Amazonas") != estados.end()) {
    cout << "Estado encontrado!\n";
}

// Iteração sobre todos os itens
for(auto chave_valor: estados)
    cout << chave_valor.first << " => " << chave_valor.second << "\n";

// Tamanho do mapa
estados.size();

// O mapa está vazio?
estados.empty();

// Limpar o mapa
estados.clear();
```

Pelo fato do `unordered_map` ser implementado como uma `hash`, o tipo de sua
chave deve ser possivel de ser fazer uma `hash` dele. Todos os tipos nativos
podem ser utilizados no `unordered_map`. O tipo `pair`, por exemplo, não pode
ser utilizado, pois não é possível se extrair uma `hash` dele.

### Unordered Set

O [unordered_set](http://en.cppreference.com/w/cpp/container/unordered_set),
assim como o `unordered_map`, é uma estrutura de dados muito semelhante ao `set`,
porém com uma busca muito mais eficiente, pois ela é implementada como uma `hash`.
Ele também possui as mesmas propriedades de conjunto que o `set` possui.

```cpp
// Construtor vazio
unordered_set<int> identificadores;

// Inserção de itens
identificadores.insert(68);
identificadores.insert(33);
identificadores.insert(108);
identificadores.insert(42);

// Remoção de itens
identificadores.erase(33);

// Checar se um item está no set
if (identificadores.count(108) != 0) {
    cout << "Encontrado!\n";
}

// Iteração sobre todos os itens
for(auto item: identificadores)
    cout << item << "\n";

// Tamanho do set
identificadores.size();

// O set está vazio?
identificadores.empty();

// Limpar o set
identificadores.clear();
```

## Algoritmos de Min e Max

Estes algoritmos identificam os maiores e menores valores, dado um conjunto de valores.
Assim como os outros algoritmos da STL, eles podem ser utilizados para todos os tipos.
Porém, eles vão requerer que o tipo possua o operador `<` definido.

Os 3 principais métodos deste tipo de algorimto são:
[min](http://en.cppreference.com/w/cpp/algorithm/min),
[max](http://en.cppreference.com/w/cpp/algorithm/max) e
[minmax](http://en.cppreference.com/w/cpp/algorithm/minmax). Porém
existem vários outros métodos como o `max_element` e o `min_element`, que retornam
o maior e menor elemento de um container.

```cpp
string abacaxi = "abacaxi";
string uva = "uva";

// Utilização do min
min(4, 5);
min(6.7, -8.9);
min(abacaxi, uva);  // Menor alfabeticamente -> "abacaxi"

// Utilização do max
max(4, 5);
max(6.7, -8.9);
max(abacaxi, uva);  // Maior alfabeticamente -> "uva"

// Utilização do minmax
auto nums = minmax(4, 5); // Retorna um pair<int, int> (4, 5)
auto fracs = minmax(6.7, -8.9); // Retorna um pair<double, double> (-8.9, 6.7)
auto frutas = minmax(uva, abacaxi); // Retorna um pair<string, string> (abacaxi, uva)
```

O retorno de cada função será do tipo que foram passados os argumentos. Exceto o
retorno do minmax, que retorna um `pair` com os tipos dos argumentos.

## Algoritmos de Modificação

Estes algoritmos trabalham modificando __containers__ e outros elementos.
Os dois métodos mais comuns destes algorimtos são o
[swap](http://en.cppreference.com/w/cpp/algorithm/swap)
e o [reverse](http://en.cppreference.com/w/cpp/algorithm/reverse).

O `swap` vai trocar o valor de dois elementos, assim o elemento `a` assume o valor
de `b` e o elemento `b` assume o valor de `a`.

```cpp
int a = 30;
int b = 20;

swap(a, b); // Agora: a = 20 e b = 30

string nome1 = "Carla";
string nome2 = "Vanessa";

swap(nome1, nome2); // Agora: nome1 = "Vanessa" e nome2 = "Carla"

vector<int> v = {3, 4, 1};
swap(v[0], v[2]);
```

O `reverse` vai inverter um intervalo de elementos dentro de um container. Os seus
parâmetros são um iterador para o início do intervalo, e um iterador para o final
do intervalo.

```cpp
vector<int> v = {4, 8, 15, 16, 23, 42};
reverse(v.begin(), v.end());
// Agora v = {42, 23, 16, 15, 8, 4}

string nome = "Alucard";
reverse(nome.begin(), nome.end());
// Agora nome = "draculA"
```

Além destas funções, os algoritmos de modificação conta com outros métodos como o
`unique`, que retona um container sem repetições de elementos. O `remove_if`, que
remove todos os elementos que retornam verdade para uma certa condição.
O `transform`, que aplica uma função para cada elemento do container e retorna
o container modificado.

## Algoritmos de Busca

Existem vários algoritmos de busca implementados na STL. Os métodos `find` de
cada container, procuram dentro do container o elemento pedido. A complexidade
deste método vai depender do container sendo utilizado. Porém existem 3
algoritmos genéricos, que vão funcionar com **containers lineares ordenados**.
Entre eles, os mais comuns são o `vector` e o `array`. Estes algorimtos são:
[lower_bound](http://en.cppreference.com/w/cpp/algorithm/lower_bound),
[upper_bound](http://en.cppreference.com/w/cpp/algorithm/upper_bound) e
[binary_search](http://en.cppreference.com/w/cpp/algorithm/binary_search).

O `lower_bound` é um método que retorna um iterador para o primeiro elemento que
é maior ou igual ao valor passado. O `upper_bound` retorna um iterador para o primeiro
elemento que é maior que o valor passado. Ambos os métodos tem uma complexidade
de `O(log n)` para achar o elemento.

```cpp
//                   0  1  2  3  4  5  6  7  8  9  10  11  12
vector<int> data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4,  5,  5,  6 };

auto lower = lower_bound(data.begin(), data.end(), 4);
auto upper = upper_bound(data.begin(), data.end(), 4);

*lower; // Valor 4, posição 7
*upper; // Valor 5, posição 10

for(auto it = lower; it <= upper; ++it) {
    cout << *it << "\n";
}
```

O método `binary_search` realiza uma busca binária no seu container ordenado.
E retorna se o elemento procurado está lá ou não. Ele também tem complexidade
`O(log n)`.

```cpp
//                   0  1  2  3  4  5  6  7  8  9  10  11  12
vector<int> data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4,  5,  5,  6 };

binary_search(data.begin(), data.end(), 3); // true
binary_search(data.begin(), data.end(), 7); // false
binary_search(data.begin(), data.end(), 4); // true
```

Se você precisa da posição do elemento, você pode utilizar o método `lower_bound`
para descobrir.

## Algoritmos de Ordenação

A `STL` oferece alguns algoritmos para ordernar um conjunto de elementos, ele
são: [sort](http://en.cppreference.com/w/cpp/algorithm/sort) e
[stable_sort](http://en.cppreference.com/w/cpp/algorithm/stable_sort). Todos eles
vão ordernar os elementos do menor para o maior.

```cpp
// Ordenação comum
vector<int> v1 = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
sort(v1.begin(), v1.end());
// 0 1 2 3 4 5 6 7 8 9
```

O `stable_sort` vai manter a ordem de ocorrência, ou seja, se houveram dois
elementos iguais, o elemento que vier primeiro vai ficar antes do próximo.
Assim como a `priority_queue`, todos eles espera, que o tipo do elemento que eles
estão ordenando, tenha o operador `<` implementado.

```cpp
class Pessoa {
public:
    // Campos da pessoa
    string nome;
    int idade;
    char sexo;

    // Método construtor da pessoa
    Pessoa(string n, int i, char s) {
        nome = n;
        idade = i;
        sexo = s;
    }

    // Operador <
    bool operator<(const Pessoa &p) const {
        return idade < p.idade;
    }
};

int main() {
    vector<Pessoa> pessoas;
    pessoas.push_back(Pessoa("Joana", 60, 'F'));
    pessoas.push_back(Pessoa("Jorge", 35, 'M'));
    pessoas.push_back(Pessoa("Fabiana", 61, 'F'));
    pessoas.push_back(Pessoa("Amanda", 60, 'F'));
    pessoas.push_back(Pessoa("Mario", 61, 'M'));

    stable_sort(pessoas.begin(), pessoas.end());

    for(auto p: pessoas)
        printf("[%s, %d, %c]\n", p.nome.c_str(), p.idade, p.sexo);

    /*
    [Jorge, 35, M]
    [Joana, 60, F]
    [Amanda, 60, F]
    [Fabiana, 61, F]
    [Mario, 61, M]
    */
    return 0;
}
```

## Algoritmos de Permutação

Os algoritmos [next_permutation]() e [prev_permutation]() são utilizados para obter
a próxima e a anterior permutações lexicográficas dos itens de um container. Ambos
possuem os mesmo parâmetros de chamada, o que muda é a direção em que eles fazem
a permuta dos itens.

Quando não há mais permutações a se fazerem naquela direção, os métodos retornam
`false`. Com isso você consegue saber todas as permutações de uma direção específica,
como mostra o código a seguir.

```cpp
string s = "aba";

do {
    cout << s << '\n';
} while(next_permutation(s.begin(), s.end()));
```

Para conseguir todas as permutações possíveis, você deve colocar os seus elementos
na ordem da primeira permutação lexicográfica. Para fazer isso, você deve ordernar
os itens.

```cpp
string s = "aba";
sort(s.begin(), s.end());

do {
    cout << s << '\n';
} while(next_permutation(s.begin(), s.end()));
```

## Iterators

O método `find` retorna um `iterator`, que é um apontador para uma posição.
Todos os containers da `STL` possuem dois iterators padrões, um que aponta para
o início do container e outro que aponta para o fim. O `begin` aponta para o
primeiro elemento daquele container, para o início. O `end` aponta para uma posição
após o último elemento do container. Por exemplo:

![Iterators](iterators.png)

O método `find`, irá retornar um iterator para posição onde ele achou o elemento.
Se ele não achar o elemento, então ele retorna o iterator `end`. Para acessar o
valor que o iterator está apontando, você deve utilizar o operador de __dereference__ `*`.

```cpp
vector<int> v {1, 2, 3, 4, 5, 6};
auto it = find(v.begin(), v.end(), 3);

if (it != v.end()) {
    cout << "Elemento encontrado: " << *it << "\n";
}

cout << *v.begin() << "\n";
```

Os parâmetros do método `find` são iteradores para o início e para o final
do intervalo onde deve ser procurado o elemento. Para procurar em outro intervalo
diferente do `[begin, end]`, você pode utilizar operações aritméticas de soma
e subtração com os iterators. Então se você deseja procurar a partir da terceira
posição até a penúltima, você pode `v.begin() + 2, v.end() - 1`.

O `iterator` pode mudar o seu tipo interno de acordo com o container de quem ele
veio. Os containers como o `map`, que guarda mais de um valor por elemento, no
caso a chave e o valor, o `iterator` vai funcionar como um `pair`. Neste caso
para acessar a chave você terá que acessar o primeiro campo do `pair` assim:
`it->first`. Para acessar o valor: `it->second`.


## Exercícios

1. UVA
    1. [10038 - Jolly Jumpers](https://uva.onlinejudge.org/external/100/10038.pdf)
    1. [594 - One Little, Two Little, Three Little Endians](https://uva.onlinejudge.org/external/5/594.pdf)
    1. [11933 - Splitting Numbers](https://uva.onlinejudge.org/external/119/11933.pdf)
    1. [127 - “Accordian” Patience](https://uva.onlinejudge.org/external/1/127.pdf)
    1. [540 - Team Queue](https://uva.onlinejudge.org/external/5/540.pdf)
    1. [12100 - Printer Queue](https://uva.onlinejudge.org/external/121/12100.pdf)
    1. [10611 - The Playboy Chimp](https://uva.onlinejudge.org/external/106/10611.pdf)
    1. [417 - Word Index](https://uva.onlinejudge.org/external/4/417.pdf)
    1. [484 - The Department of Redundancy Department](https://uva.onlinejudge.org/external/4/484.pdf)
    1. [11917 - Do Your Own Homework!](https://uva.onlinejudge.org/external/119/11917.pdf)
    1. [11572 - Unique Snowflakes](https://uva.onlinejudge.org/external/115/11572.pdf)
    1. [11286 - Conformity](https://uva.onlinejudge.org/external/112/11286.pdf)
    1. [10815 - Andy’s First Dictionary](https://uva.onlinejudge.org/external/108/10815.pdf)
    1. [11849 - CD](https://uva.onlinejudge.org/external/118/11849.pdf)
    1. [10954 - Add All](https://uva.onlinejudge.org/external/109/10954.pdf)
1. URI
    1. [1089 - Musical Loop](https://www.urionlinejudge.com.br/judge/problems/view/1089)
    1. [1062 - Rails](https://www.urionlinejudge.com.br/judge/problems/view/1062)
    1. [1025 - Where is the Marble?](https://www.urionlinejudge.com.br/judge/en/problems/view/1025)
    1. [1259 - Even and Odd](https://www.urionlinejudge.com.br/judge/en/problems/view/1259)
    1. [1548 - Canteen Queue](https://www.urionlinejudge.com.br/judge/en/problems/view/1548)
    1. [1104 - Exchanging Cards](https://www.urionlinejudge.com.br/judge/en/problems/view/1104)

## Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

Wikipedia. [Standard Template Library](https://en.wikipedia.org/wiki/Standard_Template_Library)
