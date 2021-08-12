## Frame
\bbcover{OJ 10459}{The Tree Root}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

line1 => Node
    @line1.x = 0
    @line1.y = 7
    @line1.text = \bbenglish{Tree is an important data structure. Searching is a basic operation in any data}
    @line1.anchor = west

line2 => Node
    @line2.x = 0
    @line2.y = 6.5
    @line2.text = \bbenglish{structure. In a tree searching mainly depends on its height. Consider the following}
    @line2.anchor = west

line3 => Node
    @line3.x = 0
    @line3.y = 6.0
    @line3.text = \bbenglish{three trees.}
    @line3.anchor = west

a1 => Node
    @a1.x = 2
    @a1.y = 4
    @a1.text = \footnotesize \bbtext{1}
    &a1.draw
    &a1.very thick
    &a1.circle

a2 => Node
    @a2.x = 3
    @a2.y = 5
    @a2.text = \scriptsize \bbtext{2}
    &a2.draw
    &a2.very thick
    &a2.circle

a3 => Node
    @a3.x = 2
    @a3.y = 2
    @a3.text = \scriptsize \bbtext{3}
    &a3.draw
    &a3.very thick
    &a3.circle

a4 => Node
    @a4.x = 1
    @a4.y = 1
    @a4.text = \scriptsize \bbtext{4}
    &a4.draw
    &a4.very thick
    &a4.circle

a5 => Node
    @a5.x = 3
    @a5.y = 1
    @a5.text = \scriptsize \bbtext{5}
    &a5.draw
    &a5.very thick
    &a5.circle

a6 => Node
    @a6.x = 3
    @a6.y = 3
    @a6.text = \scriptsize \bbtext{6}
    &a6.draw
    &a6.very thick
    &a6.circle

a7 => Node
    @a7.x = 4
    @a7.y = 4
    @a7.text = \scriptsize \bbtext{7}
    &a7.draw
    &a7.very thick
    &a7.circle

a21 => Edge
    @a21.from = a2
    @a21.to = a1
    &a21.thick

a26 => Edge
    @a26.from = a2
    @a26.to = a6
    &a26.thick

a27 => Edge
    @a27.from = a2
    @a27.to = a7
    &a27.thick

a13 => Edge
    @a13.from = a1
    @a13.to = a3
    &a13.thick

a34 => Edge
    @a34.from = a3
    @a34.to = a4
    &a34.thick

a35 => Edge
    @a35.from = a3
    @a35.to = a5
    &a35.thick

b1 => Node
    @b1.x = 7
    @b1.y = 5
    @b1.text = \footnotesize \bbtext{1}
    &b1.draw
    &b1.very thick
    &b1.circle

b2 => Node
    @b2.x = 8
    @b2.y = 3
    @b2.text = \scriptsize \bbtext{2}
    &b2.draw
    &b2.very thick
    &b2.circle

b3 => Node
    @b3.x = 6
    @b3.y = 3
    @b3.text = \scriptsize \bbtext{3}
    &b3.draw
    &b3.very thick
    &b3.circle

b4 => Node
    @b4.x = 5
    @b4.y = 1
    @b4.text = \scriptsize \bbtext{4}
    &b4.draw
    &b4.very thick
    &b4.circle

b5 => Node
    @b5.x = 6.5
    @b5.y = 1
    @b5.text = \scriptsize \bbtext{5}
    &b5.draw
    &b5.very thick
    &b5.circle

b6 => Node
    @b6.x = 7.5
    @b6.y = 1
    @b6.text = \scriptsize \bbtext{6}
    &b6.draw
    &b6.very thick
    &b6.circle

b7 => Node
    @b7.x = 9
    @b7.y = 1
    @b7.text = \scriptsize \bbtext{7}
    &b7.draw
    &b7.very thick
    &b7.circle

b13 => Edge
    @b13.from = b1
    @b13.to = b3
    &b13.thick

b12 => Edge
    @b12.from = b1
    @b12.to = b2
    &b12.thick

b27 => Edge
    @b27.from = b2
    @b27.to = b7
    &b27.thick

b26 => Edge
    @b26.from = b2
    @b26.to = b6
    &b26.thick

