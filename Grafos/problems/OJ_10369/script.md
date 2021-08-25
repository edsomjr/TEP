## Frame
\bbcover{OJ 10369}{Arctic Network}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{The Department of National Defence (DND) wishes to connect several northern outposts by a wireless network.  Two different communication technologies are to be used in establishing the network: every outpost will have a radio transceiver and some outposts will in addition have a satellite channel.}

\vspace{0.1in}

\bbenglish{Any two outposts with a satellite channel can communicate via the satellite, regardless of their location. Otherwise, two outposts can communicate by radio only if the distance between them does not exceed $D$, which depends of the power of the transceivers. Higher power yields higher $D$ but costs more. Due to purchasing and maintenance considerations, the transceivers at the outposts must be identical; that is, the value of $D$ is the same for every pair of outposts.}

\vspace{0.1in}

\bbenglish{Your job is to determine the minimum $D$ required for the transceivers. There must be at least one communication path (direct or indirect) between every pair of outposts.}

## Text

\bbtext{O Departamento de Defesa Nacional (DDN) deseja conectar vários postos avançados do norte através de uma rede sem fio.  Duas tecnologias de comunicação diferentes serão utilizadas para estabelecer a rede: todo posto terá um transmissor via rádio e alguns postos terão um canal via satélite adicional.}

\vspace{0.1in}

\bbtext{Quaisquer dois postos com canais via satélite podem se comunicar, independentemente de suas localizações. Caso contrário, dois postos podem se comunicar via rádio somente se a distância entre eles não excede $D$, o qual depende da potência dos transmissores. Maior potência leva a um maior valor de $D$, porém o custo também aumenta. Devido a fatores relacionados a compra e manutenção, todos os transmissores dos postos serão idênticos; isto é, o valor de $D$ é o mesmo para qualquer par de postos.}

\vspace{0.1in}

\bbtext{Seu trabalho é determinar o valor mínimo de $D$. Deve haver no mínimo um canal de comunicação (direto ou indireto) entre qualquer par de postos.}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The first line of input contains $N$, the number of test cases. The first line of each test case contains $1\leq S\leq 100$, the number of satellite channels, and $S < P\leq 500$, the number of outposts. $P$ lines follow, giving the $(x, y)$ coordinates of each outpost in km (coordinates are integers between $0$ and $10.000$).}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{For each case, output should consist of a single line giving the minimum $D$ required to connect the network. Output should be specified to $2$ decimal points.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A primeira linha da entrada contém $N$, o número de casos de teste. A primeira linha de cada caso de teste contém $1\leq S\leq 100$, o número de canais de satélite, e $S < P\leq 500$, o número de postos. As $P$ linhas seguintes contém as coordenadas $(x, y)$ de cada posto, em km (coordenadas são inteiros entre $0$ e $10,000$).}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Para cada caso de teste, imprima uma única linha com o valor mínimo de $D$ necessário para conectar a rede. A saída deve ser dada com $2$ casas decimais.}


## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{2 4} }
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
    @r.x = 0.5
    @r.y = 4.75
    @r.text = \footnotesize \bbcomment{\# de canais de satélite}
    @r.anchor = west
---
    @arrow.x = 1.65
    @arrow.u = 1.65

    !r
    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{\# de postos}

---

-r
-arrow

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{0 100} }
    @line2.anchor = west

---

+r
+arrow

    @r.x = 1.25
    @r.y = 4.25
    @r.text = \footnotesize $x$

    @arrow.x = 1.25
    @arrow.y = 4.5
    @arrow.u = 1.25
    @arrow.v = 5.25

---

    @r.x = 1.85
    @r.text = \footnotesize $y$

    @arrow.x = 1.85
    @arrow.u = 1.85

---

-r
-arrow

node1 => Node
    @node1.x = 6
    @node1.y = 1
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{0 300} }
    @line3.anchor = west

---

node2 => Node
    @node2.x = 6
    @node2.y = 3
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{0 600} }
    @line4.anchor = west

---

node3 => Node
    @node3.x = 6
    @node3.y = 7
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle

---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{150 750} }
    @line5.anchor = west

---

node4 => Node
    @node4.x = 13.5
    @node4.y = 1.5
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle

---

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    %e12.label = node[left] { \footnotesize \bbinfo{100}}

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    %e14.label = node[above] { \footnotesize \bbinfo{212.13}}

---
    @node1.fill = BBGreen
    @node3.fill = BBGreen

---

+r
+arrow

    @arrow.y = 3.75
    @arrow.v = 2.75
    @arrow.color = BBBlack
    &arrow.-latex
    &arrow.very thick

    @r.y = 2.5
    @r.text = \bbinfo{212.13}

## Scene


header => Node
    @header.x = 0
    @header.y = 7
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{O problema pode ser modelado como um grafo $G$ onde os postos são os}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.5
    @a1.text = \bbtext{vértices e as arestas são comunicações via rádio}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Se for identificada uma floresta geradora mínima $F_S$ de $G$, em cada}
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4
    @b1.text = \bbtext{componente um posto é escolhido para receber o canal via satélite}
    @b1.anchor = west


---

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $\star$ \bbtext{Assim, se $u$ e $v$ estão no mesmo componente, eles se comunicam via rádio}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbtext{Elementos em componentes distintos se comunicam via satélite}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1
    @e.text = $\star$ \bbbold{Cuidado:} \bbtext{Neste problema, o custo da floresta não é a soma dos pesos!}
    @e.anchor = west

## Frame

\inputsnippet{cpp}{68}{87}{codes/10369.cpp}

## Frame

\inputsnippet{cpp}{47}{66}{codes/10369.cpp}

## End
