## Frame
\bbcover{Grafos}{Programação Dinâmica em DAGs}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.0
    @title.text = \Large \bbbold{Relação entre DAGs e programação dinâmica}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.0
    @a.text = $\star$ \bbtext{É possível utilizar algoritmos de programação dinâmica (DP) em um grafo }
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 4.5
    @a1.text = \bbtext{$G$, se $G$ é direcionado e acíclico (DAG -- \bbenglish{directed acyclic graph})}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 3.5
    @b.text = $\star$ \bbtext{De fato, há uma relação direta entre uma DP e um DAG}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 2.5
    @c.text = $\star$ \bbtext{Uma DP induz um DAG cujos vértices são os estados e as arestas indicam}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 2
    @c1.text = \bbtext{as transições entre estados}
    @c1.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Aplicação: número de caminhos de $u$ a $v$}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $\star$ \bbtext{É possível computar o número de caminhos distintos entre os vértices}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 4.5
    @a1.text = \bbtext{$u, v\in V$ de um DAG $G(V, E)$}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 3.5
    @b.text = $\star$ \bbtext{Seja $p_u(x)$ o número de caminhos de $u$ a $x$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 2.5
    @c.text = $\star$ \bbtext{Há um único caminho de $u$ a $u$:  permanecer onde está}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 1.5
    @d.text = $\star$ \bbtext{Assim, $p_u(u) = 1$ é o caso base}
    @d.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Aplicação: número de caminhos de $u$ a $v$}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $\star$ \bbtext{Para os demais vértices $x\in V$, vale que}
    @a.anchor = west

a1 => Node
    @a1.x = 7
    @a1.y = 4
    @a1.text = $\displaystyle p_u(x) = \sum_{(v_i, x)\in E} p_u(v_i)$

---

b => Node
    @b.x = 1
    @b.y = 3
    @b.text = $\star$ \bbtext{O cálculo de $p_u(x)$ depende da ordem de processamento dos vértices}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 2
    @c.text = $\star$ \bbtext{Como $G$ é um DAG, basta usar a ordenação topológica para computar $p_u(x)$}
    @c.anchor = west

## Scene

node1 => Node
    @node1.x = 2
    @node1.y = 3.5
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

 node2 => Node
    @node2.x = 4
    @node2.y = 5.5
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

 node3 => Node
    @node3.x = 4
    @node3.y = 2.5
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

 node4 => Node
    @node4.x = 6
    @node4.y = 3.5
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

 node5 => Node
    @node5.x = 6
    @node5.y = 6.5
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node6 => Node
    @node6.x = 8
    @node6.y = 7.5
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node7 => Node
    @node7.x = 10
    @node7.y = 4.5
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node8 => Node
    @node8.x = 10
    @node8.y = 2.5
    @node8.text = \bbtext{8}
    &node8.very thick
    &node8.draw
    &node8.circle

node9 => Node
    @node9.x = 12
    @node9.y = 4.5
    @node9.text = \bbtext{9}
    &node9.very thick
    &node9.draw
    &node9.circle

O => Node
    @O.x = 0
    @O.y = 7.5
    @O.text = \bbtext{$O = \{$ 2, 1, 3, 4, 7, 8, 5, 6, 9 $\}$}
    @O.anchor = west

e21 => Edge
    @e21.from = node2
    @e21.to = node1
    &e21.thick
    &e21.-latex

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.thick
    &e23.-latex

e24 => Edge
    @e24.from = node2
    @e24.to = node4
    &e24.thick
    &e24.-latex

e25 => Edge
    @e25.from = node2
    @e25.to = node5
    &e25.thick
    &e25.-latex

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    &e13.-latex

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    &e34.-latex

e38 => Edge
    @e38.from = node3
    @e38.to = node8
    &e38.thick
    &e38.-latex

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    &e45.-latex

e47 => Edge
    @e47.from = node4
    @e47.to = node7
    &e47.thick
    &e47.-latex

e48 => Edge
    @e48.from = node4
    @e48.to = node8
    &e48.thick
    &e48.-latex

e56 => Edge
    @e56.from = node5
    @e56.to = node6
    &e56.thick
    &e56.-latex

e69 => Edge
    @e69.from = node6
    @e69.to = node9
    &e69.thick
    &e69.-latex