b34 => Edge
    @b34.from = b3
    @b34.to = b4
    &b34.thick

b35 => Edge
    @b35.from = b3
    @b35.to = b5
    &b35.thick

c1 => Node
    @c1.x = 12
    @c1.y = 3
    @c1.text = \footnotesize \bbtext{1}
    &c1.draw
    &c1.very thick
    &c1.circle

c2 => Node
    @c2.x = 12
    @c2.y = 2
    @c2.text = \scriptsize \bbtext{2}
    &c2.draw
    &c2.very thick
    &c2.circle

c3 => Node
    @c3.x = 11
    @c3.y = 4
    @c3.text = \scriptsize \bbtext{3}
    &c3.draw
    &c3.very thick
    &c3.circle

c4 => Node
    @c4.x = 11
    @c4.y = 5
    @c4.text = \scriptsize \bbtext{4}
    &c4.draw
    &c4.very thick
    &c4.circle

c5 => Node
    @c5.x = 10
    @c5.y = 3
    @c5.text = \scriptsize \bbtext{5}
    &c5.draw
    &c5.very thick
    &c5.circle

c6 => Node
    @c6.x = 11
    @c6.y = 1
    @c6.text = \scriptsize \bbtext{6}
    &c6.draw
    &c6.very thick
    &c6.circle

c7 => Node
    @c7.x = 13
    @c7.y = 1
    @c7.text = \scriptsize \bbtext{7}
    &c7.draw
    &c7.very thick
    &c7.circle

c43 => Edge
    @c43.from = c4
    @c43.to = c3
    &c43.thick

c26 => Edge
    @c26.from = c2
    @c26.to = c6
    &c26.thick

c27 => Edge
    @c27.from = c2
    @c27.to = c7
    &c27.thick

c12 => Edge
    @c12.from = c1
    @c12.to = c2
    &c12.thick

c31 => Edge
    @c31.from = c3
    @c31.to = c1
    &c31.thick

c35 => Edge
    @c35.from = c3
    @c35.to = c5
    &c35.thick

## Scene

line1 => Node
    @line1.x = 0
    @line1.y = 7
    @line1.text = \bbtext{Árvore é uma importante estrutura de dados. Busca é uma operação básica em}
    @line1.anchor = west

line2 => Node
    @line2.x = 0
    @line2.y = 6.5
    @line2.text = \bbtext{qualquer estrutura de dados. Em uma árvore a busca depende de sua altura. }
    @line2.anchor = west

line3 => Node
    @line3.x = 0
    @line3.y = 6.0
    @line3.text = \bbtext{Considere as três árvores abaixo.}
    @line3.anchor = west

a1 => Node
    @a1.x = 2
    @a1.y = 4
    @a1.text = \footnotesize \bbtext{1}
    &a1.draw
    &a1.very thick
    &a1.circle

a2 => Node
    @a2.x = 3
    @a2.y = 5
    @a2.text = \scriptsize \bbtext{2}
    &a2.draw
    &a2.very thick
    &a2.circle

a3 => Node
    @a3.x = 2
    @a3.y = 2
    @a3.text = \scriptsize \bbtext{3}
    &a3.draw
    &a3.very thick
    &a3.circle

a4 => Node
    @a4.x = 1
    @a4.y = 1
    @a4.text = \scriptsize \bbtext{4}
    &a4.draw
    &a4.very thick
    &a4.circle

a5 => Node
    @a5.x = 3
    @a5.y = 1
    @a5.text = \scriptsize \bbtext{5}
    &a5.draw
    &a5.very thick
    &a5.circle

a6 => Node
    @a6.x = 3
    @a6.y = 3
    @a6.text = \scriptsize \bbtext{6}
    &a6.draw
    &a6.very thick
    &a6.circle

a7 => Node
    @a7.x = 4
    @a7.y = 4
    @a7.text = \scriptsize \bbtext{7}
    &a7.draw
    &a7.very thick
    &a7.circle

a21 => Edge
    @a21.from = a2
    @a21.to = a1
    &a21.thick

a26 => Edge
    @a26.from = a2
    @a26.to = a6
    &a26.thick

a27 => Edge
    @a27.from = a2
    @a27.to = a7
    &a27.thick

