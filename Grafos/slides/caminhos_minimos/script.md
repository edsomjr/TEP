## Frame
+ \bbcover{Grafos}{Caminhos mínimos}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Caminhos mínimos} };
+ \node[anchor=west] at (1, 6) { \bbtext{Seja $p$ um caminho entre os vértices $u$ e $v$ do grafo $G$ . Dizemos que $p$ é um} };
+ \node[anchor=west] at (0.5, 5) { \bbtext{\bbbold{caminho mínimo} de $u$ a $v$ se, para qualquer caminho $q$ de $u$ a $v$, vale que } };
+ \node at (6.5, 3.5) { \bbtext{$\displaystyle{\sum_{e_i\in p} w(e_i) \leq \sum_{e_j\in q} w(e_j)}$ } };
+ \node[anchor=west] at (0.5, 2) { \bbtext{onde $w(e)$ é o peso da aresta $e$. } };

## Scene
+ \node[circle, draw, very thick] (A) at (2, 5) { \bbtext{A} };
+ \node[circle, draw, very thick] (B) at (5, 5) { \bbtext{B} };
+ \node[circle, draw, very thick] (C) at (8, 7) { \bbtext{C} };
+ \node[circle, draw, very thick] (D) at (8, 3) { \bbtext{D} };
+ \node[circle, draw, very thick] (E) at (11, 5) { \bbtext{E} };
+ \draw[thick] (A) to node[above] { \bbinfo{9} } (B);
+ \draw[thick] (B) to node[above] { \bbinfo{5} } (C);
+ \draw[thick] (B) to node[above] { \bbinfo{1} } (D);
+ \draw[thick] (B) to node[above] { \bbinfo{1} } (E);
+ \draw[thick] (C) to [bend right] node[above] { \bbinfo{3} } (A);
+ \draw[thick] (C) to [bend left] node[above] { \bbinfo{2} } (E);
+ \draw[thick] (D) to [bend left] node[above] { \bbinfo{6} } (A);

- \draw[thick] (A) to node[above] { \bbinfo{9} } (B);
+ \draw[latex-,very thick,color=BBRed] (A) to node[above] { \bbinfo{9} } (B);

+ \setbeamercolor{math text}{fg=BBRed}
+ \node[anchor=west] at (1, 1.5) { $\displaystyle{\sum_{e\in p_1} w(e) = 9}$ };

- \draw[thick] (B) to node[above] { \bbinfo{5} } (C);
+ \draw[-latex,very thick,color=BBGreen] (B) to node[above] { \bbinfo{5} } (C);
- \draw[thick] (C) to [bend right] node[above] { \bbinfo{3} } (A);
+ \draw[-latex,very thick,color=BBGreen] (C) to [bend right] node[above] { \bbinfo{3} } (A);

+ \setbeamercolor{math text}{fg=BBGreen}
+ \node[anchor=west] at (4, 1.5) { $\displaystyle{\sum_{e\in p_2} w(e) = 8}$ };

- \draw[thick] (B) to node[above] { \bbinfo{1} } (D);
+ \draw[-latex,very thick,color=BBViolet] (B) to node[above] { \bbinfo{1} } (D);
- \draw[thick] (D) to [bend left] node[above] { \bbinfo{6} } (A);
+ \draw[-latex,very thick,color=BBViolet] (D) to [bend left] node[above] { \bbinfo{6} } (A);

+ \setbeamercolor{math text}{fg=BBViolet}
+ \node[anchor=west] at (7, 1.5) { $\displaystyle{\sum_{e\in p_3} w(e) = 7}$ };

- \draw[thick] (B) to node[above] { \bbinfo{1} } (E);
+ \draw[-latex,dashed,very thick,color=BBCyan] (B) to node[above] { \bbinfo{1} } (E);
- \draw[thick] (C) to [bend left] node[above] { \bbinfo{2} } (E);
+ \draw[latex-,dashed,very thick,color=BBCyan] (C) to [bend left] node[above] { \bbinfo{2} } (E);
+ \draw[-latex,dashed,very thick,color=BBCyan] (C) to node[above] { \bbinfo{3} } (A);

+ \setbeamercolor{math text}{fg=BBCyan}
+ \node[anchor=west] at (10, 1.5) { $\displaystyle{\sum_{e\in p_3} w(e) = 6}$ };

## Scene
+ \node[anchor=west] at (0, 6.5) { \Large \bbbold{Caminhos mínimos em grafos não-ponderado} };

+ \node[anchor=west] at (1, 5.5) { $\star$ \bbtext{Se $G$ é não-ponderado, o custo de um caminho pode ser medido em arestas} };

+ \node[anchor=west] at (1, 4.5) { $\star$ \bbtext{Isto equivale a considerar que todas as arestas de $G$ tem peso $1$ } };

+ \node[anchor=west] at (1, 3.5) { $\star$ \bbtext{Neste caso, uma BFS pode determinar a distância mínima entre o vértice de } };
+ \node[anchor=west] at (0.5, 3.0) { \bbtext{partida $s$ e todos os vértices de $G$ } };

+ \node[anchor=west] at (1, 2.0) { $\star$ \bbtext{A BFS também poder ser usada em grafos cujas arestas tem todas o mesmo } };
+ \node[anchor=west] at (0.5, 1.5) { \bbtext{peso $c$ } };

