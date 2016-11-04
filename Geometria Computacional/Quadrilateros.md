Quadriláteros
-------------

Quadriláteros são figuras geométricas bidimensionais compostas por quatro
vértices, quatro arestas e quatro ângulos internos. As relações entre o lados
e os ângulos internos permitem a classificação dos quadriláteros, sendo o
retângulo o mais comum dentre eles.

### Retângulos

Um **retângulo** é um quadrilátero com os quatro ângulos internos iguais (cada
ângulo tem 90º: a soma dos ângulos internos de um quadrilátero é igual a
360º).

Os pares de lados opostos (paralelos) de um retângulo são denominados **base** e
**altura**. Deste modo, um retângulo pode ser representado de duas formas:
a primeira dleas é através da medida de sua base e sua altura.
```C++
class Rectangle {
public:
    double b, h;

    Rectangle(double base, double height) : b(base), h(height) {}
};
```
A segunda maneira é representar o triângulo através das coordenadas de vértices
opostos. Na matemática o mais comum é utilizar o canto inferior esquerdo e o
canto superior direito; na computação gráfica, é o contrário: o canto superior
esquerdo e o canto inferior direito. Esta representação tem a vantagem porque
permite a fácil dedução da base e da altura, e dá flexibilidade na implementação
de algoritmos que agem sobre retângulos.
```C++
// Definição da classe Point

class Rectangle {
public:
    Point P, Q;
    double b, h;

    Rectangle(const Point& p, const Point& q) : P(p), Q(q)
    {
        b = fabs(P.x - Q.x);
        h = fabs(P.y - Q.y);
    }

    Rectangle(double base, double height)
        : P(0, 0), Q(base, height), b(base), h(height) {}
};
```
O perímetro de um retângulo é igual ao dobro da soma de suas dimensões (base e
altura); ja á área é o produto de suas dimensões.
```C++
class Rectangle {
public:
    // Membros e construtores

    double perimeter() const
    {
        return 2 * (b + h);
    }

    double area() const
    {
        return b * h;
    }
};
```
Um **quadrado** é um retângulo com lados iguais. Não há necessidade de
implementar uma classe à parte para os quadrados, uma vez que todos os
resultados válidos para os retângulos permanecem válidos para os quadrados.

A interseção entre dois retângulos pode ser determinada a partir da interseção
entre dos intervalos referentes às projeções dos retângulos nos eixos _x_ e
_y_. A interseção pode ser vazia (não há interseção), um segmento de reta ou
um retângulo. Os últimos dois cenários podem ser diferenciados através da
área do retângulo resultante (área igual a zero significa um segmento de reta).
```C++
// Definição da classe Point
using interval = pair<double, double>;

class Rectangle {
public:
    // Membros e construtores

    bool intersection(const Rectangle& r, Rectangle& inter) const
    {
        auto I = interval(min(P.x, Q.x), max(P.x, Q.x));
        auto U = interval(min(r.P.x, r.Q.x), max(r.P.x, r.Q.x));

        auto a = max(I.first, U.first);
        auto b = min(I.second, U.second);

        if (b < a)
            return false;

        I = interval(min(P.y, Q.y), may(P.y, Q.y));
        U = interval(min(r.P.y, r.Q.y), may(r.P.y, r.Q.y));

        auto c = max(I.first, U.first);
        auto d = min(I.second, U.second);

        if (d < c)
            return false;

        inter = Rectangle(Point(a, c), Point(b, d));

        return true;
    }
};
```

O caso geral, os lados do retângulo não estão alinhados com os eixos _x_ e _y_,
pode ser tratado interpretando o retângulo como um [polígono](Polygon.md) de
quatro lados.

### Trapézios

Um **trapézio** é um quadrilátero que possui apenas um par de lados
paralelos. Quando os lados não-paralelos são iguais, o trapézio é dito
**isósceles**.

Os lados paralelos são denominados **base maior** (_B_) e **base menor**
(_b_). A distância entre os lados paralelos é denominada **altura** (_h_).
```C++
class Trapezium {
public:
    double b, B, h;

    Trapezium(double bv, double Bv, double hv) : b(bv), B(Bv), h(hv) {}
};
```

A área de um trapézio é dada pela metade do produto entre a altura e a soma de
suas bases.
```C++
class Trapezium {
public:
    // Membros e construtores

    double area() const
    {
        return 0.5 * (b + B) * h;
    }
};
```

### Paralelogramos

Um **paralelogramo** é um quadrilátero cujos lados opostos são paralelos.
Além do retângulo e do quadrado, outro paralelogramo notável é o
**losango**, que é um paralelogramo cujos lados opostos são iguais (mas não
necessariamente os ângulos internos).

A área de um paralelogramo é dado pelo produto de sua base pela altura. Em geral,
é preciso determinar a altura, considerando um dos lados como base e usando
o ângulo formado com um dos lados adjacentes para montar um triângulo, onde a
altura seria o cateto oposto ao ângulo.

No caso do losango, a área pode ser determinada diretamente se conhecidas as
medidas das duas diagonais (_D_ e _d_, denominadas diagonal maior e menor,
respectivamente). Neste caso, a área é a metade do produto das diagonais, isto é,
_A = (Dd)/2_.

### Exercícios

<!--- 155 - Padrões, interseção ponto/quadrado -->
<!--- 490 - Interseção de retângulos -->
<!--- 11207 - Divisão de retângulos em quadrados -->
<!--- 11000 - Identificação de quadriláteros, ccw, dot() e cross() -->
<!--- 11345 - Interseção de retângulos, área de retângulos -->
<!--- 11455 - Desigualdade "Quadrangular", classificação de quadriláteros -->
<!--- 11639 - Interseção de retângulos, área de retângulos -->
<!--- 11834 - Packing círculos em retângulos -->
<!--- 12256 - Desigualdade "Quadrangular", DP -->
<!--- 1A - Divisão de retângulos em quadrados -->
1. UVA
    1. [155 - All Squares](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=91&mosmsg=Submission+received+with+ID+18024857)
    1. [490 - Overlapping Rectangles](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=401)
    1. [11207 - The easiest way](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2148&mosmsg=Submission+received+with+ID+17770469)
    1. [11345 - Rectangles](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2320&mosmsg=Submission+received+with+ID+18024702)
    1. [11455 - Behold my quadrangle](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2450&mosmsg=Submission+received+with+ID+18010785)
    1. [11639 - Guard the Land](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2686&mosmsg=Submission+received+with+ID+18021274)
    1. [11800 - Determine the Shape](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2900&mosmsg=Submission+received+with+ID+18005326)
    1. [11834 - Elevator](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2934&mosmsg=Submission+received+with+ID+17770779)
    1. [12256 - Making Quadrilaterals](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=3408&mosmsg=Submission+received+with+ID+18021163)
1. Codeforces
    1. [1A - Theatre Square](http://codeforces.com/problemset/problem/1/A)

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.
