## Frame
\bbcover{Grafos}{Ancestrais}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{$k$-ésimo ancestral}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = \bbtext{Seja $T$ uma árvore enraizada, $u$ um vértice de $T$ e $k$ um inteiro positivo.} 
    @a.anchor = west

b => Node
    @b.x = 0.5
    @b.y = 4.75
    @b.text = \bbtext{O $k$-\bbbold{ésimo ancestral de} $u$ é o nó $v$ que encerra o caminho que parte de $u$ e}
    @b.anchor = west

c => Node
    @c.x = 0.5
    @c.y = 4.0
    @c.text = \bbtext{segue $k$ níveis, em direção à raiz. \bbbold{Notação:} \texttt{$v$ = ancestor(}$u, k$\texttt{)}.}
    @c.anchor = west

## Scene

node1 => Node
    @node1.x = 9
    @node1.y = 3
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

node2 => Node
    @node2.x = 9
    @node2.y = 5
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

node3 => Node
    @node3.x = 5
    @node3.y = 7
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

node4 => Node
    @node4.x = 5
    @node4.y = 5
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

node5 => Node
    @node5.x = 9
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node7 => Node
    @node7.x = 1
    @node7.y = 5
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node6 => Node
    @node6.x = 6
    @node6.y = 3
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node8 => Node
    @node8.x = 12
    @node8.y = 3
    @node8.text = \bbtext{8}
    &node8.very thick
    &node8.draw
    &node8.circle

node9 => Node
    @node9.x = 1
    @node9.y = 3
    @node9.text = \bbtext{9}
    &node9.very thick
    &node9.draw
    &node9.circle


e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick

e15 => Edge
    @e15.from = node1
    @e15.to = node5
    &e15.thick

e23 => Edge
    @e23.from = node3
    @e23.to = node2
    &e23.thick

e26 => Edge
    @e26.from = node6
    @e26.to = node2
    &e26.thick

e28 => Edge
    @e28.from = node8
    @e28.to = node2
    &e28.thick

e32 => Edge
    @e32.from = node2
    @e32.to = node3
    &e32.thick

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick

e37 => Edge
    @e37.from = node3
    @e37.to = node7
    &e37.thick

e79 => Edge
    @e79.from = node7
    @e79.to = node9
    &e79.thick

---

e97 => Edge
    @e97.from = node9
    @e97.to = node7
    @e97.color = BBViolet
    &e97.thick
    &e97.-latex
    &e97.dashed
    %e97.label = [bend right] node[anchor=west] { \scriptsize \texttt{ancestor($9, 1$) = 7} }

---

e62 => Edge
    @e62.from = node6
    @e62.to = node2
    @e62.color = BBGreen
    &e62.thick
    &e62.-latex
    &e62.dashed
    %e62.label = [bend right]

e623 => Edge
    @e623.from = node2
    @e623.to = node3
    @e623.color = BBGreen
    &e623.thick
    &e623.-latex
    &e623.dashed
    %e623.label = [bend right] node[anchor=south west] { \scriptsize \texttt{ancestor($6, 2$) = 3} }

---

e51 => Edge
    @e51.from = node5
    @e51.to = node1
    @e51.color = BBCyan
    &e51.thick
    &e51.-latex
    &e51.dashed
    %e51.label = [bend right] node[anchor=west] { \scriptsize \texttt{ancestor($5, 3$) = 3} }

e21 => Edge
    @e21.from = node1
    @e21.to = node2
    @e21.color = BBCyan
    &e21.thick
    &e21.-latex
    &e21.dashed
    %e21.label = [bend right]

e32 => Edge
    @e32.from = node2
    @e32.to = node3
    @e32.color = BBCyan
    &e32.thick
    &e32.-latex
    &e32.dashed
    %e32.label = [bend left] 


## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Identificação do $k$-eśimo ancestral em $O(\log N)$}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{É possível identificar o $k$-ésimo ancestral em $O(\log N)$, onde $N$ é o número}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.25
    @a1.text = \bbtext{vértices da árvore, por meio de um algoritmo de programação dinâmica}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.25
    @b.text = $\star$ \bbtext{Seja $p(u)$ o ancestral direto de $u$ na árvore enraizada}
    @b.anchor = west


