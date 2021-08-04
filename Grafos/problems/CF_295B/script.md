## Frame
\bbcover{Codeforces Round \#179 (Div. 1)}{Problem B -- Greg and Graph}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{Greg has a weighed directed graph, consisting of $n$ vertices. In this graph any pair of distinct vertices has an edge between them in both directions. Greg loves playing with the graph and now he has invented a new game:}

\begin{itemize}
    \item \bbenglish{The game consists of $n$ steps.}
    \item \bbenglish{On the $i$-th step Greg removes vertex number $x_i$ from the graph. As Greg removes a vertex, he also removes all the edges that go in and out of this vertex.}
    \item \bbenglish{Before executing each step, Greg wants to know the sum of lengths of the shortest paths between all pairs of the remaining vertices. The shortest path can go through any remaining vertex. In other words, if we assume that $d(i, v, u)$ is the shortest path between vertices $v$ and  $u$ in the graph that formed before deleting vertex $x_i$, then Greg wants to know the value of the following sum:} $\sum_{v,u,v\neq u} d(i, v, u)$

\end{itemize}

\vspace{0.1in}

\bbenglish{Help Greg, print the value of the required sum before each step.}

## Text

\bbtext{Greg tem um grafo ponderado, composto por $n$ vértices. Neste grafo qualquer par de vértices distintos tem uma arestas entre eles em ambas direções. Greg ama brincar com o grafo e agora ele inventou um novo jogo:}

\begin{itemize}
    \item \bbtext{O jogo é composto de $n$ etapas.}
    \item \bbtext{Na $i$-ésima etapa Greg remove o vértice $x_i$ do grafo. Quando Greg remove um vértice, ele também remove todas as arestas que chegam ou partem deste vértice.}
    \item \bbtext{Antes de cada etapa, Greg quer saber a soma dos custos dos caminhos mínimos entre todos os pares de vértices restantes. O caminho mais curto pode passar por qualquer vértice restante. Em outras palavras, se $d(i, v, u)$  é o custo do caminho mínimo entre os vértices $v$ e  $u$ no grafo antes da exclusão do vértice $x_i$, então Greg quer saber o valor da seguinte soma:} $\sum_{v,u,v\neq u} d(i, v, u)$

\end{itemize}

\vspace{0.1in}

\bbtext{Help Greg, print the value of the required sum before each step.}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The first line contains integer $n$ $(1\leq n\leq 500)$ -- the number of vertices in the graph.}

\vspace{0.1in}

\bbenglish{Next $n$ lines contain $n$ integers each -- the graph adjacency matrix: the $j$-th number in the $i$-th line $a_{ij}$ $(1\leq a_{ij}\leq 10^5, a_{ii} = 0)$ represents the weight of the edge that goes from vertex $i$ to vertex $j$.}

\vspace{0.1in}

\bbenglish{The next line contains $n$ distinct integers: $x_1, x_2, \ldots, x_n$ $(1\leq x_i\leq n)$ -- the vertices that Greg deletes.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{Print $n$ integers -- the $i$-th number equals the required sum before the $i$-th step.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A primeira linha contém o inteiro $n$ $(1\leq n\leq 500)$ -- o número de vértices no grafo.}

\vspace{0.1in}

\bbtext{As próximas $n$ linhas contém $n$ inteiros cada -- a matriz de adjacências do grafo: o $j$-ésimo número na $i$-ésima linha $a_{ij}$ $(1\leq a_{ij}\leq 10^5, a_{ii} = 0)$ representa o peso da aresta que vai do vértice $i$ ao vértice $j$.}

\vspace{0.1in}

\bbtext{A próxima linha contém $n$ inteiros distintos: $x_1, x_2, \ldots, x_n$ $(1\leq x_i\leq n)$ -- os vértices que Greg apagará.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Imprima $n$ inteiros -- o $i$-ésimo número corresponde à soma requerida antes da $i$-ésima etapa.}


## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{2} }
    @line1.anchor = west

---

arrow => Edge
    &arrow.->
    @arrow.x = 1.25
    @arrow.y = 5.00
    @arrow.u = 1.25
    @arrow.v = 5.75
    @arrow.color = BBViolet

r => Node
    @r.x = 1.25
    @r.y = 4.75
    @r.text = \footnotesize \bbcomment{\# de vértices}

---
-r
-arrow

node1 => Node
    @node1.x = 7
    @node1.y = 4
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle

node2 => Node
    @node2.x = 12
    @node2.y = 4
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{0 5} }
    @line2.anchor = west

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{4 0} }
    @line3.anchor = west

