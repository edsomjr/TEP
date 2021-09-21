## Frame
\bbcover{USACO 2017 December Contest}{Silver, Problem 3: The Bovine Shuffle}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{Convinced that happy cows generate more milk, Farmer John has installed a giant disco ball in his barn and plans to teach his cows to dance!}

\vspace{0.1in}

\bbenglish{Looking up popular cow dances, Farmer John decides to teach his cows the ``Bovine Shuffle''. The Bovine Shuffle consists of his $N$ cows $(1\leq N\leq 100,000)$ lining up in a row in some order, then performing successive ``shuffles'', each of which potentially re-orders the cows. To make it easier for his cows to locate themselves, Farmer John marks the locations for his line of cows with positions $1\ldots N$, so the first cow in the lineup will be in position $1$, the next in position $2$, and so on, up to position $N$.}

## Text

\bbtext{Convencido que vacas felizes dão mais leite, o fazendeiro John instalou uma bola de discoteca gigante no celeiro e planeja ensinar suas vacas a dançar!}

\vspace{0.1in}

\bbtext{Procurando por danças bovinas populares, o fazendeiro John decidiu ensinar a suas vacas a ``Misturada Bovina''. A Misturada Bovina consiste em alinhar suas $N$ vacas $(1\leq N\leq 100.000)$ em uma linha, em alguma ordem. Então elas executam sucessivas ``misturas'', cada uma delas potencialmente reordenando as vacas. Para que as vacas possam se localizar com mais facilidade, o fazendeiro John marcou posições na linha com números de $1\ldots N$, de modo que a primeira vaca se alinhe na posição $1$, a próxima na posição $2$, e assim por diante, até a posição $N$.}


## Text

\bbenglish{A shuffle is described with $N$ numbers, $a_1\ldots a_N$, where a cow in position $i$ moves to position $a_i$ during the shuffle (and so, each $a_i$ is in the range $1\leq N$). Every cow moves to its new location during the shuffle. Unfortunately, all the $a_i$'s are not necessarily distinct, so multiple cows might try to move to the same position during a shuffle, after which they will move together for all remaining shuffles.}

\vspace{0.1in}

\bbenglish{Farmer John notices that some positions in his lineup contain cows in them no matter how many shuffles take place. Please help him count the number of such positions.}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The first line of input contains $N$, the number of cows. The next line contains the $N$ integers $a_1\ldots a_N$.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{Please output the number of positions that will always contain cows, no matter how many shuffles take place.}

## End

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{8 9} }
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
    @r.text = \footnotesize \bbcomment{\# de tarefas}

---

    @r.x = 2.5
    @r.text = \footnotesize \bbcomment{\# de relações de dependência}
    @arrow.x = 1.65
    @arrow.u = 1.65

---
-r
-arrow

node1 => Node
    @node1.x = 6
    @node1.y = 5
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle

node2 => Node
    @node2.x = 8
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 10
    @node3.y = 7
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle

node4 => Node
    @node4.x = 12
    @node4.y = 5
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle

node5 => Node
    @node5.x = 12
    @node5.y = 3
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle

node6 => Node
    @node6.x = 10
    @node6.y = 1
    @node6.text = \bbtext{6}
    &node6.draw
    &node6.very thick
    &node6.circle

node7 => Node
    @node7.x = 8
    @node7.y = 1
    @node7.text = \bbtext{7}
    &node7.draw
    &node7.very thick
    &node7.circle

node8 => Node
    @node8.x = 6
    @node8.y = 3
    @node8.text = \bbtext{8}
    &node8.draw
    &node8.very thick
    &node8.circle

node9 => Node
    @node9.x = 6
    @node9.y = 4
    @node9.text = \bbtext{9}
    &node9.draw
    &node9.very thick
    &node9.circle

-node9

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{1 4} }
    @line2.anchor = west

+r
    @r.x = 1.25
    @r.y = 4.0
    @r.text = \footnotesize \bbcomment{$x$}

+arrow
    @arrow.x = 1.25
    @arrow.y = 4.25
    @arrow.u = 1.25
    @arrow.v = 5.25

---
    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{$y$}

    @arrow.x = 1.65
    @arrow.u = 1.65

---
-r
-arrow

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    &e14.-latex

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{1 2} }
    @line3.anchor = west

---

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex

---

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
    @line5.text = \bbtext{\texttt{4 3} }
    @line5.anchor = west

---

e43 => Edge
    @e43.from = node4
    @e43.to = node3
    &e43.thick
    &e43.-latex

---

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{3 2} }
    @line6.anchor = west

---

e32 => Edge
    @e32.from = node3
    @e32.to = node2
    &e32.thick
    &e32.-latex

