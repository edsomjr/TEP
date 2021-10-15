## Frame
\bbcover{Grafos}{Ordenação Topológica}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.0
    @title.text = \Large \bbbold{Ordenação topológica}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.0
    @a.text = \bbtext{Seja $G(V, E)$ um grafo direcionado com $N$ vértices. Uma ordenação }
    @a.anchor = west

b => Node
    @b.x = 0.5
    @b.y = 4.25
    @b.text = \bbtext{$O = \{\ v_{i_1}, v_{i_2}, \ldots, v_{i_N}\ \}$ dos vértices de $G$ é uma \bbbold{ordenação topológica} se}
    @b.anchor = west

c => Node
    @c.x = 0.5
    @c.y = 3.5
    @c.text = \bbtext{vale a seguinte afirmação: para quaisquer pares de vértices $u, v \in V$, se }
    @c.anchor = west

d => Node
    @d.x = 0.5
    @d.y = 2.75
    @d.text = \bbtext{existe um caminho de $u$ a $v$, então $u$ antecede $v$ na ordenação $O$.}
    @d.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Características da ordenação topológica}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Grafos que possuem ciclos não possuem ordenações topológicas}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Um grafo direcionado acíclico (DAG) contém, no mínimo, uma ordenação }
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.5
    @b1.text = \bbtext{topológica}
    @b1.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Ordenações topológicas estabelecem relações de prioridade: se a tarefa $A$}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.0
    @c1.text = \bbtext{é pré-requisito da tarefa $B$, então $A < B$ na ordenação}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.0
    @d.text = $\star$ \bbtext{O algoritmo de Tarjan determina uma ordenação topológica em um DAG}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1.0
    @e.text = $\star$ \bbtext{O algoritmo de Kahn também identifica uma ordenação topológica }
    @e.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Proponente do algoritmo de Tarjan}
    @title.anchor = west

tarjan => Node
    @tarjan.x = 7
    @tarjan.y = 4
    @tarjan.text = \includegraphics[scale=0.12]{figs/tarjan.jpg}

tname => Node
    @tname.x = 7
    @tname.y = 1
    @tname.text = \bbbold{Robert Endre Tarjan}

tdate => Node
    @tdate.x = 7
    @tdate.y = 0.5
    @tdate.text = \bbtext{(1976)}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Características do algoritmo de Tarjan}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{O algoritmo de Tarjan determina uma ordenação topológica em um DAG}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.5
    @a1.text = \bbtext{por meio de uma DFS modificada}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{A ideia central é que, na árvore induzida pela DFS, as folhas devem aparecer}
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4
    @b1.text = \bbtext{após os nós intermediários na ordenação topológica}
    @b1.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.0
    @c.text = $\star$ \bbtext{Durante a travessia, cada vértice assume um dentre três estados: não}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 2.5
    @c1.text = \bbtext{encontrado (branco), encontrado (verde) e processado (azul)}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 1.5
    @d.text = $\star$ \bbtext{Quando um vértice se torna processado, ele deve entrar no início da fila}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 1.0
    @d1.text = \bbtext{que conterá a ordenação topológica}
    @d1.anchor = west

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
    @input.text = \bbemph{Entrada:} \bbtext{um grafo direcionado acíclico $G(V, E)$}
    @input.anchor = west

output => Node
    @output.x = 0.5
    @output.y = 5.5
    @output.text = \bbemph{Saída:} \bbtext{uma ordenação topológica $O$ de $G$}
    @output.anchor = west

---

step1 => Node
    @step1.x = 1.0
    @step1.y = 4.5
    @step1.text = $1.$ \bbtext{Marque todos os vértices $v\in V$ como não encontrados}
    @step1.anchor = west

---

step2 => Node
    @step2.x = 1.0
    @step2.y = 3.5
    @step2.text = $2.$ \bbtext{Enquanto existir ao menos um vértice $u$ não encontrado:}
    @step2.anchor = west

step2a => Node
    @step2a.x = 2.0
    @step2a.y = 3.0
    @step2a.text = $(a)$ \bbtext{Marque $u$ como encontrado}
    @step2a.anchor = west

step2b => Node
    @step2b.x = 2.0
    @step2b.y = 2.5
    @step2b.text = $(b)$ \bbtext{Avalie todos os filhos não encontrados de $u$}
    @step2b.anchor = west

step2c => Node
    @step2c.x = 2.0
    @step2c.y = 2.0
    @step2c.text = $(c)$ \bbtext{Marque $u$ como processado e insira $u$ na frente da fila $O$}
    @step2c.anchor = west

---

step3 => Node
    @step3.x = 2.0
    @step3.y = 1.0
    @step3.text = $3.$ \bbtext{Retorne $O$}

## Scene

node1 => Node
    @node1.x = 2
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
    @node3.y = 2
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
    @node5.x = 6
    @node5.y = 6
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node6 => Node
    @node6.x = 8
    @node6.y = 7
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node7 => Node
    @node7.x = 10
    @node7.y = 4
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node8 => Node
    @node8.x = 10
    @node8.y = 2
    @node8.text = \bbtext{8}
    &node8.very thick
    &node8.draw
    &node8.circle