---
+r
    @r.x = 1.85
    @r.y = 3.5
    @r.text = \bbcomment{matriz de adjacências}

+arrow
    @arrow.x = 1.45
    @arrow.y = 3.75
    @arrow.u = 1.45
    @arrow.v = 4.75

---
-r
-arrow

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.very thick
    &e12.-latex
    %e12.label = [bend left] node[above] { \bbinfo{5} }

e21 => Edge
    @e21.from = node2
    @e21.to = node1
    &e21.very thick
    &e21.-latex
    %e21.label = [bend left] node[above] { \bbinfo{4} }

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{1 2} }
    @line4.anchor = west

---

+r
    @r.y = 3.0
    @r.text = \bbcomment{vértices excluídos}

+arrow
    @arrow.y = 3.25
    @arrow.v = 4.25

---
-r
-arrow

eq => Node
    @eq.x = 7
    @eq.y = 1.5
    @eq.text = $\displaystyle \sum_{u, v, u\neq v} d(1, u, v) = d(1, 1, 2) + d(1, 2, 1) = 5 + 4 = 9$

---
-eq

    @node1.fill = BBRed

---

-node1
-e12
-e21

---
+eq
    @eq.text = $\displaystyle \sum_{u, v, u\neq v} d(2, u, v) = 0$

---
-eq
+arrow
+r

    @r.x = 1.45
    @r.text = \bbinfo{9 0}

    @arrow.color = BBBlack
    &arrow.very thick
    &arrow.latex-

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{4} }
    @line1.anchor = west

---

node1 => Node
    @node1.x = 5
    @node1.y = 4
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle

node2 => Node
    @node2.x = 6.5
    @node2.y = 6
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 8
    @node3.y = 4
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle

node4 => Node
    @node4.x = 6.5
    @node4.y = 2
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{0 3 1 1} }
    @line2.anchor = west

line3 => Node
    @line3.x = 1
    @line3.y = 5
    @line3.text = \bbtext{\texttt{6 0 400 1} }
    @line3.anchor = west

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{2 4 0 1} }
    @line4.anchor = west

line5 => Node
    @line5.x = 1
    @line5.y = 4
    @line5.text = \bbtext{\texttt{1 1 1 0} }
    @line5.anchor = west

--- 

grid => Grid
    @grid.x = 10
    @grid.y = 2
    @grid.u = 14
    @grid.v = 6
    &grid.thick

c1 => Node
    @c1.x = 9.5
    @c1.y = 5.5
    @c1.text = \bbtext{1}

c2 => Node
    @c2.x = 9.5
    @c2.y = 4.5
    @c2.text = \bbtext{2}

c3 => Node
    @c3.x = 9.5
    @c3.y = 3.5
    @c3.text = \bbtext{3}

c4 => Node
    @c4.x = 9.5
    @c4.y = 2.5
    @c4.text = \bbtext{4}

r1 => Node
    @r1.x = 10.5
    @r1.y = 6.5
    @r1.text = \bbtext{1}

r2 => Node
    @r2.x = 11.5
    @r2.y = 6.5
    @r2.text = \bbtext{2}

r3 => Node
    @r3.x = 12.5
    @r3.y = 6.5
    @r3.text = \bbtext{3}

r4 => Node
    @r4.x = 13.5
    @r4.y = 6.5
    @r4.text = \bbtext{4}

a11 => Node
    @a11.x = 10.5
    @a11.y = 5.5
    @a11.text = \footnotesize $0$

a12 => Node
    @a12.x = 11.5
    @a12.y = 5.5
    @a12.text = \footnotesize $3$

a13 => Node
    @a13.x = 12.5
    @a13.y = 5.5
    @a13.text = \footnotesize $1$

a14 => Node
    @a14.x = 13.5
    @a14.y = 5.5
    @a14.text = \footnotesize $1$

a21 => Node
    @a21.x = 10.5
    @a21.y = 4.5
    @a21.text = \footnotesize $6$

a22 => Node
    @a22.x = 11.5
    @a22.y = 4.5
    @a22.text = \footnotesize $0$

a23 => Node
    @a23.x = 12.5
    @a23.y = 4.5
    @a23.text = \footnotesize $400$

a24 => Node
    @a24.x = 13.5
    @a24.y = 4.5
    @a24.text = \footnotesize $1$

a31 => Node
    @a31.x = 10.5
    @a31.y = 3.5
    @a31.text = \footnotesize $2$

