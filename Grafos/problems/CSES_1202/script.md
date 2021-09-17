## Frame
\bbcover{CSES 1202}{Investigation}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{You are going to travel from Syrjälä to Lehmälä by plane. You would like to find answers to the following questions:}

\vspace{0.2in}

\begin{itemize}
    \item \bbenglish{what is the minimum price of such a route?}
    \item \bbenglish{how many minimum-price routes are there? (modulo $10^9+7$)}
    \item \bbenglish{what is the minimum number of flights in a minimum-price route?}
    \item \bbenglish{what is the maximum number of flights in a minimum-price route?}
\end{itemize}

## Text

\bbtext{Você irá viajar de Syrjälä para Lehmälä de avião. Você gostaria de encontrar respostas para as seguintes questões:}

\vspace{0.2in}

\begin{itemize}
    \item \bbtext{qual é o preço mínimo de tal rota?}
    \item \bbtext{existem quantas rotas de preço mínimo? (módulo $10^9+7$)}
    \item \bbtext{qual é o número mínimo de voôs em uma rota de preço mínimo?}
    \item \bbtext{qual é o número máximo de voôs em uma rota de preço mínimo?}
\end{itemize}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The first input line contains two integers $n$ and $m$: the number of cities and the number of flights. The cities are numbered $1, 2, \ldots, n$. City $1$ is Syrjälä, and city $n$ is Lehmälä.}

\vspace{0.1in}

\bbenglish{After this, there are $m$ lines describing the flights. Each line has three integers $a, b,$ and $c$: there is a flight from city $a$ to city $b$ with price $c$. All flights are one-way flights.}

\vspace{0.1in}

\bbenglish{You may assume that there is a route from Syrjälä to Lehmälä.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A primeira linha da entrada contém dois inteiros $n$ e $m$: o número de cidades e o número de vôos. As cidades são numeradas $1, 2, \ldots, n$. A cidade $1$ é Syrjälä e a cidade $n$ é Lehmälä.}

\vspace{0.1in}

\bbtext{Após isto, há $m$ linhas descrevendo os vôos. Cada linha tem três inteiros $a, b,$ e $c$: há um vôo da cidade $a$ para a cidade $b$ com preço $c$. Todos vôos são dados em sentido único.}

\vspace{0.1in}

\bbtext{Você pode assumir que existe uma rota de Syrjälä para Lehmälä.}

## Text

\bbbold{Output}

\vspace{0.1in}

\bbenglish{Print four integers according to the problem statement.}

\vspace{0.2in}

\bbbold{Constraints}

\vspace{0.1in}

\begin{itemize}
    \item $1\leq n\leq 10^5$
    \item $1\leq m\leq 2\times 10^5$
    \item $1\leq a, b\leq n$
    \item $1\leq c\leq 10^9$
\end{itemize}

## Text

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Imprima quatro inteiros, de acordo com o texto do problema.}

\vspace{0.2in}

\bbbold{Restrições}

\vspace{0.1in}

\begin{itemize}
    \item $1\leq n\leq 10^5$
    \item $1\leq m\leq 2\times 10^5$
    \item $1\leq a, b\leq n$
    \item $1\leq c\leq 10^9$
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
    @line1.text = \bbtext{\texttt{4 5} }
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
    @r.text = \footnotesize \bbcomment{\# de cidades}

---

    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{\# de vôos}
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
    @line2.text = \bbtext{\texttt{1 4 5}}
    @line2.anchor = west

---
+r
    @r.x = 1.25
    @r.y = 4
    @r.text = \footnotesize \bbcomment{$a$}

+arrow
    @arrow.x = 1.25
    @arrow.y = 4.25
    @arrow.u = 1.25
    @arrow.v = 5.25

---

    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{$b$}

    @arrow.x = 1.65
    @arrow.u = 1.65

---

    @r.x = 2.05
    @r.text = \footnotesize \bbcomment{$c$}

    @arrow.x = 2.05
    @arrow.u = 2.05

---
-r
-arrow

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    &e14.-latex
    %e14.label = node[below left] { \bbinfo{5} }

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{1 2 4} }
    @line3.anchor = west

---
e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex
    %e12.label = node[above left] { \bbinfo{4} }

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{2 4 5} }
    @line4.anchor = west

