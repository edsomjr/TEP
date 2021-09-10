## Frame
\bbcover{Codeforces Round \#516 (Div. 1)}{Problem B -- Labyrinth}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{You are playing some computer game. One of its levels puts you in a maze consisting of $n$ lines, each of which contains $m$ cells. Each cell either is free or is occupied by an obstacle. The starting cell is in the row $r$ and column $c$. In one step you can move one square up, left, down or right, if the target cell is not occupied by an obstacle. You can't move beyond the boundaries of the labyrinth.}

\vspace{0.1in}

\bbenglish{Unfortunately, your keyboard is about to break, so you can move left no more than $x$ times and move right no more than $y$ times. There are no restrictions on the number of moves up and down since the keys used to move up and down are in perfect condition.}

\vspace{0.1in}

\bbenglish{Now you would like to determine for each cell whether there exists a sequence of moves that will put you from the starting cell to this particular one. How many cells of the board have this property?}

## Text

\bbtext{Você está jogando um jogo de computador. Um dos níveis do jogo o coloca em um labirinto composto por $n$ linhas, cada uma delas contendo $m$ celas. Cada cela ou está livre ou está ocupada por um obstáculo. A cela de partida está na linha $r$, coluna $c$. A cada passo você pode se mover um quadrado para cima, esquerda, baixo ou direita, se a cela alvo não estiver ocupada por um obstáculo. Você não pode ser mover além dos limites do labirinto.}

\vspace{0.1in}

\bbtext{Infelizmente, seu teclado está prestes a quebrar, de modo que você pode ser mover para a esquerda no máximo $x$ vezes e se mover para a direita no máximo $y$ vezes. Não há restrição quanto ao número de movimentos para cima ou para baixo, uma vez que as teclas utilizadas para se mover para cima ou para baixo estão em perfeitas condições.}
\vspace{0.1in}

\bbtext{Agora você gostaria de determinar, para cada cela, se existe uma sequência de movimentos que permitem atingir tal cela a partir da cela de partida. Quantas celas do tabuleiro tem esta propriedade?}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The first line contains two integers $n, m$ $(1\leq n, m\leq 2000)$ -- the number of rows and the number columns in the labyrinth respectively.}

\vspace{0.1in}

\bbenglish{The second line contains two integers $r, c$ $(1\leq r\leq n, 1\leq c\leq m)$ -- index of the row and index of the column that define the starting cell.}

\vspace{0.1in}

\bbenglish{The third line contains two integers $x, y$ $(0\leq x, y\leq 10^9)$ -- the maximum allowed number of movements to the left and to the right respectively.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A primeira linha contém dois inteiros $n, m$ $(1\leq n, m\leq 2000)$ -- o número de linhas e o número de colunas no labirinto, respectivamente.}

\vspace{0.1in}

\bbtext{A segunda linha contém dois inteiros $r, c$ $(1\leq r\leq n, 1\leq c\leq m)$ -- os índices da linha e da coluna que definem a cela de partida.}

\vspace{0.1in}

\bbtext{A terceira linha contém dois inteiros $x, y$ $(0\leq x, y\leq 10^9)$ -- o número máximo de movimentos permitidos para a esquerda e para a direita, respectivamente.}

## Text

\bbenglish{The next $n$ lines describe the labyrinth. Each of them has length of $m$ and consists only of symbols `\texttt{.}' and `\texttt{*}'. The $j$-th character of the $i$-th line corresponds to the cell of labyrinth at row $i$ and column $j$. Symbol `\texttt{.}' denotes the free cell, while symbol `\texttt{*}' denotes the cell with an obstacle.}

\vspace{0.1in}

\bbenglish{It is guaranteed, that the starting cell contains no obstacles.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{Print exactly one integer -- the number of cells in the labyrinth, which are reachable from starting cell, including the starting cell itself.}

## Text

\bbtext{As próximas $n$ linhas descrevem o labirinto. Cada uma delas tem tamanho $m$ e são compostas apenas pelos símbolos `\texttt{.}' e `\texttt{*}'. O $j$-ésimo caractere da $i$-ésima linha corresponde a cela do labirinto que ocupa a linha $i$ e a coluna $j$. O símbolo `\texttt{.}' indica uma cela livre, enquanto que o símbolo `\texttt{*}' indica uma cela com um obstáculo.}

\vspace{0.1in}

\bbtext{É garantido que a cela de partida não contém obstáculos.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Imprima um único inteiro -- o número de celas do labirinto que são alcancáveis a partir da cela de partida, inclusive a própria cela de partida.}

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
    @r.text = \footnotesize \bbcomment{\# de linhas}

---
    @arrow.x = 1.65
    @arrow.u = 1.65
 
    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{\# de colunas}

---
-r
-arrow
    
grid => Grid
    @grid.x = 7
    @grid.y = 2
    @grid.u = 12
    @grid.v = 6
    &grid.very thick

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{3 2} }
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
    @r.text = \footnotesize $r$

---

    @arrow.x = 1.65
    @arrow.u = 1.65
 
    @r.x = 1.65
    @r.text = \footnotesize $c$

---

start => Rect
    @start.x = 8
    @start.y = 3
    @start.u = 9
    @start.v = 4
    @start.fill = BBGreen 
    &start.draw
    &start.very thick

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
    @r.text = \footnotesize \bbcomment{mov. para esquerda}

---

    @arrow.x = 1.65
    @arrow.u = 1.65
 
    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{mov. para direita}

---

-arrow
-r

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{.....} }
    @line4.anchor = west

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{.***.} }
    @line5.anchor = west

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{...**} }
    @line6.anchor = west

