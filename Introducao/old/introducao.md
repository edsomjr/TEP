Introdução a Programação para Competições
=========================================

Programação para Competições requer e trabalha algumas habilidades do programador:

1. **Problem Solving:** A habilidade de solucionar problemas pensando em um algoritmo
eficiente o bastante dado um contexto. Para refinar esta habilidade não requer
só o conhecimento prévio dos algoritmos que já existe, mas também requer habilidades
lógicas e matemáticas que irão te ajudar a: embasar seu pensamento, auxiliar o
seu algoritmo e provar que o mesmo funciona.

1. **Programação**: A habilidade de implementar o algoritmo pensado em alguma linguagem
de programação existe. Pois não basta apenas pensar no algoritmo, você deve provar
que o mesmo funciona, implementando ele. E para garantir que a resposta esteja correta
é necessário que tanto o pensamento quanto a implementação estejam corretos. Ter um bom
conhecimento na linguagem escolida vai te ajudar a realizar um boa implementação.

A prática e o refinamento dessas habilidades te ajudam para ser um bom programador
para comeptições.

## Código Base (C++)

A linguagem mais utilizada nas maratonas de programação é o C++. Ela é muito popular
por ter uma boa performance e várias bibliotecas padrões que já implementam estruturas
de dados e algoritmos. Para ter acesso a estas bibliotecas existem vários inclusões (`#include`)
que deve ser fazer. Porém, no compilador GCC, o _header file_ `bits/stdc++.h` já faz
todas as inclusões necessárias. Você pode conferir o arquivo
[aqui](https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01040_source.html).

Em maratonas é possível utilizar este include, pois o compilador oficial é o GCC. Porém
se você não estiver utilizando o GCC, você pode não ter um _header file_ equivalente.

O código base de todos os problemas resolvidos em C++ é o seguinte:

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    return 0;
}
```

A linha `using namespace std` é necessária para um uso mais facilitado das funcionalidades
das bibliotecas padrões. Sua omissão requer um código muito mais verboso.

Para compilar o código acima, algumas _flags_ são recomendadas. Estas flags são utilizadas
pela a Maratona de Programação para compilar o seu código, o uso delas vai permitir que você
tenha uma versão executável muito similar a versão da Maratona de Programação.

```sh
g++ -o prog -std=c++11 -O2 -Wall codigo.cpp
```

Onde `-std=c++11` força o seu compilador a utilizar o padrão do C++11. `-O2` garante
o nível 2 de otimização para o seu código. E `-Wall` liga algumas flags de warning,
que te alertam sobre possíveis erros no seu código ou boas práticas de programação.

É comum encontrar em um corretor online, a descrição de todas as flags que eles utilizam
para que você possa reproduzir no seu ambiente. Assim como a versão do compilador utilizado.

Além destas flags, é recomendado utilizar:

* `-Wshadow`: que diz se alguma variável esta mascarando/sobrepondo outra.


## Leitura e Escrita (I/O)

A leitura e escrita em C++ pode ser feita de vários modos. Um deles é utlizando as
_streams_ de dados `cin` (entrada) e `cout` (saída). Estas _streams_ conseguem ler e escrever
qualquer padrão tipo sem a necessidade de especifica-lo. Exemplo:

```cpp
int a;
float b;
double c;
char d;
string e;

cin >> a >> b >> c >> d >> e;

cout << a << b << c << d << e << "\n";
```

O operador `>>` é utlizado no `cin`, para possibilitar a leitura de mais de um dado
em um mesmo `cin`. Já o operador `<<` é utilizado no `cout` com a mesma finalidade.
E no `cout` é pssível colocar, além de variáeis, constantes.

```cpp
cout << "O valor " << (a + b) << " nao eh multiplo de " << 3 << "\n";
```

### C++ com I/O do C

Apesar do `cin/cout` serem os métodos de leitura do C++, e terem uma grande vantagem
de serem genéricos, aceitando vários tipos sem a especificação do mesmo. Eles tem uma
performance inferior as funções de leitura e escrita do C, `scanf` (leitura) e `printf` (escrita).

```c
int a;
float b;
double c;
char d;
char e[100];