## Scene
+ \node[circle, draw, very thick] (A) at (2, 5.5) { \bbtext{A} };
+ \node[circle, draw, very thick] (B) at (5, 5.5) { \bbtext{B} };
+ \node[circle, draw, very thick] (C) at (8, 7.5) { \bbtext{C} };
+ \node[circle, draw, very thick] (D) at (8, 3.5) { \bbtext{D} };
+ \node[circle, draw, very thick] (E) at (11, 5.5) { \bbtext{E} };
+ \draw[thick] (A) to (B);
+ \draw[thick] (B) to (C);
+ \draw[thick] (B) to (E);
+ \draw[thick] (C) to (A);
+ \draw[thick] (C) to (E);
+ \draw[thick] (D) to (A);

+ \draw[thick] (5, 1) grid (10, 2);
+ \node[anchor=east] at (4.8, 1.5) { $\mathrm{dist}(u, \mbox{\bbtext{E}})$ };
+ \node at (5.5, 2.3) { \bbtext{A} };
+ \node at (6.5, 2.3) { \bbtext{B} };
+ \node at (7.5, 2.3) { \bbtext{C} };
+ \node at (8.5, 2.3) { \bbtext{D} };
+ \node at (9.5, 2.3) { \bbtext{E} };
+ \node at (5.5, 1.5) { $\infty$ };
+ \node at (6.5, 1.5) { $\infty$ };
+ \node at (7.5, 1.5) { $\infty$ };
+ \node at (8.5, 1.5) { $\infty$ };
+ \node at (9.5, 1.5) { $\infty$ };

+ \node[circle, draw, very thick] (E) at (11, 5.5) { \bbtext{E} };
+ \node[circle, draw, very thick,fill=BBGreen] (E) at (11, 5.5) { \bbtext{E} };

- \node at (9.5, 1.5) { $\infty$ };
+ \node at (9.5, 1.5) { $0$ };

- \node[circle, draw, very thick] (B) at (5, 5.5) { \bbtext{B} };
+ \node[circle, draw, very thick,fill=BBCyan] (B) at (5, 5.5) { \bbtext{B} };
- \node[circle, draw, very thick] (C) at (8, 7.5) { \bbtext{C} };
+ \node[circle, draw, very thick,fill=BBCyan] (C) at (8, 7.5) { \bbtext{C} };
- \draw[thick] (B) to (E);
+ \draw[latex-,very thick] (B) to (E);
- \draw[thick] (C) to (E);
+ \draw[latex-,very thick] (C) to (E);

- \node at (6.5, 1.5) { $\infty$ };
+ \node at (6.5, 1.5) { $1$ };
- \node at (7.5, 1.5) { $\infty$ };
+ \node at (7.5, 1.5) { $1$ };

- \node[circle, draw, very thick] (A) at (2, 5.5) { \bbtext{A} };
+ \node[circle, draw, very thick,fill=BBViolet] (A) at (2, 5.5) { \bbtext{A} };
- \draw[thick] (B) to (C);
+ \draw[dashed,very thick,-latex] (B) to (C);
- \draw[thick] (A) to (B);
+ \draw[latex-,very thick] (A) to (B);

- \node at (5.5, 1.5) { $\infty$ };
+ \node at (5.5, 1.5) { $2$ };

- \draw[thick] (C) to (A);
+ \draw[-latex,dashed,very thick] (C) to (A);

- \node[circle, draw, very thick] (D) at (8, 3.5) { \bbtext{D} };
+ \node[circle, draw, very thick,fill=BBOrange] (D) at (8, 3.5) { \bbtext{D} };
- \draw[thick] (D) to (A);
+ \draw[latex-,very thick] (D) to (A);

- \node at (8.5, 1.5) { $\infty$ };
+ \node at (8.5, 1.5) { $3$ };

## Frame
+ \begin{center}\inputcode{cpp}{codes/dist.cpp}\end{center}

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Caminhos mínimos em grafos ponderados} };

+ \node[anchor=west] at (0.5, 6) { $\star$ \bbtext{Se $G$ é ponderado, existem outros algoritmos que permitem determinar as} };
+ \node[anchor=west] at (0.0, 5.5) { \bbtext{distâncias mínimas de um vértice de partida $s$ aos demais vértices de $G$} };

+ \node[anchor=west] at (0.5, 4.5) { $\star$ \bbtext{No caso geral, deve ser empregado o algoritmo de Bellman-Ford} };

+ \node[anchor=west] at (0.5, 3.5) { $\star$ \bbtext{Se não há arestas com pesos negativos, pode-se usar o algoritmo de Dijkstra} };

+ \node[anchor=west] at (0.5, 2.5) { $\star$ \bbtext{Se os pesos das arestas são ou $0$ ou $1$, a BFS 0/1 é uma alternativa eficiente } };

+ \node[anchor=west] at (0.5, 1.5) { $\star$ \bbtext{Para determinar todas as distâncias mínimas entre todos os pares de vértices} };
+ \node[anchor=west] at (0.0, 1.0) { \bbtext{de $G$, há o algoritmo de Floyd-Warshall } };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Problemas sugeridos} };
+ \node[anchor=west] at (1, 5) { $1.$ \bbtext{AtCoder Beginner Contest 088 -- Problem D: Repainting } };
+ \node[anchor=west] at (1, 4) { $2.$ \bbtext{Codeforces Beta Round \#3 -- Problem A: Shortest path of the king } };
+ \node[anchor=west] at (1, 3) { $3.$ \bbtext{OJ 10000 -- Longest Paths } };
+ \node[anchor=west] at (1, 2) { $4.$ \bbtext{OJ 10959 -- The Party, Part I } };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Referências} };
+ \node[anchor=west] at (1, 5) { $1.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.} };
+ \node[anchor=west] at (1, 4) { $2.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 3) { $3.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.} };

## End
