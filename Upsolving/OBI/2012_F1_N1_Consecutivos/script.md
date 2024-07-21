## Frame
\bbcover{OBI 2012 - Nível 1: Fase 1}{Consecutivos}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbtext{Num sorteio que distribui prêmios, um participante inicialmente sorteia um inteiro $N$ e depois $N$ valores. O
número de pontos do participante é o tamanho da maior sequência de valores consecutivos iguais. Por exemplo,
suponhamos que um participante sorteia $N = 11$ e, nesta ordem, os valores}

\vspace{0.1in}
\bbtext{$$
30, 30, 30, 30, 40, 40, 40, 40, 40, 30, 30
$$}

\vspace{0.1in}

\bbtext{Então, o participante ganha 5 pontos, correspondentes aos 5 valores 40 consecutivos. Note que o participante
sorteou 6 valores iguais a 30, mas nem todos são consecutivos.}

\vspace{0.2in}

\bbtext{Sua tarefa é ajudar a organização do evento, escrevendo um programa que determina o número de pontos de
um participante.}

## Text

\bbbold{Entrada}

\vspace{0.2in}

\bbtext{A primeira linha da entrada contém um inteiro $N$, o número de valores sorteados. A segunda linha contém $N$
valores, $V_1, V_2, \ldots, V_N$, na ordem de sorteio, separados por um espaço em branco.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.2in}

\bbtext{Seu programa deve imprimir apenas uma linha, contendo apenas um inteiro, indicando o número de pontos do
participante.}

\vspace{0.2in}

\bbbold{Restrições}
\vspace{-0.1in}

\bbtext{
\begin{itemize}
    \item $1\leq N\leq 10^4$
    \item $-2^{31}\leq V_i\leq 2^{31} - 1$\bbtext{, para} $i = 1, 2, \ldots, N$
\end{itemize}
}
## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{11} }
    @line1.anchor = west

---

arrow => Edge
    &arrow.->
    @arrow.x = 1.35
    @arrow.y = 5.00
    @arrow.u = 1.35
    @arrow.v = 5.75
    @arrow.color = BBViolet

r => Node
    @r.x = 0.5
    @r.y = 4.75
    @r.text = \footnotesize \bbcomment{\# de valores sorteados}
    @r.anchor = west

---
-r
-arrow

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{30 30 30 40 40 40 40 40 30 30 30}}
    @line2.anchor = west

---

+r
+arrow

    @arrow.x = 4.35
    @arrow.y = 5.00
    @arrow.u = 4.35
    @arrow.v = 3.75
 
    @r.x = 3.25
    @r.y = 3.25
    @r.text = \footnotesize \bbcomment{Números sorteados}

---

-r
-arrow

node1 => Node
    @node1.x = 2
    @node1.y = 3
    @node1.text = \bbtext{\texttt{30}}
    &node1.draw
    &node1.very thick
    &node1.circle

node2 => Node
    @node2.x = 3
    @node2.y = 3
    @node2.text = \bbtext{\texttt{30}}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 4
    @node3.y = 3
    @node3.text = \bbtext{\texttt{30}}
    &node3.draw
    &node3.very thick
    &node3.circle

node4 => Node
    @node4.x = 5
    @node4.y = 3
    @node4.text = \bbtext{\texttt{40}}
    &node4.draw
    &node4.very thick
    &node4.circle

node5 => Node
    @node5.x = 6
    @node5.y = 3
    @node5.text = \bbtext{\texttt{40}}
    &node5.draw
    &node5.very thick
    &node5.circle

node6 => Node
    @node6.x = 7
    @node6.y = 3
    @node6.text = \bbtext{\texttt{40}}
    &node6.draw
    &node6.very thick
    &node6.circle

node7 => Node
    @node7.x = 8
    @node7.y = 3
    @node7.text = \bbtext{\texttt{40}}
    &node7.draw
    &node7.very thick
    &node7.circle

node8 => Node
    @node8.x = 9
    @node8.y = 3
    @node8.text = \bbtext{\texttt{40}}
    &node8.draw
    &node8.very thick
    &node8.circle

node9 => Node
    @node9.x = 10
    @node9.y = 3
    @node9.text = \bbtext{\texttt{30}}
    &node9.draw
    &node9.very thick
    &node9.circle

