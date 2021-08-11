## Frame
\bbcover{Grafos}{Árvores: Travessias}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{DFS em árvores}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{A estrutura das árvores simplifica a implementação da DFS}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Por conta da ausência de ciclos, a DFS em árvores dispensa o registro dos}
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.5
    @b1.text = \bbtext{vértices já visitados}
    @b1.anchor = west


---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Este registro é substituído por um parâmetro extra, com o vértice $p$ que }
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.0
    @c1.text = \bbtext{antecedeu $u$ na travessia}
    @c1.anchor = west


---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbtext{A complexidade de memória se reduz de $O(V)$ para $O(1)$}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1
    @e.text = $\star$ \bbtext{Na primeira chamada, $p = 0$ (ou algum sentinela apropriado)}
    @e.anchor = west


## Frame

\inputcode{cpp}{codes/dfs.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Números de nós na subárvore}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{A DFS, em conjunto com técnicas de programação dinâmica, permite}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.5
    @a1.text = \bbtext{computar em $O(N)$ algumas características da árvore}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Um exemplo seria o número de nós $\mathrm{nodes}[u]$ da subárvore cuja raiz é $u$}
    @b.anchor = west


---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Se $u$ é folha, então $\mathrm{nodes}[u] = 1$}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{Caso contrário,} 
    @d.anchor = west

d1 => Node
    @d1.x = 7
    @d1.y = 1.5
    @d1.text = $\displaystyle \mathrm{nodes}[u] = 1 + \sum_{v \in \mathrm{adj}[u]} \mathrm{nodes}[v]$

## Scene

node4 => Node
    @node4.x = 7
    @node4.y = 7
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle
 
node7 => Node
    @node7.x = 3
    @node7.y = 5
    @node7.text = \bbtext{7}
    &node7.draw
    &node7.very thick
    &node7.circle
 
node2 => Node
    @node2.x = 7
    @node2.y = 5
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle
 
node5 => Node
    @node5.x = 11
    @node5.y = 5
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle
 
node1 => Node
    @node1.x = 1
    @node1.y = 3
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle
 
node3 => Node
    @node3.x = 5
    @node3.y = 3
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle
 
node6 => Node
    @node6.x = 11
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
    @text.text = $\mathrm{nodes}[u] = $

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
    @n4.text = $\mathbf{1}$

---
    @node4.fill = BBGray
    @node7.fill = BBGreen
    @n7.text = $\mathbf{1}$
    @n4.text = ${1}$

---
    @node7.fill = BBGray
    @node1.fill = BBCyan
    @n1.text = $\mathbf{1}$
    @n7.text = ${1}$

---
    @node7.fill = BBGreen
    @n7.text = $\mathbf{2}$
    @n1.text = ${1}$

---
    @node7.fill = BBGray
    @node3.fill = BBCyan
    @n3.text = $\mathbf{1}$
    @n7.text = ${2}$

---
    @node7.fill = BBCyan
    @n7.text = $\mathbf{3}$
    @n3.text = ${1}$

---
    @node4.fill = BBGreen
    @n4.text = $\mathbf{4}$
    @n7.text = ${3}$

---
    @node4.fill = BBGray
    @node2.fill = BBCyan
    @n2.text = $\mathbf{1}$
    @n4.text = ${4}$

---
    @node4.fill = BBGreen
    @n2.text = ${1}$
    @n4.text = $\mathbf{5}$

---
    @node4.fill = BBGray
    @node5.fill = BBGreen
    @n4.text = ${5}$
    @n5.text = $\mathbf{1}$

---
    @node5.fill = BBGray
    @node6.fill = BBCyan
    @n5.text = ${1}$
    @n6.text = $\mathbf{1}$

---
    @node5.fill = BBCyan
    @n6.text = ${1}$
    @n5.text = $\mathbf{2}$

---
    @node4.fill = BBCyan
    @n5.text = ${2}$
    @n4.text = $\mathbf{7}$

---
    @n4.text = ${7}$

### Frame

\inputsnippet{cpp}{9}{28}{codes/nodes.cpp}

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

## Frame

\inputsnippet{cpp}{9}{28}{codes/to_leaf.cpp}

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
    @b.text = $2.$ \bbtext{Codeforces Round \#250 (Div. 2) -- Problem C: The Child and Toy}
    @b.anchor = west

c => Node
    @c.x = 0.25
    @c.y = 3
    @c.text = $3.$ \bbtext{Codeforces Tound \#660 (Div. 2) -- Problem C: Uncle Bogdan and Country Happiness}
    @c.anchor = west

d => Node
    @d.x = 0.25
    @d.y = 2
    @d.text = $4.$ \bbtext{OJ 548 -- Tree}
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
