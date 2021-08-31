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

\bbtext{O reino é bem planejado, e por bem planejado entenda que é possível ir de qualquer povoado a qualquer outro povoado. Mas como os povooados foram destruídas por inimigos, todas as estradas estão em ruínas, o rei irá reconstruir as estradas de modo que o reino se torne novamente um reino bem planejado.}
    
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


## Scene

header => Node
    @header.x = 0
    @header.y = 7
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

gA => Node
    @gA.x = 5
    @gA.y = 6
    @gA.text = \tiny \bbtext{A}
    &gA.draw
    &gA.thick
    &gA.circle

gB => Node
    @gB.x = 7
    @gB.y = 7
    @gB.text = \tiny \bbtext{B}
    &gB.draw
    &gB.thick
    &gB.circle

gC => Node
    @gC.x = 8
    @gC.y = 5
    @gC.text = \tiny \bbtext{C}
    &gC.draw
    &gC.thick
    &gC.circle

gD => Node
    @gD.x = 10
    @gD.y = 5
    @gD.text = \tiny \bbtext{D}
    &gD.draw
    &gD.thick
    &gD.circle

gE => Node
    @gE.x = 6
    @gE.y = 4
    @gE.text = \tiny \bbtext{E}
    &gE.draw
    &gE.thick
    &gE.circle

gF => Node
    @gF.x = 4
    @gF.y = 5
    @gF.text = \tiny \bbtext{F}
    &gF.draw
    &gF.thick
    &gF.circle

eAB => Edge
    @eAB.from = gA
    @eAB.to = gB
    @eAB.color = BBCyan
    &eAB.thick
    &eAB.-latex
    %eAB.label = [bend left]
    
eAC => Edge
    @eAC.from = gA
    @eAC.to = gC
    @eAC.color = BBCyan
    &eAC.thick
    &eAC.>=latex
    &eAC.<->
 
eDA => Edge
    @eDA.from = gD
    @eDA.to = gA
    @eDA.color = BBCyan
    &eDA.thick
    &eDA.>=latex
    &eDA.<->
    %eDA.label = [bend right]
 
eFE => Edge
    @eFE.from = gF
    @eFE.to = gE
    @eFE.color = BBCyan
    &eFE.thick
    &eFE.>=latex
    &eFE.<->

eBA => Edge
    @eBA.from = gB
    @eBA.to = gA
    @eBA.color = BBGreen
    &eBA.thick
    &eBA.-latex
    %eBA.label = [bend left]
 
eBC => Edge
    @eBC.from = gB
    @eBC.to = gC
    @eBC.color = BBGreen
    &eBC.thick
    &eBC.>=latex
    &eBC.<->
 
eDC => Edge
    @eDC.from = gD
    @eDC.to = gC
    @eDC.color = BBGreen
    &eDC.thick
    &eDC.-latex
 
eDE => Edge
    @eDE.from = gD
    @eDE.to = gE
    @eDE.color = BBGreen
    &eDE.thick
    &eDE.-latex
    %eDE.label = [bend left]

eEC => Edge
    @eEC.from = gE
    @eEC.to = gC
    @eEC.color = BBGreen
    &eEC.thick
    &eEC.-latex
 
eFA => Edge
    @eFA.from = gF
    @eFA.to = gA
    @eFA.color = BBGreen
    &eFA.thick
    &eFA.>=latex
    &eFA.<->
 
---

sA => Node
    @sA.x = 1.5
    @sA.y = 2
    @sA.text = \tiny \bbtext{A}
    &sA.draw
    &sA.thick
    &sA.circle

mA => Node
    @mA.x = 9
    @mA.y = 2
    @mA.text = \tiny \bbtext{A}
    &mA.draw
    &mA.thick
    &mA.circle

sB => Node
    @sB.x = 3.5
    @sB.y = 3
    @sB.text = \tiny \bbtext{B}
    &sB.draw
    &sB.thick
    &sB.circle

mB => Node
    @mB.x = 11
    @mB.y = 3
    @mB.text = \tiny \bbtext{B}
    &mB.draw
    &mB.thick
    &mB.circle

sC => Node
    @sC.x = 4.5
    @sC.y = 1
    @sC.text = \tiny \bbtext{C}
    &sC.draw
    &sC.thick
    &sC.circle

mC => Node
    @mC.x = 12
    @mC.y = 1
    @mC.text = \tiny \bbtext{C}
    &mC.draw
    &mC.thick
    &mC.circle

sD => Node
    @sD.x = 6.5
    @sD.y = 1
    @sD.text = \tiny \bbtext{D}
    &sD.draw
    &sD.thick
    &sD.circle

mD => Node
    @mD.x = 14
    @mD.y = 1
    @mD.text = \tiny \bbtext{D}
    &mD.draw
    &mD.thick
    &mD.circle

mE => Node
    @mE.x = 10
    @mE.y = 0
    @mE.text = \tiny \bbtext{E}
    &mE.draw
    &mE.thick
    &mE.circle

sE => Node
    @sE.x = 2.5
    @sE.y = 0
    @sE.text = \tiny \bbtext{E}
    &sE.draw
    &sE.thick
    &sE.circle

