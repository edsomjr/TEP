# Pontos

Os pontos são elementos básicos da geometria, e são elementos adimensionais
(dimensão 0). A maioria dos outros elementos e definições da geometria se
referem a pontos, e o termo ponto, em si, é um termo primitivo (sem definição).

### Representação de pontos

Na prática, em C/C++, um ponto pode ser representado de várias maneiras, cada
uma com suas respectivas vantagens e desvantagens:

**Representação via `struct` ou `class`**

    Representar um ponto utilizando uma classe ou estrutura tem a vantagem da
    legibilidade, mas precisa da implementação dos operadores relacionais para
    comparações entre pontos.

```C++
typedef struct _Point {
        double x;
        double y;
} Point;

Point p, q;     // Declaração
p.x = 5;
q.y = 10;

p = q;          // Atribuição

if (p < q) {    // Erro de compilação: operador < não definido!
        ...
}
```
    Nestas representações, é útil definir construtores para a inicialização
    das variáveis.

```C++
class Point {
public:
        double x;
        double y;

        Point(double xv = 0, double yv = 0) : x(xv), y(yv) {}
};

...

Point p(5), q(0, 10); // Exemplos de uso do construtor (p = (5, 0))
```

**Representação via `std::pair`**

    Usar pares do C++ tem a vantagem de herdar os operadores de comparação dos
    tipos definidos. Porém, a desvantagem é a notação, que utiliza `first` e
    `second` ao invés de `x` e `y`, sendo menos legível que o uso de classes e
    estruturas. Além disso, não podem ser utilizados diretamente para
    representar pontos tridimensionais.

```C++
using point = pair<double, double>;     // C++11

...

point p, q;     // Declaração
p.first = 5;
q.second = 10;

p = q;          // Atribuição

if (p < q) {    // Ok! Operador < para doubles utilizado
        ...
}
```

    A desvantagem de notação menos legível pode ser contornada com o uso
    de macros, conforme mostrado abaixo.

```C++
#define x first
#define y second
```
    Contudo, ao usar tais macros, deve-se tomar cuidado pois todas as aparições
    de `x` e `y` serão substituídas por `first` e `second`. Logo a declaração de
    uma variável com nome `x` pode levar a um erro de compilação.

**Representação via _arrays_**

    Utilizar _arrays_ para representar pontos permite a representação de
    conjuntos de pontos com facilidade, além de permitir a travessia via
    laço `for` por coordenada. Porém, peca na legibilidade (índices inteiros
    para acesso aos membros) e na necessidade de definição dos operadores.

```C++
double p[2], q[2];      // Declaração usando _arrays_ unidimensionais de tamanho 2
p[0] = 5;
q[1] = 10;

p = q;          // Erro de compilação: operador = não definido!

if (p < q) {    // Perigo: comparação entre os endereços dos ponteiros! O
        ...         // código compila normalmente!
}
```

### Comparação entre pontos

Caso a representação para pontos escolhida não herde os comparadores padrão do
C++, é necessário escrever os mesmos para a representação escolhida. Mesmo no
caso do uso de pares, é necessário escrever ao menos o operador de comparação,
para que o mesmo utilize o limiar _e_ (EPS) definido (ver seção
[Motivação](Motivacao.md)).

Abaixo segue um exemplo de implementação do operador de igualdade:

```C++
// Definição da função equals()

bool operator==(const point& a, const point& b)
{
    return equals(a.first, b.first) && equals(a.second, b.second);
}
```

A implementação do operador `<` é dada a seguir. Os demais operadores podem ser
implementados de forma semelhante.

```C++
// Definição do limiar EPS

typedef struct _Point {
    double x;
    double y;
} Point;

bool operator<(const Point& p, const Point& q)
{
    return (equals(p.x,q.x)) ? (q.y - p.y) > EPS : q.x - p.x > EPS);
}

```

Observe que a comparação acima é feita coordenada a coordenada.
Em certas situações, pode ser necessário
ordenar pontos por sua distância a origem ou algum outro critério: se for o
caso, basta alterar a implementação para o critério desejado.

