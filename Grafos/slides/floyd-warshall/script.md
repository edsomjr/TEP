## Frame
\bbcover{Grafos}{Algoritmo de Floyd-Warshall}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 1
    @title.y = 7
    @title.text = \Large \bbbold{Proponentes}

---

floyd => Node
    @floyd.x = 2
    @floyd.y = 4
    @floyd.text = \includegraphics[scale=0.4]{figs/floyd.jpg}

fname => Node
    @fname.x = 2
    @fname.y = 1.75
    @fname.text = \bbbold{Robert W. Floyd}

fdate => Node
    @fdate.x = 2
    @fdate.y = 1.25
    @fdate.text = \bbtext{(1962)}


---

warshall => Node
    @warshall.x = 8
    @warshall.y = 6
    @warshall.text = \includegraphics[scale=2.4]{figs/warshall.jpg}

wname => Node
    @wname.x = 11
    @wname.y = 6.5
    @wname.text = \bbbold{Stephen Warshall}

wdate => Node
    @wdate.x = 11
    @wdate.y = 6.0
    @wdate.text = \bbtext{(1962)}

---

roy => Node
    @roy.x = 8
    @roy.y = 2
    @roy.text = \includegraphics[scale=0.1]{figs/roy.jpg}

rname => Node
    @rname.x = 11.5
    @rname.y = 2.5
    @rname.text = \bbbold{Bernard Roy}

rdate => Node
    @rdate.x = 11.5
    @rdate.y = 2.0
    @rdate.text = \bbtext{(1959)}


## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Características do algoritmo de Bellman-Ford}
    @title.anchor = west
---

a => Node
    @a.x = 0.5
    @a.y = 6
    @a.text = $\star$ \bbtext{Computa o caminho mínimo entre todos os pares de vértices de $G(V, E)$}
    @a.anchor = west

---

b => Node
    @b.x = 0.5
    @b.y = 5
    @b.text = $\star$ \bbtext{É capaz de processar arestas negativas}
    @b.anchor = west

---

c => Node
    @c.x = 0.5
    @c.y = 4
    @c.text = $\star$ \bbtext{Não processa, mas identifica ciclos negativos}
    @c.anchor = west

---

d => Node
    @d.x = 0.5
    @d.y = 3
    @d.text = $\star$ \bbtext{As distâncias são reduzidas por meio do uso de vértices intermediários}
    @d.anchor = west

---

e => Node
    @e.x = 0.5
    @e.y = 2
    @e.text = $\star$ \bbtext{\bbbold{Complexidade}: $O(V^3)$ }
    @e.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Pseudocódigo}
    @title.anchor = west

---

input => Node
    @input.x = 0.5
    @input.y = 6
    @input.text = \bbemph{Entrada:} \bbtext{um grafo $G(V, E)$}
    @input.anchor = west

output => Node
    @output.x = 0.5
    @output.y = 5.5
    @output.text = \bbemph{Saída:} \bbtext{uma matriz $d$ tal que $d[u][v]$ é a distância mínima em $G$ entre $u$ e $v$}
    @output.anchor = west

---

step1 => Node
    @step1.x = 1.0
    @step1.y = 4.5
    @step1.text = $1.$ \bbtext{Faça:}
    @step1.anchor = west

step1_1 => Node
    @step1_1.x = 1.5
    @step1_1.y = 4.0
    @step1_1.text = $(a)$ $d[u][u] = 0$, \bbtext{para todos} $u\in V$
    @step1_1.anchor = west

step1_2 => Node
    @step1_2.x = 1.5
    @step1_2.y = 3.5
    @step1_2.text = $(b)$ $d[u][v] = w$, \bbtext{se} $(u, v, w)\in E$
    @step1_2.anchor = west

step1_3 => Node
    @step1_3.x = 1.5
    @step1_3.y = 3.0
    @step1_3.text = $(c)$ $d[u][v] = \infty$, \bbtext{caso contrário}
    @step1_3.anchor = west

---

step2 => Node
    @step2.x = 1.0
    @step2.y = 2.0
    @step2.text = $2.$ \bbtext{Para cada vértice $k$ e todos os pares $(u,v)\in V^2$, faça}
    @step2.anchor = west