a13 => Edge
    @a13.from = a1
    @a13.to = a3
    &a13.thick

a34 => Edge
    @a34.from = a3
    @a34.to = a4
    &a34.thick

a35 => Edge
    @a35.from = a3
    @a35.to = a5
    &a35.thick

b1 => Node
    @b1.x = 7
    @b1.y = 5
    @b1.text = \footnotesize \bbtext{1}
    &b1.draw
    &b1.very thick
    &b1.circle

b2 => Node
    @b2.x = 8
    @b2.y = 3
    @b2.text = \scriptsize \bbtext{2}
    &b2.draw
    &b2.very thick
    &b2.circle

b3 => Node
    @b3.x = 6
    @b3.y = 3
    @b3.text = \scriptsize \bbtext{3}
    &b3.draw
    &b3.very thick
    &b3.circle

b4 => Node
    @b4.x = 5
    @b4.y = 1
    @b4.text = \scriptsize \bbtext{4}
    &b4.draw
    &b4.very thick
    &b4.circle

b5 => Node
    @b5.x = 6.5
    @b5.y = 1
    @b5.text = \scriptsize \bbtext{5}
    &b5.draw
    &b5.very thick
    &b5.circle

b6 => Node
    @b6.x = 7.5
    @b6.y = 1
    @b6.text = \scriptsize \bbtext{6}
    &b6.draw
    &b6.very thick
    &b6.circle

b7 => Node
    @b7.x = 9
    @b7.y = 1
    @b7.text = \scriptsize \bbtext{7}
    &b7.draw
    &b7.very thick
    &b7.circle

b13 => Edge
    @b13.from = b1
    @b13.to = b3
    &b13.thick

b12 => Edge
    @b12.from = b1
    @b12.to = b2
    &b12.thick

b27 => Edge
    @b27.from = b2
    @b27.to = b7
    &b27.thick

b26 => Edge
    @b26.from = b2
    @b26.to = b6
    &b26.thick

b34 => Edge
    @b34.from = b3
    @b34.to = b4
    &b34.thick

b35 => Edge
    @b35.from = b3
    @b35.to = b5
    &b35.thick

c1 => Node
    @c1.x = 12
    @c1.y = 3
    @c1.text = \footnotesize \bbtext{1}
    &c1.draw
    &c1.very thick
    &c1.circle

c2 => Node
    @c2.x = 12
    @c2.y = 2
    @c2.text = \scriptsize \bbtext{2}
    &c2.draw
    &c2.very thick
    &c2.circle

c3 => Node
    @c3.x = 11
    @c3.y = 4
    @c3.text = \scriptsize \bbtext{3}
    &c3.draw
    &c3.very thick
    &c3.circle

c4 => Node
    @c4.x = 11
    @c4.y = 5
    @c4.text = \scriptsize \bbtext{4}
    &c4.draw
    &c4.very thick
    &c4.circle

c5 => Node
    @c5.x = 10
    @c5.y = 3
    @c5.text = \scriptsize \bbtext{5}
    &c5.draw
    &c5.very thick
    &c5.circle

c6 => Node
    @c6.x = 11
    @c6.y = 1
    @c6.text = \scriptsize \bbtext{6}
    &c6.draw
    &c6.very thick
    &c6.circle

c7 => Node
    @c7.x = 13
    @c7.y = 1
    @c7.text = \scriptsize \bbtext{7}
    &c7.draw
    &c7.very thick
    &c7.circle

c43 => Edge
    @c43.from = c4
    @c43.to = c3
    &c43.thick

c26 => Edge
    @c26.from = c2
    @c26.to = c6
    &c26.thick

c27 => Edge
    @c27.from = c2
    @c27.to = c7
    &c27.thick

c12 => Edge
    @c12.from = c1
    @c12.to = c2
    &c12.thick

c31 => Edge
    @c31.from = c3
    @c31.to = c1
    &c31.thick

c35 => Edge
    @c35.from = c3
    @c35.to = c5
    &c35.thick

## Text