a32 => Node
    @a32.x = 11.5
    @a32.y = 3.5
    @a32.text = \footnotesize $4$

a33 => Node
    @a33.x = 12.5
    @a33.y = 3.5
    @a33.text = \footnotesize $0$

a34 => Node
    @a34.x = 13.5
    @a34.y = 3.5
    @a34.text = \footnotesize $1$

a41 => Node
    @a41.x = 10.5
    @a41.y = 2.5
    @a41.text = \footnotesize $1$

a42 => Node
    @a42.x = 11.5
    @a42.y = 2.5
    @a42.text = \footnotesize $1$

a43 => Node
    @a43.x = 12.5
    @a43.y = 2.5
    @a43.text = \footnotesize $1$

a44 => Node
    @a44.x = 13.5
    @a44.y = 2.5
    @a44.text = \footnotesize $0$

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.-latex
    %e12.label = [bend left] node[above,pos=0.9] { \scriptsize \bbinfo{3} }
    &e12.thick

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.-latex
    %e13.label = [bend right] node[below,pos=0.9] { \scriptsize \bbinfo{1} }
    &e13.thick

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.-latex
    %e14.label = node[left,pos=0.9] { \scriptsize \bbinfo{1} }
    &e14.thick

e21 => Edge
    @e21.from = node2
    @e21.to = node1
    &e21.-latex
    %e21.label = node[above,pos=0.9] { \scriptsize \bbinfo{6} }
    &e21.thick

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.-latex
    %e23.label = [bend left] node[right,pos=0.9] { \scriptsize \bbinfo{400} }
    &e23.thick

e24 => Edge
    @e24.from = node2
    @e24.to = node4
    &e24.-latex
    %e24.label = [bend left] node[left,pos=0.9] { \scriptsize \bbinfo{1} }
    &e24.thick

e31 => Edge
    @e31.from = node3
    @e31.to = node1
    &e31.-latex
    %e31.label = [bend right] node[below,pos=0.9] { \scriptsize \bbinfo{2} }
    &e31.thick

e32 => Edge
    @e32.from = node3
    @e32.to = node2
    &e32.-latex
    %e32.label = node[right,pos=0.9] { \scriptsize \bbinfo{4} }
    &e32.thick

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.-latex
    %e34.label = node[right,pos=0.9] { \scriptsize \bbinfo{1} }
    &e34.thick

e41 => Edge
    @e41.from = node4
    @e41.to = node1
    &e41.-latex
    %e41.label = [bend left] node[left,pos=0.9] { \scriptsize \bbinfo{1} }
    &e41.thick

e42 => Edge
    @e42.from = node4
    @e42.to = node2
    &e42.-latex
    %e42.label = node[left,pos=0.9] { \scriptsize \bbinfo{1} }
    &e42.thick

e43 => Edge
    @e43.from = node4
    @e43.to = node3
    &e43.-latex
    %e43.label = [bend right] node[right,pos=0.9] { \scriptsize \bbinfo{1} }
    &e43.thick


---

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{4 1 2 3} }
    @line6.anchor = west

---

    @a12.text = \footnotesize $\mathbf{2}$
    @a21.text = \footnotesize $\mathbf{2}$
    @a23.text = \footnotesize $\mathbf{2}$
    @a32.text = \footnotesize $\mathbf{2}$

---

eq => Node
    @eq.x = 10
    @eq.y = 1
    @eq.text = $\displaystyle \sum_{u, v, u\neq v} d(1, u, v) = 17$
    @eq.anchor = west

---

-eq
    @a12.text = \footnotesize ${2}$
    @a21.text = \footnotesize ${2}$
    @a23.text = \footnotesize ${2}$
    @a32.text = \footnotesize ${2}$

    @node4.fill = BBRed

---

-node4
-e41
-e42
-e43
-e14
-e24
-e34

---

    @a14.text = \footnotesize $\infty$
    @a24.text = \footnotesize $\infty$
    @a34.text = \footnotesize $\infty$
    @a44.text = \footnotesize $\infty$
    @a41.text = \footnotesize $\infty$
    @a42.text = \footnotesize $\infty$
    @a43.text = \footnotesize $\infty$
    @a12.text = \footnotesize $\mathbf{3}$
    @a21.text = \footnotesize $\mathbf{6}$
    @a23.text = \footnotesize $\mathbf{7}$
    @a32.text = \footnotesize $\mathbf{4}$

---

