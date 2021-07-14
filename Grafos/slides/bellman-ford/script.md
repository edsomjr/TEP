## Frame
+ \bbcover{Grafos}{Algoritmo de Bellman-Ford}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Proponentes} };

+ \node[anchor=north west] at (0.5, 6) { \includegraphics[scale=0.45]{figs/ford.png} };
+ \node[anchor=west] at (4.25, 5.5) { \bbbold{Lester Randolph Ford Jr. } };
+ \node[anchor=west] at (4.75, 5.0) { \bbtext{(1956)} };

+ \node[anchor=north west] at (9, 6) { \includegraphics[scale=0.5]{figs/bellman.jpg} };
+ \node[anchor=east] at (9, 2.0) { \bbbold{Richard Ernest Bellman} };
+ \node[anchor=east] at (8.5, 1.5) { \bbtext{(1958)} };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Características do algoritmo de Bellman-Ford } };

+ \node[anchor=west] at (0.5, 5) { $\star$ \bbtext{Computa o caminho mínimo de todos os vértices de $G(V, E)$ a um dado nó $s$} };

+ \node[anchor=west] at (0.5, 4) { $\star$ \bbtext{É capaz de processar arestas negativas} };

+ \node[anchor=west] at (0.5, 3) { $\star$ \bbtext{Não processa, mas identifica ciclos negativos} };

+ \node[anchor=west] at (0.5, 2) { $\star$ \bbtext{\bbbold{Complexidade}: $O(VE)$ } };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Pseudocódigo } };

+ \node[anchor=west] at (0, 6) { \bbemph{Entrada:} \bbtext{um grafo $G(V, E)$ e um vértice $s\in V$} };
+ \node[anchor=west] at (0, 5.5) { \bbemph{Saída:} \bbtext{um vetor $d$ tal que $d[u]$ é a distância mínima em $G$ entre $s$ e $u$ } };

+ \node[anchor=west] at (1, 4.5) { $1.$ \bbtext{Faça $d[s] = 0$ e $d[u] = \infty$ para todos vértices $u\in V$ tais que $u\neq s$ }};

+ \node[anchor=west] at (1, 3.5) { $2.$ \bbtext{Para cada aresta $(u, v, w)\in E$, se existe um caminho de $s$ a $u$ (isto é, } };
+ \node[anchor=west] at (0.5, 3.0) { \bbtext{$d[u] < \infty$) e $d[u] + w < d[v]$, faça $d[v] = d[u] + w$} };

+ \node[anchor=west] at (1, 2.0) { $3.$ \bbtext{Se o vetor $d$ foi atualizado ao menos uma vez, volte ao passo $2.$ } };

+ \node[anchor=west] at (1, 1.0) { $4.$ \bbtext{Retorne $d$ } };

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

+ \draw[thick] (4, 1) grid (10, 2);
+ \node[anchor=east] at (3.8, 1.5) { $\mathrm{dist}(u, \mbox{\bbtext{A}})$ };
+ \node at (4.5, 2.3) { \bbtext{A} };
+ \node at (5.5, 2.3) { \bbtext{B} };
+ \node at (6.5, 2.3) { \bbtext{C} };
+ \node at (7.5, 2.3) { \bbtext{D} };
+ \node at (8.5, 2.3) { \bbtext{E} };
+ \node at (9.5, 2.3) { \bbtext{F} };
+ \node at (4.5, 1.5) { $0$ };
+ \node at (5.5, 1.5) { $\infty$ };
+ \node at (6.5, 1.5) { $\infty$ };
+ \node at (7.5, 1.5) { $\infty$ };
+ \node at (8.5, 1.5) { $\infty$ };
+ \node at (9.5, 1.5) { $\infty$ };

- \draw[thick] (A) to node[above] { \bbinfo{9} } (B);
+ \draw[-latex,very thick,color=BBCyan] (A) to node[above] { \bbinfo{9} } (B);
- \node at (5.5, 1.5) { $\infty$ };
+ \node at (5.5, 1.5) { $\mathbf{9}$ };

- \draw[-latex,very thick,color=BBCyan] (A) to node[above] { \bbinfo{9} } (B);
- \node at (5.5, 1.5) { $\mathbf{9}$ };
+ \draw[thick] (A) to node[above] { \bbinfo{9} } (B);
+ \node at (5.5, 1.5) { $9$ };
- \draw[thick] (A) to node[right] { \bbinfo{7} } (C);
+ \draw[-latex,very thick,color=BBCyan] (A) to node[right] { \bbinfo{7} } (C);
- \node at (6.5, 1.5) { $\infty$ };
+ \node at (6.5, 1.5) { $\mathbf{7}$ };