---

c => Node
    @c.x = 1
    @c.y = 3.25
    @c.text = $\star$ \bbtext{O caso base ocorre com $k = 2^0 = 1$:  \texttt{ancestor($u, 1$) = $p(u)$}}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.25
    @d.text = $\star$ \bbtext{A transição é dada por:}
    @d.anchor = west

d1 => Node
    @d1.x = 7
    @d1.y = 1.25
    @d1.text = $ \texttt{ancestor}(u, 2^k) = \texttt{ancestor}(\texttt{ancestor}(u, 2^{k - 1}), 2^{k - 1}) $

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Identificação do $k$-eśimo ancestral em $O(\log N)$}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Seja $k$ um inteiro positivo}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{É possível escrever $k$ como a soma de potências distintas de $2$:}
    @b.anchor = west

b1 => Node
    @b1.x = 7
    @b1.y = 4
    @b1.text = $k = 2^{\alpha} + 2^{\beta} + \ldots + 2^{\omega}$

---

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $\star$ \bbtext{Deste modo,}
    @c.anchor = west

c1 => Node
    @c1.x = 7
    @c1.y = 2
    @c1.text = $\texttt{ancestor}(u, k) =  \texttt{ancestor}(\texttt{ancestor}(\texttt{ancestor}(\texttt{ancestor}(u, 2^\alpha), 2^\beta), \ldots), 2^\omega)$


## Scene

node1 => Node
    @node1.x = 7
    @node1.y = 3
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

node2 => Node
    @node2.x = 7
    @node2.y = 5
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

node3 => Node
    @node3.x = 4
    @node3.y = 7
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

node4 => Node
    @node4.x = 4
    @node4.y = 5
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

node5 => Node
    @node5.x = 7
    @node5.y = 1
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node7 => Node
    @node7.x = 1
    @node7.y = 5
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node6 => Node
    @node6.x = 5
    @node6.y = 3
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node8 => Node
    @node8.x = 9
    @node8.y = 3
    @node8.text = \bbtext{8}
    &node8.very thick
    &node8.draw
    &node8.circle

node9 => Node
    @node9.x = 1
    @node9.y = 3
    @node9.text = \bbtext{9}
    &node9.very thick
    &node9.draw
    &node9.circle


e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick

e15 => Edge
    @e15.from = node1
    @e15.to = node5
    &e15.thick

e23 => Edge
    @e23.from = node3
    @e23.to = node2
    &e23.thick

e26 => Edge
    @e26.from = node6
    @e26.to = node2
    &e26.thick

e28 => Edge
    @e28.from = node8
    @e28.to = node2
    &e28.thick

e32 => Edge
    @e32.from = node2
    @e32.to = node3
    &e32.thick

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick

e37 => Edge
    @e37.from = node3
    @e37.to = node7
    &e37.thick

e79 => Edge
    @e79.from = node7
    @e79.to = node9
    &e79.thick

p1 => Path
    @p1.path = (11, 7.3) -- (13.1, 7.3) -- (13.1, 1) -- (11, 1) -- cycle
    &p1.thick

p2 => Path
    @p2.path = (11.7, 7.3) -- (11.7, 1)
    &p2.thick

p3 => Path
    @p3.path = (12.4, 7.3) -- (12.4, 1)
    &p3.thick

p4 => Path
    @p4.path = (11, 6.6) -- (13.1, 6.6)
    &p4.thick

p5 => Path
    @p5.path = (11, 5.9) -- (13.1, 5.9)
    &p5.thick

p6 => Path
    @p6.path = (11, 5.2) -- (13.1, 5.2)
    &p6.thick

p7 => Path
    @p7.path = (11, 4.5) -- (13.1, 4.5)
    &p7.thick

p8 => Path
    @p8.path = (11, 3.8) -- (13.1, 3.8)
    &p8.thick

p9 => Path
    @p9.path = (11, 3.1) -- (13.1, 3.1)
    &p9.thick

p10 => Path
    @p10.path = (11, 2.4) -- (13.1, 2.4)
    &p10.thick

