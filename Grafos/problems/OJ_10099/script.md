## Frame
\bbcover{OJ 10099}{The Tourist Guide}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{Mr. G. works as a tourist guide. His current assignment is to take some tourists from one city to another. Some two-way roads connect the cities. For each pair of neighboring cities there is a bus service that runs only between those two cities and uses the road that directly connects them. Each bus service has a limit on the maximum number of passengers it can carry. Mr. G. has a map showing the cities and the roads connecting them. He also has the information regarding each bus service. He understands that it may not always be possible for him to take all the tourists to the destination city in a single trip. For example, consider the following road map of $7$ cities. The edges connecting the cities represent the roads and the number written on each edge indicates the passenger limit of the bus service that runs on that road.}

## Text

\bbtext{O senhor G. trabalha como guia turístico. Sua tarefa atual é levar turistas de uma cidade a outra. As cidades são conectados por algumas estradas de mão dupla. Para cada par de cidades vizinhas há um serviço de ônibus que opera apenas entre estas duas cidades e que utiliza a estrada que as une diretamente. Cada serviço de ônibus tem um limite quanto ao número de passageiros que ele pode transportar. O senhor G. tem um mapa das cidades e das estradas que as conectam. Ele também tem informações a respeito dos serviços de ônibus. Ele entende que nem sempre é possível levar todos os turistas para a cidade de destino em uma única viagem. Por exemplo, considere o seguinte mapa, com $7$ cidades. As arestas conectando as cidades representam as estradas e o número associado a cada aresta indica o limite de passageiros do serviço de ônibus que opera naquela estrada.}

## Scene

node1 => Node
    @node1.x = 1
    @node1.y = 4
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.circle
    &node1.very thick

node2 => Node
    @node2.x = 4
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.circle
    &node2.very thick

node3 => Node
    @node3.x = 4
    @node3.y = 1
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.circle
    &node3.very thick

node4 => Node
    @node4.x = 7
    @node4.y = 4
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.circle
    &node4.very thick

node5 => Node
    @node5.x = 10
    @node5.y = 7
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.circle
    &node5.very thick

node6 => Node
    @node6.x = 10
    @node6.y = 1
    @node6.text = \bbtext{6}
    &node6.draw
    &node6.circle
    &node6.very thick

node7 => Node
    @node7.x = 13
    @node7.y = 4
    @node7.text = \bbtext{7}
    &node7.draw
    &node7.circle
    &node7.very thick

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    %e12.label = node[above left] { \footnotesize \bbinfo{30} }

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    %e13.label = node[below left] { \footnotesize \bbinfo{15} }

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    %e14.label = node[above] { \footnotesize \bbinfo{10} }

e24 => Edge
    @e24.from = node2
    @e24.to = node4
    &e24.thick
    %e24.label = node[above right] { \footnotesize \bbinfo{25} }

e25 => Edge
    @e25.from = node2
    @e25.to = node5
    &e25.thick
    %e25.label = node[above] { \footnotesize \bbinfo{60} }

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    %e34.label = node[below right] { \footnotesize \bbinfo{40} }

e36 => Edge
    @e36.from = node3
    @e36.to = node6
    &e36.thick
    %e36.label = node[below] { \footnotesize \bbinfo{20} }

e47 => Edge
    @e47.from = node4
    @e47.to = node7
    &e47.thick
    %e47.label = node[above left] { \footnotesize \bbinfo{35} }

e57 => Edge
    @e57.from = node5
    @e57.to = node7
    &e57.thick
    %e57.label = node[above right] { \footnotesize \bbinfo{20} }

e67 => Edge
    @e67.from = node6
    @e67.to = node7
    &e67.thick
    %e67.label = node[below right] { \footnotesize \bbinfo{30} }

## Text

\bbenglish{Now, if he wants to take $99$ tourists from city $1$ to city $7$, he will require at least $5$ trips and the route he should take is : $1$ - $2$ - $4$ - $7$.}

\vspace{0.1in}

\bbenglish{But, Mr. G. finds it difficult to find the best route all by himself so that he may be able to take all the tourists to the destination city in minimum number of trips. So, he seeks your help.}

## Text

\bbtext{Se ele quer levar $99$ turistas da cidade $1$ para a cidade $7$, ele precisará no mínimo de $5$ viagens e a rota que ele deverá seguir é: $1$ - $2$ - $4$ - $7$.}

\vspace{0.1in}

