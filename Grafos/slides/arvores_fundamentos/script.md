## Frame
\bbcover{Grafos}{Árvores: Fundamentos}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene

title => Node
    @title.x = 0
    @title.y = 6.5
    @title.text = \Large \bbbold{Definição de árvore}
    @title.anchor = west
---

a => Node
    @a.x = 1
    @a.y = 5.5
    @a.text = $\star$ \bbtext{Uma árvore é um grafo não-direcionado, conectado e acíclico com $N$}
    @a.anchor = west

a1 => Node
    @a1.x = 0.5
    @a1.y = 5
    @a1.text = \bbtext{vértices e $N - 1$ arestas}
    @a1.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 4
    @b.text = $\star$ \bbtext{A remoção de qualquer aresta divide a árvore em dois componentes}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 3
    @c.text = $\star$ \bbtext{A adição de uma aresta cria um ciclo, descaracterizando a árvore}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2
    @d.text = $\star$ \bbtext{Para quaisquer vértices $u$ e $v$ da árvore existe um caminho único de $u$ a $v$}
    @d.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Exemplo de árvore}
    @title.anchor = west

a => Node
    @a.x = 2
    @a.y = 1
    @a.text = \bbtext{1}
    &a.draw
    &a.circle
    &a.very thick

b => Node
    @b.x = 8
    @b.y = 2
    @b.text = \bbtext{2}
    &b.draw
    &b.circle
    &b.very thick

c => Node
    @c.x = 4
    @c.y = 5
    @c.text = \bbtext{3}
    &c.draw
    &c.circle
    &c.very thick

d => Node
    @d.x = 8
    @d.y = 4
    @d.text = \bbtext{4}
    &d.draw
    &d.circle
    &d.very thick

e => Node
    @e.x = 10
    @e.y = 6
    @e.text = \bbtext{5}
    &e.draw
    &e.circle
    &e.very thick

f => Node
    @f.x = 12
    @f.y = 3
    @f.text = \bbtext{6}
    &f.draw
    &f.circle
    &f.very thick

g => Node
    @g.x = 6
    @g.y = 3
    @g.text = \bbtext{7}
    &g.draw
    &g.circle
    &g.very thick

e17 => Edge
    @e17.from = a
    @e17.to = g
    &e17.thick

e73 => Edge
    @e73.from = g
    @e73.to = c
    &e73.thick

e74 => Edge
    @e74.from = g
    @e74.to = d
    &e74.thick

e42 => Edge
    @e42.from = d
    @e42.to = b
    &e42.thick

e45 => Edge
    @e45.from = d
    @e45.to = e
    &e45.thick

e56 => Edge
    @e56.from = e
    @e56.to = f
    &e56.thick

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Árvores enraizadas}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 1
    @a.text = \footnotesize \bbtext{1}
    &a.draw
    &a.circle
    &a.very thick

b => Node
    @b.x = 5.5
    @b.y = 1.8
    @b.text = \footnotesize \bbtext{2}
    &b.draw
    &b.circle
    &b.very thick

c => Node
    @c.x = 2.5
    @c.y = 4.2
    @c.text = \footnotesize \bbtext{3}
    &c.draw
    &c.circle
    &c.very thick

d => Node
    @d.x = 5.5
    @d.y = 3.4
    @d.text = \footnotesize \bbtext{4}
    &d.draw
    &d.circle
    &d.very thick

e => Node
    @e.x = 6
    @e.y = 5
    @e.text = \footnotesize \bbtext{5}
    &e.draw
    &e.circle
    &e.very thick

f => Node
    @f.x = 7.5
    @f.y = 2.6
    @f.text = \footnotesize \bbtext{6}
    &f.draw
    &f.circle
    &f.very thick

g => Node
    @g.x = 4
    @g.y = 2.6
    @g.text = \footnotesize \bbtext{7}
    &g.draw
    &g.circle
    &g.very thick

e17 => Edge
    @e17.from = a
    @e17.to = g
    &e17.thick

e73 => Edge
    @e73.from = g
    @e73.to = c
    &e73.thick

e74 => Edge
    @e74.from = g
    @e74.to = d
    &e74.thick

