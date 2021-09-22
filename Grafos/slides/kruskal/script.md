## Frame
\bbcover{Grafos}{Algoritmo de Kruskal}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Proponente}
    @title.anchor = west

floyd => Node
    @floyd.x = 7
    @floyd.y = 4
    @floyd.text = \includegraphics[scale=0.4]{figs/kruskal.jpeg}

fname => Node
    @fname.x = 7
    @fname.y = 1
    @fname.text = \bbbold{Joseph Bernard Kruskal, Jr.}

fdate => Node
    @fdate.x = 7
    @fdate.y = 0.5
    @fdate.text = \bbtext{(1962)}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Características do algoritmo de Kruskal}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{O algoritmo de Kruskal encontra uma MST usando uma abordagem gulosa}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{As arestas são ordenadas, ascendentemente, por peso}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{Inicialmente os vértices formam uma floresta de vértices isolados}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $\star$ \bbtext{Na ordem estipulada, cada aresta que una dois componentes conectados}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 2.5
    @d1.text = \bbtext{fará parte da MST e unirá estes componentes distintos}
    @d1.anchor = west


---

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $\star$ \bbtext{\bbbold{Complexidade}: $O(E\log V)$ }
    @e.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Pseudocódigo}
    @title.anchor = west

---

input => Node
    @input.x = 0.5
    @input.y = 6
    @input.text = \bbemph{Entrada:} \bbtext{um grafo ponderado $G(V, E)$}
    @input.anchor = west

output => Node
    @output.x = 0.5
    @output.y = 5.5
    @output.text = \bbemph{Saída:} \bbtext{uma MST de $G$}
    @output.anchor = west

---

step1 => Node
    @step1.x = 1.0
    @step1.y = 4.5
    @step1.text = $1.$ \bbtext{Faça $M = \emptyset$ e seja $F(V, \emptyset)$ uma floresta de vértices isolados}
    @step1.anchor = west

---

step2 => Node
    @step2.x = 1.0
    @step2.y = 3.5
    @step2.text = $2.$ \bbtext{Ordene $E$ ascendentemente, por peso} 
    @step2.anchor = west

---

step3 => Node
    @step3.x = 1.0
    @step3.y = 2.5
    @step3.text = $3.$ \bbtext{Para cada $(u, v, w)\in E$, se $u$ e $v$ estão em componentes distintos de $F$:}
    @step3.anchor = west

step3a => Node
    @step3a.x = 2.0
    @step3a.y = 2.0
    @step3a.text = $(a)$ \bbtext{una estes componentes em $F$}
    @step3a.anchor = west

step3b => Node
    @step3b.x = 2.0
    @step3b.y = 1.5
    @step3b.text = $(b)$ \bbtext{inclua $(u, v, w)$ no conjunto $M$}
    @step3b.anchor = west

---

step4 => Node
    @step4.x = 1.0
    @step4.y = 0.5
    @step4.text = $4.$ \bbtext{Retorne $M$}
    @step4.anchor = west

## Scene

x1 => Node
    @x1.x = 10
    @x1.y = 6
    @x1.text = \bbtext{\tt 1 2 3}
    @x1.anchor = west

x2 => Node
    @x2.x = 10
    @x2.y = 5.5
    @x2.text = \bbtext{\tt 1 4 5}
    @x2.anchor = west

x3 => Node
    @x3.x = 10
    @x3.y = 5.0
    @x3.text = \bbtext{\tt 2 4 1}
    @x3.anchor = west

x4 => Node
    @x4.x = 10
    @x4.y = 4.5
    @x4.text = \bbtext{\tt 2 1 5}
    @x4.anchor = west

x5 => Node
    @x5.x = 10
    @x5.y = 4.0
    @x5.text = \bbtext{\tt 3 3 4}
    @x5.anchor = west

x6 => Node
    @x6.x = 10
    @x6.y = 3.5
    @x6.text = \bbtext{\tt 4 2 1}
    @x6.anchor = west

x7 => Node
    @x7.x = 10
    @x7.y = 3
    @x7.text = \bbtext{\tt 5 3 1}
    @x7.anchor = west

x8 => Node
    @x8.x = 10
    @x8.y = 2.5
    @x8.text = \bbtext{\tt 7 3 6}
    @x8.anchor = west