\bbtext{Mas o senhor G. descobriu que é difícil determinar a melhor rota por conta própria, de modo que ele possa levar todos os turistas ao destino deles no menor número de viagens possível. Assim, ele pediu a sua ajuda.}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The input will contain one or more test cases. The first line of each test case will contain two integers: $N$ $(N\leq 100)$ and $R$ representing respectively the number of cities and the number of road segments.  Then $R$ lines will follow each containing three integers: $C_1, C_2$ and $P$. $C_1$ and $C_2$ are the city numbers and $P$ $(P > 1)$ is the limit on the maximum number of passengers to be carried by the bus service between the two cities. City numbers are positive integers ranging from $1$ to $N$. The $(R + 1)$-th line will contain three integers: $S, D$ and $T$ representing respectively the starting city, the destination city and the number of tourists to be guided.}

\vspace{0.1in}

\bbenglish{The input will end with two zeroes for $N$ and $R$.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A entrada é composta por um ou mais casos de teste. A primeira linha de cada caso de teste contém dois inteiros: $N$ $(N\leq 100)$ e $R$, representando o número de cidades e o número de estradas, respectivamente. As $R$ linhas seguintes contém três inteiros: $C_1, C_2$ e $P$. $C_1$ e $C_2$ são os números das cidades e  $P$ $(P > 1)$ é o número máximo de passageiros que podem ser transportados pelo serviço de ônibus entre as duas cidades. Os números das cidades são inteiros postiviso entre $1$ e $N$. A $(R + 1)$-ésima linha contém três inteiros: $S, D$ e $T$, representando o ponto de partida, o destino e o número de turistas a serem guiados, respectivamente.}

\vspace{0.1in}

\bbtext{A entrada termina com dois zeros para $N$ e $R$.}

## Text

\bbbold{Output}

\vspace{0.1in}

\bbenglish{For each test case in the input first output the scenario number. Then output the minimum number of trips required for this case on a separate line. Print a blank line after the output of each test case.}

## Text

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Para cada caso de teste da entrada imprima o número do cenário. Então imprima o número mínimo de viagens necessárias neste caso em uma linha. Imprima uma linha em branco após a saída de cada caso de teste.}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{7 10} }
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
    @r.x = 1.75
    @r.text = \footnotesize \bbcomment{\# de estradas}

    @arrow.x = 1.75
    @arrow.u = 1.75
---

-r
-arrow

node1 => Node
    @node1.x = 5
    @node1.y = 4
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.circle
    &node1.very thick

node2 => Node
    @node2.x = 7
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.circle
    &node2.very thick

node3 => Node
    @node3.x = 7
    @node3.y = 1
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.circle
    &node3.very thick

node4 => Node
    @node4.x = 9
    @node4.y = 4
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.circle
    &node4.very thick

node5 => Node
    @node5.x = 11
    @node5.y = 7
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.circle
    &node5.very thick

node6 => Node
    @node6.x = 11
    @node6.y = 1
    @node6.text = \bbtext{6}
    &node6.draw
    &node6.circle
    &node6.very thick

node7 => Node
    @node7.x = 13
    @node7.y = 4
    @node7.text = \bbtext{7}
    &node7.draw
    &node7.circle
    &node7.very thick

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{1 2 30} }
    @line2.anchor = west

---
+r
    @r.x = 1.25
    @r.y = 4.25
    @r.text = \footnotesize \bbcomment{cidade $C_1$}

+arrow
    @arrow.x = 1.25
    @arrow.y = 4.50
    @arrow.u = 1.25
    @arrow.v = 5.25
 
---
    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{cidade $C_2$}

    @arrow.x = 1.65
    @arrow.u = 1.65
 
---
    @r.x = 2.15
    @r.text = \footnotesize \bbcomment{máximo de turistas}

    @arrow.x = 2.15
    @arrow.u = 2.15
 
---
-r
-arrow

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    %e12.label = node[above left] { \footnotesize \bbinfo{30} }

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{1 3 15} }
    @line3.anchor = west

---

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    %e13.label = node[below left] { \footnotesize \bbinfo{15} }

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{1 4 10} }
    @line4.anchor = west

---

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    %e14.label = node[above] { \footnotesize \bbinfo{10} }

---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{2 4 25} }
    @line5.anchor = west

---

e24 => Edge
    @e24.from = node2
    @e24.to = node4
    &e24.thick
    %e24.label = node[above right] { \footnotesize \bbinfo{25} }