scanf("%d %f %lf %c %s", &a, &b, &c, &d, e);
printf("%d %f %lf %c %s\n", a, b, c, d, e);
```

O [scanf](http://www.cplusplus.com/reference/cstdio/scanf/)
possui 3 principais modos que podem ser especificados no seu primeiro
argumento. São eles:

1. Espaço em branco: ignora 0 ou mais [caracteres não imprimiveis](http://www.cplusplus.com/reference/cctype/isspace/)
até o próximo caractere imprimivel. Ele vai ignorar os caracteres: '\n', '\t', ' ', '\v', '\f', '\r'.

1. Especificador de formato: são iniciados pelo símbolo `%`, e seguem o formato
`%[*][width][length]specifier`. Onde o `*` diz se o dado lido deve ser guardado
ou não eu uma variável. O `width` diz até quantos dados serão lidos por aquele
especificador. O `length` é um modificador de tamanho para o specifier, um `lenght`
comum de se usar é o `ll` para o `%lld` (long long int). E o `specifier` diz o tipo
do dado que será lido, ou os grupos de caracteres permitidos. Exemplos: %d, %f,
%lf, %[abcdef], %29[^abcdef]

1. Caracteres normais: estes caracteres são qualquer caracter, exceto os citados anteriormente.
Quando há um caracter deste tipo no scanf, ele lê um caracter da entrada, e se este caracter
estiver compativel com o caracter do scanf, então a leitura procede. Caso contrário, a leitura
finaliza com um erro.

```c
// Leitura de um telfone: +55 (61) 91234-5678
scanf("+%d (%d) %d-%d", &pais, &estado, &telefone1, &telefone2);

// Leitura de um CPF: 000.000.000-42
scanf("%d.%d.%d-%d", &d1, &d2, &d3, &d4);

// Leitura de preço: R$ 29.99
scanf("R$ %d.%d", &reais, &centavos);

// Leitura de todas as letras minúsculas até uma que não seja
// Exemplo: abcdeFgh   --> ele vai ler abcde
scanf("%[a-z]", &letras);

// Leitura de qualquer coisa EXCETO as letras minúsculas
// Exemplo: 123 FGH ##$$abcdeFgh   --> ele vai ler 123 FGH ##$$
scanf("%[^a-z]", &letras);

// Leitura das 4 primeiras letras maiúsculas
// Exemplo: ABCDEFG --> ele vai ler ABCD
scanf("%4[A-Z]", &abreviatura);

// Leitura de um inteiro depois de jogar fora uma string
scanf("%*s %d", &numero);
```

O `scanf` retorna quantas variáveis ele conseguiu ler com sucesso. Se por algum motivo
não foi possível fazer a leitura até o fim do padrão determinado, então ele retorna o número
de variáveis lidas com sucesso até ali. Ou ele retorna EOF (end-of-file) se ele não conseguir
ler nenhuma variável e a entrada tiver acabado.


O [printf](http://www.cplusplus.com/reference/cstdio/printf/) também possui formatos
espeficos para a impressão de valores. Além de modificadores para justificar o valor,
a direita e esquerda, mostrar o sinal ou não, regular a precisão apresentada. Vários
exemplos podem ser vistos a seguir, porém é recomendada a leitura da
[documentação](http://www.cplusplus.com/reference/cstdio/printf/)
para maiores esclarecimentos.

```c
// Imprimir com no mínimo 4 casas, preenchendo as que tão faltando com 0
printf("%04d\n", 23); //$ 0023

// Imprimir com no mínimo 4 casas, sem preencher as que tão faltando
printf("%4d\n", 23); //$   23

// Imprimir o sinal de + ou - junto
printf("%+d %+d\n", -23, 23); //$ -23 +23

// Imprimir o sinal de -, e se for positivo deixa um espaço em branco
printf("% d % d\n", -23, 23); //$ -23  23

// Justificar o dado a direita, com 4 casas
printf("%-4d\n", 23); //$ 23  

// Tamanho e precisão definidos dinamicamente
printf("%*.*f\n", 10, 4, 23.23f); //$      23.2300
```

### Leitura de strings

A principal desvantagem de utilizar os métodos de leitura e escrita do C, é que
eles não suportam os tipos padrões do C++, como a `string`. Porém algumas medidas
podem ser tomadas para reproduzir o mesmo comportamento com o `scanf` e `printf`.

```cpp
char c_str[500];

scanf("%s", c_str);
string str(c_str);

printf("%s", str.c_str());
```

Neste exemplo, a variável `str` do tipo `string` é criada a partir de um array de
caracteres `c_str`. E utilizada no `printf` com o formato de string do C `%s`, porém
isso só é possível, por causa do método `c_str()`, chamado através da variável `str`.
Este método retorna um array de caracteres.

Para ler uma linha completa, até o `\n`, pode-se utilizar um formato especial no
`scanf` que diz até qual caractere delimitador a leitura deve ir.

```c
scanf("%[^\n]", linha);
```

Já no `cin`, existe o método [getline](http://www.cplusplus.com/reference/string/string/getline/),
que lê a linha até o `\n` por padrão. Porém você também pode modificar o caractere
delimitador.

```cpp
getline(cin, linha); // Lê na string linha
getline(cin, linha, '#'); // Lê todos os caracteres até encontrar o '#'
```

### End of File (EOF)

End of File ou EOF, fim de arquivo, em português, se refere ao fim da entrada. Ao
ler todas as entradas e não sobrar mais nada, você chega ao EOF. Para saber se você
chegou no EOF, você precisa checar o retorno da função utilizada.

```c
while (scanf("%[^\n]", linha) != EOF) {
    ...
}
```

O `cin` retorna `false` assim que atinge o EOF e não consgue ler mais nenhuma entrada.

```cpp
while (getline(cin, linha) != EOF) {
    ...
}

