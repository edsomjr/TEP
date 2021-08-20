## Frame
\bbcover{Grafos}{Árvores: Diâmetro}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Definição de diâmetro}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = \bbtext{Seja $G(V, E)$ um grafo. O \bbbold{diâmetro} de $G$ é igual ao maior dentre todos os}
    @a.anchor = west

b => Node
    @b.x = 0.5
    @b.y = 4.25
    @b.text = \bbtext{tamanhos dos caminhos entre os pares de vértices $u, v\in V$.}
    @b.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Características do diâmetro}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{O caminho cujo tamanho determina o diâmetro não é, necessariamente, }
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.5
    @a1.text = \bbtext{único}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Computar todos os tamanho com Floyd-Warshall em $O(V^3)$ e determinar}
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.0
    @b1.text = \bbtext{o maior dentre eles em $O(V^2)$ determina o diâmetro corretamente}
    @b1.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.0
    @c.text = $\star$ \bbtext{Porém, é possível determinar o diâmetro usando programação dinâmica}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 2.5
    @c1.text = \bbtext{ou duas DFS}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 1.5
    @d.text = $\star$ \bbtext{Em ambos casos, a complexidade é $O(V)$}
    @d.anchor = west

## Scene

node1 => Node
    @node1.x = 1
    @node1.y = 1
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle
 
node2 => Node
    @node2.x = 7
    @node2.y = 2
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle
 
node3 => Node
    @node3.x = 1
    @node3.y = 5
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle
 
node4 => Node
    @node4.x = 7
    @node4.y = 4
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle
 
node5 => Node
    @node5.x = 10
    @node5.y = 6
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle
 
node6 => Node
    @node6.x = 13
    @node6.y = 3
    @node6.text = \bbtext{6}
    &node6.draw
    &node6.very thick
    &node6.circle
 
node7 => Node
    @node7.x = 4
    @node7.y = 3
    @node7.text = \bbtext{7}
    &node7.draw
    &node7.very thick
    &node7.circle
 
e17 => Edge
    @e17.from = node1
    @e17.to = node7
    &e17.thick
 
e37 => Edge
    @e37.from = node3
    @e37.to = node7
    &e37.thick
 
e47 => Edge
    @e47.from = node4
    @e47.to = node7
    &e47.thick
 
e42 => Edge
    @e42.from = node4
    @e42.to = node2
    &e42.thick
 
e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
 
e65 => Edge
    @e65.from = node6
    @e65.to = node5
    &e65.thick
 
---

    &e17.very thick
    &e47.very thick
    &e45.very thick
    &e65.very thick

    @e17.color = BBOrange
    @e47.color = BBOrange
    @e45.color = BBOrange
    @e65.color = BBOrange

info => Node
    @info.x = 2
    @info.y = 7
    @info.text = \bbtext{Diâmetro: $4$}
    @info.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Definição de pico de um caminho}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = \bbtext{Seja $T$ uma árvore enraizada e considere dois vértices $u$ e $v$ de $T$. O pico do}
    @a.anchor = west

b => Node
    @b.x = 0.5
    @b.y = 5.25
    @b.text = \bbtext{caminho de $u$ a $v$ é o nó que ocupa o nível baixo em $T$.}
    @b.anchor = west

---

nodeA => Node
    @nodeA.x = 9
    @nodeA.y = 4
    @nodeA.text = \tiny $a$
    &nodeA.draw
    &nodeA.thick
    &nodeA.circle

nodeB => Node
    @nodeB.x = 6
    @nodeB.y = 3
    @nodeB.text = \tiny $b$
    &nodeB.draw
    &nodeB.thick
    &nodeB.circle

nodeC => Node
    @nodeC.x = 10
    @nodeC.y = 3
    @nodeC.text = \tiny $c$
    &nodeC.draw
    &nodeC.thick
    &nodeC.circle

nodeD => Node
    @nodeD.x = 4
    @nodeD.y = 2
    @nodeD.text = \tiny $d$
    &nodeD.draw
    &nodeD.thick
    &nodeD.circle

nodeE => Node
    @nodeE.x = 3
    @nodeE.y = 1
    @nodeE.text = \tiny $e$
    &nodeE.draw
    &nodeE.thick
    &nodeE.circle

