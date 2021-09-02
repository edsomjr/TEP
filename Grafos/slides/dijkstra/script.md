## Frame
+ \bbcover{Grafos}{Algoritmo de Dijkstra}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Proponente} };

+ \node at (7, 4.5) { \includegraphics[scale=0.45]{figs/dijkstra.jpg} };
+ \node at (7, 1.5) { \bbbold{Edsger Wybe Dijkstra} };
+ \node at (7, 1.0) { \bbtext{(1956)} };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Características do algoritmo de Dijkstra } };

+ \node[anchor=west] at (0.5, 5) { $\star$ \bbtext{Computa o caminho mínimo de todos os vértices de $G(V, E)$ a um dado nó $s$} };

+ \node[anchor=west] at (0.5, 4) { $\star$ \bbtext{Processa corretamente apenas grafos com arestas não-negativas} };

+ \node[anchor=west] at (0.5, 3) { $\star$ \bbtext{Eficiência: cada aresta é processada uma única vez} };

+ \node[anchor=west] at (0.5, 2) { $\star$ \bbtext{\bbbold{Complexidade}: $O(E + V\log V)$ } };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Pseudocódigo } };

+ \node[anchor=west] at (0, 6) { \bbemph{Entrada:} \bbtext{um grafo $G(V, E)$ e um vértice $s\in V$} };
+ \node[anchor=west] at (0, 5.5) { \bbemph{Saída:} \bbtext{um vetor $d$ tal que $d[u]$ é a distância mínima em $G$ entre $s$ e $u$ } };

+ \node[anchor=west] at (1.0, 4.5) { $1.$ \bbtext{Faça $d[s] = 0$, $d[u] = \infty$ se $u\neq s$ e seja $U = V$}};

+ \node[anchor=west] at (1.0, 3.5) { $2.$ \bbtext{Enquanto $U\neq \emptyset$:} };
+ \node[anchor=west] at (2.0, 3.0) { $(a)$ \bbtext{Seja $u\in U$ o vértice mais próximo de $s$ em $U$} };
+ \node[anchor=west] at (2.0, 2.5) { $(b)$ \bbtext{Relaxe as distâncias usando as arestas que partem de $u$ } };
+ \node[anchor=west] at (2.0, 2.0) { $(c)$ \bbtext{Remova $u$ de $U$ } };

+ \node[anchor=west] at (1.0, 1.0) { $3.$ \bbtext{Retorne $d$ } };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Relaxamento} };

+ \node[circle, draw, very thick] (s) at (2, 4) { $s$ };
+ \node[circle, draw, very thick] (a) at (4, 6) { $a$ };
+ \node[circle, draw, very thick] (b) at (6, 5) { $b$ };
+ \node[circle, draw, very thick] (c) at (8, 7) { $c$ };
+ \node[circle, draw, very thick] (d) at (4, 3) { $c$ };
+ \node[circle, draw, very thick] (u) at (10, 6) { $u$ };
+ \node[circle, draw, very thick] (v) at (12, 3) { $v$ };
+ \draw[-latex,very thick,color=BBCyan] (s) to node[above left] { $r_1$ } (a);
+ \draw[-latex,very thick,color=BBCyan] (a) to node[above right] { $r_2$ } (b);
+ \draw[-latex,very thick,color=BBCyan] (b) to node[above left] { $r_3$ } (c);
+ \draw[-latex,very thick,color=BBCyan] (c) to node[above right] { $r_4$ } (u);
+ \draw[-latex,very thick,color=BBViolet] (s) to node[below] { $s_1$ } (b);
+ \draw[-latex,very thick,color=BBViolet] (b) to node[below right] { $s_2$ } (d);
+ \draw[-latex,very thick,color=BBViolet] (d) to node[below] { $s_3$ } (v);

+ \node[anchor=west] at (2, 1.5) { $\displaystyle{\dist(s, u) = \sum_{i = 1}^4 r_i}$ };
+ \node[anchor=west] at (7, 1.5) { $\displaystyle{\dist(s, v) = \sum_{j = 1}^3 s_i}$ };