### Distância entre dois pontos

A distância entre dois pontos pode ser computada utilizando o Teorema de
Pitágoras: o quadrado da distância é igual a soma dos quadrados das diferenças
entre as respectivas coordenadas (tanto em duas quanto três dimensões). Se
as coordenadas forem inteiras, pode-se comparar o quadrado diretamente, sem
a extração da raiz quadrada: isto permite a obtenção da igualdade sem o
recurso do limiar, o que aumenta a velocidade e a precisão do cálculo.

```C++
typedef struct _Point {
    double x;
    double y;
    double z;
} Point;

double distance(const Point& P, const Point& Q)
{
    return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y) + (P.z - Q.z)*(P.z - Q.z));
}
```

No caso bidimensional, o melhor é utilizar a função `hypot` da biblioteca
matemática padrão do C/C++: além de computar a distância corretamente, ela
trata de possíveis _underflows_ ou _overflows_ que possam vir a ocorrer
durante o cálculo.

```C++
using point = pair<double, double>;
point p, q;

...

auto dist = hypot(p.first - q.first, p.second - q.second);  // #include <cmath>
```

### Vetores

Um vetor pode se definido/entendido como um segmento de reta orientado.
Embora os segmentos de reta sejam discutidos em maiores detalhes na seção
[Retas](Retas.md), vale destacar a relação entre pontos e vetores.

Dados dois pontos _A_ e _B_, denotaremos _AB_ o vetor que parte do ponto _A_ em
direção ao ponto _B_ (observe que _AB_ e _BA_ tem mesma direção e comprimento,
mas orientações distintas).  O **vetor posição** de um ponto
_P_ é o vetor que une a origem _O_ ao ponto _P_ (_OP_).

Na prática, trabalha-se apenas com vetores-posição: o vetor posição
que corresponde ao vetor _AB_ é o vetor _v = (B.x - A.x, B.y - A.y)_. Deste
modo, embora seja possível definir um tipo de dado para representar vetores,
é possível utilizar pontos para representar vetores. Esta estratégia pode
dificultar a leitura das rotinas, há a vantagem da velocidade de codificação,
devido a redução de código semelhante. A título de ilustração, segue uma
possível implementação da classe Vector (não confundir com o contêiner
`vector` da STL).
```C++
// Definição da classe Point

class Vector {
public:
    double x, y;

    Vector(double xv, double yv) : x(xv), y(yv) {}

    Vector(const Point& A, const Point& B) : x(B.x - A.x), y(B.y - A.y) {}
};
```

O comprimento (ou magnitude) de um vetor é dado pela distância entre seus
pontos (no caso do vetor-posição, a distância do ponto até a origem). O ângulo
que o vetor faz com o eixo-x positivo pode ser determinado pelo arco tangente
da razão entre as coordenadas _y_ e _x_. Vale ressaltar que a função `atan` (
que computa o arco tangente de um número) opera apenas no primeiro e quarto
quadrante do plano cartesiano (onde _x > 0 e -π/2 ≤ θ ≤ π/2_). Para superar
esta limitação, basta somar π ao retorno da função caso _x < 0_ (atenção ao
caso especial onde _x = 0_). Se o vetor for **degenerado** (isto é, liga a
origem à origem), o ângulo não estará definido (a função abaixo resultará em
`-nan`, isto é, _not a number_).
```C++
#define PI 3.141592653589793

class Vector {
public:
    // Membros e construtores

    double length() const
    {
        return hypot(x, y);
    }

    double angle() const
    {
        return atan(y / x) + (x < 0 ? PI : 0);
    }
};
```

### Translações e Rotações

Um ponto _P_ pode ser transladado para outro ponto do espaço, conhecidos os
deslocamentos _dx, dy_ nas direções paralelas aos eixos-_x_ e _y_,
respectivamente (na verdade, a operação acontece no vetor posição
correspondente).
```C++
// Definição da estrutura Point

Point translate(const Point& P, double dx, double dy)
{
    return Point { P.x + dx, P.y + dy };
}
```