node10 => Node
    @node10.x = 11
    @node10.y = 3
    @node10.text = \bbtext{\texttt{30}}
    &node10.draw
    &node10.very thick
    &node10.circle

node11 => Node
    @node11.x = 12
    @node11.y = 3
    @node11.text = \bbtext{\texttt{30}}
    &node11.draw
    &node11.very thick
    &node11.circle

---

    @node1.fill = BBGreen
    @node2.fill = BBGreen
    @node3.fill = BBGreen

---

    @node1.fill = BBWhite
    @node2.fill = BBWhite
    @node3.fill = BBWhite

    @node4.fill = BBCyan
    @node5.fill = BBCyan
    @node6.fill = BBCyan
    @node7.fill = BBCyan
    @node8.fill = BBCyan

---

    @node4.fill = BBWhite
    @node5.fill = BBWhite
    @node6.fill = BBWhite
    @node7.fill = BBWhite
    @node8.fill = BBWhite

    @node9.fill = BBGreen
    @node10.fill = BBGreen
    @node11.fill = BBGreen

---

+r
+arrow

    @arrow.x = 8
    @arrow.u = 10
    @arrow.y = 5.5
    @arrow.v = 5.5
    @arrow.color = BBBlack
    &arrow.-latex
    &arrow.thick

    @r.x = 10.25
    @r.y = 5.5
    @r.text = \footnotesize \bboutput{5}
    @r.anchor = west


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
    @a.text = $\star$ \bbtext{O problema consiste em identificar as sequências de números consecutivos}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Uma vez identificadas, a resposta será o tamanho da maior delas}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{Uma possível solução usa um laço e mantém o registro do último elemento visto}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $\star$ \bbtext{Este registro deve ser inicializado com o primeiro elemento do vetor}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 2
    @e.text = $\star$ \bbtext{É preciso fazer uma última verificação, após o encerramento do laço, para verificar}
    @e.anchor = west

e1 => Node
    @e1.x = 0.5
    @e1.y = 1.25
    @e1.text = \bbtext{a última sequência de números consecutivos}
    @e1.anchor = west

## Scene

line1 => Node
	@line1.x = 1
	@line1.y = 8.00
	@line1.text = \inputline{c}{1}{codes/solution.c}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 7.62
	@line2.text = \inputline{c}{2}{codes/solution.c}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 7.24
	@line3.text = \inputline{c}{3}{codes/solution.c}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 6.86
	@line4.text = \inputline{c}{4}{codes/solution.c}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 6.48
	@line5.text = \inputline{c}{5}{codes/solution.c}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 6.10
	@line6.text = \inputline{c}{6}{codes/solution.c}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 5.71
	@line7.text = \inputline{c}{7}{codes/solution.c}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 5.33
	@line8.text = \inputline{c}{8}{codes/solution.c}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 4.95
	@line9.text = \inputline{c}{9}{codes/solution.c}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 4.57
	@line10.text = \inputline{c}{10}{codes/solution.c}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 4.19
	@line11.text = \inputline{c}{11}{codes/solution.c}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 3.81
	@line12.text = \inputline{c}{12}{codes/solution.c}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 3.43
	@line13.text = \inputline{c}{13}{codes/solution.c}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 3.05
	@line14.text = \inputline{c}{14}{codes/solution.c}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = 2.67
	@line15.text = \inputline{c}{15}{codes/solution.c}
	@line15.anchor = west

line16 => Node
	@line16.x = 1
	@line16.y = 2.29
	@line16.text = \inputline{c}{16}{codes/solution.c}
	@line16.anchor = west

line17 => Node
	@line17.x = 1
	@line17.y = 1.90
	@line17.text = \inputline{c}{17}{codes/solution.c}
	@line17.anchor = west

line18 => Node
	@line18.x = 1
	@line18.y = 1.52
	@line18.text = \inputline{c}{18}{codes/solution.c}
	@line18.anchor = west

line19 => Node
	@line19.x = 1
	@line19.y = 1.14
	@line19.text = \inputline{c}{19}{codes/solution.c}
	@line19.anchor = west

line20 => Node
	@line20.x = 1
	@line20.y = 0.76
	@line20.text = \inputline{c}{20}{codes/solution.c}
	@line20.anchor = west

line21 => Node
	@line21.x = 1
	@line21.y = 0.38
	@line21.text = \inputline{c}{21}{codes/solution.c}
	@line21.anchor = west

