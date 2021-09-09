## Frame
\bbcover{Timus 1280}{Topological Sorting}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{Michael wants to win the world championship in programming and decided to study $N$ subjects (for convenience we will number these subjects from $1$ to $N$). Michael has worked out a study plan for this purpose. But it turned out that certain subjects may be studied only after others. So, Michael’s coach analyzed all subjects and prepared a list of $M$ limitations in the form ``$s_i\ u_i$'' $(1\leq s_i, u_i\leq N;$ $i = 1, 2, \ldots, M)$, which means that subject $s_i$ must be studied before subject $u_i$.}

\vspace{0.1in}

\bbenglish{Your task is to verify if the order of subjects being studied is correct.}

## Text

\bbtext{Michael quer vencer o campeonato mundial de programação e decidiu estudar $N$ assuntos (de forma conveniente, nós iremos numerar estes assuntos de $1$ a $N$). Michael trabalhou em um plano de estudos para este objetivo. Mas acontece que certos assuntos só devem ser estudados após alguns outros. Assim, o técnico de Michael analisou os assuntos e preparou uma lista de $M$ limitações na forma ``$s_i\ u_i$'' $(1\leq s_i, u_i\leq N;$ $i = 1, 2, \ldots, M)$, o que significa que o assunto $s_i$ deve ser estudado antes do assunto $u_i$.}

\vspace{0.1in}

\bbtext{Sua tarefa é verificar se a ordem dos assuntos a serem estudados está correta.}

## Text

\bbbold{Remark.} \bbenglish{It may appear that it’s impossible to find the correct order of subjects within the given limitations. In this case any subject order worked out by Michael is incorrect.}

\vspace{0.2in}

\bbbold{Limitations}

\vspace{0.1in}

$1\leq N\leq 1000; 0\leq M\leq 100000.$

## Text

\bbbold{Observação.} \bbtext{Pode ser impossível encontrar uma ordem correta para os assuntos que atenda as limitações dadas. Neste caso qualquer ordem de assuntos produzida por Michael estará incorreta.}

\vspace{0.2in}

\bbbold{Limitações}

\vspace{0.1in}

$1\leq N\leq 1000; 0\leq M\leq 100000.$

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The first line contains two integers $N$ and $M$ ($N$ is the number of the subjects, $M$ is the number of the limitations). The next $M$ lines contain pairs $s_i, u_i$, which describe the order of subjects: subject $s_i$ must be studied before $u_i$. Further there is a sequence of $N$ unique numbers ranging from $1$ to $N$ -- the proposed study plan.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{Output a single word ``\texttt{YES}'' or ``\texttt{NO}''. ``\texttt{YES}'' means that the proposed order is correct and has no contradictions with the given limitations. ``\texttt{NO}'' means that the order is incorrect.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A primeira linha contém dois inteiros $N$ e $M$ ($N$ é o número de assuntos, $M$ é o número de limitações). As próximas $M$ linhas contém pares $s_i, u_i$, os quais descrevem a ordem dos assuntos: o assunto $s_i$ deve ser estudado antes do assunto $u_i$. A seguir há uma sequência de $N$ inteiros únicos no intervalo de $1$ a $N$ -- o plano de estudo proposto.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Imprima uma única palavra: ``\texttt{YES}'' ou ``\texttt{NO}''. ``\texttt{YES}'' significa que a ordem proposta está correta e que não há contradições com as limitações dadas. ``\texttt{NO}'' significa que a ordem está incorreta.}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{5 6} }
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
    @r.text = \footnotesize \bbcomment{\# de assuntos}

---

    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{\# de limitações}
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
    @node4.x = 12
    @node4.y = 1
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle

node5 => Node
    @node5.x = 8
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle
---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{1 3} }
    @line2.anchor = west

---
+r
    @r.x = 1.25
    @r.y = 4.0
    @r.text = \footnotesize \bbcomment{$s_i$}

+arrow
    @arrow.x = 1.25
    @arrow.y = 4.25
    @arrow.u = 1.25
    @arrow.v = 5.25

---
    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{$u_i$}

    @arrow.x = 1.65
    @arrow.u = 1.65

---
-r
-arrow

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    &e13.-latex

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{1 4} }
    @line3.anchor = west

---

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    &e14.-latex

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{3 5} }
    @line4.anchor = west

---

e35 => Edge
    @e35.from = node3
    @e35.to = node5
    &e35.thick
    &e35.-latex
---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{5 2} }
    @line5.anchor = west

---

e52 => Edge
    @e52.from = node5
    @e52.to = node2
    &e52.thick
    &e52.-latex

---

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{4 2} }
    @line6.anchor = west

---

e42 => Edge
    @e42.from = node4
    @e42.to = node2
    &e42.thick
    &e42.-latex

---

line7 => Node
    @line7.x = 1
    @line7.y = 3.0
    @line7.text = \bbtext{\texttt{1 2} }
    @line7.anchor = west

---

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex

---

line8 => Node
    @line8.x = 1
    @line8.y = 2.5
    @line8.text = \bbtext{\texttt{1 3 4 5 2} }
    @line8.anchor = west

---
+r
    @r.x = 2.05
    @r.y = 1.0
    @r.text = \footnotesize \bbcomment{ordem proposta}

+arrow
    @arrow.x = 2.05
    @arrow.y = 1.25
    @arrow.u = 2.05
    @arrow.v = 2.25

