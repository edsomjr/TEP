## Frame
\bbcover{OBI 2013 - Nível Júnior: Fase 1}{Saldo do Vovô}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbtext{Vovô João tem uma banca de jornais; ele tem muitos clientes, e diariamente recebe muito dinheiro,
mas também faz muitos pagamentos para manter o seu estoque de jornais e revistas. Todo dia ele
vai ao banco realizar um depósito ou uma retirada de dinheiro. Em alguns dias, o saldo de sua conta
no banco fica negativo, mas Vovô João tem um acordo com o banco que garante que ele somente é
cobrado se o saldo for menor do que um valor pré-estabelecido.}


\vspace{0.2in}

\bbtext{Dada a movimentação diária da conta do banco do Vovô João, você deve escrever um programa que
calcule o menor saldo da conta, no período dado.}

## Text

\bbbold{Entrada}

\vspace{0.2in}

\bbtext{A primeira linha da entrada contém dois números inteiros $N$ e $S$ que indicam respectivamente o
número de dias do período de interesse e o saldo da conta no início do período. Cada uma das $N$
linhas seguintes contém um número inteiro indicando a movimentação de um dia (valor positivo no
caso de depósito, valor negativo no caso de retirada). A movimentação é dada para um período de
$N$ dias consecutivos: a primeira das $N$ linhas corresponde ao primeiro dia do período de interesse,
a segunda linha corresponde ao segundo dia, e assim por diante.}

## Text

\bbbold{Saída}

\vspace{0.2in}

\bbtext{Seu programa deve imprimir uma única linha, contendo um único número inteiro, o menor valor de
saldo da conta no período dado.}

\vspace{0.2in}

\bbbold{Restrições}
\vspace{-0.1in}

\bbtext{
\begin{itemize}
    \item $1 \leq N \leq 30$
    \item $-10^3 \leq S \leq 10^3$
    \item $-10^3 \leq$ cada movimentação $\leq 10^3$
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
    @line1.text = \bbtext{\texttt{6 -200}}
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
    @r.text = \footnotesize \bbcomment{\# de dias}

---
    @arrow.x = 2.03
    @arrow.u = 2.03

    !r
    @r.x = 2.03
    @r.text = \footnotesize \bbcomment{saldo inicial}

---

-r
-arrow

granpa => Node
    @granpa.x = 11
    @granpa.y = 4.5
    @granpa.text = \includegraphics[scale=0.3]{figs/grandfather.png}

cash => Node
    @cash.x = 11
    @cash.y = 1.75
    @cash.text = \Large \bbtext{-200}

answer => Node
    @answer.x = 11
    @answer.y = 1
    @answer.text = \large \bboutput{-200}

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{-100}}
    @line2.anchor = west

---
+r
+arrow
    @r.x = 3.1
    @r.y = 5.5
    @r.text = \footnotesize \bbcomment{retirada no dia $1$}
    @r.anchor = west

    @arrow.x = 3
    @arrow.u = 2.25
    @arrow.y = 5.5
    @arrow.v = 5.5
---
-r
-arrow

    @cash.text = \Large \bbtext{-300}
---
    @answer.text = \large \bboutput{-300}
 
---

line3 => Node
    @line3.x = 1
    @line3.y = 5
    @line3.text = \bbtext{\texttt{1000}}
    @line3.anchor = west

---

+r
+arrow
    @r.x = 3.1
    @r.y = 5
    @r.text = \footnotesize \bbcomment{depósito no dia $2$}
    @r.anchor = west

    @arrow.x = 3
    @arrow.u = 2.25
    @arrow.y = 5
    @arrow.v = 5
---
-r
-arrow

    @cash.text = \Large \bbtext{700}
 
---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{-2000}}
    @line4.anchor = west

---

+r
+arrow
    @r.x = 3.1
    @r.y = 4.5
    @r.text = \footnotesize \bbcomment{retirada no dia $3$}
    @r.anchor = west

    @arrow.x = 3
    @arrow.u = 2.25
    @arrow.y = 4.5
    @arrow.v = 4.5
