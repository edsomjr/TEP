## Frame
\bbcover{Grafos}{Decteção de ciclos em grafos de sucessores}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Identificação de ciclos}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = \bbtext{Seja $G$ um grafo de sucessores que contém um caminho que termine em}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 4.75
    @a1.text = \bbtext{um ciclo.}
    @a1.anchor = west

---

b => Node
    @b.x = 1.5
    @b.y = 4
    @b.text = \bbtext{$1$. Qual é o nó de menor índice que pertence ao ciclo? $(\mu)$}
    @b.anchor = west

b1 => Node
    @b1.x = 1.5
    @b1.y = 3.5
    @b1.text = \bbtext{$2$. O ciclo contém quantos nós? $(\lambda)$}
    @b1.anchor = west

---

node1 => Node
    @node1.x = 1
    @node1.y = 1.0
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

node2 => Node
    @node2.x = 4
    @node2.y = 1.0
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

node3 => Node
    @node3.x = 7
    @node3.y = 1.0
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

node4 => Node
    @node4.x = 10
    @node4.y = 1.0
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

node5 => Node
    @node5.x = 13
    @node5.y = 1.0
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node6 => Node
    @node6.x = 13
    @node6.y = 2.5
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node7 => Node
    @node7.x = 10
    @node7.y = 2.5
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node8 => Node
    @node8.x = 7
    @node8.y = 2.5
    @node8.text = \bbtext{8}
    &node8.very thick
    &node8.draw
    &node8.circle

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.thick
    &e23.-latex

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    &e34.-latex

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    &e45.-latex

e56 => Edge
    @e56.from = node5
    @e56.to = node6
    &e56.thick
    &e56.-latex

e67 => Edge
    @e67.from = node6
    @e67.to = node7
    &e67.thick
    &e67.-latex

e78 => Edge
    @e78.from = node7
    @e78.to = node8
    &e78.thick
    &e78.-latex

e83 => Edge
    @e83.from = node8
    @e83.to = node3
    &e83.thick
    &e83.-latex


## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Algoritmo linear em execução e memória}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = \bbtext{$1$. Faça $u = 1$ e $s = \emptyset$}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4.5
    @b.text = \bbtext{$2$. Enquanto $u\not\in s$:}
    @b.anchor = west

---

b1 => Node
    @b1.x = 1.5
    @b1.y = 3.75
    @b1.text = \bbtext{$(a)$ Insira $u$ em $s$}
    @b1.anchor = west

---

b2 => Node
    @b2.x = 1.5
    @b2.y = 3.0
    @b2.text = \bbtext{$(b)$ Faça $u = \mathrm{succ}(u)$}
    @b2.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 2
    @c.text = \bbtext{$3$. $\mu = u$}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 1
    @d.text = \bbtext{$4$. $\lambda = N - \mu + 1$, onde $N = |V|$}
    @d.anchor = west

## Frame

\inputsnippet{cpp}{5}{20}{codes/linear.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Algoritmo de Floyd}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5
    @a.text = $\star$ \bbtext{Também conhecido como algoritmo da lebre e da tartaruga}
    @a.anchor = west
---

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $\star$ \bbtext{Identifica um ciclo com execução $O(N)$ e memória $O(1)$}
    @b.anchor = west
---

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $\star$ \bbtext{Utilizada dois ponteiros: a lebre e a tartaruga}
    @c.anchor = west
---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbtext{A cada passo da tartaruga, a lebre caminha dois passos}
    @d.anchor = west
---

e => Node
    @e.x = 1
    @e.y = 1
    @e.text = $\star$ \bbtext{É composto de 3 etapas}
    @e.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Etapa 1: Identificação do ciclo}
    @title.anchor = west
---

node1 => Node
    @node1.x = 1
    @node1.y = 2.0
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

node2 => Node
    @node2.x = 4
    @node2.y = 2.0
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

node3 => Node
    @node3.x = 7
    @node3.y = 2.0
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

node4 => Node
    @node4.x = 10
    @node4.y = 2.0
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

node5 => Node
    @node5.x = 13
    @node5.y = 2.0
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node6 => Node
    @node6.x = 13
    @node6.y = 4.0
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node7 => Node
    @node7.x = 10
    @node7.y = 4.0
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node8 => Node
    @node8.x = 7
    @node8.y = 4.0
    @node8.text = \bbtext{8}
    &node8.very thick
    &node8.draw
    &node8.circle

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.thick
    &e23.-latex

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    &e34.-latex

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    &e45.-latex