while (cin >> numero) {
    ...
}
```

## Quesitos de Parada

O quesito de parada, define até onde você vai ler a entrada do problema. Cada
problema tem um quesito de parada diferente. Os mais comuns são:

* EOF: ler até alcançar o fim do arquivo
* Número de casos de teste: neste quesito o número de casos de teste é informado
no início da entrada e você deve repertir a leitura n-vezes.
* Ler até uma entrada 0: neste quesito você deve ler as entradas até que todas sejam 0

### Parada pelo número de casos

Quando o quesito de parada for o número de casos de testes, há dois principais modos
de se fazer a questão. O primeiro modo é utilizando quando a informação de em qual
caso de teste você está atualmente não é relevante. Neste modo, você utiliza o fato
que na linguagem C: `0` é falso e `!0` é verdadeiro. Com isso você itera `n` vezes
decrementando a variável `n_casos`, até que ela se torne `0`, então loop para de
executar.

```cpp
int n_casos;
cin >> n_casos;

while(n_casos--) {
    // Resto do código vai aqui
}
```

O segundo modo é quando o número do caso, em que você está agora, importa para a
solução. Neste modo você utiliza o  `n_casos` como condição de parada do seu `for`.
E a variavel `caso_i` como o caso onde você está agora.

```cpp
int n_casos;
cin >> n_casos;

for (int caso_i = 1; caso_i <= n_casos; caso_i++) {
    // Resto do código vai aqui

    cout << "Caso " << caso_i;
}
```

### Parada quando houver entrada zerada

Quando o quesito de parada for quando a entrada vier zerada, você pode utilizar
o operador de `,` (vírgula) para checar se você deve parar ou não. Suponha que o
problema pede para você processar a entrada até que venham dois números zero.

```cpp
while(cin >> a >> b, a || b) {
    // Resto do código vai aqui
}
```

Neste caso você vai executar a leitura de a e b, e logo após você vai checar
se `a || b`, que retorna falso só se ambos forem 0.

Se a questão pede para ler até que um dos valores seja zero, você pode utilizar
a mesma lógica, alterando o `||` pelo `&&`.

```cpp
while(cin >> a >> b, a && b) {
    // Resto do código vai aqui
}
```

## O operador vírgula

Em C e C++, o operador `,` é o operador com a precedência mais baixa. A função
dele é ignorar os resultados lógicos que aconteceram até então.

```cpp
if (false || false, false && false, true || false) {
    cout << "Entrei por causa do true || false\n";
}
```

## Forma de execução das entradas e saídas

Ao trabalhar em questões de maratona de programação você terá acesso a um conjunto
de entradas e saídas. **Nunca** escrevam elas direto no terminal ou no seu programa,
pois isso pode gerar erros de digitação. **Sempre** copiem as entradas e saídas para
arquivos de texto, por exemplo, `in.txt` e `out.txt`. Para usar estes arquivos,
utilize o seguinte comando:

```sh
./prog < in.txt > ans.txt
```

O arquivo `ans.txt` vai guardar a saída que o seu programa vai responder para o
`in.txt`. Ele deve ser comparado com o `out.txt`, que é a saída esperada.

```sh
diff out.txt ans.txt
```

Se não houver nenhum diferença entre os arquivos, o seu progrma está certo para
aquele conjunto de entrada e saída.

## Python 3

Python é uma linguagem interpretada que se aplica em vários contextos na resolução
de problemas. Ela funciona tanto como ferramenta para auxilo na resolução de problema,
e também como linguagem para resolver problemas. Nela você vai encontrar:

* Aritimética Extentida
* Biblioteca de Calendário
* Regex
* Conversão de Bases

Além de ter muitas coisas já implementadas por padrão que podem ser utilizadas
para a resolução de problemas.

### I/O no Python

Para ler e escrever no python podemos utilizar as funções:

* `input`: lê uma linha de dados no formato de string
* `print`: imprime uma mensagem em uma linha

Como a função `input`, no Python 3, sempre retorna uma string, é necessário converter
as partes desta string para os valores que queremos. Suponha que a questão sempre vai
te dar uma linha com um inteiro, um ponto flutuante e uma string.

```python
linha = input().split()

