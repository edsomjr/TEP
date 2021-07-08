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

+ \node[anchor=west] at (1, 3.5) { $2.$ \bbtext{Para cada aresta $(u, v, w)\in E$, se $d[u] + w < d[v]$, faça $d[v] = d[u] + w$} };

+ \node[anchor=west] at (1, 2.5) { $3.$ \bbtext{Se o vetor $d$ foi atualizado ao menos uma vez, volte ao passo $2.$ } };

+ \node[anchor=west] at (1, 1.5) { $4.$ \bbtext{Retorne $d$ } };

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

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{O algoritmo de Bellman-Forde computa as distâncias mínimas, mas não} };
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
 
## End