- \draw[-latex,very thick,color=BBCyan] (A) to node[right] { \bbinfo{7} } (C);
+ \draw[thick] (A) to node[right] { \bbinfo{7} } (C);
- \draw[thick] (A) to node[above] { \bbinfo{4} } (D);
+ \draw[-latex,very thick,color=BBCyan] (A) to node[above] { \bbinfo{4} } (D);
- \node at (6.5, 1.5) { $\mathbf{7}$ };
+ \node at (6.5, 1.5) { ${7}$ };
- \node at (7.5, 1.5) { $\infty$ };
+ \node at (7.5, 1.5) { $\mathbf{4}$ };

- \draw[-latex,very thick,color=BBCyan] (A) to node[above] { \bbinfo{4} } (D);
+ \draw[thick] (A) to node[above] { \bbinfo{4} } (D);
- \node at (7.5, 1.5) { $\mathbf{4}$ };
+ \node at (7.5, 1.5) { ${4}$ };
- \draw[thick] (A) to node[below] { \bbinfo{2} } (E);
+ \draw[-latex,very thick,color=BBCyan] (A) to node[below] { \bbinfo{2} } (E);
- \node at (8.5, 1.5) { $\infty$ };
+ \node at (8.5, 1.5) { $\mathbf{2}$ };

- \draw[-latex,very thick,color=BBCyan] (A) to node[below] { \bbinfo{2} } (E);
+ \draw[thick] (A) to node[below] { \bbinfo{2} } (E);
- \draw[thick] (A) to node[above] { \bbinfo{9} } (B);
+ \draw[latex-,very thick,color=BBRed] (A) to node[above] { \bbinfo{9} } (B);
- \node at (8.5, 1.5) { $\mathbf{2}$ };
+ \node at (8.5, 1.5) { ${2}$ };

- \draw[thick] (B) to node[below] { \bbinfo{1} } (C);
+ \draw[-latex,very thick,color=BBRed] (B) to node[below] { \bbinfo{1} } (C);
- \draw[latex-,very thick,color=BBRed] (A) to node[above] { \bbinfo{9} } (B);
+ \draw[thick] (A) to node[above] { \bbinfo{9} } (B);

- \draw[-latex,very thick,color=BBRed] (B) to node[below] { \bbinfo{1} } (C);
+ \draw[thick] (B) to node[below] { \bbinfo{1} } (C);
- \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[-latex,very thick,color=BBCyan] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
- \node at (9.5, 1.5) { $\infty$ };
+ \node at (9.5, 1.5) { $\mathbf{12}$ };

- \draw[-latex,very thick,color=BBCyan] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
- \node at (9.5, 1.5) { $\mathbf{12}$ };
+ \node at (9.5, 1.5) { ${12}$ };
- \draw[thick] (A) to node[right] { \bbinfo{7} } (C);
+ \draw[latex-,very thick,color=BBRed] (A) to node[right] { \bbinfo{7} } (C);

- \draw[latex-,very thick,color=BBRed] (A) to node[right] { \bbinfo{7} } (C);
+ \draw[thick] (A) to node[right] { \bbinfo{7} } (C);
- \draw[thick] (B) to node[below] { \bbinfo{1} } (C);
+ \draw[latex-,very thick,color=BBCyan] (B) to node[below] { \bbinfo{1} } (C);
- \node at (5.5, 1.5) { $9$ };
+ \node at (5.5, 1.5) { $\mathbf{8}$ };

- \node at (5.5, 1.5) { $\mathbf{8}$ };
+ \node at (5.5, 1.5) { ${8}$ };
- \draw[latex-,very thick,color=BBCyan] (B) to node[below] { \bbinfo{1} } (C);
+ \draw[thick] (B) to node[below] { \bbinfo{1} } (C);
- \draw[thick] (C) to node[right] { \bbinfo{2} } (D);
+ \draw[-latex,very thick,color=BBRed] (C) to node[right] { \bbinfo{2} } (D);

- \draw[-latex,very thick,color=BBRed] (C) to node[right] { \bbinfo{2} } (D);
+ \draw[thick] (C) to node[right] { \bbinfo{2} } (D);
- \draw[thick] (A) to node[above] { \bbinfo{4} } (D);
+ \draw[latex-,very thick,color=BBRed] (A) to node[above] { \bbinfo{4} } (D);

