## Frame
\bbcover{OBI 2024 - Nível 2: Fase 1}{Concurso}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbtext{Cláudia trabalha na OBI (Organização dos Bons Informáticos), que recentemente realizou um concurso para contratar novos funcionários. Agora, Cláudia tem a tarefa de determinar a \bbenglish{nota de corte} para o concurso. Chamamos de nota de corte a nota mínima necessária para ser aprovado no concurso. Ou seja, se a nota de corte do concurso for $C$, então todos os participantes com uma nota maior ou igual a $C$ serão aprovados no concurso e todos com nota menor que $C$ serão reprovados.}

\vspace{0.2in}

\bbtext{Seu chefe pediu para que Cláudia aprove no mínimo $K$ candidatos do concurso para a próxima fase,
mas ela também não quer que a nota de corte seja muito baixa. Por isso, Cláudia decidiu que a
nota de corte deverá ser a maior nota $C$ que faz com que no mínimo $K$ candidatos sejam aprovados.}

\vspace{0.2in}

\bbtext{Sua tarefa é: dados o número $N$ de candidatos, as notas $A_1, A_2, \ldots, A_N$ dos candidatos e a quantidade
mínima de aprovados $K$, diga qual deve ser a maior nota de corte $C$ para que pelo menos $K$
candidatos sejam aprovados.}

## Text

\bbbold{Entrada}

\vspace{0.2in}

\bbtext{A primeira linha da entrada contém dois inteiros, $N$ e $K$, representando, respectivamente, o número
de participantes e o número mínimo de candidatos que devem ser aprovados.}

\vspace{0.1in}

\bbtext{A segunda linha da entrada contém $N$ inteiros $A_i$, representando as notas dos participantes.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.2in}

\bbtext{Seu programa deve imprimir uma linha contendo um único inteiro $C$, a nota de corte que deve ser escolhida por Cláudia.}

\vspace{0.2in}

\bbbold{Restrições}
\vspace{-0.1in}

\bbtext{
\begin{itemize}
    \item $1\leq K\leq N\leq 500$
    \item $1\leq A_i\leq 100$ para todo $1\leq i\leq N$
\end{itemize}
}
## Text

\bbbold{Informações sobre a pontuação}

\vspace{0.2in}

\bbtext{A tarefa vale 100 pontos. Estes pontos estão distribuídos em subtarefas, cada uma com suas
\bbbold{restrições adicionais} às definidas acima.}

\vspace{0.2in}

\begin{itemize}
    \item \bbbold{Subtarefa 1 (0 pontos):} \bbtext{Esta subtarefa é composta apenas pelos exemplos mostrados abaixo. Ela não vale pontos, serve apenas para que você verifique se o seu programa imprime o resultado correto para os exemplos.}
    \item \bbbold{Subtarefa 2 (20 pontos):} $K = 1$\bbtext{.}
    \item \bbbold{Subtarefa 3 (20 pontos):} $K = 3$\bbtext{.}
    \item \bbbold{Subtarefa 4 (20 pontos):} $A_i \leq 2$\bbtext{.}
    \item \bbbold{Subtarefa 5 (40 pontos):} \bbtext{Sem restrições adicionais.}