nodeG => Node
    @nodeG.x = 7
    @nodeG.y = 1
    @nodeG.text = \tiny $g$
    &nodeG.draw
    &nodeG.thick
    &nodeG.circle

nodeU => Node
    @nodeU.x = 5
    @nodeU.y = 1
    @nodeU.text = \tiny $\textcolor{BBWhite}{u}$
    @nodeU.fill = BBGreen
    &nodeU.draw
    &nodeU.thick
    &nodeU.circle

nodeV => Node
    @nodeV.x = 8
    @nodeV.y = 2
    @nodeV.text = \tiny $\textcolor{BBWhite}{v}$
    @nodeV.fill = BBCyan
    &nodeV.draw
    &nodeV.thick
    &nodeV.circle
 
eAB => Edge
    @eAB.from = nodeA
    @eAB.to = nodeB
    &eAB.thick

eAC => Edge
    @eAC.from = nodeA
    @eAC.to = nodeC
    &eAC.thick

eDB => Edge
    @eDB.from = nodeD
    @eDB.to = nodeB
    &eDB.thick

eVB => Edge
    @eVB.from = nodeV
    @eVB.to = nodeB
    &eVB.thick

eDE => Edge
    @eDE.from = nodeD
    @eDE.to = nodeE
    &eDE.thick

eDU => Edge
    @eDU.from = nodeD
    @eDU.to = nodeU
    &eDU.thick

eVG => Edge
    @eVG.from = nodeV
    @eVG.to = nodeG
    &eVG.thick
 
---
    &eDU.dashed
    &eDB.dashed
    &eVB.dashed

---
    @nodeB.text = \tiny $\textcolor{BBWhite}{b}$
    @nodeB.fill = BBOrange

arrow => Edge
    @arrow.x = 5
    @arrow.y = 3.5
    @arrow.u = 5.7
    @arrow.v = 3.3
    @arrow.color = BBViolet
    %arrow.label = [bend left]
    &arrow.-latex
 
info => Node
    @info.x = 5
    @info.y = 3.5
    @info.anchor = east
    @info.text = \scriptsize \bbcomment{pico}

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Diâmetro de uma árvore com programação dinâmica}
    @title.anchor = west
---

a => Node
    @a.x = 2
    @a.y = 3
    @a.text = $\displaystyle \mathrm{maxLength}[u]$
    @a.anchor = west

---

info => Node
    @info.x = 1
    @info.y = 4.6
    @info.text = \footnotesize \bbcomment{Tamanho do maior caminho que tem pico igual a $u$}
    @info.anchor = west

arrow => Edge
    @arrow.x = 3
    @arrow.y = 3.3
    @arrow.u = 3
    @arrow.v = 4.3
    @arrow.color = BBViolet
    &arrow.-latex