node9 => Node
    @node9.x = 12
    @node9.y = 4
    @node9.text = \bbtext{9}
    &node9.very thick
    &node9.draw
    &node9.circle


O => Node
    @O.x = 4.5
    @O.y = 0.75
    @O.text = \bbtext{$O = \{\ \}$}
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

---

    @node1.fill = BBGreen

---

    @node3.fill = BBGreen

---

    @node4.fill = BBGreen

---

    @node5.fill = BBGreen

---

    @node6.fill = BBGreen

---

    @node9.fill = BBGreen

---

    @node9.fill = BBCyan
    @O.text = \bbtext{$O = \{$ 9 $\}$}

---

    @node6.fill = BBCyan
    @O.text = \bbtext{$O = \{$ 6, 9 $\}$}

---

    @node5.fill = BBCyan
    @O.text = \bbtext{$O = \{$ 5, 6, 9 $\}$}

---
    @node7.fill = BBGreen

---
    @node8.fill = BBGreen

---

    @node8.fill = BBCyan
    @O.text = \bbtext{$O = \{$ 8, 5, 6, 9 $\}$}
---

    @node7.fill = BBCyan
    @O.text = \bbtext{$O = \{$ 7, 8, 5, 6, 9 $\}$}
---

    @node4.fill = BBCyan
    @O.text = \bbtext{$O = \{$ 4, 7, 8, 5, 6, 9 $\}$}

---

    @node3.fill = BBCyan
    @O.text = \bbtext{$O = \{$ 3, 4, 7, 8, 5, 6, 9 $\}$}

---

    @node1.fill = BBCyan
    @O.text = \bbtext{$O = \{$ 1, 3, 4, 7, 8, 5, 6, 9 $\}$}

---
    @node2.fill = BBGreen

---
    @node2.fill = BBCyan
    @O.text = \bbtext{$O = \{$ 2, 1, 3, 4, 7, 8, 5, 6, 9 $\}$}

## Frame

\inputsnippet{cpp}{31}{43}{codes/tarjan.cpp}

## Frame

\inputsnippet{cpp}{11}{29}{codes/tarjan.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Algoritmo de Kahn}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{O algoritmo de Kahn encontra uma ordenação topológica em um DAG}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Foi proposto por Arthur B. Kahn em 1962}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{A ideia central é que os vértices com grau de entrada menor aparecem}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.0
    @c1.text = \bbtext{antes dos vértices com grau de entrada maior na ordenação topológica}
    @c1.anchor = west


---

d => Node
    @d.x = 1
    @d.y = 2.0
    @d.text = $\star$ \bbtext{Para identificar tais vértices, é utilizada uma BFS modificada}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1.0
    @e.text = $\star$ \bbtext{\bbbold{Complexidade}: $O(E\log V)$ }
    @e.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7.0
    @title.text = \Large \bbbold{Pseudocódigo}
    @title.anchor = west

---

input => Node
    @input.x = 0.5
    @input.y = 6.0
    @input.text = \bbemph{Entrada:} \bbtext{um grafo direcionado acíclico $G(V, E)$}
    @input.anchor = west

output => Node
    @output.x = 0.5
    @output.y = 5.5
    @output.text = \bbemph{Saída:} \bbtext{uma ordenação topológica $O$ de $G$}
    @output.anchor = west

---

step1 => Node
    @step1.x = 1.0
    @step1.y = 4.5
    @step1.text = $1.$ \bbtext{Insira, em uma fila $Q$, todos os vértices com grau de entrada igual a zero}
    @step1.anchor = west

---

step2 => Node
    @step2.x = 1.0
    @step2.y = 3.5
    @step2.text = $2.$ \bbtext{Enquanto $Q$ não estiver vazia:}
    @step2.anchor = west

step2a => Node
    @step2a.x = 2.0
    @step2a.y = 3.0
    @step2a.text = $(a)$ \bbtext{Extraia o primeiro elemento $u$ da fila e o insira em $O$}
    @step2a.anchor = west

step2b => Node
    @step2b.x = 2.0
    @step2b.y = 2.5
    @step2b.text = $(b)$ \bbtext{Exclua $u$ e todas as suas arestas que partem de $u$ do grafo $G$}
    @step2b.anchor = west

step2c => Node
    @step2c.x = 2.0
    @step2c.y = 2.0
    @step2c.text = $(b)$ \bbtext{Insira em $Q$ os vértices com grau de entrada igual a zero}
    @step2c.anchor = west

---

step3 => Node
    @step3.x = 2.0
    @step3.y = 1.0
    @step3.text = $3.$ \bbtext{Retorne $O$}

## Scene

node1 => Node
    @node1.x = 2
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
    @node3.y = 2
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
    @node5.x = 6
    @node5.y = 6
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node6 => Node
    @node6.x = 8
    @node6.y = 7
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node7 => Node
    @node7.x = 10
    @node7.y = 4
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node8 => Node
    @node8.x = 10
    @node8.y = 2
    @node8.text = \bbtext{8}
    &node8.very thick
    &node8.draw
    &node8.circle