dist => Node
    @dist.x = 7.0
    @dist.y = 1.25
    @dist.text = $d[u][v] = \min(d[u][v], d[u][k] + d[k][v])$

---

step3 => Node
    @step3.x = 1.0
    @step3.y = 0.5
    @step3.text = $3.$ \bbtext{Retorne} $d$
    @step3.anchor = west

## Scene

grid => Grid
    @grid.x = 8
    @grid.y = 1
    @grid.u = 14
    @grid.v = 7
    &grid.very thick

x1 => Node
    @x1.x = 8.5
    @x1.y = 7.5
    @x1.text = \bbtext{\tt 1}

x2 => Node
    @x2.x = 9.5
    @x2.y = 7.5
    @x2.text = \bbtext{\tt 2}

x3 => Node
    @x3.x = 10.5
    @x3.y = 7.5
    @x3.text = \bbtext{\tt 3}

x4 => Node
    @x4.x = 11.5
    @x4.y = 7.5
    @x4.text = \bbtext{\tt 4}

x5 => Node
    @x5.x = 12.5
    @x5.y = 7.5
    @x5.text = \bbtext{\tt 5}

x6 => Node
    @x6.x = 13.5
    @x6.y = 7.5
    @x6.text = \bbtext{\tt 6}

y1 => Node
    @y1.x = 7.5
    @y1.y = 6.5
    @y1.text = \bbtext{\tt 1}

y2 => Node
    @y2.x = 7.5
    @y2.y = 5.5
    @y2.text = \bbtext{\tt 2}

y3 => Node
    @y3.x = 7.5
    @y3.y = 4.5
    @y3.text = \bbtext{\tt 3}

y4 => Node
    @y4.x = 7.5
    @y4.y = 3.5
    @y4.text = \bbtext{\tt 4}

y5 => Node
    @y5.x = 7.5
    @y5.y = 2.5
    @y5.text = \bbtext{\tt 5}

y6 => Node
    @y6.x = 7.5
    @y6.y = 1.5
    @y6.text = \bbtext{\tt 6}

node1 => Node
    @node1.x = 5
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
    @node3.x = 1
    @node3.y = 5
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

 node4 => Node
    @node4.x = 5
    @node4.y = 3
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

 node5 => Node
    @node5.x = 3
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

 node6 => Node
    @node6.x = 1
    @node6.y = 3
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle
    
e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    %e12.label = node[above right] {\footnotesize \bbinfo{9}}

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    %e13.label = node[above] {\footnotesize \bbinfo{7}}

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    %e14.label = node[right] {\footnotesize \bbinfo{4}}

e15 => Edge
    @e15.from = node1
    @e15.to = node5
    &e15.thick
    %e15.label = node[above left,pos=.6] {\footnotesize \bbinfo{2}}

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.thick
    %e23.label = node[above left] {\footnotesize \bbinfo{1}}

e26 => Edge
    @e26.from = node2
    @e26.to = node6
    &e26.thick
    %e26.label = node[below right,pos=.8] {\footnotesize \bbinfo{3}}

e26 => Edge
    @e26.from = node2
    @e26.to = node6
    &e26.thick
    %e26.label = node[below right,pos=.8] {\footnotesize \bbinfo{3}}

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    %e34.label = node[above] {\footnotesize \bbinfo{2}}

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    %e45.label = node[below right] {\footnotesize \bbinfo{1}}

e56 => Edge
    @e56.from = node5
    @e56.to = node6
    &e56.thick
    %e56.label = node[below left] {\footnotesize \bbinfo{11}}

---

a11 => Node
    @a11.x = 8.5
    @a11.y = 6.5
    @a11.text = $\mathbf{0}$

a22 => Node
    @a22.x = 9.5
    @a22.y = 5.5
    @a22.text = $\mathbf{0}$

a33 => Node
    @a33.x = 10.5
    @a33.y = 4.5
    @a33.text = $\mathbf{0}$

a44 => Node
    @a44.x = 11.5
    @a44.y = 3.5
    @a44.text = $\mathbf{0}$

a55 => Node
    @a55.x = 12.5
    @a55.y = 2.5
    @a55.text = $\mathbf{0}$

a66 => Node
    @a66.x = 13.5
    @a66.y = 1.5
    @a66.text = $\mathbf{0}$