\bbenglish{If you observe carefully, you will see that all trees are same except different nodes are used as roots.  Here the height of the tree varies with the selection of the root. In the 1st tree root is `\texttt{2}' and height is $3$. In 2nd one root is `\texttt{1}' and height is $2$. And in last one root is `\texttt{4}' and height is $4$. We will call `\texttt{1}' best root as it keeps the tree with the least possible height and `\texttt{4}' worst root for the opposite reason.}

\vspace{0.1in}

\bbenglish{In this problem, you have to find out all best roots and worst roots for a given tree.}

## Text

\bbtext{Se você observar atentamente, você verá que todas as três árvores são idênticas, exceto pelo fato de terem escolhidos nós diferentes como raízes.  Aqui a altura da árvore varia de acordo com a escolha da raiz. Na primeira árvore a raiz é `\texttt{2}' e a altura é $3$. Na segunda a raiz é `\texttt{1}' e a altura é $2$. E na última a raiz é `\texttt{4}' e a altura é $4$. Nos dizemos que `\texttt{1}' é uma raiz ótima no sentido que ela minimiza a altura máxima e `\texttt{4}' uma raiz péssima pela razão oposta.}

\vspace{0.1in}

\bbtext{Neste problema você deve encontrar todas as raízes ótimas e péssimas de uma dada árvore.}

## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{Each dataset starts with a positive integer $N$ $(3\leq N\leq 5000)$, which is the number of nodes in the tree. Each node in the tree has a unique id from $1$ to $N$. Then successively for each $i$’th node there will be a positive integer $K[i]$ following id of $K[i]$ nodes which are adjacent to $i$. Input is terminated by \texttt{EOF}.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbenglish{For each dataset print two lines. In the 1st line show all the best roots in ascending order and in next line show all worst roots in ascending order. See sample output for exact format.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{Cada caso de teste começa com um inteiro positivo $N$ $(3\leq N\leq 5000)$, o qual indica o número de nós na árvore. Cada nó da árvore tem um identificador único no intervalo de $1$ a $N$. Então para cada $i$-ésimo nó haverá um inteiro positivo $K[i]$ seguido pelos identificadores dos $K[i]$ nós adjacentes a $i$. A entrada termina com \texttt{EOF}.}

\vspace{0.2in}

\bbbold{Output}

\vspace{0.1in}

\bbtext{Para cada caso de teste imprima duas linhas. Na primeira linha mostre todas as raízes ótimas, em ordem crescente, e na linha seguinte todas as raízes péssimas, em ordem crescente. Veja o exemplo para o formato exato da saída.}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{7} }
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
    @r.text = \footnotesize \bbcomment{\# número de nós}

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
    @node2.x = 9
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 11
    @node3.y = 7
    @node3.text = \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle

node4 => Node
    @node4.x = 13
    @node4.y = 5
    @node4.text = \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle

node5 => Node
    @node5.x = 13
    @node5.y = 3
    @node5.text = \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle

node6 => Node
    @node6.x = 11
    @node6.y = 1
    @node6.text = \bbtext{6}
    &node6.draw
    &node6.very thick
    &node6.circle

node7 => Node
    @node7.x = 9
    @node7.y = 1
    @node7.text = \bbtext{7}
    &node7.draw
    &node7.very thick
    &node7.circle

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{2 2 3} }
    @line2.anchor = west

---
+arrow
+r

    @arrow.x = 1.25
    @arrow.y = 5.25
    @arrow.u = 1.25
    @arrow.v = 4.25
 
    @r.x = 1.25
    @r.y = 4
    @r.text = \footnotesize $K_1$

---

    @arrow.x = 1.65
    @arrow.u = 1.65
 
    @r.x = 1.65
    @r.text = \footnotesize $v_1$

---
-arrow
-r

a12 => Edge
    @a12.from = node1
    @a12.to = node2
    &a12.thick


---
+arrow
+r
    @arrow.x = 2.05
    @arrow.u = 2.05
 
    @r.x = 2.05
    @r.text = \footnotesize $v_2$

---
-arrow
-r

a13 => Edge
    @a13.from = node1
    @a13.to = node3
    &a13.thick

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{3 1 6 7} }
    @line3.anchor = west

---

a26 => Edge
    @a26.from = node2
    @a26.to = node6
    &a26.thick

a27 => Edge
    @a27.from = node2
    @a27.to = node7
    &a27.thick

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{3 1 4 5} }
    @line4.anchor = west