x9 => Node
    @x9.x = 10
    @x9.y = 2
    @x9.text = \bbtext{\tt 8 6 5}
    @x9.anchor = west

E => Node
    @E.x = 10.4
    @E.y = 6.75
    @E.text = \large $E$
    @E.anchor = west


node1 => Node
    @node1.x = 6
    @node1.y = 5
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

 node2 => Node
    @node2.x = 4
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

 node3 => Node
    @node3.x = 2
    @node3.y = 5
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

 node4 => Node
    @node4.x = 6
    @node4.y = 3
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

 node5 => Node
    @node5.x = 4
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

 node6 => Node
    @node6.x = 2
    @node6.y = 3
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

---

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.thick
    %e23.label = node[above left] {\footnotesize \bbinfo{1}}

    @x1.text = \bbtext{\tt 1 2 3}\ \ \footnotesize{\textcolor{BBGreen}{\faCheck}}

---

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    %e45.label = node[below right] {\footnotesize \bbinfo{1}}

    @x2.text = \bbtext{\tt 1 4 5}\ \ \footnotesize{\textcolor{BBGreen}{\faCheck}}

---

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    %e14.label = node[right] {\footnotesize \bbinfo{2}}

    @x3.text = \bbtext{\tt 2 4 1}\ \ \footnotesize{\textcolor{BBGreen}{\faCheck}}

---

    @x4.text = \bbtext{\tt 2 1 5}\ \ \footnotesize{\textcolor{BBRed}{\faClose}}

---

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    %e34.label = node[above] {\footnotesize \bbinfo{3}}

    @x5.text = \bbtext{\tt 3 3 4}\ \ \footnotesize{\textcolor{BBGreen}{\faCheck}}

---

    @x6.text = \bbtext{\tt 4 2 1}\ \ \footnotesize{\textcolor{BBRed}{\faClose}}

---

    @x7.text = \bbtext{\tt 5 3 1}\ \ \footnotesize{\textcolor{BBRed}{\faClose}}

---

e36 => Edge
    @e36.from = node3
    @e36.to = node6
    &e36.thick
    %e36.label = node[below left] {\footnotesize \bbinfo{7}}

    @x8.text = \bbtext{\tt 7 3 6}\ \ \footnotesize{\textcolor{BBGreen}{\faCheck}}

---

    @x9.text = \bbtext{\tt 8 6 5}\ \ \footnotesize{\textcolor{BBRed}{\faClose}}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Identificação e união dos componentes conectados}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{A complexidade do algoritmo de Kruskal depende da identificação e união}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.5
    @a1.text = \bbtext{eficiente dos componentes conectados}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{A \bbenglish{union-find disjoint sets} (UFDS) (também conhecida como \bbenglish{disjoint set union}}
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.0
    @b1.text = \bbtext{-- DSU) é uma estrutura de dados que atende a esta demanda}
    @b1.anchor = west


---

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $\star$ \bbtext{A operação \texttt{same\_set($u$, $v$)} retorna verdadeiro se ambos $u$ e $v$ pertencem}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 2.5
    @c1.text = \bbtext{ao mesmo componente conectado, em $O(\log V)$}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 1.5
    @d.text = $\star$ \bbtext{A operação \texttt{union\_set($u$, $v$)} une os componentes distintos onde estão}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 1.0
    @d1.text = \bbtext{localizados $u$ e $v$, também em $O(\log V)$}
    @d1.anchor = west


## Frame

\inputsnippet{cpp}{46}{63}{codes/kruskal.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Aplicação: Floresta mínima geradora}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{Uma floresta mínima geradora $F_k$ pode ser identificada por meio de uma}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.0
    @a1.text = \bbtext{modificação simples no algoritmo de Kruskal}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.0
    @b.text = $\star$ \bbtext{Inicialmente, a floresta de vértices isolados contém $V$ componentes}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.0
    @c.text = $\star$ \bbtext{A cada união de componentes, o total é reduzido em uma unidade}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.0
    @d.text = $\star$ \bbtext{Quando a contagem de componentes for igual a $k$, o algoritmo deve ser }
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 1.5
    @d1.text = \bbtext{encerrado}
    @d1.anchor = west

## Scene

nodeA => Node
    @nodeA.x = 3
    @nodeA.y = 3
    @nodeA.text = \bbtext{A}
    &nodeA.draw
    &nodeA.very thick
    &nodeA.circle
 