e78 => Edge
    @e78.from = node7
    @e78.to = node8
    &e78.thick
    &e78.-latex

e79 => Edge
    @e79.from = node7
    @e79.to = node9
    &e79.thick
    &e79.-latex

e89 => Edge
    @e89.from = node8
    @e89.to = node9
    &e89.thick
    &e89.-latex

-O

---

grid => Grid
    @grid.x = 3
    @grid.y = 0
    @grid.u = 12
    @grid.v = 1
    &grid.thick

p => Node
    @p.x = 3
    @p.y = 0.5
    @p.text = $p_1(x) = $
    @p.anchor = east

x1 => Node
    @x1.x = 3.5
    @x1.y = 1.4
    @x1.text = \bbtext{1}

x2 => Node
    @x2.x = 4.5
    @x2.y = 1.4
    @x2.text = \bbtext{2}

x3 => Node
    @x3.x = 5.5
    @x3.y = 1.4
    @x3.text = \bbtext{3}

x4 => Node
    @x4.x = 6.5
    @x4.y = 1.4
    @x4.text = \bbtext{4}

x5 => Node
    @x5.x = 7.5
    @x5.y = 1.4
    @x5.text = \bbtext{5}

x6 => Node
    @x6.x = 8.5
    @x6.y = 1.4
    @x6.text = \bbtext{6}

x7 => Node
    @x7.x = 9.5
    @x7.y = 1.4
    @x7.text = \bbtext{7}

x8 => Node
    @x8.x = 10.5
    @x8.y = 1.4
    @x8.text = \bbtext{8}

x9 => Node
    @x9.x = 11.5
    @x9.y = 1.4
    @x9.text = \bbtext{9}

d1 => Node
    @d1.x = 3.5
    @d1.y = 0.5
    @d1.text = \bbtext{-}

d2 => Node
    @d2.x = 4.5
    @d2.y = 0.5
    @d2.text = \bbtext{-}

d3 => Node
    @d3.x = 5.5
    @d3.y = 0.5
    @d3.text = \bbtext{-}

d4 => Node
    @d4.x = 6.5
    @d4.y = 0.5
    @d4.text = \bbtext{-}

d5 => Node
    @d5.x = 7.5
    @d5.y = 0.5
    @d5.text = \bbtext{-}

d6 => Node
    @d6.x = 8.5
    @d6.y = 0.5
    @d6.text = \bbtext{-}

d7 => Node
    @d7.x = 9.5
    @d7.y = 0.5
    @d7.text = \bbtext{-}

d8 => Node
    @d8.x = 10.5
    @d8.y = 0.5
    @d8.text = \bbtext{-}

d9 => Node
    @d9.x = 11.5
    @d9.y = 0.5
    @d9.text = \bbtext{-}

---

    @node1.fill = BBCyan
    @d1.text = $\mathbf{1}$

---
+O

---
    @node2.fill = BBCyan
    @d1.text = ${1}$
    @d2.text = $\mathbf{0}$

---
    @node3.fill = BBCyan
    @d2.text = ${0}$
    @d3.text = $\mathbf{1}$

---
    @node4.fill = BBCyan
    @d3.text = ${1}$
    @d4.text = $\mathbf{1}$

---
    @node7.fill = BBCyan
    @d4.text = ${1}$
    @d7.text = $\mathbf{1}$

---
    @node8.fill = BBCyan
    @d7.text = ${1}$
    @d8.text = $\mathbf{3}$

---
    @node5.fill = BBCyan
    @d8.text = ${3}$
    @d5.text = $\mathbf{1}$

---
    @node6.fill = BBCyan
    @d5.text = ${1}$
    @d6.text = $\mathbf{1}$

---
    @node9.fill = BBCyan
    @d6.text = ${1}$
    @d9.text = $\mathbf{5}$

---
    @node1.fill = BBWhite
    @node2.fill = BBWhite
    @node3.fill = BBWhite
    @node4.fill = BBWhite
    @node5.fill = BBWhite
    @node6.fill = BBWhite
    @node7.fill = BBWhite
    @node8.fill = BBWhite
    @node9.fill = BBWhite

    @p.text = $p_2(x) = $

    @d1.text = \bbtext{-}
    @d2.text = \bbtext{-}
    @d3.text = \bbtext{-}
    @d4.text = \bbtext{-}
    @d5.text = \bbtext{-}
    @d6.text = \bbtext{-}
    @d7.text = \bbtext{-}
    @d8.text = \bbtext{-}
    @d9.text = \bbtext{-}

