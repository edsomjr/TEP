## Frame
\bbcover{Grafos}{Componentes fortemente conectados}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Grafos fortemente conectados}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = \bbtext{Seja $G(V, E)$ um grafo direcionado. Dizemos que $G$ é \bbbold{fortemente conectado}}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 4.75
    @a1.text = \bbtext{se, para qualquer par de vértices $u, v\in V$, existe pelo menos um caminho de}
    @a1.anchor = west

a2 => Node
    @a2.x = 0.5
    @a2.y = 4.0
    @a2.text = \bbtext{$u$ até $v$.}
    @a2.anchor = west

---

node1 => Node
    @node1.x = 2
    @node1.y = 1.0
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

node2 => Node
    @node2.x = 5
    @node2.y = 1.0
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

node3 => Node
    @node3.x = 3.5
    @node3.y = 3
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.thick
    &e23.-latex

e31 => Edge
    @e31.from = node3
    @e31.to = node1
    &e31.thick
    &e31.-latex

---

text1 => Node
    @text1.x = 5.5
    @text1.y = 2.5
    @text1.text = \bbtext{\Large \textcolor{BBGreen}{\faCheck}}
    @text1.anchor = west

---

node4 => Node
    @node4.x = 8
    @node4.y = 1.0
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

node5 => Node
    @node5.x = 11
    @node5.y = 1.0
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node6 => Node
    @node6.x = 9.5
    @node6.y = 3
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    &e45.-latex

e46 => Edge
    @e46.from = node4
    @e46.to = node6
    &e46.thick
    &e46.-latex


e56 => Edge
    @e56.from = node5
    @e56.to = node6
    &e56.thick
    &e56.-latex


---

text2 => Node
    @text2.x = 11.5
    @text2.y = 2.5
    @text2.text = \bbtext{\Large \textcolor{BBRed}{\faClose}}
    @text2.anchor = west


## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Componentes fortemente conectados}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = \bbtext{Seja $G(V, E)$ um grafo direcionado. Um \bbbold{componente fortemente conectado}}
    @a.anchor = west

b => Node
    @b.x = 0.5
    @b.y = 4.75
    @b.text = \bbtext{ de $G$ é um subgrafo $S$ de $G$ fortemente conectado.}
    @b.anchor = west

---

b1 => Node
    @b1.x = 1.0
    @b1.y = 3.25
    @b1.text = \bbtext{Se $G$ é dividido nos maiores componentes conectados possíveis (maiores em}
    @b1.anchor = west

b2 => Node
    @b2.x = 0.5
    @b2.y = 2.5
    @b2.text = \bbtext{relação ao número de vértices), estes componentes formarão um grafo acíclico} 
    @b2.anchor = west

c => Node
    @c.x = 0.5
    @c.y = 1.75
    @c.text = \bbtext{que representa a estrutura subjacente do grafo original.}
    @c.anchor = west

## Scene

node1 => Node
    @node1.x = 1
    @node1.y = 4
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

node2 => Node
    @node2.x = 4
    @node2.y = 6
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

node3 => Node
    @node3.x = 4
    @node3.y = 2
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

node4 => Node
    @node4.x = 7
    @node4.y = 6
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

node5 => Node
    @node5.x = 7
    @node5.y = 2
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node7 => Node
    @node7.x = 10
    @node7.y = 6
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node6 => Node
    @node6.x = 10
    @node6.y = 2
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node8 => Node
    @node8.x = 13
    @node8.y = 4
    @node8.text = \bbtext{8}
    &node8.very thick
    &node8.draw
    &node8.circle

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    &e13.-latex

e23 => Edge
    @e23.from = node3
    @e23.to = node2
    &e23.thick
    &e23.-latex
    %e23.label = [bend right]

e32 => Edge
    @e32.from = node2
    @e32.to = node3
    &e32.thick
    &e32.-latex
    %e32.label = [bend right]

e24 => Edge
    @e24.from = node2
    @e24.to = node4
    &e24.thick
    &e24.-latex

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    &e34.-latex

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

e56 => Edge
    @e56.from = node5
    @e56.to = node6
    &e56.thick
    &e56.-latex

e67 => Edge
    @e67.from = node6
    @e67.to = node7
    &e67.thick
    &e67.-latex

e68 => Edge
    @e68.from = node6
    @e68.to = node8
    &e68.thick
    &e68.-latex

e75 => Edge
    @e75.from = node7
    @e75.to = node5
    &e75.thick
    &e75.-latex

e87 => Edge
    @e87.from = node8
    @e87.to = node7
    &e87.thick
    &e87.-latex

---
    @node1.fill = BBCyan

p1 => Path
    @p1.path = (0.25, 3.25) -- (0.25, 4.75) -- (1.75, 4.75) -- (1.75, 3.25) -- cycle
    @p1.color = BBRed
    &p1.dashed

---
    @node2.fill = BBGreen
    @node3.fill = BBGreen

p2 => Path
    @p2.path = (3.25, 1.25) -- (3.25, 6.75) -- (4.75, 6.75) -- (4.75, 1.25) -- cycle
    @p2.color = BBRed
    &p2.dashed

---
    @node4.fill = BBViolet

p3 => Path
    @p3.path = (6.25, 5.25) -- (6.25, 6.75) -- (7.75, 6.75) -- (7.75, 5.25) -- cycle
    @p3.color = BBRed
    &p3.dashed

---
    @node5.fill = BBOrange
    @node6.fill = BBOrange
    @node7.fill = BBOrange
    @node8.fill = BBOrange

p4 => Path
    @p4.path = (6.25, 1.25) -- (6.25, 2.75) -- (9.25, 6.75) -- (10.75, 6.75) -- (13.75, 4.75) -- (13.75, 3.25) -- (10.75, 1.25) -- cycle
    @p4.color = BBRed
    &p4.dashed

---
    @node1.text = {\Huge \bbbold{A}}
    -p1

---
    @node2.text = {\Huge \bbbold{B}}
    -node3
    -e13
    -e34
    -e32
    -p2
    -e23

---
    @node4.text = {\Huge \bbbold{C}}
    -p3

---
    @node6.text = {\Huge \bbbold{D}}
    -p4
    -node5
    -node7
    -node8
    -e56
    -e68
    -e67
    -e75
    -e87
    -e47
    -e45

e46 => Edge
    @e46.from = node4
    @e46.to = node6
    &e46.thick
    &e46.-latex

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

## End