--- 

@a11.text = $0$
@a22.text = $0$
@a33.text = $0$
@a44.text = $0$
@a55.text = $0$
@a66.text = $0$

a12 => Node
    @a12.x = 9.5
    @a12.y = 6.5
    @a12.text = $\mathbf{9}$

a21 => Node
    @a21.x = 8.5
    @a21.y = 5.5
    @a21.text = $\mathbf{9}$

a13 => Node
    @a13.x = 10.5
    @a13.y = 6.5
    @a13.text = $\mathbf{7}$

a31 => Node
    @a31.x = 8.5
    @a31.y = 4.5
    @a31.text = $\mathbf{7}$

a14 => Node
    @a14.x = 11.5
    @a14.y = 6.5
    @a14.text = $\mathbf{4}$

a41 => Node
    @a41.x = 8.5
    @a41.y = 3.5
    @a41.text = $\mathbf{4}$

a15 => Node
    @a15.x = 12.5
    @a15.y = 6.5
    @a15.text = $\mathbf{2}$

a51 => Node
    @a51.x = 8.5
    @a51.y = 2.5
    @a51.text = $\mathbf{2}$

a23 => Node
    @a23.x = 10.5
    @a23.y = 5.5
    @a23.text = $\mathbf{1}$

a32 => Node
    @a32.x = 9.5
    @a32.y = 4.5
    @a32.text = $\mathbf{1}$

a26 => Node
    @a26.x = 13.5
    @a26.y = 5.5
    @a26.text = $\mathbf{3}$

a62 => Node
    @a62.x = 9.5
    @a62.y = 1.5
    @a62.text = $\mathbf{3}$

a34 => Node
    @a34.x = 11.5
    @a34.y = 4.5
    @a34.text = $\mathbf{2}$

a43 => Node
    @a43.x = 10.5
    @a43.y = 3.5
    @a43.text = $\mathbf{2}$

a45 => Node
    @a45.x = 12.5
    @a45.y = 3.5
    @a45.text = $\mathbf{1}$

a54 => Node
    @a54.x = 11.5
    @a54.y = 2.5
    @a54.text = $\mathbf{1}$

a56 => Node
    @a56.x = 13.5
    @a56.y = 2.5
    @a56.text = $\mathbf{11}$

a65 => Node
    @a65.x = 12.5
    @a65.y = 1.5
    @a65.text = $\mathbf{11}$

---

@a12.text = $9$
@a13.text = $7$
@a14.text = $4$
@a15.text = $2$
@a21.text = $9$
@a23.text = $1$
@a26.text = $3$
@a31.text = $7$
@a32.text = $1$
@a34.text = $2$
@a41.text = $4$
@a43.text = $2$
@a45.text = $1$
@a51.text = $2$
@a54.text = $1$
@a56.text = $11$
@a62.text = $3$
@a65.text = $11$

a16 => Node
    @a16.x = 13.5
    @a16.y = 6.5
    @a16.text = $\mathbf{\infty}$

a24 => Node
    @a24.x = 11.5
    @a24.y = 5.5
    @a24.text = $\mathbf{\infty}$

a25 => Node
    @a25.x = 12.5
    @a25.y = 5.5
    @a25.text = $\mathbf{\infty}$

a35 => Node
    @a35.x = 12.5
    @a35.y = 4.5
    @a35.text = $\mathbf{\infty}$

a36 => Node
    @a36.x = 13.5
    @a36.y = 4.5
    @a36.text = $\mathbf{\infty}$

a42 => Node
    @a42.x = 9.5
    @a42.y = 3.5
    @a42.text = $\mathbf{\infty}$

a46 => Node
    @a46.x = 13.5
    @a46.y = 3.5
    @a46.text = $\mathbf{\infty}$

a52 => Node
    @a52.x = 9.5
    @a52.y = 2.5
    @a52.text = $\mathbf{\infty}$

a53 => Node
    @a53.x = 10.5
    @a53.y = 2.5
    @a53.text = $\mathbf{\infty}$

a61 => Node
    @a61.x = 8.5
    @a61.y = 1.5
    @a61.text = $\mathbf{\infty}$

a63 => Node
    @a63.x = 10.5
    @a63.y = 1.5
    @a63.text = $\mathbf{\infty}$

