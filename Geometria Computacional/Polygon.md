Polígonos
---------

Polígonos são figuras planas delimitadas por caminhos fechados (o vértice de
partida é o vértice de chegada), compostos por segmentos de retas que une
pontos (**vértices**) consecutivos. Os segmentos que unem os vértices são 
denominados **arestas**.

A maior parte dos problemas de Geometria Computacional envolvem polígonos. 
Embora alguns polígonos especiais (triângulos, quadriláteros) já tenham sido
expostos anteriormente, a abordagem desta seção é mais geral, e pode ser 
aplicada a qualquer polígono com qualquer número de vértices.

### Representação de polígonos

A representação mais comum de um polígono é a listagem de seus vértices, sendo
que as arestas ficam subentendidas (há sempre uma aresta unindo dois vértice
consecutivos). Para facilitar a implementação de algumas rotinas, pode ser
conveniente inserir, ao final da lista, o ponto de partida, mas é preciso
tomar cuidado: ao fazer isso, o número de vértices do polígono passa a ser
o número de elementos da lista subtraído de uma unidade.
```C++
// Definição da classe Point

using Polygon = vector<Point>;
```

Esta primeira implementação é a mais compacta possível, mas requer atenção
a questão do número de vértices, conforme já comentado. A implementação abaixo
é mais extensa, porém evita os problemas já mencionados.
```C++
// Definição da classe Point

class Polygon {
public:
    vector<Point> vertices;
    int n;

    // O parâmetro deve conter os n vértices do polígono
    Polygon(const vector<Point>& vs) : vertices(vs), n(vs.size())
    {
        vertices.push_back(vertices[0]);
    }
};
```

Importante notar que ambas implementações não checam a validade do polígono
no que se refere ao número de vértices: um polígono deve ter, no mínimo,
três vértices.

### Perímetro e área

O perímetro de um polígono pode ser calculado diretamente da representação 
proposta, pois consiste na medida do contorno do polígono, isto é, a soma dos
comprimentos de cada aresta.
```C++
// Definição da classe Point

class Polygon {
public:
    // Membros e construtor

    double perimeter() const 
    {
        double p = 0;

        for (int i = 0; i < n; ++i)
            p += vertices[i].distance(vertices[i + 1]);

        return p;
    }
};
```
Já a área de um polígono pode ser também determinada diretamente da 
representação dada. Ela corresponde a metade do valor absoluto do 
"determinante" abaixo (as 
aspas significam que a notação remete a um determinante, mas não é um 
determinante de fato, uma vez que a matriz não é quadrada). 

![Área de um polígono](area.png)

```C++
// Definição da classe Point

class Polygon {
public:
    // Membros e construtor

    double area() const 
    {
        double a = 0;

        for (int i = 0; i < n; ++i)
        {
            a += vertices[i].x * verticies[i+1].y;
            a -= vertices[[i+1].x * vertices[i].y;
        }

        return 0.5 * fabs(a);
    }
};
```     

### Polígonos côncavos e convexos

Um polígono é dito **convexo** se, para quaisquer dois pontos _P_ e _Q_ 
localizados no interior do polígono, o segmento de reta _PQ_ não intercepta
nenhuma das arestas do polígono. Caso contrário, o polígono é dito **convexo**.

É possível determinar se um polígono é ou não convexo sem recorrer à busca 
completa (isto é, testar todos os possíveis pares de pontos interiores ao
polígono): 
a rotina de orientação entre pontos e reta (discutida na seção [Retas](Retas.md))
pode ser utilizada para tal fim. Basta checar se, para quaisquer três pontos 
consecutivos do polígono, eles tem a mesma orientação (ou sempre a esquerda,
ou sempre à direita).
```C++
// Definição da classe Point

// Implementação da função de orientação D

class Polygon {
public:
    // Membros e construtor

    bool is_convex() const
    {
        vector<Point> vs(vertices);

        if (n < 3)
            return false;

        vs.push_back(vs[1]);    // Temporário/inserção evitam um if no laço

        int orientation = 0, i;

        for (i = 0; i < n; ++i)
        {
            int d = D(vs[i], vs[i + 1], vs[i + 2]);

            if (d == 0)
                continue;

            orientation = d;
        }

        for (; i < n; ++i)
        {
            int d = D(vs[i], vs[i + 1], vs[i + 2]);

            if (d == -orientation)
                return false;
        }

        return orientation != 0;
    }
};
```