- \node[anchor=west] at (2, 1.5) { $\displaystyle{\dist(s, u) = \sum_{i = 1}^4 r_i}$ };
- \node[anchor=west] at (7, 1.5) { $\displaystyle{\dist(s, v) = \sum_{j = 1}^3 s_i}$ };
+ \draw[-latex,very thick,color=BBRed] (u) to node[above right] { $w$ } (v);

+  \node[anchor=west] at (2, 1.5) { \bbtext{Se $\dist(s, u) + w < \dist(s, v)$, faça $\dist(s, v) = \dist(s, u) + w$} };

## Scene
+ \node[circle, draw, very thick] (A) at (5, 7.5) { \bbtext{A} };
+ \node[circle, draw, very thick] (B) at (2, 5.5) { \bbtext{B} };
+ \node[circle, draw, very thick] (C) at (5, 3.5) { \bbtext{C} };
+ \node[circle, draw, very thick] (D) at (8, 7.5) { \bbtext{D} };
+ \node[circle, draw, very thick] (E) at (11, 5.5) { \bbtext{E} };
+ \node[circle, draw, very thick] (F) at (8, 3.5) { \bbtext{F} };
+ \draw[thick] (A) to node[above] { \bbinfo{9} } (B);
+ \draw[thick] (A) to node[right] { \bbinfo{7} } (C);
+ \draw[thick] (A) to node[above] { \bbinfo{4} } (D);
+ \draw[thick] (A) to node[below] { \bbinfo{2} } (E);
+ \draw[thick] (B) to node[below] { \bbinfo{1} } (C);
+ \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[thick] (C) to node[right] { \bbinfo{2} } (D);
+ \draw[thick] (D) to node[above] { \bbinfo{1} } (E);
+ \draw[thick] (E) to node[below] { \bbinfo{11} } (F);

+ \draw[thick] (2, 1) grid (8, 2);
+ \node[anchor=east] at (1.8, 1.5) { $\mathrm{dist}(u, \mbox{\bbtext{A}})$ };
+ \node at (2.5, 2.3) { \bbtext{A} };
+ \node at (3.5, 2.3) { \bbtext{B} };
+ \node at (4.5, 2.3) { \bbtext{C} };
+ \node at (5.5, 2.3) { \bbtext{D} };
+ \node at (6.5, 2.3) { \bbtext{E} };
+ \node at (7.5, 2.3) { \bbtext{F} };
+ \node at (2.5, 1.5) { $0$ };
+ \node at (3.5, 1.5) { $\infty$ };
+ \node at (4.5, 1.5) { $\infty$ };
+ \node at (5.5, 1.5) { $\infty$ };
+ \node at (6.5, 1.5) { $\infty$ };
+ \node at (7.5, 1.5) { $\infty$ };
+ \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ A, B, C, D, E, F $\}$ } };

- \node[circle, draw, very thick] (A) at (5, 7.5) { \bbtext{A} };
+ \node[circle, draw, very thick,fill=BBGreen] (A) at (5, 7.5) { \bbtext{A} };
- \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ A, B, C, D, E, F $\}$ } };
+ \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ B, C, D, E, F $\}$ } };

- \draw[thick] (A) to node[above] { \bbinfo{9} } (B);
+ \draw[-latex,color=BBCyan,very thick] (A) to node[above] { \bbinfo{9} } (B);
- \node at (3.5, 1.5) { $\infty$ };
+ \node at (3.5, 1.5) { $\mathbf{9}$ };

- \draw[-latex,color=BBCyan,very thick] (A) to node[above] { \bbinfo{9} } (B);
+ \draw[thick] (A) to node[above] { \bbinfo{9} } (B);
- \node at (3.5, 1.5) { $\mathbf{9}$ };
+ \node at (3.5, 1.5) { ${9}$ };
- \node at (4.5, 1.5) { $\infty$ };
+ \node at (4.5, 1.5) { $\mathbf{7}$ };
- \draw[thick] (A) to node[right] { \bbinfo{7} } (C);
+ \draw[-latex,color=BBCyan,very thick] (A) to node[right] { \bbinfo{7} } (C);