---
e24 => Edge
    @e24.from = node2
    @e24.to = node4
    &e24.thick
    &e24.-latex
    %e24.label = node[left, pos=0.7] { \bbinfo{5} }

---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{1 3 2} }
    @line5.anchor = west

---
e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    &e13.-latex
    %e13.label = node[above,pos=0.7] { \bbinfo{2} }

---

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{3 4 3} }
    @line6.anchor = west

---
e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    &e34.-latex
    %e34.label = node[below right] { \bbinfo{3} }

---
    @node1.fill = BBGreen

---
    @node4.fill = BBCyan

---
    @e14.color = BBCyan
    &e14.dashed

---
    @e13.color = BBGreen
    &e13.dashed

    @e34.color = BBGreen
    &e34.dashed

---
+r
    @r.x = 1.65
    @r.y = 2.0
    @r.text = \footnotesize \bboutput{5 2 1 2}

+arrow
    @arrow.x = 1.65
    @arrow.y = 3.25
    @arrow.u = 1.65
    @arrow.v = 2.25
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
    @a.text = $\star$ \bbtext{Os quatro subproblemas apresentados podem ser divididos em dois grupos:}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5
    @a1.text = \bbtext{o problema de distância mínima e os outros três}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $\star$ \bbtext{O algoritmo de Dijkstra resolve o problema das distâncias mínimas}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $\star$ \bbtext{Além disso, ele gera dois subprodutos úteis para os demais problemas:}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 2.5
    @c1.text = \bbtext{uma ordenação de vértices $O$ e um subgrafo $G'(V, E')$ de $G(V, E)$}
    @c1.anchor = west


---

d => Node
    @d.x = 1
    @d.y = 1.5
    @d.text = $\star$ \bbtext{A aresta $(v, u)\in E'$ se $(u,v)\in E$ finaliza um  caminho mínimo de $1$ a $v$}
    @d.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7.5
    @title.text = \Large \bbbold{Solução}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 6.5
    @a.text = $\star$ \bbtext{A partir de $G'$ os três outros subproblemas podem ser resolvidos por DP}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5.5
    @b.text = $\star$ \bbtext{Os casos base são: $\mathrm{minPaths}[1] = 1$ e $\mathrm{minEdges}[1] = \mathrm{maxEdges}[1] = 0$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4.5
    @c.text = $\star$ \bbtext{As transições são dadas por:}
    @c.anchor = west

---

d => Node
    @d.x = 7
    @d.y = 3.5
    @d.text = $\displaystyle \mathrm{minPaths}[u] = \sum_{(v, u)\in E'} \mathrm{minPaths}[v]$

---

d1 => Node
    @d1.x = 7
    @d1.y = 2.25
    @d1.text = $\displaystyle \mathrm{minEdges}[u] = \min_{(v, u)\in E'}\{\ \mathrm{minEdges[u]}, \mathrm{minEdges}[v] + 1 \ \}$

---

d2 => Node
    @d2.x = 7
    @d2.y = 1
    @d2.text = $\displaystyle \mathrm{maxEdges}[u] = \max_{(v, u)\in E'}\{\ \mathrm{maxEdges[u]}, \mathrm{maxEdges}[v] + 1 \ \}$

## Frame

\inputsnippet{cpp}{73}{79}{codes/1202.cpp}

## Frame

\inputsnippet{cpp}{14}{33}{codes/1202.cpp}

## Frame

\inputsnippet{cpp}{35}{51}{codes/1202.cpp}

## Frame

\inputsnippet{cpp}{53}{70}{codes/1202.cpp}

## End
