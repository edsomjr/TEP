Circulos
--------

Um círculo é o conjunto de pontos equidistantes de um ponto _C_. A distância
de um ponto do círculo ao seu **centro** _C_ é denominada **raio** _r_ do 
círculo.

### Representação de círculos

Conforme sua definição, um círculo pode ser representado através de um ponto
_C_ e um raio _r_.
```C++
// Definição da classe Point

class Circle {
public:
        Point C;
        double r;

        Circle(const Point& Cv = Point(0, 0), double rv = 1.0) : C(Cv), r(rv) {}
};

```

A equação do círculo pode ser deduzida a partir da expressão _d(P, C) = r_,
onde _P = (x, y)_ é um ponto do círculo, _C = (x0, y0)_ é o centro do círculo
e _r_ é o raio. A equação final é dada a seguir.

![Equação do Círculo](circle.png)

Esta equação é útil para resolver vários problemas envolvendo círculos, como
o problema de determinar se um ponto está dentro, fora ou sobre um círculo,
como veremos a seguir.

### Relação entre círculos e pontos

Dado um ponto _P_ e um círculo de centro _C_ e raio _r_, uma (e apenas uma)
das três afirmações abaixo será verdadeira:

1. _P_ está dentro do círculo;
1. _P_ está sobre o círculo;
1. _P_ está fora do círculo.

Para determinar qual é a relação válida, basta computar a distância entre o
ponto _P_ e o centro _C_ do círculo: caso esta distância seja menor, igual ou
maior que _r_, _P_ estará dentro, sobre e fora do círculo, respectivamente.

```C++
// Definição da classe Point

class Circle {
public:

    // Membros e construtores

    typedef enum { IN, OUT, ON } PointPosition;

    PointPosition position(const Point& P) const
    {
        auto d = P.distance(C);

        return equals(d, r) ? ON : (d < r ? IN : OUT);
    }
};
```


### Perímetro e Área

Tanto o cálculo do perímetro quanto da área de um círculo envolvem o uso da
constante _PI_. Caso o problema não informe o valor a ser utilizado, há duas
maneira de proceder para determinar o valor desta constante. A primeira é
utilizar o valor definido na linguagem Python, que pode ser obtido com o
script abaixo.
```Python
from math import *

print pi
```

O valor resultante, 3.141592653589793, está correto nas suas 15 casas decimais.
Outra forma é utilizar a função `acos` da biblioteca de matemática padrão do
C/C++.
```C++
#include <cmath>

const double PI = 2.0 * acos(0.0);
```
O valor obtido coincide com aquele fornecido pelo _script_ Python.

O perímetro (circunferência) é o comprimento do contorno do círculo, e é 
igual a PI vezes o seu diâmetro, sendo o diâmetro o dobro do raio do círculo.
```C++
// Definição do valor de PI

class Circle {
public:

    // Membros e construtores

    double perimeter() const
    {
        return 2.0 * PI * r;
    }
};
```

O valor da área delimitada pelo círculo é igual a PI vezes o quadrado do raio do
círculo.

```C++
// Definição do valor de PI

class Circle {
public:

    // Membros e construtores

    double area() const
    {
        return PI * r * r;
    }
};
```

### Arcos e cordas

Um **arco** de um círculo corresponde a uma seção conectada da circunferência.
O comprimento do arco pode ser determinado através do ângulo central _a_
(definido pela união dos dois pontos extremos do arco entre si e com o centro
do círculo) através do produto do perímetro P e a razão entre _a_ e _2PI_
(caso _a_ esteja em radianos). A simplificação desta razão nos leva a
_a*r_.

```C++
// Definição do valor de PI

class Circle {
public:

    // Membros e construtores
    // Perímetro e área

    double arc(double a) const
    {
        return a * r;
    }
};
```