---
    @node2.fill = BBGreen
    @d2.text = $\mathbf{1}$

---
    @node1.fill = BBGreen
    @d1.text = $\mathbf{1}$
    @d2.text = ${1}$

---
    @node3.fill = BBGreen
    @d3.text = $\mathbf{2}$
    @d1.text = ${1}$

---
    @node4.fill = BBGreen
    @d4.text = $\mathbf{3}$
    @d3.text = ${2}$

---
    @node7.fill = BBGreen
    @d7.text = $\mathbf{3}$
    @d4.text = ${3}$

---
    @node8.fill = BBGreen
    @d8.text = $\mathbf{8}$
    @d7.text = ${3}$

---
    @node5.fill = BBGreen
    @d5.text = $\mathbf{4}$
    @d8.text = ${8}$

---
    @node6.fill = BBGreen
    @d6.text = $\mathbf{4}$
    @d5.text = ${4}$

---
    @node9.fill = BBGreen
    @d9.text = $\mathbf{15}$
    @d6.text = ${4}$

## Frame

\inputsnippet{cpp}{44}{56}{codes/paths.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Aplicação: número de caminhos mínimos de $u$ a $v$}
    @title.anchor = west
---

a => Node
    @a.x = 0.8
    @a.y = 6
    @a.text = $\star$ \bbtext{O algoritmo de Dijkstra induz um DAG que indica, para cada vértice do grafo}
    @a.anchor = west

a1 => Node
    @a1.x = 0.3
    @a1.y = 5.5
    @a1.text = \bbtext{original, como atingir os demais vértices por caminhos mínimos}
    @a1.anchor = west

---

b => Node
    @b.x = 0.8
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Assim, pode-se usar DP neste grafo}
    @b.anchor = west

---

c => Node
    @c.x = 0.8
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Assim seria possível, por exemplo, computar o número de caminhos mínimos}
    @c.anchor = west

c1 => Node
    @c1.x = 0.3
    @c1.y = 3
    @c1.text = \bbtext{de $u$ a $v$}
    @c1.anchor = west

---

d => Node
    @d.x = 0.8
    @d.y = 2
    @d.text = $\star$ \bbtext{O algoritmo seria o mesmo usado para computar o número de caminhos, com}
    @d.anchor = west

d1 => Node
    @d1.x = 0.3
    @d1.y = 1.5
    @d1.text = \bbtext{a ordenação $O$ sendo substituída pela ordenação de Dijkstra}
    @d1.anchor = west

## Scene

node1 => Node
    @node1.x = 1
    @node1.y = 5
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

node2 => Node
    @node2.x = 3
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

node3 => Node
    @node3.x = 3
    @node3.y = 5
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

node4 => Node
    @node4.x = 3
    @node4.y = 3
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

node5 => Node
    @node5.x = 5
    @node5.y = 5
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex
    %e12.label = node[above left] { \footnotesize \bbinfo{3} }

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    &e13.-latex
    %e13.label = node[above] { \footnotesize \bbinfo{2} }

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    &e14.-latex
    %e14.label = node[below left] { \footnotesize \bbinfo{5} }

e32 => Edge
    @e32.from = node3
    @e32.to = node2
    &e32.thick
    &e32.-latex
    %e32.label = node[right] { \footnotesize \bbinfo{1} }

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    &e34.-latex
    %e34.label = node[right] { \footnotesize \bbinfo{2} }

e25 => Edge
    @e25.from = node2
    @e25.to = node5
    &e25.thick
    &e25.-latex
    %e25.label = node[above right] { \footnotesize \bbinfo{3} }

e35 => Edge
    @e35.from = node3
    @e35.to = node5
    &e35.thick
    &e35.-latex
    %e35.label = node[above] { \footnotesize \bbinfo{5} }

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    &e45.-latex
    %e45.label = node[below right] { \footnotesize \bbinfo{2} }

grid => Grid
    @grid.x = 1
    @grid.y = 0
    @grid.u = 6
    @grid.v = 1
    &grid.thick

