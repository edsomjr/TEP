## Frame
\bbcover{OJ 10171}{Meeting Prof. Miguel...}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{I have always thought that someday I will meet Professor Miguel, who has allowed me to arrange so many contests. But I have managed to miss all the opportunities in reality. At last with the help of a magician I have managed to meet him in the magical \bbbold{City of Hope}. The city of hope has many roads. Some of them are bi-directional and others are unidirectional. Another important property of these streets are that some of the streets are for people whose age is less than thirty and rest are for the others. This is to give the minors freedom in their activities.  Each street has a certain length. Given the description of such a city and our initial positions, you will have to find the most suitable place where we can meet. The most suitable place is the place where our combined effort of reaching is minimum. You can assume that I am 25 years old and Prof. Miguel is 40+.}

## Text

\bbtext{Eu sempre pensei que algum dia eu iria me encontrar com o Professor Miguel, que tem me permitido preparar muitos eventos. Mas, de fato, eu perdi todas as oportunidades. Enfim, com a ajuda de um mágico eu consegui encontrá-lo na mágica \bbbold{Cidade da Esperança}. A cidade da esperança tem muitas ruas. Algumas delas são bidirecionais, outras unidirecionais. Outra propriedade importante destas ruas é que algumas delas são para pessoas com menos do que 30 anos e as outras são para os demais cidadãos. Isto é feito para dar aos menores liberdade em suas atividades.  Cada rua tem um certo comprimento. Dada a descrição de cada cidade e as nossas posições iniciais, determine o local mais apropriado para o encontro. O lugar mais apropriado é o lugar cujo esforço combinado de ambos para chegar lá é minimo. Você pode assumir que eu tenho 25 anos e o Prof. Miguel tem 40 ou mais.}

## Text

\begin{figure}
    \includegraphics[scale=1.3]{figs/figure.png}
    \caption{\bbenglish{Shahriar Manzoor and Miguel A.  Revilla (Shanghai, 2005).  First meeting after five years of collaboration}}
\end{figure}

## Text

\begin{figure}
    \includegraphics[scale=1.3]{figs/figure.png}
    \caption{\bbtext{Shahriar Manzoor e Miguel A.  Revilla (Shanghai, 2005).  Primeiro encontro após cinco anos de colaboração}}
\end{figure}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The input contains several descriptions of cities. Each description of city is started by a integer $N$, which indicates how many streets are there. The next $N$ lines contain the description of $N$ streets.}

\vspace{0.1in}

\bbenglish{The description of each street consists of four uppercase alphabets and an integer. The first alphabet is either ‘\texttt{Y}’ (indicates that the street is for young) or ‘\texttt{M}’ (indicates that the road is for people aged 30 or more) and the second character is either ‘\texttt{U}’ (indicates that the street is unidirectional) or ‘\texttt{B}’ (indicates that the street is bi-directional). The third and fourth characters, $X$ and $Y$ can be any uppercase alphabet and they indicate that place named $X$ and $Y$ of the city are connected (in case of unidirectional it means that there is a one-way street from $X$ to $Y$) and the last non-negative integer $C$ indicates the energy required to walk through the street. If we are in the same place we can meet each other in zero cost anyhow. Every energy value is less than $500$.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A entrada contém várias descrições de cidades. Cada descrição de cidade começa com um inteiro $N$, o qual indica quantas ruas há na cidade. As próximas $N$ linhas contém as descrições das $N$ ruas.}

\vspace{0.1in}

\bbtext{A descrição de cada rua consiste em quatro letras maiúsculas do alfabeto e um inteiro. A primeira letra é ou ‘\texttt{Y}’ (indicando que a rua é para os jovens) ou ‘\texttt{M}’ (indicando que a rua é para pessoas com 30 anos ou mais) e o segundo caractere ou é ‘\texttt{U}’ (indicando que a rua é unidirecional) ou ‘\texttt{B}’ (indicando que a rua é bidirecional). O terceiro e o quarto caracteres $X$ e $Y$ podem ser qualquer letra maiúscula do alfabeto e indicam que os lugares $X$ e $Y$ da cidade estão conectados (no caso unidirecional significa que há uma rua de mão única com sentido de $X$ a $Y$) e o inteiro não-negativo $C$ indica que a energia necessária para caminhar pela rua. Se ambos estamos no mesmo lugar nós podemos nos encontrar com custo zero, de algum modo. Os valores da energia são menores do que $500$.}


## Text

\bbenglish{After the description of the city the last line of each input contains two place names, which are the initial position of me and Prof. Miguel respectively.}

\vspace{0.1in}

