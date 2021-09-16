## Frame
\bbcover{AtCoder Beginner Contest 126}{Problem D -- Even Relation}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbenglish{We have a tree with $N$ vertices numbered $1$ to $N$. The $i$-th edge in the tree connects Vertex $u_i$ and Vertex $v_i$, and its length is $w_i$. Your objective is to paint each vertex in the tree white or black (it is fine to paint all vertices the same color) so that the following condition is satisfied:}

\vspace{0.1in}

\begin{itemize}
    \item \bbenglish{For any two vertices painted in the same color, the distance between them is an even number.}
\end{itemize}

\vspace{0.1in}

\bbenglish{Find a coloring of the vertices that satisfies the condition and print it. It can be proved that at least one such coloring exists under the constraints of this problem.}

## Text

\bbtext{Nós temos uma árvore com $N$ vértices numerados de $1$ a $N$. A $i$-ésima aresta da árvore conecta o Vértice $u_i$ e o Vértice $v_i$, e seu comprimento é $w_i$. Seu objetivo é pintar cada vértice da árvore de branco ou preto (é válido pintar todos os vértices com uma mesma cor) de modo que a seguinte condição é satisfeita:}

\vspace{0.1in}

\begin{itemize}
    \item \bbtext{Para quaisquer dois vértices pintados com a mesma cor, a distância entre eles é um número par.}
\end{itemize}

\vspace{0.1in}

\bbtext{Determine uma coloração dos vértices que satisfaça a condição e a imprima. Pode ser provado que existe no mínimo uma coloração que atenda a condição imposta pelo problema.}

## Text

\bbbold{Constraints}

\vspace{0.1in}

\begin{itemize}
    \item \bbenglish{All values in input are integers.}
    \item $1\leq N\leq 10^5$
    \item $1\leq u_i < v_i\leq N$
    \item $1\leq w_i\leq 10^9$
\end{itemize}

## Text

\bbbold{Restrições}

\vspace{0.1in}

\begin{itemize}
    \item \bbtext{Todos os valores da entrada são inteiros.}
    \item $1\leq N\leq 10^5$
    \item $1\leq u_i < v_i\leq N$
    \item $1\leq w_i\leq 10^9$
\end{itemize}


## Text

\bbbold{Input}

\vspace{0.1in}

\bbenglish{Input is given from Standard Input in the following format:}
\[
\begin{matrix}
    N \\
    u_1 & v_1 & w_1 \\
    u_2 & v_2 & w_2 \\
    \vdots \\
    u_{N - 1} & v_{N - 1} & w_{N - 1}
\end{matrix}
\]

\bbbold{Output}

\vspace{0.1in}

\bbenglish{Print a coloring of the vertices that satisfies the condition, in $N$ lines. The $i$-th line should contain \texttt{0} if Vertex $i$ is painted white and \texttt{1} if it is painted black.}

\vspace{0.1in}

\bbenglish{If there are multiple colorings that satisfy the condition, any of them will be accepted.}

## Text

\bbbold{Entrada}

\vspace{0.1in}

\bbtext{A entrada é dada na Entrada Padrão no seguinte formato: }
\[
\begin{matrix}
    N \\
    u_1 & v_1 & w_1 \\
    u_2 & v_2 & w_2 \\
    \vdots \\
    u_{N - 1} & v_{N - 1} & w_{N - 1}
\end{matrix}
\]

\bbbold{Saída}

\vspace{0.1in}

\bbtext{Imprima uma coloração dos vértices que satisfaça a condição, em $N$ linhas. A $i$-ésima linha deve conter \texttt{0} se o Vértice $i$ deve ser pintado branco ou \texttt{1} se ele deve ser pintado preto.}

\vspace{0.1in}

\bbtext{Se há múltiplas colorações que satisfaçam a condição, qualquer uma delas será aceita.}

## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{3} }
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
    @r.text = \footnotesize \bbcomment{\# número de vértices}

---
-r
-arrow
    
node1 => Node
    @node1.x = 7
    @node1.y = 2
    @node1.text = \bbtext{1}
    @node1.fill = BBGray
    &node1.draw
    &node1.very thick
    &node1.circle
    
node2 => Node
    @node2.x = 10
    @node2.y = 6
    @node2.text = \bbtext{2}
    @node2.fill = BBGray
    &node2.draw
    &node2.very thick
    &node2.circle

 node3 => Node
    @node3.x = 13
    @node3.y = 2
    @node3.text = \bbtext{3}
    @node3.fill = BBGray
    &node3.draw
    &node3.very thick
    &node3.circle

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{1 2 2} }
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
    @r.text = \footnotesize $u_1$

---

    @arrow.x = 1.65
    @arrow.u = 1.65
 
    @r.x = 1.65
    @r.text = \footnotesize $v_1$

---
    @arrow.x = 2.05
    @arrow.u = 2.05
 
    @r.x = 2.05
    @r.text = \footnotesize $w_1$

---
-arrow
-r

a12 => Edge
    @a12.from = node1
    @a12.to = node2
    &a12.thick
    %a12.label = node[above left] { \bbinfo{2} }

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{2 3 1} }
    @line3.anchor = west

---
a23 => Edge
    @a23.from = node2
    @a23.to = node3
    &a23.thick
    %a23.label = node[above right] { \bbinfo{1} }

---
    @node1.fill = BBWhite
        
---
    @node2.fill = BBWhite

---
    @node3.fill = BBBlack
    @node3.text = \textcolor{BBWhite}{\textbf{3}}

---
+r
+arrow

    @r.x = 1.65
    @r.y = 3.5
    @r.text = \bboutput{0 0 1}

    @arrow.x = 1.65
    @arrow.y = 4.75
    @arrow.u = 1.65
    @arrow.v = 3.75
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
    @line1.text = \bbtext{\texttt{5} }
    @line1.anchor = west

---
   
node1 => Node
    @node1.x = 6
    @node1.y = 5
    @node1.text = \bbtext{1}
    @node1.fill = BBGray
    &node1.draw
    &node1.very thick
    &node1.circle
    
node2 => Node
    @node2.x = 9
    @node2.y = 7
    @node2.text = \bbtext{2}
    @node2.fill = BBGray
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 12
    @node3.y = 5
    @node3.text = \bbtext{3}
    @node3.fill = BBGray
    &node3.draw
    &node3.very thick
    &node3.circle

node4 => Node
    @node4.x = 11
    @node4.y = 2
    @node4.text = \bbtext{4}
    @node4.fill = BBGray
    &node4.draw
    &node4.very thick
    &node4.circle
 
node5 => Node
    @node5.x = 7
    @node5.y = 2
    @node5.text = \bbtext{5}
    @node5.fill = BBGray
    &node5.draw
    &node5.very thick
    &node5.circle

---

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{2 5 2}}
    @line2.anchor = west

---

a25 => Edge
    @a25.from = node2
    @a25.to = node5
    &a25.thick
    %a25.label = node[above left,pos=0.8] { \bbinfo{2} }

---

line3 => Node
    @line3.x = 1
    @line3.y = 5.0
    @line3.text = \bbtext{\texttt{2 3 10}}
    @line3.anchor = west

---

a23 => Edge
    @a23.from = node2
    @a23.to = node3
    &a23.thick
    %a23.label = node[above right] { \bbinfo{10} }

---

line4 => Node
    @line4.x = 1
    @line4.y = 4.5
    @line4.text = \bbtext{\texttt{1 3 8}}
    @line4.anchor = west

---

a13 => Edge
    @a13.from = node1
    @a13.to = node3
    &a13.thick
    %a13.label = node[above left,pos=0.8] { \bbinfo{8} }

---

line5 => Node
    @line5.x = 1
    @line5.y = 4.0
    @line5.text = \bbtext{\texttt{3 4 2}}
    @line5.anchor = west

---

a34 => Edge
    @a34.from = node3
    @a34.to = node4
    &a34.thick
    %a34.label = node[above left] { \bbinfo{2} }


