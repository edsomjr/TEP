## Frame
\bbcover{OJ 10600}{ACM contest and Blackout}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{In order to prepare the “The First National ACM School Contest” (in 20??) the major of the city decided to provide all the schools with a reliable source of power (The major is really afraid of blackouts).  So, in order to do that, power station ``Future'' and one school (doesn’t matter which one) must be connected; in addition, some schools must be connected as well.}

\vspace{0.1in}

\bbenglish{You may assume that a school has a reliable source of power if it’s connected directly to ``Future'', or to any other school that has a reliable source of power. You are given the cost of connection between some schools. The major has decided to pick out two the cheapest connection plans – the cost of the connection is equal to the sum of the connections between the schools. Your task is to help the major -- find the cost of the two cheapest connection plans.}

## Text

\bbtext{Durante os preparativos da “Primeira Maratona Nacional Escolar ACM" (em 20??), o prefeito da cidade decidiu prover todas as escolas com uma fonte de energia confiável (na verdade o prefeito está preocupado com blecautes).  Assim, para atingir este objetivo, a estação de energia ``Futuro'' e uma escola (não importa qual) devem estar conectadas; além disso, algumas outras escolas devem estar conectadas também.}

\vspace{0.1in}

\bbtext{Você pode assumir que uma escola tem uma fonte de energia confiável se ela está conectada diratamente a ``Futuro'', ou a qualquer escola que tenha uma fonte de energia confiável. Serão dados os custos de conexão entre algumas escolas. O prefeito tem que decidir entre os dois planos de conexão mais baratos -- o custo de conexão é igual a soma das conexões entre todas as escolas. Sua tarefa é ajudar o prefeito -- determine os custos dos dois planos mais baratos.}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The Input starts with the number of test cases, $T$ $(1 < T < 15)$ on a line. Then $T$ test cases follow. The first line of every test case contains two numbers, which are separated by a space, $N$ $(3 < N < 100)$ the number of schools in the city, and $M$ the number of possible connections among them. Next $M$ lines contain three numbers $A_i, B_i, C_i$, where $C_i$ is the cost of the connection $(1 < C_i < 300)$ between schools $A_i$ and $B_i$. The schools are numbered with integers in the range $1$ to $N$.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{For every test case print only one line of output. This line should contain two numbers separated by a single space -- the cost of two the cheapest connection plans. Let $S_1$ be the cheapest cost and $S_2$ the next cheapest cost. It’s important, that $S_1 = S_2$ if and only if there are two cheapest plans, otherwise $S_1 < S_2$. You can assume that it is always possible to find the costs $S_1$ and $S_2$.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A entrada começa com o número de casos de teste $T$ $(1 < T < 15)$ em uma linha. Então seguem $T$ casos de teste. A primeira linha de cada caso de teste contém dois inteiros, separados por um espaço em branco, $N$ $(3 < N < 100)$, o número de escolas na cidade, e $M$, o número de conexões possíveis entre elas. As próximas $M$ linhas contém três números $A_i, B_i, C_i$, onde $C_i$ é o custo da conexão $(1 < C_i < 300)$ entre as escolas $A_i$ e $B_i$. As escolas estão numeradas com inteiros de $1$ a $N$.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Para cada caso de teste imprima uma única linha. Esta linha deverá conter dois inteiros separados por um único espaço -- o custo dos dois planos de conexão mais baratos. Seja $S_1$ o custo do plano mais barato e $S_2$ o custo do segundo plano mais barato. Imporante: $S_1 = S_2$ se e somente se há dois planos mais baratos, caso contrário $S_1 < S_2$. Você pode assumir que é sempre possível encontrar os custos $S_1$ e $S_2$.}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{5 8} }
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
    @r.text = \footnotesize \bbcomment{\# de escolas}

---
    @arrow.x = 1.65
    @arrow.u = 1.65

    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{\# de conexões}

---

-r
-arrow

node1 => Node
    @node1.x = 7
    @node1.y = 4.5
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
    @node3.y = 4.5
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle

node4 => Node
    @node4.x = 13
    @node4.y = 1
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle

node5 => Node
    @node5.x = 7
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{1 3 75} }
    @line2.anchor = west

---
+r
+arrow

    @arrow.x = 1.25
    @arrow.y = 5.25
    @arrow.u = 1.25
    @arrow.v = 4.25

    @r.x = 1.25
    @r.y = 4
    @r.text = \footnotesize \bbcomment{cidade A}

---

    @arrow.x = 1.65
    @arrow.u = 1.65

    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{cidade B}

---

    @arrow.x = 2.15
    @arrow.u = 2.15

    @r.x = 2.15
    @r.text = \footnotesize \bbcomment{custo}

---

-r
-arrow

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    %e13.label = node[above] { \footnotesize \bbinfo{75} }

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{3 4 51} }
    @line3.anchor = west

