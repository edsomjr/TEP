## Frame
\bbcover{Grafos}{Algoritmo de Kruskall}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Proponente}
    @title.anchor = west

floyd => Node
    @floyd.x = 7
    @floyd.y = 4
    @floyd.text = \includegraphics[scale=0.4]{figs/kruskal.jpeg}

fname => Node
    @fname.x = 7
    @fname.y = 1
    @fname.text = \bbbold{Joseph Bernard Kruskall, Jr.}

fdate => Node
    @fdate.x = 7
    @fdate.y = 0.5
    @fdate.text = \bbtext{(1962)}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Características do algoritmo de Kruskall}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{O algoritmo de Kruskall encontra uma MST usando uma abordagem gulosa}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{As arestas são ordenadas, ascendentemente, por peso}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{Inicialmente os vértices formam uma floresta de vértices isolados}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $\star$ \bbtext{Na ordem estipulada, cada aresta que una dois componentes conectados}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 2.5
    @d1.text = \bbtext{fará parte da MST e unirá estes componentes distintos}
    @d1.anchor = west


---

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $\star$ \bbtext{\bbbold{Complexidade}: $O(E\log V)$ }
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
    @input.text = \bbemph{Entrada:} \bbtext{um grafo ponderado $G(V, E)$}
    @input.anchor = west

output => Node
    @output.x = 0.5
    @output.y = 5.5
    @output.text = \bbemph{Saída:} \bbtext{uma MST de $G$}
    @output.anchor = west

step1 => Node
    @step1.x = 1.0
    @step1.y = 4.5
    @step1.text = $1.$ \bbtext{Faça $M = \emptyset$ e seja $F(V, \emptyset)$ uma floresta de vértices isolados}
    @step1.anchor = west

step2 => Node
    @step2.x = 1.0
    @step2.y = 3.5
    @step2.text = $2.$ \bbtext{Ordene $E$ ascendentemente, por peso} 
    @step2.anchor = west

step3 => Node
    @step3.x = 1.0
    @step3.y = 2.5
    @step3.text = $3.$ \bbtext{Para cada $(u, v, w)\in E$, se $u$ e $v$ estão em componentes distintos de $F$:}
    @step3.anchor = west

step3a => Node
    @step3a.x = 2.0
    @step3a.y = 2.0
    @step3a.text = $(a)$ \bbtext{Una estes componentes em $F$}
    @step3a.anchor = west

step3b => Node
    @step3b.x = 2.0
    @step3b.y = 1.5
    @step3b.text = $(b)$ \bbtext{Inclua $(u, v, w)$ no conjunto $M$}
    @step3b.anchor = west

step4 => Node
    @step4.x = 1.0
    @step4.y = 0.5
    @step4.text = $4.$ \bbtext{Retorne $M$}
    @step4.anchor = west


## Scene

x1 => Node
    @x1.x = 10
    @x1.y = 6
    @x1.text = \bbtext{\tt 1 2 3}
    @x1.anchor = west

x2 => Node
    @x2.x = 10
    @x2.y = 5.5
    @x2.text = \bbtext{\tt 1 4 5}
    @x2.anchor = west

x3 => Node
    @x3.x = 10
    @x3.y = 5.0
    @x3.text = \bbtext{\tt 2 4 1}
    @x3.anchor = west

x4 => Node
    @x4.x = 10
    @x4.y = 4.5
    @x4.text = \bbtext{\tt 2 1 5}
    @x4.anchor = west

x5 => Node
    @x5.x = 10
    @x5.y = 4.0
    @x5.text = \bbtext{\tt 3 3 4}
    @x5.anchor = west

x6 => Node
    @x6.x = 10
    @x6.y = 3.5
    @x6.text = \bbtext{\tt 4 2 1}
    @x6.anchor = west

x7 => Node
    @x7.x = 10
    @x7.y = 3
    @x7.text = \bbtext{\tt 5 3 1}
    @x7.anchor = west