nodeB => Node
    @nodeB.x = 4.5
    @nodeB.y = 5.5
    @nodeB.text = \bbtext{B}
    &nodeB.draw
    &nodeB.very thick
    &nodeB.circle
 
nodeC => Node
    @nodeC.x = 7
    @nodeC.y = 1
    @nodeC.text = \bbtext{C}
    &nodeC.draw
    &nodeC.very thick
    &nodeC.circle
 
nodeD => Node
    @nodeD.x = 7
    @nodeD.y = 7
    @nodeD.text = \bbtext{D}
    &nodeD.draw
    &nodeD.very thick
    &nodeD.circle
 
nodeE => Node
    @nodeE.x = 9
    @nodeE.y = 4.5
    @nodeE.text = \bbtext{E}
    &nodeE.draw
    &nodeE.very thick
    &nodeE.circle
 
nodeF => Node
    @nodeF.x = 11
    @nodeF.y = 3.5
    @nodeF.text = \bbtext{F}
    &nodeF.draw
    &nodeF.very thick
    &nodeF.circle
 
nodeG => Node
    @nodeG.x = 13
    @nodeG.y = 5
    @nodeG.text = \bbtext{G}
    &nodeG.draw
    &nodeG.very thick
    &nodeG.circle
 
nodeH => Node
    @nodeH.x = 11
    @nodeH.y = 7
    @nodeH.text = \bbtext{H}
    &nodeH.draw
    &nodeH.very thick
    &nodeH.circle
 
eAB => Edge
    @eAB.from = nodeA
    @eAB.to = nodeB
    &eAB.thick
    %eAB.label = node[above left] { \footnotesize \bbinfo{1} }
 
eAC => Edge
    @eAC.from = nodeA
    @eAC.to = nodeC
    &eAC.thick
    %eAC.label = node[above] { \footnotesize \bbinfo{8} }
 
eBD => Edge
    @eBD.from = nodeB
    @eBD.to = nodeD
    &eBD.thick
    %eBD.label = node[above left] { \footnotesize \bbinfo{5} }
 
eBE => Edge
    @eBE.from = nodeB
    @eBE.to = nodeE
    &eBE.thick
    %eBE.label = node[above left,pos=0.2] { \footnotesize \bbinfo{3} }
 
eCD => Edge
    @eCD.from = nodeC
    @eCD.to = nodeD
    &eCD.thick
    %eCD.label = node[left,pos=0.3] { \footnotesize \bbinfo{9} }
 
eCE => Edge
    @eCE.from = nodeC
    @eCE.to = nodeE
    &eCE.thick
    %eCE.label = node[below right] { \footnotesize \bbinfo{7} }
 
eCG => Edge
    @eCG.from = nodeC
    @eCG.to = nodeG
    &eCG.thick
    %eCG.label = [bend right] node[below] { \footnotesize \bbinfo{5} }
 
eDE => Edge
    @eDE.from = nodeD
    @eDE.to = nodeE
    &eDE.thick
    %eDE.label = node[above right] { \footnotesize \bbinfo{7} }
 
eEF => Edge
    @eEF.from = nodeE
    @eEF.to = nodeF
    &eEF.thick
    %eEF.label = node[above right] { \footnotesize \bbinfo{2} }

eEH => Edge
    @eEH.from = nodeE
    @eEH.to = nodeH
    &eEH.thick
    %eEH.label = node[above left] { \footnotesize \bbinfo{4} }

eFG => Edge
    @eFG.from = nodeF
    @eFG.to = nodeG
    &eFG.thick
    %eFG.label = node[above left] { \footnotesize \bbinfo{6} }
 
eFH => Edge
    @eFH.from = nodeF
    @eFH.to = nodeH
    &eFH.thick
    %eFH.label = node[left] { \footnotesize \bbinfo{3} }
 
k => Node
    @k.x = 0
    @k.y = 7.5
    @k.text = \footnotesize $k = 4$
    @k.anchor = west

c => Node
    @c.x = 0
    @c.y = 6.75
    @c.text = \footnotesize \bbtext{componentes: $8$}
    @c.anchor = west

-eAB
-eAC
-eBD
-eBE
-eCD
-eCE
-eCG
-eDE
-eEF
-eEH
-eFH
-eFG

---

