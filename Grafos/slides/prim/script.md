## Frame
\bbcover{Grafos}{Algoritmo de Prim}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Proponentes}
    @title.anchor = west

jarnik => Node
    @jarnik.x = 2
    @jarnik.y = 4
    @jarnik.text = \includegraphics[scale=0.4]{figs/jarnik.jpg}

jname => Node
    @jname.x = 2
    @jname.y = 1
    @jname.text = \bbbold{Vojtěch Jarník}

jdate => Node
    @jdate.x = 2
    @jdate.y = 0.5
    @jdate.text = \bbtext{(1930)}

prim => Node
    @prim.x = 7
    @prim.y = 4
    @prim.text = \includegraphics[scale=1.3]{figs/prim.jpg}

pname => Node
    @pname.x = 7
    @pname.y = 1
    @pname.text = \bbbold{Robert Clay Prim}

pdate => Node
    @pdate.x = 7
    @pdate.y = 0.5
    @pdate.text = \bbtext{(1957)}

dijkstra => Node
    @dijkstra.x = 12
    @dijkstra.y = 4
    @dijkstra.text = \includegraphics[scale=0.4]{figs/dijkstra.jpg}

dname => Node
    @dname.x = 12
    @dname.y = 1
    @dname.text = \bbbold{Edsger Wybe Dijkstra}

ddate => Node
    @ddate.x = 12
    @ddate.y = 0.5
    @ddate.text = \bbtext{(1959)}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Características do algoritmo de Prim}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{O algoritmo de Prim encontra uma MST usando uma abordagem gulosa}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Um vértice $u$ é escolhido para iniciar um componente conectado $C$}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Enquanto $C \neq V$, é identificado o vértice $u\not\in C$ mais pŕoximo de $C$}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{Então $u$ é inserido em $C$ e a aresta que uniu $u$ a $C$ faz parte de uma MST}
    @d.anchor = west

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
    @input.text = \bbemph{Entrada:} \bbtext{um grafo conectado ponderado $G(V, E)$}
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
    @step1.text = $1.$ \bbtext{Escolha um vértice $u\in V$ e faça $C = \{ u \}, M = \emptyset$}
    @step1.anchor = west

---

step2 => Node
    @step2.x = 1.0
    @step2.y = 3.5
    @step2.text = $2.$ \bbtext{Enquanto $C\neq V$:}
    @step2.anchor = west

step2a => Node
    @step2a.x = 2.0
    @step2a.y = 3.0
    @step2a.text = $(a)$ \bbtext{Escolha o vértice $v\not\in C$ mais próximo de $C$}
    @step2a.anchor = west

step2b => Node
    @step2b.x = 2.0
    @step2b.y = 2.5
    @step2b.text = $(b)$ \bbtext{Inclua $v$ em $C$ e a aresta que une $v$ a $C$ em $M$}
    @step2b.anchor = west

---

step3 => Node
    @step3.x = 1.0
    @step3.y = 1.5
    @step3.text = $3.$ \bbtext{Retorne $M$}
    @step3.anchor = west

## Scene

node1 => Node
    @node1.x = 10
    @node1.y = 5
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

 node2 => Node
    @node2.x = 7
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

 node3 => Node
    @node3.x = 4
    @node3.y = 5
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

 node4 => Node
    @node4.x = 10
    @node4.y = 3
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

 node6 => Node
    @node6.x = 4
    @node6.y = 3
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.thick
    %e23.label = node[above left] {\footnotesize \bbinfo{1}}

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    %e45.label = node[below right] {\footnotesize \bbinfo{1}}

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    %e14.label = node[right] {\footnotesize \bbinfo{2}}

e51 => Edge
    @e51.from = node5
    @e51.to = node1
    &e51.thick
    %e51.label = node[above left,pos=0.3] {\footnotesize \bbinfo{2}}

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    %e34.label = node[above left] {\footnotesize \bbinfo{3}}

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    %e12.label = node[above right] {\footnotesize \bbinfo{4}}

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    %e13.label = node[above] {\footnotesize \bbinfo{5}}

e36 => Edge
    @e36.from = node3
    @e36.to = node6
    &e36.thick
    %e36.label = node[left] {\footnotesize \bbinfo{7}}

e65 => Edge
    @e65.from = node6
    @e65.to = node5
    &e65.thick
    %e65.label = node[above] {\footnotesize \bbinfo{8}}

---

    @node6.fill = BBCyan

---

    @node3.fill = BBCyan

    &e36.very thick
    &e36.dashed
    @e36.color = BBGreen

---

    @node2.fill = BBCyan

    &e23.very thick
    &e23.dashed
    @e23.color = BBGreen