a64 => Node
    @a64.x = 11.5
    @a64.y = 1.5
    @a64.text = $\mathbf{\infty}$

---

    @node1.fill = BBCyan

    @a24.text = $\mathbf{13}$
    @a25.text = $\mathbf{11}$
    @a35.text = $\mathbf{9}$
    @a42.text = $\mathbf{13}$
    @a52.text = $\mathbf{11}$
    @a53.text = $\mathbf{9}$

---
    @node1.fill = BBGreen
    @node2.fill = BBCyan

    @a24.text = ${13}$
    @a25.text = ${11}$
    @a35.text = ${9}$
    @a42.text = ${13}$
    @a52.text = ${11}$
    @a53.text = ${9}$

    @a16.text = $\mathbf{12}$
    @a36.text = $\mathbf{4}$
    @a46.text = $\mathbf{16}$
    @a61.text = $\mathbf{12}$
    @a63.text = $\mathbf{4}$
    @a64.text = $\mathbf{16}$

---

    @node2.fill = BBGreen
    @node3.fill = BBCyan

    @a16.text = ${12}$
    @a36.text = ${4}$
    @a46.text = ${16}$
    @a61.text = ${12}$
    @a63.text = ${4}$
    @a64.text = ${16}$

    @a12.text = $\mathbf{8}$
    @a16.text = $\mathbf{11}$
    @a24.text = $\mathbf{3}$
    @a25.text = $\mathbf{10}$
    @a46.text = $\mathbf{6}$
    @a21.text = $\mathbf{8}$
    @a61.text = $\mathbf{11}$
    @a42.text = $\mathbf{3}$
    @a52.text = $\mathbf{10}$
    @a64.text = $\mathbf{6}$


---

    @node3.fill = BBGreen
    @node4.fill = BBCyan

    @a12.text = ${8}$
    @a16.text = ${11}$
    @a24.text = ${3}$
    @a25.text = ${10}$
    @a46.text = ${6}$
    @a21.text = ${8}$
    @a61.text = ${11}$
    @a42.text = ${3}$
    @a52.text = ${10}$
    @a64.text = ${6}$

    @a12.text = $\mathbf{7}$
    @a13.text = $\mathbf{6}$
    @a16.text = $\mathbf{10}$
    @a25.text = $\mathbf{4}$
    @a35.text = $\mathbf{3}$
    @a56.text = $\mathbf{7}$
    @a21.text = $\mathbf{7}$
    @a31.text = $\mathbf{6}$
    @a61.text = $\mathbf{10}$
    @a52.text = $\mathbf{4}$
    @a53.text = $\mathbf{3}$
    @a65.text = $\mathbf{7}$

---

    @node4.fill = BBGreen
    @node5.fill = BBCyan

    @a12.text = ${7}$
    @a13.text = ${6}$
    @a16.text = ${10}$
    @a25.text = ${4}$
    @a35.text = ${3}$
    @a56.text = ${7}$
    @a21.text = ${7}$
    @a31.text = ${6}$
    @a61.text = ${10}$
    @a52.text = ${4}$
    @a53.text = ${3}$
    @a65.text = ${7}$

    @a12.text = $\mathbf{6}$
    @a13.text = $\mathbf{5}$
    @a14.text = $\mathbf{3}$
    @a16.text = $\mathbf{9}$
    @a21.text = $\mathbf{6}$
    @a31.text = $\mathbf{5}$
    @a41.text = $\mathbf{3}$
    @a61.text = $\mathbf{9}$

---

    @node5.fill = BBGreen
    @node6.fill = BBCyan

    @a12.text = ${6}$
    @a13.text = ${5}$
    @a14.text = ${3}$
    @a16.text = ${9}$
    @a21.text = ${6}$
    @a31.text = ${5}$
    @a41.text = ${3}$
    @a61.text = ${9}$

## Frame

\inputsnippet{cpp}{11}{29}{codes/floyd.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Identificação de um caminho mínimo}
    @title.anchor = west

---

a1 => Node
    @a1.x = 1
    @a1.y = 6
    @a1.text = $\star$ \bbtext{O algoritmo de Dijkstra computa as distâncias mínimas, mas não os}
    @a1.anchor = west

