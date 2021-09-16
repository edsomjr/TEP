## Frame
\bbcover{OJ 10308}{Roads in the North}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{Building and maintaining roads among communities in the far North is an expensive business. With this in mind, the roads are built in such a way that there is only one route from a village to a village that does not pass through some other village twice.}

\vspace{0.1in}

\bbenglish{Given is an area in the far North comprising a number of villages and roads among them such that any village can be reached by road from any other village. Your job is to find the road distance between the two most remote villages in the area.}

\vspace{0.1in}

\bbenglish{The area has up to $10,000$ villages connected by road segments. The villages are numbered from $1$.}

## Text

\bbtext{Construir e manter estradas entre comunidades no Norte é um negócio caro. Com isto em mente, as estradas foram construídas de tal modo que há uma única rota entre uma vila e outra e que não passa por uma mesma vila duas vezes.} 

\vspace{0.1in}

\bbtext{É dada uma área no Norte composta por um certo número de vilas e estradas que as conectam, de modo que pode-se chegar a qualquer vila a partir de qualquer vila. Seu trabalho é encontrar a distância da rota entre as duas vilas mais remotas desta área.} 

\vspace{0.1in}

\bbtext{A área tem no máximo $10.000$ vilas conectadas por estradas. As vilas são numeradas a partir de $1$.}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The input contains several sets of input. Each set of input is a sequence of lines, each containing three positive integers: the number of a village, the number of a different village, and the length of the road segment connecting the villages in kilometers. All road segments are two-way. Two consecutive sets are separated by a blank line.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{For each set of input, you are to output a single line containing a single integer: the road distance between the two most remote villages in the area.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A entrada é composta por vários casos de teste. Cada caso de teste é formado por uma sequência de linhas, cada uma contendo três inteiros positivos: o número de uma vila, o número de uma vila diferente e o comprimento da estrada que conecta estas duas vilas, em kilômetros. Todas as estradas são bidirecionais. Dois casos de teste consecutivos são separados por uma linha em branco.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Para cada caso de teste, você deve imprimr uma única linha contendo um único inteiro: a distância da rota entre as duas vilas mais remotas da área.}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{5 1 6} }
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
    @r.text = \footnotesize \bbcomment{vila A}

---
    @arrow.x = 1.65
    @arrow.u = 1.65

    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{vila B}

---
    @arrow.x = 2.05
    @arrow.u = 2.05

    @r.x = 2.05
    @r.text = \footnotesize \bbcomment{distância entre A e B}

---

-r
-arrow

node1 => Node
    @node1.x = 7
    @node1.y = 5
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
    @node3.y = 5
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle

node4 => Node
    @node4.x = 13
    @node4.y = 3
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle

node5 => Node
    @node5.x = 10
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle

node6 => Node
    @node6.x = 7
    @node6.y = 3
    @node6.text = \bbtext{6}
    &node6.draw
    &node6.very thick
    &node6.circle

-node2
-node3
-node4
-node6

e51 => Edge
    @e51.from = node5
    @e51.to = node1
    &e51.thick
    %e51.label = node[above right,pos=0.2] { \bbinfo{6} }

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{1 4 5} }
    @line2.anchor = west

---

+node4

e41 => Edge
    @e41.from = node4
    @e41.to = node1
    &e41.thick
    %e41.label = node[above right,pos=0.7] { \bbinfo{5} }


---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{6 3 9} }
    @line3.anchor = west

---
+node3
+node6

e63 => Edge
    @e63.from = node6
    @e63.to = node3
    &e63.thick
    %e63.label = node[above right,pos=0.7] { \bbinfo{9} }

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{2 6 8} }
    @line4.anchor = west

---
+node2

e62 => Edge
    @e62.from = node6
    @e62.to = node2
    &e62.thick
    %e62.label = node[above left,pos=0.7] { \bbinfo{8} }

---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{6 1 7} }
    @line5.anchor = west

---

e61 => Edge
    @e61.from = node6
    @e61.to = node1
    &e61.thick
    %e61.label = node[left] { \bbinfo{7} }

---

    @e51.color = BBCyan
    &e51.dashed

    @e61.color = BBCyan
    &e61.dashed

    @e63.color = BBCyan
    &e63.dashed

---
+r
+arrow

    @r.x = 1.65
    @r.y = 2.5
    @r.text = \bboutput{6 + 7 + 9 = 22}

    @arrow.x = 1.65
    @arrow.y = 2.75
    @arrow.u = 1.65
    @arrow.v = 3.75
    @arrow.color = BBBlack
    &arrow.very thick
    &arrow.-latex

## Scene

header => Node
    @header.x = 0
    @header.y = 6
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $\star$ \bbtext{As vilas mais remotas são as mais distantes entre si}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $\star$ \bbtext{Neste problema, as vilas são os vértices e as estradas são arestas}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $\star$ \bbtext{As características dadas no texto tornam o grafo uma árvore}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbbold{Atenção:} \bbtext{Como o grafo é ponderado, o último vértice visitado na BFS}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 1.5
    @d1.text = \bbtext{não é, necessariamente, o mais distante da origem}
    @d1.anchor = west

## Frame

\inputsnippet{cpp}{9}{28}{codes/10308.cpp}

## Frame

\inputsnippet{cpp}{30}{43}{codes/10308.cpp}

## End
