## Frame
\bbcover{SPOJ IITKWPCG}{Help the old King}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{Once upon a time there lived a king in a far far country. In the country, there are $n$ cities and $m$ roads. He was severly attacked by his enemy. The enemy damaged all the cities of King's country. As the roads between the cities had been damaged, the King wanted to repair those. So he decided to launch a tender for this.}

\vspace{0.1in}

\bbenglish{As King's country is a well managed country. By well managed country, we mean that it is possible to go from each city to any other city. But now as the city has been destroyed by enemies, all the roads are broken, the king will like to rebuild the roads in such a way that it is still a well manged country.}
    
\vspace{0.1in}

\bbenglish{Cost of repairing the road in the country is really wierd, it is not addition of costs but it is instead multiplication of those. What it means that if the king decides that he should repair $5$ roads, then total cost of repairing those roads will be multiplication of all the $5$ costs.}

## Text

\bbtext{Era uma vez um rei que vivia em um reino muito, muito distante. Neste reino há $n$ povoados e $m$ estradas. O rei foi atacado severamente por seu inimigo. O inimigo danificou todos os povoados do reino. Uma vez que as estradas entre os povoados foram danificadas, o rei quer reparar estas estradas. Deste modo, ele decidiu lançar uma proposta para isto.}

\vspace{0.1in}

\bbtext{O reino é bem planejado, e por bem planejado entenda que é possível ir de qualquer povoado a qualquer outro povoado. Mas como os povooados foram destruídas por inimigos, todas as estradas estão em ruínas, e o rei irá reconstruir as estradas de modo que o reino se torne novamente um reino bem planejado.}
    
\vspace{0.1in}

\bbtext{O custo de reparo de uma estrada neste reino é realmente estranho, de modo que ele não adiciona ao custo total, e sim multiplica. Isto significa que se o rei decidir reparar $5$ estradas, então o custo total do reparo destas estradas será a multiplicação dos $5$ custos individuais de cada estrada.}

## Text

\bbenglish{As the King's treasure has been damaged by the attack of foreign city, he would like to spend minimum amount of money and that the will want that his country still remains well managed country. Surprisingly the company that was given tender had a rule that all the costs will be in powers of two, as they were really love with binary numbers.}

\vspace{0.1in}

\bbenglish{As value of the total cost can be really large. We do not want to know the actual cost, instead output number of divisors of the number.}

## Text

\bbtext{Uma vez que o tesouro real foi prejudicado pelo ataque estrangeiro, o rei gostaria de gastar o mínimo possível de dinheiro e ele deseja que o país continue sendo bem planejado. Supreendentemente, a compania que assumiu a proposta tem uma regra que todos os custos serão potências de dois, uma vez que eles realmente gostam de números binários.}

\vspace{0.1in}

\bbtext{Uma vez que o custo total pode ser muito grande, nos não desejamos este valor. Ao invés disso, imprima o número de divisores deste valor.}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{$T$: number of test cases $(T \leq 5)$}

\vspace{0.1in}

\bbenglish{$n$ and $m$ $(n \leq 10^5$ \&\& $m \leq 2 \times 10^5)$}

\vspace{0.1in}

\bbenglish{Next $m$ lines will have $a, b, c$, which denotes that cities $a$ and $b$ are connected with road of cost $c$.}

\vspace{0.1in}

\bbenglish{$(c \geq 2$ \&\& $c \leq 10^{18}$ \&\& $c$ will always be power of $2)$ $(1 \leq a \leq n)$ and $(1 \leq b \leq n)$}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{For each test case, output a single line containing a number as stated in the problem.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{$T$: número de casos de teste $(T \leq 5)$}

\vspace{0.1in}

\bbtext{$n$ e $m$ $(n \leq 10^5$ \&\& $m \leq 2 \times 10^5)$}

\vspace{0.1in}

\bbtext{As $m$ linhas seguintes terão inteiros $a, b, c$, os quais indicam que os povoados $a$ e $b$ estão conectadas por uma estrada de custo $c$.}

\vspace{0.1in}

\bbtext{$(c \geq 2$ \&\& $c \leq 10^{18}$ \&\& $c$ será sempre uma potência de $2)$ $(1 \leq a \leq n)$ e $(1 \leq b \leq n)$}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Para cada caso de teste, imprima uma única linha contendo o número solicitado pelo problema.}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{2 1} }
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
    @r.text = \footnotesize \bbcomment{\# de povoados}

---

    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{\# de estradas}
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
    @node2.x = 12
    @node2.y = 4
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle
---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{1 2 16} }
    @line2.anchor = west

+r
    @r.x = 1.25
    @r.y = 4.0
    @r.text = \footnotesize \bbcomment{povoado $a$}

+arrow
    @arrow.x = 1.25
    @arrow.y = 4.25
    @arrow.u = 1.25
    @arrow.v = 5.25

---
    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{povoado $b$}

    @arrow.x = 1.65
    @arrow.u = 1.65

---
    @r.x = 2.05
    @r.text = \footnotesize \bbcomment{custo do reparo $c$}

    @arrow.x = 2.05
    @arrow.u = 2.05

---
-r
-arrow

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.very thick
    %e12.label = node[above] { \bbinfo{16} }
   
---

    @e12.color = BBCyan
    &e12.dashed

---

r => Node
    @r.x = 1.65
    @r.y = 4
    @r.text = \bbinfo{5}

arrow => Edge
    @arrow.x = 1.65
    @arrow.y = 5.25
    @arrow.u = 1.65
    @arrow.v = 4.25
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
    @line1.text = \bbtext{\texttt{5 5} }
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
    @b.x = 10
    @b.y = 7
    @b.text = \bbtext{2}
    &b.draw
    &b.very thick
    &b.circle

c => Node
    @c.x = 13
    @c.y = 4
    @c.text = \bbtext{3}
    &c.draw
    &c.very thick
    &c.circle

d => Node
    @d.x = 12
    @d.y = 1
    @d.text = \bbtext{4}
    &d.draw
    &d.very thick
    &d.circle

e => Node
    @e.x = 8
    @e.y = 1
    @e.text = \bbtext{5}
    &e.draw
    &e.very thick
    &e.circle


---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{1 2 2} }
    @line2.anchor = west

---

eAB => Edge
    @eAB.from = a
    @eAB.to = b
    &eAB.very thick
    %eAB.label = node[above left] { \bbinfo{2} }

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{2 3 2 } }
    @line3.anchor = west

---

eCB => Edge
    @eCB.from = c
    @eCB.to = b
    &eCB.very thick
    %eCB.label = node[above right] { \bbinfo{2} }

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{1 3 4} }
    @line4.anchor = west