---
-info
-arrow

    @a.text = $\displaystyle \mathrm{maxLength}[u] = \left\{ \begin{array}{ll} 0,& \mbox{se $u$ não tem filhos}\\ \ \\ \end{array}\right.$

---
    @a.text = $\displaystyle \mathrm{maxLength}[u] = \left\{ \begin{array}{ll} 0,& \mbox{se $u$ não tem filhos}\\ 1 + \mathrm{toLeaf}[v],& \mbox{se $u$ tem apenas um filho $v$}, \\\ \\ \end{array}\right.$

---
    @a.text = $\displaystyle \mathrm{maxLength}[u] = \left\{ \begin{array}{ll} 0,& \mbox{se $u$ não tem filhos}\\ 1 + \mathrm{toLeaf}[v],& \mbox{se $u$ tem apenas um filho $v$}, \\2 + \mathrm{toLeaf}[v] + \mathrm{toLeaf}[w],& \mbox{caso contrário}, \\ \end{array}\right.$

+info
    @info.x = 0.5
    @info.y = 1.5
    @info.text = \bbtext{onde $v$ e $w$ são dois filhos distintos de $u$ com os dois maiores valores de $\mathrm{toLeaf}$}

---

diameter => Node
    @diameter.x = 2
    @diameter.y = 4.5
    @diameter.text = $\displaystyle \mathrm{diameter}(G) = \max_{u\in V} \left\{\ \mathrm{maxLength}[u]\ \right\}$
    @diameter.anchor = west


## Scene

node4 => Node
    @node4.x = 7
    @node4.y = 7.5
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle
 
node7 => Node
    @node7.x = 3
    @node7.y = 5.5
    @node7.text = \bbtext{7}
    &node7.draw
    &node7.very thick
    &node7.circle
 
node2 => Node
    @node2.x = 7
    @node2.y = 5.5
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle
 
node5 => Node
    @node5.x = 11
    @node5.y = 5.5
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle
 
node1 => Node
    @node1.x = 1
    @node1.y = 3.5
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle
 
node3 => Node
    @node3.x = 5
    @node3.y = 3.5
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle
 
node6 => Node
    @node6.x = 11
    @node6.y = 3.5
    @node6.text = \bbtext{6}
    &node6.draw
    &node6.very thick
    &node6.circle
 
e47 => Edge
    @e47.from = node4
    @e47.to = node7
    &e47.thick
    
e42 => Edge
    @e42.from = node4
    @e42.to = node2
    &e42.thick
 
e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
 
e71 => Edge
    @e71.from = node7
    @e71.to = node1
    &e71.thick
 
e73 => Edge
    @e73.from = node7
    @e73.to = node3
    &e73.thick
 
e56 => Edge
    @e56.from = node5
    @e56.to = node6
    &e56.thick
 
grid => Grid
    @grid.x = 4
    @grid.y = 0
    @grid.u = 11
    @grid.v = 1

grid2 => Grid
    @grid2.x = 4
    @grid2.y = 1
    @grid2.u = 11
    @grid2.v = 2

text => Node
    @text.x = 3.9
    @text.y = 0.5
    @text.anchor = east
    @text.text = $\mathrm{maxLength}[u] = $

text2 => Node
    @text2.x = 3.9
    @text2.y = 1.5
    @text2.anchor = east
    @text2.text = $\mathrm{toLeaf}[u] = $

1 => Node
    @1.x = 4.5
    @1.y = 2.5
    @1.text = \bbtext{1}

2 => Node
    @2.x = 5.5
    @2.y = 2.5
    @2.text = \bbtext{2}

3 => Node
    @3.x = 6.5
    @3.y = 2.5
    @3.text = \bbtext{3}

4 => Node
    @4.x = 7.5
    @4.y = 2.5
    @4.text = \bbtext{4}

5 => Node
    @5.x = 8.5
    @5.y = 2.5
    @5.text = \bbtext{5}

6 => Node
    @6.x = 9.5
    @6.y = 2.5
    @6.text = \bbtext{6}

7 => Node
    @7.x = 10.5
    @7.y = 2.5
    @7.text = \bbtext{7}

n1 => Node
    @n1.x = 4.5
    @n1.y = 0.5
    @n1.text = \bbtext{-}

n2 => Node
    @n2.x = 5.5
    @n2.y = 0.5
    @n2.text = \bbtext{-}

n3 => Node
    @n3.x = 6.5
    @n3.y = 0.5
    @n3.text = \bbtext{-}

n4 => Node
    @n4.x = 7.5
    @n4.y = 0.5
    @n4.text = \bbtext{-}

n5 => Node
    @n5.x = 8.5
    @n5.y = 0.5
    @n5.text = \bbtext{-}

n6 => Node
    @n6.x = 9.5
    @n6.y = 0.5
    @n6.text = \bbtext{-}

n7 => Node
    @n7.x = 10.5
    @n7.y = 0.5
    @n7.text = \bbtext{-}

L1 => Node
    @L1.x = 4.5
    @L1.y = 1.5
    @L1.text = \bbtext{-}

L2 => Node
    @L2.x = 5.5
    @L2.y = 1.5
    @L2.text = \bbtext{-}

L3 => Node
    @L3.x = 6.5
    @L3.y = 1.5
    @L3.text = \bbtext{-}

L4 => Node
    @L4.x = 7.5
    @L4.y = 1.5
    @L4.text = \bbtext{-}

L5 => Node
    @L5.x = 8.5
    @L5.y = 1.5
    @L5.text = \bbtext{-}

L6 => Node
    @L6.x = 9.5
    @L6.y = 1.5
    @L6.text = \bbtext{-}

L7 => Node
    @L7.x = 10.5
    @L7.y = 1.5
    @L7.text = \bbtext{-}

---
    @node1.fill = BBCyan
    @n1.text = $\mathbf{0}$
    @L1.text = $\mathbf{0}$

---
    @node3.fill = BBCyan
    @n3.text = $\mathbf{0}$
    @L3.text = $\mathbf{0}$
    @n1.text = ${0}$
    @L1.text = ${0}$

---
    @node2.fill = BBCyan
    @n2.text = $\mathbf{0}$
    @L2.text = $\mathbf{0}$
    @n3.text = ${0}$
    @L3.text = ${0}$

---
    @node6.fill = BBCyan
    @n6.text = $\mathbf{0}$
    @L6.text = $\mathbf{0}$
    @n2.text = ${0}$
    @L2.text = ${0}$

---
    @node5.fill = BBGreen
    @n5.text = $\mathbf{1}$
    @L5.text = $\mathbf{1}$
    @n6.text = ${0}$
    @L6.text = ${0}$

---
    @node7.fill = BBOrange
    @n7.text = $\mathbf{2}$
    @L7.text = $\mathbf{1}$
    @n5.text = ${1}$
    @L5.text = ${1}$

---
    @node4.fill = BBOrange
    @n4.text = $\mathbf{4}$
    @L4.text = $\mathbf{2}$
    @n7.text = ${2}$
    @L7.text = ${1}$


## Frame

\inputsnippet{cpp}{43}{53}{codes/dp.cpp}

## Frame

\inputsnippet{cpp}{10}{25}{codes/dp.cpp}

## Frame

\inputsnippet{cpp}{27}{41}{codes/dp.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Maior caminho até uma folha}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Outra aplicação de DFS com DP é o cálculo do tamanho, em arestas, do }
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.5
    @a1.text = \bbtext{maior caminho $\mathrm{toLeaf}[u]$ de $u$ até uma folha}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Se $u$ for uma folha, então $\mathrm{toLeaf}[u] = 0$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Caso contrário,}
    @c.anchor = west

c1 => Node
    @c1.x = 7
    @c1.y = 2.5
    @c1.text = $\displaystyle \mathrm{toLeaf}[u] = 1 + \max_{v\in\mathrm{adj[u]}}\{\ \mathrm{toLeaf}[v]\ \}$

---

d => Node
    @d.x = 1
    @d.y = 1.5
    @d.text = $\star$ \bbtext{Este algoritmo pode ser adaptado para computar o tamanho como soma }
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 1.0
    @d1.text = \bbtext{dos pesos das arestas do caminho que vai de $u$ até a folha}
    @d1.anchor = west

## Scene

node4 => Node
    @node4.x = 6
    @node4.y = 7
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle
 
node7 => Node
    @node7.x = 10
    @node7.y = 5
    @node7.text = \bbtext{7}
    &node7.draw
    &node7.very thick
    &node7.circle
 
node2 => Node
    @node2.x = 6
    @node2.y = 5
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle
 
node5 => Node
    @node5.x = 2
    @node5.y = 5
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle
 
node1 => Node
    @node1.x = 8
    @node1.y = 3
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle
 
node3 => Node
    @node3.x = 12
    @node3.y = 3
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle
 
node6 => Node
    @node6.x = 2
    @node6.y = 3
    @node6.text = \bbtext{6}
    &node6.draw
    &node6.very thick
    &node6.circle
 
e47 => Edge
    @e47.from = node4
    @e47.to = node7
    &e47.thick
    
e42 => Edge
    @e42.from = node4
    @e42.to = node2
    &e42.thick
 
e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
 
e71 => Edge
    @e71.from = node7
    @e71.to = node1
    &e71.thick
 
e73 => Edge
    @e73.from = node7
    @e73.to = node3
    &e73.thick
 
e56 => Edge
    @e56.from = node5
    @e56.to = node6
    &e56.thick
 
grid => Grid
    @grid.x = 4
    @grid.y = 0
    @grid.u = 11
    @grid.v = 1

text => Node
    @text.x = 3.9
    @text.y = 0.5
    @text.anchor = east
    @text.text = $\mathrm{toLeaf}[u] = $

1 => Node
    @1.x = 4.5
    @1.y = 1.5
    @1.text = \bbtext{1}

2 => Node
    @2.x = 5.5
    @2.y = 1.5
    @2.text = \bbtext{2}

3 => Node
    @3.x = 6.5
    @3.y = 1.5
    @3.text = \bbtext{3}

4 => Node
    @4.x = 7.5
    @4.y = 1.5
    @4.text = \bbtext{4}

5 => Node
    @5.x = 8.5
    @5.y = 1.5
    @5.text = \bbtext{5}

6 => Node
    @6.x = 9.5
    @6.y = 1.5
    @6.text = \bbtext{6}

7 => Node
    @7.x = 10.5
    @7.y = 1.5
    @7.text = \bbtext{7}

n1 => Node
    @n1.x = 4.5
    @n1.y = 0.5
    @n1.text = \bbtext{-}

n2 => Node
    @n2.x = 5.5
    @n2.y = 0.5
    @n2.text = \bbtext{-}

n3 => Node
    @n3.x = 6.5
    @n3.y = 0.5
    @n3.text = \bbtext{-}

n4 => Node
    @n4.x = 7.5
    @n4.y = 0.5
    @n4.text = \bbtext{-}

n5 => Node
    @n5.x = 8.5
    @n5.y = 0.5
    @n5.text = \bbtext{-}

n6 => Node
    @n6.x = 9.5
    @n6.y = 0.5
    @n6.text = \bbtext{-}

n7 => Node
    @n7.x = 10.5
    @n7.y = 0.5
    @n7.text = \bbtext{-}

---

    @node4.fill = BBGreen

---

    @node4.fill = BBGray
    @node5.fill = BBGreen

---

    @node5.fill = BBGray
    @node6.fill = BBCyan

    @n6.text = $\mathbf{0}$

---

    @node5.fill = BBCyan

    @n6.text = ${0}$
    @n5.text = $\mathbf{1}$

---

    @node4.fill = BBGreen

    @n5.text = ${1}$
    @n4.text = $\mathbf{2}$

---

    @node2.fill = BBCyan
    @node4.fill = BBGray

    @n4.text = ${2}$
    @n2.text = $\mathbf{0}$

---

    @node4.fill = BBGreen

    @n2.text = ${0}$

---

    @node7.fill = BBGreen
    @node4.fill = BBGray

---

    @node1.fill = BBCyan
    @node7.fill = BBGray

    @n1.text = $\mathbf{0}$

---

    @node7.fill = BBGreen

    @n7.text = $\mathbf{0}$
    @n1.text = ${0}$

---

    @node7.fill = BBGray
    @node3.fill = BBCyan

    @n3.text = $\mathbf{0}$
    @n7.text = ${0}$

---

    @node7.fill = BBCyan

    @n7.text = $\mathbf{1}$
    @n3.text = ${0}$

---

    @node4.fill = BBCyan
    @n7.text = ${1}$

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Problemas sugeridos}
    @title.anchor = west