x8 => Node
    @x8.x = 10
    @x8.y = 2.5
    @x8.text = \bbtext{\tt 7 3 6}
    @x8.anchor = west

x9 => Node
    @x9.x = 10
    @x9.y = 2
    @x9.text = \bbtext{\tt 8 6 5}
    @x9.anchor = west

E => Node
    @E.x = 10.4
    @E.y = 6.75
    @E.text = \large $E$
    @E.anchor = west


node1 => Node
    @node1.x = 6
    @node1.y = 5
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

 node2 => Node
    @node2.x = 4
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

 node3 => Node
    @node3.x = 2
    @node3.y = 5
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

 node4 => Node
    @node4.x = 6
    @node4.y = 3
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

 node5 => Node
    @node5.x = 4
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

 node6 => Node
    @node6.x = 2
    @node6.y = 3
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

---

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.thick
    %e23.label = node[above left] {\footnotesize \bbinfo{1}}

    @x1.text = \bbtext{\tt 1 2 3}\ \ \footnotesize{\textcolor{BBGreen}{\faCheck}}

---

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    %e45.label = node[below right] {\footnotesize \bbinfo{1}}

    @x2.text = \bbtext{\tt 1 4 5}\ \ \footnotesize{\textcolor{BBGreen}{\faCheck}}

---

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    %e14.label = node[right] {\footnotesize \bbinfo{2}}

    @x3.text = \bbtext{\tt 2 4 1}\ \ \footnotesize{\textcolor{BBGreen}{\faCheck}}

---

    @x4.text = \bbtext{\tt 2 1 5}\ \ \footnotesize{\textcolor{BBRed}{\faClose}}

---

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    %e34.label = node[above] {\footnotesize \bbinfo{3}}

    @x5.text = \bbtext{\tt 3 3 4}\ \ \footnotesize{\textcolor{BBGreen}{\faCheck}}

---

    @x6.text = \bbtext{\tt 4 2 1}\ \ \footnotesize{\textcolor{BBRed}{\faClose}}

---

    @x7.text = \bbtext{\tt 5 3 1}\ \ \footnotesize{\textcolor{BBRed}{\faClose}}

---

e36 => Edge
    @e36.from = node3
    @e36.to = node6
    &e36.thick
    %e36.label = node[below left] {\footnotesize \bbinfo{7}}

    @x8.text = \bbtext{\tt 7 3 6}\ \ \footnotesize{\textcolor{BBGreen}{\faCheck}}

---

    @x9.text = \bbtext{\tt 8 6 5}\ \ \footnotesize{\textcolor{BBRed}{\faClose}}

## Frame

\inputsnippet{cpp}{46}{63}{codes/kruskal.cpp}

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
    @title.y = 7
    @title.text = \Large \bbbold{Referências}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $1.$ \bbtext{\bbbold{CP-Algorithm}. \bbenglish{Minimum spanning tree -- Kruskall's algorithm}, acesso em}
    @a.anchor = west

a1 => Node
    @a1.x = 2
    @a1.y = 5.5
    @a1.text = \bbtext{24/08/2021.}
    @a1.anchor = west

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $2.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $3.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $4.$ \bbbold{Wikipédia}. \bbenglish{Joseph Kruskal,} \bbtext{acesso em 24/08/2021.}
    @d.anchor = west

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $5.$ \bbbold{Wikipédia}. \bbenglish{Kruskal's algorithm,} \bbtext{acesso em 24/08/2021.}
    @e.anchor = west


## End

https://cses.fi/problemset/task/1675 - MST cost
https://www.spoj.com/problems/EC_MODE/ - MST cost
https://codeforces.com/contest/17/problem/B - MST cost
https://www.spoj.com/problems/IITKWPCG/ - MST de multiplicação
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2833 - MST cost e number of vertex
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3649 - MST
https://www.codechef.com/problems/CHEFELEC - MST e coordenadas cartesianas
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1541 - Second BEST MST
http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=989 - Minimax
http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1040 - Minimax
http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1310 - Minimum spanning forest