---
    @node1.fill = BBBlack
    @node1.text = \textcolor{BBWhite}{\textbf{1}}

---
    @node2.fill = BBWhite

---
    @node3.fill = BBBlack
    @node3.text = \textcolor{BBWhite}{\textbf{3}}

---
    @node4.fill = BBWhite

---
    @node5.fill = BBBlack
    @node5.text = \textcolor{BBWhite}{\textbf{5}}

---
r => Node
    @r.x = 1.65
    @r.y = 2.5
    @r.text = \bboutput{1 0 1 0 1}

arrow => Edge
    @arrow.x = 1.65
    @arrow.y = 3.75
    @arrow.u = 1.65
    @arrow.v = 2.75
    @arrow.color = BBBlack
    &arrow.-latex
    &arrow.very thick
 
## Scene

header => Node
    @header.y = 7
    @header.text = \Large \bbbold{Solução}
    @header.anchor = west

---

nodeA => Node
    @nodeA.x = 6
    @nodeA.y = 1.5
    @nodeA.text = \bbtext{A}
    @nodeA.fill = BBGray
    &nodeA.draw
    &nodeA.very thick
    &nodeA.circle

nodeB => Node
    @nodeB.x = 8
    @nodeB.y = 4.5
    @nodeB.text = \bbtext{B}
    @nodeB.fill = BBGray
    &nodeB.draw
    &nodeB.very thick
    &nodeB.circle

aAB => Edge
    @aAB.from = nodeA
    @aAB.to = nodeB
    &aAB.thick
    %aAB.label = node[above left] { $p$ }

---

info => Node
    @info.x = 1
    @info.y = 6
    @info.text = \bbtext{Se o peso $w$ é um número par $p$, ambos vértices devem ter a mesma cor}
    @info.anchor = west


---
    @nodeA.fill = BBWhite
    @nodeB.fill = BBWhite

---
-info
    @nodeA.fill = BBGray
    @nodeB.fill = BBGray
    %aAB.label = node[above left] { $i$ }

---
+info
    @info.text = \bbtext{Se o peso $w$ é um número ímpar $i$, ambos vértices devem ter cores distintas}

---
    @nodeA.fill = BBWhite
    @nodeB.fill = BBBlack
    @nodeB.text = \textcolor{BBWhite}{\textbf{B}}

---
-nodeA
-nodeB
-aAB

    @info.text = \bbtext{Estes dois critérios são suficientes para a resolução do problema!}

---
info2 => Node
    @info2.x = 7
    @info2.y = 5
    @info2.text = \bbcomment{Isto porque cada aresta com peso ímpar em um caminho}

info3 => Node
    @info3.x = 7
    @info3.y = 4.5
    @info3.text = \bbcomment{corresponde a uma troca de cores!}

---
-info3

    @info.text = \bbtext{Se a distância de $u$ a $v$ é par, ou todas arestas são pares, ou há um número}

    @info2.x = 0.5
    @info2.y = 5.5
    @info2.anchor = west

    @info2.text = \bbtext{par de arestas ímpares no caminho de $u$ a $v$.}

---
+nodeA
+nodeB
+aAB

    @nodeA.x = 2
    @nodeA.y = 2.5
    @nodeA.fill = BBGray

    @nodeB.x = 4
    @nodeB.y = 4
    @nodeB.fill = BBGray
    @nodeB.text = \bbtext{B}


nodeU => Node
    @nodeU.x = 5
    @nodeU.y = 1
    @nodeU.text = $u$
    @nodeU.fill = BBGray
    &nodeU.draw
    &nodeU.very thick
    &nodeU.circle

aBU => Edge
    @aBU.from = nodeU
    @aBU.to = nodeB
    &aBU.thick
    %aBU.label = node[above right] { $p$ }


nodeC => Node
    @nodeC.x = 7
    @nodeC.y = 2.5
    @nodeC.text = \bbtext{C}
    @nodeC.fill = BBGray
    &nodeC.draw
    &nodeC.very thick
    &nodeC.circle