line7 => Node
    @line7.x = 1
    @line7.y = 3.0
    @line7.text = \bbtext{\texttt{*.... } }
    @line7.anchor = west

---

a22 => Rect
    @a22.x = 8
    @a22.y = 4
    @a22.u = 9
    @a22.v = 5
    @a22.fill = BBBlack
    &a22.draw
    &a22.very thick

a23 => Rect
    @a23.x = 9
    @a23.y = 4
    @a23.u = 10
    @a23.v = 5
    @a23.fill = BBBlack
    &a23.draw
    &a23.very thick

a24 => Rect
    @a24.x = 10
    @a24.y = 4
    @a24.u = 11
    @a24.v = 5
    @a24.fill = BBBlack
    &a24.draw
    &a24.very thick

a34 => Rect
    @a34.x = 10
    @a34.y = 3
    @a34.u = 11
    @a34.v = 4
    @a34.fill = BBBlack
    &a34.draw
    &a34.very thick

a35 => Rect
    @a35.x = 11
    @a35.y = 3
    @a35.u = 12
    @a35.v = 4
    @a35.fill = BBBlack
    &a35.draw
    &a35.very thick

a41 => Rect
    @a41.x = 7
    @a41.y = 2
    @a41.u = 8
    @a41.v = 3
    @a41.fill = BBBlack
    &a41.draw
    &a41.very thick

---

a11 => Rect
    @a11.x = 7
    @a11.y = 5
    @a11.u = 8
    @a11.v = 6
    @a11.fill = BBCyan
    &a11.draw
    &a11.very thick

a12 => Rect
    @a12.x = 8
    @a12.y = 5
    @a12.u = 9
    @a12.v = 6
    @a12.fill = BBCyan
    &a12.draw
    &a12.very thick

a13 => Rect
    @a13.x = 9
    @a13.y = 5
    @a13.u = 10
    @a13.v = 6
    @a13.fill = BBCyan
    &a13.draw
    &a13.very thick

a21 => Rect
    @a21.x = 7
    @a21.y = 4
    @a21.u = 8
    @a21.v = 5
    @a21.fill = BBCyan
    &a21.draw
    &a21.very thick

a31 => Rect
    @a31.x = 7
    @a31.y = 3
    @a31.u = 8
    @a31.v = 4
    @a31.fill = BBCyan
    &a31.draw
    &a31.very thick

a42 => Rect
    @a42.x = 8
    @a42.y = 2
    @a42.u = 9
    @a42.v = 3
    @a42.fill = BBCyan
    &a42.draw
    &a42.very thick

a33 => Rect
    @a33.x = 9
    @a33.y = 3
    @a33.u = 10
    @a33.v = 4
    @a33.fill = BBCyan
    &a33.draw
    &a33.very thick

a43 => Rect
    @a43.x = 9
    @a43.y = 2
    @a43.u = 10
    @a43.v = 3
    @a43.fill = BBCyan
    &a43.draw
    &a43.very thick

a44 => Rect
    @a44.x = 10
    @a44.y = 2
    @a44.u = 11
    @a44.v = 3
    @a44.fill = BBCyan
    &a44.draw
    &a44.very thick

---
+arrow
    @arrow.y = 2.75
    @arrow.v = 2.00
    @arrow.color = BBBlack
    &arrow.very thick
    &arrow.-latex
+r
    @r.y = 1.75
    @r.text = \bbinfo{10}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{4 4} }
    @line1.anchor = west

---

grid => Grid
    @grid.x = 7
    @grid.y = 2
    @grid.u = 11
    @grid.v = 6
    &grid.very thick

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{2 2} }
    @line2.anchor = west

---

start => Rect
    @start.x = 8
    @start.y = 4
    @start.u = 9
    @start.v = 5
    @start.fill = BBGreen 
    &start.draw
    &start.very thick

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{0 1} }
    @line3.anchor = west

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{.....} }
    @line4.anchor = west

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{...*.} }
    @line5.anchor = west

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{.....} }
    @line6.anchor = west

