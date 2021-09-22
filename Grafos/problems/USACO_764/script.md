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

\bbenglish{A shuffle is described with $N$ numbers, $a_1\ldots a_N$, where a cow in position $i$ moves to position $a_i$ during the shuffle (and so, each $a_i$ is in the range $1\ldots N$). Every cow moves to its new location during the shuffle. Unfortunately, all the $a_i$'s are not necessarily distinct, so multiple cows might try to move to the same position during a shuffle, after which they will move together for all remaining shuffles.}

\vspace{0.1in}

\bbenglish{Farmer John notices that some positions in his lineup contain cows in them no matter how many shuffles take place. Please help him count the number of such positions.}

## Text

\bbtext{Uma mistura é descrita por $N$ números, $a_1\ldots a_N$, onde a vaca que ocupa a posição $i$ se move para a posição $a_i$ durante a mistura (e assim por diante, cada $a_i$ está no intervalo $1\ldots N$). Cada vaca se move para sua nova localização durante a mistura. Infelizmente, os $a_i$'s não são necessariamente distintos, de modo que múltiplas vacas podem tentar se move para a mesma posição durante a mistura, e após isso elas deve se mover juntas durante todas as misturas restantes.}

\vspace{0.1in}

\bbtext{O fazendeiro John notou que algumas posições na linha sempre tinham vacas sobre elas independentemente do número de misturas feitas. Por favor o ajude a contar o número de tais posições.}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The first line of input contains $N$, the number of cows. The next line contains the $N$ integers $a_1\ldots a_N$.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{Please output the number of positions that will always contain cows, no matter how many shuffles take place.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A primeira linha da entrada contém $N$, o número de vacas. A próxima linha contém os $N$ inteiros $a_1\ldots a_N$.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Por favor imprima o número de posições que sempre terão vacas, independentemente de quantas misturas sejam feitas.}

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
    @r.text = \footnotesize \bbcomment{\# de vacas}

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

cow1 => Node
    @cow1.x = 6
    @cow1.y = 5
    @cow1.text = \includegraphics[scale=0.05]{figs/cow.png}

cow2 => Node
    @cow2.x = 8
    @cow2.y = 5
    @cow2.text = \includegraphics[scale=0.05]{figs/cow.png}

cow3 => Node
    @cow3.x = 10
    @cow3.y = 5
    @cow3.text = \includegraphics[scale=0.05]{figs/cow.png}

cow4 => Node
    @cow4.x = 12
    @cow4.y = 5
    @cow4.text = \includegraphics[scale=0.05]{figs/cow.png}

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{3 2 1 3} }
    @line2.anchor = west

---

+r
    @r.x = 1.25
    @r.y = 4.0
    @r.text = \footnotesize \bbcomment{$a_1$}

+arrow
    @arrow.x = 1.25
    @arrow.y = 4.25
    @arrow.u = 1.25
    @arrow.v = 5.25

---

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    &e13.-latex
    %e13.label = [bend right]

---

    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{$a_2$}

    @arrow.x = 1.65
    @arrow.u = 1.65

---

e22 => Edge
    @e22.from = node2
    @e22.to = node2
    &e22.thick
    &e22.-latex
    %e22.label = [loop left]


---
    @r.x = 2.05
    @r.text = \footnotesize \bbcomment{$a_3$}

    @arrow.x = 2.05
    @arrow.u = 2.05

---
    &e13.latex-latex

---
    @r.x = 2.45
    @r.text = \footnotesize \bbcomment{$a_4$}

    @arrow.x = 2.45
    @arrow.u = 2.45

---

e43 => Edge
    @e43.from = node4
    @e43.to = node3
    &e43.thick
    &e43.-latex

---
-r
-arrow

---

info => Node
    @info.x = 9
    @info.y = 2
    @info.text = \bbbold{Mistura \#1}

---
    @cow4.x = 10
    @cow4.y = 5.75

---
    @info.text = \bbbold{Mistura \#2}
---
    @cow4.x = 6

---
+r
    @r.x = 1.85
    @r.y = 4
    @r.text = \footnotesize \bboutput{3}

+arrow
    @arrow.x = 1.85
    @arrow.y = 5.25
    @arrow.u = 1.85
    @arrow.v = 4.25
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
    @a.x = 7
    @a.y = 6
    @a.text = \bbtext{No problema, as posições são os vértices e as movimentações as arestas}

b => Node
    @b.x = 7
    @b.y = 5.25
    @b.text = \bbtext{de um grafo $G$}

---
-b
    @a.text = \bbtext{Este grafo $G$ é um grafo de sucessores}

---
+b
    @a.text = \bbtext{Assim, ele tem um mais um componentes, onde cada componente tem um ciclo}
    @b.text = \bbtext{e um ou mais caminhos que levam a este ciclo}

---

a1 => Node
    @a1.x = 0.8
    @a1.y = 2
    &a1.draw
    &a1.circle
    &a1.thick

a2 => Node
    @a2.x = 2.4
    @a2.y = 4
    &a2.draw
    &a2.circle
    &a2.thick

a3 => Node
    @a3.x = 4
    @a3.y = 2
    &a3.draw
    &a3.circle
    &a3.thick

a4 => Node
    @a4.x = 3.2
    @a4.y = 0
    &a4.draw
    &a4.circle
    &a4.thick

a5 => Node
    @a5.x = 1.6
    @a5.y = 0
    &a5.draw
    &a5.circle
    &a5.thick

a12 => Edge
    @a12.from = a1
    @a12.to = a2
    &a12.-latex
    &a12.thick
    
a23 => Edge
    @a23.from = a2
    @a23.to = a3
    &a23.-latex
    &a23.thick
 
a34 => Edge
    @a34.from = a3
    @a34.to = a4
    &a34.-latex
    &a34.thick
 
a45 => Edge
    @a45.from = a4
    @a45.to = a5
    &a45.-latex
    &a45.thick
 
a51 => Edge
    @a51.from = a5
    @a51.to = a1
    &a51.-latex
    &a51.thick
 
---

b1 => Node
    @b1.x = 5.5
    @b1.y = 3
    &b1.draw
    &b1.circle
    &b1.thick

b2 => Node
    @b2.x = 6.5
    @b2.y = 3
    &b2.draw
    &b2.circle
    &b2.thick

b3 => Node
    @b3.x = 7.5
    @b3.y = 3
    &b3.draw
    &b3.circle
    &b3.thick

b4 => Node
    @b4.x = 8.5
    @b4.y = 3
    &b4.draw
    &b4.circle
    &b4.thick

b12 => Edge
    @b12.from = b1
    @b12.to = b2
    &b12.-latex
    &b12.thick
 
b23 => Edge
    @b23.from = b2
    @b23.to = b3
    &b23.-latex
    &b23.thick

b34 => Edge
    @b34.from = b3
    @b34.to = b4
    &b34.-latex
    &b34.thick

b43 => Edge
    @b43.from = b4
    @b43.to = b3
    &b43.-latex
    &b43.thick
    %b43.label = [bend right]
 
---

c1 => Node
    @c1.x = 9.8
    @c1.y = 1.6
    &c1.draw
    &c1.circle
    &c1.thick

c2 => Node
    @c2.x = 10.6
    @c2.y = 2.8
    &c2.draw
    &c2.circle
    &c2.thick

c3 => Node
    @c3.x = 11.4
    @c3.y = 4
    &c3.draw
    &c3.circle
    &c3.thick

c4 => Node
    @c4.x = 12.2
    @c4.y = 2.8
    &c4.draw
    &c4.circle
    &c4.thick

c5 => Node
    @c5.x = 12.2
    @c5.y = 1.6
    &c5.draw
    &c5.circle
    &c5.thick

c6 => Node
    @c6.x = 11.4
    @c6.y = 0.4
    &c6.draw
    &c6.circle
    &c6.thick

c7 => Node
    @c7.x = 13
    @c7.y = 0.4
    &c7.draw
    &c7.circle
    &c7.thick

c12 => Edge
    @c12.from = c1
    @c12.to = c2
    &c12.-latex
    &c12.thick
 
c23 => Edge
    @c23.from = c2
    @c23.to = c3
    &c23.-latex
    &c23.thick

c34 => Edge
    @c34.from = c3
    @c34.to = c4
    &c34.-latex
    &c34.thick

c42 => Edge
    @c42.from = c4
    @c42.to = c2
    &c42.-latex
    &c42.thick

c54 => Edge
    @c54.from = c5
    @c54.to = c4
    &c54.-latex
    &c54.thick

c65 => Edge
    @c65.from = c6
    @c65.to = c5
    &c65.-latex
    &c65.thick

c75 => Edge
    @c75.from = c7
    @c75.to = c5
    &c75.-latex
    &c75.thick
 
---
-b
    @a.text = \bbtext{As vacas convergem, a cada mistura, para os ciclos}

---
    @a1.fill = BBCyan
    @a2.fill = BBCyan
    @a3.fill = BBCyan
    @a4.fill = BBCyan
    @a5.fill = BBCyan

---
    @b3.fill = BBGreen
    @b4.fill = BBGreen

---
    @c2.fill = BBOrange
    @c3.fill = BBOrange
    @c4.fill = BBOrange

---
    @a.text = \bbtext{Assim, a solução é a soma dos comprimentos destes ciclos}


## Frame

\inputsnippet{cpp}{11}{30}{codes/764.cpp}

## Frame

\inputsnippet{cpp}{32}{51}{codes/764.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Créditos}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = \bbtext{Cow icon made by surang from \bbenglish{www.flaticon.com}. }
    @a.anchor = west

## End
