## Frame
\bbcover{OBI 2013 - Nível Júnior: Fase 1}{Tomadas}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbtext{A Olimpíada Internacional de Informática (IOI, no original em inglês) é a mais prestigiada competição de
programação para alunos de ensino médio; seus aproximadamente 300 competidores se reúnem em um país
diferente todo ano para os dois dias de prova da competição. Naturalmente, os competidores usamo o tempo
livre para acessar a Internet, programar e jogar em seus notebooks, mas eles se depararam com um problema:
o saguão do hotel só tem uma tomada.}

\vspace{0.2in}

\bbtext{Felizmente, os quatro competidores da equipe brasileira da IOI trouxeram cada um uma régua de tomadas,
permitindo assim ligar vários notebooks em uma tomada só; eles também podem ligar uma régua em outra
para aumentar ainda mais o número de tomadas disponíveis. No entanto, como as réguas têm muitas
tomadas, eles pediram para você escrever um programa que, dado o número de tomadas em cada régua,
determina quantas tomadas podem ser disponibilizadas no saguão do hotel.}

## Text

\bbbold{Entrada}

\vspace{0.2in}

\bbtext{A entrada consiste de uma linha com quatro inteiros positivos $T_1, T_2, T_3, T_4$, indicando o número de tomadas
de cada uma das quatro réguas.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.2in}

\bbtext{Seu programa deve imprimir uma única linha contendo um único número inteiro, indicando o número máximo
de notebooks que podem ser conectados num mesmo instante.}

\vspace{0.2in}

\bbbold{Restrições}
\vspace{-0.1in}