---

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{2 5 60} }
    @line6.anchor = west

---

e25 => Edge
    @e25.from = node2
    @e25.to = node5
    &e25.thick
    %e25.label = node[above] { \footnotesize \bbinfo{60} }

---

line7 => Node
    @line7.x = 1
    @line7.y = 3.0
    @line7.text = \bbtext{\texttt{3 4 40} }
    @line7.anchor = west

---

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    %e34.label = node[below right] { \footnotesize \bbinfo{40} }

---

line8 => Node
    @line8.x = 1
    @line8.y = 2.5
    @line8.text = \bbtext{\texttt{3 6 20} }
    @line8.anchor = west

---

e36 => Edge
    @e36.from = node3
    @e36.to = node6
    &e36.thick
    %e36.label = node[below] { \footnotesize \bbinfo{20} }

---

line9 => Node
    @line9.x = 1
    @line9.y = 2.0
    @line9.text = \bbtext{\texttt{4 7 35} }
    @line9.anchor = west

---

e47 => Edge
    @e47.from = node4
    @e47.to = node7
    &e47.thick
    %e47.label = node[above left] { \footnotesize \bbinfo{35} }

---

line10 => Node
    @line10.x = 1
    @line10.y = 1.5
    @line10.text = \bbtext{\texttt{5 7 20} }
    @line10.anchor = west
---


e57 => Edge
    @e57.from = node5
    @e57.to = node7
    &e57.thick
    %e57.label = node[above right] { \footnotesize \bbinfo{20} }

---

line11 => Node
    @line11.x = 1
    @line11.y = 1.0
    @line11.text = \bbtext{\texttt{6 7 30} }
    @line11.anchor = west
---

e67 => Edge
    @e67.from = node6
    @e67.to = node7
    &e67.thick
    %e67.label = node[below right] { \footnotesize \bbinfo{30} }

---

line12 => Node
    @line12.x = 1
    @line12.y = 0.5
    @line12.text = \bbtext{\texttt{1 7 99} }
    @line12.anchor = west
---

p => Path
    @p.path = (1.25, 0.25) to (1.25, 0) to (3, 0);
    @p.color = BBViolet 
    &p.-latex

+r
    @r.x = 3
    @r.y = 0
    @r.text = \footnotesize \bbcomment{ponto de partida}
    @r.anchor = west

---
    @node1.fill = BBGreen

---
    @p.path = (1.65, 0.25) to (1.65, 0) to (3, 0);
    @r.text = \footnotesize \bbcomment{destino}

---
    @node7.fill = BBCyan