e56 => Edge
    @e56.from = node5
    @e56.to = node6
    &e56.thick
    &e56.-latex

e67 => Edge
    @e67.from = node6
    @e67.to = node7
    &e67.thick
    &e67.-latex

e78 => Edge
    @e78.from = node7
    @e78.to = node8
    &e78.thick
    &e78.-latex

e83 => Edge
    @e83.from = node8
    @e83.to = node3
    &e83.thick
    &e83.-latex

---

info => Node
    @info.x = 1
    @info.y = 5.5
    @info.text = \bbtext{$(a)$ A tartaruga e a lebre são posicionadas no primeiro vértice}
    @info.anchor = west

---

T => Node
    @T.x = 1
    @T.y = 1.25
    @T.text = \includegraphics[scale=0.05]{figs/tortoise.png}

H => Node
    @H.x = 1
    @H.y = 3
    @H.text = \includegraphics[scale=0.03]{figs/rabbit.png}

---
    @info.text = \bbtext{$(b)$ A lebre dá dois passos, a tartaruga um, até se reencontrarem}

---
    @H.x = 7
    @H.y = 1.25

    @T.x = 4

---
    @H.x = 13
    @T.x = 7

---
    @H.x = 10
    @H.y = 4.75
    @H.text = \includegraphics[scale=0.03]{figs/rabbitR.png}
    @T.x = 10

---
    @H.x = 7
    @H.y = 1.25
    @H.text = \includegraphics[scale=0.03]{figs/rabbit.png}
    @T.x = 13

---
    @H.x = 13
    @T.x = 13
    @T.y = 4.75
    @T.text = \includegraphics[scale=0.05]{figs/tortoiseR.png}

---
    @H.x = 10
    @H.y = 3.25
    @T.x = 10
    @T.y = 4.75
    @H.text = \includegraphics[scale=0.03]{figs/rabbitR.png}
    @node7.fill = green!60!black

---
    @info.text = \bbtext{A tartaruga andou $k$ passos e a lebre andou $2k$ passos}

---
    @info.text = \bbtext{Logo, $\lambda$ divide $k$}
 

## Frame

\inputsnippet{cpp}{5}{14}{codes/floyd.cpp}


## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Etapa 2: Encontrando $\mu$}
    @title.anchor = west
---

node1 => Node
    @node1.x = 1
    @node1.y = 2.0
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

node2 => Node
    @node2.x = 4
    @node2.y = 2.0
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

node3 => Node
    @node3.x = 7
    @node3.y = 2.0
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

node4 => Node
    @node4.x = 10
    @node4.y = 2.0
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

node5 => Node
    @node5.x = 13
    @node5.y = 2.0
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node6 => Node
    @node6.x = 13
    @node6.y = 4.0
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node7 => Node
    @node7.x = 10
    @node7.y = 4.0
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node8 => Node
    @node8.x = 7
    @node8.y = 4.0
    @node8.text = \bbtext{8}
    &node8.very thick
    &node8.draw
    &node8.circle

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.thick
    &e23.-latex

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    &e34.-latex

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    &e45.-latex

e56 => Edge
    @e56.from = node5
    @e56.to = node6
    &e56.thick
    &e56.-latex

e67 => Edge
    @e67.from = node6
    @e67.to = node7
    &e67.thick
    &e67.-latex

e78 => Edge
    @e78.from = node7
    @e78.to = node8
    &e78.thick
    &e78.-latex

e83 => Edge
    @e83.from = node8
    @e83.to = node3
    &e83.thick
    &e83.-latex

T => Node
    @T.x = 10
    @T.y = 4.75
    @T.text = \includegraphics[scale=0.05]{figs/tortoiseR.png}

H => Node
    @H.x = 10
    @H.y = 3.25
    @H.text = \includegraphics[scale=0.03]{figs/rabbitR.png}

    @node7.fill = green!60!black

---

info => Node
    @info.x = 1
    @info.y = 5.5
    @info.text = \bbtext{$(a)$ A tartaruga volta para o ponto de partida}
    @info.anchor = west

---
    @T.x = 1
    @T.y = 1.25
    @T.text = \includegraphics[scale=0.05]{figs/tortoise.png}

---
    @info.text = \bbtext{$(b)$ Agora ambos andam um passo por vez até se encontrarem}
    
---
    @T.x = 4
    @H.x = 7
    @H.y = 4.75
    @H.text = \includegraphics[scale=0.03]{figs/rabbitR.png}
    @node7.fill = white