- \draw[latex-,very thick,color=BBRed] (A) to node[above] { \bbinfo{4} } (D);
+ \draw[thick] (A) to node[above] { \bbinfo{4} } (D);
- \draw[thick] (C) to node[right] { \bbinfo{2} } (D);
+ \draw[latex-,very thick,BBCyan] (C) to node[right] { \bbinfo{2} } (D);
- \node at (6.5, 1.5) { ${7}$ };
+ \node at (6.5, 1.5) { $\mathbf{6}$ };

- \node at (6.5, 1.5) { $\mathbf{6}$ };
+ \node at (6.5, 1.5) { ${6}$ };
- \draw[latex-,very thick,BBCyan] (C) to node[right] { \bbinfo{2} } (D);
+ \draw[thick] (C) to node[right] { \bbinfo{2} } (D);
- \draw[thick] (D) to node[above] { \bbinfo{1} } (E);
+ \draw[-latex,very thick,color=BBRed] (D) to node[above] { \bbinfo{1} } (E);

- \draw[thick] (A) to node[below] { \bbinfo{2} } (E);
+ \draw[latex-,very thick,color=BBRed] (A) to node[below] { \bbinfo{2} } (E);
- \draw[-latex,very thick,color=BBRed] (D) to node[above] { \bbinfo{1} } (E);
+ \draw[thick] (D) to node[above] { \bbinfo{1} } (E);

- \draw[latex-,very thick,color=BBRed] (A) to node[below] { \bbinfo{2} } (E);
+ \draw[thick] (A) to node[below] { \bbinfo{2} } (E);
- \draw[thick] (D) to node[above] { \bbinfo{1} } (E);
+ \draw[latex-,very thick,color=BBCyan] (D) to node[above] { \bbinfo{1} } (E);
- \node at (7.5, 1.5) { ${4}$ };
+ \node at (7.5, 1.5) { $\mathbf{3}$ };

- \draw[latex-,very thick,color=BBCyan] (D) to node[above] { \bbinfo{1} } (E);
+ \draw[thick] (D) to node[above] { \bbinfo{1} } (E);
- \node at (7.5, 1.5) { $\mathbf{3}$ };
+ \node at (7.5, 1.5) { ${3}$ };
- \draw[thick] (E) to node[below] { \bbinfo{11} } (F);
+ \draw[-latex,very thick,color=BBRed] (E) to node[below] { \bbinfo{11} } (F);

- \draw[-latex,very thick,color=BBRed] (E) to node[below] { \bbinfo{11} } (F);
+ \draw[thick] (E) to node[below] { \bbinfo{11} } (F);
- \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[latex-,very thick,color=BBRed] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);

- \draw[latex-,very thick,color=BBRed] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
- \draw[thick] (E) to node[below] { \bbinfo{11} } (F);
+ \draw[latex-,very thick,color=BBRed] (E) to node[below] { \bbinfo{11} } (F);