edge => Node
    @edge.x = 0
    @edge.y = 6.0
    @edge.text = \footnotesize \bbtext{próxima aresta: {\tt 1 A B}}
    @edge.anchor = west

---

+eAB
    &eAB.very thick
    &eAB.dashed
    @eAB.color = BBCyan

    @c.text = \footnotesize \bbtext{componentes: $\mathbf{7}$}

---

    @edge.text = \footnotesize \bbtext{próxima aresta: {\tt 2 E F}}
    @c.text = \footnotesize \bbtext{componentes: ${7}$}

---

+eEF
    &eEF.very thick
    &eEF.dashed
    @eEF.color = BBViolet

    @c.text = \footnotesize \bbtext{componentes: $\mathbf{6}$}

---
    @edge.text = \footnotesize \bbtext{próxima aresta: {\tt 3 F H}}
    @c.text = \footnotesize \bbtext{componentes: ${6}$}

---

+eFH
    &eFH.very thick
    &eFH.dashed
    @eFH.color = BBViolet

    @c.text = \footnotesize \bbtext{componentes: $\mathbf{5}$}
---

    @edge.text = \footnotesize \bbtext{próxima aresta: {\tt 4 E H}}
    @c.text = \footnotesize \bbtext{componentes: ${5}$}

---
    @edge.text = \footnotesize \bbtext{próxima aresta: {\tt 4 E H}}\ \ \ \textcolor{BBRed}{\faClose}

---
    @edge.text = \footnotesize \bbtext{próxima aresta: {\tt 5 C G}}

---

+eCG
    &eCG.very thick
    &eCG.dashed
    @eCG.color = BBGreen

    @c.text = \footnotesize \bbtext{componentes: $\mathbf{4}$}
  
## Frame

\inputsnippet{cpp}{46}{65}{codes/msf.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Aplicação: Segunda melhor MST}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Algumas aplicações demandam a identificação da segunda melhor MST}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Esta segunda melhor MST, se existir, pode ser identificada por meio de } 
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.5
    @b1.text = \bbtext{uma nova modificação no algoritmo de Kruskal}
    @b1.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Primeiramente, deve ser identificada a MST}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{Em seguida, cada uma das arestas da MST deve ser excluída e o algoritmo}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 2.0
    @d1.text = \bbtext{deve identificar a MST formada pelas arestas restantes}
    @d1.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1.0
    @e.text = $\star$ \bbbold{Complexidade:} $O(VE)$
    @e.anchor = west

## Scene

nodeA => Node
    @nodeA.x = 6
    @nodeA.y = 7
    @nodeA.text = \bbtext{A}
    &nodeA.draw
    &nodeA.very thick
    &nodeA.circle
 
nodeB => Node
    @nodeB.x = 10
    @nodeB.y = 7
    @nodeB.text = \bbtext{B}
    &nodeB.draw
    &nodeB.very thick
    &nodeB.circle

nodeC => Node
    @nodeC.x = 12
    @nodeC.y = 4
    @nodeC.text = \bbtext{C}
    &nodeC.draw
    &nodeC.very thick
    &nodeC.circle

nodeD => Node
    @nodeD.x = 8
    @nodeD.y = 1
    @nodeD.text = \bbtext{D}
    &nodeD.draw
    &nodeD.very thick
    &nodeD.circle

nodeE => Node
    @nodeE.x = 4
    @nodeE.y = 4
    @nodeE.text = \bbtext{E}
    &nodeE.draw
    &nodeE.very thick
    &nodeE.circle
 
eAB => Edge
    @eAB.from = nodeA
    @eAB.to = nodeB
    &eAB.thick
    %eAB.label = node[above] { \footnotesize \bbinfo{1} }

eAC => Edge
    @eAC.from = nodeA
    @eAC.to = nodeC
    &eAC.thick
    %eAC.label = node[above right] { \footnotesize \bbinfo{4} }
 
eAD => Edge
    @eAD.from = nodeA
    @eAD.to = nodeD
    &eAD.thick
    %eAD.label = node[below left,pos=0.2] { \footnotesize \bbinfo{4} }
 
eAE => Edge
    @eAE.from = nodeA
    @eAE.to = nodeE
    &eAE.thick
    %eAE.label = node[left] { \footnotesize \bbinfo{3} }
 
eBC => Edge
    @eBC.from = nodeB
    @eBC.to = nodeC
    &eBC.thick
    %eBC.label = node[above right] { \footnotesize \bbinfo{5} }
 
