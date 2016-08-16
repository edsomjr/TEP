Retas
-----

As retas são elementos unidimensionais da geometria e, assim como a palavra
ponto, reta também é um termo primitivo da geometria.

### Representação de retas

Existem duas representações principais da reta: a equação reduzida e a
equação geral. A equação reduzida de uma reta é a mais conhecida e utilizada
nos cursos de ensino médio, e tem a vantagem de facilitar comparações entre
retas e identificar paralelismo; porém não é capaz de representar retas 
verticais. A equação geral, como o próprio nome diz, pode representar qualquer
reta do plano.

A equação **reduzida** da reta tem a forma _y = mx + b_, onde _m_ é o coeficiente
angular da reta e _b_ é o coeficiente linear da reta. O primeiro coeficiente
representa a variação da reta: consiste no número de unidades que _y_ varia
para cada unidade de variação de _x_ no sentido positivo do eixo horizontal.
O segundo coeficiente é o valor no qual a reta intercepta o eixo _y_.

Baseado na equação reduzida da reta, pode-se representar uma reta, em C/C++,
utilizando-se uma classe ou estrutura da seguinte forma:

```C++
class Line {
public:
    double m;
    double b;

    Line(double mv, double bv) : m(mv), b(bv) {}
};
```

Conforme dito anteriormente, esta representação não permite a representação
de retas verticais. Tal limitação pode ser contornada através do uso de uma
variável booleana, que indica se a reta é ou não vertical. Em caso 
afirmativo, o coeficiente _b_ passa a ser interpretado como o valor no
qual a reta intercepta o eixo _x_.

```C++
class Line {
public:
    double m;
    double b;
    bool vertical;

    Line(double mv, double bv, bool v = false) : m(mv), b(bv), vertical(v) {}
};
```


Dados dois pontos _P = (x1, y1)_ e _Q = (x2, y2)_, com _x1 != x2_, temos
_m = (y2 - y1)/(x2 - x1)_ e pode-se verificar que a reta que passa por 
_P_ e _Q_ tem equação reduzida _y = m(x - x1) + y1_.

```C++
// Definição da classe Point

class Line {
public:
    double m;
    double b;
    bool vertical;

    Line(double mv, double bv, bool v = false) : m(mv), b(bv), vertical(v) {}

    Line(const Point& p, const Point& q)
    {
        if (p.x == q.x)     // Reta vertical
        {
            b = p.x;
            vertical = true;
        } else
        {
            m = (p.y - q.y) / (p.x - q.x);
            b = p.y - p.x * m;
            vertical = false;
        }
    }
};
```

A equação **geral** da reta tem a forma _ax + by + c = 0_ e, como dito, pode
representar retas verticais (onde _b = 0_). Nos demais casos, é possível 
obter a equação reduzida a partir da equação geral. 

```C++
class Line {
public:
    double a;
    double b;
    double c;

    Line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}
};
```

Dados dois pontos _P = (x1, y1)_ e _Q = (x2, y2)_, o coeficiente _c_ pode 
ser obtido pela substituição direta das coordenadas de um dos dois pontos na
equação geral. Conhecido o valor de _c_, pode-se obter os outros dois 
coeficientes resolvendo um sistema linear, cujas equações são resultante das
substituições das coordenadas dos dois pontos.

Contudo, este processo pode ser simplificado com o uso de Álgebra Linear: se
três pontos _P = (x1, y1), Q = (x2, y2)_ e _R = (x, y)_ são colineares 
(isto é, pertencem a uma mesma reta), então o determinante abaixo se anula.

![DiscriminanteRetas2D](discriminante2D.png)

Desta forma, temos _a = y1 - y2, b = x2 - x1, c = x1y2 - x2y1_. Importante
notar que este determinante, além de permitir a identificação dos coeficientes
da equação geral da reta, pode ser utilizado para determinar outras relações,
conforme será explicado mais adiante.

```C++
// Definição da classe Point

class Line {
public:
    double a;
    double b;
    double c;

    Line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

    Line(const Point& p, const Point& q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - p.y * q.x;
    }
};
```