Um ponto _P_ pode ser rotacionado _b_ graus radianos em torno da origem (0, 0),
no sentido anti-horário, através da multiplicação do vetor posição _v_
de _P_ pela matriz de rotação _R_, dada abaixo.

![Matriz de Rotação 2D](rotation2D.png)

Esta matriz pode ser deduzida observando-se que as coordenadas do ponto podem
ser expressas como `x = r cos a, y = r sin a` (onde _a_ é o ângulo que o vetor
_v_ faz com o eixo-_x_ e _r_ é a magnitude de _V_) e
que as coordenadas do ponto resultante
 da rotação são `x' = r cos (a + b), y' = r sin (a + b)`.

O código abaixo ilustra esta rotação em linguagem C/C++.

```C++
// Definição da estrutura Point

Point rotate(const Point& P, double angle)
{
    auto x = cos(angle) * P.x - sin(angle) * P.y;
    auto y = sin(angle) * P.x + cos(angle) * P.y;

    return Point { x, y };
}
```

Caso se deseje rotacionar o ponto _P_ em torno de outro ponto _C_ que não
seja a origem
(mais precisamente, outro eixo paralelo a _z_ que passe pelo ponto dado),
basta seguir os três passos abaixo:

1. Transladar o ponto com deslocamentos iguais aos opostos das coordenadas de
_C_, obtendo-se _P'_;
2. Rotacionar o ponto transladado _P'_;
3. Transladar _P'_, com deslocamentos iguais as coordenadas de _C_.

A translação inicial muda o sistema de coordenadas do problema, o levando a
um novo sistema onde _C_ é a origem. Assim, pode-se utilizar a rotina de
rotação em torno da origem e, ao final do processo, retornar ao sistema
original, com a translação inversa. Importante notar que as três operações
devem ser realizadas exatamente na ordem descrita.
```C++
// Definição da classe Point e das funções translate() e rotate()

Point rotate(const Point& P, double angle, const Point& C)
{
    auto Q = translate(P, -C.x, -C.y);
    Q = rotate(Q, angle);
    Q = translate(Q, C.x, C.y);

    return Q;
}
```

O mesmo raciocínio se aplica em três dimensões: as matrizes de rotação
_Rx, Ry_ e _Rz_, que rotacionam, no sentido anti-horário, em torno dos eixos
_x, y_ e _z_, respectivamente, são dadas abaixo.

![Matrizes de Rotação 3D](rotation3D.png)

Dado um conjunto de pontos _P_, as operações de translação e rotação não alteram
as distâncias entre os pares de pontos. Desta forma, se uma figura é
descrita por um conjunto de pontos, todas as suas características que são
baseadas em distâncias (ângulos internos, perímetro, área, volume, etc) são
invariantes a estas duas transformações. Este importante fato pode ser
utilizado para simplificar problemas, como foi feito no caso da rotação de
torno de um ponto arbitrário.

### Escala

Outra transformação possível em um ponto (vetor posição) é a escala, que
consiste na multiplicação das coordenadas por um escalar. Se o mesmo escalar
é utilizado em todos os produtos a escala é dita **uniforme**. Ao contrário
das transformações anteriores, a escala não preserva as distâncias.
```C++
// Definição da classe Point

Point scale(double sx, double sy)
{
    return Point(sx * P.x, sy * P.y);
}
```

Uma aplicação comum da escala é a **normalização** de vetor. Um vetor é dito
**unitário** se o seu comprimento é igual a 1. Dado um vetor _v_ qualquer, é
possível determinar um vetor unitário _u_, na mesma direção e sentido de _v_
(a escala com constante positiva preserva direção e sentido), dividindo-se
as coordenadas de _v_ pelo comprimento de _v_.
```C++
// Definição da classe Vector

Vector normalize(const Vector& v)
{
    auto len = v.length();
    auto u = Vector(v.x / len, v.y / len);

    return u;
}
```

