## Frame
\bbcover{AIZU GRL 5A}{Diameter of a Tree}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{Given a tree $T$ with non-negative weight, find the diameter of the tree.}

\vspace{0.1in}

\bbenglish{The diameter of a tree is the maximum distance between two nodes in a tree.}

## Text

\bbtext{Dada uma árvore $T$ com pesos não-negativos, encontre o diâmetro desta árvore.}

\vspace{0.1in}

\bbtext{O diâmetro de uma árvore é a distância máxima entre dois vértices de uma árvore.}

## Text

\bbbold{Input}

$$
\begin{array}{lll}
n \\
s_1 & t_1 & w_1 \\
s_2 & t_2 & w_2 \\
\ldots \\
s_{n-1} & t_{n-1} & w_{n-1} \\
\end{array}
$$
\vspace{0.1in}

\bbenglish{The first line consists of an integer $n$ which represents the number of nodes in the tree. Every node has a unique ID from $0$ to $n-1$ respectively.}

\vspace{0.1in}

\bbenglish{In the following $n-1$ lines, edges of the tree are given. $s_i$ and $t_i$ represent end-points of the $i$-th edge (undirected) and $w_i$ represents the weight (distance) of the $i$-th edge.}

## Text

\bbbold{Entrada}

$$
\begin{array}{lll}
n \\
s_1 & t_1 & w_1 \\
s_2 & t_2 & w_2 \\
\ldots \\
s_{n-1} & t_{n-1} & w_{n-1} \\
\end{array}
$$
\vspace{0.1in}

\bbtext{A primeira linha consiste em um inteiro $n$, o qual representa o número de nós na árvore. Cada nó tem um identificador único entre $0$ e $n-1$, respectivamente.}

\vspace{0.1in}

\bbtext{Nas próximas $n-1$ linhas são dadas as arestas da árvore. $s_i$ e $t_i$ representam os pontos terminais da $i$-ésima aresta (não-direcionada) e $w_i$ representa o peso (distância) da $i$-ésima aresta.}

## Text

\bbbold{Output}

\vspace{0.1in}

\bbenglish{Print the diameter of the tree in a line.}

\vspace{0.3in}

\bbbold{Constraints}

\vspace{0.1in}

\begin{itemize}
    \item $1\leq n\leq 100,000$
    \item $0\leq w_i\leq 1,000$
\end{itemize}

## Text

\bbbold{Saída}

\vspace{0.1in}

\bbenglish{Imprima, em uma linha, o diâmetro da árvore.}

\vspace{0.3in}

\bbbold{Restrições}

\vspace{0.1in}

\begin{itemize}
    \item $1\leq n\leq 100,000$
    \item $0\leq w_i\leq 1,000$
\end{itemize}


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
    @r.text = \footnotesize \bbcomment{\# de nós}

---
-r
-arrow

node0 => Node
    @node0.x = 7
    @node0.y = 4
    @node0.text = \bbtext{0}
    &node0.draw
    &node0.very thick
    &node0.circle

node1 => Node
    @node1.x = 10
    @node1.y = 7
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle

node2 => Node
    @node2.x = 13
    @node2.y = 4
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 10
    @node3.y = 1
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle


---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{0 1 2} }
    @line2.anchor = west

---
+r
    @r.y = 4
    @r.text = \bbcomment{$u$}

+arrow
    @arrow.y = 4.25
    @arrow.v = 5.25

---
    @r.x = 1.65
    @r.text = \bbcomment{$v$}

    @arrow.x = 1.65
    @arrow.u = 1.65

---
    @r.x = 2.05
    @r.text = \bbcomment{$w$}

    @arrow.x = 2.05
    @arrow.u = 2.05

---

-r
-arrow

e01 => Edge
    @e01.from = node0
    @e01.to = node1
    &e01.very thick
    %e01.label = node[above left] { \bbinfo{2} }

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{1 2 1} }
    @line3.anchor = west

---

e21 => Edge
    @e21.from = node2
    @e21.to = node1
    &e21.very thick
    %e21.label = node[above right] { \bbinfo{1} }


---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{1 3 3} }
    @line4.anchor = west

---

e31 => Edge
    @e31.from = node3
    @e31.to = node1
    &e31.very thick
    %e31.label = node[right] { \bbinfo{3} }

---
    @e31.color = BBCyan
    &e31.dashed
    @e01.color = BBCyan
    &e01.dashed

---
+r
    @r.x = 1.65
    @r.y = 3
    @r.text = \bbinfo{2 + 3 = 5}

+arrow
    @arrow.x = 1.65
    @arrow.y = 4.25
    @arrow.u = 1.65
    @arrow.v = 3.25
    @arrow.color = BBBlack
    &arrow.thick
    &arrow.-latex

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
    @r.text = \footnotesize \bbcomment{\# de nós}

-r
-arrow

---

node0 => Node
    @node0.x = 7
    @node0.y = 4
    @node0.text = \bbtext{0}
    &node0.draw
    &node0.very thick
    &node0.circle

node1 => Node
    @node1.x = 10
    @node1.y = 7
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle

node2 => Node
    @node2.x = 13
    @node2.y = 4
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 10
    @node3.y = 1
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle


---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{0 1 1} }
    @line2.anchor = west

---

e01 => Edge
    @e01.from = node0
    @e01.to = node1
    &e01.very thick
    %e01.label = node[above left] { \bbinfo{1} }

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{1 2 2} }
    @line3.anchor = west

---

e21 => Edge
    @e21.from = node2
    @e21.to = node1
    &e21.very thick
    %e21.label = node[above right] { \bbinfo{2} }


---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{2 3 4} }
    @line4.anchor = west

---

e32 => Edge
    @e32.from = node3
    @e32.to = node2
    &e32.very thick
    %e32.label = node[below right] { \bbinfo{4} }

---
    @e32.color = BBCyan
    &e32.dashed
    @e01.color = BBCyan
    &e01.dashed
    @e21.color = BBCyan
    &e21.dashed

---
+r
    @r.x = 1.65
    @r.y = 3
    @r.text = \bbinfo{1 + 2 + 4 = 7}

+arrow
    @arrow.x = 1.65
    @arrow.y = 4.25
    @arrow.u = 1.65
    @arrow.v = 3.25
    @arrow.color = BBBlack
    &arrow.thick
    &arrow.-latex

## Scene

header => Node
    @header.x = 0
    @header.y = 6
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 5
    @line1.text = $\star$ \bbtext{O diâmetro também pode ser computado por meio de duas DFS}
    @line1.anchor = west

---

line11 => Node
    @line11.x = 1
    @line11.y = 4
    @line11.text = $\star$ \bbtext{Isto porque, em árvores, todos caminhos mínimos são únicos}
    @line11.anchor = west

---

line2 => Node
    @line2.x = 1
    @line2.y = 3
    @line2.text = $\star$ \bbtext{A DFS encurta o código}
    @line2.anchor = west

---

line3 => Node
    @line3.x = 1
    @line3.y = 2
    @line3.text = $\star$ \bbtext{A função \texttt{max\_element()} do C++ retorna um iterador para o elemento}
    @line3.anchor = west

line31 => Node
    @line31.x = 0.5
    @line31.y = 1.5
    @line31.text = \bbtext{máximo no intervalo passado como parâmetro}
    @line31.anchor = west

## Frame

\inputsnippet{cpp}{10}{20}{codes/GRL_5_A.cpp}

## Frame

\inputsnippet{cpp}{22}{35}{codes/GRL_5_A.cpp}

## End
