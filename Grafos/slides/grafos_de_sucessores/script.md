## Frame
\bbcover{Grafos}{Grafos de sucessores}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Grafos de sucessores}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = \bbtext{Um grafo $G(V,E)$ é um \bbbold{grafo de sucessores} se, para qualquer $u\in V$, o}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 4.75
    @a1.text = \bbtext{grau de saída de $u$ é igual a $1$.}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 3.75
    @b.text = \bbtext{Um grafo de sucessores também é denominado \bbbold{grafo funcional}, pois está }
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 3
    @b1.text = \bbtext{associado a uma função $\mathrm{succ}: V \to V$ que define o conjunto de arestas}
    @b1.anchor = west

b2 => Node
    @b2.x = 7
    @b2.y = 2
    @b2.text = $\displaystyle E = \{\ (u, \mathrm{succ}(u))\ |\ u\in V\ \}$

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Características dos grafos de sucessores}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{Um grafo de sucessores $G$ tem exatamente $|V|$ arestas}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Há, no mínimo, um ciclo em $G$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{De fato, $G$ é composto por $k$ componentes, cada um deles com ao menos}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3
    @c1.text = \bbtext{um ciclo e um ou mais caminhos que levam a estes ciclos}
    @c1.anchor = west


---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbtext{Cada nó $u$ tem um sucessor $\mathrm{succ}(u)$ único}
    @d.anchor = west

## Scene

grid => Grid
    @grid.x = 2
    @grid.y = 0
    @grid.u = 12
    @grid.v = 1
    &grid.thick

succ => Node
    @succ.x = 2
    @succ.y = 0.5
    @succ.anchor = east
    @succ.text = $\mathrm{succ}[u] = $

l1 => Node
    @l1.x = 2.5
    @l1.y = 1.4
    @l1.text = \bbtext{1}

l2 => Node
    @l2.x = 3.5
    @l2.y = 1.4
    @l2.text = \bbtext{2}

l3 => Node
    @l3.x = 4.5
    @l3.y = 1.4
    @l3.text = \bbtext{3}

l4 => Node
    @l4.x = 5.5
    @l4.y = 1.4
    @l4.text = \bbtext{4}

l5 => Node
    @l5.x = 6.5
    @l5.y = 1.4
    @l5.text = \bbtext{5}

l6 => Node
    @l6.x = 7.5
    @l6.y = 1.4
    @l6.text = \bbtext{6}

l7 => Node
    @l7.x = 8.5
    @l7.y = 1.4
    @l7.text = \bbtext{7}

l8 => Node
    @l8.x = 9.5
    @l8.y = 1.4
    @l8.text = \bbtext{8}

l9 => Node
    @l9.x = 10.5
    @l9.y = 1.4
    @l9.text = \bbtext{9}

l10 => Node
    @l10.x = 11.5
    @l10.y = 1.4
    @l10.text = \bbtext{10}

v1 => Node
    @v1.x = 2.5
    @v1.y = 0.5
    @v1.text = $4$

v2 => Node
    @v2.x = 3.5
    @v2.y = 0.5
    @v2.text = $5$

v3 => Node
    @v3.x = 4.5
    @v3.y = 0.5
    @v3.text = $3$

v4 => Node
    @v4.x = 5.5
    @v4.y = 0.5
    @v4.text = $7$

v5 => Node
    @v5.x = 6.5
    @v5.y = 0.5
    @v5.text = $2$

v6 => Node
    @v6.x = 7.5
    @v6.y = 0.5
    @v6.text = $8$

v7 => Node
    @v7.x = 8.5
    @v7.y = 0.5
    @v7.text = $1$

v8 => Node
    @v8.x = 9.5
    @v8.y = 0.5
    @v8.text = $9$

v9 => Node
    @v9.x = 10.5
    @v9.y = 0.5
    @v9.text = $6$

v10 => Node
    @v10.x = 11.5
    @v10.y = 0.5
    @v10.text = $8$

---

node1 => Node
    @node1.x = 1
    @node1.y = 7
    @node1.text = \bbtext{1}
    @node1.fill = BBCyan
    &node1.very thick
    &node1.draw
    &node1.circle

