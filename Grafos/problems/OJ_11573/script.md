## Frame
\bbcover{OJ 11573}{Ocean Currents}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{For a boat on a large body of water, strong currents can be dangerous, but with careful planning, they can be harnessed to help the boat reach its destination. Your job is to help in that planning.}

\vspace{0.1in}

\bbenglish{At each location, the current flows in some direction. The captain can choose to either go with the flow of the current, using no energy, or to move one square in any other direction, at the cost of one energy unit. The boat always moves in one of the following eight directions: north, south, east, west, northeast, northwest, southeast, southwest. The boat cannot leave the boundary of the lake.}

\vspace{0.1in}

\bbenglish{You are to help him devise a strategy to reach the destination with the minimum energy consumption.}

## Text

\bbtext{Para um barco, as correntes podem ser perigosas ao se navegar em uma área ampla, mas com um planejamento cuidadoso, estas correntes podem ser usadas para auxiliar o barco a chegar em seu destino. Seu trabalho é auxiliar neste planejamento.}

\vspace{0.1in}

\bbtext{Em cada localidade, as correntes seguem uma certa direção. O capitão pode optar ou por seguir a corrente, sem gastar energia, ou se mover um quadrado em qualquer outra direção, com o custo de uma unidade de energia. O barco sempre se move em uma das seguintes oito direções: norte, sul, leste, oeste, nordeste, noroeste, sudeste, sudoeste. O barco não pode sair da região delimitada pelo lago.}

\vspace{0.1in}

\bbtext{Você deve auxiliá-lo a estabelecer uma estratégia para atingir o seu destino com o menor consumo de energia possível.}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The lake is represented as a rectangular grid. The first line of input contains two integers $r$ and $c$, the number of rows and columns in the grid. The grid has no more than $1000$ rows and no more than $1000$ columns. Each of the following $r$ lines contains exactly $c$ characters, each a digit from $0$ to $7$ inclusive.  The character `\texttt{0}' means the current flows north (i.e. up in the grid, in the direction of decreasing row number), `\texttt{1}' means it flows northeast, `\texttt{2}' means east (i.e. in the direction of increasing column number), `\texttt{3}' means southeast, and so on in a clockwise manner:}

\vspace{0.1in}

\begin{center}
    \begin{tikzpicture}[scale=0.5]
        \node (A0) at (4, 6) { \tt 0 };
        \node (A1) at (6, 6) { \tt 1 };
        \node (A2) at (6, 4) { \tt 2 };
        \node (A3) at (6, 2) { \tt 3 };
        \node (A4) at (4, 2) { \tt 4 };
        \node (A5) at (2, 2) { \tt 5 };
        \node (A6) at (2, 4) { \tt 6 };
        \node (A7) at (2, 6) { \tt 7 };
        \node (S) at (4, 4) { \tt * };

        \draw (S) to (A0);
        \draw (S) to (A1);
        \draw (S) to (A2);
        \draw (S) to (A3);
        \draw (S) to (A4);
        \draw (S) to (A5);
        \draw (S) to (A6);
        \draw (S) to (A7);
    \end{tikzpicture}
\end{center}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{O lago é representado como uma malha retangular. A primeira linha da entrada contém dois inteiros $r$ e $c$, o número de linhas e de colunas da malha. A malha não tem mais do que $1000$ linhas e não mais do que $1000$ colunas. Cada uma das $r$ linhas seguintes contém exatamente $c$ caracteres, sendo um dos dígitos $0$ a $7$, inclusive.  O caractere `\texttt{0}' significa que a corrente flui para o norte (isto é, para cima na malha, na direção decrescente do número da linha), `\texttt{1}' significa que a corrente flui no sentido nordeste, `\texttt{2}' significa leste (isto é, na direção crescente do número da coluna), `\texttt{3}' significa sudeste, e assim por diante, em sentido horário:}

\vspace{0.1in}

\begin{center}
    \begin{tikzpicture}[scale=0.5]
        \node (A0) at (4, 6) { \tt 0 };
        \node (A1) at (6, 6) { \tt 1 };
        \node (A2) at (6, 4) { \tt 2 };
        \node (A3) at (6, 2) { \tt 3 };
        \node (A4) at (4, 2) { \tt 4 };
        \node (A5) at (2, 2) { \tt 5 };
        \node (A6) at (2, 4) { \tt 6 };
        \node (A7) at (2, 6) { \tt 7 };
        \node (S) at (4, 4) { \tt * };

        \draw (S) to (A0);
        \draw (S) to (A1);
        \draw (S) to (A2);
        \draw (S) to (A3);
        \draw (S) to (A4);
        \draw (S) to (A5);
        \draw (S) to (A6);
        \draw (S) to (A7);
    \end{tikzpicture}
\end{center}


## Text