+eq

    @eq.text = $\displaystyle \sum_{u, v, u\neq v} d(2, u, v) = 23$

---

-eq

    @a12.text = \footnotesize ${3}$
    @a21.text = \footnotesize ${6}$
    @a23.text = \footnotesize ${7}$
    @a32.text = \footnotesize ${4}$

    @node1.fill = BBRed

---

-node1
-e12
-e13
-e21
-e31

---
    @a11.text = \footnotesize $\infty$
    @a12.text = \footnotesize $\infty$
    @a13.text = \footnotesize $\infty$
    @a21.text = \footnotesize $\infty$
    @a31.text = \footnotesize $\infty$
    @a23.text = \footnotesize $\mathbf{400}$

---

+eq

    @eq.text = $\displaystyle \sum_{u, v, u\neq v} d(3, u, v) = 404$

---

-eq

    @a23.text = \footnotesize ${400}$

    @node2.fill = BBRed

---

-node2
-e23
-e32

---

    @a22.text = \footnotesize $\infty$
    @a23.text = \footnotesize $\infty$
    @a32.text = \footnotesize $\infty$

---

+eq

    @eq.text = $\displaystyle \sum_{u, v, u\neq v} d(4, u, v) = 0$

---

arrow => Edge
    &arrow.-latex
    &arrow.very thick
    @arrow.x = 1.85
    @arrow.y = 3.25
    @arrow.u = 1.85
    @arrow.v = 2.25
    @arrow.color = BBBlack

r => Node
    @r.x = 1.85
    @r.y = 2.0
    @r.text = \bbinfo{17 23 404 0} 

## Scene

header => Node
    @header.x = 0
    @header.y = 7
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = $\star$ \bbtext{As arestas de um vértice podem ser removidas da matriz de adjacências}
    @line1.anchor = west

line1a => Node
    @line1a.x = 0.5
    @line1a.y = 5.5
    @line1a.text = \bbtext{em $O(N)$}
    @line1a.anchor = west

---

line2 => Node
    @line2.x = 1
    @line2.y = 4.5
    @line2.text = $\star$ \bbtext{Em cada etapa, os caminhos mínimos entre todos os pares podem ser}
    @line2.anchor = west

line2a => Node
    @line2a.x = 0.5
    @line2a.y = 4.0
    @line2a.text = \bbtext{computados com Floyd-Warshall em $O(N^3)$}
    @line2a.anchor = west

---

line3 => Node
    @line3.x = 1
    @line3.y = 3
    @line3.text = $\star$ \bbtext{Como são $N$ etapas, esta solução tem complexidade $O(N^4)$}
    @line3.anchor = west
---

line4 => Node
    @line4.x = 1
    @line4.y = 2
    @line4.text = $\star$ \bbbold{Veredito}\bbtext{: TLE!}
    @line4.anchor = west

## Scene

header => Node
    @header.x = 0
    @header.y = 7
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = $\star$ \bbtext{Para reduzir a complexidade, é preciso compreender o funcionamento do}
    @line1.anchor = west

line1a => Node
    @line1a.x = 0.5
    @line1a.y = 5.5
    @line1a.text = \bbtext{algoritmo de Floyd-Warshall}
    @line1a.anchor = west

---

line2 => Node
    @line2.x = 1
    @line2.y = 4.5
    @line2.text = $\star$ \bbtext{A cada iteração, as distâncias são relaxadas usando o vértice $k$ como}
    @line2.anchor = west

line2a => Node
    @line2a.x = 0.5
    @line2a.y = 4.0
    @line2a.text = \bbtext{intermediário}
    @line2a.anchor = west

---

line3 => Node
    @line3.x = 1
    @line3.y = 3
    @line3.text = $\star$ \bbtext{Assim, basta começar com o grafo vazio e, a cada etapa, em ordem reversa,}
    @line3.anchor = west

line3a => Node
    @line3a.x = 0.5
    @line3a.y = 2.5
    @line3a.text = \bbtext{adicionar o vértice $x_i$ e suas arestas a $G$, e relaxar as distâncias usando $x_i$}
    @line3a.anchor = west

---

line4 => Node
    @line4.x = 1
    @line4.y = 1.5
    @line4.text = $\star$ \bbbold{Complexidade}\bbtext{: $O(N^3)$}
    @line4.anchor = west


## Frame

\inputsnippet{cpp}{11}{28}{codes/295B.cpp}

## Frame

\inputsnippet{cpp}{30}{42}{codes/295B.cpp}

## End