a2 => Node
    @a2.x = 0.5
    @a2.y = 5.5
    @a2.text = \bbtext{caminhos mínimos}
    @a2.anchor = west

---

b1 => Node
    @b1.x = 1
    @b1.y = 4.5
    @b1.text = $\star$ \bbtext{Para determinar um caminho mínimo, é preciso definir uma matriz auxiliar}
    @b1.anchor = west

b2 => Node
    @b2.x = 0.5
    @b2.y = 4.0
    @b2.text = \bbtext{$\mathrm{pred}$, onde $\mathrm{pred}[u][v] = $ antecessor de $v$ no caminho mínimo de $u$ a $v$}
    @b2.anchor = west

---

c1 => Node
    @c1.x = 1
    @c1.y = 3.0
    @c1.text = $\star$ \bbtext{No início do algoritmo,}
    @c1.anchor = west

c2 => Node
    @c2.x = 2
    @c2.y = 2.5
    @c2.text = \bbtext{$(a)$ $\mathrm{pred}[u][u] = u, \forall u\in V$}
    @c2.anchor = west

c3 => Node
    @c3.x = 2
    @c3.y = 2.0
    @c3.text = \bbtext{$(b)$ $\mathrm{pred}[u][v] = u$, se $(u, v)\in E$}
    @c3.anchor = west

c4 => Node
    @c4.x = 2
    @c4.y = 1.5
    @c4.text = \bbtext{$(c)$ $\mathrm{pred}[u][v] = \mathrm{undef}$, caso contrário}
    @c4.anchor = west


## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Identificação de um caminho mínimo}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $\star$ \bbtext{Se $k$ atualizar $d[u][v]$, faça $\mathrm{pred}[u][v] = \mathrm{pred}[k][v]$}
    @a.anchor = west


---

b1 => Node
    @b1.x = 1
    @b1.y = 4
    @b1.text = $\star$ \bbtext{A sequência } 
    @b1.anchor = west

b2 => Node
    @b2.x = 7
    @b2.y = 3
    @b2.text = \bbtext{$ p = \{ (u, \mathrm{pred}^{k - 1}[u][v]), \ldots, (\mathrm{pred}[\mathrm{pred}[u][v]], \mathrm{pred}[u][v]), (\mathrm{pred}[u][v], v)\}$ }

b3 => Node
    @b3.x = 0.5
    @b3.y = 2
    @b3.text = \bbtext{é um caminho mínimo de $u$ a $v$ composto por $k$ arestas e tamanho $d[u][v]$}
    @b3.anchor = west

## Scene

a => Node
    @a.x = 0
    @a.y = 4
    @a.text = \bbtext{A}
    &a.circle
    &a.draw
    &a.very thick

b => Node
    @b.x = 3
    @b.y = 7
    @b.text = \bbtext{B}
    &b.circle
    &b.draw
    &b.very thick

c => Node
    @c.x = 6
    @c.y = 4
    @c.text = \bbtext{C}
    &c.circle
    &c.draw
    &c.very thick

d => Node
    @d.x = 3
    @d.y = 1
    @d.text = \bbtext{D}
    &d.circle
    &d.draw
    &d.very thick

eAB => Edge
    @eAB.from = a
    @eAB.to = b
    %eAB.label = node[above left] { \bbinfo{1} }
    &eAB.-latex
    &eAB.thick
    
eAC => Edge
    @eAC.from = a
    @eAC.to = c
    %eAC.label = node[above] { \bbinfo{4} }
    &eAC.-latex
    &eAC.thick
 
eAD => Edge
    @eAD.from = a
    @eAD.to = d
    %eAD.label = node[above right] { \bbinfo{9} }
    &eAD.-latex
    &eAD.thick
 
eBC => Edge
    @eBC.from = b
    @eBC.to = c
    %eBC.label = node[above right] { \bbinfo{2} }
    &eBC.-latex
    &eBC.thick
 
eCD => Edge
    @eCD.from = c
    @eCD.to = d
    %eCD.label = node[above left] { \bbinfo{5} }
    &eCD.-latex
    &eCD.thick
 
grid => Grid
    @grid.x = 9
    @grid.y = 2
    @grid.u = 13
    @grid.v = 6
    &grid.thick