---
-r
-arrow

    @node1.text = \bbtext{1$^1$}
    @node2.text = \bbtext{2$^5$}
    @node3.text = \bbtext{3$^2$}
    @node4.text = \bbtext{4$^3$}
    @node5.text = \bbtext{5$^4$}

---
    @e13.color = BBOrange

---
    @line2.text = \bbtext{\texttt{1 3}\ \ \textcolor{BBGreen}{\faCheck} }

---
    @e14.color = BBOrange
    @e13.color = BBBlack

---
    @line3.text = \bbtext{\texttt{1 4}\ \ \textcolor{BBGreen}{\faCheck} }

---
    @e14.color = BBBlack
    @e35.color = BBOrange

---
    @line4.text = \bbtext{\texttt{3 5}\ \ \textcolor{BBGreen}{\faCheck} }

---
    @e35.color = BBBlack
    @e52.color = BBOrange

---
    @line5.text = \bbtext{\texttt{5 2}\ \ \textcolor{BBGreen}{\faCheck} }

---
    @e52.color = BBBlack
    @e42.color = BBOrange

---
    @line6.text = \bbtext{\texttt{4 2}\ \ \textcolor{BBGreen}{\faCheck} }

---
    @e42.color = BBBlack
    @e12.color = BBOrange

---
    @line7.text = \bbtext{\texttt{1 2}\ \ \textcolor{BBGreen}{\faCheck} }

---
+r
    @r.y = 1
    @r.text = \footnotesize \bboutput{YES}

+arrow
    @arrow.y = 2.25
    @arrow.v = 1.25
    @arrow.color = BBBlack
    &arrow.-latex
    &arrow.very thick

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{5 6} }
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
    @r.text = \footnotesize \bbcomment{\# de assuntos}

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
    @node4.x = 12
    @node4.y = 1
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle

node5 => Node
    @node5.x = 8
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle
---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{1 3} }
    @line2.anchor = west

---
    @r.x = 1.25
    @r.y = 4.0
    @r.text = \footnotesize \bbcomment{$s_i$}

    @arrow.x = 1.25
    @arrow.y = 4.25
    @arrow.u = 1.25
    @arrow.v = 5.25

    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{$u_i$}

    @arrow.x = 1.65
    @arrow.u = 1.65

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    &e13.-latex

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{1 4} }
    @line3.anchor = west

---

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    &e14.-latex

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{3 5} }
    @line4.anchor = west

---

e35 => Edge
    @e35.from = node3
    @e35.to = node5
    &e35.thick
    &e35.-latex
---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{5 2} }
    @line5.anchor = west

---

e52 => Edge
    @e52.from = node5
    @e52.to = node2
    &e52.thick
    &e52.-latex

---

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{4 2} }
    @line6.anchor = west

---

e42 => Edge
    @e42.from = node4
    @e42.to = node2
    &e42.thick
    &e42.-latex

---

line7 => Node
    @line7.x = 1
    @line7.y = 3.0
    @line7.text = \bbtext{\texttt{1 2} }
    @line7.anchor = west

---

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex

---

line8 => Node
    @line8.x = 1
    @line8.y = 2.5
    @line8.text = \bbtext{\texttt{1 2 4 5 3} }
    @line8.anchor = west

---
    @r.x = 2.05
    @r.y = 1.0
    @r.text = \footnotesize \bbcomment{ordem proposta}

    @arrow.x = 2.05
    @arrow.y = 1.25
    @arrow.u = 2.05
    @arrow.v = 2.25

    @node1.text = \bbtext{1$^1$}
    @node2.text = \bbtext{2$^2$}
    @node3.text = \bbtext{3$^5$}
    @node4.text = \bbtext{4$^3$}
    @node5.text = \bbtext{5$^4$}

---
    @e13.color = BBOrange

---
    @line2.text = \bbtext{\texttt{1 3}\ \ \textcolor{BBGreen}{\faCheck} }

---
    @e13.color = BBBlack
    @e14.color = BBOrange

---
    @line3.text = \bbtext{\texttt{1 4}\ \ \textcolor{BBGreen}{\faCheck} }

---
    @e14.color = BBBlack
    @e35.color = BBOrange

---
    @line4.text = \bbtext{\texttt{3 5}\ \ \textcolor{BBRed}{\faClose} }

---
+r
    @r.y = 1
    @r.text = \footnotesize \bboutput{NO}

+arrow
    @arrow.y = 2.25
    @arrow.v = 1.25
    @arrow.color = BBBlack
    &arrow.-latex
    &arrow.very thick


## Scene

title => Node
    @title.x = 0
    @title.y = 7.5
    @title.text = \Large \bbbold{Solução}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 6.5
    @a.text = $\star$ \bbtext{O problema consiste em determinar se a ordenação proposta por Michael}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 6.0
    @a1.text = \bbtext{é ou não topológica}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Assim, não é preciso de fato gerar uma ordenação topológica: basta verificar}
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.5
    @b1.text = \bbtext{se a ordenação proposta atende às limitações dadas}
    @b1.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Um dicionário permite identificar, de forma eficiente, a posição de uma}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.0
    @c1.text = \bbtext{tarefa de acordo com a ordenação}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.0
    @d.text = $\star$ \bbtext{Se alguma limitação for violada, a resposta será \bboutput{NO}}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1.0
    @e.text = $\star$ \bbtext{\bbbold{Complexidade:} $O(N + M)$}
    @e.anchor = west

## Frame

\inputsnippet{cpp}{46}{59}{codes/1280.cpp}

## End