node9 => Node
    @node9.x = 12
    @node9.y = 4
    @node9.text = \bbtext{9}
    &node9.very thick
    &node9.draw
    &node9.circle


O => Node
    @O.x = 7
    @O.y = 0.75
    @O.text = \bbtext{$Q = \{\ \},\ \ O = \{\ \}$}

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
---
    @node2.fill = BBGreen
    @O.text = \bbtext{$Q = \{$ 2  $\},\ \ O = \{\ \}$}

---
    @node2.fill = BBCyan
    @O.text = \bbtext{$Q = \{$  $\},\ \ O = \{$ 2 $\}$}

---
-node2
-e21
-e23
-e24
-e25

---
    @node1.fill = BBGreen
    @O.text = \bbtext{$Q = \{$ 1 $\},\ \ O = \{$ 2 $\}$}
    
---
    @node1.fill = BBCyan
    @O.text = \bbtext{$Q = \{$ $\},\ \ O = \{$ 2, 1 $\}$}

---
-node1
-e13

---
    @node3.fill = BBGreen
    @O.text = \bbtext{$Q = \{$ 3 $\},\ \ O = \{$ 2, 1 $\}$}

---
    @node3.fill = BBCyan
    @O.text = \bbtext{$Q = \{$ $\},\ \ O = \{$ 2, 1, 3 $\}$}

---
-node3
-e34
-e38

---
    @node4.fill = BBGreen
    @O.text = \bbtext{$Q = \{$ 4 $\},\ \ O = \{$ 2, 1, 3 $\}$}

---
    @node4.fill = BBCyan
    @O.text = \bbtext{$Q = \{$ $\},\ \ O = \{$ 2, 1, 3, 4 $\}$}

---
-node4
-e45
-e47
-e48
---
    @node5.fill = BBGreen
    @node7.fill = BBGreen

    @O.text = \bbtext{$Q = \{$ 5, 7 $\},\ \ O = \{$ 2, 1, 3, 4 $\}$}

---
    @node5.fill = BBCyan
    @O.text = \bbtext{$Q = \{$ 7 $\},\ \ O = \{$ 2, 1, 3, 4, 5 $\}$}

---
-node5
-e56

---
    @node6.fill = BBGreen
    @O.text = \bbtext{$Q = \{$ 7, 6 $\},\ \ O = \{$ 2, 1, 3, 4, 5 $\}$}

---
    @node7.fill = BBCyan
    @O.text = \bbtext{$Q = \{$ 6 $\},\ \ O = \{$ 2, 1, 3, 4, 5, 7 $\}$}

---
-node7
-e78
-e79

---
    @node8.fill = BBGreen
    @O.text = \bbtext{$Q = \{$ 6, 8 $\},\ \ O = \{$ 2, 1, 3, 4, 5, 7 $\}$}

---
    @node6.fill = BBCyan
    @O.text = \bbtext{$Q = \{$ 8 $\},\ \ O = \{$ 2, 1, 3, 4, 5, 7, 6 $\}$}

---
-node6
-e69

---
    @node8.fill = BBCyan
    @O.text = \bbtext{$Q = \{$ $\},\ \ O = \{$ 2, 1, 3, 4, 5, 7, 6, 8 $\}$}

---
-node8
-e89

---
    @node9.fill = BBGreen
    @O.text = \bbtext{$Q = \{$ 9 $\},\ \ O = \{$ 2, 1, 3, 4, 5, 7, 6, 8 $\}$}

---
    @node9.fill = BBCyan
    @O.text = \bbtext{$Q = \{$ $\},\ \ O = \{$ 2, 1, 3, 4, 5, 7, 6, 8, 9 $\}$}

---
-node9

## Frame

\inputsnippet{cpp}{10}{24}{codes/kahn.cpp}

## Frame

\inputsnippet{cpp}{26}{36}{codes/kahn.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Problemas sugeridos}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $1.$ \bbtext{Codeforces 510C -- Fox and Names}
    @a.anchor = west

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $2.$ \bbtext{OJ 11060 -- Beverages}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $3.$ \bbtext{SPOJ TOPOSORT -- Topological Sorting}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $4.$ \bbtext{Timus 1280 -- Topological Sorting}
    @d.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Referências}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $1.$ \bbtext{\bbbold{ACM Digital Library}. \bbenglish{Topological sorting of large networks}, A. B. Kahn, 1962.}
    @a.anchor = west

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
    @d.text = $4.$ \bbbold{Wikipédia}. \bbenglish{Robert Tarjan,} \bbtext{acesso em 08/09/2021.}
    @d.anchor = west

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $5.$ \bbbold{Wikipédia}. \bbenglish{Topological sorting,} \bbtext{acesso em 08/09/2021.}
    @e.anchor = west

## End

https://codeforces.com/problemset/problem/510/C
https://www.spoj.com/problems/TOPOSORT/
https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2001
https://acm.timus.ru/problem.aspx?space=1&num=1280