---
-r
-arrow

    @cash.text = \Large \bbtext{-1300}
---
    @answer.text = \Large \bboutput{-1300}
 
---

line5 => Node
    @line5.x = 1
    @line5.y = 4
    @line5.text = \bbtext{\texttt{100}}
    @line5.anchor = west

---

+r
+arrow
    @r.x = 3.1
    @r.y = 4
    @r.text = \footnotesize \bbcomment{depósito no dia $4$}
    @r.anchor = west

    @arrow.x = 3
    @arrow.u = 2.25
    @arrow.y = 4
    @arrow.v = 4
---
-r
-arrow

    @cash.text = \Large \bbtext{-1200}
 
---

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{-50}}
    @line6.anchor = west

---

+r
+arrow
    @r.x = 3.1
    @r.y = 3.5
    @r.text = \footnotesize \bbcomment{retirada no dia $5$}
    @r.anchor = west

    @arrow.x = 3
    @arrow.u = 2.25
    @arrow.y = 3.5
    @arrow.v = 3.5
---
-r
-arrow

    @cash.text = \Large \bbtext{-1250}

---

line7 => Node
    @line7.x = 1
    @line7.y = 3
    @line7.text = \bbtext{\texttt{2000}}
    @line7.anchor = west

---

+r
+arrow
    @r.x = 3.1
    @r.y = 3
    @r.text = \footnotesize \bbcomment{depósito no dia $6$}
    @r.anchor = west

    @arrow.x = 3
    @arrow.u = 2.25
    @arrow.y = 3
    @arrow.v = 3
---
-r
-arrow

    @cash.text = \Large \bbtext{800}
 
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
    @a.text = $\star$ \bbtext{O problema consiste em simular as ações do vovô a cada dia}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Devem ser mantidas duas variáveis: o saldo atual e o menor saldo da série histórica}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{É necessário um laço de se repita $N$ vezes para ler a entrada}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $\star$ \bbtext{A cada inteiro lido, o saldo deve ser atualizado somando-se tal número}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 2
    @e.text = $\star$ \bbtext{Se o saldo atual é o menor da série, deve-se atualizar o registro}
    @e.anchor = west

---

f => Node
    @f.x = 1
    @f.y = 1
    @f.text = $\star$ \bbtext{Esta atualização pode ser feita por meio de um \mintinline{cpp}{if} ou da função \mintinline{cpp}{min()}}
    @f.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução $O(N)$ em C++}
    @title.anchor = west

line1 => Node
	@line1.x = 1
	@line1.y = 6.00
	@line1.text = \inputline{cpp}{1}{codes/solution.cpp}
	@line1.anchor = west

line2 => Node
	@line2.x = 1
	@line2.y = 5.57
	@line2.text = \inputline{cpp}{2}{codes/solution.cpp}
	@line2.anchor = west

line3 => Node
	@line3.x = 1
	@line3.y = 5.14
	@line3.text = \inputline{cpp}{3}{codes/solution.cpp}
	@line3.anchor = west

line4 => Node
	@line4.x = 1
	@line4.y = 4.71
	@line4.text = \inputline{cpp}{4}{codes/solution.cpp}
	@line4.anchor = west

line5 => Node
	@line5.x = 1
	@line5.y = 4.29
	@line5.text = \inputline{cpp}{5}{codes/solution.cpp}
	@line5.anchor = west

line6 => Node
	@line6.x = 1
	@line6.y = 3.86
	@line6.text = \inputline{cpp}{6}{codes/solution.cpp}
	@line6.anchor = west

line7 => Node
	@line7.x = 1
	@line7.y = 3.43
	@line7.text = \inputline{cpp}{7}{codes/solution.cpp}
	@line7.anchor = west

line8 => Node
	@line8.x = 1
	@line8.y = 3.00
	@line8.text = \inputline{cpp}{8}{codes/solution.cpp}
	@line8.anchor = west

