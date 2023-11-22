## Frame
\bbcover{Grafos}{Algoritmo de Kosaraju}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Proponente}
    @title.anchor = west

kosaraju => Node
    @kosaraju.x = 7
    @kosaraju.y = 4
    @kosaraju.text = \includegraphics[scale=0.6]{figs/kosaraju.jpeg}

kname => Node
    @kname.x = 7
    @kname.y = 1
    @kname.text = \bbbold{S. Rao Kosaraju}

kdate => Node
    @kdate.x = 7
    @kdate.y = 0.5
    @kdate.text = \bbtext{(1978)}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Características do algoritmo de Kosaraju}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{O algoritmo de Kosaraju encontra os componentes fortemente conectados}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 4.75
    @a1.text = \bbtext{de um grafo direcionado}
    @a1.anchor = west

---

b => Node
    @b.x = 1.0
    @b.y = 3.75
    @b.text = $\star$ \bbtext{O algoritmo realiza duas buscas em profundidade}
    @b.anchor = west

---

c => Node
    @c.x = 1.0
    @c.y = 2.75
    @c.text = $\star$ \bbtext{A primeira busca constrói uma lista de vértices, na ordem em que foram}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 2.0
    @c1.text = \bbtext{processados na DFS}
    @c1.anchor = west


---

d => Node
    @d.x = 1.0
    @d.y = 1.0
    @d.text = $\star$ \bbtext{A segunda busca identifica os componentes fortemente conectados do grafo}
    @d.anchor = west


## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Primeira busca}
    @title.anchor = west

order => Node
    @order.x = 6
    @order.y = 6.5
    @order.text = $O = \{\ \}$
    @order.anchor = west


node1 => Node
    @node1.x = 1
    @node1.y = 3
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

node2 => Node
    @node2.x = 4
    @node2.y = 5
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

node3 => Node
    @node3.x = 4
    @node3.y = 1
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

node4 => Node
    @node4.x = 7
    @node4.y = 5
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

node5 => Node
    @node5.x = 7
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node7 => Node
    @node7.x = 10
    @node7.y = 5
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node6 => Node
    @node6.x = 10
    @node6.y = 1
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node8 => Node
    @node8.x = 13
    @node8.y = 3
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
    @node1.fill = BBGreen

---
    @node2.fill = BBGreen

---
    @node3.fill = BBGreen

---
    @node4.fill = BBGreen

---
    @node5.fill = BBGreen

---
    @node6.fill = BBGreen

---
    @node8.fill = BBGreen

---
    @node7.fill = BBGreen

---
    @node7.fill = BBCyan
    @order.text = $O = \{\ 7\ \}$

---
    @node8.fill = BBCyan
    @order.text = $O = \{\ 7, 8\ \}$

---
    @node6.fill = BBCyan
    @order.text = $O = \{\ 7, 8, 6\ \}$

---
    @node5.fill = BBCyan
    @order.text = $O = \{\ 7, 8, 6, 5\ \}$

---
    @node4.fill = BBCyan
    @order.text = $O = \{\ 7, 8, 6, 5, 4\ \}$

---
    @node3.fill = BBCyan
    @order.text = $O = \{\ 7, 8, 6, 5, 4, 3\ \}$

---
    @node2.fill = BBCyan
    @order.text = $O = \{\ 7, 8, 6, 5, 4, 3, 2\ \}$

---
    @node1.fill = BBCyan
    @order.text = $O = \{\ 7, 8, 6, 5, 4, 3, 2, 1\ \}$


## Frame

\inputsnippet{cpp}{23}{31}{codes/dfs_order.cpp}

## Frame

\inputsnippet{cpp}{10}{21}{codes/dfs_order.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Segunda busca}
    @title.anchor = west

text => Node
    @text.x = 7
    @text.y = 6.5
    @text.text = \bbtext{\bbbold{Passo \#1:} reverta a ordem da DFS}


node1 => Node
    @node1.x = 1
    @node1.y = 3
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

node2 => Node
    @node2.x = 4
    @node2.y = 5
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

node3 => Node
    @node3.x = 4
    @node3.y = 1
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

node4 => Node
    @node4.x = 7
    @node4.y = 5
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

node5 => Node
    @node5.x = 7
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node7 => Node
    @node7.x = 10
    @node7.y = 5
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node6 => Node
    @node6.x = 10
    @node6.y = 1
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node8 => Node
    @node8.x = 13
    @node8.y = 3
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

order => Node
    @order.x = 7
    @order.y = 5.75
    @order.text = $O = \{\ 7, 8, 6, 5, 4, 3, 2, 1\ \}$

---
    @order.text = $O = \{\ 1, 2, 3, 4, 5, 6, 8, 7\ \}$

---
    @text.text = \bbtext{\bbbold{Passo \#2:} reverta as arestas do grafo}

---
    @e12.from = node2
    @e12.to = node1

    @e13.from = node3
    @e13.to = node1

    @e23.from = node3
    @e23.to = node2

    @e24.from = node4
    @e24.to = node2

    @e32.from = node2
    @e32.to = node3

    @e34.from = node4
    @e34.to = node3

    @e42.from = node2
    @e42.to = node4

    @e45.from = node5
    @e45.to = node4

    @e47.from = node7
    @e47.to = node4

    @e56.from = node6
    @e56.to = node5

    @e67.from = node7
    @e67.to = node6

    @e68.from = node8
    @e68.to = node6

    @e74.from = node4
    @e74.to = node7

    @e75.from = node5
    @e75.to = node7

    @e87.from = node7
    @e87.to = node8

--- 
    @text.text = \bbtext{\bbbold{Passo \#3:} identifique os componentes}

---
    @order.text = $O = \{\ \mathbf{1}, 2, 3, 4, 5, 6, 8, 7\ \}$

---
    @node1.fill = BBCyan

---
    @order.text = $O = \{\ 1, \mathbf{2}, 3, 4, 5, 6, 8, 7\ \}$

---
    @node2.fill = BBGreen

---
    @node3.fill = BBGreen

---
    @order.text = $O = \{\ 1, 2, 3, \mathbf{4}, 5, 6, 8, 7\ \}$

---
    @node4.fill = BBViolet

---
    @order.text = $O = \{\ 1, 2, 3, 4, \mathbf{5}, 6, 8, 7\ \}$

---
    @node5.fill = BBOrange

---
    @node7.fill = BBOrange

---
    @node8.fill = BBOrange

---
    @node6.fill = BBOrange

## Frame

\inputsnippet{cpp}{45}{65}{codes/kosaraju.cpp}

## Frame

\inputsnippet{cpp}{33}{43}{codes/kosaraju.cpp}


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