\end{itemize}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{3 1} }
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
    @r.text = \footnotesize \bbcomment{\# de candidatos}
    @r.anchor = west

---
    @arrow.x = 1.65
    @arrow.u = 1.65

    !r
    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{\# de aprovados}

---

-r
-arrow

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{92 83 98}}
    @line2.anchor = west

---

+r
+arrow

    @r.x = 1.25
    @r.y = 4.25
    @r.text = \footnotesize \bbcomment{Nota do candidato 1}

    @arrow.x = 1.25
    @arrow.y = 4.5
    @arrow.u = 1.25
    @arrow.v = 5.25

---

    @r.x = 1.85
    @r.text = \footnotesize \bbcomment{Nota do candidato 2}

    @arrow.x = 1.85
    @arrow.u = 1.85

---

    @r.x = 2.45
    @r.text = \footnotesize \bbcomment{Nota do candidato 3}

    @arrow.x = 2.45
    @arrow.u = 2.45

---

-r
-arrow

node1 => Node
    @node1.x = 5
    @node1.y = 3
    @node1.text = \bbtext{\texttt{92}}
    &node1.draw
    &node1.very thick
    &node1.circle

node2 => Node
    @node2.x = 8
    @node2.y = 3
    @node2.text = \bbtext{\texttt{83}}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 11
    @node3.y = 3
    @node3.text = \bbtext{\texttt{98}}
    &node3.draw
    &node3.very thick
    &node3.circle

---

nodeC => Node
    @nodeC.x = 7
    @nodeC.y = 5
    @nodeC.text = \bbtext{$C = 70$}
    @nodeC.anchor = west

---
    @node1.fill = BBCyan
    @node2.fill = BBCyan
    @node3.fill = BBCyan

---
    @nodeC.text = \bbtext{$C = 99$}
    @node1.fill = BBWhite
    @node2.fill = BBWhite
    @node3.fill = BBWhite


---
    @node1.fill = BBRed
    @node2.fill = BBRed
    @node3.fill = BBRed

---
    @nodeC.text = \bbtext{$C = 90$}
    @node1.fill = BBWhite
    @node2.fill = BBWhite
    @node3.fill = BBWhite


---
    @node1.fill = BBCyan
    @node2.fill = BBRed
    @node3.fill = BBCyan

---
    @nodeC.text = \bbtext{$C = 98$}
    @node1.fill = BBWhite
    @node2.fill = BBWhite
    @node3.fill = BBWhite


---
    @node1.fill = BBRed
    @node2.fill = BBRed
    @node3.fill = BBCyan

---

+r
+arrow

    @arrow.x = 1.85
    @arrow.u = 1.85
    @arrow.y = 4.75
    @arrow.v = 3.75
    @arrow.color = BBBlack
    &arrow.-latex
    &arrow.thick

    @r.x = 1.85
    @r.y = 3.5
    @r.text = \footnotesize \bboutput{98}



## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução: Subtarefa 2 ($K = 1$)}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Nesta subtarefa, pelo menos um candidato deve ser aprovado}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Seja $M$ a maior nota obtida entre todos os candidatos}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{Se a nota de corte for igual a $M$, ao menos o candidato que obteve $M$ será}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.5
    @c1.text = \bbtext{aprovado}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{Se a nota de corte for maior que $M$, ninguém será aprovado}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $\star$ \bbtext{Portanto, para esta subtarefa a resposta é a maior nota obtida entre todos os}
    @e.anchor = west

e1 => Node
    @e1.x = 0.5
    @e1.y = 1.0
    @e1.text = \bbtext{candidatos}
    @e1.anchor = west

## Scene

line1 => Node
	@line1.x = 1
	@line1.y = 8.00
	@line1.text = \inputline{c}{1}{codes/sub2.c}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 7.62
	@line2.text = \inputline{c}{2}{codes/sub2.c}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 7.24
	@line3.text = \inputline{c}{3}{codes/sub2.c}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 6.86
	@line4.text = \inputline{c}{4}{codes/sub2.c}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 6.48
	@line5.text = \inputline{c}{5}{codes/sub2.c}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 6.10
	@line6.text = \inputline{c}{6}{codes/sub2.c}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 5.71
	@line7.text = \inputline{c}{7}{codes/sub2.c}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 5.33
	@line8.text = \inputline{c}{8}{codes/sub2.c}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 4.95
	@line9.text = \inputline{c}{9}{codes/sub2.c}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 4.57
	@line10.text = \inputline{c}{10}{codes/sub2.c}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 4.19
	@line11.text = \inputline{c}{11}{codes/sub2.c}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 3.81
	@line12.text = \inputline{c}{12}{codes/sub2.c}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 3.43
	@line13.text = \inputline{c}{13}{codes/sub2.c}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 3.05
	@line14.text = \inputline{c}{14}{codes/sub2.c}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = 2.67
	@line15.text = \inputline{c}{15}{codes/sub2.c}
	@line15.anchor = west

line16 => Node
	@line16.x = 1
	@line16.y = 2.29
	@line16.text = \inputline{c}{16}{codes/sub2.c}
	@line16.anchor = west

line17 => Node
	@line17.x = 1
	@line17.y = 1.90
	@line17.text = \inputline{c}{17}{codes/sub2.c}
	@line17.anchor = west

line18 => Node
	@line18.x = 1
	@line18.y = 1.52
	@line18.text = \inputline{c}{18}{codes/sub2.c}
	@line18.anchor = west

line19 => Node
	@line19.x = 1
	@line19.y = 1.14
	@line19.text = \inputline{c}{19}{codes/sub2.c}
	@line19.anchor = west

line20 => Node
	@line20.x = 1
	@line20.y = 0.76
	@line20.text = \inputline{c}{20}{codes/sub2.c}
	@line20.anchor = west

line21 => Node
	@line21.x = 1
	@line21.y = 0.38
	@line21.text = \inputline{c}{21}{codes/sub2.c}
	@line21.anchor = west

line22 => Node
	@line22.x = 1
	@line22.y = -0.00
	@line22.text = \inputline{c}{22}{codes/sub2.c}
	@line22.anchor = west

-line5
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

---

+line5
+line6

---

+line8

---

+line10
+line11
+line17

---
+line12
+line13

---
+line15
+line16

---
+line19

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução: Subtarefa 4 ($A_i \leq 2$)}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Nesta subtarefa, todos candidatos tiraram ou nota 1 ou nota 2}
    @a.anchor = west
