## Frame
\bbcover{Grafos}{Árvore Geradora Mínima: Definição}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Árvores geradoras}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = \bbtext{Seja $G(V, E)$ um grafo. Uma \bbbold{árvore geradora} de $G$ é um subgrafo $T(V, E')$}
    @a.anchor = west

b => Node
    @b.x = 0.5
    @b.y = 4.25
    @b.text = \bbtext{de $G$ tal que $T$ é uma árvore que contém todos os vértices de $G$.}
    @b.anchor = west

## Scene

nodeA => Node
    @nodeA.x = 2
    @nodeA.y = 3
    @nodeA.text = \bbtext{A}
    &nodeA.draw
    &nodeA.very thick
    &nodeA.circle
 
nodeB => Node
    @nodeB.x = 3.5
    @nodeB.y = 5.5
    @nodeB.text = \bbtext{B}
    &nodeB.draw
    &nodeB.very thick
    &nodeB.circle
 
nodeC => Node
    @nodeC.x = 6
    @nodeC.y = 1
    @nodeC.text = \bbtext{C}
    &nodeC.draw
    &nodeC.very thick
    &nodeC.circle
 
nodeD => Node
    @nodeD.x = 6
    @nodeD.y = 7
    @nodeD.text = \bbtext{D}
    &nodeD.draw
    &nodeD.very thick
    &nodeD.circle
 
nodeE => Node
    @nodeE.x = 8
    @nodeE.y = 4.5
    @nodeE.text = \bbtext{E}
    &nodeE.draw
    &nodeE.very thick
    &nodeE.circle
 
nodeF => Node
    @nodeF.x = 10
    @nodeF.y = 3.5
    @nodeF.text = \bbtext{F}
    &nodeF.draw
    &nodeF.very thick
    &nodeF.circle
 
nodeG => Node
    @nodeG.x = 12
    @nodeG.y = 5
    @nodeG.text = \bbtext{G}
    &nodeG.draw
    &nodeG.very thick
    &nodeG.circle
 
nodeH => Node
    @nodeH.x = 10
    @nodeH.y = 7
    @nodeH.text = \bbtext{H}
    &nodeH.draw
    &nodeH.very thick
    &nodeH.circle
 
eAB => Edge
    @eAB.from = nodeA
    @eAB.to = nodeB
    &eAB.thick
 
eAC => Edge
    @eAC.from = nodeA
    @eAC.to = nodeC
    &eAC.thick
 
eBD => Edge
    @eBD.from = nodeB
    @eBD.to = nodeD
    &eBD.thick
 
eBE => Edge
    @eBE.from = nodeB
    @eBE.to = nodeE
    &eBE.thick
 
eCD => Edge
    @eCD.from = nodeC
    @eCD.to = nodeD
    &eCD.thick
 
eCE => Edge
    @eCE.from = nodeC
    @eCE.to = nodeE
    &eCE.thick
 
eCG => Edge
    @eCG.from = nodeC
    @eCG.to = nodeG
    &eCG.thick
    %eCG.label = [bend right]
 
eDE => Edge
    @eDE.from = nodeD
    @eDE.to = nodeE
    &eDE.thick
 
eEF => Edge
    @eEF.from = nodeE
    @eEF.to = nodeF
    &eEF.thick

eEH => Edge
    @eEH.from = nodeE
    @eEH.to = nodeH
    &eEH.thick

eFG => Edge
    @eFG.from = nodeF
    @eFG.to = nodeG
    &eFG.thick
 
eFH => Edge
    @eFH.from = nodeF
    @eFH.to = nodeH
    &eFH.thick
 
---

    &eAC.very thick
    &eCD.very thick
    &eCE.very thick
    &eBE.very thick
    &eEF.very thick
    &eFH.very thick
    &eFG.very thick

    &eAC.dashed
    &eCD.dashed
    &eCE.dashed
    &eBE.dashed
    &eEF.dashed
    &eFH.dashed
    &eFG.dashed

    @eAC.color = BBCyan
    @eCD.color = BBCyan
    @eCE.color = BBCyan
    @eBE.color = BBCyan
    @eEF.color = BBCyan
    @eFH.color = BBCyan
    @eFG.color = BBCyan

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Árvore mínima geradora}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = \bbtext{Seja $G(V, E)$ um grafo ponderado. Uma árvore geradora $T(V, E')$ de $G$ é}
    @a.anchor = west

b => Node
    @b.x = 0.5
    @b.y = 4.25
    @b.text = \bbtext{uma \bbbold{árvore mínima geradora} (MST) de $G$ se a soma}
    @b.anchor = west

c => Node
    @c.x = 7
    @c.y = 3.25
    @c.text = $\displaystyle c(T) = \sum_{e\in E'} w(e)$

d => Node
    @d.x = 0.5
    @d.y = 2.5
    @d.text = \bbtext{é mínima.}
    @d.anchor = west

## Scene

nodeA => Node
    @nodeA.x = 2
    @nodeA.y = 3
    @nodeA.text = \bbtext{A}
    &nodeA.draw
    &nodeA.very thick
    &nodeA.circle
 
nodeB => Node
    @nodeB.x = 3.5
    @nodeB.y = 5.5
    @nodeB.text = \bbtext{B}
    &nodeB.draw
    &nodeB.very thick
    &nodeB.circle
 
nodeC => Node
    @nodeC.x = 6
    @nodeC.y = 1
    @nodeC.text = \bbtext{C}
    &nodeC.draw
    &nodeC.very thick
    &nodeC.circle
 
nodeD => Node
    @nodeD.x = 6
    @nodeD.y = 7
    @nodeD.text = \bbtext{D}
    &nodeD.draw
    &nodeD.very thick
    &nodeD.circle
 
nodeE => Node
    @nodeE.x = 8
    @nodeE.y = 4.5
    @nodeE.text = \bbtext{E}
    &nodeE.draw
    &nodeE.very thick
    &nodeE.circle
 
nodeF => Node
    @nodeF.x = 10
    @nodeF.y = 3.5
    @nodeF.text = \bbtext{F}
    &nodeF.draw
    &nodeF.very thick
    &nodeF.circle
 
nodeG => Node
    @nodeG.x = 12
    @nodeG.y = 5
    @nodeG.text = \bbtext{G}
    &nodeG.draw
    &nodeG.very thick
    &nodeG.circle
 
nodeH => Node
    @nodeH.x = 10
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
 
---

    &eAB.very thick
    &eAB.dashed
    @eAB.color = BBCyan

    &eEF.very thick
    &eEF.dashed
    @eEF.color = BBCyan

    &eFH.very thick
    &eFH.dashed
    @eFH.color = BBCyan

    &eBE.very thick
    &eBE.dashed
    @eBE.color = BBCyan

    &eBD.very thick
    &eBD.dashed
    @eBD.color = BBCyan

    &eCG.very thick
    &eCG.dashed
    @eCG.color = BBCyan

    &eCE.very thick
    &eCE.dashed
    @eCE.color = BBCyan

---

info => Node
    @info.x = 1
    @info.y = 7
    @info.text = $\displaystyle c(T) = 32$

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Propriedades da árvore mínima geradora}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{A MST é única apenas se todos os pesos forem distintos}
    @a.anchor = west
---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{A MST minimiza o produto dos pesos, se as arestas forem positivas}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{A árvore máxima geradora pode ser obtida invertendo os sinais dos pesos}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.5
    @c1.text = \bbtext{de todas das arestas}
    @c1.anchor = west


---

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{A MST minimiza o peso máximo das arestas, quando consideradas todas}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 2.0
    @d1.text = \bbtext{as árvores geradoras (minimax)}
    @d1.anchor = west

## Scene

nodeA => Node
    @nodeA.x = 2
    @nodeA.y = 3
    @nodeA.text = \bbtext{A}
    &nodeA.draw
    &nodeA.very thick
    &nodeA.circle
 
nodeB => Node
    @nodeB.x = 3.5
    @nodeB.y = 5.5
    @nodeB.text = \bbtext{B}
    &nodeB.draw
    &nodeB.very thick
    &nodeB.circle
 
nodeC => Node
    @nodeC.x = 6
    @nodeC.y = 1
    @nodeC.text = \bbtext{C}
    &nodeC.draw
    &nodeC.very thick
    &nodeC.circle
 
nodeD => Node
    @nodeD.x = 6
    @nodeD.y = 7
    @nodeD.text = \bbtext{D}
    &nodeD.draw
    &nodeD.very thick
    &nodeD.circle
 
nodeE => Node
    @nodeE.x = 8
    @nodeE.y = 4.5
    @nodeE.text = \bbtext{E}
    &nodeE.draw
    &nodeE.very thick
    &nodeE.circle
 
nodeF => Node
    @nodeF.x = 10
    @nodeF.y = 3.5
    @nodeF.text = \bbtext{F}
    &nodeF.draw
    &nodeF.very thick
    &nodeF.circle
 
nodeG => Node
    @nodeG.x = 12
    @nodeG.y = 5
    @nodeG.text = \bbtext{G}
    &nodeG.draw
    &nodeG.very thick
    &nodeG.circle
 
nodeH => Node
    @nodeH.x = 10
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
 
---

    &eCD.very thick
    &eCD.dashed
    @eCD.color = BBCyan

    &eAC.very thick
    &eAC.dashed
    @eAC.color = BBCyan

    &eDE.very thick
    &eDE.dashed
    @eDE.color = BBCyan

    &eEH.very thick
    &eEH.dashed
    @eEH.color = BBCyan

    &eFG.very thick
    &eFG.dashed
    @eFG.color = BBCyan

    &eCG.very thick
    &eCG.dashed
    @eCG.color = BBCyan

    &eBD.very thick
    &eBD.dashed
    @eBD.color = BBCyan

info => Node
    @info.x = 0
    @info.y = 7
    @info.text = \footnotesize \bbtext{Árvore geradora máxima}
    @info.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Subgrafo gerador mínimo}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = \bbtext{Seja $G(V, E)$ um grafo ponderado e $X\subset E$. O \bbbold{subgrafo gerador mínimo}}
    @a.anchor = west

b => Node
    @b.x = 0.5
    @b.y = 4.25
    @b.text = \bbtext{$S_X(V, E')$ de $G$ é o subgrafo de $S_X$ de $G$, de custo mínimo, tal que $X \subseteq E'$.}
    @b.anchor = west

## Scene

nodeA => Node
    @nodeA.x = 2
    @nodeA.y = 3
    @nodeA.text = \bbtext{A}
    &nodeA.draw
    &nodeA.very thick
    &nodeA.circle
 
nodeB => Node
    @nodeB.x = 3.5
    @nodeB.y = 5.5
    @nodeB.text = \bbtext{B}
    &nodeB.draw
    &nodeB.very thick
    &nodeB.circle
 
nodeC => Node
    @nodeC.x = 6
    @nodeC.y = 1
    @nodeC.text = \bbtext{C}
    &nodeC.draw
    &nodeC.very thick
    &nodeC.circle
 
nodeD => Node
    @nodeD.x = 6
    @nodeD.y = 7
    @nodeD.text = \bbtext{D}
    &nodeD.draw
    &nodeD.very thick
    &nodeD.circle
 
nodeE => Node
    @nodeE.x = 8
    @nodeE.y = 4.5
    @nodeE.text = \bbtext{E}
    &nodeE.draw
    &nodeE.very thick
    &nodeE.circle
 
nodeF => Node
    @nodeF.x = 10
    @nodeF.y = 3.5
    @nodeF.text = \bbtext{F}
    &nodeF.draw
    &nodeF.very thick
    &nodeF.circle
 
nodeG => Node
    @nodeG.x = 12
    @nodeG.y = 5
    @nodeG.text = \bbtext{G}
    &nodeG.draw
    &nodeG.very thick
    &nodeG.circle
 
nodeH => Node
    @nodeH.x = 10
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
 

    &eCD.very thick
    &eCD.dashed
    @eCD.color = BBRed
    &eCE.very thick
    &eCE.dashed
    @eCE.color = BBRed
    &eDE.very thick
    @eDE.color = BBRed
    &eDE.dashed
---

    &eAB.very thick
    &eAB.dashed
    @eAB.color = BBCyan

    &eEF.very thick
    &eEF.dashed
    @eEF.color = BBCyan

    &eFH.very thick
    &eFH.dashed
    @eFH.color = BBCyan

    &eCG.very thick
    &eCG.dashed
    @eCG.color = BBCyan

    &eBE.very thick
    &eBE.dashed
    @eBE.color = BBCyan

info => Node
    @info.x = 0
    @info.y = 7
    @info.text = \footnotesize \bbtext{Subgrafo gerador mínimo}
    @info.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Floresta geradora mínima}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = \bbtext{Seja $G(V, E)$ um grafo ponderado. A \bbbold{floresta mínima geradora} $F_k$ de $G$}
    @a.anchor = west

b => Node
    @b.x = 0.5
    @b.y = 4.25
    @b.text = \bbtext{é um subgrafo $F_k(V, E')$ de $G$, de custo mínimo, formado por exatamente $k$}
    @b.anchor = west

c => Node
    @c.x = 0.5
    @c.y = 3.5
    @c.text = \bbtext{componentes conectados, sendo cada componente conectado uma árvore.}
    @c.anchor = west

## Scene

nodeA => Node
    @nodeA.x = 2
    @nodeA.y = 3
    @nodeA.text = \bbtext{A}
    &nodeA.draw
    &nodeA.very thick
    &nodeA.circle
 
nodeB => Node
    @nodeB.x = 3.5
    @nodeB.y = 5.5
    @nodeB.text = \bbtext{B}
    &nodeB.draw
    &nodeB.very thick
    &nodeB.circle
 
nodeC => Node
    @nodeC.x = 6
    @nodeC.y = 1
    @nodeC.text = \bbtext{C}
    &nodeC.draw
    &nodeC.very thick
    &nodeC.circle
 
nodeD => Node
    @nodeD.x = 6
    @nodeD.y = 7
    @nodeD.text = \bbtext{D}
    &nodeD.draw
    &nodeD.very thick
    &nodeD.circle
 
nodeE => Node
    @nodeE.x = 8
    @nodeE.y = 4.5
    @nodeE.text = \bbtext{E}
    &nodeE.draw
    &nodeE.very thick
    &nodeE.circle
 
nodeF => Node
    @nodeF.x = 10
    @nodeF.y = 3.5
    @nodeF.text = \bbtext{F}
    &nodeF.draw
    &nodeF.very thick
    &nodeF.circle
 
nodeG => Node
    @nodeG.x = 12
    @nodeG.y = 5
    @nodeG.text = \bbtext{G}
    &nodeG.draw
    &nodeG.very thick
    &nodeG.circle
 
nodeH => Node
    @nodeH.x = 10
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
    %eBE.label = node[above left,pos=0.2] { \footnotesize \bbinfo{8} }
 
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
 
---
    &eAB.very thick
    &eAB.dashed
    @eAB.color = BBCyan

    @eAC.opacity = 0
    @eBD.opacity = 0
    @eBE.opacity = 0
    @eCD.opacity = 0
    @eCE.opacity = 0
    @eDE.opacity = 0
    @eEH.opacity = 0
    @eFG.opacity = 0

    &eAC.very thick
    &eAC.dashed
    @eAC.color = BBCyan

    &eCG.very thick
    &eCG.dashed
    @eCG.color = BBGreen

    &eEF.very thick
    &eEF.dashed
    @eEF.color = BBViolet

    &eFH.very thick
    &eFH.dashed
    @eFH.color = BBViolet

info => Node
    @info.x = 0
    @info.y = 7
    @info.text = \footnotesize \bbtext{Floresta mínima geradora $F_4$}
    @info.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Referências}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $1.$ \bbtext{\bbbold{CP-Algorithm}. \bbenglish{Minimum spanning tree -- Kruskall's algorithm}, acesso em}
    @a.anchor = west

a1 => Node
    @a1.x = 2
    @a1.y = 5.5
    @a1.text = \bbtext{24/08/2021.}
    @a1.anchor = west


e => Node
    @e.x = 1
    @e.y = 4.5
    @e.text = $2.$ \bbbold{DROZDEK}, \bbtext{Adam}. \bbenglish{Algoritmos e Estruturas de Dados em C++,} \bbtext{2002.}
    @e.anchor = west


b => Node
    @b.x = 1
    @b.y = 3.5
    @b.text = $3.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 2.5
    @c.text = $4.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 1.5
    @d.text = $5.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.}
    @d.anchor = west

## End