Um mesma reta pode ter infinitas equações gerais associadas: basta multiplicar
toda a equação por uma número real diferente de zero. Para normalizar a 
representação, associando uma única equação a cada reta, é necessário dividir
toda a equação pelo coeficiente _a_ (ou por _b_, caso _a_ seja igual a zero).
Esta estratégia permite a simplificação de algoritmos de comparação entre
retas.

```C++
// Definição da classe Point

class Line {
public:
    double a;
    double b;
    double c;

    Line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

    Line(const Point& p, const Point& q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - p.y * q.x;

        auto k = a ? a : b;

        a /= k;
        b /= k;
        c /= k;
    }
};
```

Importante notar que, em ambas representações, pode acontecer da reta 
resultante ser **degenerada**. Isto ocorre quando os pontos _p_ e _q_ são
idênticos: neste caso, a reta se reduz a um único ponto. O tratamento deste
caso especiais nos demais algoritmos aumenta o tamanho e complexidade dos
códigos. Dado o aspecto didático deste material, este caso será ignorado
deste ponto em diante, mas o leitor é incentivado a tratá-lo em seus códigos.

### Retas paralelas, concorrentes, coincidentes e perpendiculares

Em relação às possíveis interseções entre duas retas, há três cenários possíveis:
nenhum ponto em comum, um único ponto em comum ou todos os pontos em comum. No
primeiro caso as retas são ditas **paralelas**; no segundo caso, 
**concorrentes**; no último, **coincidentes**.

O coeficiente angular é a chava para tal classificação: retas com coeficientes
angulares distintos são concorrentes. Na coincidência destes concorrentes, é
necessário verificar também o coeficiente linear: se iguais, as retas são
coincidentes. Retas com coeficientes angulares iguais e coeficientes lineares
distintos são paralelas.

A implementação destas verificações é trivial na representação baseada na
equação reduzida, sendo necessário apenas o cuidado no trato do caso das
retas verticais.

```C++

#define EPS 1e-9

bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

class Line {
public:
    double m;
    double b;
    bool vertical;

    // Construtores

    bool operator==(const Line& r) const    // Verdadeiro se coincidentes
    {
        if (vertical != r.vertical || !equals(m, r.m))
            return false;

        return equals(b, r.b);
    }


    bool parallel(const Line& r) const // Verdadeiro se paralelas
    {
        if (vertical and r.vertical)
            return b != r.b;

        if (vertical or r.vertical)
            return false;

        return equals(m, r.m) && !equals(b, r.b);
    }
};
```

No caso da representação baseada na equação geral da reta, para checar se retas
são paralelas (ou coincidentes) basta verificar o determinante dos coeficientes
do sistema linear formado por ambas retas: se zero, as retas serão paralelas 
ou coincidentes.

```C++
// Definição de reta baseada na equação geral

bool parallel(const Line& r, const Line& s)     // Verdadeiro se coincidentes!
{
    return equals(r.a * s.b - r.b * s.a, 0);
}
```

Nesta abordagem, para verificar se as retas são coincidentes, é necessário 
comparar também os coeficientes _c_: se _c_ == _r.c_, as retas serão
coincidentes.

Duas retas serão **perpendiculares** se o produto de seus coeficientes angulares
for igual a -1. Outra maneira de checar se duas retas são perpendiculares é
escolher dois pontos pertencentes a cada reta e montar dois vetores _u_ e _v_
cujas coordenadas são a diferença entre as coordenadas dos pontos escolhidos.
Se o produto interno dos dois vetores for igual a zero, as retas são
perpendiculares.

```C++
// Definição da comparação entre doubles (função equals())

class Line {
public:
    double m;
    double b;
    bool vertical;

    // Construtores

    bool orthogonal(const Line& r) const // Verdadeiro se perpendiculares
    {
        if (vertical and r.vertical)
            return false;

        if ((vertical && equals(r.m, 0)) || (equals(m, 0) && r.vertical))
            return true;

        if (vertical or r.vertical)
            return false;

        return equals(m * r.m, -1.0);
    }
};
```