Uma **corda** corresponde a qualquer segmento de reta cujos pontos extremos
estão sob o círculo. O diâmetro é a maior dentre todas as cordas possíveis
de um círculo. Conhecidos o raio _r_ e o ângulo central _a_ do arco definido
pela corda, o comprimento _L_ da corda pode ser determinado através da
Lei dos Cossenos (_L = sqrt(2 * r * r * (1 - cos(a)_) ou pela Trigonometria
(_L = 2 * r * sin(a/2)_).

```C++
// Definição do valor de PI

class Circle {
public:

    // Membros e construtores
    // Perímetro e área

    double chord(double a) const
    {
        return 2 * r * sin(a/2);
    }
};
```

### Setores e Segmentos

Um **setor** de um círculo é a área delimitada por um arco. Assim como no caso
do arco, a área do setor será a fração da área total correspondente ao ângulo
central _a_ do arco que delimita o setor. A simplificação desta fração nos
leva a _ar²/2_.

```C++
// Definição do valor de PI

class Circle {
public:

    // Membros e construtores
    // Perímetro e área

    double sector(double a) const
    {
        return a * r * r / 2.0;
    }
};
```

Um **segmento** de um círculo, associado a um ângulo central _a_, corresponde à
área resultante da diferença entre o setor delimitado por _a_ e do triângulo
resultante do segmentos de reta que unem os extremos dos arcos ao centro do
círculo e os extremos entre si (a corda). A área deste triângulo pode ser
determinada pela Fórmula de Heron (semiperímetro).

```C++
class Circle {
public:

    // Membros e construtores
    // Setor e corda

    double segment(double a) const
    {
        auto c = chord(a);
        auto s = (r + r + c)/2.0;                   // Semiperímetro
        auto T = sqrt(s*(s - r)*(s - r)*(s - c));   // Área do triângulo

        return sector(a) - T;
    }
};
```

Considerando que _T_ é um triângulo com base igual a corda e altura igual a
_rcos(a/2)_, chegamos a expressão fechada para o segmento:
_ar²(a - sen a)/2_.

```C++
class Circle {
public:

    // Membros e construtores
    // Setor e corda

    double segment(double a) const
    {
        return r*r*(a - sin(a))/2.0;
    }
};
```

### Construção de círculos a partir de pontos

É possível identificar o(s) círculo(s) que interceptam um conjunto de _N_
pontos dados.

No caso de _N = 1_, existem infinitos círculos (com infinitos raios possíveis)
que passam por um ponto. O caso _N = 2_ se torna mais interessante se o raio
_r_ também for dado de antemão. Dados dois pontos _P_ e _Q_ e o um raio _r_,
os cenários possíveis são:

1. _P = Q_: esta situação é idêntica ao caso _N = 1_;
1. _dist(P, Q) = 2r_: se a distância entre os dois pontos dados é igual ao
diâmetro do círculo, existe um único círculo de raio _r_ que passa por _P_ e
_Q_. O centro deste círculo será o ponto médio do segmento _PQ_;
1. _dist(P, Q) > 2r_: neste caso, nenhum círculo de _r_ pode passar por ambos
pontos simultaneamente
1. _dist(P, Q) < 2r_: neste caso, exatamente dois círculos passam por _P_ e
_Q_ com raio _r_. O código abaixo, adaptado do livro
[Competitive Programming 3](http://cpbook.net/), permite identificar um destes
círculos. O outro pode ser encontrado invertendo os parâmetros (passar _Q_
como primeiro e _P_ como segundo parâmetro).

```C++
// Definição da class Point

class Circle {
public:
    // Membros e construtores

    static bool
    from2PointsAndRadius(const Point& P, const Point& Q, double r, Circle& c)
    {
        double d2 = (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
        double det = r * r / d2 - 0.25;

        if (det < 0.0)
            return false;

        double h = sqrt(det);

        auto x = (P.x + Q.x) * 0.5 + (P.y - Q.y) * h;
        auto y = (P.y + Q.y) * 0.5 + (Q.x - P.x) * h;

        c = Circle(Point(x, y), r);

        return true;
    }
}
```

O método retorna falso se a distância entre os pontos é menor que o diâmetro.
Nos demais casos, o círculo _c_, passado por referência, contém o centro e o
raio de um círculo que intercepta ambos _P_ e _Q_.

Para o caso _N = 3_ há uma interessante relação: se os pontos _P, Q, R_ não são
colineares, a equação do círculo que passa por estes três pontos pode ser
expressa pelo determinante abaixo.

![Equação do círculo que passa por 3 pontos](discriminante4D.png)

Este determinante também pode ser utilizado para determinar se 4 pontos são
cocirculares, substituindo as coordenadas do quarto ponto nas variáveis da
primeira linha.

Contudo, a implementação desta determinante não é trivial, uma vez que é preciso
recorrer a cofatores, e o resultado final não fica na forma canônica, de onde
são extraídas as informações sobre o raio e o centro.

Uma outra abordagem é observar que a distância entre os três pontos e o centro
do círculo são iguais e, das relações _d(P, C) = d(Q, C), d(P, C) = d(R, C)_,
encontrar um sistema linear em relação as coordenadas do centro. Determinado
o centro, o raio será a distância entre qualquer um dos pontos e o centro.
```C++
// Definição da classe Point e Circle

Circle circle_from_3_points(const Point& P, const Point& Q, const Point& R)
{
    auto a = 2*(Q.x - P.x);
    auto b = 2*(Q.y - P.y);
    auto c = 2*(R.x - P.x);
    auto d = 2*(R.y - P.y);

    auto det = a*d - b*c;

    // Pontos colineares
    if (equals(det, 0))
        return Circle();

    auto k1 = (Q.x*Q.x + Q.y*Q.y) - (P.x*P.x + P.y*P.y);
    auto k2 = (R.x*R.x + R.y*R.y) - (P.x*P.x + P.y*P.y);

    auto cx = (k1*d - k2*b)/det;
    auto cy = (a*k2 - c*k1)/det;

    Point C(cx, cy);
    auto r = C.distance(P);

    return Circle(C, r);
}
```

### Interseção entre dois círculos

Dados dois círculos com centros _C1, C2_ e raios _r1, r2_, existem cinco
cenários possíveis para suas interseções. Seja _d_ a distância entre os pontos
_C1_ e _C2_. Então

1. se _d > r1 + r2_, então os círculos não se interceptam;
2. se _d < |r1 - r2|_, então também não há interseção, pois um dos círculos (o de
menor raio) está contido no outro (o de maior raio);
3. se _d == 0_ e _r1 == r2_, então os círculos são idênticos: há infinitos pontos
de interseção;
4. se _d == r1 + r2_, os círculos se interceptam em um único ponto;
5. nos demais casos, há dois pontos na interseção entre os círculos.

Se _C1 = (x1, y1)_ e _C2 = (x2, y2)_, então as coordenadas dos pontos de
interseção _P1_ e _P2_ são dadas pelas expressões abaixo.

![Interseção entre dois círculos](circle_intersection.png)

```C++
// Definição das classes Point e Circle

#define INF -1

using pp = pair<Point, Point>;
using ipp = pair<int, pp>;

ipp intersection(const Circle& c1, const Circle& c2)
{
    double d = c1.C.distance(c2.C);

    if (d > c1.r + c2.r or d < fabs(c1.r - c2.r))
        return ipp(0, pp(Point(), Point()));

    if (equals(d, 0) and equals(c1.r, c2.r))
        return ipp(INF, pp(Point(), Point()));

    auto a = (c1.r * c1.r - c2.r * c2.r + d * d)/(2 * d);
    auto h = sqrt(c1.r * c1.r - a * a);

    auto x = c1.C.x + (a/d)*(c2.C.x - c1.C.x);
    auto y = c1.C.y + (a/d)*(c2.C.y - c1.C.y);

    auto P = Point(x, y);

    x = P.x + (h/d)*(c2.C.y - c1.C.y);
    y = P.y - (h/d)*(c2.C.x - c1.C.x);
    auto P1 = Point(x, y);

    x = P.x - (h/d)*(c2.C.y - c1.C.y);
    y = P.y + (h/d)*(c2.C.x - c1.C.x);

    auto P2 = Point(x, y);

    return ipp(equals(d, c1.r + c2.r) ? 1 : 2, pp(P1, P2));
}
```

### Interseção entre círculos e retas

Uma reta que passa pelos pontos _P1_ e _P2_ pode ser representada, na forma
paramétrica, pela expressão vetorial _P = P1 + u(P2 - P1)_, onde _u_ é uma
variável real. Assim, a coordenada _x_ de _P_ é dada por _x = x1 + u(x2 - x1)_;
de forma semelhante, a coordenada _y_ de _P_ é dada por _y = y1 + u(y2 - y1)_.

Se estas coordenadas forem levadas para a equação do círculo de centro
_C_ e raio _r_ (isto é, _(x - Cx)² + (y - Cy)² = r²)_, obtemos o polinômio
quadrático _au² + bu + c = 0_, onde

![Coeficientes da interseção entre círculo e reta](coefs.png)

O discriminante _D_ (delta) desta equação caracteriza as possíveis interseções:

1. se _D < 0_, não há interseção entre o círculo e a reta;
2. se _D == 0_, há um único ponto de interseção (a reta é tangente ao círculo);
3. se _D > 0_, há dois pontos distintos de interseção.

```C++
// Definição das classes Point e Circle

// Interseção entre o círculo c e a reta que passa por P e Q
ipp intersection(const Circle& c, const Point& P, const Point& Q)
{
    auto a = pow(Q.x - P.x, 2.0) + pow(Q.y - P.y, 2.0);
    auto b = 2*((Q.x - P.x) * (P.x - c.C.x) + (Q.y - P.y) * (P.y - c.C.y));
    auto d = pow(c.C.x, 2.0) + pow(c.C.y, 2.0) + pow(P.x, 2.0) + pow(P.y, 2.0)
        + 2*(c.C.x * P.x + c.C.y * P.y);

    auto D = b * b - 4 * a * d;

    if (D < 0)
        return ipp(0, pp(Point(), Point()));
    else if (equals(D, 0))
    {
        auto u = -b/(2*a);

        auto x = P.x + u*(Q.x - P.x);
        auto y = P.y + u*(Q.y - P.y);

        return ipp(1, pp(Point(x, y), Point()));
    }

    auto u = (-b + sqrt(D))/(2*a);

    auto x = P.x + u*(Q.x - P.x);
    auto y = P.y + u*(Q.y - P.y);

    auto P1 = Point(x, y);

    u = (-b - sqrt(D))/(2*a);

    x = P.x + u*(Q.x - P.x);
    y = P.y + u*(Q.y - P.y);

    auto P2 = Point(x, y);

    return ipp(2, pp(P1, P2));
}
```

<!--- Pontos cocirculares - determinante -->

### Exercícios

<!--- 2C - Interseção entre círculos, mediatriz, pontos proporcionalmente distantes de dois pontos dados -->
<!--- 190 - Equações do círculo a partir de 3 pontos -->
<!--- 438 - Circunferência do círculo a partir de 3 pontos -->
<!--- 10005 - Empacotamento de pontos -->
<!--- 10209 - Cordas, Setores e Segmentos (Triângulos e Círculos) --->
<!--- 10221 - Cordas e Arcos -->
<!--- 10573 - Área de círculos  -->
<!--- 10589 - Relação ponto x círculo --->
<!--- 10678 - Área de Elipses! --->
<!--- 12578 - Área de retângulo e círculo --->
1. Codeforces
    1. [2C - Commentator Problem](http://codeforces.com/problemset/problem/2/C)
1. UVA
    1. [190 - Circle Through Three Points](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=126&mosmsg=Submission+received+with+ID+17867754)
    1. [438 - The Circumference of the Circle](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=379&mosmsg=Submission+received+with+ID+17859473)
    1. [10005 - Packing Polygons](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=946)
    1. [10209 - Is This Integration?](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1150)
    1. [10221 - Satellites](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1162&mosmsg=Submission+received+with+ID+17966499)
    1. [10563 - Geometry Paradox](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1514&mosmsg=Submission+received+with+ID+17971797)
    1. [10589 - Area](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1530)
    1. [10678 - The Grazing Cow](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1619&mosmsg=Submission+received+with+ID+17708795)
    1. [12578 - 10:6:2](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=4023&mosmsg=Submission+received+with+ID+17708746)

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

BOURKE, Paul. [Intersection of two circles](http://paulbourke.net/geometry/circlesphere/). Acesso em 06/08/2016.

QC.EDU.HK. [Equation of circle passing through 3 givem points](http://www.qc.edu.hk/math/Advanced%20Level/circle%20given%203%20points.htm). Acesso em 18/08/2016.

Stack Exchange. [Mathematics: Get the equation of a circle when given 3 points](http://math.stackexchange.com/questions/213658/get-the-equation-of-a-circle-when-given-3-points). Acesso em 18/08/2016.