---
node4 => Node
    @node4.x = 3
    @node4.y = 7
    @node4.text = \bbtext{4}
    @node4.fill = BBCyan
    &node4.very thick
    &node4.draw
    &node4.circle

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    &e14.-latex

---
node7 => Node
    @node7.x = 5
    @node7.y = 7
    @node7.text = \bbtext{7}
    @node7.fill = BBCyan
    &node7.very thick
    &node7.draw
    &node7.circle

e47 => Edge
    @e47.from = node4
    @e47.to = node7
    &e47.thick
    &e47.-latex

---
e71 => Edge
    @e71.from = node7
    @e71.to = node1
    &e71.thick
    &e71.-latex
    %e71.label = [bend left]

---
node2 => Node
    @node2.x = 7
    @node2.y = 7
    @node2.text = \bbtext{2}
    @node2.fill = BBGreen
    &node2.very thick
    &node2.draw
    &node2.circle

---
node5 => Node
    @node5.x = 7
    @node5.y = 5
    @node5.text = \bbtext{5}
    @node5.fill = BBGreen
    &node5.very thick
    &node5.draw
    &node5.circle

e25 => Edge
    @e25.from = node2
    @e25.to = node5
    &e25.thick
    &e25.-latex

---
e52 => Edge
    @e52.from = node5
    @e52.to = node2
    &e52.thick
    &e52.-latex
    %e52.label = [bend left]

---

node3 => Node
    @node3.x = 7
    @node3.y = 3
    @node3.text = \bbtext{3}
    @node3.fill = BBOrange
    &node3.very thick
    &node3.draw
    &node3.circle

---
e33 => Edge
    @e33.from = node3
    @e33.to = node3
    &e33.thick
    &e33.-latex
    %e33.label = [loop left]

---

node6 => Node
    @node6.x = 9
    @node6.y = 7
    @node6.text = \bbchalk{6}
    @node6.fill = BBBlack
    &node6.very thick
    &node6.draw
    &node6.circle

---

node8 => Node
    @node8.x = 11
    @node8.y = 7
    @node8.text = \bbchalk{8}
    @node8.fill = BBBlack
    &node8.very thick
    &node8.draw
    &node8.circle

e68 => Edge
    @e68.from = node6
    @e68.to = node8
    &e68.thick
    &e68.-latex

---

node9 => Node
    @node9.x = 13
    @node9.y = 7
    @node9.text = \bbchalk{9}
    @node9.fill = BBBlack
    &node9.very thick
    &node9.draw
    &node9.circle

e89 => Edge
    @e89.from = node8
    @e89.to = node9
    &e89.thick
    &e89.-latex
---

e96 => Edge
    @e96.from = node9
    @e96.to = node6
    &e96.thick
    &e96.-latex
    %e96.label = [bend right]
---

node10 => Node
    @node10.x = 11
    @node10.y = 5
    @node10.text = \bbchalk{10}
    @node10.fill = BBBlack
    &node10.very thick
    &node10.draw
    &node10.circle

e108 => Edge
    @e108.from = node10
    @e108.to = node8
    &e108.thick
    &e108.-latex

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{$k$-ésimo sucessor}
    @title.anchor = west
---

a => Node
    @a.x = 0.8
    @a.y = 5
    @a.text = \bbtext{Seja $G$ um grafo de sucessores. O $k$\bbbold{-ésimo sucessor} de um vértice $u$ é definido}
    @a.anchor = west

a1 => Node
    @a1.x = 0.3
    @a1.y = 4.25
    @a1.text = \bbtext{como}
    @a1.anchor = west

b => Node
    @b.x = 7
    @b.y = 3.25
    @b.text = $\displaystyle \mathrm{succ}(u, k) = \mathrm{succ}^k(u) = \mathrm{succ}(\mathrm{succ}(\ldots \mathrm{succ}(u)))$

---
p => Path
    @p.path = (7.2, 2.95) -- (7.2, 2.8) -- node[below] { \footnotesize \bbcomment{$k$ vezes} } (10.7, 2.8) -- (10.7, 2.95)
    @p.color = BBViolet

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Cálculo de $\mathrm{succ}(u, k)$ em $O(\log k)$}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{A função $\mathrm{succ}(u, k)$ pode ser computada, trivialmente, em $O(k)$}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Contudo, é possível computar $\mathrm{succ}(u, v)$ em $O(\log k)$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Basta pré-computar, para cada $u\in V$, os valores de $\mathrm{succ}(u, 2^i)$, para cada }
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.0
    @c1.text = \bbtext{$i = 0, 1, \ldots, M$ tal que $2^M\leq k$, por meio da recursão:}
    @c1.anchor = west


