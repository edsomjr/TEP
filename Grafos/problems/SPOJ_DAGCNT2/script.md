## Frame
\bbcover{SPOJ DAGCNT2}{Counting in a DAG}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{You are given a weighted DAG. For each vertex, calculate the sum of the weights of the vertices within its reach (including itself).}

## Text

\bbtext{A você é dado um DAG ponderado. Para cada vértice, compute a soma dos pesos dos vértices que são atingíveis a partir deste vértice (inclusive o próprio vértice).}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The first line contains an integer $T$, denoting the number of test cases.}

\vspace{0.1in}

\bbenglish{For each test case, the first line contains two positive integers $n$ and $m$, denoting the number of vertices and the number of edges in the DAG.}

\vspace{0.1in}

\bbenglish{The second line contains $n$ positive integers $w_1, \ldots, w_n$, denoting the weights of vertices.}

\vspace{0.1in}

\bbenglish{The next $m$ lines contain two positive integers $u, v$, denoting an edge from $u$ to $v$.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{For each test case, print a line consisting of $n$ numbers, denoting the sum for each vertex.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A primeira linha contém um inteiro $T$, o qual indica o número de casos de teste.}

\vspace{0.1in}

\bbtext{A primeira linha de um caso de teste contém dois inteiros positivos $n$ e $m$, representando o número de vértices e o número de arestas no DAG.} 

\vspace{0.1in}

\bbtext{A segunda linha contém $n$ inteiros positivos $w_1, \ldots, w_n$, que representam os pesos dos vértices.}

\vspace{0.1in}

\bbtext{As próximas $m$ linhas contém dois inteiros positivos $u, v$, indicando uma aresta de $u$ a $v$.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Para cada caso de teste imprima uma linha contendo $n$ números, que correspondem à soma para cada vértice.}

## Text

\bbbold{Constraints}

\vspace{0.2in}

\bbenglish{Input Set 1: $T \leq 40, n \leq 100, m \leq 10000$}

\vspace{0.1in}

\bbenglish{Input Set 2: $T \leq 2, n \leq 1000, m \leq 500000$}

\vspace{0.1in}

\bbenglish{Input Set 3: $T \leq 2, n \leq 20000, m \leq 500000$}

\vspace{0.1in}

\bbenglish{The weights are no more than $1000$.}

## Text

\bbbold{Restrições}

\vspace{0.2in}

\bbtext{Conjunto de entradas 1: $T \leq 40, n \leq 100, m \leq 10000$}

\vspace{0.1in}

\bbtext{Conjunto de entradas 2: $T \leq 2, n \leq 1000, m \leq 500000$}

\vspace{0.1in}

\bbtext{Conjunto de entradas 3: $T \leq 2, n \leq 20000, m \leq 500000$}

\vspace{0.1in}

\bbtext{Os pesos não são maiores do que $1000$.}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{4 3} }
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

    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{\# de arestas}
    @arrow.x = 1.65
    @arrow.u = 1.65

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
    @node2.x = 10
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 13
    @node3.y = 4
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle

node4 => Node
    @node4.x = 10
    @node4.y = 1
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{510 713 383 990}}
    @line2.anchor = west

+r
    @r.x = 1.45
    @r.y = 4.0
    @r.text = \footnotesize \bbcomment{$w_1$}

+arrow
    @arrow.x = 1.45
    @arrow.y = 4.25
    @arrow.u = 1.45
    @arrow.v = 5.25

---
    @r.x = 2.25
    @r.text = \footnotesize \bbcomment{$w_2$}

    @arrow.x = 2.25
    @arrow.u = 2.25

---
    @r.x = 3.05
    @r.text = \footnotesize \bbcomment{$w_3$}

    @arrow.x = 3.05
    @arrow.u = 3.05

---
    @r.x = 3.85
    @r.text = \footnotesize \bbcomment{$w_4$}

    @arrow.x = 3.85
    @arrow.u = 3.85

---
-r
-arrow

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{4 1} }
    @line3.anchor = west

---
+r
    @r.x = 1.25
    @r.y = 3.5
    @r.text = \footnotesize \bbcomment{$u$}

+arrow
    @arrow.x = 1.25
    @arrow.y = 3.75
    @arrow.u = 1.25
    @arrow.v = 4.75

---

    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{$v$}

    @arrow.x = 1.65
    @arrow.u = 1.65

---