---

line7 => Node
    @line7.x = 1
    @line7.y = 3.0
    @line7.text = \bbtext{\texttt{5 2} }
    @line7.anchor = west

---

e52 => Edge
    @e52.from = node5
    @e52.to = node2
    &e52.thick
    &e52.-latex

---

line8 => Node
    @line8.x = 1
    @line8.y = 2.5
    @line8.text = \bbtext{\texttt{3 5} }
    @line8.anchor = west

---

e35 => Edge
    @e35.from = node3
    @e35.to = node5
    &e35.thick
    &e35.-latex

---

line9 => Node
    @line9.x = 1
    @line9.y = 2.0
    @line9.text = \bbtext{\texttt{8 2} }
    @line9.anchor = west

---

e82 => Edge
    @e82.from = node8
    @e82.to = node2
    &e82.thick
    &e82.-latex

---

line10 => Node
    @line10.x = 1
    @line10.y = 1.5
    @line10.text = \bbtext{\texttt{8 6} }
    @line10.anchor = west

---

e86 => Edge
    @e86.from = node8
    @e86.to = node6
    &e86.thick
    &e86.-latex

---

    @node1.fill = BBGreen
    @node7.fill = BBGreen
    @node8.fill = BBGreen
    @node9.fill = BBGreen

---
    @node1.fill = BBCyan

---
-node1
-e12
-e14

---
    @node4.fill = BBGreen

---
    @node4.fill = BBCyan

---
-node4
-e42
-e43

---
    @node3.fill = BBGreen

---
    @node3.fill = BBCyan

---
-node3
-e32
-e35

---
    @node5.fill = BBGreen

---
    @node5.fill = BBCyan

---
-node5
-e52

---
    @node7.fill = BBCyan

---
-node7

---
    @node8.fill = BBCyan

---
-node8
-e82
-e86

---
    @node2.fill = BBGreen
    @node6.fill = BBGreen

---
    @node2.fill = BBCyan
---
-node2

---
    @node6.fill = BBCyan
---
-node6

---
+r
    @r.x = 3.5
    @r.y = 2.5
    @r.text = \footnotesize \bboutput{1 4 3 5 7 8 2 6}
    @r.anchor = west

+arrow
    @arrow.x = 2.25
    @arrow.y = 2.5
    @arrow.u = 3.25
    @arrow.v = 2.5
    @arrow.color = BBBlack
    &arrow.very thick
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
    @line1.text = \bbtext{\texttt{2 2} }
    @line1.anchor = west

---

a => Node
    @a.x = 7
    @a.y = 4
    @a.text = \bbtext{1}
    &a.draw
    &a.very thick
    &a.circle

b => Node
    @b.x = 12
    @b.y = 4
    @b.text = \bbtext{2}
    &b.draw
    &b.very thick
    &b.circle

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{1 2} }
    @line2.anchor = west

---

eAB => Edge
    @eAB.from = a
    @eAB.to = b
    &eAB.thick
    &eAB.-latex
    %eAB.label = [bend left]

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{2 1 } }
    @line3.anchor = west

---

eBA => Edge
    @eBA.from = b
    @eBA.to = a
    &eBA.thick
    &eBA.-latex
    %eBA.label = [bend left]

---
r => Node
    @r.x = 1.45
    @r.y = 3.5
    @r.text = \footnotesize \bboutput{Sandro fails.}

arrow => Edge
    @arrow.x = 1.45
    @arrow.y = 4.75
    @arrow.u = 1.45
    @arrow.v = 3.75
    @arrow.color = BBBlack
    &arrow.very thick
    &arrow.-latex
 
## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Sandro será capaz de cumprir suas tarefas apenas se elas puderem ser}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.5
    @a1.text = \bbtext{ordenadas de tal forma que as prioridades sejam respeitadas}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Em outras palavras, há solução apenas se existe uma ordenação topológica}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Se o grafo tem um ou mais ciclos, a resposta é \bboutput{Sandro fails.}}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{O problema pede, na saída, uma ordenação específica}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $\star$ \bbtext{Esta ordenação pode ser obtida se a fila do algoritmo de Kahn for}
    @e.anchor = west

e1 => Node
    @e1.x = 0.5
    @e1.y = 1.0
    @e1.text = \bbtext{substituída por uma \bbenglish{min heap}}
    @e1.anchor = west


## Frame

\inputsnippet{cpp}{11}{29}{codes/764.cpp}

## Frame

\inputsnippet{cpp}{31}{42}{codes/764.cpp}


## End

SAMPLE INPUT:
4
3 2 1 3
SAMPLE OUTPUT:
3
Problem credits: Brian Dean