matrix => Node
    @matrix.x = 8.5
    @matrix.y = 4
    @matrix.text = $M = $

legend => Node
    @legend.x = 11
    @legend.y = 1.0
    @legend.text = $m_{ij} = \mathrm{dist}[i][j]_{\mathrm{pred}[i][j]}$

r1 => Node
    @r1.x = 13.5
    @r1.y = 5.5
    @r1.text = \bbtext{A}

r2 => Node
    @r2.x = 13.5
    @r2.y = 4.5
    @r2.text = \bbtext{B}

r3 => Node
    @r3.x = 13.5
    @r3.y = 3.5
    @r3.text = \bbtext{C}

r4 => Node
    @r4.x = 13.5
    @r4.y = 2.5
    @r4.text = \bbtext{D}

c1 => Node
    @c1.x = 9.5
    @c1.y = 6.5
    @c1.text = \bbtext{A}

c2 => Node
    @c2.x = 10.5
    @c2.y = 6.5
    @c2.text = \bbtext{B}

c3 => Node
    @c3.x = 11.5
    @c3.y = 6.5
    @c3.text = \bbtext{C}

c4 => Node
    @c4.x = 12.5
    @c4.y = 6.5
    @c4.text = \bbtext{D}

---

a11 => Node
    @a11.x = 9.5
    @a11.y = 5.5
    @a11.text = $\bbupdate{0}_{\bbtext{A}}$

a22 => Node
    @a22.x = 10.5
    @a22.y = 4.5
    @a22.text = $\bbupdate{0}_{\bbtext{B}}$

a33 => Node
    @a33.x = 11.5
    @a33.y = 3.5
    @a33.text = $\bbupdate{0}_{\bbtext{C}}$

a44 => Node
    @a44.x = 12.5
    @a44.y = 2.5
    @a44.text = $\bbupdate{0}_{\bbtext{D}}$

---

    @a11.text = $0_{\bbtext{A}}$
    @a22.text = $0_{\bbtext{B}}$
    @a33.text = $0_{\bbtext{C}}$
    @a44.text = $0_{\bbtext{D}}$

a12 => Node
    @a12.x = 10.5
    @a12.y = 5.5
    @a12.text = $\bbupdate{1}_{\bbtext{A}}$

a13 => Node
    @a13.x = 11.5
    @a13.y = 5.5
    @a13.text = $\bbupdate{4}_{\bbtext{A}}$

a14 => Node
    @a14.x = 12.5
    @a14.y = 5.5
    @a14.text = $\bbupdate{9}_{\bbtext{A}}$

b23 => Node
    @b23.x = 11.5
    @b23.y = 4.5
    @b23.text = $\bbupdate{2}_{\bbtext{B}}$

c34 => Node
    @c34.x = 12.5
    @c34.y = 3.5
    @c34.text = $\bbupdate{5}_{\bbtext{C}}$

---

    @a12.text = $1_{\bbtext{A}}$
    @a13.text = $4_{\bbtext{A}}$
    @a14.text = $9_{\bbtext{A}}$
    @b23.text = $2_{\bbtext{B}}$
    @c34.text = $5_{\bbtext{C}}$

b21 => Node
    @b21.x = 9.5
    @b21.y = 4.5
    @b21.text = $\bbupdate{\infty}_{\bbtext{-}}$

b24 => Node
    @b24.x = 12.5
    @b24.y = 4.5
    @b24.text = $\bbupdate{\infty}_{\bbtext{-}}$

c31 => Node
    @c31.x = 9.5
    @c31.y = 3.5
    @c31.text = $\bbupdate{\infty}_{\bbtext{-}}$

c32 => Node
    @c32.x = 10.5
    @c32.y = 3.5
    @c32.text = $\bbupdate{\infty}_{\bbtext{-}}$

d41 => Node
    @d41.x = 9.5
    @d41.y = 2.5
    @d41.text = $\bbupdate{\infty}_{\bbtext{-}}$

d42 => Node
    @d42.x = 10.5
    @d42.y = 2.5
    @d42.text = $\bbupdate{\infty}_{\bbtext{-}}$

d43 => Node
    @d43.x = 11.5
    @d43.y = 2.5
    @d43.text = $\bbupdate{\infty}_{\bbtext{-}}$

---

    @a.fill = BBGreen
    