line7 => Node
    @line7.x = 1
    @line7.y = 3.0
    @line7.text = \bbtext{\texttt{.....} }
    @line7.anchor = west

---

a23 => Rect
    @a23.x = 9
    @a23.y = 4
    @a23.u = 10
    @a23.v = 5
    @a23.fill = BBBlack
    &a23.draw
    &a23.very thick

---

a12 => Rect
    @a12.x = 8
    @a12.y = 5
    @a12.u = 9
    @a12.v = 6
    @a12.fill = BBCyan
    &a12.draw
    &a12.very thick

a13 => Rect
    @a13.x = 9
    @a13.y = 5
    @a13.u = 10
    @a13.v = 6
    @a13.fill = BBCyan
    &a13.draw
    &a13.very thick

a32 => Rect
    @a32.x = 8
    @a32.y = 3
    @a32.u = 9
    @a32.v = 4
    @a32.fill = BBCyan
    &a32.draw
    &a32.very thick

a33 => Rect
    @a33.x = 9
    @a33.y = 3
    @a33.u = 10
    @a33.v = 4
    @a33.fill = BBCyan
    &a33.draw
    &a33.very thick

a42 => Rect
    @a42.x = 8
    @a42.y = 2
    @a42.u = 9
    @a42.v = 3
    @a42.fill = BBCyan
    &a42.draw
    &a42.very thick

a43 => Rect
    @a43.x = 9
    @a43.y = 2
    @a43.u = 10
    @a43.v = 3
    @a43.fill = BBCyan
    &a43.draw
    &a43.very thick

---

arrow => Edge
    @arrow.x = 1.65
    @arrow.y = 2.75
    @arrow.u = 1.65
    @arrow.v = 2.00
    @arrow.color = BBBlack
    &arrow.very thick
    &arrow.-latex

r => Node
    @r.x = 1.65
    @r.y = 1.75
    @r.text = \bbinfo{7}

## Scene

header => Node
    @header.y = 7
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

grid => Grid
    @grid.x = 4
    @grid.y = 3
    @grid.u = 10
    @grid.v = 6
    &grid.very thick

a35 => Rect
    @a35.x = 8
    @a35.y = 3
    @a35.u = 9
    @a35.v = 4
    @a35.fill = BBGreen
    &a35.draw
    &a35.very thick
    
a25 => Rect
    @a25.x = 8
    @a25.y = 4
    @a25.u = 9
    @a25.v = 5
    @a25.fill = BBBlack
    &a25.draw
    &a25.very thick
 
a34 => Rect
    @a34.x = 7
    @a34.y = 3
    @a34.u = 8
    @a34.v = 4
    @a34.fill = BBBlack
    &a34.draw
    &a34.very thick
 
a13 => Rect
    @a13.x = 6
    @a13.y = 5
    @a13.u = 7
    @a13.v = 6
    @a13.fill = BBBlack
    &a13.draw
    &a13.very thick
 
a22 => Rect
    @a22.x = 5
    @a22.y = 4
    @a22.u = 6
    @a22.v = 5
    @a22.fill = BBBlack
    &a22.draw
    &a22.very thick
 
a12 => Rect
    @a12.x = 5
    @a12.y = 5
    @a12.u = 6
    @a12.v = 6
    @a12.fill = BBCyan
    &a12.draw
    &a12.very thick
 
---

p => Path
    @p.path = (8.5, 3.5) to (9.5, 3.5) to (9.5, 4.5) to (9.5, 5.5) to (8.5, 5.5) to (7.5, 5.5) to (7.5, 4.5) to (6.5, 4.5) to (6.5, 3.5) to (5.5, 3.5) to (4.5, 3.5) to (4.5, 4.5) to (4.5, 5.5) to (5.5, 5.5)
    @p.color = BBViolet
    &p.->
    &p.thick

---

info => Node
    @info.x = 7
    @info.y = 2
    @info.text = \bbtext{Considere $(x_p, y_p)$ e $(x_q, y_q)$ os pontos de partida e chegada, respectivamente.}

---

    @info.text = \bbtext{Se foram dados $L$ passos para a esquerda e $R$ passos a direita, então}

more => Node
    @more.x = 5
    @more.y = 1
    @more.text = $x_q = x_p + R - L$
    @more.anchor = west

---

    @info.text = \bbtext{Se $L$ for minimizado, o valor de $R$ pode ser obtido por meio da expressão}
    @more.text = $R = x_q - x_p + L$

## Frame

\inputsnippet{cpp}{9}{28}{codes/1063B.cpp}

## Frame

\inputsnippet{cpp}{30}{49}{codes/1063B.cpp}

## End
