## Frame
\bbcover{OBI 2008 - Nível 2: Fase 1}{Telefone}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbtext{As primeiras redes públicas de telefonia foram construídas pela AT\&T; no começo do século XX. Elas permitiam que seus assinantes conversassem com a ajuda de uma telefonista, que conectava as linhas dos assinantes com um cabo especial.}

\vspace{0.1in}

\bbtext{Essas redes evoluíram muito desde então, com a ajuda de vários avanços tecnológicos. Hoje em dia, essas redes atendem centenas de milhões de assinantes; ao invés de falar diretamente com uma telefonista, você pode simplesmente discar o número da pessoa desejada no telefone.}

\vspace{0.1in}

\bbtext{Cada assinante recebe um número de telefone -- por exemplo, 55-98-234-5678. Qualquer pessoa que discar esse número consegue então falar com a pessoa do outro lado da linha. Os hifens no número de telefone são só para facilitar a leitura, e não são discados no telefone.}

\vspace{0.1in}

\bbtext{Para que fique mais fácil de se lembrar de um número de telefone, muitas companhias divulgam números que contém letras no lugar de dígitos. Para convertê-los de volta para dígitos, a maioria dos telefones tem letras nas suas teclas:}

## Text

\begin{center}
    \includegraphics[scale=0.8]{telefone.png}
\end{center}

\bbtext{Ao invés de discar uma letra, disca-se a tecla que contém aquela letra. Por exemplo, se você quiser discar o número 0800-FALE-SBC, você na realidade discaria 0800-3253-722.}

\vspace{0.1in}

\bbtext{A sua avó tem reclamado de problemas de vista -- em particular, ela não consegue mais enxergar as letrinhas nas teclas do telefone, e por isso queria que você fizesse um programa que convertesse as letras em um número de telefone para dígitos.}

## Text

\bbbold{Entrada}

\vspace{0.2in}

\bbtext{A entrada contém um único conjunto de testes, que deve ser lido do \textit{dispositivo de entrada padrão} (normalmente
o teclado). A entrada é composta de apenas uma linha, contendo o número de telefone que deve ser traduzido.
O número de telefone contém entre 1 e 15 caracteres, que podem ser dígitos e `\texttt{0}' a `\texttt{9}', letras de `\texttt{A}' a `\texttt{Y}' e hífens
(`\texttt{-}').}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.2in}

\bbtext{Seu programa deve imprimir, na saída padrão, uma única linha, contendo o número de telefone com as letras
convertidas para dígitos. Hífens no número telefone devem ser mantidos no número de telefone de saída.}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{M1S-TU-R4} }
    @line1.anchor = west

---

arrow => Edge
    &arrow.->
    @arrow.x = 2.15
    @arrow.y = 5.00
    @arrow.u = 2.15
    @arrow.v = 5.75
    @arrow.color = BBViolet

r => Node
    @r.x = 2.75
    @r.y = 4.75
    @r.text = \footnotesize \bbcomment{Telefone com letras, números e hífens}

---
-r
-arrow

line2 => Node
    @line2.x = 7
    @line2.y = 4.0
    @line2.text = \bbtext{\Huge \texttt{M1S-TU-R4}}

---
+r
+arrow

    @arrow.x = 5.15
    @arrow.u = 5.15
    @arrow.y = 3.6
    @arrow.v = 2.85
    @arrow.color = BBBlack
    &arrow.-latex
    &arrow.thick

    @r.x = 5.15
    @r.y = 2.5
    @r.text = \bboutput{6}

---
    @arrow.x = 6.05
    @arrow.u = 6.05
    @r.x = 6.05
    @r.text = \bboutput{7}

---
    @arrow.x = 6.975
    @arrow.u = 6.975
    @r.x = 6.975
    @r.text = \bboutput{8}

---
    @arrow.x = 7.425
    @arrow.u = 7.425
    @r.x = 7.425
 