- \draw[-latex,color=BBCyan,very thick] (A) to node[right] { \bbinfo{7} } (C);
+ \draw[thick] (A) to node[right] { \bbinfo{7} } (C);
- \node at (4.5, 1.5) { $\mathbf{7}$ };
+ \node at (4.5, 1.5) { ${7}$ };
- \node at (5.5, 1.5) { $\infty$ };
+ \node at (5.5, 1.5) { $\mathbf{4}$ };
- \draw[thick] (A) to node[above] { \bbinfo{4} } (D);
+ \draw[-latex,color=BBCyan,very thick] (A) to node[above] { \bbinfo{4} } (D);

- \draw[-latex,color=BBCyan,very thick] (A) to node[above] { \bbinfo{4} } (D);
+ \draw[thick] (A) to node[above] { \bbinfo{4} } (D);
- \node at (5.5, 1.5) { $\mathbf{4}$ };
+ \node at (5.5, 1.5) { ${4}$ };
- \node at (6.5, 1.5) { $\infty$ };
+ \node at (6.5, 1.5) { $\mathbf{2}$ };
- \draw[thick] (A) to node[below] { \bbinfo{2} } (E);
+ \draw[-latex,color=BBCyan,very thick] (A) to node[below] { \bbinfo{2} } (E);

- \node at (6.5, 1.5) { $\mathbf{2}$ };
+ \node at (6.5, 1.5) { ${2}$ };
- \draw[-latex,color=BBCyan,very thick] (A) to node[below] { \bbinfo{2} } (E);
+ \draw[thick] (A) to node[below] { \bbinfo{2} } (E);
- \node[circle, draw, very thick,fill=BBGreen] (A) at (5, 7.5) { \bbtext{A} };
+ \node[circle, draw, very thick,fill=BBGray] (A) at (5, 7.5) { \bbtext{A} };
- \node[circle, draw, very thick] (E) at (11, 5.5) { \bbtext{E} };
+ \node[circle, draw, very thick,fill=BBGreen] (E) at (11, 5.5) { \bbtext{E} };
- \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ B, C, D, E, F $\}$ } };
+ \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ B, C, D, F $\}$ } };

- \draw[thick] (A) to node[below] { \bbinfo{2} } (E);
+ \draw[latex-,color=BBRed,very thick] (A) to node[below] { \bbinfo{2} } (E);

- \draw[latex-,color=BBRed,very thick] (A) to node[below] { \bbinfo{2} } (E);
+ \draw[thick] (A) to node[below] { \bbinfo{2} } (E);
- \draw[thick] (D) to node[above] { \bbinfo{1} } (E);
+ \draw[latex-,color=BBCyan,very thick] (D) to node[above] { \bbinfo{1} } (E);
- \node at (5.5, 1.5) { ${4}$ };
+ \node at (5.5, 1.5) { $\mathbf{3}$ };

- \node at (5.5, 1.5) { $\mathbf{3}$ };
+ \node at (5.5, 1.5) { ${3}$ };
- \draw[latex-,color=BBCyan,very thick] (D) to node[above] { \bbinfo{1} } (E);
+ \draw[thick] (D) to node[above] { \bbinfo{1} } (E);
- \draw[thick] (E) to node[below] { \bbinfo{11} } (F);
+ \draw[-latex,color=BBCyan,very thick] (E) to node[below] { \bbinfo{11} } (F);
- \node at (7.5, 1.5) { $\infty$ };
+ \node at (7.5, 1.5) { $\mathbf{13}$ };

- \draw[-latex,color=BBCyan,very thick] (E) to node[below] { \bbinfo{11} } (F);
+ \draw[thick] (E) to node[below] { \bbinfo{11} } (F);
- \node at (7.5, 1.5) { $\mathbf{13}$ };
+ \node at (7.5, 1.5) { ${13}$ };
- \node[circle, draw, very thick,fill=BBGreen] (E) at (11, 5.5) { \bbtext{E} };
+ \node[circle, draw, very thick,fill=BBGray] (E) at (11, 5.5) { \bbtext{E} };
- \node[circle, draw, very thick] (D) at (8, 7.5) { \bbtext{D} };
+ \node[circle, draw, very thick,fill=BBGreen] (D) at (8, 7.5) { \bbtext{D} };
- \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ B, C, D, F $\}$ } };
+ \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ B, C, F $\}$ } };

- \draw[thick] (C) to node[right] { \bbinfo{2} } (D);
+ \draw[latex-,color=BBCyan,very thick] (C) to node[right] { \bbinfo{2} } (D);
- \node at (4.5, 1.5) { ${7}$ };
+ \node at (4.5, 1.5) { $\mathbf{5}$ };