---
    @p.path = (2.15, 0.25) to (2.15, 0) to (3, 0);
    @r.text = \footnotesize \bbcomment{\# de turistas}

---
-p
-r

    @e12.color = BBCyan
    &e12.very thick
    &e12.dashed

    @e24.color = BBCyan
    &e24.very thick
    &e24.dashed

    @e47.color = BBCyan
    &e47.very thick
    &e47.dashed

---

+r
+arrow
    @r.x = 3.5
    @r.y = 2.5
    @r.text = \bbinfo{5}

    @arrow.x = 2.5
    @arrow.y = 2.5
    @arrow.u = 3.5
    @arrow.v = 2.5
    @arrow.color = BBBlack
    &arrow.-latex
    &arrow.very thick
    
## Scene

header => Node
    @header.x = 0
    @header.y = 7
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

info => Node
    @info.x = 7
    @info.y = 6
    @info.text = \bbtext{Considere um caminho entre a partida S e o destino D}

---

nodeS => Node
    @nodeS.x = 2
    @nodeS.y = 4
    @nodeS.text = \bbtext{S}
    &nodeS.draw
    &nodeS.circle
    &nodeS.very thick
    
nodeA => Node
    @nodeA.x = 5
    @nodeA.y = 4
    @nodeA.text = \bbtext{A}
    &nodeA.draw
    &nodeA.circle
    &nodeA.very thick

nodeB => Node
    @nodeB.x = 9
    @nodeB.y = 4
    @nodeB.text = \bbtext{B}
    &nodeB.draw
    &nodeB.circle
    &nodeB.very thick

nodeC => Node
    @nodeC.x = 7
    @nodeC.y = 2
    @nodeC.text = \bbtext{C}
    &nodeC.draw
    &nodeC.circle
    &nodeC.very thick

nodeD => Node
    @nodeD.x = 12
    @nodeD.y = 4
    @nodeD.text = \bbtext{D}
    &nodeD.draw
    &nodeD.circle
    &nodeD.very thick
 
eSA => Edge
    @eSA.from = nodeS
    @eSA.to = nodeA
    &eSA.thick
    %eSA.label = node[above] { \footnotesize \bbinfo{40} }

eAB => Edge
    @eAB.from = nodeA
    @eAB.to = nodeB
    &eAB.thick
    %eAB.label = node[above] { \footnotesize \bbinfo{10} }

eBD => Edge
    @eBD.from = nodeB
    @eBD.to = nodeD
    &eBD.thick
    %eBD.label = node[above] { \footnotesize \bbinfo{50} }

eAC => Edge
    @eAC.from = nodeA
    @eAC.to = nodeC
    &eAC.thick
    %eAC.label = node[above right] { \footnotesize \bbinfo{30} }

eCB => Edge
    @eCB.from = nodeC
    @eCB.to = nodeB
    &eCB.thick
    %eCB.label = node[above left] { \footnotesize \bbinfo{20} }

    @eSA.color = BBCyan
    &eSA.very thick
    &eSA.dashed

    @eAB.color = BBCyan
    &eAB.very thick
    &eAB.dashed

    @eBD.color = BBCyan
    &eBD.very thick
    &eBD.dashed

---
    @info.text = \bbtext{O máximo de passageiros é determinado pela aresta de menor peso}

---

    %eAB.label = node[above] { \footnotesize \textcolor{BBViolet}{\textbf{10}} }

---
    @info.text = \bbtext{O máximo é dado por este peso mínimo menos um, por conta do guia,} 

info2 => Node
    @info2.x = 7
    @info2.y = 5.5
    @info2.text = \bbtext{que ocupa uma posição no ônibus}

---
    @info.text = \bbtext{O problema consiste em determinar o caminho de S a D que maximiza este peso }
    @info2.text = \bbtext{mínimo, ou seja, um problema \bbenglish{maximin}}

    !eAB
    &eAB.thick
    %eAB.label = node[above] { \footnotesize \bbinfo{10} }

    !eSA
    &eSA.thick

    !eBD
    &eBD.thick
---
    @eSA.color = BBGreen
    &eSA.very thick
    &eSA.dashed

    @eAC.color = BBGreen
    &eAC.very thick
    &eAC.dashed

    @eCB.color = BBGreen
    &eCB.very thick
    &eCB.dashed

    @eBD.color = BBGreen
    &eBD.very thick
    &eBD.dashed

    %eCB.label = node[above left] { \footnotesize \textcolor{BBViolet}{\textbf{20}} }

---
-info2

    @info.text = \bbtext{A MST resolve o problema \bbenglish{maximin}.}

    !eSA
    &eSA.thick

    !eAC
    &eAC.thick

    !eCB
    &eCB.thick

    !eBD
    &eBD.thick

    %eCB.label = node[above left] { \footnotesize \bbinfo{20} }

---
+info2
    
    @info.text = \bbtext{O algoritmo de Prim pode ser modificado para computar $\mathrm{maximin}($S$, u)$}
    @info2.text = \bbtext{para todos os vértices do componente conectado que contém $S$}

---
-info2
    @info.text = \bbtext{Seja $u$ o próximo vértice a ser adicionado a $C$}

    @nodeS.fill = BBCyan

---
+info2

    @info.text = \bbtext{Se a aresta que conecta $u$ a $C$ é $(u, $ S$, w)$, então}
    @info2.text = $\displaystyle \mathrm{maximin}($\bbtext{S}$, u) = w$
    @info2.y = 5.25

---
    @nodeA.fill = BBGreen
    %eSA.label = node[above] { \footnotesize \textcolor{BBViolet}{\textbf{40}} }

---
    @info.text = \bbtext{Se a aresta que conecta $u$ a $C$ é $(u, v, w)$, então}
    @info2.text = $\displaystyle \mathrm{maximin}(S, u) = \min\ \{ \mathrm{maximin}($\bbtext{S}$, u), w) \}$
    %eSA.label = node[above] { \footnotesize \bbinfo{40} }
---

    @nodeC.fill = BBOrange
    %eAC.label = node[above right] { \footnotesize \textcolor{BBViolet}{\textbf{30}} }

## Frame

\inputsnippet{cpp}{11}{30}{codes/10099.cpp}

## Frame

\inputsnippet{cpp}{31}{47}{codes/10099.cpp}

## End