---

a34 => Edge
    @a34.from = node3
    @a34.to = node4
    &a34.thick

a35 => Edge
    @a35.from = node3
    @a35.to = node5
    &a35.thick

---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{1 3} }
    @line5.anchor = west
---

line6 => Node
    @line6.x = 1
    @line6.y = 3.5
    @line6.text = \bbtext{\texttt{1 3} }
    @line6.anchor = west

---

line7 => Node
    @line7.x = 1
    @line7.y = 3.0
    @line7.text = \bbtext{\texttt{1 2} }
    @line7.anchor = west

---

line8 => Node
    @line8.x = 1
    @line8.y = 2.5
    @line8.text = \bbtext{\texttt{1 2} }
    @line8.anchor = west

---

    @node1.x = 10
    @node1.y = 7

    @node2.x = 12
    @node2.y = 4

    @node3.x = 8
    @node3.y = 4

    @node4.x = 7
    @node4.y = 1

    @node5.x = 9
    @node5.y = 1

    @node6.x = 11
    @node6.y = 1

    @node7.x = 13
    @node7.y = 1

---

info => Node
    @info.x = 4
    @info.y = 3
    @info.text = $h = \textcolor{BBCyan}{\mathbf{3}}$
    @info.anchor = west

---
-info
    @node1.x = 9
    @node2.x = 11
    @node1.y = 5
    @node2.y = 7
    @node3.y = 3
    @node6.y = 5
    @node7.y = 5

---
+info
    @info.text = $h = \textcolor{BBCyan}{{4}}$

---
-info
    @node1.x = 11
    @node2.x = 12
    @node2.y = 3
    @node3.y = 7
    @node4.y = 5
    @node5.y = 5
    @node6.y = 1
    @node7.y = 1

---
+info
    @info.text = $h = \textcolor{BBCyan}{{4}}$

---
-info

    @node1.y = 4
    @node2.y = 2.5
    @node3.x = 9
    @node3.y = 5.5
    @node4.x = 10
    @node4.y = 7
    @node5.x = 8
    @node5.y = 4
    @node6.y = 1
    @node7.y = 1

---
+info
    @info.text = $h = \textcolor{BBRed}{\mathbf{5}}$

---
-info

    @node4.x = 8
    @node4.y = 4
    @node5.x = 10
    @node5.y = 7

---
+info
    @info.text = $h = \textcolor{BBRed}{\mathbf{5}}$

---
-info

    @node5.text = \bbtext{6}
    @node3.text = \bbtext{2}
    @node4.text = \bbtext{7}
    @node2.text = \bbtext{3}
    @node6.text = \bbtext{5}
    @node7.text = \bbtext{4}

---
+info
    @info.text = $h = \textcolor{BBRed}{\mathbf{5}}$

---
-info

    @node5.text = \bbtext{7}
    @node4.text = \bbtext{6}

---
+info
    @info.text = $h = \textcolor{BBRed}{\mathbf{5}}$

## Scene

header => Node
    @header.y = 7
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

info => Node
    @info.x = 7
    @info.y = 6
    @info.text = \bbtext{Aplicar a DFS $N$ vezes para obter as alturas leva ao veredito \bbbold{TLE}!}

---

    @info.text = \bbtext{A ideia é usar a DFS em uma raiz em particular para extrair métricas}

info2 => Node
    @info2.x = 7
    @info2.y = 5.5
    @info2.text = \bbtext{e deduzir as alturas a partir destas métricas}

---
-info
-info2

node1 => Node
    @node1.x = 5
    @node1.y = 4.8
    @node1.text = \scriptsize \bbtext{1}
    &node1.draw
    &node1.very thick
    &node1.circle
    
node2 => Node
    @node2.x = 3
    @node2.y = 3.6
    @node2.text = \scriptsize \bbtext{2}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 7
    @node3.y = 3.6
    @node3.text = \scriptsize \bbtext{3}
    &node3.draw
    &node3.very thick
    &node3.circle
    
node4 => Node
    @node4.x = 11
    @node4.y = 3.6
    @node4.text = \scriptsize \bbtext{4}
    &node4.draw
    &node4.very thick
    &node4.circle