---

    @b.fill = BBGreen
    @a.fill = BBCyan

    @a13.text = $\bbupdate{3}_{\bbtext{\bbupdate{B}}}$

---

    @c.fill = BBGreen
    @b.fill = BBCyan

    @a13.text = ${3}_{\bbtext{{B}}}$
    @a14.text = $\bbupdate{8}_{\bbtext{\bbupdate{C}}}$
    @b24.text = $\bbupdate{7}_{\bbtext{\bbupdate{C}}}$

---

    @d.fill = BBGreen
    @c.fill = BBCyan

    @a14.text = ${8}_{\bbtext{{C}}}$
    @b24.text = ${7}_{\bbtext{{C}}}$

---

eDC => Edge
    @eDC.from = d
    @eDC.to = c
    @eDC.color = BBViolet
    %eDC.label = [bend right] node[below right, pos=0.3] { \tiny $(\mathrm{prev}[\mbox{\bbtext{A}}][\mbox{\bbtext{D}}], \mbox{\bbtext{D}})$ }
    &eDC.latex-
    &eDC.dashed

---

eCB => Edge
    @eCB.from = c
    @eCB.to = b
    @eCB.color = BBViolet
    %eCB.label = [bend right] node[above right, pos=0.3] { \tiny $(\mathrm{prev}[\bbtext{A}][\mbox{\bbtext{C}}], \mbox{\bbtext{C}})$ }
    &eCB.latex-
    &eCB.dashed

---

eBA => Edge
    @eBA.from = b
    @eBA.to = a
    @eBA.color = BBViolet
    %eBA.label = [bend right] node[above left, pos=0.3] { \tiny $(\mathrm{prev}[\bbtext{A}][\mbox{\bbtext{B}}], \mbox{\bbtext{B}})$ }
    &eBA.latex-
    &eBA.dashed

## Frame

\inputsnippet{cpp}{10}{27}{codes/floyd_path.cpp}

## Frame

\inputsnippet{cpp}{28}{44}{codes/floyd_path.cpp}

## Frame

\inputsnippet{cpp}{46}{58}{codes/floyd_path.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Identificação de ciclos negativos}
    @title.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 5.5
    @line1.text = $\star$ \bbtext{O algoritmo de Floyd-Warshall é capaz de detectar ciclos negativos}
    @line1.anchor = west

---

line2 => Node
    @line2.x = 1
    @line2.y = 4.5
    @line2.text = $\star$ \bbtext{Inicialmente $\dist[u][u] = 0, \forall u\in V$, se $G$ não tem \bbenglish{autoloops}}
    @line2.anchor = west


---

line3 => Node
    @line3.x = 1
    @line3.y = 3.5
    @line3.text = $\star$ \bbtext{Caso exista um ciclo negativo que passe por $u$, seguir este ciclo de $u$ a $u$}
    @line3.anchor = west

line3a => Node
    @line3a.x = 0.5
    @line3a.y = 3.0
    @line3a.text = \bbtext{torna $\dist[u][u] < 0$}
    @line3a.anchor = west

---

line4 => Node
    @line4.x = 1
    @line4.y = 2.0
    @line4.text = $\star$ \bbtext{Assim, $G$ terá um ciclo negativo se, ao final do algoritmo, $\dist[i][i] < 0$ para}
    @line4.anchor = west

line4a => Node
    @line4a.x = 0.5
    @line4a.y = 1.5
    @line4a.text = \bbtext{algum $i\in V$}
    @line4a.anchor = west

## Frame

\inputsnippet{cpp}{11}{30}{codes/cycle.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Problemas sugeridos}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $1.$ \bbtext{Codeforces Round \#179 (Div. 1) -- Problem B: Greg and Graph}
    @a.anchor = west

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $2.$ \bbtext{LightOJ -- Travel Company}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $3.$ \bbtext{OJ 104 -- Arbitrage}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $4.$ \bbtext{OJ 10171 -- Meeting Prof. Miguel...}
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
    @a.text = $1.$ \bbtext{\bbbold{CP-Algorithms}. \bbenglish{Floyd-Warshall Algorithm}, acesso em 03/08/2021.}
    @a.anchor = west

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $2.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $3.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $4.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.}
    @d.anchor = west

## End
