## Frame
\bbcover{OBI 2013 - Nível Júnior: Fase 1}{Capital}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbtext{O governo do estado de Queensland está com problemas sérios de trânsito na capital Brisbane, onde estão
os prédios administrativos. Para desafogar o trânsito, o prefeito de Brisbane e o governador de Queensland
decidiram que uma nova capital administrativa deve ser construída em uma área fora de Brisbane. Para
projetar a nova capital, o renomado arquiteto minimalista Joe Bloggs foi contratado.}

\vspace{0.2in}

\bbtext{Bloggs foi informado de que o terreno destinado à nova capital ainda não foi demarcado, mas será retangular.
Além disso, a cidade deverá ser dividida em quatro zonas, uma delas destinada a uma reserva ambiental
e cada uma das outras três receberá os novos prédios de cada um dos três poderes (Executivo, Legislativo
e Judiciário). Em um arroubo de criatividade, Bloggs decidiu que duas avenidas, perpendiculares entre si,
cada uma paralela a dois dos lados do terreno retangular, dividirão a capital nas quatro zonas.}

## Text

\bbtext{Bloggs recebeu do governo as áreas de cada uma das zonas e, após muito esforço, encontrou um retângulo que
pode ser dividido conforme seus planos e de forma a respeitar as áreas delimitadas. No entanto, a Fundação
de Conservação dos Cangurus determinou que a área destinada à reserva ambiental era muito pequena, o
que obrigou o governo a alterar as áreas das quatro zonas. Após receber as novas medidas, Bloggs tentou
encontrar um novo retângulo que viabilizasse seu projeto, porém sem sucesso. Cansado de fazer testes,
ele pensou que talvez tenha que abandonar sua brilhante ideia. Por isso, ele pediu para você escrever um
programa que, dadas as áreas das quatro zonas, determine se ele poderá ou não manter seu projeto (ou seja,
se existe um retângulo que possa ser dividido por duas retas perpendiculares, cada uma paralela a dois dos
lados do retângulo, tal que as quatro áreas formadas obedeçam às exigências do governo).}

## Text

\bbbold{Entrada}

\vspace{0.2in}

\bbtext{A entrada consiste de uma única linha contendo quatro inteiros $A_1$, $A_2$, $A_3$, $A_4$, indicando a área de casa
uma das zonas.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.2in}

\bbtext{Imprima uma única linha contendo um único caractere: `\texttt{S}' se Bloggs pode preservar seu projeto e `\texttt{N}' caso
contrário.}

\vspace{0.2in}

\bbbold{Restrições}
\vspace{-0.1in}

\bbtext{
\begin{itemize}
    \item $1 \leq A_i \leq 10^4$
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
    @line1.text = \bbtext{\texttt{1 2 4 8}}
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
    @r.text = \footnotesize \bbcomment{$A_1$}

---
    @arrow.x = 1.625
    @arrow.u = 1.625

    !r
    @r.x = 1.625
    @r.text = \footnotesize \bbcomment{$A_2$}

---
    @arrow.x = 2.025
    @arrow.u = 2.025

    !r
    @r.x = 2.05
    @r.text = \footnotesize \bbcomment{$A_3$}

---
    @arrow.x = 2.425
    @arrow.u = 2.425

    !r
    @r.x = 2.45
    @r.text = \footnotesize \bbcomment{$A_4$}


a1 => Path
    @a1.path = (6, 2) rectangle (7, 3)
    @a1.color = cyan!40
    @a1.fill = cyan!40

a2 => Path
    @a2.path = (7, 2) rectangle (11, 3)
    @a2.color = green!30
    @a2.fill = green!30

a3 => Path
    @a3.path = (6, 3) rectangle (7, 5)
    @a3.color = red!30
    @a3.fill = red!30

a4 => Path
    @a4.path = (7, 3) rectangle (11, 5)
    @a4.color = orange!40
    @a4.fill = orange!40

-a1
-a2
-a3
-a4

---
-r
-arrow

rect => Path
    @rect.path = (6, 2) rectangle (11, 5)
    &rect.very thick

---

h => Path
    @h.path = (7, 2) to (7, 5)
    @h.color = gray
    &h.thick
    &h.dashed

b1 => Node
    @b1.text = $1$
    @b1.x = 6.5
    @b1.y = 1.65

b2 => Node
    @b2.text = $4$
    @b2.x = 9
    @b2.y = 1.65

---

b => Path
    @b.path = (6, 3) to (11, 3)
    @b.color = gray
    &b.thick
    &b.dashed

h1 => Node
    @h1.text = $1$
    @h1.x = 5.65
    @h1.y = 2.5

h2 => Node
    @h2.text = $2$
    @h2.x = 5.65
    @h2.y = 4

---
+a1

a1_label => Node
    @a1_label.text = $A_1$
    @a1_label.x = 6.5
    @a1_label.y = 2.5
---
+a3

a2_label => Node
    @a2_label.text = $A_2$
    @a2_label.x = 6.5
    @a2_label.y = 4

---
+a2

a3_label => Node
    @a3_label.text = $A_3$
    @a3_label.x = 9
    @a3_label.y = 2.5

---
+a4

a4_label => Node
    @a4_label.text = $A_4$
    @a4_label.x = 9
    @a4_label.y = 4

---
+r
+arrow

    @arrow.x = 2.75
    @arrow.u = 3.75
    @arrow.y = 6
    @arrow.v = 6

    @r.x = 4
    @r.y = 6
    @r.text = \footnotesize \bboutput{S}



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
    @a.text = \bbtext{Considere que exista um retângulo de base $b$ e altura $h$}
    @a.anchor = west

---

r => Path
    @r.path = (1, 1) rectangle (9, 5)
    &r.very thick

b => Node
    @b.x = 5
    @b.y = 0.6
    @b.text = $b$

h => Node
    @h.x = 0.65
    @h.y = 3
    @h.text = $h$

---
    @a.text = \bbtext{Façamos um corte paralelo à altura, dividindo o retângulo em duas partes}
---

hline => Path
    @hline.path = (4, 1) to (4, 5)
    @hline.color = gray
    &hline.dashed
    
    @b.x = 2.5
    @b.text = $b_1$

b2 => Node
    @b2.x = 6.5
    @b2.y = 0.6
    @b2.text = $b_2$

---
    @a.text = \bbtext{Um novo corte, paralelo à base, divide o retângulo em quatro partes}

---

bline => Path
    @bline.path = (1, 3) to (9, 3)
    @bline.color = gray
    &bline.dashed
    
    @h.text = $h_1$
    @h.y = 2

h2 => Node
    @h2.x = 0.65
    @h2.y = 4
    @h2.text = $h_2$

---
    @a.text = \bbtext{Suponha que esta divisão tenha gerado partes com áreas $A_1, A_2, A_3$ e $A_4$}

---

a1 => Node
    @a1.text = $A_1$
    @a1.x = 2.5
    @a1.y = 2

a2 => Node
    @a2.text = $A_2$
    @a2.x = 6.5
    @a2.y = 2

a3 => Node
    @a3.text = $A_3$
    @a3.x = 2.5
    @a3.y = 4

a4 => Node
    @a4.text = $A_4$
    @a4.x = 6.5
    @a4.y = 4

---
    @a.text = \bbtext{Em relação às áreas $A_1$ e $A_2$, observe que}

---

eq1 => Node
    @eq1.text = $A_1 = b_1h_1$
    @eq1.x = 10
    @eq1.y = 5
    @eq1.anchor = west

---

eq2 => Node
    @eq2.text = $A_2 = b_2h_1$
    @eq2.x = 10
    @eq2.y = 4.25
    @eq2.anchor = west

---

eq3 => Node
    @eq3.text = $\dfrac{A_1}{A_2} = \dfrac{b_1}{b_2}$
    @eq3.x = 10
    @eq3.y = 3
    @eq3.anchor = west

---
    @a.text = \bbtext{De forma semelhante, para $A_3$ e $A_4$ temos que}

---
eq4 => Node
    @eq4.text = $A_3 = b_1h_2$
    @eq4.x = 10
    @eq4.y = 1.75
    @eq4.anchor = west

---

eq5 => Node
    @eq5.text = $A_4 = b_2h_2$
    @eq5.x = 10
    @eq5.y = 1
    @eq5.anchor = west

---
    @eq3.text = $\dfrac{A_1}{A_2} = \dfrac{b_1}{b_2} = \dfrac{A_3}{A_4}$

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{A relação entre as áreas pode ser expressa como $A_1A_4 = A_2A_3$}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Esta relação permite identificar se é possível ou não construir o retângulo desejado}
    @b.anchor = west

