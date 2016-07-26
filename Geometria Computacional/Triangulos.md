Triângulos
----------

Os triângulos são polígonos com três vértices e três arestas. É o mais 
simples dos polígonos, mas guarda uma série de propriedades e características
notáveis.

### Representação de triângulos

Um triângulo pode ser representado ou pelas coordenadas de seus vértices ou
pela medida de seus três lados. A segunda representação pode ser deduzida
a partir da primeira, mas no sentido oposto haveriam infinitas possibilidades.

```C++
// Definição da classe Ponto

class Triangle {
public:
    Point A, B, C;

    Triangle(const Point& P, const Point& Q, const Point& R) : A(P), B(Q), C(R) {}
}
```

A representação através dos vértices pode levar a um caso especial: se os 
três pontos estiverem alinhados, o triângulo se degenera em um segmento de reta.

```C++
// Definição da classe Ponto

class Triangle {
public:
    double a, b, c;

    Triangle(double av, double bv, double cv) : a(av), b(bv), c(cv) {}
}
```

Já na representação pelas medidas dos três lados, o número de casos especiais
aumenta: além do caso degenerado (quanto a soma de dois lados coincide com o
terceiro), há o perigo das medidas não formarem um triângulo de fato: a 
**Desigualdade Triangular** garante que, dadas as medidas _a, b, c_ dos lados
do triâgulo, a soma de duas destas medidas é sempre maior do que a medida
restante.

### Classificação de triângulos

Os triângulos podem ser classificados pela medida de seus lados ou de seus
ângulos internos.

Sejam _a, b, c_ as medidas dos três lados de um triângulo. O triângulo é dito 
**equilátero** se _a = b = c_; **isósceles** se dois lados são iguais (e 
diferentes do terceiro); ou **escaleno** se todos os três valores forem
distintos.
```C++
class Triangle {
public:
    // Membros e construtor
    
    typedef enum { EQUILATERAL, ISOSCELES, SCALENE } Sides;

    Sides classification_by_sides() const
    {
        if (a == b and b == c)
            return EQUILATERAL;

        if (a == b or a == c or b == c)
            return ISOSCELES;

        return SCALENE;
    }
}
```

Sejam _BC, AC, AB_ os ângulos opostos aos lados _a, b, c_ de um triângulo.
O triângulo é dito **retângulo** se um dos três ângulo é igual a 90º;
**obstusângulo** se um dos três ângulo é maior que 90º; ou **acutângulo** se
todos os três ângulos forem menores que 90º (lembrando que 
_AB + AC + BC = 180º_).

É possível determinar os ângulos internos de um triângulo através da 
**Lei dos Cossenos**, enunciada abaixo.

![Lei dos Cossenos](cosine_law.png)

```C++
class Triangle {
public:
    // Membros e construtor
    
    typedef enum { RIGHT, ACUTE, OBTUSE } Angles;

    Angles classification_by_angles() const
    {
        auto AB = acos((c*c - a*a - b*b)/(2*a*b));
        auto AC = acos((b*b - a*a - c*c)/(2*a*c));
        auto BC = acos((a*a - b*b - c*c)/(2*b*c));

        auto right = PI / 2.0;

        if (equals(AB, right) or equals(AC, right) or equals(BC, right))
            return RIGHT;

        if (AB > right or AC > right or BC > right)
            return OBTUSE;

        return ACUTE;
    }
}
```

Se for necessário verificar apenas se o triângulo é retângulo ou não, basta
utilizar o **Teorema de Pitágoras**: o quadrado da hipotenusa (maior lado) é
igual a soma dos quadrados dos outros lados (catetos). O Teorema de Pitágoras
pode ser deduzido da Lei dos Cossenos fazendo _c_ igual a hipotenusa e 
_AB = 90º_.

### Perímetro e área

O perímetro de um triângulo é igual a soma das medidas dos seus lados.
```C++
class Triangle {
public:
    // Membros e construtor
 
    double perimeter() const
    {
        return a + b + c;
    }
}
```

A área delimitada pelo triângulo pode ser determinada de três maneiras.
A primeira delas é computar a metade do produto entre a **base** (o comprimento
de um dos lados do triângulo) e a **altura** (segmento de reta, ortogonal à base,
com um ponto sobre a base e o outro no vértice oposto a esta). Contudo,
na representação por pontos ou pelas medidas, esta abordagem é pouco prática,
pois envolve o cálculo da altura.

A segunda maneira é utilizar a **Fórmula de Heron**, dada abaixo,
onde _A_ é a área do triângulo de lados _a, b, c_ e _s_ é o semiperímetro 
(metade do perímetro). Esta abordagem é a mais 
apropriada na representação do triângulo pela medida de seus lados.

![Fórmula de Heron](heron.png)

```C++
class Triangle {
public:
    // Membros e construtor
    
    // Perímetro
 
    double area() const
    {
        auto s = perimetro() / 2.0;

        return sqrt(s*(s - a)*(s - b)*(s - c));
    }
}
```

A terceira maneira é computar a área a partir das coordenadas dos vértices.
Se os vértices de um triângulo são _P = (x1, y1), Q = (x2, y2), R = (x3, y3)_,
a área _A_ do triângulo é dada pela metade do módulo do determinante mostrado
abaixo.

![Área por determinante](detarea.png)

Naturalmente, esta é a melhor abordagem para a representação do triângulo pelas
coordenadas de seus vértices.
```C++
class Triangle {
public:
    // Membros e construtor
    
    double area() const
    {
        double det = (A.x*B.y + A.y*C.x + B.x*C.y) - (C.x*B.y + C.y*A.x + B.x*A.y);

        return 0.5 * fabs(det);
    } 
}
```