line9 => Node
	@line9.x = 1
	@line9.y = 2.57
	@line9.text = \inputline{cpp}{9}{codes/solution.cpp}
	@line9.anchor = west

line10 => Node
	@line10.x = 1
	@line10.y = 2.14
	@line10.text = \inputline{cpp}{10}{codes/solution.cpp}
	@line10.anchor = west

line11 => Node
	@line11.x = 1
	@line11.y = 1.71
	@line11.text = \inputline{cpp}{11}{codes/solution.cpp}
	@line11.anchor = west

line12 => Node
	@line12.x = 1
	@line12.y = 1.29
	@line12.text = \inputline{cpp}{12}{codes/solution.cpp}
	@line12.anchor = west

line13 => Node
	@line13.x = 1
	@line13.y = 0.86
	@line13.text = \inputline{cpp}{13}{codes/solution.cpp}
	@line13.anchor = west

line14 => Node
	@line14.x = 1
	@line14.y = 0.43
	@line14.text = \inputline{cpp}{14}{codes/solution.cpp}
	@line14.anchor = west

line15 => Node
	@line15.x = 1
	@line15.y = -0.00
	@line15.text = \inputline{cpp}{15}{codes/solution.cpp}
	@line15.anchor = west

line17 => Node
	@line17.x = 7
	@line17.y = 5.50
	@line17.text = \inputline{cpp}{17}{codes/solution.cpp}
	@line17.anchor = west

line18 => Node
	@line18.x = 7
	@line18.y = 5.11
	@line18.text = \inputline{cpp}{18}{codes/solution.cpp}
	@line18.anchor = west

line19 => Node
	@line19.x = 7
	@line19.y = 4.72
	@line19.text = \inputline{cpp}{19}{codes/solution.cpp}
	@line19.anchor = west

line20 => Node
	@line20.x = 7
	@line20.y = 4.33
	@line20.text = \inputline{cpp}{20}{codes/solution.cpp}
	@line20.anchor = west

line21 => Node
	@line21.x = 7
	@line21.y = 3.94
	@line21.text = \inputline{cpp}{21}{codes/solution.cpp}
	@line21.anchor = west

line22 => Node
	@line22.x = 7
	@line22.y = 3.56
	@line22.text = \inputline{cpp}{22}{codes/solution.cpp}
	@line22.anchor = west

line23 => Node
	@line23.x = 7
	@line23.y = 3.17
	@line23.text = \inputline{cpp}{23}{codes/solution.cpp}
	@line23.anchor = west

line24 => Node
	@line24.x = 7
	@line24.y = 2.78
	@line24.text = \inputline{cpp}{24}{codes/solution.cpp}
	@line24.anchor = west

line25 => Node
	@line25.x = 7
	@line25.y = 2.39
	@line25.text = \inputline{cpp}{25}{codes/solution.cpp}
	@line25.anchor = west

line26 => Node
	@line26.x = 7
	@line26.y = 2.00
	@line26.text = \inputline{cpp}{26}{codes/solution.cpp}
	@line26.anchor = west

vbar => Path
@vbar.path = (6.5, 6) -- (6.5, 0) -- cycle
@vbar.color = gray!50
&vbar.dashed

-line7
-line8
-line10
-line11
-line12
-line13
-line14
-line15
-line17
-line18
-line19
-line20
-line21
-line22
-line23
-line24

---
+line7

---
+line8

---
+line10

---
+line12
+line13
+line21

---
    @line12.text = \inputline{cpp}{1}{codes/delta.cpp}


---
+line14

---
+line15

---
+line17

---
+line19
+line20

---
-line20
    @line19.text = \inputline{cpp}{2}{codes/delta.cpp}

---
+line23

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Referências}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 4.5
    @a.text = $\star$ \bbtext{Grandpa icon created by Freepik - Flaticon:}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 4
    @a1.text = \url{https://www.flaticon.com/free-icons/grandpa}
    @a1.anchor = west



## End

<a href="https://www.flaticon.com/free-icons/grandpa" title="grandpa icons">Grandpa icons created by Freepik - Flaticon</a>