p11 => Path
    @p11.path = (11, 1.7) -- (13.1, 1.7)
    &p11.thick

k1 => Node
    @k1.x = 11.35
    @k1.y = 7.6
    @k1.text = \footnotesize $2^0$

k2 => Node
    @k2.x = 12.05
    @k2.y = 7.6
    @k2.text = \footnotesize $2^1$

k3 => Node
    @k3.x = 12.75
    @k3.y = 7.6
    @k3.text = \footnotesize $2^2$

x1 => Node
    @x1.x = 10.7
    @x1.y = 6.95
    @x1.text = \footnotesize \bbtext{1}

x2 => Node
    @x2.x = 10.7
    @x2.y = 6.25
    @x2.text = \footnotesize \bbtext{2}

x3 => Node
    @x3.x = 10.7
    @x3.y = 5.55
    @x3.text = \footnotesize \bbtext{3}

x4 => Node
    @x4.x = 10.7
    @x4.y = 4.85
    @x4.text = \footnotesize \bbtext{4}

x5 => Node
    @x5.x = 10.7
    @x5.y = 4.15
    @x5.text = \footnotesize \bbtext{5}

x6 => Node
    @x6.x = 10.7
    @x6.y = 3.45
    @x6.text = \footnotesize \bbtext{6}

x7 => Node
    @x7.x = 10.7
    @x7.y = 2.75
    @x7.text = \footnotesize \bbtext{7}

x8 => Node
    @x8.x = 10.7
    @x8.y = 2.05
    @x8.text = \footnotesize \bbtext{8}

x9 => Node
    @x9.x = 10.7
    @x9.y = 1.35
    @x9.text = \footnotesize \bbtext{9}

succ => Node
    @succ.x = 12.05
    @succ.y = 0.5
    @succ.text = \footnotesize $\mathrm{succ}(u, 2^k)$

---
    @node1.fill = BBCyan

---
    @node2.fill = BBGreen

---

m11 => Node
    @m11.x = 11.35
    @m11.y = 6.95
    @m11.text = \footnotesize $\mathtt{2}$

---
    @node1.fill = BBWhite
    @node2.fill = BBCyan

---
    @node3.fill = BBGreen

---

m21 => Node
    @m21.x = 11.35
    @m21.y = 6.25
    @m21.text = \footnotesize $\mathtt{3}$

---
    @node2.fill = BBWhite
    @node3.fill = BBCyan
---

m31 => Node
    @m31.x = 11.35
    @m31.y = 5.55
    @m31.text = \footnotesize -

---
    @node3.fill = BBWhite
    @node4.fill = BBCyan

---
    @node3.fill = BBGreen

---

m41 => Node
    @m41.x = 11.35
    @m41.y = 4.85
    @m41.text = \footnotesize $\mathtt{3}$

---
    @node4.fill = BBWhite
    @node3.fill = BBWhite
    @node5.fill = BBCyan

---
    @node1.fill = BBGreen

---

m51 => Node
    @m51.x = 11.35
    @m51.y = 4.15
    @m51.text = \footnotesize $\mathtt{1}$

---
    @node5.fill = BBWhite
    @node1.fill = BBWhite
    @node6.fill = BBCyan

---
    @node2.fill = BBGreen

---

m61 => Node
    @m61.x = 11.35
    @m61.y = 3.45
    @m61.text = \footnotesize $\mathtt{2}$

---
    @node6.fill = BBWhite
    @node2.fill = BBWhite
    @node7.fill = BBCyan

---
    @node3.fill = BBGreen

---

m71 => Node
    @m71.x = 11.35
    @m71.y = 2.75
    @m71.text = \footnotesize $\mathtt{3}$

---
    @node7.fill = BBWhite
    @node3.fill = BBWhite
    @node8.fill = BBCyan

---
    @node2.fill = BBGreen

---

m81 => Node
    @m81.x = 11.35
    @m81.y = 2.05
    @m81.text = \footnotesize $\mathtt{2}$

---
    @node8.fill = BBWhite
    @node2.fill = BBWhite
    @node9.fill = BBCyan

---
    @node7.fill = BBGreen

---

m91 => Node
    @m91.x = 11.35
    @m91.y = 1.35
    @m91.text = \footnotesize $\mathtt{7}$

