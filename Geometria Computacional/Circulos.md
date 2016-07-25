Circulos
--------

Um círculo é o conjunto de pontos equidistantes de um ponto _C_. A distância
de um ponto do círculo ao seu **centro** _C_ é denominada **raio** do círculo.

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
constante PI. Caso o problema não informe o valor a ser utilizado, há duas
maneira de proceder para determinar o valor desta constante. A primeira é 
utilizar o valor definido na linguagem python, que pode ser obtido com o 
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

O perímetro é o comprimento do contorno do círculo, e é igual a PI vezes o seu
diâmetro, sendo o diâmetro o dobro do raio do círculo.
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
(caso _a_ esteja em radianos).

```C++
// Definição do valor de PI

class Circle {
public:

    // Membros e construtores
    // Perímetro e área

    double arc(double a) const
    {
        return (a / (2*PI)) * perimeter();
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
central _a_ do arco que delimita o setor.

```C++
// Definição do valor de PI

class Circle {
public:

    // Membros e construtores
    // Perímetro e área

    double sector(double a) const
    {
        return (a / (2*PI)) * area();
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


### Exercícios

<!--- 10209 - Cordas, Setores e Segmentos (Triângulos e Círculos) --->
<!--- 10589 - Relação ponto x círculo --->
<!--- 10678 - Área de Elipses! --->
<!--- 12578 - Área de retângulo e círculo --->
1. UVA
    1. [10209 - Is This Integration?](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1150)
    1. [10589 - Area](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1530)
    1. [10678 - The Grazing Cow](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1619&mosmsg=Submission+received+with+ID+17708795)
    1. [12578 - 10:6:2](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=4023&mosmsg=Submission+received+with+ID+17708746)

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.