---

eCA => Edge
    @eCA.from = c
    @eCA.to = a
    &eCA.very thick
    %eCA.label = node[above] { \bbinfo{4} }

---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{3 4 16} }
    @line5.anchor = west

---

eCD => Edge
    @eCD.from = c
    @eCD.to = d
    &eCD.very thick
    %eCD.label = node[below right] { \bbinfo{16} }

---

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{3 5 8} }
    @line6.anchor = west

---

eCE => Edge
    @eCE.from = c
    @eCE.to = e
    &eCE.very thick
    %eCE.label = node[above left] { \bbinfo{8} }

---
    @eAB.color = BBCyan
    &eAB.dashed

---
    @eCB.color = BBCyan
    &eCB.dashed


---
    @eCE.color = BBCyan
    &eCE.dashed

---
    @eCD.color = BBCyan
    &eCD.dashed

---

r => Node
    @r.x = 1.65
    @r.y = 2
    @r.text = \bbinfo{10}

arrow => Edge
    @arrow.x = 1.65
    @arrow.y = 3.25
    @arrow.u = 1.65
    @arrow.v = 2.25
    @arrow.color = BBBlack
    &arrow.-latex
    &arrow.very thick

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
    @a.text = $\star$ \bbtext{A MST minimiza também o produto dos pesos da arestas}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Para verificar este fato, basta substituir os pesos de $G$ por seus respectivos}
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.5
    @b1.text = \bbtext{logaritmos e identificar a MST do grafo $G'$ resultante}
    @b1.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Neste problema em particular, por conta das restrições dos pesos, use $\log_2()$}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{O produto mínimo $p$ da MST original pode ser obtido a partir do custo $k$ da}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 2.0
    @d1.text = \bbtext{MST de $G'$ por meio da expressão $p = 2^k$}
    @d1.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1.0
    @e.text = $\star$ \bbtext{O número de divisores de $2^k$ é igual a $k + 1$}
    @e.anchor = west


## Frame

\inputsnippet{cpp}{41}{59}{codes/IITKWPCG.cpp}

## End