- \draw[latex-,color=BBCyan,very thick] (C) to node[right] { \bbinfo{2} } (D);
+ \draw[thick] (C) to node[right] { \bbinfo{2} } (D);
- \node at (4.5, 1.5) { $\mathbf{5}$ };
+ \node at (4.5, 1.5) { ${5}$ };
+ \node[circle, draw, very thick,fill=BBGreen] (D) at (8, 7.5) { \bbtext{D} };
+ \node[circle, draw, very thick,fill=BBGray] (D) at (8, 7.5) { \bbtext{D} };
- \node[circle, draw, very thick] (C) at (5, 3.5) { \bbtext{C} };
+ \node[circle, draw, very thick,fill=BBGreen] (C) at (5, 3.5) { \bbtext{C} };
- \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ B, C, F $\}$ } };
+ \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ B, F $\}$ } };

- \draw[thick] (B) to node[below] { \bbinfo{1} } (C);
+ \draw[latex-,color=BBCyan,very thick] (B) to node[below] { \bbinfo{1} } (C);
- \node at (3.5, 1.5) { ${9}$ };
+ \node at (3.5, 1.5) { $\mathbf{6}$ };

- \node at (3.5, 1.5) { $\mathbf{6}$ };
+ \node at (3.5, 1.5) { ${6}$ };
- \draw[latex-,color=BBCyan,very thick] (B) to node[below] { \bbinfo{1} } (C);
+ \draw[thick] (B) to node[below] { \bbinfo{1} } (C);
- \node[circle, draw, very thick,fill=BBGreen] (C) at (5, 3.5) { \bbtext{C} };
+ \node[circle, draw, very thick,fill=BBGray] (C) at (5, 3.5) { \bbtext{C} };
- \node[circle, draw, very thick] (B) at (2, 5.5) { \bbtext{B} };
+ \node[circle, draw, very thick,fill=BBGreen] (B) at (2, 5.5) { \bbtext{B} };
- \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ B, F $\}$ } };
+ \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ F $\}$ } };

- \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[-latex,color=BBCyan,very thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
- \node at (7.5, 1.5) { ${13}$ };
+ \node at (7.5, 1.5) { $\mathbf{9}$ };

- \node at (7.5, 1.5) { $\mathbf{9}$ };
+ \node at (7.5, 1.5) { ${9}$ };
- \draw[-latex,color=BBCyan,very thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
- \node[circle, draw, very thick,fill=BBGreen] (B) at (2, 5.5) { \bbtext{B} };
+ \node[circle, draw, very thick,fill=BBGray] (B) at (2, 5.5) { \bbtext{B} };
- \node[circle, draw, very thick] (F) at (8, 3.5) { \bbtext{F} };
+ \node[circle, draw, very thick,fill=BBGreen] (F) at (8, 3.5) { \bbtext{F} };
- \node[anchor=west] at (9, 1.5) { \bbtext{$U = \{$ F $\}$ } };
+ \node[anchor=west] at (9, 1.5) { \bbtext{$U = \emptyset$ } };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Identificação eficiente do vértice $u$ mais próximo de $s$} };

+ \node[circle, draw, very thick] (A) at (3.8, 5.5) { \bbtext{2} };
+ \node[circle, draw, very thick] (B) at (2.4, 3.75) { \bbtext{4} };
+ \node[circle, draw, very thick] (C) at (5.2, 3.75) { \bbtext{3} };
+ \node[circle, draw, very thick] (D) at (1.7, 2) { \bbtext{9} };
+ \node[circle, draw, very thick] (E) at (3.1, 2) { \bbtext{6} };
+ \node[circle, draw, very thick] (F) at (4.5, 2) { \bbtext{7} };
+ \node[circle, draw, very thick] (G) at (5.9, 2) { \bbtext{5} };
+ \draw[thick] (A) to (B);
+ \draw[thick] (A) to (C);
+ \draw[thick] (B) to (D);
+ \draw[thick] (B) to (E);
+ \draw[thick] (C) to (F);
+ \draw[thick] (C) to (G);
+ \node at (3.8, 1) { \bbenglish{min heap} };