dist => Node
    @dist.x = 1
    @dist.y = 0.5
    @dist.text = $d_1(x) = $
    @dist.anchor = east

d1 => Node
    @d1.x = 1.5
    @d1.y = 1.4
    @d1.text = \bbtext{1}

d2 => Node
    @d2.x = 2.5
    @d2.y = 1.4
    @d2.text = \bbtext{2}

d3 => Node
    @d3.x = 3.5
    @d3.y = 1.4
    @d3.text = \bbtext{3}

d4 => Node
    @d4.x = 4.5
    @d4.y = 1.4
    @d4.text = \bbtext{4}

d5 => Node
    @d5.x = 5.5
    @d5.y = 1.4
    @d5.text = \bbtext{5}

dv1 => Node
    @dv1.x = 1.5
    @dv1.y = 0.5
    @dv1.text = \bbtext{-}

dv2 => Node
    @dv2.x = 2.5
    @dv2.y = 0.5
    @dv2.text = \bbtext{-}

dv3 => Node
    @dv3.x = 3.5
    @dv3.y = 0.5
    @dv3.text = \bbtext{-}

dv4 => Node
    @dv4.x = 4.5
    @dv4.y = 0.5
    @dv4.text = \bbtext{-}

dv5 => Node
    @dv5.x = 5.5
    @dv5.y = 0.5
    @dv5.text = \bbtext{-}

---

    @node1.fill = BBGreen
    @dv1.text = $\mathbf{0}$

---

    @dv1.text = ${0}$

n1 => Node
    @n1.x = 8
    @n1.y = 5
    @n1.text = \textcolor{BBEmerald}{\textbf{1}}$^1$
    &n1.very thick
    &n1.draw
    &n1.circle

---
    @e12.color = BBCyan
    @dv2.text = $\mathbf{3}$

---
    @dv2.text = ${3}$
    @e12.color = BBBlack

    @e13.color = BBCyan
    @dv3.text = $\mathbf{2}$

---
    @dv3.text = ${2}$
    @e13.color = BBBlack

    @e14.color = BBCyan
    @dv4.text = $\mathbf{5}$

---
    @dv4.text = ${5}$
    @e14.color = BBBlack
   
    @node1.fill = BBCyan

---
    @node3.fill = BBGreen


---
n3 => Node
    @n3.x = 10
    @n3.y = 5
    @n3.text = \textcolor{BBEmerald}{\textbf{3}}$^2$
    &n3.very thick
    &n3.draw
    &n3.circle

a13 => Edge
    @a13.from = n1
    @a13.to = n3
    &a13.thick
    &a13.dashed
    &a13.-latex

---
    @e32.color = BBCyan

---
    @e32.color = BBBlack
    @e34.color = BBCyan
    @dv4.text = $\mathbf{4}$

---
    @e34.color = BBBlack
    @dv4.text = ${4}$

    @e35.color = BBCyan
    @dv5.text = $\mathbf{7}$

---
    @e35.color = BBBlack
    @dv5.text = ${7}$
    @node3.fill = BBCyan

---
    @node2.fill = BBGreen

---

n2 => Node
    @n2.x = 10
    @n2.y = 7
    @n2.text = \textcolor{BBEmerald}{\textbf{2}}$^3$
    &n2.very thick
    &n2.draw
    &n2.circle

a12 => Edge
    @a12.from = n1
    @a12.to = n2
    &a12.thick
    &a12.dashed
    &a12.-latex

a32 => Edge
    @a32.from = n3
    @a32.to = n2
    &a32.thick
    &a32.dashed
    &a32.-latex

---
    @e25.color = BBCyan
    @dv5.text = $\mathbf{6}$

---
    @e25.color = BBBlack
    @dv5.text = $6$
    @node2.fill = BBCyan

---
    @node4.fill = BBGreen

---

n4 => Node
    @n4.x = 10
    @n4.y = 3
    @n4.text = \textcolor{BBEmerald}{\textbf{4}}$^4$
    &n4.very thick
    &n4.draw
    &n4.circle

a34 => Edge
    @a34.from = n3
    @a34.to = n4
    &a34.thick
    &a34.dashed
    &a34.-latex

---
    @e45.color = BBCyan

---
    @e45.color = BBBlack
    @node4.fill = BBCyan