a => Node
    @a.x = 0.25
    @a.y = 5
    @a.text = $1.$ \bbtext{AtCoder Beginner Contest 126 -- Problem D: Even Relation}
    @a.anchor = west

b => Node
    @b.x = 0.25
    @b.y = 4
    @b.text = $2.$ \bbtext{Codeforces Beta Round \#87 (Div. 1 Only) -- Problem A: Party}
    @b.anchor = west

c => Node
    @c.x = 0.25
    @c.y = 3
    @c.text = $3.$ \bbtext{Codeforces Round \#660 (Div. 2) -- Problem C: Uncle Bogdan and Country Happiness}
    @c.anchor = west

d => Node
    @d.x = 0.25
    @d.y = 2
    @d.text = $4.$ \bbtext{OJ 10459 -- The Tree Root}
    @d.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Referências}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 2
    @a.text = $5.$ \bbtext{\bbbold{Wikipédia}. \bbenglish{Tree (graph theory),} acesso em 06/08/2021.}
    @a.anchor = west

e => Node
    @e.x = 1
    @e.y = 6
    @e.text = $1.$ \bbbold{DROZDEK}, \bbtext{Adam}. \bbenglish{Algoritmos e Estruturas de Dados em C++,} \bbtext{2002.}
    @e.anchor = west


b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $2.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $3.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $4.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.}
    @d.anchor = west

## End