### Interseção entre retas

Como dito anteriormente, dado um par de retas, elas podem ser coincidentes
(infinitas interseções), paralelas (nenhuma interseção) ou concorrentes
(um único ponto de interseção).

Para encontrar o ponto de interseção, no caso de retas concorrentes, basta
resolver o sistema linear resultante das equações gerais das duas retas.

```C++
// Definição da comparação entre doubles (função equals())

// Definições das classes Point e Line

#define INF -1

pair<int, Point> intersections(const Line& r, const Line& s)
{
    auto det = r.a * s.b - r.b * s.a;

    if (equals(det, 0))
    {
        auto kr = r.a ? r.a : r.b;
        auto ks = s.a ? s.a : s.b;

        auto ar = r.a / kr;
        auto br = r.b / kr;
        auto cr = r.c / kr;

        auto as = s.a / ks;
        auto bs = s.b / ks;
        auto cs = s.c / ks;

        // Coincidentes
        if (equals(ar, as) && equals(br, bs) && equals(cr, cs))
            return pair<int, Point>(INF, Point());
        else    
            return pair<int, Point>(0, Point());    // Paralelas
    } else  // Concorrentes
    {
        double x = (-r.c * s*b + s.c * r.b) / det;
        double y = (-s.c * r.a + r.c * s.a) / det;

        return pair<int, Point>(1, Point(x, y));
    }
}
```

### Ângulos entre retas

Para mensurar o ângulo formado por duas retas (ou dois segmentos de reta), é
preciso identificar os vetores _u_ e _v_ de direção das duas retas e usar o 
produto interno. Dados dois pontos _P = (x1, y1)_ e _Q = (x2, y2)_, o vetor
de direção da reta que passa por _P_ e _Q_ é dado por _u = (x1 - x2, y1 - y2)_.

De posse dos vetores de direção, o cosseno ângulo entre as retas é dado pela 
expressão abaixo:

![Ângulo entre vetores](angle.png)

Para achar o ângulo, basta computar a função inversa do cosseno (`acos`, na
biblioteca de matemática padrão do C/C++) no lado direito da expressão acima.

```C++
// Definição da classe Point

// Ângulo entre os segmentos de reta PQ e RS
double angle(const Point& P, const Point& Q, const Point& R, const Point& S)
{
    auto ux = P.x - Q.x;
    auto uy = P.y - Q.y;
    
    auto vx = R.x - S.x;
    auto vy = R.y - S.y;

    auto num = ux * vx + uy * vy;
    auto den = hypot(ux, uy) * hypot(vx, vy);

    // Caso especial: se den == 0, algum dos vetores é degenerado: os dois
    // pontos são iguais. Neste caso, o ângulo não está definido

    return acos(num / den);
}
``` 

### Distância de um ponto a uma reta

A distância de um ponto _P_ a uma reta _r_ é definida como a menor distância 
possível entre todos os pontos de _r_ e _P_. Contudo, não é necessário computar
estas infinitas distâncias possíveis: a menor distância será aquela entre _P_
e o ponto de interseção _Q_ de _r_ com a reta perpendicular a _r_ que passa por
_P_.

Seja usando álgebra, geometria ou álgebra linear, é possível mostrar que 
esta distância _d_ entre _P = (x0, y0)_ e a reta _ax + by + c = 0_ é dada por

![Distância de um ponto a uma reta](distPointLine.png)

As coordenadas de _Q = (x1, y1)_ podem ser obtidas utilizando-se as expressões 
abaixo

![Ponto mais próximo](closestPoint.png)

Abaixo temos a implementação da distância e do ponto mais próximo em C++.

```C++
// Definição da classe Point

class Line {
public:
    double a;
    double b;
    double c;

    // Construtores

    double distance(const Point& p) const
    {
        return fabs(a*p.x + b*p.y + c)/hypot(a, b);
    }

    Point closest(const Point& p) const // Ponto da reta mais próximo de p
    {
        auto den = a*a + b*b;
        auto x = (b*(b*p.x - a*p.y) - a*c)/den;
        auto y = (a*(-b*p.x + a*p.y) - b*c)/den;

        return Point(x, y);
    }
};
```

