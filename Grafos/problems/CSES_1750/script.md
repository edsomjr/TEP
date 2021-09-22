## Frame
\bbcover{CSES 1750}{Planets Queries I}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{You are playing a game consisting of $n$ planets. Each planet has a teleporter to another planet (or the planet itself).}

\vspace{0.1in}

\bbenglish{Your task is to process $q$ queries of the form: when you begin on planet $x$ and travel through $k$ teleporters, which planet will you reach?}

## Text

\bbtext{Você está jogando um jogo composto de $n$ planetas. Cada planeta tem um teletransporte para outro planeta (ou para si mesmo).}

\vspace{0.1in}

\bbtext{Sua tarefa é processar $q$ consultas da seguinte forma: partindo do planeta $x$ e viajando por $k$ teletransportes, você chegará em qual planeta?}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The first input line has two integers $n$ and $q$: the number of planets and queries. The planets are numbered $1, 2, \ldots, n$.}

\vspace{0.1in}

\bbenglish{The second line has $n$ integers $t_1, t_2, \ldots, t_n$: for each planet, the destination of the teleporter. It is possible that $t_i = i$.}

\vspace{0.1in}

\bbenglish{Finally, there are $q$ lines describing the queries. Each line has two integers $x$ and $k$: you start on planet $x$ and travel through $k$ teleporters.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{Print the answer to each query.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A primeira linha da entrada tem dois inteiros $n$ e $q$: o número de planetas e consultas. Os planetas são numerados $1, 2, \ldots, n$.}

\vspace{0.1in}

\bbtext{A segunda linha contém $n$ inteiros $t_1, t_2, \ldots, t_n$: para cada planeta, o destino do teletransporte. É possível que $t_i = i$.}

\vspace{0.1in}

\bbtext{Finalmente, há $q$ linhas descrevendo as consultas. Cada linha tem dois inteiros $x$ e $k$: você inicia no planeta $x$ e viaja através de $k$ teletransportes.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Imprima a resposta para cada consulta.}

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
    @r.text = \footnotesize \bbcomment{\# de planetas}

---
-r
-arrow

node1 => Node
    @node1.x = 6
    @node1.y = 4
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle

node2 => Node
    @node2.x = 8
    @node2.y = 4
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 10
    @node3.y = 4
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle

node4 => Node
    @node4.x = 12
    @node4.y = 4
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle

---
+arrow
    @arrow.x = 1.65
    @arrow.u = 1.65

+r
    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{\# de consultas}

---
-arrow
-r

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{2 1 1 4} }
    @line2.anchor = west

---
+arrow
    @arrow.x = 1.25
    @arrow.y = 4.50
    @arrow.u = 1.25
    @arrow.v = 5.25

+r
    @r.x = 1.25
    @r.y = 4.25
    @r.text = $t_1$

---

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex

---
    @r.x = 1.65
    @r.text = $t_2$

    @arrow.x = 1.65
    @arrow.u = 1.65

---

e21 => Edge
    @e21.from = node2
    @e21.to = node1
    &e21.thick
    &e21.-latex
    %e21.label = [bend right]

---
    @r.x = 2.05
    @r.text = $t_3$

    @arrow.x = 2.05
    @arrow.u = 2.05

---

e31 => Edge
    @e31.from = node3
    @e31.to = node1
    &e31.thick
    &e31.-latex
    %e31.label = [bend left]

---
    @r.x = 2.45
    @r.text = $t_4$

    @arrow.x = 2.45
    @arrow.u = 2.45

---

e44 => Edge
    @e44.from = node4
    @e44.to = node4
    &e44.thick
    &e44.-latex
    %e44.label = [loop right]

---

-arrow
-r

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{1 2} }
    @line3.anchor = west

---
+arrow
    @arrow.x = 1.25
    @arrow.y = 4.00
    @arrow.u = 1.25
    @arrow.v = 4.75

+r
    @r.x = 1.25
    @r.y = 3.75
    @r.text = $x$

---
    @node1.fill = BBGreen

---
    @arrow.x = 1.65
    @arrow.u = 1.65

    @r.x = 1.65
    @r.text = $k$

---
-r
-arrow

    @node2.fill = BBOrange

---
    @node2.fill = BBWhite
    @node1.fill = BBCyan

---
+r
    @r.x = 3
    @r.y = 5
    @r.text = \footnotesize \bboutput{1}
    @r.anchor = west

+arrow
    @arrow.x = 2
    @arrow.y = 5
    @arrow.u = 3
    @arrow.v = 5
    @arrow.color = BBBlack
    &arrow.thick
    &arrow.-latex

---

-r
-arrow

    @node1.fill = BBWhite

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{3 4} }
    @line4.anchor = west

---
    @node3.fill = BBGreen

---
    @node1.fill = BBOrange
---
    @node1.fill = BBWhite
    @node2.fill = BBOrange
---
    @node2.fill = BBWhite
    @node1.fill = BBOrange
---
    @node1.fill = BBWhite
    @node2.fill = BBCyan

---
+r
    @r.y = 4.5
    @r.text = \footnotesize \bboutput{2}

+arrow
    @arrow.y = 4.5
    @arrow.v = 4.5

---
-r
-arrow

    @node2.fill = BBWhite
    @node3.fill = BBWhite

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{4 1} }
    @line5.anchor = west

---
    @node4.fill = BBGreen
---
    @node4.fill = BBCyan

---

+r
    @r.y = 4
    @r.text = \footnotesize \bboutput{4}

+arrow
    @arrow.y = 4
    @arrow.v = 4

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
    @a.text = $\star$ \bbtext{Computar cada consulta em $O(k)$ leva a um veredito TLE}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Contudo, é possível responder as consultas em $O(\log k)$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Para isso, é preciso pré-computar $\mathrm{succ}(u, k)$ para as potências $2^i$ tais que}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3
    @c1.text = \bbtext{$2^i\leq k$, com $i\geq 0$, em $O(n\log k)$}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbtext{Esta solução tem complexidade $O((n + k)\log k)$}
    @d.anchor = west

## Frame

\inputsnippet{cpp}{30}{40}{codes/1750.cpp}

## Frame

\inputsnippet{cpp}{11}{28}{codes/1750.cpp}

## End