---

    @node5.fill = BBGreen

---

n5 => Node
    @n5.x = 12
    @n5.y = 5
    @n5.text = \textcolor{BBEmerald}{\textbf{5}}$^5$
    &n5.very thick
    &n5.draw
    &n5.circle

a25 => Edge
    @a25.from = n2
    @a25.to = n5
    &a25.thick
    &a25.dashed
    &a25.-latex

a45 => Edge
    @a45.from = n4
    @a45.to = n5
    &a45.thick
    &a45.dashed
    &a45.-latex

---
    @node5.fill = BBCyan

---

grid2 => Grid
    @grid2.x = 8
    @grid2.y = 0
    @grid2.u = 13
    @grid2.v = 1
    &grid2.thick

ps => Node
    @ps.x = 8
    @ps.y = 0.5
    @ps.text = $p_1(x) = $
    @ps.anchor = east

p1 => Node
    @p1.x = 8.5
    @p1.y = 1.4
    @p1.text = \bbtext{1}

p2 => Node
    @p2.x = 9.5
    @p2.y = 1.4
    @p2.text = \bbtext{2}

p3 => Node
    @p3.x = 10.5
    @p3.y = 1.4
    @p3.text = \bbtext{3}

p4 => Node
    @p4.x = 11.5
    @p4.y = 1.4
    @p4.text = \bbtext{4}

p5 => Node
    @p5.x = 12.5
    @p5.y = 1.4
    @p5.text = \bbtext{5}

pv1 => Node
    @pv1.x = 8.5
    @pv1.y = 0.5
    @pv1.text = \bbtext{-}

pv2 => Node
    @pv2.x = 9.5
    @pv2.y = 0.5
    @pv2.text = \bbtext{-}

pv3 => Node
    @pv3.x = 10.5
    @pv3.y = 0.5
    @pv3.text = \bbtext{-}

pv4 => Node
    @pv4.x = 11.5
    @pv4.y = 0.5
    @pv4.text = \bbtext{-}

pv5 => Node
    @pv5.x = 12.5
    @pv5.y = 0.5
    @pv5.text = \bbtext{-}

---
    @pv1.text = $\mathbf{1}$
    @n1.fill = BBGray

---
    @pv1.text = ${1}$
    @pv3.text = $\mathbf{1}$
    @n3.fill = BBGray

---
    @pv3.text = ${1}$
    @pv2.text = $\mathbf{2}$
    @n2.fill = BBGray

---
    @pv2.text = ${2}$
    @pv4.text = $\mathbf{1}$
    @n4.fill = BBGray

---
    @pv4.text = ${1}$
    @pv5.text = $\mathbf{3}$
    @n5.fill = BBGray

## Frame

\inputsnippet{cpp}{48}{60}{codes/min_paths.cpp}

## Frame

\inputsnippet{cpp}{12}{28}{codes/min_paths.cpp}

## Frame

\inputsnippet{cpp}{30}{46}{codes/min_paths.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Problemas sugeridos}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $1.$ \bbtext{CSES 1202 -- Investigation}
    @a.anchor = west

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $2.$ \bbtext{HackerEarth -- Counting on Tree}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $3.$ \bbtext{SPOJ DAGCNT2 -- Counting in a DAG}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $4.$ \bbtext{Timus 1018 -- Binary Apple Tree}
    @d.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Referências}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $1.$ \bbtext{\bbbold{Codeforces}. \bbenglish{DP on Trees Tutorial}, acesso em 14/09/2021.}
    @a.anchor = west

b => Node
    @b.x = 1
    @b.y = 3
    @b.text = $3.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 2
    @c.text = $4.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 4
    @d.text = $2.$ \bbbold{DUMOL}, \bbtext{Tim.} \bbenglish{IOI Trainning Week 5 -- DP on Trees and DAGs}.
    @d.anchor = west


## End

https://cses.fi/problemset/task/1202
https://www.spoj.com/problems/DAGCNT2/
https://www.spoj.com/problems/DAGCNT/
https://www.hackerearth.com/pt-br/challenges/competitive/march-clash-15/algorithm/counting-on-tree-1/description/
https://acm.timus.ru/problem.aspx?space=1&num=1018

https://noi.ph/training/weekly/week5.pdf?x75983
https://codeforces.com/blog/entry/20935