node5 => Node
    @node5.x = 7
    @node5.y = 2.4
    @node5.text = \scriptsize \bbtext{5}
    &node5.draw
    &node5.very thick
    &node5.circle
    
node6 => Node
    @node6.x = 9
    @node6.y = 2.4
    @node6.text = \scriptsize \bbtext{6}
    &node6.draw
    &node6.very thick
    &node6.circle

node7 => Node
    @node7.x = 13
    @node7.y = 2.4
    @node7.text = \scriptsize \bbtext{7}
    &node7.draw
    &node7.very thick
    &node7.circle
    
node8 => Node
    @node8.x = 9
    @node8.y = 1.2
    @node8.text = \scriptsize \bbtext{8}
    &node8.draw
    &node8.very thick
    &node8.circle

a12 => Edge
    @a12.from = node1
    @a12.to = node2
    &a12.thick

a13 => Edge
    @a13.from = node1
    @a13.to = node3
    &a13.thick

a14 => Edge
    @a14.from = node1
    @a14.to = node4
    &a14.thick

a35 => Edge
    @a35.from = node3
    @a35.to = node5
    &a35.thick

a46 => Edge
    @a46.from = node4
    @a46.to = node6
    &a46.thick

a47 => Edge
    @a47.from = node4
    @a47.to = node7
    &a47.thick

a68 => Edge
    @a68.from = node6
    @a68.to = node8
    &a68.thick