### Produto interno e produto vetorial

O **produto interno** entre dois vetores _u_ e _v_ é dado pela soma dos
produtos das coordenadas correspondentes dos dois vetores. Logo, o resultado
deste produto não é um vetor, e sim um escalar.
```C++
// Definição da classe Vector

double dot_product(const Vector& u, const Vector& v)
{
    return u.x * v.x + u.y * v.y;
}
```

É possível mostrar que este produto coincide com o produto do tamanho dos
dois vetores e do cosseno do ângulo formado por estes vetores, conforme
mostra a expressão abaixo.

![Produto Escalar](dot.png)

A relação acima nos permite computar o ângulo entre dois vetores.
```C++
// Definição da classe Vector e da função dot_product()

double angle(const Vector& u, const Vector& v)
{
    auto lu = u.length();
    auto lv = v.length();
    auto prod = dot_product(u, v);

    return acos(prod/(lu * lv));
}
```

O sinal do produto interno _d_ pode ser utilizado para interpretar a natureza
do ângulo entre os dois vetores:

1. se _d == 0_, os vetores são **ortogonais** (formam um ângulo de 90º);
1. se _d < 0_, os vetores foram um ângulo agudo (menor que 90º);
1. se _d > 0_, os vetores formam um ângulo obtuso (maior que 90º).

O produto vetorial entre dois vetores pode ser definido pelo vetor resultante
do determinante abaixo, onde _i, j, k_ são vetores unitários com mesma direção
e sentido que os eixos _x, y, z_, respectivamente.

![Produto vetorial](cross.png)

Veja que, definido como um determinante, o produto vetorial não é comutativo:
a troca da ordem dos vetores altera o sentido do resultado. Para vetores
bidimensionais, basta fazer a coordenada _z = 0_.

O vetor resultante é perpendicular tanto a _u_ quanto a _v_, e pode-se mostrar
que a magnitude deste vetor é igual ao produto dos comprimentos dos vetores
_u_ e _v_ pelo seno do ângulo formado por estes dois vetores, o que coincide
com a área do paralelogramo (ver seção  [Quadriláteros](Quadrilateros.md))
formado por _u_ e _v_.
```C++
// Definição da classe Vector

Vector cross_product(const Vector& u, const Vector& v)
{
    auto x = u.y*v.z - v.y*u.z;
    auto y = u.z*v.x - u.x*v.z;
    auto z = u.x*v.y - u.y*v.x;

    return Vector(x, y, z);
}
```

Se os vetores tiverem mesma direção, o produto vetorial terá comprimento
zero (como não definirão um plano, não há um vetor normal). Vetores normais
podem ser utilizados para definir a orientação de uma figura tridimensional
(o lado interno e externo da figura).

### Exercícios

<!--- 152 - Distância entre dois pontos -->
<!--- 587 - Distância entre dois pontos -->
<!--- 10466 - Rotações e translações -->
<!--- 10585 - Ordenação de pontos, greedy, simetria, soma dos extremos de um vetor ordenado -->
<!--- 11505 - Pontos, vetores, rotação e translação -->
1. UVA
    1. [152 - Tree's a Crowd](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=88)
    1. [587 - There's treasure everywhere!](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=528)
    1. [10466 - How Far?](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1407&mosmsg=Submission+received+with+ID+17903926)
    1. [10585 - Center of symmetry](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1526&mosmsg=Submission+received+with+ID+17867787)
    1. [11505 - Logo](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2500)

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

STRANG, Gilbert. [Introdução à Álgebra Linear](http://www.americanas.com.br/produto/116582671/livro-introducao-a-algebra-linear?opn=YSMESP&WT.srch=1&loja=79065181000194&epar=&WT.srch=1&epar=bp_pl_00_go_liv_todas_geral_gmv&gclid=CKOWs-LGy84CFYEJkQodCMMEew), 4ª edição, LTC, 2013.
