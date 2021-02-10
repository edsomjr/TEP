---
theme: gaia
backgroundColor: black
color: lightGray
headingDivider: 2
---

<style>
    section {
        font-size: 30px;
    }

    h1 {
        font-size: 70px;
    }
</style>

<!-- _class: lead -->
# Matemática

*__Malhas__*

Prof. Edson Alves
Faculdade UnB Gama

## Definição

Uma malha, em geral, se refere a dois ou mais conjuntos de retas paralelas no plano, igualmente espaçadas, em ângulos específicos, ou a interseção de tais retas.

Mas malhas mais comuns são as quadradas, triangulares e hexagonais.

## Malha quadrada

![bg invert center 65%](figs/squares.svg)

## Malha triangular

![bg invert center 45%](figs/triangles.svg)

## Malha hexagonal

![bg invert center 65%](figs/hexagons.svg)

## Malhas e sistemas de coordenadas

- As malhas podem induzir um sistema de coordenadas e uma ordenação entre seus elementos básicos

- O sistema de coordenadas e a ordenação também podem ser arbitrários

- Conhecida a ordenação utilizada, duas questões se tornam relevantes:

    1. qual é a coordenada do $n$-ésimo ponto?
    1. as coordenadas dadas corresponde a qual ponto da ordenação?

- Responder estas perguntas dependem ou de uma observação atenta dos padrões gerados pelo sistema de coordenadas ou pela ordenação

- Em alguns casos é possível utilizar uma simulação para responder tais questões

## Exemplo: Zigue-zague em malhas quadradas

![bg invert center 75%](figs/zigzag.svg)

## Exemplo: Zigue-zague em malhas quadradas

- Neste exemplo, o sistema de coordenadas é idêntico ao sistema cartesiano, onde as linhas são representadas pelas primeiras coordenadas do par, e as colunas pelas segundas coordenadas

- A ordenação inicia no canto inferior esquerdo e avança até o fim da linha

- Ao subir para a próxima linha, a ordenação segue em sentido oposto, do final para o início da próxima linha, e assim por diante

- É possível simular esta ordenação por meio de um vetor de direção $\vec{u}$

- Inicialmente, $\vec{u} = (0, 1)$

## Exemplo: Zigue-zague em malhas quadradas

- Sempre que os limites da malha forem atingidos, o vetor dever ser rotacionado em 180° 

- É possível, porém, determinar a posição $n$ referente à coordenada $(x, y)$ por meio da expressão
$$
    n = (x - 1)W + y,
$$
se $x$ é ímpar, e
$$
    n = (x - 1)W + (W - y + 1),
$$
se $y$ é par, onde $W$ é o número de pontos por linha

## Exemplo: Zigue-zague em malhas quadradas

- Também é possível determinar as coordenadas do $n$-ésimo ponto

- Este ponto estará na linha
$$
    x = \left\lfloor \frac{n - 1}{W} \right\rfloor + 1
$$
e, se $x$ é ímpar, na coluna
$$
    y = [(n - 1)\ \mathrm{mod}\ W] + 1,
$$

- Se $x$ é par, então
$$
    y = W - [(n - 1)\ \mathrm{mod}\ W]
$$

## Implementação do zigue-zague em malhas quadradas

```C++
int position(int x, int y, int W)
{
    return (x - 1)*W + (x % 2 ? y : W - y + 1);
}

void coordinates(int n, int& x, int& y, int W, int)
{
    x = ((n - 1) / W) + 1;
    y = x % 2 ? ((n - 1) % W) + 1 : W - ((n - 1) % W);
}
```

## Problemas

- OJ
    1. [264 - Count on Cantor](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=200)
    1. [10182 - Bee Maja](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1123)
    1. [10233 - Dermuba Triangle](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1174)
    1. [10620 - A Flea on a Chessboard](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1561)
    1. [10964 - Strange Planet](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1905)

## Referências

1. Wolfram MathWorld. [Grid](https://mathworld.wolfram.com/Grid.html). Acesso em 04/02/2021.

1. Wolfram MathWorld. [Hexagonal Grid](https://mathworld.wolfram.com/HexagonalGrid.html). Acesso em 04/02/2021.

1. Wolfram MathWorld. [Triangular Grid](https://mathworld.wolfram.com/TriangularGrid.html). Acesso em 04/02/2021.