e41 => Edge
    @e41.from = node4
    @e41.to = node1
    &e41.thick
    &e41.-latex

---
-r
-arrow

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{4 2} }
    @line4.anchor = west

---

e42 => Edge
    @e42.from = node4
    @e42.to = node2
    &e42.thick
    &e42.-latex
---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{2 1} }
    @line5.anchor = west

---

e21 => Edge
    @e21.from = node2
    @e21.to = node1
    &e21.thick
    &e21.-latex

---
    @node1.fill = BBCyan

---
    @node1.fill = BBWhite
    @node2.fill = BBCyan

---
    @node1.fill = BBGreen
    @e21.color = BBCyan

---
    @node1.fill = BBWhite
    @node2.fill = BBWhite
    @node3.fill = BBCyan
    @e21.color = BBBlack

---
    @node3.fill = BBWhite
    @node4.fill = BBCyan

---
    @e42.color = BBCyan
    @node2.fill = BBGreen

---
    @e41.color = BBCyan
    @node1.fill = BBGreen

---
    @e41.color = BBBlack
    @e42.color = BBBlack
    @node1.fill = BBWhite
    @node2.fill = BBWhite
    @node4.fill = BBWhite

+r
    @r.x = 0.5
    @r.y = 2.5
    @r.text = \footnotesize \bboutput{510 1223 383 2213}
    @r.anchor = west

+arrow
    @arrow.x = 1.45
    @arrow.y = 3.75
    @arrow.u = 1.45
    @arrow.v = 2.75
    @arrow.color = BBBlack
    &arrow.very thick
    &arrow.-latex

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Solução}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{Uma travessia pode determinar o alcance do vértice $u$ e determinar a}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5
    @a1.text = \bbtext{soma desejada}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $\star$ \bbtext{Seriam $N$ travessias, cada uma realizada em $O(N + M)$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $\star$ \bbtext{A complexidade desta solução é $O(N^2 + NM)$}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbbold{Veredito:} \bbtext{TLE!}
    @d.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Contudo, com as devidas otimizações, é possível obter um veredito AC}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.5
    @a1.text = \bbtext{com uma solução com complexidade $O(N^2 + NM)$}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{A primeira providência é utilizar I/O eficiente (\texttt{printf()/scanf()})}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Devido a natureza do problema, não é possível utilizar uma DP que use}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3
    @c1.text = \bbtext{as somas como estado do problema}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbtext{Isto porque, se um vértice $u$ atingir $v$ por mais de um caminho, o peso de}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 1.5
    @d1.text = \bbtext{$v$ seria totalizado mais de uma vez}
    @d1.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Seja $R[u]$ o conjunto do vértices alcancáveis a partir de $u$}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Se o grau de saída de $u$ é igual a zero, então $R[u] = \{\ u\ \}$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{Caso contrário, se os estados forem computados na ordem inversa da}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.5
    @c1.text = \bbtext{ordenação topológica, então}
    @c1.anchor = west

c2 => Node
    @c2.x = 7
    @c2.y = 2.5
    @c2.text = $\displaystyle R[u] = \{\ u\ \} \cup \{\ R[v_1]\cup R[v_2]\cup \ldots, R[v_k]\ \}, \ \ \ \forall (u, v_i)\in E$

---

d => Node
    @d.x = 1
    @d.y = 1.5
    @d.text = $\star$ \bbtext{Dadas as restrições de tempo, $R[u]$ deve ser representado por um \bbenglish{bitset}}
    @d.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Além disso, a implementação deste \bbenglish{bitset} deve ser customizada}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Se os elementos são representados em $R[u]$ por seus índices na ordenação}
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.5
    @b1.text = \bbtext{topológica, a união pode ser feita de forma mais eficiente}
    @b1.anchor = west


---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Isto porque todo vértice $v$ alcancável a partir do vértice $u$ o sucederá na}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.0
    @c1.text = \bbtext{ordenação topológica}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbtext{Assim, ao contrário do \bbenglish{bitset} do C++, é possível unir $R[u]$ e $R[v_i]$ somente}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 1.5
    @d1.text = \bbtext{ até o índice de $u$ na ordenação topológica}
    @d1.anchor = west


## Frame

\inputsnippet{cpp}{46}{65}{codes/DAGCNT2.cpp}

## Frame

\inputsnippet{cpp}{41}{44}{codes/DAGCNT2.cpp}


## End