---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Só há duas alternativas para a nota de corte: $C = 1$ e $C = 2$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{Se a nota de corte for igual a $1$, todos serão aprovados}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $\star$ \bbtext{Se a nota de corte for igual a $2$, apenas os candidatos que tiraram 2 serão}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 2.5
    @d1.text = \bbtext{aprovados}
    @d1.anchor = west


---

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $\star$ \bbtext{Portanto, a resposta só será $2$ quanto o número de candidatos que tiraram 2 for}
    @e.anchor = west

e1 => Node
    @e1.x = 0.5
    @e1.y = 1
    @e1.text = \bbtext{maior ou igual a $K$; caso contrário, a resposta é igual a 1}
    @e1.anchor = west

## Scene

line1 => Node
	@line1.x = 1
	@line1.y = 8.00
	@line1.text = \inputline{c}{1}{codes/sub4.c}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 7.62
	@line2.text = \inputline{c}{2}{codes/sub4.c}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 7.24
	@line3.text = \inputline{c}{3}{codes/sub4.c}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 6.86
	@line4.text = \inputline{c}{4}{codes/sub4.c}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 6.48
	@line5.text = \inputline{c}{5}{codes/sub4.c}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 6.10
	@line6.text = \inputline{c}{6}{codes/sub4.c}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 5.71
	@line7.text = \inputline{c}{7}{codes/sub4.c}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 5.33
	@line8.text = \inputline{c}{8}{codes/sub4.c}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 4.95
	@line9.text = \inputline{c}{9}{codes/sub4.c}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 4.57
	@line10.text = \inputline{c}{10}{codes/sub4.c}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 4.19
	@line11.text = \inputline{c}{11}{codes/sub4.c}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 3.81
	@line12.text = \inputline{c}{12}{codes/sub4.c}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 3.43
	@line13.text = \inputline{c}{13}{codes/sub4.c}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 3.05
	@line14.text = \inputline{c}{14}{codes/sub4.c}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = 2.67
	@line15.text = \inputline{c}{15}{codes/sub4.c}
	@line15.anchor = west

line16 => Node
	@line16.x = 1
	@line16.y = 2.29
	@line16.text = \inputline{c}{16}{codes/sub4.c}
	@line16.anchor = west

line17 => Node
	@line17.x = 1
	@line17.y = 1.90
	@line17.text = \inputline{c}{17}{codes/sub4.c}
	@line17.anchor = west

line18 => Node
	@line18.x = 1
	@line18.y = 1.52
	@line18.text = \inputline{c}{18}{codes/sub4.c}
	@line18.anchor = west

line19 => Node
	@line19.x = 1
	@line19.y = 1.14
	@line19.text = \inputline{c}{19}{codes/sub4.c}
	@line19.anchor = west

line20 => Node
	@line20.x = 1
	@line20.y = 0.76
	@line20.text = \inputline{c}{20}{codes/sub4.c}
	@line20.anchor = west

line21 => Node
	@line21.x = 1
	@line21.y = 0.38
	@line21.text = \inputline{c}{21}{codes/sub4.c}
	@line21.anchor = west

line22 => Node
	@line22.x = 1
	@line22.y = -0.00
	@line22.text = \inputline{c}{22}{codes/sub4.c}
	@line22.anchor = west

-line5
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

---

+line5
+line6

---

+line8

---

+line10
+line11
+line17

---
+line12
+line13

---
+line15
+line16

---
+line19

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução: Subtarefa 3 ($K = 3$)}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Nesta subtarefa deve ser classificados, no mínimo, 3 candidatos}
    @a.anchor = west