\bbtext{
\begin{itemize}
    \item $2\leq T_i\leq 6$
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
    @line1.text = \bbtext{\texttt{2 4 3 2} }
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
    @r.text = \footnotesize \bbcomment{\# de tomadas}

s => Node
    @s.x = 1.25
    @s.y = 4.25
    @s.text = \footnotesize \bbcomment{na régua $1$}


---
    @arrow.x = 1.65
    @arrow.u = 1.65

    !r
    @r.x = 1.65

    !s
    @s.x = 1.65
    @s.text = \footnotesize \bbcomment{na régua $2$}

---
    @arrow.x = 2.05
    @arrow.u = 2.05

    !r
    @r.x = 2.05

    !s
    @s.x = 2.05
    @s.text = \footnotesize \bbcomment{na régua $3$}
---
    @arrow.x = 2.45
    @arrow.u = 2.45

    !r
    @r.x = 2.45

    !s
    @s.x = 2.45
    @s.text = \footnotesize \bbcomment{na régua $4$}
---

-r
-s
-arrow

tomada1 => Path
   @tomada1.path = (1, 3.5) rectangle (2, 5) 
   &tomada1.thick
   &tomada1.rounded corners

tomada2 => Path
   @tomada2.path = (1.5, 4.25) circle (0.35)
   @tomada2.fill = yellow!50!white
   &tomada2.thick

tomada3 => Path
   @tomada3.path = (1.375, 4.1) to (1.375, 4.4)
   &tomada3.ultra thick
   &tomada3.rounded corners

tomada4 => Path
   @tomada4.path = (1.625, 4.1) to (1.625, 4.4)
   &tomada4.ultra thick
   &tomada4.rounded corners

---

regua1 => Path
   @regua1.path = (3, 3.75) rectangle (5, 4.75) 
   @regua1.fill = gray!10!white
   &regua1.very thick

r12 => Path
   @r12.path = (3.5, 4.25) circle (0.35)
   @r12.fill = gray!40!white
   &r12.thick

r13 => Path
   @r13.path = (3.375, 4.1) to (3.375, 4.4)
   &r13.ultra thick
   &r13.rounded corners

r14 => Path
   @r14.path = (3.625, 4.1) to (3.625, 4.4)
   &r14.ultra thick
   &r14.rounded corners

r22 => Path
   @r22.path = (4.5, 4.25) circle (0.35)
   @r22.fill = gray!40!white
   &r22.thick

r23 => Path
   @r23.path = (4.375, 4.1) to (4.375, 4.4)
   &r23.ultra thick
   &r23.rounded corners

r24 => Path
   @r24.path = (4.625, 4.1) to (4.625, 4.4)
   &r24.ultra thick
   &r24.rounded corners

---

wire1 => Path
   @wire1.path = (3, 4.25) to (1.8, 4.25)
   &wire1.ultra thick

    @tomada2.fill = black

---

regua2 => Path
   @regua2.path = (6, 3.75) rectangle (10, 4.75) 
   @regua2.fill = gray!10!white
   &regua2.very thick

r32 => Path
   @r32.path = (6.5, 4.25) circle (0.35)
   @r32.fill = gray!40!white
   &r32.thick

r33 => Path
   @r33.path = (6.375, 4.1) to (6.375, 4.4)
   &r33.ultra thick
   &r33.rounded corners

r34 => Path
   @r34.path = (6.625, 4.1) to (6.625, 4.4)
   &r34.ultra thick
   &r34.rounded corners

r42 => Path
   @r42.path = (7.5, 4.25) circle (0.35)
   @r42.fill = gray!40!white
   &r42.thick

r43 => Path
   @r43.path = (7.375, 4.1) to (7.375, 4.4)
   &r43.ultra thick
   &r43.rounded corners

r44 => Path
   @r44.path = (7.625, 4.1) to (7.625, 4.4)
   &r44.ultra thick
   &r44.rounded corners

r82 => Path
   @r82.path = (8.5, 4.25) circle (0.35)
   @r82.fill = gray!40!white
   &r82.thick

r83 => Path
   @r83.path = (8.375, 4.1) to (8.375, 4.4)
   &r83.ultra thick
   &r83.rounded corners

r84 => Path
   @r84.path = (8.625, 4.1) to (8.625, 4.4)
   &r84.ultra thick
   &r84.rounded corners

r92 => Path
   @r92.path = (9.5, 4.25) circle (0.35)
   @r92.fill = gray!40!white
   &r92.thick

r93 => Path
   @r93.path = (9.375, 4.1) to (9.375, 4.4)
   &r93.ultra thick
   &r93.rounded corners

r94 => Path
   @r94.path = (9.625, 4.1) to (9.625, 4.4)
   &r94.ultra thick
   &r94.rounded corners

---

wire2 => Path
   @wire2.path = (6, 4.25) to (4.8, 4.25)
   &wire2.ultra thick

    @r22.fill = black

---

regua3 => Path
   @regua3.path = (7, 1.75) rectangle (10, 2.75) 
   @regua3.fill = gray!10!white
   &regua3.very thick

ra2 => Path
   @ra2.path = (9.5, 2.25) circle (0.35)
   @ra2.fill = gray!40!white
   &ra2.thick

ra3 => Path
   @ra3.path = (9.375, 2.1) to (9.375, 2.4)
   &ra3.ultra thick
   &ra3.rounded corners

ra4 => Path
   @ra4.path = (9.625, 2.1) to (9.625, 2.4)
   &ra4.ultra thick
   &ra4.rounded corners

rb2 => Path
   @rb2.path = (8.5, 2.25) circle (0.35)
   @rb2.fill = gray!40!white
   &rb2.thick

rb3 => Path
   @rb3.path = (8.375, 2.1) to (8.375, 2.4)
   &rb3.ultra thick
   &rb3.rounded corners

rb4 => Path
   @rb4.path = (8.625, 2.1) to (8.625, 2.4)
   &rb4.ultra thick
   &rb4.rounded corners

rc2 => Path
   @rc2.path = (7.5, 2.25) circle (0.35)
   @rc2.fill = gray!40!white
   &rc2.thick

rc3 => Path
   @rc3.path = (7.375, 2.1) to (7.375, 2.4)
   &rc3.ultra thick
   &rc3.rounded corners

rc4 => Path
   @rc4.path = (7.625, 2.1) to (7.625, 2.4)
   &rc4.ultra thick
   &rc4.rounded corners

---

wire3 => Path
   @wire3.path = (10, 2.25) to (10.5, 2.25) to (10.5, 4.24) to (9.5, 4.25)
   &wire3.ultra thick
   &wire3.rounded corners

    @r92.fill = black

---

regua4 => Path
   @regua4.path = (4, 1.75) rectangle (6, 2.75) 
   @regua4.fill = gray!10!white
   &regua4.very thick

rd2 => Path
   @rd2.path = (5.5, 2.25) circle (0.35)
   @rd2.fill = gray!40!white
   &rd2.thick

rd3 => Path
   @rd3.path = (5.375, 2.1) to (5.375, 2.4)
   &rd3.ultra thick
   &rd3.rounded corners

rd4 => Path
   @rd4.path = (5.625, 2.1) to (5.625, 2.4)
   &rd4.ultra thick
   &rd4.rounded corners

re2 => Path
   @re2.path = (4.5, 2.25) circle (0.35)
   @re2.fill = gray!40!white
   &re2.thick

re3 => Path
   @re3.path = (4.375, 2.1) to (4.375, 2.4)
   &re3.ultra thick
   &re3.rounded corners

re4 => Path
   @re4.path = (4.625, 2.1) to (4.625, 2.4)
   &re4.ultra thick
   &re4.rounded corners

---

wire4 => Path
   @wire4.path = (6, 2.25) to (7.5, 2.25)
   &wire4.ultra thick

    @rc2.fill = black

---

+r
+arrow

    @arrow.x = 2.85
    @arrow.u = 4
    @arrow.y = 6
    @arrow.v = 6
    @arrow.color = BBBlack
    &arrow.-latex
    &arrow.thick

    @r.x = 4.25
    @r.y = 6
    @r.text = \footnotesize \bboutput{8}

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
    @a.text = $\star$ \bbtext{Inicialmente, há uma única tomada disponível $(T = 1)$}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{A primeira régua ocupa a tomada, porém acrescenta mais $T_1$ tomadas, de }
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.5
    @b1.text = \bbtext{modo que $T = 1 + (-1 + T_1) = T_1$}
    @b1.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{A segunda régua é ligada em uma tomada disponível e soma outras $T_2$. Agora}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3
    @c1.text = \bbtext{$T = T_1 - 1 + T_2 = T_1 + T_2 - 1$}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbtext{O mesmo para a terceira régua: $T = (T_1 + T_2 - 1) - 1 + T_3$}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1
    @e.text = $\star$ \bbtext{Por fim, para a quarta e última régua vale que}
    @e.anchor = west

e1 => Node
    @e1.x = 7
    @e1.y = 0.25
    @e1.text = $T = (T_1 + T_2 + T_3 - 2) - 1 + T_4 = T_1 + T_2 + T_3 + T_4 - 3$

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução $O(1)$ em C++}
    @title.anchor = west

line1 => Node
	@line1.x = 1
	@line1.y = 6.00
	@line1.text = \inputline{cpp}{1}{codes/solution.cpp}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 5.61
	@line2.text = \inputline{cpp}{2}{codes/solution.cpp}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 5.21
	@line3.text = \inputline{cpp}{3}{codes/solution.cpp}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 4.82
	@line4.text = \inputline{cpp}{4}{codes/solution.cpp}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 4.43
	@line5.text = \inputline{cpp}{5}{codes/solution.cpp}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 4.04
	@line6.text = \inputline{cpp}{6}{codes/solution.cpp}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 3.64
	@line7.text = \inputline{cpp}{7}{codes/solution.cpp}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 3.25
	@line8.text = \inputline{cpp}{8}{codes/solution.cpp}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 2.86
	@line9.text = \inputline{cpp}{9}{codes/solution.cpp}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 2.46
	@line10.text = \inputline{cpp}{10}{codes/solution.cpp}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 2.07
	@line11.text = \inputline{cpp}{11}{codes/solution.cpp}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 1.68
	@line12.text = \inputline{cpp}{12}{codes/solution.cpp}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 1.29
	@line13.text = \inputline{cpp}{13}{codes/solution.cpp}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 0.89
	@line14.text = \inputline{cpp}{14}{codes/solution.cpp}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = 0.50
	@line15.text = \inputline{cpp}{15}{codes/solution.cpp}
	@line15.anchor = west

-line7
-line8
-line10
-line12

---
    +line7

---
    +line8

---
    +line10

---
    +line12

## End