---
c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{A partir dela, e usando a relação entre as áreas no sentido vertical, é possivel}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.5
    @c1.text =\bbtext{determinar os valores de $b_1, b_2, h_1$ e $h_2$}
    @c1.anchor = west

---
d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{O problema, contudo, não demanda o cálculo destas dimensões}
    @d.anchor = west

---
e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $\star$ \bbtext{A construção feita para encontrar a relação não estabeleceu relação de ordem entre}
    @e.anchor = west

e1 => Node
    @e1.x = 0.5
    @e1.y = 1
    @e1.text = \bbtext{as áreas $A_1, A_2, A_3, A_4$}
    @e1.anchor = west

---

f => Node
    @f.x = 1
    @f.y = 0
    @f.text = $\star$ \bbtext{Logo é preciso checar todas as 3 possibilidades (mantendo $A_1$ fixo à esquerda)}
    @f.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução $O(1)$ em C++}
    @title.anchor = west

---

line1 => Node
	@line1.x = 1
	@line1.y = 6.00
	@line1.text = \inputline{cpp}{1}{codes/solution.cpp}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 5.60
	@line2.text = \inputline{cpp}{2}{codes/solution.cpp}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 5.20
	@line3.text = \inputline{cpp}{3}{codes/solution.cpp}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 4.80
	@line4.text = \inputline{cpp}{4}{codes/solution.cpp}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 4.40
	@line5.text = \inputline{cpp}{5}{codes/solution.cpp}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 4.00
	@line6.text = \inputline{cpp}{6}{codes/solution.cpp}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 3.60
	@line7.text = \inputline{cpp}{7}{codes/solution.cpp}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 3.20
	@line8.text = \inputline{cpp}{8}{codes/solution.cpp}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 2.80
	@line9.text = \inputline{cpp}{9}{codes/solution.cpp}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 2.40
	@line10.text = \inputline{cpp}{10}{codes/solution.cpp}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 2.00
	@line11.text = \inputline{cpp}{11}{codes/solution.cpp}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 1.60
	@line12.text = \inputline{cpp}{12}{codes/solution.cpp}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 1.20
	@line13.text = \inputline{cpp}{13}{codes/solution.cpp}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 0.80
	@line14.text = \inputline{cpp}{14}{codes/solution.cpp}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = 0.40
	@line15.text = \inputline{cpp}{15}{codes/solution.cpp}
	@line15.anchor = west

line16 => Node
	@line16.x = 1
	@line16.y = -0.00
	@line16.text = \inputline{cpp}{16}{codes/solution.cpp}
	@line16.anchor = west

-line7
-line8
-line10
-line11
-line12
-line13

---
+line7

---
+line8

---
+line10
+line11

---
+line12
+line13

## End