---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Na Subtarefa 2 a resposta era a nota do primeiro classificado}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{Nesta subtarefa, a resposta será a nota do terceiro colocado no concurso}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $\star$ \bbtext{Para determinar esta nota, é preciso manter o registro das três maiores notas }
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 2.5
    @d1.text = \bbtext{observadas até o momento}
    @d1.anchor = west


---

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $\star$ \bbtext{A cada iteração do laço, as variáveis $x, y$ e $z$ serão atualizadas para que representem }
    @e.anchor = west

e1 => Node
    @e1.x = 0.5
    @e1.y = 1
    @e1.text = \bbtext{a terceira, a segunda e a primeira melhor nota, respectivamente}
    @e1.anchor = west

## Scene

line1 => Node
	@line1.x = 1
	@line1.y = 8.00
	@line1.text = \inputline{c}{1}{codes/sub3.c}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 7.62
	@line2.text = \inputline{c}{2}{codes/sub3.c}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 7.24
	@line3.text = \inputline{c}{3}{codes/sub3.c}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 6.86
	@line4.text = \inputline{c}{4}{codes/sub3.c}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 6.48
	@line5.text = \inputline{c}{5}{codes/sub3.c}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 6.10
	@line6.text = \inputline{c}{6}{codes/sub3.c}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 5.71
	@line7.text = \inputline{c}{7}{codes/sub3.c}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 5.33
	@line8.text = \inputline{c}{8}{codes/sub3.c}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 4.95
	@line9.text = \inputline{c}{9}{codes/sub3.c}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 4.57
	@line10.text = \inputline{c}{10}{codes/sub3.c}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 4.19
	@line11.text = \inputline{c}{11}{codes/sub3.c}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 3.81
	@line12.text = \inputline{c}{12}{codes/sub3.c}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 3.43
	@line13.text = \inputline{c}{13}{codes/sub3.c}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 3.05
	@line14.text = \inputline{c}{14}{codes/sub3.c}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = 2.67
	@line15.text = \inputline{c}{15}{codes/sub3.c}
	@line15.anchor = west

line16 => Node
	@line16.x = 1
	@line16.y = 2.29
	@line16.text = \inputline{c}{16}{codes/sub3.c}
	@line16.anchor = west

line17 => Node
	@line17.x = 1
	@line17.y = 1.90
	@line17.text = \inputline{c}{17}{codes/sub3.c}
	@line17.anchor = west

line18 => Node
	@line18.x = 1
	@line18.y = 1.52
	@line18.text = \inputline{c}{18}{codes/sub3.c}
	@line18.anchor = west

line19 => Node
	@line19.x = 1
	@line19.y = 1.14
	@line19.text = \inputline{c}{19}{codes/sub3.c}
	@line19.anchor = west

line20 => Node
	@line20.x = 1
	@line20.y = 0.76
	@line20.text = \inputline{c}{20}{codes/sub3.c}
	@line20.anchor = west

line21 => Node
	@line21.x = 1
	@line21.y = 0.38
	@line21.text = \inputline{c}{21}{codes/sub3.c}
	@line21.anchor = west

line22 => Node
	@line22.x = 1
	@line22.y = -0.00
	@line22.text = \inputline{c}{22}{codes/sub3.c}
	@line22.anchor = west

line23 => Node
	@line23.x = 8
	@line23.y = 8.00
	@line23.text = \inputline{c}{23}{codes/sub3.c}
	@line23.anchor = west

line24 => Node
	@line24.x = 8
	@line24.y = 7.62
	@line24.text = \inputline{c}{24}{codes/sub3.c}
	@line24.anchor = west

line25 => Node
	@line25.x = 8
	@line25.y = 7.24
	@line25.text = \inputline{c}{25}{codes/sub3.c}
	@line25.anchor = west

line26 => Node
	@line26.x = 8
	@line26.y = 6.86
	@line26.text = \inputline{c}{26}{codes/sub3.c}
	@line26.anchor = west

line27 => Node
	@line27.x = 8
	@line27.y = 6.48
	@line27.text = \inputline{c}{27}{codes/sub3.c}
	@line27.anchor = west

line28 => Node
	@line28.x = 8
	@line28.y = 6.10
	@line28.text = \inputline{c}{28}{codes/sub3.c}
	@line28.anchor = west

line29 => Node
	@line29.x = 8
	@line29.y = 5.71
	@line29.text = \inputline{c}{29}{codes/sub3.c}
	@line29.anchor = west