---

d => Node
    @d.x = 7
    @d.y = 1.75
    @d.text = $\displaystyle \mathrm{succ}(u, 2^i) = \left\{ \begin{array}{ll} \mathrm{succ}(u), & \mbox{se}\ $i = 0$\\ \mathrm{succ}(\mathrm{succ}(u, 2^{i - 1}), 2^{i - 1}),& \mbox{caso contrário}\end{array}\right.$


## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Cálculo de $\mathrm{succ}(u, k)$ em $O(\log k)$}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{Estes valores podem ser pré-computados em $O(|V|\log k)$}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{De posse destes valores, $\mathrm{succ}(u, k)$ é dado por}
    @b.anchor = west

c => Node
    @c.x = 7
    @c.y = 3.5
    @c.text = $\displaystyle \mathrm{succ}(u, k) = \mathrm{succ}(\mathrm{succ}(\mathrm{succ}(\mathrm{succ}(u, 2^\alpha), 2^\beta), \ldots), 2^\omega),$ 

d => Node
    @d.x = 0.5
    @d.y = 2.5
    @d.text = \bbtext{onde $k = 2^\alpha 2^\beta \ldots 2^\omega$}
    @d.anchor = west

## Scene

node1 => Node
    @node1.x = 7
    @node1.y = 6
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

 node2 => Node
    @node2.x = 8.5
    @node2.y = 6
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

 node3 => Node
    @node3.x = 10
    @node3.y = 6
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

 node4 => Node
    @node4.x = 10
    @node4.y = 4
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

 node5 => Node
    @node5.x = 11.5
    @node5.y = 6
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

 node6 => Node
    @node6.x = 13
    @node6.y = 6
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.-latex
    &e12.thick

e32 => Edge
    @e32.from = node2
    @e32.to = node3
    &e32.-latex
    &e32.thick

e34 => Edge
    @e34.from = node4
    @e34.to = node3
    &e34.-latex
    &e34.thick

e35 => Edge
    @e35.from = node3
    @e35.to = node5
    &e35.-latex
    &e35.thick

e65 => Edge
    @e65.from = node5
    @e65.to = node6
    &e65.-latex
    &e65.thick

e61 => Edge
    @e61.from = node6
    @e61.to = node1
    &e61.-latex
    &e61.thick
    %e61.label = [bend right]

---

grid => Grid
    @grid.x = 1
    @grid.y = 1
    @grid.u = 5
    @grid.v = 7
    &grid.thick

k1 => Node
    @k1.x = 1.5
    @k1.y = 7.4
    @k1.text = \bbtext{1}

k2 => Node
    @k2.x = 2.5
    @k2.y = 7.4
    @k2.text = \bbtext{2}

k3 => Node
    @k3.x = 3.5
    @k3.y = 7.4
    @k3.text = \bbtext{4}

k4 => Node
    @k4.x = 4.5
    @k4.y = 7.4
    @k4.text = \bbtext{8}

x1 => Node
    @x1.x = 0.6
    @x1.y = 6.5
    @x1.text = \bbtext{1}

x2 => Node
    @x2.x = 0.6
    @x2.y = 5.5
    @x2.text = \bbtext{2}

x3 => Node
    @x3.x = 0.6
    @x3.y = 4.5
    @x3.text = \bbtext{3}

x4 => Node
    @x4.x = 0.6
    @x4.y = 3.5
    @x4.text = \bbtext{4}

x5 => Node
    @x5.x = 0.6
    @x5.y = 2.5
    @x5.text = \bbtext{5}

x6 => Node
    @x6.x = 0.6
    @x6.y = 1.5
    @x6.text = \bbtext{6}

succ => Node
    @succ.x = 3
    @succ.y = 0.5
    @succ.text = $\mathrm{succ}(u, k)$

---

v11 => Node
    @v11.x = 1.5
    @v11.y = 6.5
    @v11.text = $2$

v21 => Node
    @v21.x = 1.5
    @v21.y = 5.5
    @v21.text = $3$

v31 => Node
    @v31.x = 1.5
    @v31.y = 4.5
    @v31.text = $5$

v41 => Node
    @v41.x = 1.5
    @v41.y = 3.5
    @v41.text = $3$

v51 => Node
    @v51.x = 1.5
    @v51.y = 2.5
    @v51.text = $6$

v61 => Node
    @v61.x = 1.5
    @v61.y = 1.5
    @v61.text = $1$

---
    @node1.fill = BBGreen
---
    @node2.fill = BBOrange
---
    @node3.fill = BBCyan
---
v12 => Node
    @v12.x = 2.5
    @v12.y = 6.5
    @v12.text = $3$
---
    @node1.fill = BBWhite
    @node2.fill = BBWhite
    @node3.fill = BBWhite

    @node2.fill = BBGreen
---
    @node3.fill = BBOrange
---
    @node5.fill = BBCyan
---
v22 => Node
    @v22.x = 2.5
    @v22.y = 5.5
    @v22.text = $5$
---
    @node2.fill = BBWhite
    @node3.fill = BBWhite
    @node5.fill = BBWhite

    @node3.fill = BBGreen
---
    @node5.fill = BBOrange
---
    @node6.fill = BBCyan
---
v32 => Node
    @v32.x = 2.5
    @v32.y = 4.5
    @v32.text = $6$
---
    @node3.fill = BBWhite
    @node5.fill = BBWhite
    @node6.fill = BBWhite

    @node4.fill = BBGreen
---
    @node3.fill = BBOrange
---
    @node5.fill = BBCyan
---
v42 => Node
    @v42.x = 2.5
    @v42.y = 3.5
    @v42.text = $5$
---
    @node4.fill = BBWhite
    @node3.fill = BBWhite
    @node5.fill = BBWhite

    @node5.fill = BBGreen
---
    @node6.fill = BBOrange
---
    @node1.fill = BBCyan
---
v52 => Node
    @v52.x = 2.5
    @v52.y = 2.5
    @v52.text = $1$
---
    @node5.fill = BBWhite
    @node6.fill = BBWhite
    @node1.fill = BBWhite

    @node6.fill = BBGreen
---
    @node1.fill = BBOrange
---
    @node2.fill = BBCyan
---
v62 => Node
    @v62.x = 2.5
    @v62.y = 1.5
    @v62.text = $2$
---
    @node6.fill = BBWhite
    @node1.fill = BBWhite
    @node2.fill = BBWhite

    @node1.fill = BBGreen
---
    @node3.fill = BBOrange
---
    @node6.fill = BBCyan
---
v14 => Node
    @v14.x = 3.5
    @v14.y = 6.5
    @v14.text = $6$
---
    @node1.fill = BBWhite
    @node3.fill = BBWhite
    @node6.fill = BBWhite

    @node2.fill = BBGreen
---
    @node5.fill = BBOrange
---
    @node1.fill = BBCyan
---
v24 => Node
    @v24.x = 3.5
    @v24.y = 5.5
    @v24.text = $1$
---
    @node2.fill = BBWhite
    @node5.fill = BBWhite
    @node1.fill = BBWhite

    @node3.fill = BBGreen
---
    @node6.fill = BBOrange
---
    @node2.fill = BBCyan
---
v34 => Node
    @v34.x = 3.5
    @v34.y = 4.5
    @v34.text = $2$
---
    @node3.fill = BBWhite
    @node6.fill = BBWhite
    @node2.fill = BBWhite

    @node4.fill = BBGreen
---
    @node5.fill = BBOrange
---
    @node1.fill = BBCyan
---
v44 => Node
    @v44.x = 3.5
    @v44.y = 3.5
    @v44.text = $1$
---
    @node4.fill = BBWhite
    @node5.fill = BBWhite
    @node1.fill = BBWhite

    @node5.fill = BBGreen
---
    @node1.fill = BBOrange
---
    @node3.fill = BBCyan
---
v54 => Node
    @v54.x = 3.5
    @v54.y = 2.5
    @v54.text = $3$
---
    @node5.fill = BBWhite
    @node1.fill = BBWhite
    @node3.fill = BBWhite

    @node6.fill = BBGreen
---
    @node2.fill = BBOrange
---
    @node5.fill = BBCyan
---
v64 => Node
    @v64.x = 3.5
    @v64.y = 1.5
    @v64.text = $5$
---
    @node6.fill = BBWhite
    @node2.fill = BBWhite
    @node5.fill = BBWhite

    @node1.fill = BBGreen
---
    @node6.fill = BBOrange
---
    @node5.fill = BBCyan
---
v18 => Node
    @v18.x = 4.5
    @v18.y = 6.5
    @v18.text = $5$
---
    @node1.fill = BBWhite
    @node6.fill = BBWhite
    @node5.fill = BBWhite

    @node2.fill = BBGreen
---
    @node1.fill = BBOrange
---
    @node6.fill = BBCyan
---
v28 => Node
    @v28.x = 4.5
    @v28.y = 5.5
    @v28.text = $6$
---
    @node2.fill = BBWhite
    @node1.fill = BBWhite
    @node6.fill = BBWhite

    @node3.fill = BBGreen
---
    @node2.fill = BBOrange
---
    @node1.fill = BBCyan
---
v38 => Node
    @v38.x = 4.5
    @v38.y = 4.5
    @v38.text = $1$
---
    @node3.fill = BBWhite
    @node2.fill = BBWhite
    @node1.fill = BBWhite

    @node4.fill = BBGreen
---
    @node1.fill = BBOrange
---
    @node6.fill = BBCyan
---
v48 => Node
    @v48.x = 4.5
    @v48.y = 3.5
    @v48.text = $6$
---
    @node4.fill = BBWhite
    @node1.fill = BBWhite
    @node6.fill = BBWhite

    @node5.fill = BBGreen
---
    @node3.fill = BBOrange
---
    @node2.fill = BBCyan
---
v58 => Node
    @v58.x = 4.5
    @v58.y = 2.5
    @v58.text = $2$
---
    @node5.fill = BBWhite
    @node3.fill = BBWhite
    @node2.fill = BBWhite

    @node6.fill = BBGreen
---
    @node5.fill = BBOrange
---
    @node3.fill = BBCyan
---
v68 => Node
    @v68.x = 4.5
    @v68.y = 1.5
    @v68.text = $3$

---
    @node3.fill = BBWhite
    @node5.fill = BBWhite
    @node6.fill = BBWhite

eq => Node
    @eq.x = 7
    @eq.y = 2
    @eq.text = $\displaystyle \mathrm{succ}(4, 14) = \mathrm{succ}(\mathrm{succ}(\mathrm{succ}(4, 2), 4), 8)$
    @eq.anchor = west
---
    @eq.text = $\displaystyle \mathrm{succ}(4, 14) = \mathrm{succ}(\mathrm{succ}(5, 4), 8)$
    @v42.text = $\mathbf{5}$

---
    @eq.text = $\displaystyle \mathrm{succ}(4, 14) = \mathrm{succ}(3, 8)$
    @v42.text = $5$
    @v54.text = $\mathbf{3}$

---
    @eq.text = $\displaystyle \mathrm{succ}(4, 14) = 1$
    @v54.text = ${3}$
    @v38.text = $\mathbf{1}$

## Frame

\inputsnippet{cpp}{9}{26}{codes/succ.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Problemas sugeridos}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $1.$ \bbtext{CSES 1750 -- Planets Queries I}
    @a.anchor = west

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $2.$ \bbtext{USACO 2017 December Contest, Silver - Problem 3: The Bovine Shuffle}
    @c.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Referências}
    @title.anchor = west

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $1.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $2.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $2.$ \bbbold{USACO}, \bbtext{Guide.} \bbenglish{Introduction to Functional Graphs}, \bbtext{acesso em 21/09/2021.}
    @d.anchor = west

## End

https://usaco.guide/silver/func-graphs?lang=cpp
https://cp.cyberlabs.club/docs/roadmap/advanced/dp-on-graphs/

http://www.usaco.org/index.php?page=viewproblem2&cpid=764

Planet Queries I - https://cses.fi/problemset/task/1750
Planet Queries II - https://cses.fi/problemset/task/1160

Planet Cycles - https://cses.fi/problemset/task/1751