\bbenglish{The line after the grid contains a single integer $n$, the number of trips to be made, which is at most $50$. Each of the following $n$ lines describes a trip using four integers $r_s, c_s, r_d, c_d$, giving the row and column of the starting point and the destination of the trip. Rows and columns are numbered starting with $1$.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{For each trip, output a line containing a single integer, the minimum number of energy units needed to get from the starting point to the destination.}

## Text

\bbtext{A linha após a malha contém um único inteiro $n$, o número de viagens que serão feitas, sendo no máximo igual a $50$. Cada uma das $n$ linhas seguintes descrevem uma viagem por meio de quatro inteiros $r_s, c_s, r_d, c_d$, os quais informam a linha e a coluna do ponto de partida e do destino da viagem. Linhas e colunas são numeradas a partir de $1$.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Para cada viagem imprima uma linha contendo um único inteiro, o número mínimo de unidades de energia gastas para atingir o destino a partir do ponto de partida.}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{5 5} }
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
    @r.text = \footnotesize $r$

---
    @arrow.x = 1.65
    @arrow.u = 1.65
 
    @r.x = 1.65
    @r.text = \footnotesize $c$

---
-r
-arrow
    
grid => Grid
    @grid.x = 7
    @grid.y = 1
    @grid.u = 12
    @grid.v = 6
    &grid.thick

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{04125} }
    @line2.anchor = west

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{03355} }
    @line3.anchor = west

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{64734} }
    @line4.anchor = west

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{72377} }
    @line5.anchor = west

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{02062} }
    @line6.anchor = west

---

+arrow
    @arrow.y = 2.5
    @arrow.v = 3.25

+r
    @r.text = \footnotesize \bbcomment{malha}
    @r.y = 2.25
    
---

-arrow
-r

a11 => Node
    @a11.x = 7.5
    @a11.y = 5.5
    @a11.text = \faArrowUp
    @a11.scale = 1.5

a12 => Node
    @a12.x = 8.5
    @a12.y = 5.5
    @a12.text = \faArrowDown
    @a12.scale = 1.5

a13 => Node
    @a13.x = 9.5
    @a13.y = 5.5
    @a13.text = \faArrowUp
    @a13.scale = 1.5
    @a13.rotate = -45

a14 => Node
    @a14.x = 10.5
    @a14.y = 5.5
    @a14.text = \faArrowRight
    @a14.scale = 1.5

a15 => Node
    @a15.x = 11.5
    @a15.y = 5.5
    @a15.text = \faArrowDown
    @a15.scale = 1.5
    @a15.rotate = -45

a21 => Node
    @a21.x = 7.5
    @a21.y = 4.5
    @a21.text = \faArrowUp
    @a21.scale = 1.5

a22 => Node
    @a22.x = 8.5
    @a22.y = 4.5
    @a22.text = \faArrowDown
    @a22.scale = 1.5
    @a22.rotate = 45

a23 => Node
    @a23.x = 9.5
    @a23.y = 4.5
    @a23.text = \faArrowDown
    @a23.scale = 1.5
    @a23.rotate = 45

a24 => Node
    @a24.x = 10.5
    @a24.y = 4.5
    @a24.text = \faArrowDown
    @a24.scale = 1.5
    @a24.rotate = -45

a25 => Node
    @a25.x = 11.5
    @a25.y = 4.5
    @a25.text = \faArrowDown
    @a25.scale = 1.5
    @a25.rotate = -45

a31 => Node
    @a31.x = 7.5
    @a31.y = 3.5
    @a31.text = \faArrowLeft
    @a31.scale = 1.5

a32 => Node
    @a32.x = 8.5
    @a32.y = 3.5
    @a32.text = \faArrowDown
    @a32.scale = 1.5

a33 => Node
    @a33.x = 9.5
    @a33.y = 3.5
    @a33.text = \faArrowLeft
    @a33.scale = 1.5
    @a33.rotate = -45

a34 => Node
    @a34.x = 10.5
    @a34.y = 3.5
    @a34.text = \faArrowRight
    @a34.scale = 1.5
    @a34.rotate = -45

a35 => Node
    @a35.x = 11.5
    @a35.y = 3.5
    @a35.text = \faArrowDown
    @a35.scale = 1.5

a41 => Node
    @a41.x = 7.5
    @a41.y = 2.5
    @a41.text = \faArrowUp
    @a41.scale = 1.5
    @a41.rotate = 45

a42 => Node
    @a42.x = 8.5
    @a42.y = 2.5
    @a42.text = \faArrowRight
    @a42.scale = 1.5

a43 => Node
    @a43.x = 9.5
    @a43.y = 2.5
    @a43.text = \faArrowRight
    @a43.scale = 1.5
    @a43.rotate = -45

a44 => Node
    @a44.x = 10.5
    @a44.y = 2.5
    @a44.text = \faArrowUp
    @a44.scale = 1.5
    @a44.rotate = 45