\bbenglish{A value zero for $N$ indicates end of input.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{For each set of input, print the minimum energy cost and the place, which is most suitable for us to meet. If there is more than one place to meet print all of them in lexicographical order in the same line, separated by a single space. If there is no such places where we can meet then print the line ‘\texttt{You will never meet.}’}

## Text

\bbtext{Após a descrição de uma cidade a última linha de cada entrada contém o nome de dois lugares, os quais são as posições iniciais onde estão eu e o prof. Miguel, respectivamente.}

\vspace{0.1in}

\bbtext{O valor $N$ igual a zero indica o fim da entrada.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Para cada conjunto da entrada, imprima o custo mínimo de energia necessário e o lugar mais apropriado para o encontro. Se existe mais de um lugar imprima todos eles, em ordem lexicográfica, na mesma linha, separados por um único espaço em branco. Se não há um lugar apropriado para o encontro imprima a mensagem ‘\texttt{You will never meet.}’}

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
    @r.text = \footnotesize \bbcomment{\# de estradas}

---
-r
-arrow

a => Node
    @a.x = 7
    @a.y = 4
    @a.text = \bbtext{A}
    &a.draw
    &a.very thick
    &a.circle

b => Node
    @b.x = 10
    @b.y = 7
    @b.text = \bbtext{B}
    &b.draw
    &b.very thick
    &b.circle

c => Node
    @c.x = 13
    @c.y = 4
    @c.text = \bbtext{C}
    &c.draw
    &c.very thick
    &c.circle

d => Node
    @d.x = 10
    @d.y = 1
    @d.text = \bbtext{D}
    &d.draw
    &d.very thick
    &d.circle

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{Y U A B 4} }
    @line2.anchor = west

+r
    @r.y = 4.0
    @r.text = \footnotesize \bbcomment{público da rua}

+arrow
    @arrow.y = 4.25
    @arrow.v = 5.25

---
    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{sentido do tráfego}

    @arrow.x = 1.65
    @arrow.u = 1.65

---
    @r.x = 2.05
    @r.text = \footnotesize \bbcomment{ponto de partida}

    @arrow.x = 2.05
    @arrow.u = 2.05

---
    @r.x = 2.45
    @r.text = \footnotesize \bbcomment{ponto de chegada}

    @arrow.x = 2.45
    @arrow.u = 2.45

---
    @r.x = 2.85
    @r.text = \footnotesize \bbcomment{custo de energia}

    @arrow.x = 2.85
    @arrow.u = 2.85

---
-r
-arrow

eAB => Edge
    @eAB.from = a
    @eAB.to = b
    @eAB.color = BBCyan
    &eAB.very thick
    &eAB.-latex
    %eAB.label = node[above left] { \bbinfo{4} }

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{Y U C A 1}}
    @line3.anchor = west

---

eCA => Edge
    @eCA.from = c
    @eCA.to = a
    @eCA.color = BBCyan
    &eCA.very thick
    &eCA.-latex
    %eCA.label = node[above, pos=0.8] { \bbinfo{1} }

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{M U D B 6}}
    @line4.anchor = west

---

eDB => Edge
    @eDB.from = d
    @eDB.to = b
    @eDB.color = BBGreen
    &eDB.very thick
    &eDB.-latex
    %eDB.label = node[right, pos=0.8] { \bbinfo{6} }

---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{M B C D 2}}
    @line5.anchor = west

---

eCD => Edge
    @eCD.from = c
    @eCD.to = d
    @eCD.color = BBGreen
    &eCD.very thick
    &eCD.>=latex
    &eCD.<->
    %eCD.label = node[below right] { \bbinfo{2} }

---

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{A D}}
    @line6.anchor = west

---

+r
+arrow

    @r.x = 1.25
    @r.y = 2.0
    @r.text = \footnotesize \bbcomment{Prof. Shahriar}

    @arrow.x = 1.25
    @arrow.y = 2.25
    @arrow.u = 1.25
    @arrow.v = 3.25

---
-r
-arrow    
    @a.text = \footnotesize \textcolor{BBCyan}{\faUser}

---
+r
+arrow    
    @r.x = 1.65
    @r.y = 2.0
    @r.text = \footnotesize \bbcomment{Prof. Miguel}

    @arrow.x = 1.65
    @arrow.y = 2.25
    @arrow.u = 1.65
    @arrow.v = 3.25

---
-r
-arrow    

    @d.text = \footnotesize \textcolor{BBGreen}{\faUser}

---

    &eAB.dashed
    &eDB.dashed

---
+r
+arrow
    @r.x = 1.45
    @r.text = \bbinfo{10}

    @arrow.x = 1.45
    @arrow.u = 1.45
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
    @line1.text = \bbtext{\texttt{2} }
    @line1.anchor = west

---

a => Node
    @a.x = 7
    @a.y = 4
    @a.text = \bbtext{A}
    &a.draw
    &a.very thick
    &a.circle

b => Node
    @b.x = 10
    @b.y = 7
    @b.text = \bbtext{B}
    &b.draw
    &b.very thick
    &b.circle

c => Node
    @c.x = 13
    @c.y = 4
    @c.text = \bbtext{C}
    &c.draw
    &c.very thick
    &c.circle

d => Node
    @d.x = 10
    @d.y = 1
    @d.text = \bbtext{D}
    &d.draw
    &d.very thick
    &d.circle

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{Y U A B 10}}
    @line2.anchor = west

---

eAB => Edge
    @eAB.from = a
    @eAB.to = b
    @eAB.color = BBCyan
    &eAB.very thick
    &eAB.-latex
    %eAB.label = node[above left] { \bbinfo{10} }

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{M U C D 20}}
    @line3.anchor = west

---

eCD => Edge
    @eCD.from = c
    @eCD.to = d
    @eCD.color = BBGreen
    &eCD.very thick
    &eCD.-latex
    %eCD.label = node[above left] { \bbinfo{20} }

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{A D}}
    @line4.anchor = west

---

    @a.text = \footnotesize \textcolor{BBCyan}{\faUser}
    @d.text = \footnotesize \textcolor{BBGreen}{\faUser}

---

r => Node
    @r.x = 1.45
    @r.y = 3.0
    @r.text = \bbalert{x}

arrow => Edge
    @arrow.x = 1.45
    @arrow.y = 3.25
    @arrow.u = 1.45
    @arrow.v = 4.25
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

\inputsnippet{cpp}{9}{25}{codes/10171.cpp}

## Frame

\inputsnippet{cpp}{27}{44}{codes/10171.cpp}

## Frame

\inputsnippet{cpp}{46}{56}{codes/10171.cpp}

## End