---
    @arrow.x = 8.35
    @arrow.u = 8.35
    @r.x = 8.35
    @r.text = \bboutput{7}
 
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
    @a.text = $\star$ \bbtext{Como o número de caracteres $N$ não é dado na entrada, o telefone deve ser}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 6
    @a1.text = \bbtext{lido como uma string}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{A função \code{c}{strlen()} pode ser usada para computar o valor de $N$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{O problema consiste em substituir os caracteres alfabéticos pelos equivalentes}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.5
    @c1.text = \bbtext{numéricos}
    @c1.anchor = west


---

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{Os demais caracteres devem permanecer inalterados}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $\star$ \bbtext{Os equivalentes numéricos podem ser determinados por uma série de \code{c}{if}/\code{c}{else}}
    @e.anchor = west

e1 => Node
    @e1.x = 0.5
    @e1.y = 1
    @e1.text = \bbtext{em cascata}
    @e1.anchor = west

## Scene

line1 => Node
	@line1.x = 1
	@line1.y = 8.00
	@line1.text = \inputsmallline{c}{1}{codes/solution.c}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 7.62
	@line2.text = \inputsmallline{c}{2}{codes/solution.c}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 7.24
	@line3.text = \inputsmallline{c}{3}{codes/solution.c}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 6.86
	@line4.text = \inputsmallline{c}{4}{codes/solution.c}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 6.48
	@line5.text = \inputsmallline{c}{5}{codes/solution.c}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 6.10
	@line6.text = \inputsmallline{c}{6}{codes/solution.c}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 5.71
	@line7.text = \inputsmallline{c}{7}{codes/solution.c}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 5.33
	@line8.text = \inputsmallline{c}{8}{codes/solution.c}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 4.95
	@line9.text = \inputsmallline{c}{9}{codes/solution.c}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 4.57
	@line10.text = \inputsmallline{c}{10}{codes/solution.c}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 4.19
	@line11.text = \inputsmallline{c}{11}{codes/solution.c}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 3.81
	@line12.text = \inputsmallline{c}{12}{codes/solution.c}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 3.43
	@line13.text = \inputsmallline{c}{13}{codes/solution.c}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 3.05
	@line14.text = \inputsmallline{c}{14}{codes/solution.c}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = 2.67
	@line15.text = \inputsmallline{c}{15}{codes/solution.c}
	@line15.anchor = west

line16 => Node
	@line16.x = 1
	@line16.y = 2.29
	@line16.text = \inputsmallline{c}{16}{codes/solution.c}
	@line16.anchor = west

line17 => Node
	@line17.x = 1
	@line17.y = 1.90
	@line17.text = \inputsmallline{c}{17}{codes/solution.c}
	@line17.anchor = west

line18 => Node
	@line18.x = 1
	@line18.y = 1.52
	@line18.text = \inputsmallline{c}{18}{codes/solution.c}
	@line18.anchor = west

line19 => Node
	@line19.x = 1
	@line19.y = 1.14
	@line19.text = \inputsmallline{c}{19}{codes/solution.c}
	@line19.anchor = west

line20 => Node
	@line20.x = 1
	@line20.y = 0.76
	@line20.text = \inputsmallline{c}{20}{codes/solution.c}
	@line20.anchor = west

line21 => Node
	@line21.x = 1
	@line21.y = 0.38
	@line21.text = \inputsmallline{c}{21}{codes/solution.c}
	@line21.anchor = west

line22 => Node
	@line22.x = 1
	@line22.y = -0.00
	@line22.text = \inputsmallline{c}{22}{codes/solution.c}
	@line22.anchor = west

vbar => Path
@vbar.path = (7.5, 8) -- (7.5, 0) -- cycle
@vbar.color = gray
&vbar.dashed
line23 => Node
	@line23.x = 8
	@line23.y = 7.62
	@line23.text = \inputsmallline{c}{23}{codes/solution.c}
	@line23.anchor = west

line24 => Node
	@line24.x = 8
	@line24.y = 7.24
	@line24.text = \inputsmallline{c}{24}{codes/solution.c}
	@line24.anchor = west

line25 => Node
	@line25.x = 8
	@line25.y = 6.86
	@line25.text = \inputsmallline{c}{25}{codes/solution.c}
	@line25.anchor = west

line26 => Node
	@line26.x = 8
	@line26.y = 6.48
	@line26.text = \inputsmallline{c}{26}{codes/solution.c}
	@line26.anchor = west

line27 => Node
	@line27.x = 8
	@line27.y = 6.10
	@line27.text = \inputsmallline{c}{27}{codes/solution.c}
	@line27.anchor = west

line28 => Node
	@line28.x = 8
	@line28.y = 5.71
	@line28.text = \inputsmallline{c}{28}{codes/solution.c}
	@line28.anchor = west

line29 => Node
	@line29.x = 8
	@line29.y = 5.33
	@line29.text = \inputsmallline{c}{29}{codes/solution.c}
	@line29.anchor = west

line30 => Node
	@line30.x = 8
	@line30.y = 4.95
	@line30.text = \inputsmallline{c}{30}{codes/solution.c}
	@line30.anchor = west

line31 => Node
	@line31.x = 8
	@line31.y = 4.57
	@line31.text = \inputsmallline{c}{31}{codes/solution.c}
	@line31.anchor = west

line32 => Node
	@line32.x = 8
	@line32.y = 4.19
	@line32.text = \inputsmallline{c}{32}{codes/solution.c}
	@line32.anchor = west

line33 => Node
	@line33.x = 8
	@line33.y = 3.81
	@line33.text = \inputsmallline{c}{33}{codes/solution.c}
	@line33.anchor = west

line34 => Node
	@line34.x = 8
	@line34.y = 3.43
	@line34.text = \inputsmallline{c}{34}{codes/solution.c}
	@line34.anchor = west

-line2
-line3
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

---

+line6
+line7

---

+line2
+line9

---

+line11
+line12
+line29

---

+line13
+line14

---

+line15
+line16

---

+line17
+line18
+line19
+line20
+line21
+line22
+line23
+line24
+line25
+line26
+line27
+line28

---

+line31


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
    @b.text = $\star$ \bbtext{Ela é baseada no código que um caractere ocupa na tabela ASCII e um vetor}
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.5
    @b1.text = \bbtext{auxiliar}
    @b1.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{As letras estão em ordem crescente na tabela ASCII}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{Assim a posição da letra \code{c}{c} no alfabeto pode ser obtida pela diferença \code{c}{(c - 'A')}}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $\star$ \bbtext{O vetor auxiliar \code{c}{keyboard} guarda, na $i$-ésima posição, o número correspondente}
    @e.anchor = west

e1 => Node
    @e1.x = 0.5
    @e1.y = 1
    @e1.text = \bbtext{à $i$-ésima letra maiúscula no teclado do telefone.}
    @e1.anchor = west

## Scene

line1 => Node
	@line1.x = 1
	@line1.y = 8.00
	@line1.text = \inputline{c}{1}{codes/solution2.c}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 7.60
	@line2.text = \inputline{c}{2}{codes/solution2.c}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 7.20
	@line3.text = \inputline{c}{3}{codes/solution2.c}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 6.80
	@line4.text = \inputline{c}{4}{codes/solution2.c}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 6.40
	@line5.text = \inputline{c}{5}{codes/solution2.c}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 6.00
	@line6.text = \inputline{c}{6}{codes/solution2.c}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 5.60
	@line7.text = \inputline{c}{7}{codes/solution2.c}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 5.20
	@line8.text = \inputline{c}{8}{codes/solution2.c}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 4.80
	@line9.text = \inputline{c}{9}{codes/solution2.c}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 4.40
	@line10.text = \inputline{c}{10}{codes/solution2.c}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 4.00
	@line11.text = \inputline{c}{11}{codes/solution2.c}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 3.60
	@line12.text = \inputline{c}{12}{codes/solution2.c}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 3.20
	@line13.text = \inputline{c}{13}{codes/solution2.c}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 2.80
	@line14.text = \inputline{c}{14}{codes/solution2.c}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = 2.40
	@line15.text = \inputline{c}{15}{codes/solution2.c}
	@line15.anchor = west

line16 => Node
	@line16.x = 1
	@line16.y = 2.00
	@line16.text = \inputline{c}{16}{codes/solution2.c}
	@line16.anchor = west

line17 => Node
	@line17.x = 1
	@line17.y = 1.60
	@line17.text = \inputline{c}{17}{codes/solution2.c}
	@line17.anchor = west

line18 => Node
	@line18.x = 1
	@line18.y = 1.20
	@line18.text = \inputline{c}{18}{codes/solution2.c}
	@line18.anchor = west

line19 => Node
	@line19.x = 1
	@line19.y = 0.80
	@line19.text = \inputline{c}{19}{codes/solution2.c}
	@line19.anchor = west

line20 => Node
	@line20.x = 1
	@line20.y = 0.40
	@line20.text = \inputline{c}{20}{codes/solution2.c}
	@line20.anchor = west

line21 => Node
	@line21.x = 1
	@line21.y = -0.00
	@line21.text = \inputline{c}{21}{codes/solution2.c}
	@line21.anchor = west

-line2
-line4
-line9
-line11
-line12
-line13
-line14
-line15
-line16
-line17
-line18
-line19

---

+line12

---

+line14

---

+line2
+line15
+line16

---

+line18


## End