a45 => Node
    @a45.x = 11.5
    @a45.y = 2.5
    @a45.text = \faArrowUp
    @a45.scale = 1.5
    @a45.rotate = 45

a51 => Node
    @a51.x = 7.5
    @a51.y = 1.5
    @a51.text = \faArrowUp
    @a51.scale = 1.5

a52 => Node
    @a52.x = 8.5
    @a52.y = 1.5
    @a52.text = \faArrowRight
    @a52.scale = 1.5

a53 => Node
    @a53.x = 9.5
    @a53.y = 1.5
    @a53.text = \faArrowUp
    @a53.scale = 1.5

a54 => Node
    @a54.x = 10.5
    @a54.y = 1.5
    @a54.text = \faArrowLeft
    @a54.scale = 1.5

a55 => Node
    @a55.x = 11.5
    @a55.y = 1.5
    @a55.text = \faArrowRight
    @a55.scale = 1.5

---

line7 => Node
    @line7.x = 1
    @line7.y = 3.0
    @line7.text = \bbtext{\texttt{3} }
    @line7.anchor = west

---

+arrow
    @arrow.x = 1.25
    @arrow.y = 2.0
    @arrow.u = 1.25
    @arrow.v = 2.75

+r
    @r.text = \footnotesize \bbcomment{\# de viagens}
    @r.x = 1.25
    @r.y = 1.75
 
---

-arrow
-r

line8 => Node
    @line8.x = 1
    @line8.y = 2.5
    @line8.text = \bbtext{\texttt{4 2 4 2} }
    @line8.anchor = west

---

+arrow
    @arrow.x = 1.25
    @arrow.y = 1.5
    @arrow.u = 1.25
    @arrow.v = 2.25

+r
    @r.text = \footnotesize $r_s$
    @r.x = 1.25
    @r.y = 1.25
 
---

+arrow
    @arrow.x = 1.65
    @arrow.u = 1.65

+r
    @r.text = \footnotesize $c_s$
    @r.x = 1.65

---

+arrow
    @arrow.x = 2.05
    @arrow.u = 2.05

+r
    @r.text = \footnotesize $r_d$
    @r.x = 2.05
 
---

+arrow
    @arrow.x = 2.45
    @arrow.u = 2.45

+r
    @r.text = \footnotesize $r_s$
    @r.x = 2.45
 
---
    @a42.text = \textcolor{BBGreen}{\faArrowRight}

+arrow
    @arrow.x = 3.0
    @arrow.y = 2.5
    @arrow.u = 4.0
    @arrow.v = 2.5
    @arrow.color = BBBlack
    &arrow.very thick
    &arrow.-latex

+r
    @r.x = 4.0
    @r.y = 2.5
    @r.anchor = west
    @r.text = \bbinfo{0}

---
-arrow
-r

    @a42.text = \textcolor{BBBlack}{\faArrowRight}

line9 => Node
    @line9.x = 1
    @line9.y = 2.0
    @line9.text = \bbtext{\texttt{4 5 1 4} }
    @line9.anchor = west

---

    @a45.text = \textcolor{BBCyan}{\faArrowUp}
    @a34.text = \textcolor{BBRed}{\faArrowRight}
    @a24.text = \textcolor{BBRed}{\faArrowDown}
    @a14.text = \textcolor{BBGreen}{\faArrowRight}

+arrow
    @arrow.y = 2.0
    @arrow.v = 2.0

+r
    @r.y = 2.0
    @r.text = \bbinfo{2}

---
-arrow
-r

    @a45.text = \textcolor{BBBlack}{\faArrowUp}
    @a34.text = \textcolor{BBBlack}{\faArrowRight}
    @a24.text = \textcolor{BBBlack}{\faArrowDown}
    @a14.text = \textcolor{BBBlack}{\faArrowRight}

---

line10 => Node
    @line10.x = 1
    @line10.y = 1.5
    @line10.text = \bbtext{\texttt{5 3 3 4} }
    @line10.anchor = west

--
    @a53.text = \textcolor{BBCyan}{\faArrowUp}
    @a43.text = \textcolor{BBRed}{\faArrowRight}
    @a34.text = \textcolor{BBGreen}{\faArrowRight}

+arrow
    @arrow.y = 1.5
    @arrow.v = 1.5

+r
    @r.y = 1.5
    @r.text = \bbinfo{1}

## Scene

header => Node
    @header.y = 6
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $\star$ \bbtext{Cada viagem consiste em um problema de caminho mínimo}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $\star$ \bbtext{As arestas tem peso $1$, exceto a direção da corrente, que tem peso $0$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $\star$ \bbtext{Portanto o problema pode ser resolvido por meio de uma BFS 0/1}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbbold{Complexidade:} $O(nrc)$
    @d.anchor = west

## Frame

\inputsnippet{cpp}{10}{29}{codes/11573.cpp}

## Frame

\inputsnippet{cpp}{31}{50}{codes/11573.cpp}

## End