+ \node at (3.8, 0.5) { \bbtext{(\texttt{priority\_queue})} };

+ \node[circle, draw, very thick,fill=BBBlack] (A1) at (10.1, 5.5) { \bbchalk{5} };
+ \node[circle, draw, very thick,fill=BBRed] (B1) at (8.7, 3.75) { \bbchalk{3} };
+ \node[circle, draw, very thick,fill=BBRed] (C1) at (11.5, 3.75) { \bbchalk{7} };
+ \node[circle, draw, very thick,fill=BBBlack] (D1) at (8, 2) { \bbchalk{2} };
+ \node[circle, draw, very thick,fill=BBBlack] (E1) at (9.4, 2) { \bbchalk{4} };
+ \node[circle, draw, very thick,fill=BBBlack] (F1) at (10.8, 2) { \bbchalk{6} };
+ \node[circle, draw, very thick,fill=BBBlack] (G1) at (12.2, 2) { \bbchalk{9} };
+ \draw[thick] (A1) to (B1);
+ \draw[thick] (A1) to (C1);
+ \draw[thick] (B1) to (D1);
+ \draw[thick] (B1) to (E1);
+ \draw[thick] (C1) to (F1);
+ \draw[thick] (C1) to (G1);
+ \node at (10.1, 1) { \bbenglish{red-black tree} };

+ \node at (10.1, 0.5) { \bbtext{(\texttt{set})} };

## Frame
+ \begin{center} \inputsnippet{cpp}{10}{24}{codes/dijkstra.cpp} \end{center}

## Frame
+ \begin{center} \inputsnippet{cpp}{25}{39}{codes/dijkstra.cpp} \end{center}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Identificação do caminho mínimo} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{O algoritmo de Dijkstra computa as distâncias mínimas, mas não os} };
+ \node[anchor=west] at (0.5, 4.5) { \bbtext{caminhos mínimos} };

+ \node[anchor=west] at (1, 3.5) { $\star$ \bbtext{Para determinar um caminho mínimo, é preciso definir o vetor auxiliar } };
+ \node[anchor=west] at (0.5, 3.0) { \bbtext{$\mathrm{pred}$, onde $\mathrm{pred}[u] = $ antecessor de $u$ no caminho mínimo de $s$ a $u$ } };

+ \node[anchor=west] at (1, 2.0) { $\star$ \bbtext{No início do algoritmo, $\mathrm{pred}[s] = s$ e $\mathrm{pred}[u] = \mathrm{undef}$, se $u\neq s$ } };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Identificação do caminho mínimo} };
+ \node[anchor=west] at (1, 5.0) { $\star$ \bbtext{Se $(u, v)$ atualizar $d[v]$, faça $\mathrm{pred}[v] = u$} };

+ \node[anchor=west] at (1, 4.0) { $\star$ \bbtext{A sequência } };
+ \node[anchor=west] at (2, 3.0) { \bbtext{$ p = \{ (s, \mathrm{pred}^{k - 1}[u]), \ldots, (\mathrm{pred}[\mathrm{pred}[u]], \mathrm{pred}[u]), (\mathrm{pred}[u], u)\}$ } };

+ \node[anchor=west] at (0.5, 2.0) { \bbtext{é um caminho mínimo de $s$ a $u$ composto de $k$ arestas e tamanho $d[u]$} };

## Scene
+ \node[circle, draw, very thick] (A) at (0, 4) { \bbtext{A} };
+ \node[circle, draw, very thick] (B) at (3, 7) { \bbtext{B} };
+ \node[circle, draw, very thick] (C) at (6, 4) { \bbtext{C} };
+ \node[circle, draw, very thick] (D) at (3, 1) { \bbtext{D} };
+ \draw[-latex,thick] (A) to node[above left] { \bbinfo{1} } (B);
+ \draw[-latex,thick] (A) to node[above] { \bbinfo{4} } (C);
+ \draw[-latex,thick] (A) to node[below left] { \bbinfo{9} } (D);
+ \draw[-latex,thick] (B) to node[above right] { \bbinfo{2} } (C);
+ \draw[-latex,thick] (C) to node[below right] { \bbinfo{5} } (D);