---

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    %e34.label = node[right] { \footnotesize \bbinfo{51} }

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{2 4 19} }
    @line4.anchor = west

---

e24 => Edge
    @e24.from = node2
    @e24.to = node4
    &e24.thick
    %e24.label = node[above right,pos=0.7] { \footnotesize \bbinfo{19} }

---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{3 2 95} }
    @line5.anchor = west

---

e32 => Edge
    @e32.from = node3
    @e32.to = node2
    &e32.thick
    %e32.label = node[above right] { \footnotesize \bbinfo{95} }

---

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{2 5 42} }
    @line6.anchor = west

---

e25 => Edge
    @e25.from = node2
    @e25.to = node5
    &e25.thick
    %e25.label = node[above left,pos=0.7] { \footnotesize \bbinfo{42} }

---

line7 => Node
    @line7.x = 1
    @line7.y = 3.0
    @line7.text = \bbtext{\texttt{5 4 31} }
    @line7.anchor = west

---

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    %e45.label = node[above] { \footnotesize \bbinfo{31} }

---

line8 => Node
    @line8.x = 1
    @line8.y = 2.5
    @line8.text = \bbtext{\texttt{1 2 9} }
    @line8.anchor = west

---

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    %e12.label = node[above left] { \footnotesize \bbinfo{9} }

---

line9 => Node
    @line9.x = 1
    @line9.y = 2.0
    @line9.text = \bbtext{\texttt{3 5 66} }
    @line9.anchor = west

---

e35 => Edge
    @e35.from = node3
    @e35.to = node5
    &e35.thick
    %e35.label = node[above left] { \footnotesize \bbinfo{66} }

---

info => Node
    @info.x = 7
    @info.y = 7
    @info.text = \bbtext{MST}
    @info.anchor = west

    @e12.color = BBCyan
    &e12.dashed
    &e12.very thick

    @e24.color = BBCyan
    &e24.dashed
    &e24.very thick

    @e45.color = BBCyan
    &e45.dashed
    &e45.very thick

    @e34.color = BBCyan
    &e34.dashed
    &e34.very thick

---

    @info.x = 6
    @info.text = \bbtext{2$^a$ melhor MST}

    @e25.color = BBGreen
    &e25.dashed
    &e25.very thick

    @e12.color = BBGreen
    @e24.color = BBGreen
    @e34.color = BBGreen

    !e45
    &e45.thick

---
+r
+arrow

    @arrow.x = 1.65
    @arrow.y = 1.75
    @arrow.u = 1.65
    @arrow.v = 0.75
    @arrow.color = BBBlack
    &arrow.very thick
    &arrow.-latex

    @r.x = 1.65
    @r.y = 0.5
    @r.text = \bbinfo{110 121}


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
    @a.text = $\star$ \bbtext{O problema consiste em determinar a segunda melhor MST}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $\star$ \bbtext{O texto do problema garante a existência desta segunda melhor MST}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $\star$ \bbtext{É preciso modificar o algoritmo de Kruskall para que ele ignore a aresta}
    @c.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 2.5
    @d1.text = \bbtext{indicada e retorne as arestas que formam a MST}
    @d1.anchor = west


---

d => Node
    @d.x = 1
    @d.y = 1.5
    @d.text = $\star$ \bbbold{Cuidado:} \bbtext{Se a aresta removida for uma ponte, o grafo não terá uma MST!}
    @d.anchor = west

## Frame

\inputsnippet{cpp}{69}{83}{codes/10600.cpp}

## Frame

\inputsnippet{cpp}{48}{67}{codes/10600.cpp}

## End
