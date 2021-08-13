## Frame
\bbcover{Codeforces Round \#250 (Div. 2)}{Problem C -- The Child and Toy}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{On Children's Day, the child got a toy from Delayyy as a present. However, the child is so naughty that he can't wait to destroy the toy.}

\vspace{0.1in}

\bbenglish{The toy consists of $n$ parts and $m$ ropes. Each rope links two parts, but every pair of parts is linked by at most one rope. To split the toy, the child must remove all its parts. The child can remove a single part at a time, and each remove consume an energy. Let's define an energy value of part $i$ as $v_i$. The child spend $v_{f_1} + v_{f_2} + \ldots + v_{f_k}$ energy for removing part $i$ where $f_1, f_2, \ldots, f_k$ are the parts that are directly connected to the $i$-th and haven't been removed.}

\vspace{0.1in}

\bbenglish{Help the child to find out, what is the minimum total energy he should spend to remove all $n$ parts.}

## Text

\bbtext{No Dia das Crianças, a criança ganha um brinquedo from Delayyy como presente. Contudo, a criança é tão levada que ela não pode esperar para destruir o brinquedo.}

\vspace{0.1in}

\bbtext{O brinquedo é formado por $n$ partes e $m$ cordas. Cada corda une duas partes, mas cada par de partes é unido por, no máximo, uma corda. Para quebrar o brinquedo, a criança deve remover todas as suas partes. A criança pode remover uma única parte por vez, e cada remoção consome energia. Vamos define a energia da parte $i$ como $v_i$. A criança gasta energia igual a $v_{f_1} + v_{f_2} + \ldots + v_{f_k}$ para remover a parte $i$, onde  $f_1, f_2, \ldots, f_k$ são as partes que estão diretamente conectadas à $i$-ésima parte e que não foram removidas ainda.}

\vspace{0.1in}

\bbtext{Auxilie a criança a descobir qual é o total mínimo de energia que ela deve gastar para remover todas as $n$ partes.}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{The first line contains two integers $n$ and $m$ $(1\leq n\leq 1000; 0\leq m\leq 2000)$. The second line contains $n$ integers: $v_1, v_2, \ldots, v_n$ $(0\leq v_i\leq 10^5)$. Then followed $m$ lines, each line contains two integers $x_i$ and $y_i$, representing a rope from part $x_i$ to part $y_i$ $(1\leq x_i, y_i\leq n; x_i\neq y_i)$.}

\vspace{0.1in}

\bbenglish{Consider all the parts are numbered from $1$ to $n$.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{Output the minimum total energy the child should spend to remove all $n$ parts of the toy.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A primeira linha contém dois inteiros $n$ e $m$ $(1\leq n\leq 1000; 0\leq m\leq 2000)$. A segunda linha contém $n$ inteiros: $v_1, v_2, \ldots, v_n$ $(0\leq v_i\leq 10^5)$. Então seguem $m$ linhas, e cada linha contém dois inteiros $x_i$ e $y_i$, representando uma corda da parte $x_i$ para a parte $y_i$ $(1\leq x_i, y_i\leq n; x_i\neq y_i)$.}

\vspace{0.1in}

\bbtext{Considere que todas as partes são numeradas de $1$ a $n$.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Imprima o total mínimo de energia que a criança deveria gastar para remover todas as $n$ partes do brinquedo.}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{4 3} }
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
    @r.text = \footnotesize \bbcomment{\# número de partes}

---
    @arrow.x = 1.65
    @arrow.u = 1.65
 
    @r.x = 1.65
    @r.text = \footnotesize \bbcomment{\# número de cordas}

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
    @node2.x = 10
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

 node3 => Node
    @node3.x = 13
    @node3.y = 4
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle

 node4 => Node
    @node4.x = 10
    @node4.y = 1
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle
 
---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{10 20 30 40} }
    @line2.anchor = west

---
+arrow
+r

    @arrow.x = 1.35
    @arrow.y = 5.25
    @arrow.u = 1.35
    @arrow.v = 4.25
 
    @r.x = 1.35
    @r.y = 4
    @r.text = \footnotesize $v_1$

---

    @arrow.x = 1.95
    @arrow.u = 1.95
 
    @r.x = 1.95
    @r.text = \footnotesize $v_2$

---
    @arrow.x = 2.55
    @arrow.u = 2.55
 
    @r.x = 2.55
    @r.text = \footnotesize $v_3$

---
    @arrow.x = 3.15
    @arrow.u = 3.15
 
    @r.x = 3.15
    @r.text = \footnotesize $v_4$

---
-arrow
-r

    @node1.text = \bbtext{1}$_{10}$
    @node2.text = \bbtext{2}$_{20}$
    @node3.text = \bbtext{3}$_{30}$
    @node4.text = \bbtext{4}$_{40}$

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{1 4} }
    @line3.anchor = west


---
+arrow
+r

    @arrow.x = 1.45
    @arrow.y = 4.75
    @arrow.u = 1.45
    @arrow.v = 3.75
 
    @r.x = 1.45
    @r.y = 3.5
    @r.text = \footnotesize \bbcomment{corda}

---
-arrow
-r

a14 => Edge
    @a14.from = node1
    @a14.to = node4
    &a14.thick

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{1 2} }
    @line4.anchor = west