---

    @node4.fill = BBCyan

    &e34.very thick
    &e34.dashed
    @e34.color = BBGreen

---

    @node5.fill = BBCyan

    &e45.very thick
    &e45.dashed
    @e45.color = BBGreen

---

    @node1.fill = BBCyan

    &e14.very thick
    &e14.dashed
    @e14.color = BBGreen

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Identificação eficiente do vértice mais próximo de $C$}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{A complexidade do algoritmo de Prim depende da identificação eficiente do}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.0
    @a1.text = \bbtext{vértice $v$ mais próximo de $C$}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $\star$ \bbtext{O vértice $v\not\in C$ é o mais próximo de $C$ se $v$ minimiza a distância}
    @b.anchor = west

b1 => Node
    @b1.x = 7
    @b1.y = 3
    @b1.text = $\displaystyle \dist(v, C) = \min_{u\in C}\ \{\ \dist(v, u)\ \}$

---

c => Node
    @c.x = 1
    @c.y = 2
    @c.text = $\star$ \bbtext{Uma forma de se identificar $v$ é manter uma fila com prioridades $q$}
    @c.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Identificação eficiente do vértice mais próximo de $C$}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{Inicialmente, $q$ estará vazia}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = $\star$ \bbtext{Esta fila será ordenada, de forma ascendente, pelas distâncias até $C$}
    @b.anchor = west


---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{A cada vértice adicionado a $C$ (inclusive o $u$ inicial), insira em $q$ pares}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3
    @c1.text = \bbtext{$(w, v)$, onde $w$ o peso da aresta que une o vértice $v\not\in C$ a $u$}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbtext{O vértice mais pŕoximo $v$ será dado pelo par mais próximo do início da fila}
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 1.5
    @d1.text = \bbtext{tal que $v\not\in C$}
    @d1.anchor = west


## Frame

\inputsnippet{cpp}{11}{26}{codes/prim.cpp}

## Frame

\inputsnippet{cpp}{27}{40}{codes/prim.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Aplicação: Minimax}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{Uma MST minimiza o maior peso entre as arestas presentes em qualquer }
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5.0
    @a1.text = \bbtext{árvore geradora}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.0
    @b.text = $\star$ \bbtext{O problema de se minimizar tal peso é denominado \bbenglish{minimax}} 
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.0
    @c.text = $\star$ \bbtext{Uma variante deste problema é o \bbenglish{maximin}, que maximiza o menor peso}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 2.5
    @c1.text = \bbtext{entre as arestas presentes em qualquer árvore geradora}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 1.5
    @d.text = $\star$ \bbtext{Uma variante simples do algoritmo de Prim resolve o \bbenglish{minimax}}
    @d.anchor = west


## Scene

node1 => Node
    @node1.x = 10
    @node1.y = 5
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

 node2 => Node
    @node2.x = 7
    @node2.y = 7
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

 node3 => Node
    @node3.x = 4
    @node3.y = 5
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

 node4 => Node
    @node4.x = 10
    @node4.y = 3
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

 node6 => Node
    @node6.x = 4
    @node6.y = 3
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.thick
    %e23.label = node[above left] {\footnotesize \bbinfo{1}}

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    %e45.label = node[below right] {\footnotesize \bbinfo{1}}

e14 => Edge
    @e14.from = node1
    @e14.to = node4
    &e14.thick
    %e14.label = node[right] {\footnotesize \bbinfo{2}}

e51 => Edge
    @e51.from = node5
    @e51.to = node1
    &e51.thick
    %e51.label = node[above left,pos=0.3] {\footnotesize \bbinfo{2}}

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    %e34.label = node[above left] {\footnotesize \bbinfo{3}}

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    %e12.label = node[above right] {\footnotesize \bbinfo{4}}

e13 => Edge
    @e13.from = node1
    @e13.to = node3
    &e13.thick
    %e13.label = node[above] {\footnotesize \bbinfo{5}}

e36 => Edge
    @e36.from = node3
    @e36.to = node6
    &e36.thick
    %e36.label = node[right] {\footnotesize \bbinfo{7}}

e65 => Edge
    @e65.from = node6
    @e65.to = node5
    &e65.thick
    %e65.label = node[above] {\footnotesize \bbinfo{8}}

---

    &e36.very thick
    @e36.color = BBGreen

    &e23.very thick
    &e23.dashed
    @e23.color = BBGreen

    &e34.very thick
    &e34.dashed
    @e34.color = BBGreen

    &e45.very thick
    &e45.dashed
    @e45.color = BBGreen

    &e14.very thick
    &e14.dashed
    @e14.color = BBGreen