a = int(linha[0])
b = float(linha[1])
c = linha[2]

print(a, b, c)
```

A função `split`, vai separa sua string lida nos espaços. Se a string lida for
`3 1.2 camelo`, o split vai separar em uma lista assim `["3", "1.2", "camelo"]`.
As funções `int` e `float` vão converter as posições 0 e 1 da lista para inteiro
e ponto flutuante, respectivamente.

Se for necessário trasformar várias posições da linha em um tipo específico, deve-se
utlizar o método `map`. Suponha que a entrada vai te dar o nome de duas pessoas,
seguido por um inteiro `n` e depois `n` notas do tipo float.

```python
linha = input().split()

nome1 = linha[0]
nome2 = linha[1]
n = int(linha[2])
notas = list(map(float, linha[3:]))

print(nome1, nome2, n, notas)
```

O método `map` no código acima vai aplicar a função `float` para cada elemento da
lista da linha, apartir do elemento de número 3, até o fim. O método `list` vai
transformar a saída do map em uma lista que você pode imprimir e acessar.

Se a necessidade for ler até o `EOF`, o método input não é capaz de detectar. Então
é necessário utilizar o `sys.stdin`. Que também vai retornar as linhas no formato
de string.

```python
import sys

for linha in sys.stdin:
    linha = linha.split()

    nome1 = linha[0]
    nome2 = linha[1]
    n = int(linha[2])
    notas = list(map(float, linha[3:]))

    print(nome1, nome2, n, notas)
```

A função `print` é utilizada para imprimir uma linha. Elá já imprime o `\n` ao final
da linha automaticamente. A cada virgula que você coloca na função para separar o que
você quer imprimir, ela insere um espaço entre as duas coisas. Para poder imprimir
mensagens com formatos específicos, é necessário utilizar a função `format` da string.
A função [format](https://pyformat.info/) possui mais funcionalidades que o `printf`
do C, um modo básico de utiliza-la, pode ser visto a seguir.

```python
print("Caso {}:\nX = {}".format(caso_i, soma))
```

Os `{}` são utilizados para identificar onde as variáveis serão colocadas. E eles aceitão
várias configurações adicionais, que podem ser consultadas na
[documentação](https://pyformat.info/).


### Divisão inteira no Python3

Para realizar divisão inteira no Python3 é necessário utilizar o operador `//`. Pois a
barra simples `/` sempre vai retornar uma divisão normal, independente dos tipos
que estiverem participando da divisão.

```python
print(2/3)  # 0.6666666666
print(2//3) # 0
```

### Execução do programa em Python3

Para executar um programa feito em python, é necessário apenas:

```sh
python3 codigo.py < in.txt > out.txt
```

Por se tratar de uma linguagem interpretada, não há necessidade de compilar o programa.
Não se esqueça que o comando é `python3`, só `python` vai chamar a versão 2.7 do Python.
Esta versão tem algumas diferenças, e não funciona no contexto da maratona oficial.

### Python como ferramenta

A maior utilidade do python, no contexto de maratona de programação, é utilizar ele
como ferramenta de apoio. Pois apartir dele você consegue fazer scripts para gerar
código e inputs.

Algumas coisas úteis que pode se fazer com o python:

```python
import string

# Imprime todas as letras do alfabeto
print string.ascii_letters

# Imprime todas os digitos
print string.digits
print string.hexdigits
print string.octdigits

# Imprime todas as pontuações
print string.punctuation

# Imprime todas caracteres imprimiveis
print string.printable
```

```python
# Calcular o número de dias entre datas

from datetime import date

# Datas (ano, mes, dia)
a = date(2011,11,24)
b = date(2011,11,17)

print (a-b).days
```

```python
# Calcular os limites do inteiro

print(2**7  - 1) # char
print(2**8  - 1) # unsigned char
print(2**31 - 1) # int
print(2**32 - 1) # unsigned int
print(2**63 - 1) # long long int
print(2**64 - 1) # unsigned long long int
```

```python
import math

# Valor do pi
print(math.pi)

# Valor do e
print(math.e)
```

```python
import random

# Um número aleatório
print(random.randint(0, 10**7))

# Um float aleatório
print(random.uniform(0.0, 1.0))

# Embaralhar uma lista
lista = range(1000)
random.shuffle(lista)
print(lista)

# Pegar K itens aleatórios de uma lista
lista = range(1000)
print(random.sample(lista, 30))
```

```python
# Percorrer um intervalo de X posições
for i in range(37):
    print i

# Percorrer os itens de uma lista
lista = [4, 7, 12, 2, 123]
for i in lista:
    print i
```