sF => Node
    @sF.x = 0.5
    @sF.y = 1
    @sF.text = \tiny \bbtext{F}
    &sF.draw
    &sF.thick
    &sF.circle

mF => Node
    @mF.x = 8
    @mF.y = 1
    @mF.text = \tiny \bbtext{F}
    &mF.draw
    &mF.thick
    &mF.circle

s => Edge
    @s.x = 5.5
    @s.y = 3.5
    @s.u = 4.5
    @s.v = 2.5
    &s.very thick
    &s.-latex
 
m => Edge
    @m.x = 9
    @m.y = 4.0
    @m.u = 10
    @m.v = 3.0
    &m.very thick
    &m.-latex
 
sAB => Edge
    @sAB.from = sA
    @sAB.to = sB
    @sAB.color = BBCyan
    &sAB.thick
    &sAB.-latex
    %sAB.label = [bend left]
    
sAC => Edge
    @sAC.from = sA
    @sAC.to = sC
    @sAC.color = BBCyan
    &sAC.thick
    &sAC.>=latex
    &sAC.<->
 
sDA => Edge
    @sDA.from = sD
    @sDA.to = sA
    @sDA.color = BBCyan
    &sDA.thick
    &sDA.>=latex
    &sDA.<->
    %sDA.label = [bend right]
 
sFE => Edge
    @sFE.from = sF
    @sFE.to = sE
    @sFE.color = BBCyan
    &sFE.thick
    &sFE.>=latex
    &sFE.<->

mBA => Edge
    @mBA.from = mB
    @mBA.to = mA
    @mBA.color = BBGreen
    &mBA.thick
    &mBA.-latex
    %mBA.label = [bend left]
 
mBC => Edge
    @mBC.from = mB
    @mBC.to = mC
    @mBC.color = BBGreen
    &mBC.thick
    &mBC.>=latex
    &mBC.<->
 
mDC => Edge
    @mDC.from = mD
    @mDC.to = mC
    @mDC.color = BBGreen
    &mDC.thick
    &mDC.-latex
 
mDE => Edge
    @mDE.from = mD
    @mDE.to = mE
    @mDE.color = BBGreen
    &mDE.thick
    &mDE.-latex
    %mDE.label = [bend left]

mEC => Edge
    @mEC.from = mE
    @mEC.to = mC
    @mEC.color = BBGreen
    &mEC.thick
    &mEC.-latex
 
mFA => Edge
    @mFA.from = mF
    @mFA.to = mA
    @mFA.color = BBGreen
    &mFA.thick
    &mFA.>=latex
    &mFA.<->
 

## Scene

header => Node
    @header.x = 0
    @header.y = 7
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

s => Node
    @s.x = 1
    @s.y = 5
    @s.text = $\displaystyle \begin{bmatrix} m_{11} & m_{12} & \ldots & \infty \\ m_{21} & \infty & \ldots & m_{2N} \\ \vdots & \vdots & \ddots & \vdots \\ m_{N1} & m_{N2} & \ldots & \infty \end{bmatrix}$
    @s.anchor = west

m => Node
    @m.x = 8
    @m.y = 5
    @m.text = $\displaystyle \begin{bmatrix} s_{11} & \infty & \ldots & s_{1N} \\ \infty & s_{22} & \ldots & s_{2N} \\ \vdots & \vdots & \ddots & \vdots \\ s_{N1} & s_{N2} & \ldots & \infty \end{bmatrix}$
    @m.anchor = west

---

me => Edge
    @me.x = 3.5
    @me.y = 1.5
    @me.u = 3.5
    @me.v = 3.5
    @me.color = BBViolet
    &me.thick
    &me.-latex

minfo1 => Node
    @minfo1.x = 3.5
    @minfo1.y = 1.25
    @minfo1.text = \footnotesize \bbcomment{distâncias mínimas para}

minfo2 => Node
    @minfo2.x = 3.5
    @minfo2.y = 0.75
    @minfo2.text = \footnotesize \bbcomment{o prof. Miguel}

---
    @me.x = 10
    @me.u = 10
    @minfo1.x = 10
    @minfo2.x = 10

    @minfo1.text = \footnotesize \bbcomment{distâncias mínimas para}
    @minfo2.text = \footnotesize \bbcomment{o prof. Shahriar}
---
-me
-minfo1
-minfo2

line => Edge
    @line.x = 6
    @line.y = 4.5
    @line.u = 7.5
    @line.v = 4.5
    &line.very thick

e => Edge
    @e.x = 6.75
    @e.y = 4.5
    @e.u = 6.75
    @e.v = 3.25
    &e.very thick
    &e.-latex


d => Node
    @d.x = 6.75
    @d.y = 2
    @d.text = $\displaystyle \begin{bmatrix} d_{11} & \infty & \ldots & \infty \\ \infty & \infty & \ldots & d_{2N} \\ \vdots & \vdots & \ddots & \vdots \\ d_{N1} & d_{N2} & \ldots & \infty \end{bmatrix}$

note => Node
    @note.x = 10
    @note.y = 2
    @note.text = $d_{ij} = m_{ij} + s_{ij}$
    @note.anchor = west


## Frame

\inputsnippet{cpp}{41}{59}{codes/IITKWPCG.cpp}

## End