line30 => Node
	@line30.x = 8
	@line30.y = 5.33
	@line30.text = \inputline{c}{30}{codes/sub3.c}
	@line30.anchor = west

line31 => Node
	@line31.x = 8
	@line31.y = 4.95
	@line31.text = \inputline{c}{31}{codes/sub3.c}
	@line31.anchor = west

vbar => Path
    @vbar.path = (7, 8) -- (7, 0) -- cycle
    @vbar.color = gray
    &vbar.dashed

-line8
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

---
+line8

---

+line10
+line11
+line12
+line13
+line26

---
+line15

---
+line17
+line18

---
+line20
+line21
+line22

---
+line24
+line25

---
+line28

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
    @a.text = $\star$ \bbtext{Para resolver o caso geral do problema, é preciso armazenar todas as notas em}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 6
    @a1.text = \bbtext{um vetor}
    @a1.anchor = west


---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{A nota do $i$-ésimo candidato será dada por \code{c}{As[i]}, sendo que a contagem começa}
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.5
    @b1.text = \bbtext{em zero}
    @b1.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{A estratégia de solução será uma busca completa em $C$}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{Iniciando em $C = 100$, serão avaliadas as possíveis notas de corte, em ordem}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 2.0
    @d1.text = \bbtext{decrescente, até encontrar o primeiro valor para o qual o número de aprovados é maior}
    @d1.anchor = west

d2 => Node
    @d2.x = 0.5
    @d2.y = 1.5
    @d2.text = \bbtext{ou igual a $K$}
    @d2.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 0.5
    @e.text = $\star$ \bbtext{Este solução tem complexidade $O(NC)$}
    @e.anchor = west

## Scene

line1 => Node
	@line1.x = 1
	@line1.y = 8.00
	@line1.text = \inputline{c}{1}{codes/solution.c}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 7.62
	@line2.text = \inputline{c}{2}{codes/solution.c}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 7.24
	@line3.text = \inputline{c}{3}{codes/solution.c}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 6.86
	@line4.text = \inputline{c}{4}{codes/solution.c}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 6.48
	@line5.text = \inputline{c}{5}{codes/solution.c}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 6.10
	@line6.text = \inputline{c}{6}{codes/solution.c}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 5.71
	@line7.text = \inputline{c}{7}{codes/solution.c}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 5.33
	@line8.text = \inputline{c}{8}{codes/solution.c}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 4.95
	@line9.text = \inputline{c}{9}{codes/solution.c}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 4.57
	@line10.text = \inputline{c}{10}{codes/solution.c}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 4.19
	@line11.text = \inputline{c}{11}{codes/solution.c}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 3.81
	@line12.text = \inputline{c}{12}{codes/solution.c}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 3.43
	@line13.text = \inputline{c}{13}{codes/solution.c}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 3.05
	@line14.text = \inputline{c}{14}{codes/solution.c}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = 2.67
	@line15.text = \inputline{c}{15}{codes/solution.c}
	@line15.anchor = west

line16 => Node
	@line16.x = 1
	@line16.y = 2.29
	@line16.text = \inputline{c}{16}{codes/solution.c}
	@line16.anchor = west

line17 => Node
	@line17.x = 1
	@line17.y = 1.90
	@line17.text = \inputline{c}{17}{codes/solution.c}
	@line17.anchor = west

line18 => Node
	@line18.x = 1
	@line18.y = 1.52
	@line18.text = \inputline{c}{18}{codes/solution.c}
	@line18.anchor = west

line19 => Node
	@line19.x = 1
	@line19.y = 1.14
	@line19.text = \inputline{c}{19}{codes/solution.c}
	@line19.anchor = west

line20 => Node
	@line20.x = 1
	@line20.y = 0.76
	@line20.text = \inputline{c}{20}{codes/solution.c}
	@line20.anchor = west

line21 => Node
	@line21.x = 1
	@line21.y = 0.38
	@line21.text = \inputline{c}{21}{codes/solution.c}
	@line21.anchor = west

line22 => Node
	@line22.x = 1
	@line22.y = -0.00
	@line22.text = \inputline{c}{22}{codes/solution.c}
	@line22.anchor = west

vbar => Path
@vbar.path = (7.5, 8) -- (7.5, 0) -- cycle
@vbar.color = gray
&vbar.dashed
line23 => Node
	@line23.x = 8
	@line23.y = 8.00
	@line23.text = \inputline{c}{23}{codes/solution.c}
	@line23.anchor = west