line22 => Node
	@line22.x = 1
	@line22.y = -0.00
	@line22.text = \inputline{c}{22}{codes/solution.c}
	@line22.anchor = west

vbar => Path
@vbar.path = (7.75, 8) -- (7.75, 0) -- cycle
@vbar.color = gray
&vbar.dashed
line23 => Node
	@line23.x = 8
	@line23.y = 7.62
	@line23.text = \inputline{c}{23}{codes/solution.c}
	@line23.anchor = west

line24 => Node
	@line24.x = 8
	@line24.y = 7.24
	@line24.text = \inputline{c}{24}{codes/solution.c}
	@line24.anchor = west

line25 => Node
	@line25.x = 8
	@line25.y = 6.86
	@line25.text = \inputline{c}{25}{codes/solution.c}
	@line25.anchor = west

line26 => Node
	@line26.x = 8
	@line26.y = 6.48
	@line26.text = \inputline{c}{26}{codes/solution.c}
	@line26.anchor = west

line27 => Node
	@line27.x = 8
	@line27.y = 6.10
	@line27.text = \inputline{c}{27}{codes/solution.c}
	@line27.anchor = west

line28 => Node
	@line28.x = 8
	@line28.y = 5.71
	@line28.text = \inputline{c}{28}{codes/solution.c}
	@line28.anchor = west

line29 => Node
	@line29.x = 8
	@line29.y = 5.33
	@line29.text = \inputline{c}{29}{codes/solution.c}
	@line29.anchor = west

line30 => Node
	@line30.x = 8
	@line30.y = 4.95
	@line30.text = \inputline{c}{30}{codes/solution.c}
	@line30.anchor = west

line31 => Node
	@line31.x = 8
	@line31.y = 4.57
	@line31.text = \inputline{c}{31}{codes/solution.c}
	@line31.anchor = west

line32 => Node
	@line32.x = 8
	@line32.y = 4.19
	@line32.text = \inputline{c}{32}{codes/solution.c}
	@line32.anchor = west

line33 => Node
	@line33.x = 8
	@line33.y = 3.81
	@line33.text = \inputline{c}{33}{codes/solution.c}
	@line33.anchor = west

line34 => Node
	@line34.x = 8
	@line34.y = 3.43
	@line34.text = \inputline{c}{34}{codes/solution.c}
	@line34.anchor = west

line35 => Node
	@line35.x = 8
	@line35.y = 3.05
	@line35.text = \inputline{c}{35}{codes/solution.c}
	@line35.anchor = west

line36 => Node
	@line36.x = 8
	@line36.y = 3.05
	@line36.text = \inputline{c}{36}{codes/solution.c}
	@line36.anchor = west


-line5
-line6
-line7
-line8
-line9
-line10
-line11
-line12
-line13
-line14
-line15
-line16
-line17
-line18
-line19
-line20
-line21
-line22
-line23
-line24
-line25
-line26
-line27
-line28
-line29
-line30
-line31
-line32
-line33

---

+line5
+line6

---

+line8
+line9

--- 

+line11

---

+line13
+line14
+line28

---

+line15
+line16

---

+line18
+line19

---

+line20
+line21
+line27

---

+line22
+line23

---

+line25
+line26

---

+line30
+line31

---

+line33

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Bônus}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Há uma solução alternativa para este problema}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Ela é baseada em uma técnica denominada \bbbold{dois ponteiros}}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{Esta técnica usa duas variáveis inteiras (\code{c}{L} e \code{c}{R}) para identificar subintervalos}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.25
    @c1.text = \bbtext{\code{c}{[L, R)} de elementos com características comuns}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.25
    @d.text = $\star$ \bbtext{Como ambas variável apenas avançam, sem retroceder, a eficiência é mesma}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 1.5
    @d1.text = \bbtext{da solução anterior}
    @d1.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 0.5
    @e.text = $\star$ \bbtext{Esta abordagem dispensa o último teste}
    @e.anchor = west

## Scene