Importante notar que, no caso de segmentos de retas, é preciso considerar os
extremos do segmento, pois ao usar a abordagem acima o ponto _Q_ pode estar
fora do segmento. Assim, o ponto mais próximo (e a respectiva distância) será
o mais próximo entre os dois extremos e _Q_.

```C++
// Definição das classes Point e Line

// Ponto mais próximo de M no segmento de reta [from, to]
Point closestToSegment(const Point& from, const Point& to, const Point& M) 
{
    Line r(from, to);

    auto Q = r.closest(M);
    auto min_x = min(from.x, to.x);
    auto max_x = max(from.x, to.x);

    if (Q.x <= min_x or Q.x >= max_x)      // Q está fora do intervalo
    {                                      // trocar <= por < resulta em WA! 
        auto distA = M.distance(from);     // (retas verticais)
        auto distB = M.distance(to);

        if (distA <= distB)
            return from;
        else
            return to;
    } else
        return Q;
}
```

### Reta mediatriz

Dado o segmento de reta _PQ_, a **mediatriz** é a reta perpendicular a _PQ_ que
passa pelo ponto médio do segmento. Qualquer ponto da reta mediatriz é 
equidistante de _P_ e _Q_, e esta propriedade permite a dedução dos coeficientes
_a, b, c_ da mediatriz.
```C++
// Definição das classes Point e Line

Line perpendicular_bisector(const Point& P, const  Point& Q)
{
    auto a = 2*(Q.x - P.x);
    auto b = 2*(Q.y - P.y);
    auto c = (P.x * P.x + P.y * P.y) - (Q.x * Q.x + Q.y * Q.y);

    return Line(a, b, c);
}
```

### Orientação entre Ponto e Reta

Conforme dito anteriormente, o determinante utilizado para o cálculo dos 
coeficientes da equação geral da reta também identifica a orientação de um
ponto em relação a uma reta. Se _r_ é uma reta que passa pelos pontos _P_ e 
_Q_, e _R_ é um ponto qualquer, o determinante abaixo permite identificar se
o ponto _R_ pertence a reta (_D = 0_), ou está no  semiplano à esquerda 
(_D > 0_) ou no semiplano à direita (_D < 0_). A orientação
(esquerda ou direita) diz respeito à direção que vai de _P_ a _Q_.

![Discriminante](discriminante.png)

```C++
// Definição da classe Point

// D = 0: R pertence a reta PQ
// D > 0: R à esquerda da reta PQ
// D < 0: R à direita da reta PQ
double D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

```
### Exercícios

<!--- 378 - Interseção entre retas -->
<!--- 920 - Interseção entre retas, comprimento de segmentos -->
<!--- 10263 - Distância entre ponto e segmento de reta -->
<!--- 10927 - Pontos colineares -->
<!--- 11068 - Interseção entre retas -->
1. UVA: 
    1. [378 - Intersecting Lines](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=314)
    1. [920 - Sunny Mountains](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=861)
    1. [10263 - Railway](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1204)
    1. [10927 - Bright Lights](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1868)
    1. [11068 - An Easy Task](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2009)

<!--- 1834 - Orientação -->
<!--- 1631 - Orientação, Distância de Ponto a Reta -->
1. URI:
    1. [1631 - O Fantástico Bolo de Bobby](https://www.urionlinejudge.com.br/judge/pt/problems/view/1631)
    1. [1834 - Vogons!](https://www.urionlinejudge.com.br/judge/pt/problems/view/1834)

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

SKIENA, Steven S.; REVILLA, Miguel A. [Programming Challenges: The Programming Contest Training Manual](http://www.programming-challenges.com/), Springer, 2002.

STRANG, Gilbert. [Introdução à Álgebra Linear](http://www.submarino.com.br/produto/116582671/livro-introducao-a-algebra-linear), 4ª edição, LTC, 2013.

Wikipédia. [Distance from a point to a line](https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line), acesso em 13 de julho de 2016.