line24 => Node
	@line24.x = 8
	@line24.y = 7.62
	@line24.text = \inputline{c}{24}{codes/solution.c}
	@line24.anchor = west

line25 => Node
	@line25.x = 8
	@line25.y = 7.24
	@line25.text = \inputline{c}{25}{codes/solution.c}
	@line25.anchor = west

line26 => Node
	@line26.x = 8
	@line26.y = 6.86
	@line26.text = \inputline{c}{26}{codes/solution.c}
	@line26.anchor = west

line27 => Node
	@line27.x = 8
	@line27.y = 6.48
	@line27.text = \inputline{c}{27}{codes/solution.c}
	@line27.anchor = west

line28 => Node
	@line28.x = 8
	@line28.y = 6.10
	@line28.text = \inputline{c}{28}{codes/solution.c}
	@line28.anchor = west

line29 => Node
	@line29.x = 8
	@line29.y = 5.71
	@line29.text = \inputline{c}{29}{codes/solution.c}
	@line29.anchor = west

line30 => Node
	@line30.x = 8
	@line30.y = 5.33
	@line30.text = \inputline{c}{30}{codes/solution.c}
	@line30.anchor = west

line31 => Node
	@line31.x = 8
	@line31.y = 4.95
	@line31.text = \inputline{c}{31}{codes/solution.c}
	@line31.anchor = west

-line5
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

---
+line5
+line6

---
+line8

---
+line10
+line11

---
+line13
+line14
+line28

---
+line15

---
+line17
+line18
+line21

---
+line19
+line20

---
+line23
+line24
+line27

---
+line25

---
+line26

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
    @a.text = $\star$ \bbtext{Há uma solução mais eficiente para este problema}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Por meio da ordenação das notas, é possível adotar uma estratégia gulosa}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{A resposta será a nota do $K$-ésimo aprovado}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $\star$ \bbtext{Se o vetor \code{c}{As} for ordenado em ordem crescente, o $K$-ésimo aprovado ocupará}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 2.5
    @d1.text = \bbtext{ o índice $N - K$ do vetor}
    @d1.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $\star$ \bbtext{Este solução tem complexidade $O(N\log N)$}
    @e.anchor = west

## Scene

line1 => Node
	@line1.x = 1
	@line1.y = 8.00
	@line1.text = \inputline{c}{1}{codes/solution.cpp}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 7.56
	@line2.text = \inputline{c}{2}{codes/solution.cpp}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 7.11
	@line3.text = \inputline{c}{3}{codes/solution.cpp}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 6.67
	@line4.text = \inputline{c}{4}{codes/solution.cpp}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 6.22
	@line5.text = \inputline{c}{5}{codes/solution.cpp}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 5.78
	@line6.text = \inputline{c}{6}{codes/solution.cpp}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 5.33
	@line7.text = \inputline{c}{7}{codes/solution.cpp}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 4.89
	@line8.text = \inputline{c}{8}{codes/solution.cpp}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 4.44
	@line9.text = \inputline{c}{9}{codes/solution.cpp}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 4.00
	@line10.text = \inputline{c}{10}{codes/solution.cpp}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 3.56
	@line11.text = \inputline{c}{11}{codes/solution.cpp}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 3.11
	@line12.text = \inputline{c}{12}{codes/solution.cpp}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 2.67
	@line13.text = \inputline{c}{13}{codes/solution.cpp}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 2.22
	@line14.text = \inputline{c}{14}{codes/solution.cpp}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = 1.78
	@line15.text = \inputline{c}{15}{codes/solution.cpp}
	@line15.anchor = west

line16 => Node
	@line16.x = 1
	@line16.y = 1.33
	@line16.text = \inputline{c}{16}{codes/solution.cpp}
	@line16.anchor = west

line17 => Node
	@line17.x = 1
	@line17.y = 0.89
	@line17.text = \inputline{c}{17}{codes/solution.cpp}
	@line17.anchor = west

line18 => Node
	@line18.x = 1
	@line18.y = 0.44
	@line18.text = \inputline{c}{18}{codes/solution.cpp}
	@line18.anchor = west

line19 => Node
	@line19.x = 1
	@line19.y = -0.00
	@line19.text = \inputline{c}{19}{codes/solution.cpp}
	@line19.anchor = west

-line2
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

---
+line6
+line7

---
+line9
+line11
+line12

---
+line14

---
+line2

---
+line16


## End