### Relação entre pontos e polígonos

Para se verificar se um ponto _P_ está localizado, ou não, no interior de um
polígono, basta computar a soma dos ângulos formados por _P_ e dois 
vértices do polígono (somando-se se o ponto está na mesma orientação do polígono,
subtraíndo em caso contrário): se a soma totalizar _2PI_, o ponto está no
interior do polígono. Esta verificação vale tanto para polígonos convexos 
quanto côncavos.
```C++
// Definição da classe Point

// Definição de PI, da função equals() do discriminante D()

// Ângulo APB, em radianos
double angle(const Point& P, const Point& A, const Point& B)
{
    auto ux = P.x - A.x;
    auto uy = P.y - A.y;

    auto vx = P.x - B.x;
    auto vy = P.y - B.y;

    auto num = ux * vx + uy * vy;
    auto den = hypot(ux, uy) * hypot(vx, vy);

    // Caso especial: se den == 0, algum dos vetores é degenerado: os dois
    // pontos são iguais. Neste caso, o ângulo não está definido

    return acos(num / den);
}

class Polygon {
public:
    // Membros e construtores

    bool contains(const Point& P) const
    {
        if (n < 3)
            return false;

        auto sum = 0.0;

        for (int i = 0; i < n; ++i)
        {
            auto d = D(P, vertices[i], vertices[i + 1]);

            // Pontos sobre as arestas ou vértices são considerados interiores
            if (equals(d, 0))
                return true;

            auto a = angle(P, vertices[i], vertices[i + 1]);

            sum += d < 0 ? a : -a;
        } 
    
        return equals(fabs(sum), 2*PI);
    }
};
```

### Relação entre polígonos e retas

Dada uma reta _r_, que passa pelos pontos _A_ e _B_, e um polígono convexo _P_, 
com
_n_ vértices, esta reta secciona o polígono em duas regiões, esquerda e direita,
que podem ser ou uma vazias e outra contendo _P_ integralmente, ou serem 
compostas de dois polígonos convexos _P1_ e _P2_, resultantes do corte de _P_
por _r_.

A rotina `cut_polygon()`, apresentada abaixo e adaptada de 
[Competitive Programming 3](http://cpbook.net/), retorna a região a esquerda
do corte, considerando que _P_ está descrito no sentido anti-horário.
```C++
// Definição da classe Point, da função equals() e do discriminante D()

// Interseção entre a reta AB e o segmento de reta PQ
Point intersection(const Point& P, const Point& Q, const Point& A, const Point& B)
{
    auto a = B.y - A.y;
    auto b = A.x - B.x;
    auto c = B.x * A.y - A.x * B.y;
    auto u = fabs(a * P.x + b * P.y + c);
    auto v = fabs(a * Q.x + b * Q.y + c);

    return Point((P.x * v + Q.x * u)/(u + v), Point(P.y * v + Q.y * u)/(u + v));
}

Polygon cut_polygon(const Polygon& P, const Point& A, const Point& B)
{
    vector<Point> points;

    for (int i = 0; i < P.n; ++i)
    {
        auto d1 = D(A, B, P.vertices[i]);
        auto d2 = D(A, B, P.vertices[i + 1]);

        // Vértice à esquerda da reta
        if (d1 < -EPS)
            points.push_back(P.vertices[i]);

        // A aresta cruza a reta
        if (d1 * d2 < -EPS)
            points.push_back(intersection(P.vertices[i], P.vertices[i+1], A, B);
    }

    // Torna o último ponto igual ao primeiro
    if (not points.empty() and not points.back() == points.front())
        points.push_back(points.front());

    return Polygon(points);
}

```

### Exercícios

<!--- 1C - Área do polígono regular inscrito --->
<!--- 478 - Verificação de pontos no interior de círculos e polígonos -->
1. Codeforces
    1. [1C - Ancient Berland Circus](http://codeforces.com/problemset/problem/1/C)
1 UVA
    1. [478 - Points in Figures: Rectangles, Circles, Triangles](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=419)

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.
