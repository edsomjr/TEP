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
    Polygon(vector<Point>& vs) : vertices(vs), n(vs.size())
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

### Exercícios

<!--- 1C - Área do polígono regular inscrito --->
1. Codeforces
    1. [1C - Ancient Berland Circus](http://codeforces.com/problemset/problem/1/C)
 
### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.