+ \draw[thick] (9, 5) grid (13, 6);
+ \node[anchor=east] at (8.8, 5.5) { $\mathrm{dist}(u, \mbox{\bbtext{A}})$ };
+ \node at (9.5, 6.3) { \bbtext{A} };
+ \node at (10.5, 6.3) { \bbtext{B} };
+ \node at (11.5, 6.3) { \bbtext{C} };
+ \node at (12.5, 6.3) { \bbtext{D} };
+ \node at (9.5, 5.5) { $0$ };
+ \node at (10.5, 5.5) { $\infty$ };
+ \node at (11.5, 5.5) { $\infty$ };
+ \node at (12.5, 5.5) { $\infty$ };

+ \draw[thick] (9, 2) grid (13, 3);
+ \node[anchor=east] at (8.8, 2.5) { $\mathrm{pred}(u)$ };
+ \node at (9.5, 3.3) { \bbtext{A} };
+ \node at (10.5, 3.3) { \bbtext{B} };
+ \node at (11.5, 3.3) { \bbtext{C} };
+ \node at (12.5, 3.3) { \bbtext{D} };
+ \node at (9.5, 2.5) { $\bbtext{A}$ };
+ \node at (10.5, 2.5) { $\bbtext{-}$ };
+ \node at (11.5, 2.5) { $\bbtext{-}$ };
+ \node at (12.5, 2.5) { $\bbtext{-}$ };

- \draw[-latex,thick] (A) to node[above left] { \bbinfo{1} } (B);
+ \draw[-latex,color=BBCyan,very thick] (A) to node[above left] { \bbinfo{1} } (B);
- \node at (10.5, 5.5) { $\infty$ };
+ \node at (10.5, 5.5) { $\mathbf{1}$ };
- \node at (10.5, 2.5) { $\bbtext{-}$ };
+ \node at (10.5, 2.5) { $\bbupdate{A}$ };

- \draw[-latex,color=BBCyan,very thick] (A) to node[above left] { \bbinfo{1} } (B);
+ \draw[-latex,thick] (A) to node[above left] { \bbinfo{1} } (B);
- \node at (10.5, 2.5) { $\bbupdate{A}$ };
+ \node at (10.5, 2.5) { $\bbtext{A}$ };
- \node at (10.5, 5.5) { $\mathbf{1}$ };
+ \node at (10.5, 5.5) { ${1}$ };
- \draw[-latex,thick] (A) to node[above] { \bbinfo{4} } (C);
+ \draw[-latex,color=BBCyan,very thick] (A) to node[above] { \bbinfo{4} } (C);
- \node at (11.5, 5.5) { $\infty$ };
+ \node at (11.5, 5.5) { $\mathbf{4}$ };
- \node at (11.5, 2.5) { $\bbtext{-}$ };
+ \node at (11.5, 2.5) { $\bbupdate{A}$ };

- \draw[-latex,color=BBCyan,very thick] (A) to node[above] { \bbinfo{4} } (C);
+ \draw[-latex,thick] (A) to node[above] { \bbinfo{4} } (C);
- \node at (11.5, 5.5) { $\mathbf{4}$ };
+ \node at (11.5, 5.5) { ${4}$ };
- \node at (11.5, 2.5) { $\bbupdate{A}$ };
+ \node at (11.5, 2.5) { $\bbtext{A}$ };
- \draw[-latex,thick] (A) to node[below left] { \bbinfo{9} } (D);
+ \draw[-latex,color=BBCyan,very thick] (A) to node[below left] { \bbinfo{9} } (D);
- \node at (12.5, 5.5) { $\infty$ };
+ \node at (12.5, 5.5) { $\mathbf{9}$ };
- \node at (12.5, 2.5) { $\bbtext{-}$ };
+ \node at (12.5, 2.5) { $\bbupdate{A}$ };

- \draw[-latex,color=BBCyan,very thick] (A) to node[below left] { \bbinfo{9} } (D);
+ \draw[-latex,thick] (A) to node[below left] { \bbinfo{9} } (D);
- \node at (12.5, 5.5) { $\mathbf{9}$ };
+ \node at (12.5, 5.5) { ${9}$ };
- \node at (12.5, 2.5) { $\bbupdate{A}$ };
+ \node at (12.5, 2.5) { $\bbtext{A}$ };
- \draw[-latex,thick] (B) to node[above right] { \bbinfo{2} } (C);
+ \draw[-latex,color=BBCyan,very thick] (B) to node[above right] { \bbinfo{2} } (C);
- \node at (11.5, 5.5) { ${4}$ };
+ \node at (11.5, 5.5) { $\mathbf{3}$ };
- \node at (11.5, 2.5) { $\bbtext{A}$ };
+ \node at (11.5, 2.5) { $\bbupdate{B}$ };