aBC => Edge
    @aBC.from = nodeC
    @aBC.to = nodeB
    &aBC.thick
    %aBC.label = node[above] { $i$ }

nodeD => Node
    @nodeD.x = 9
    @nodeD.y = 4
    @nodeD.text = \bbtext{D}
    @nodeD.fill = BBGray
    &nodeD.draw
    &nodeD.very thick
    &nodeD.circle

aCD => Edge
    @aCD.from = nodeC
    @aCD.to = nodeD
    &aCD.thick
    %aCD.label = node[above] { $p$ }

nodeE => Node
    @nodeE.x = 9
    @nodeE.y = 1
    @nodeE.text = \bbtext{E}
    @nodeE.fill = BBGray
    &nodeE.draw
    &nodeE.very thick
    &nodeE.circle

aDE => Edge
    @aDE.from = nodeE
    @aDE.to = nodeD
    &aDE.thick
    %aDE.label = node[left] { $i$ }

nodeF => Node
    @nodeF.x = 13
    @nodeF.y = 1
    @nodeF.text = \bbtext{F}
    @nodeF.fill = BBGray
    &nodeF.draw
    &nodeF.very thick
    &nodeF.circle

aEF => Edge
    @aEF.from = nodeE
    @aEF.to = nodeF
    &aEF.thick
    %aEF.label = node[below] { $i$ }

nodeG => Node
    @nodeG.x = 12
    @nodeG.y = 4
    @nodeG.text = \bbtext{G}
    @nodeG.fill = BBGray
    &nodeG.draw
    &nodeG.very thick
    &nodeG.circle

aFG => Edge
    @aFG.from = nodeG
    @aFG.to = nodeF
    &aFG.thick
    %aFG.label = node[above right] { $p$ }


nodeV => Node
    @nodeV.x = 10
    @nodeV.y = 2.5
    @nodeV.text = $v$
    @nodeV.fill = BBGray
    &nodeV.draw
    &nodeV.very thick
    &nodeV.circle

aGV => Edge
    @aGV.from = nodeV
    @aGV.to = nodeG
    &aGV.thick
    %aGV.label = node[above] { $i$ }

---
    @nodeU.fill = BBWhite

---
    @nodeB.fill = BBWhite

---
    @nodeC.fill = BBBlack
    @nodeC.text = \textcolor{BBWhite}{\textbf{C}}

---
    @nodeD.fill = BBBlack
    @nodeD.text = \textcolor{BBWhite}{\textbf{D}}

---
    @nodeE.fill = BBWhite

---
    @nodeF.fill = BBBlack
    @nodeF.text = \textcolor{BBWhite}{\textbf{F}}

---
    @nodeG.fill = BBBlack
    @nodeG.text = \textcolor{BBWhite}{\textbf{G}}

---
    @nodeV.fill = BBWhite

---
    @nodeA.text = $u$
    @nodeB.fill = BBGray
    @nodeU.fill = BBGray
    @nodeU.text = \bbtext{A}
    @nodeC.fill = BBGray
    @nodeC.text = \bbtext{C}
    @nodeD.fill = BBGray
    @nodeD.text = \bbtext{D}
    @nodeE.fill = BBGray
    @nodeF.fill = BBGray
    @nodeF.text = \bbtext{F}
    @nodeG.fill = BBGray
    @nodeG.text = \bbtext{G}
    @nodeV.fill = BBGray
    @nodeV.text = \bbtext{H}
    @nodeE.text = $v$

---
    @nodeA.fill = BBWhite

---
    @nodeB.fill = BBBlack
    @nodeB.text = \textcolor{BBWhite}{\textbf{B}}

---
    @nodeC.fill = BBWhite

---
    @nodeD.fill = BBWhite

---
    @nodeE.fill = BBBlack
    @nodeE.text = $\textcolor{BBWhite}{v}$

## Frame

\inputsnippet{cpp}{10}{24}{codes/B126D.cpp}

## Frame

\inputsnippet{cpp}{26}{33}{codes/B126D.cpp}

## End