e42 => Edge
    @e42.from = d
    @e42.to = b
    &e42.thick

e45 => Edge
    @e45.from = d
    @e45.to = e
    &e45.thick

e56 => Edge
    @e56.from = e
    @e56.to = f
    &e56.thick

---

info => Node
    @info.x = 1
    @info.y = 6
    @info.text = \bbtext{Um nó deve ser escolhido como raiz}
    @info.anchor = west

---

    @d.fill = BBGreen

---

D => Node
    @D.x = 12
    @D.y = 5
    @D.text = \footnotesize \bbtext{4}
    @D.fill = BBGreen
    &D.draw
    &D.circle
    &D.very thick

---

    @info.text = \bbtext{Os demais são organizados em níveis, de acordo com sua distância à raiz}

---

G => Node
    @G.x = 10
    @G.y = 3
    @G.text = \footnotesize \bbtext{7}
    &G.draw
    &G.circle
    &G.very thick

B => Node
    @B.x = 12
    @B.y = 3
    @B.text = \footnotesize \bbtext{2}
    &B.draw
    &B.circle
    &B.very thick

E => Node
    @E.x = 14
    @E.y = 3
    @E.text = \footnotesize \bbtext{5}
    &E.draw
    &E.circle
    &E.very thick

A => Node
    @A.x = 9
    @A.y = 1
    @A.text = \footnotesize \bbtext{1}
    &A.draw
    &A.circle
    &A.very thick

C => Node
    @C.x = 11
    @C.y = 1
    @C.text = \footnotesize \bbtext{3}
    &C.draw
    &C.circle
    &C.very thick

F => Node
    @F.x = 14
    @F.y = 1
    @F.text = \footnotesize \bbtext{6}
    &F.draw
    &F.circle
    &F.very thick

E17 => Edge
    @E17.from = A
    @E17.to = G
    &E17.thick

E73 => Edge
    @E73.from = G
    @E73.to = C
    &E73.thick

E74 => Edge
    @E74.from = G
    @E74.to = D
    &E74.thick

E42 => Edge
    @E42.from = D
    @E42.to = B
    &E42.thick

E45 => Edge
    @E45.from = D
    @E45.to = E
    &E45.thick

E56 => Edge
    @E56.from = E
    @E56.to = F
    &E56.thick

---

    @info.text = \bbtext{Filhos são vizinhos que estão no nível imediatamente inferior}

---
    @G.fill = BBGray

---

e1 => Edge
    @e1.x = 8
    @e1.y = 1
    @e1.u = 8.5
    @e1.v = 1
    @e1.color = BBViolet
    &e1.thick
    &e1.-latex

e2 => Edge
    @e2.x = 12
    @e2.y = 1
    @e2.u = 11.5
    @e2.v = 1
    @e2.color = BBViolet
    &e2.thick
    &e2.-latex

---
-e1
-e2

    @info.text = \bbtext{Pai é o nó do nível imediatamente acima}
    @G.fill = BBWhite

---

    @G.fill = BBGray

---

+e1
    @e1.from = G
    @e1.to = D
    %e1.label = [bend left]
    &e1.dashed

---
-e1

    @info.text = \bbtext{Folhas são nós com apenas um vizinho (sem filhos)}
    @G.fill = BBWhite

---

    @A.fill = BBCyan
    @B.fill = BBCyan
    @C.fill = BBCyan
    @F.fill = BBCyan

---
    @info.text = \bbtext{Cada nó pode ser interpretado como raiz de uma subárvore}

---
    @G.fill = BBGray

---

p => Path
    &p.dashed
    &p.draw
    &p.color = BBViolet
    @p.path = (8, 1) [bend right] to (10, 0) [bend right] to (12, 1) [bend right] to (10, 4) [bend right] to [bend right] (8, 1)


## Scene

title => Node
    @title.x = 0
    @title.y = 6
    @title.text = \Large \bbbold{Referências}
    @title.anchor = west

a => Node
    @a.x = 1
    @a.y = 2
    @a.text = $4.$ \bbtext{\bbbold{Wikipédia}. \bbenglish{Tree (graph theory),} acesso em 06/08/2021.}
    @a.anchor = west

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

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $3.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.}
    @d.anchor = west

## End