eCD => Edge
    @eCD.from = nodeC
    @eCD.to = nodeD
    &eCD.thick
    %eCD.label = node[below right] { \footnotesize \bbinfo{5} }
 
eCE => Edge
    @eCE.from = nodeC
    @eCE.to = nodeE
    &eCE.thick
    %eCE.label = node[above, pos=0.3] { \footnotesize \bbinfo{2} }
 
eDE => Edge
    @eDE.from = nodeD
    @eDE.to = nodeE
    &eDE.thick
    %eDE.label = node[below left] { \footnotesize \bbinfo{3} }
 
---

tree => Node
    @tree.x = 0
    @tree.y = 7
    @tree.text = \bbtext{MST}
    @tree.anchor = west

cost => Node
    @cost.x = 0
    @cost.y = 6.25
    @cost.text = $c($\bbtext{MST}$) = 9$
    @cost.anchor = west

    @eAB.color = BBCyan
    &eAB.dashed
    &eAB.very thick

    @eAE.color = BBCyan
    &eAE.dashed
    &eAE.very thick

    @eCE.color = BBCyan
    &eCE.dashed
    &eCE.very thick

    @eDE.color = BBCyan
    &eDE.dashed
    &eDE.very thick

---

    @tree.text = \bbtext{Árvore geradora $T_1$}
    @cost.text = $c(T_1) = 13$

-eAB

    @eAE.color = BBGreen
    @eCE.color = BBGreen
    @eDE.color = BBGreen

    @eBC.color = BBGreen
    &eBC.dashed
    &eBC.very thick

---

    @tree.text = \bbtext{Árvore geradora $T_2$}
    @cost.text = $c(T_2) = 11$

+eAB
-eCE
-eBC

eBC1 => Edge
    @eBC1.from = nodeB
    @eBC1.to = nodeC
    &eBC1.thick
    %eBC1.label = node[above right] { \footnotesize \bbinfo{5} }
 
    @eAB.color = BBViolet
    @eAC.color = BBViolet
    @eAE.color = BBViolet
    @eDE.color = BBViolet

    &eAC.dashed
    &eAC.very thick

---

    @tree.text = \bbtext{Árvore geradora $T_3$}
    @cost.text = $c(T_3) = 10$

+eCE
-eAE

    @eAB.color = BBRed
    @eAC.color = BBRed
    @eCE.color = BBRed
    @eDE.color = BBRed

---

    @tree.text = \bbtext{Árvore geradora $T_4$}
    @cost.text = $c(T_4) = 10$

-eDE
+eAE

    @eAB.color = BBGray
    @eAD.color = BBGray
    @eAE.color = BBGray
    @eCE.color = BBGray

    &eAD.dashed
    &eAD.very thick

-eAC

eAC1 => Edge
    @eAC1.from = nodeA
    @eAC1.to = nodeC
    &eAC1.thick
    %eAC1.label = node[above right] { \footnotesize \bbinfo{4} }
 
## Frame

\inputsnippet{cpp}{48}{67}{codes/second_best.cpp}

## Frame

\inputsnippet{cpp}{69}{83}{codes/second_best.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Problemas sugeridos}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $1.$ \bbtext{Codechef CHEFELEC -- Chefland and Electricity}
    @a.anchor = west

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $2.$ \bbtext{OJ 10369 -- Artic Network}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $3.$ \bbtext{OJ 10600 -- ACM Contest and Blackout}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $4.$ \bbtext{SPOJ EC\_MODE -- Modems}
    @d.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Referências}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $1.$ \bbtext{\bbbold{CP-Algorithm}. \bbenglish{Minimum spanning tree -- Kruskal's algorithm}, acesso em}
    @a.anchor = west

a1 => Node
    @a1.x = 2
    @a1.y = 5.5
    @a1.text = \bbtext{24/08/2021.}
    @a1.anchor = west

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $2.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $3.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $4.$ \bbbold{Wikipédia}. \bbenglish{Joseph Kruskal,} \bbtext{acesso em 24/08/2021.}
    @d.anchor = west

e => Node
    @e.x = 1
    @e.y = 1.5
    @e.text = $5.$ \bbbold{Wikipédia}. \bbenglish{Kruskal's algorithm,} \bbtext{acesso em 24/08/2021.}
    @e.anchor = west

## End
