## Frame
\bbcover{Grafos}{Algoritmo de Floyd-Warshall}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

floyd => Node
    @floyd.x = 2
    @floyd.y = 5
    @floyd.text = \includegraphics[scale=0.4]{figs/floyd.jpg}

fname => Node
    @fname.x = 2
    @fname.y = 2.75
    @fname.text = \bbbold{Robert W. Floyd}

fdate => Node
    @fdate.x = 2
    @fdate.y = 2.25
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

step2 => Node
    @step2.x = 1.0
    @step2.y = 2.0
    @step2.text = $2.$ \bbtext{Para cada vértice $k$ e todos os pares $(u,v)\in V^2$, faça}
    @step2.anchor = west

dist => Node
    @dist.x = 7.0
    @dist.y = 1.25
    @dist.text = $d[u][v] = \min(d[u][v], d[u][k] + d[k][v])$

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
    %e15.label = node[below right,pos=.8] {\footnotesize \bbinfo{2}}



## End

## Scene
+ \node[anchor=west] at (0, 5.5) { 

+ \node[anchor=west] at (1, 4.5) { 

+ \node[anchor=west] at (1, 3.5) { $2.$ \bbtext{Para cada aresta $(u, v, w)\in E$, se existe um caminho de $s$ a $u$ (isto é, } };
+ \node[anchor=west] at (0.5, 3.0) { \bbtext{$d[u] < \infty$) e $d[u] + w < d[v]$, faça $d[v] = d[u] + w$} };

+ \node[anchor=west] at (1, 2.0) { $3.$ \bbtext{Se o vetor $d$ foi atualizado ao menos uma vez, volte ao passo $2.$ } };

+ \node[anchor=west] at (1, 1.0) { $4.$ \bbtext{Retorne $d$ } };