---
    @node9.fill = BBWhite
    @node7.fill = BBWhite
    @node1.fill = BBCyan

---
    @node2.fill = BBOrange
---
    @node3.fill = BBGreen

---

m12 => Node
    @m12.x = 12.05
    @m12.y = 6.95
    @m12.text = \footnotesize $\mathtt{3}$


---
    @node1.fill = BBWhite
    @node3.fill = BBWhite
    @node2.fill = BBCyan

---

m22 => Node
    @m22.x = 12.05
    @m22.y = 6.25
    @m22.text = \footnotesize -

---
    @node2.fill = BBWhite
    @node3.fill = BBCyan

---

m32 => Node
    @m32.x = 12.05
    @m32.y = 5.55
    @m32.text = \footnotesize -

---
    @node3.fill = BBWhite
    @node4.fill = BBCyan

---

m42 => Node
    @m42.x = 12.05
    @m42.y = 4.85
    @m42.text = \footnotesize -

---
    @node4.fill = BBWhite
    @node5.fill = BBCyan

---
    @node1.fill = BBOrange
---
    @node2.fill = BBGreen

---

m52 => Node
    @m52.x = 12.05
    @m52.y = 4.15
    @m52.text = \footnotesize $\mathtt{2}$

---
    @node5.fill = BBWhite
    @node1.fill = BBWhite
    @node2.fill = BBWhite
    @node6.fill = BBCyan

---
    @node2.fill = BBOrange
---
    @node3.fill = BBGreen

---

m62 => Node
    @m62.x = 12.05
    @m62.y = 3.45
    @m62.text = \footnotesize $\mathtt{3}$

---
    @node6.fill = BBWhite
    @node2.fill = BBWhite
    @node3.fill = BBWhite
    @node7.fill = BBCyan

---

m72 => Node
    @m72.x = 12.05
    @m72.y = 2.75
    @m72.text = \footnotesize -

---
    @node7.fill = BBWhite
    @node8.fill = BBCyan

---
    @node2.fill = BBOrange
---
    @node3.fill = BBGreen

---

m82 => Node
    @m82.x = 12.05
    @m82.y = 2.05
    @m82.text = \footnotesize $\mathtt{3}$

---
    @node8.fill = BBWhite
    @node3.fill = BBWhite
    @node2.fill = BBWhite
    @node9.fill = BBCyan

---
    @node7.fill = BBOrange
---
    @node3.fill = BBGreen

---

m92 => Node
    @m92.x = 12.05
    @m92.y = 1.35
    @m92.text = \footnotesize $\mathtt{3}$

---
    @node9.fill = BBWhite
    @node7.fill = BBWhite
    @node3.fill = BBWhite

m13 => Node
    @m13.x = 12.75
    @m13.y = 6.95
    @m13.text = \footnotesize -

m23 => Node
    @m23.x = 12.75
    @m23.y = 6.25
    @m23.text = \footnotesize -

m33 => Node
    @m33.x = 12.75
    @m33.y = 5.55
    @m33.text = \footnotesize -

m43 => Node
    @m43.x = 12.75
    @m43.y = 4.85
    @m43.text = \footnotesize -

m53 => Node
    @m53.x = 12.75
    @m53.y = 4.15
    @m53.text = \footnotesize -

m63 => Node
    @m63.x = 12.75
    @m63.y = 3.45
    @m63.text = \footnotesize -

m73 => Node
    @m73.x = 12.75
    @m73.y = 2.75
    @m73.text = \footnotesize -

m83 => Node
    @m83.x = 12.75
    @m83.y = 2.05
    @m83.text = \footnotesize -

m93 => Node
    @m93.x = 12.75
    @m93.y = 1.35
    @m93.text = \footnotesize -

## Frame

\inputsnippet{cpp}{41}{58}{codes/ancestor.cpp}

## Frame

\inputsnippet{cpp}{19}{39}{codes/ancestor.cpp}

## Frame

\inputsnippet{cpp}{10}{17}{codes/ancestor.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Referências}
    @title.anchor = west

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $1.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $2.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.}
    @c.anchor = west

## End