- \draw[-latex,color=BBCyan,very thick] (B) to node[above right] { \bbinfo{2} } (C);
+ \draw[-latex,thick] (B) to node[above right] { \bbinfo{2} } (C);
- \node at (11.5, 5.5) { $\mathbf{3}$ };
+ \node at (11.5, 5.5) { ${3}$ };
- \node at (11.5, 2.5) { $\bbupdate{B}$ };
+ \node at (11.5, 2.5) { $\bbtext{B}$ };
- \draw[-latex,thick] (C) to node[below right] { \bbinfo{5} } (D);
+ \draw[-latex,color=BBCyan,very thick] (C) to node[below right] { \bbinfo{5} } (D);
- \node at (12.5, 5.5) { ${9}$ };
+ \node at (12.5, 5.5) { $\mathbf{8}$ };
- \node at (12.5, 2.5) { $\bbtext{A}$ };
+ \node at (12.5, 2.5) { $\bbupdate{C}$ };

- \node at (12.5, 2.5) { $\bbupdate{C}$ };
+ \node at (12.5, 2.5) { $\bbtext{C}$ };
- \node at (12.5, 5.5) { $\mathbf{8}$ };
+ \node at (12.5, 5.5) { ${8}$ };
- \draw[-latex,color=BBCyan,very thick] (C) to node[below right] { \bbinfo{5} } (D);
+ \draw[-latex,thick] (C) to node[below right] { \bbinfo{5} } (D);

+ \draw[-latex,thick,color=BBViolet,dashed] (C) to [bend left] node[below right, pos=0.3] { \tiny $(\mathrm{pred}(\mbox{\bbtext{D}}), \mbox{\bbtext{D}})$ } (D);

+ \draw[-latex,thick,color=BBViolet,dashed] (B) to [bend left] node[above right, pos=0.3] { \tiny $(\mathrm{pred}(\mbox{\bbtext{C}}), \mbox{\bbtext{C}})$ } (C);

+ \draw[-latex,thick,color=BBViolet,dashed] (A) to [bend left] node[above left, pos=0.7] { \tiny $(\mathrm{pred}(\mbox{\bbtext{B}}), \mbox{\bbtext{B}})$ } (B);

## Frame
+ \begin{center} \inputsnippet{cpp}{11}{26}{codes/dijkstra-path.cpp} \end{center}

## Frame
+ \begin{center} \inputsnippet{cpp}{27}{43}{codes/dijkstra-path.cpp} \end{center}

## Frame
+ \begin{center} \inputsnippet{cpp}{45}{58}{codes/dijkstra-path.cpp} \end{center}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Problemas sugeridos} };
+ \node[anchor=west] at (1, 5) { $1.$ \bbtext{AtCoder Beginner Contest 143 -- Problem E: Travel by Car} };
+ \node[anchor=west] at (1, 4) { $2.$ \bbtext{Codeforces Alpha Round \#20 - Problem C: Dijkstra?} };
+ \node[anchor=west] at (1, 3) { $3.$ \bbtext{OJ 1112 -- Mice and Maze } };
+ \node[anchor=west] at (1, 2) { $4.$ \bbtext{OJ 10986 -- Sending email } };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Referências} };
+ \node[anchor=west] at (1, 6) { $1.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.} };
+ \node[anchor=west] at (1, 5) { $2.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 4) { $3.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.} };
+ \node[anchor=west] at (1, 3) { $4.$ \bbbold{Wikipédia}, \bbenglish{Dijkstra's algorithm.} \bbtext{Acesso em 13/07/2021.} };
+ \node[anchor=west] at (1, 2) { $5.$ \bbbold{Wikipédia}, \bbenglish{Edsger W. Dijkstra.} \bbtext{Acesso em 13/07/2021.} };

## End