r => Node
    @r.x = 3.0
    @r.y = 4
    @r.text = \footnotesize \bbcomment{minimax}
    @r.anchor = east
    
arrow => Edge
    @arrow.x = 3.05
    @arrow.y = 4
    @arrow.u = 3.85
    @arrow.v = 4
    @arrow.color = BBViolet
    &arrow.-latex

## Frame

\inputsnippet{cpp}{11}{26}{codes/minimax.cpp}

## Frame

\inputsnippet{cpp}{27}{40}{codes/minimax.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Aplicação: Menor Subgrafo Gerador}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Seja $G(V, E)$ um grafo conectado e ponderado e $E'\subset E$}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{O menor subgrafo gerador $S_{E'}$ de $G$ é um subgrafo conectado que contém}
    @b.anchor = west

b1 => Node
    @b1.x = 0.5
    @b1.y = 4.5
    @b1.text = \bbtext{todas as arestas $E'$ e que tem custo mínimo}
    @b1.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3.5
    @c.text = $\star$ \bbtext{Por conta da restrição $E'$, $S_{E'}$ não é, necessariamente, uma MST}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.5
    @d.text = $\star$ \bbtext{O menor subgrafo gerador pode ser encontrado atribuíndo a $C$ todos os }
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 2.0
    @d1.text = \bbtext{vértices ligados por alguma aresta em $E'$ no passo inicial do algoritmo de Prim}
    @d1.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 1.0
    @e.text = $\star$ \bbtext{A complexidade é a mesma do algoritmo original}
    @e.anchor = west

## Scene

nodeA => Node
    @nodeA.x = 4
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
    @nodeC.x = 13
    @nodeC.y = 4
    @nodeC.text = \bbtext{C}
    &nodeC.draw
    &nodeC.very thick
    &nodeC.circle

nodeD => Node
    @nodeD.x = 7
    @nodeD.y = 1
    @nodeD.text = \bbtext{D}
    &nodeD.draw
    &nodeD.very thick
    &nodeD.circle

nodeE => Node
    @nodeE.x = 1
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
 
    @eAD.color = BBRed
    &eAD.dashed
    &eAD.very thick

    @eAE.color = BBRed
    &eAE.dashed
    &eAE.very thick

    @eDE.color = BBRed
    &eDE.dashed
    &eDE.very thick

---

    @eAB.color = BBCyan
    &eAB.dashed
    &eAB.very thick

---

    @eCE.color = BBCyan
    &eCE.dashed
    &eCE.very thick

## Frame

\inputsnippet{cpp}{11}{30}{codes/msg.cpp}

## Frame

\inputsnippet{cpp}{31}{48}{codes/msg.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Problemas sugeridos}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $1.$ \bbtext{CSES 1675 -- Road Reparation}
    @a.anchor = west

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $2.$ \bbtext{OJ 10048 -- Audiophobia}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $3.$ \bbtext{OJ 10099 -- Tourist Guide}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $4.$ \bbtext{SPOJ IITKWPCG -- Help the old King}
    @d.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Referências}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $2.$ \bbtext{\bbbold{IT History Society}. \bbenglish{Dr. Robert Clay Prim}, acesso em 28/08/2021.}
    @a.anchor = west

b => Node
    @b.x = 1
    @b.y = 6
    @b.text = $1.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $3.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.}
    @c.anchor = west

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $4.$ \bbbold{Wikipédia}. \bbenglish{Edsger Wybe Dijkstra,} \bbtext{acesso em 28/08/2021.}
    @d.anchor = west

e => Node
    @e.x = 1
    @e.y = 2
    @e.text = $5.$ \bbbold{Wikipédia}. \bbenglish{Prim's algorithm,} \bbtext{acesso em 28/08/2021.}
    @e.anchor = west

f => Node
    @f.x = 1
    @f.y = 1
    @f.text = $6.$ \bbbold{Wikipédia}. \bbenglish{Vojtěch Jarník,} \bbtext{acesso em 28/08/2021.}
    @f.anchor = west

## End

https://www.ithistory.org/honor-roll/dr-robert-clay-prim
https://en.wikipedia.org/wiki/Edsger_W._Dijkstra
https://en.wikipedia.org/wiki/Vojt%C4%9Bch_Jarn%C3%ADk
https://en.wikipedia.org/wiki/Prim%27s_algorithm

https://cses.fi/problemset/task/1675 - MST cost
http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=989 - Minimax
http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1040 - Minimax
https://www.spoj.com/problems/IITKWPCG/ - MST de multiplicação