---
    @T.x = 7
    @H.x = 7
    @H.y = 0.5
    @H.text = \includegraphics[scale=0.03]{figs/rabbit.png}
    @node3.fill = green!60!black

---
    @info.text = \bbtext{O ponto de encontro é o primeiro nó do ciclo}

---
    @info.text = \bbtext{Logo, $\mu = 3$}

## Frame

\inputsnippet{cpp}{16}{24}{codes/floyd.cpp}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Etapa 3: Encontrando $\lambda$}
    @title.anchor = west
---

node1 => Node
    @node1.x = 1
    @node1.y = 2.0
    @node1.text = \bbtext{1}
    &node1.very thick
    &node1.draw
    &node1.circle

node2 => Node
    @node2.x = 4
    @node2.y = 2.0
    @node2.text = \bbtext{2}
    &node2.very thick
    &node2.draw
    &node2.circle

node3 => Node
    @node3.x = 7
    @node3.y = 2.0
    @node3.text = \bbtext{3}
    &node3.very thick
    &node3.draw
    &node3.circle

node4 => Node
    @node4.x = 10
    @node4.y = 2.0
    @node4.text = \bbtext{4}
    &node4.very thick
    &node4.draw
    &node4.circle

node5 => Node
    @node5.x = 13
    @node5.y = 2.0
    @node5.text = \bbtext{5}
    &node5.very thick
    &node5.draw
    &node5.circle

node6 => Node
    @node6.x = 13
    @node6.y = 4.0
    @node6.text = \bbtext{6}
    &node6.very thick
    &node6.draw
    &node6.circle

node7 => Node
    @node7.x = 10
    @node7.y = 4.0
    @node7.text = \bbtext{7}
    &node7.very thick
    &node7.draw
    &node7.circle

node8 => Node
    @node8.x = 7
    @node8.y = 4.0
    @node8.text = \bbtext{8}
    &node8.very thick
    &node8.draw
    &node8.circle

e12 => Edge
    @e12.from = node1
    @e12.to = node2
    &e12.thick
    &e12.-latex

e23 => Edge
    @e23.from = node2
    @e23.to = node3
    &e23.thick
    &e23.-latex

e34 => Edge
    @e34.from = node3
    @e34.to = node4
    &e34.thick
    &e34.-latex

e45 => Edge
    @e45.from = node4
    @e45.to = node5
    &e45.thick
    &e45.-latex

e56 => Edge
    @e56.from = node5
    @e56.to = node6
    &e56.thick
    &e56.-latex

e67 => Edge
    @e67.from = node6
    @e67.to = node7
    &e67.thick
    &e67.-latex

e78 => Edge
    @e78.from = node7
    @e78.to = node8
    &e78.thick
    &e78.-latex

e83 => Edge
    @e83.from = node8
    @e83.to = node3
    &e83.thick
    &e83.-latex

T => Node
    @T.x = 7
    @T.y = 1.25
    @T.text = \includegraphics[scale=0.05]{figs/tortoise.png}

H => Node
    @H.x = 7
    @H.y = 0.5
    @H.text = \includegraphics[scale=0.03]{figs/rabbit.png}

    @node3.fill = green!60!black

---

info => Node
    @info.x = 1
    @info.y = 5.5
    @info.text = \bbtext{$(a)$ A tartaruga espera enquanto a lebre percorre o ciclo}
    @info.anchor = west

---
    @H.x = 10
    @H.y = 1.25
    @node4.fill = cyan

---
    @H.x = 13
    @node5.fill = cyan

---
    @H.x = 13.75
    @H.y = 4
    @node6.fill = cyan

---
    @H.x = 10
    @H.y = 4.75
    @node7.fill = cyan
    @H.text = \includegraphics[scale=0.03]{figs/rabbitR.png}

---
    @H.x = 7
    @H.y = 4.75
    @node8.fill = cyan

---
    @H.x = 7
    @H.y = 0.5
    @node3.fill = cyan
    @H.text = \includegraphics[scale=0.03]{figs/rabbit.png}

---
    @info.text = \bbtext{$(b)$ $\lambda$ será igual ao número de passos da lebre}

## Frame

\inputsnippet{cpp}{25}{33}{codes/floyd.cpp}

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


## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Créditos}
    @title.anchor = west

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Tortoise by Zohaib Bajwa from Noun Project (CC BY 3.0)}
    @b.anchor = west

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{Rabbit by ARIS ARISA from Noun Project (CC BY 3.0)}
    @c.anchor = west


## End