+ \node[anchor=west] at (11, 3) { \bbbold{Round \#2} };
+ \draw[thick] (E) to node[below] { \bbinfo{11} } (F);
- \draw[latex-,very thick,color=BBRed] (E) to node[below] { \bbinfo{11} } (F);
- \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[-latex,very thick,color=BBCyan] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
- \node at (9.5, 1.5) { ${12}$ };
+ \node at (9.5, 1.5) { $\mathbf{11}$ };
 
- \node at (9.5, 1.5) { $\mathbf{11}$ };
+ \node at (9.5, 1.5) { ${11}$ };
- \draw[-latex,very thick,color=BBCyan] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
- \draw[thick] (B) to node[below] { \bbinfo{1} } (C);
+ \draw[latex-,very thick,color=BBCyan] (B) to node[below] { \bbinfo{1} } (C);
- \node at (5.5, 1.5) { ${8}$ };
+ \node at (5.5, 1.5) { $\mathbf{7}$ };

- \node at (5.5, 1.5) { $\mathbf{7}$ };
+ \node at (5.5, 1.5) { ${7}$ };
- \draw[latex-,very thick,color=BBCyan] (B) to node[below] { \bbinfo{1} } (C);
+ \draw[thick] (B) to node[below] { \bbinfo{1} } (C);
- \draw[thick] (C) to node[right] { \bbinfo{2} } (D);
+ \draw[latex-,very thick,color=BBCyan] (C) to node[right] { \bbinfo{2} } (D);
- \node at (6.5, 1.5) { ${6}$ };
+ \node at (6.5, 1.5) { $\mathbf{5}$ };

- \node[anchor=west] at (11, 3) { \bbbold{Round \#2} };
+ \node[anchor=west] at (11, 3) { \bbbold{Round \#3} };
- \draw[latex-,very thick,color=BBCyan] (C) to node[right] { \bbinfo{2} } (D);
+ \draw[thick] (C) to node[right] { \bbinfo{2} } (D);
- \node at (6.5, 1.5) { $\mathbf{5}$ };
+ \node at (6.5, 1.5) { ${5}$ };
- \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[-latex,very thick,color=BBCyan] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
- \node at (9.5, 1.5) { ${11}$ };
+ \node at (9.5, 1.5) { $\mathbf{10}$ };

- \node at (9.5, 1.5) { $\mathbf{10}$ };
+ \node at (9.5, 1.5) { ${10}$ };
- \draw[-latex,very thick,color=BBCyan] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
- \draw[thick] (B) to node[below] { \bbinfo{1} } (C);
+ \draw[latex-,very thick,color=BBCyan] (B) to node[below] { \bbinfo{1} } (C);
- \node at (5.5, 1.5) { ${7}$ };
+ \node at (5.5, 1.5) { $\mathbf{6}$ };

- \node[anchor=west] at (11, 3) { \bbbold{Round \#3} };
+ \node[anchor=west] at (11, 3) { \bbbold{Round \#4} };
- \node at (5.5, 1.5) { $\mathbf{6}$ };
+ \node at (5.5, 1.5) { ${6}$ };
- \draw[latex-,very thick,color=BBCyan] (B) to node[below] { \bbinfo{1} } (C);
+ \draw[thick] (B) to node[below] { \bbinfo{1} } (C);
- \draw[thick] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
+ \draw[-latex,very thick,color=BBCyan] (B) to node[below,pos=0.8] { \bbinfo{3} } (F);
- \node at (9.5, 1.5) { ${10}$ };
+ \node at (9.5, 1.5) { $\mathbf{9}$ };

## Frame
+ \begin{center}\inputsnippet{cpp}{6}{18}{codes/bellman-ford.cpp}\end{center}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Identificação do caminho mínimo} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{O algoritmo de Bellman-Ford computa as distâncias mínimas, mas não} };
+ \node[anchor=west] at (0.5, 4.5) { \bbtext{os caminhos mínimos} };

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
+ \node[circle, draw, very thick] (B) at (6, 4) { \bbtext{B} };
+ \node[circle, draw, very thick] (C) at (3, 1) { \bbtext{C} };
+ \node[circle, draw, very thick] (D) at (3, 7) { \bbtext{D} };
+ \draw[-latex,thick] (A) to node[above,pos=0.8] { \bbinfo{7} } (B);
+ \draw[-latex,thick] (A) to node[right] { \bbinfo{1} } (C);
+ \draw[-latex,thick] (C) to node[left,pos=0.7] { \bbinfo{2} } (D);
+ \draw[-latex,thick] (D) to node[above] { \bbinfo{3} } (B);

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

- \draw[-latex,thick] (A) to node[above,pos=0.8] { \bbinfo{7} } (B);
+ \draw[-latex,very thick,color=BBCyan] (A) to node[above,pos=0.8] { \bbinfo{7} } (B);
- \node at (10.5, 5.5) { $\infty$ };
+ \node at (10.5, 5.5) { $\mathbf{7}$ };
- \node at (10.5, 2.5) { $\bbtext{-}$ };
+ \node at (10.5, 2.5) { $\bbupdate{A}$ };

- \draw[-latex,very thick,color=BBCyan] (A) to node[above,pos=0.8] { \bbinfo{7} } (B);
+ \draw[-latex,thick] (A) to node[above,pos=0.8] { \bbinfo{7} } (B);
- \node at (10.5, 5.5) { $\mathbf{7}$ };
+ \node at (10.5, 5.5) { $7$ };
- \node at (10.5, 2.5) { $\bbupdate{A}$ };
+ \node at (10.5, 2.5) { $\bbtext{A}$ };
- \draw[-latex,thick] (A) to node[right] { \bbinfo{1} } (C);
+ \draw[-latex,very thick,color=BBCyan] (A) to node[right] { \bbinfo{1} } (C);
- \node at (11.5, 5.5) { $\infty$ };
+ \node at (11.5, 5.5) { $\mathbf{1}$ };
- \node at (11.5, 2.5) { $\bbtext{-}$ };
+ \node at (11.5, 2.5) { $\bbupdate{A}$ };

- \node at (11.5, 5.5) { $\mathbf{1}$ };
+ \node at (11.5, 5.5) { ${1}$ };
- \node at (11.5, 2.5) { $\bbupdate{A}$ };
+ \node at (11.5, 2.5) { $\bbtext{A}$ };
- \draw[-latex,very thick,color=BBCyan] (A) to node[right] { \bbinfo{1} } (C);
+ \draw[-latex,thick] (A) to node[right] { \bbinfo{1} } (C);
- \draw[-latex,thick] (C) to node[left,pos=0.7] { \bbinfo{2} } (D);
+ \draw[-latex,very thick,color=BBCyan] (C) to node[left,pos=0.7] { \bbinfo{2} } (D);
- \node at (12.5, 2.5) { $\bbtext{-}$ };
+ \node at (12.5, 2.5) { $\bbupdate{C}$ };
- \node at (12.5, 5.5) { $\infty$ };
+ \node at (12.5, 5.5) { $\mathbf{3}$ };

- \node at (12.5, 2.5) { $\bbupdate{C}$ };
+ \node at (12.5, 2.5) { $\bbtext{C}$ };
- \node at (12.5, 5.5) { $\mathbf{3}$ };
+ \node at (12.5, 5.5) { ${3}$ };
- \draw[-latex,very thick,color=BBCyan] (C) to node[left,pos=0.7] { \bbinfo{2} } (D);
+ \draw[-latex,thick] (C) to node[left,pos=0.7] { \bbinfo{2} } (D);
- \draw[-latex,thick] (D) to node[above] { \bbinfo{3} } (B);
+ \draw[-latex,very thick,color=BBCyan] (D) to node[above] { \bbinfo{3} } (B);
- \node at (10.5, 5.5) { $7$ };
+ \node at (10.5, 5.5) { $\mathbf{6}$ };
- \node at (10.5, 2.5) { $\bbtext{A}$ };
+ \node at (10.5, 2.5) { $\bbupdate{D}$ };

- \node at (10.5, 2.5) { $\bbupdate{D}$ };
+ \node at (10.5, 2.5) { $\bbtext{D}$ };
- \draw[-latex,very thick,color=BBCyan] (D) to node[above] { \bbinfo{3} } (B);
+ \draw[-latex,thick] (D) to node[above] { \bbinfo{3} } (B);
- \node at (10.5, 5.5) { $\mathbf{6}$ };
+ \node at (10.5, 5.5) { ${6}$ };

+ \draw[latex-,thick,color=BBViolet] (B) to [bend right] node[above right] { \tiny $(\mathrm{prev}(\mbox{\bbtext{B}}), \mbox{\bbtext{B}})$ } (D);

+ \draw[-latex,thick,color=BBViolet] (C) to [bend right] node[right, pos=0.3] { \tiny $(\mathrm{prev}(\mbox{\bbtext{D}}), \mbox{\bbtext{D}})$ } (D);

+ \draw[-latex,thick,color=BBViolet] (A) to [bend right] node[below left, pos=0.8] { \tiny $(\mathrm{prev}(\mbox{\bbtext{C}}), \mbox{\bbtext{C}})$ } (C);

## Frame
+ \begin{center}\inputsnippet{cpp}{9}{25}{codes/bellman-ford-path.cpp}\end{center}

## Frame
+ \begin{center}\inputsnippet{cpp}{27}{40}{codes/bellman-ford-path.cpp}\end{center}

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Caminhos mínimos e ciclos} };

+ \node[anchor=west] at (1, 6) { \bbtext{Seja} };
+ \node[anchor=west] at (2, 5) { $p = \{ (a, u_1), (u_1, u_2), \ldots, (v, u_r), \dots, (u_s, v), \ldots, (u_t, b) \}$ };
+ \node[anchor=west] at (0.5, 4) { \bbtext{um caminho de $a$ a $b$ e $\omega(c)$ o custo do ciclo $c = \{ (v, u_r), \ldots, (u_s, v) \}$, isto é } };
+ \node[anchor=west] at (5, 3) { $\displaystyle{\omega(c) = \sum_{e\in c} w(e)}$ };

+ \draw[-latex,color=BBViolet] (7.3, 2.8) to (7.3, 2.6) to (10, 2.6);
+ \node[anchor=west] at (10, 2.6) { \footnotesize \bbcomment{custo da aresta $e$} };

+ \node[anchor=west] at (0.5, 2) { \bbtext{Se $p$ é caminho mínimo de $a$ a $b$ então $\omega(c) = 0$.} };

## Scene
+ \node[anchor=west] at (0, 6.5) { \Large \bbbold{Caminhos mínimos e ciclos positivos} };

+ \node[anchor=west] at (1, 5.5) { \bbtext{Seja $\omega(c) > 0$ e } };
+ \node[anchor=west] at (2, 4.5) { $q = \{ (a, u_1), (u_1, u_2), \ldots, (u_{r - 1}, v), (v, u_{s + 1}), \ldots, (u_t, b) \},$ };
+ \node[anchor=west] at (0.5, 3.5) { \bbtext{o caminho resultante da exclusão do ciclo $c$ de $p$. Então $\omega(q) < \omega(p)$, pois} };
+ \node[anchor=west] at (2, 2) { $ \omega(p) = \displaystyle{\sum_{e_i\in p} w(e_i) = \sum_{e_j\in q} w(e_j) + \sum_{e_k\in c} w(e_k) = \omega(q) + \omega(c) > \omega(q)} $ };

## Scene
+ \node[circle, draw, very thick] (A) at (0.5, 7) { \bbtext{A} };
+ \node[circle, draw, very thick] (B) at (6.5, 7) { \bbtext{B} };
+ \node[circle, draw, very thick] (C) at (12.5, 7) { \bbtext{C} };
+ \node[circle, draw, very thick] (D) at (9.5, 5) { \bbtext{D} };
+ \node[circle, draw, very thick] (E) at (6.5, 3) { \bbtext{E} };
+ \node[circle, draw, very thick] (F) at (3.5, 5) { \bbtext{F} };
+ \draw[thick] (A) to node[below] { \bbinfo{1} } (B);
+ \draw[thick] (B) to node[below] { \bbinfo{2} } (C);
+ \draw[thick] (B) to node[below] { \bbinfo{3} } (D);
+ \draw[thick] (D) to node[below] { \bbinfo{4} } (E);
+ \draw[thick] (E) to node[below] { \bbinfo{5} } (F);
+ \draw[thick] (F) to node[below] { \bbinfo{-6} } (B);

+ \draw[-latex,color=BBCyan] (1, 2) to (2, 2);
+ \node[anchor=west] at (2, 2) { $p$ };

- \draw[thick] (A) to node[below] { \bbinfo{1} } (B);
+ \draw[-latex,very thick,color=BBCyan] (A) to node[below] { \bbinfo{1} } (B);

- \draw[thick] (B) to node[below] { \bbinfo{3} } (D);
+ \draw[-latex,very thick,color=BBCyan] (B) to node[below] { \bbinfo{3} } (D);

- \draw[thick] (D) to node[below] { \bbinfo{4} } (E);
+ \draw[-latex,very thick,color=BBCyan] (D) to node[below] { \bbinfo{4} } (E);

- \draw[thick] (E) to node[below] { \bbinfo{5} } (F);
+ \draw[-latex,very thick,color=BBCyan] (E) to node[below] { \bbinfo{5} } (F);

- \draw[thick] (F) to node[below] { \bbinfo{-6} } (B);
+ \draw[-latex,very thick,color=BBCyan] (F) to node[below] { \bbinfo{-6} } (B);

- \draw[thick] (B) to node[below] { \bbinfo{2} } (C);
+ \draw[-latex,very thick,color=BBCyan] (B) to node[below] { \bbinfo{2} } (C);

+ \node[anchor=west] at (3, 2) { $\omega(p) = 9$ };

+ \draw[dashed,-latex,color=BBGreen] (1, 1) to (2, 1);
+ \node[anchor=west] at (2, 1) { $q$ };

+ \draw[-latex,very thick,dashed,color=BBGreen] (A) to [bend left] (B);
+ \draw[-latex,very thick,dashed,color=BBGreen] (B) to [bend left] (C);

+ \node[anchor=west] at (3, 1) { $\omega(q) = 3$ };

## Scene
+ \node[anchor=west] at (0, 6.5) { \Large \bbbold{Caminhos mínimos e ciclos negativos} };

+ \node[anchor=west] at (1, 5.5) { \bbtext{Seja $\omega(c) < 0$ e } };
+ \node[anchor=west] at (0.75, 4.5) { $q = \{ (a, u_1), (u_1, u_2), \ldots, (v, u_r), \dots, (u_s, v), (v, u_r), \ldots, (u_s, v), \ldots, (u_t, b) \}$ };
+ \node[anchor=west] at (0.5, 3.5) { \bbtext{o caminho resultante da duplicação do ciclo $c$ de $p$. Então $\omega(q) < \omega(p)$, pois} };
+ \node[anchor=west] at (2, 2) { $ \omega(q) = \displaystyle{\sum_{e_i\in q} w(e_i) = \sum_{e_j\in p} w(e_j) + \sum_{e_k\in c} w(e_k) = \omega(p) + \omega(c) < \omega(p)} $ };

## Scene
+ \node[circle, draw, very thick] (A) at (0.5, 7) { \bbtext{A} };
+ \node[circle, draw, very thick] (B) at (6.5, 7) { \bbtext{B} };
+ \node[circle, draw, very thick] (C) at (12.5, 7) { \bbtext{C} };
+ \node[circle, draw, very thick] (D) at (9.5, 5) { \bbtext{D} };
+ \node[circle, draw, very thick] (E) at (6.5, 3) { \bbtext{E} };
+ \node[circle, draw, very thick] (F) at (3.5, 5) { \bbtext{F} };
+ \draw[thick] (A) to node[below] { \bbinfo{1} } (B);
+ \draw[thick] (B) to node[below] { \bbinfo{2} } (C);
+ \draw[thick] (B) to node[below] { \bbinfo{3} } (D);
+ \draw[thick] (D) to node[below] { \bbinfo{-4} } (E);
+ \draw[thick] (E) to node[below] { \bbinfo{5} } (F);
+ \draw[thick] (F) to node[below] { \bbinfo{-6} } (B);

+ \draw[-latex,color=BBCyan] (1, 2) to (2, 2);
+ \node[anchor=west] at (2, 2) { $p$ };

- \draw[thick] (A) to node[below] { \bbinfo{1} } (B);
+ \draw[-latex,very thick,color=BBCyan] (A) to node[below] { \bbinfo{1} } (B);

- \draw[thick] (B) to node[below] { \bbinfo{3} } (D);
+ \draw[-latex,very thick,color=BBCyan] (B) to node[below] { \bbinfo{3} } (D);

- \draw[thick] (D) to node[below] { \bbinfo{-4} } (E);
+ \draw[-latex,very thick,color=BBCyan] (D) to node[below] { \bbinfo{-4} } (E);

- \draw[thick] (E) to node[below] { \bbinfo{5} } (F);
+ \draw[-latex,very thick,color=BBCyan] (E) to node[below] { \bbinfo{5} } (F);

- \draw[thick] (F) to node[below] { \bbinfo{-6} } (B);
+ \draw[-latex,very thick,color=BBCyan] (F) to node[below] { \bbinfo{-6} } (B);

- \draw[thick] (B) to node[below] { \bbinfo{2} } (C);
+ \draw[-latex,very thick,color=BBCyan] (B) to node[below] { \bbinfo{2} } (C);

+ \node[anchor=west] at (3, 2) { $\omega(p) = 3$ };

- \draw[-latex,very thick,color=BBCyan] (A) to node[below] { \bbinfo{1} } (B);
- \draw[-latex,very thick,color=BBCyan] (B) to node[below] { \bbinfo{3} } (D);
- \draw[-latex,very thick,color=BBCyan] (D) to node[below] { \bbinfo{-4} } (E);
- \draw[-latex,very thick,color=BBCyan] (E) to node[below] { \bbinfo{5} } (F);
- \draw[-latex,very thick,color=BBCyan] (F) to node[below] { \bbinfo{-6} } (B);
- \draw[-latex,very thick,color=BBCyan] (B) to node[below] { \bbinfo{2} } (C);
+ \draw[thick] (A) to node[below] { \bbinfo{1} } (B);
+ \draw[thick] (B) to node[below] { \bbinfo{2} } (C);
+ \draw[thick] (B) to node[below] { \bbinfo{3} } (D);
+ \draw[thick] (D) to node[below] { \bbinfo{-4} } (E);
+ \draw[thick] (E) to node[below] { \bbinfo{5} } (F);
+ \draw[thick] (F) to node[below] { \bbinfo{-6} } (B);
+ \draw[dashed,-latex,color=BBGreen] (1, 1) to (2, 1);
+ \node[anchor=west] at (2, 1) { $q$ };

- \draw[thick] (A) to node[below] { \bbinfo{1} } (B);
+ \draw[dashed,-latex,very thick,color=BBGreen] (A) to node[below] { \bbinfo{1} } (B);

- \draw[thick] (B) to node[below] { \bbinfo{3} } (D);
+ \draw[dashed,-latex,very thick,color=BBGreen] (B) to node[below] { \bbinfo{3} } (D);

- \draw[thick] (D) to node[below] { \bbinfo{-4} } (E);
+ \draw[dashed,-latex,very thick,color=BBGreen] (D) to node[below] { \bbinfo{-4} } (E);

- \draw[thick] (E) to node[below] { \bbinfo{5} } (F);
+ \draw[dashed,-latex,very thick,color=BBGreen] (E) to node[below] { \bbinfo{5} } (F);

- \draw[thick] (F) to node[below] { \bbinfo{-6} } (B);
+ \draw[dashed,-latex,very thick,color=BBGreen] (F) to node[below] { \bbinfo{-6} } (B);

+ \draw[very thick,-latex,color=BBGreen,dashed] (B) to [bend left] (D);

+ \draw[very thick,-latex,color=BBGreen,dashed] (D) to [bend left] (E);

+ \draw[very thick,-latex,color=BBGreen,dashed] (E) to [bend left] (F);

+ \draw[very thick,-latex,color=BBGreen,dashed] (F) to [bend left] (B);

- \draw[thick] (B) to node[below] { \bbinfo{2} } (C);
+ \draw[dashed,-latex,very thick,color=BBGreen] (B) to node[below] { \bbinfo{2} } (C);

+ \node[anchor=west] at (3, 1) { $\omega(q) = 1$ };

## Scene
+ \node[anchor=west] at (0, 6.5) { \Large \bbbold{Número de rodadas do algoritmo de Bellman-Ford} };

+ \node[anchor=west] at (1, 5) { \bbtext{\bbbold{Teorema.} Seja $G(V, E)$ um grafo cujos pesos de suas arestas sejam todos } }; 
+ \node[anchor=west] at (0.5, 4) { \bbtext{não-negativos. Então para qualquer $v\in V$, o caminho mínimo de $s$ a $u$ iden-} };
+ \node[anchor=west] at (0.5, 3) { \bbtext{tificado pelo algoritmo de Bellman-Ford tem, no máximo, $|V| - 1$ arestas. } };

## Scene
+ \node[anchor=west] at (0, 6.5) { \Large \bbbold{Detecção de ciclos negativos} };

+ \node[anchor=west] at (1, 5) { \bbtext{\bbbold{Teorema.} Seja $G(V, E)$ um grafo. Se a $|V|$-ésima rodada do algoritmo de } }; 
+ \node[anchor=west] at (0.5, 4) { \bbtext{Bellman-Ford atualizar o vetor $d$ ao menos uma vez, então $G$ possui pelo menos } };
+ \node[anchor=west] at (0.5, 3) { \bbtext{um ciclo negativo. } };

## Frame
+ \begin{center}\inputsnippet{cpp}{6}{23}{codes/negative-cycle.cpp}\end{center}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Problemas sugeridos} };
+ \node[anchor=west] at (1, 5) { $1.$ \bbtext{AtCoder Beginner Contest 137 -- Problem E: Coin Respawn } };
+ \node[anchor=west] at (1, 4) { $2.$ \bbtext{CSES 1673 -- High Score } };
+ \node[anchor=west] at (1, 3) { $3.$ \bbtext{OJ 423 -- MPI Maelstrom } };
+ \node[anchor=west] at (1, 2) { $4.$ \bbtext{OJ 534 -- Frogger } };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Referências} };
+ \node[anchor=west] at (1, 6) { $1.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.} };
+ \node[anchor=west] at (1, 5) { $2.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 4) { $3.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.} };
+ \node[anchor=west] at (1, 3) { $4.$ \bbbold{Wikipédia}, \bbenglish{Bellman-Ford algorithm.} \bbtext{Acesso em 07/07/2021.} };
+ \node[anchor=west] at (1, 2) { $5.$ \bbbold{Wikipédia}, \bbenglish{L. R. Ford Jr.} \bbtext{Acesso em 07/07/2021.} };
+ \node[anchor=west] at (1, 1) { $6.$ \bbbold{Wikipédia}, \bbenglish{Richard E. Bellman.} \bbtext{Acesso em 07/07/2021.} };

## End