line1 => Node
	@line1.x = 1
	@line1.y = 8.00
	@line1.text = \inputline{c}{1}{codes/solution2.c}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 7.62
	@line2.text = \inputline{c}{2}{codes/solution2.c}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 7.24
	@line3.text = \inputline{c}{3}{codes/solution2.c}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 6.86
	@line4.text = \inputline{c}{4}{codes/solution2.c}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 6.48
	@line5.text = \inputline{c}{5}{codes/solution2.c}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 6.10
	@line6.text = \inputline{c}{6}{codes/solution2.c}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 5.71
	@line7.text = \inputline{c}{7}{codes/solution2.c}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 5.33
	@line8.text = \inputline{c}{8}{codes/solution2.c}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 4.95
	@line9.text = \inputline{c}{9}{codes/solution2.c}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 4.57
	@line10.text = \inputline{c}{10}{codes/solution2.c}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 4.19
	@line11.text = \inputline{c}{11}{codes/solution2.c}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 3.81
	@line12.text = \inputline{c}{12}{codes/solution2.c}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 3.43
	@line13.text = \inputline{c}{13}{codes/solution2.c}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 3.05
	@line14.text = \inputline{c}{14}{codes/solution2.c}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = 2.67
	@line15.text = \inputline{c}{15}{codes/solution2.c}
	@line15.anchor = west

line16 => Node
	@line16.x = 1
	@line16.y = 2.29
	@line16.text = \inputline{c}{16}{codes/solution2.c}
	@line16.anchor = west

line17 => Node
	@line17.x = 1
	@line17.y = 1.90
	@line17.text = \inputline{c}{17}{codes/solution2.c}
	@line17.anchor = west

line18 => Node
	@line18.x = 1
	@line18.y = 1.52
	@line18.text = \inputline{c}{18}{codes/solution2.c}
	@line18.anchor = west

line19 => Node
	@line19.x = 1
	@line19.y = 1.14
	@line19.text = \inputline{c}{19}{codes/solution2.c}
	@line19.anchor = west

line20 => Node
	@line20.x = 1
	@line20.y = 0.76
	@line20.text = \inputline{c}{20}{codes/solution2.c}
	@line20.anchor = west

line21 => Node
	@line21.x = 1
	@line21.y = 0.38
	@line21.text = \inputline{c}{21}{codes/solution2.c}
	@line21.anchor = west

line22 => Node
	@line22.x = 1
	@line22.y = -0.00
	@line22.text = \inputline{c}{22}{codes/solution2.c}
	@line22.anchor = west

vbar => Path
@vbar.path = (7.5, 8) -- (7.5, 0) -- cycle
@vbar.color = gray
&vbar.dashed
line23 => Node
	@line23.x = 8
	@line23.y = 7.62
	@line23.text = \inputline{c}{23}{codes/solution2.c}
	@line23.anchor = west

line24 => Node
	@line24.x = 8
	@line24.y = 7.24
	@line24.text = \inputline{c}{24}{codes/solution2.c}
	@line24.anchor = west

line25 => Node
	@line25.x = 8
	@line25.y = 6.86
	@line25.text = \inputline{c}{25}{codes/solution2.c}
	@line25.anchor = west

line26 => Node
	@line26.x = 8
	@line26.y = 6.48
	@line26.text = \inputline{c}{26}{codes/solution2.c}
	@line26.anchor = west

line27 => Node
	@line27.x = 8
	@line27.y = 6.10
	@line27.text = \inputline{c}{27}{codes/solution2.c}
	@line27.anchor = west

line28 => Node
	@line28.x = 8
	@line28.y = 5.71
	@line28.text = \inputline{c}{28}{codes/solution2.c}
	@line28.anchor = west

line29 => Node
	@line29.x = 8
	@line29.y = 5.33
	@line29.text = \inputline{c}{29}{codes/solution2.c}
	@line29.anchor = west

line30 => Node
	@line30.x = 8
	@line30.y = 4.95
	@line30.text = \inputline{c}{30}{codes/solution2.c}
	@line30.anchor = west

line31 => Node
	@line31.x = 8
	@line31.y = 4.57
	@line31.text = \inputline{c}{31}{codes/solution2.c}
	@line31.anchor = west

-line7
-line8
-line9
-line10
-line11
-line12
-line13
-line14
-line15
-line16
-line17
-line18
-line19
-line20
-line21
-line22
-line23
-line24
-line25
-line26
-line27
-line28
-line29

---

+line8

---

+line10
+line11

---

+line13

---

+line15
+line16
+line26

---

+line17

---

+line19
+line20

---

+line22
+line23

---

+line25

---

+line28

## End