---
+info

    @info.text = \bbtext{\bbbold{Métrica \#1}: $h(u) = $ altura da subárvore cuja raiz é $u$}

---
    @node1.text = \scriptsize \bbtext{1}$_4$
    @node2.text = \scriptsize \bbtext{2}$_1$
    @node3.text = \scriptsize \bbtext{3}$_2$
    @node4.text = \scriptsize \bbtext{4}$_3$
    @node5.text = \scriptsize \bbtext{5}$_1$
    @node6.text = \scriptsize \bbtext{6}$_2$
    @node7.text = \scriptsize \bbtext{7}$_1$
    @node8.text = \scriptsize \bbtext{8}$_1$

---

    @info.text = \bbtext{\bbbold{Métrica \#2}: $p(u) = $ pai do nó $u$, $p(r) = 0$ se $r$ é a raiz}

---

e21 => Edge
    @e21.from = node2
    @e21.to = node1
    @e21.color = BBViolet
    &e21.dashed
    &e21.-latex
    %e21.label = [bend right]

e31 => Edge
    @e31.from = node3
    @e31.to = node1
    @e31.color = BBViolet
    &e31.dashed
    &e31.-latex
    %e31.label = [bend left]

e53 => Edge
    @e53.from = node5
    @e53.to = node3
    @e53.color = BBViolet
    &e53.dashed
    &e53.-latex
    %e53.label = [bend right]

e41 => Edge
    @e41.from = node4
    @e41.to = node1
    @e41.color = BBViolet
    &e41.dashed
    &e41.-latex
    %e41.label = [bend right]

e64 => Edge
    @e64.from = node6
    @e64.to = node4
    @e64.color = BBViolet
    &e64.dashed
    &e64.-latex
    %e64.label = [bend right]

e86 => Edge
    @e86.from = node8
    @e86.to = node6
    @e86.color = BBViolet
    &e86.dashed
    &e86.-latex
    %e86.label = [bend right]

e74 => Edge
    @e74.from = node7
    @e74.to = node4
    @e74.color = BBViolet
    &e74.dashed
    &e74.-latex
    %e74.label = [bend right]

--- 
+info2

    @info.y = 6.5
    @info.text = \bbtext{\bbbold{Métrica \#3}: $\delta(u, v) = $ altura da árvore cuja raiz é $u$ }

    @info2.y = 6.0
    @info2.text = \bbtext{se $v$ fosse o único filho de $u$}
--- 

    @info.text = \bbtext{Para computar $\delta(u, v)$ é preciso processar os}
    @info2.text = \bbtext{vértices na ordem da BFS}

---
-info2

    @info.y = 6
    @info.text = \bbtext{$\delta(r, v) = 1 + h(v)$, se $r$ é a raiz}

---
    @a12.color = BBGreen
    &a12.-latex
    %a12.label = node[above left] { \scriptsize \bbinfo{2} }

---
    @a13.color = BBGreen
    &a13.-latex
    %a13.label = node[above,pos=0.7] { \scriptsize \bbinfo{3} }

---
    @a14.color = BBGreen
    &a14.-latex
    %a14.label = node[above] { \scriptsize \bbinfo{4} }

---
    @info.text = $\displaystyle \delta(u, v) = \left\{ \begin{array}{ll} 1 + \max_{w\in\mathrm{adj}[v], w\neq u} \{ 1, \delta(v, w) \}, & \mbox{se}\ v = p(u)\\ 1 + h(v),& \mbox{caso contrário}\end{array}\right.$

---
    &a12.latex-
    %a12.label = node[above left,pos=0.3] { \scriptsize \bbinfo{5} }

    @a13.color = BBBlack
    &a13.-
    %a13.label = node { }

    @a14.color = BBBlack
    &a14.-
    %a14.label = node { }

---
    @a12.color = BBBlack
    &a12.-
    %a12.label = node { }

    @a13.color = BBGreen
    &a13.latex-
    %a13.label = node[above] { \scriptsize \bbinfo{5} }

    @a35.color = BBGreen
    &a35.-latex
    %a35.label = node[left] { \scriptsize \bbinfo{2} }

---
-a13

a31 => Edge
    @a31.from = node3
    @a31.to = node1
    &a31.thick

    @a35.color = BBBlack
    &a35.-
    %a35.label = node { }

    @a14.color = BBGreen
    &a14.latex-
    %a14.label = node[above] { \scriptsize \bbinfo{4} }

    @a46.color = BBGreen
    &a46.-latex
    %a46.label = node[above] { \scriptsize \bbinfo{3} }

    @a47.color = BBGreen
    &a47.-latex
    %a47.label = node[below] { \scriptsize \bbinfo{2} }

---
-a14

a41 => Edge
    @a41.from = node4
    @a41.to = node1
    &a41.thick

    @a46.color = BBBlack
    &a46.-
    %a46.label = node { }

    @a47.color = BBBlack
    &a47.-
    %a47.label = node { }

    @a35.color = BBGreen
    &a35.latex-
    %a35.label = node[left] { \scriptsize \bbinfo{6} }

---
-a35

a53 => Edge
    @a53.from = node5
    @a53.to = node3
    &a53.thick


    @a35.color = BBBlack
    &a35.-
    %a35.label = node { }

    @a46.color = BBGreen
    &a46.latex-
    %a46.label = node[above left] { \scriptsize \bbinfo{5} }

    @a68.color = BBGreen
    &a68.-latex
    %a68.label = node[left] { \scriptsize \bbinfo{2} }

---
-a46

a64 => Edge
    @a64.from = node6
    @a64.to = node4
    &a64.thick

    @a46.color = BBBlack
    &a46.-
    %a46.label = node { }

    @a68.color = BBBlack
    &a68.-
    %a68.label = node { }

    @a47.color = BBGreen
    &a47.latex-
    %a47.label = node[above] { \scriptsize \bbinfo{5} }

---
-a47

a74 => Edge
    @a74.from = node7
    @a74.to = node4
    &a74.thick

    @a47.color = BBBlack
    &a47.-
    %a47.label = node { }

    @a68.color = BBGreen
    &a68.latex-
    %a68.label = node[left] { \scriptsize \bbinfo{6} }

---
-a68

a86 => Edge
    @a86.from = node8
    @a86.to = node6
    &a86.thick

    @info.text = \bbtext{Por fim, seja $H(u)$ a altura da árvore cuja raiz é $u$}

---

    @info.text = $\displaystyle H(u) = \max_{v\in\mathrm{adj}[u]} \delta(u, v)$

## Frame

\inputsnippet{cpp}{10}{21}{codes/10459.cpp}

## Frame

\inputsnippet{cpp}{23}{41}{codes/10459.cpp}

## Frame

\inputsnippet{cpp}{43}{61}{codes/10459.cpp}

## Frame

\inputsnippet{cpp}{63}{73}{codes/10459.cpp}

## End
