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
`
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

### Igualdade e paralelismo