---

a12 => Edge
    @a12.from = node1
    @a12.to = node2
    &a12.thick

---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{2 3} }
    @line5.anchor = west

---

a23 => Edge
    @a23.from = node2
    @a23.to = node3
    &a23.thick

---

    %a14.label = node { \Large \textbf{\textcolor{BBRed}{x}} } node[above right] { \bbinfo { 10 } }

---
-a14
-node4

---
    %a23.label = node { \Large \textbf{\textcolor{BBRed}{x}} } node[above right] { \bbinfo { 20 } }

---

-a23
-node3

---
    %a12.label = node { \Large \textbf{\textcolor{BBRed}{x}} } node[above left] { \bbinfo { 10 } }

---
-a12
-node2

---
-node1

---
+r
+arrow

    @r.x = 1.45
    @r.y = 2.5
    @r.text = \bbinfo{40}

    @arrow.x = 1.45
    @arrow.y = 3.75
    @arrow.u = 1.45
    @arrow.v = 2.75
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
    @line1.text = \bbtext{\texttt{7 10} }
    @line1.anchor = west

---
   
node1 => Node
    @node1.x = 6
    @node1.y = 5
    @node1.text = \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle
    
node2 => Node
    @node2.x = 8
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 10
    @node3.y = 7
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle

node4 => Node
    @node4.x = 12
    @node4.y = 4
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle
 
node5 => Node
    @node5.x = 10
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle

node6 => Node
    @node6.x = 8
    @node6.y = 1
    @node6.text = \bbtext{6}
    &node6.draw
    &node6.very thick
    &node6.circle

node7 => Node
    @node7.x = 6
    @node7.y = 3
    @node7.text = \bbtext{7}
    &node7.draw
    &node7.very thick
    &node7.circle
 
---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{40 10 20 10 20 80 40}}
    @line2.anchor = west

---
    @node1.text = \footnosize \bbtext{1}$_40$

## Scene

header => Node
    @header.y = 6
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $\star$ \bbtext{Cada viagem consiste em um problema de caminho mínimo}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $\star$ \bbtext{As arestas tem peso $1$, exceto a direção da corrente, que tem peso $0$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $\star$ \bbtext{Portanto o problema pode ser resolvido por meio de uma BFS 0/1}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbbold{Complexidade:} $O(nrc)$
    @d.anchor = west

## Frame

\inputsnippet{cpp}{10}{29}{codes/437C.cpp}

## Frame

\inputsnippet{cpp}{31}{50}{codes/437C.cpp}

## End
