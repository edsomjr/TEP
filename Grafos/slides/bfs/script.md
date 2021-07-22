## Frame
+ \bbcover{Grafos}{Travessia por largura}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Travessia por largura} \bbenglish{(Breadth-first search)} };

+ \node[anchor=west] at (1, 6) { \bbtext{Seja $s$ o vértice de partida e $u$ o vértice observado no momento. As regras} };
+ \node[anchor=west] at (0.5, 5.5) { \bbtext{abaixo definem a BFS:} };

+ \node[anchor=west] at (2, 4.5) { $1.$ \bbtext{Faça $u = s$}};

+ \node[anchor=west] at (2, 3.5) { $2.$ \bbtext{Visite $u$}};

+ \node[anchor=west] at (2, 2.5) { $3.$ \bbtext{Enfileire todos vizinhos de $u$ não visitados} };

+ \node[anchor=west] at (2, 1.5) { $4.$ \bbtext{Extraia o próximo elemento $p$ da fila e faça $u = p$}};

## Scene
+ \node[circle,draw,very thick,color=BBOrange] (A) at (0, 4) {\bbtext{1}};
+ \node[circle,draw,very thick] (B) at (3, 6) {\bbtext{2}};
+ \node[circle,draw,very thick] (C) at (3, 2) {\bbtext{3}};
+ \node[circle,draw,very thick] (D) at (6, 7) {\bbtext{4}};
+ \node[circle,draw,very thick] (E) at (6, 5) {\bbtext{5}};
+ \node[circle,draw,very thick] (F) at (6, 3) {\bbtext{6}};
+ \node[circle,draw,very thick] (G) at (6, 1) {\bbtext{7}};
+ \node[circle,draw,very thick] (H) at (9, 6) {\bbtext{8}};
+ \node[circle,draw,very thick] (I) at (9, 4) {\bbtext{9}};
+ \node[circle,draw,very thick] (J) at (9, 2) {\bbtext{10}};
+ \node[circle,draw,very thick] (K) at (11, 5) {\bbtext{11}};
+ \node[circle,draw,very thick] (L) at (11, 3) {\bbtext{12}};
+ \node[circle,draw,very thick] (M) at (13, 4) {\bbtext{13}};
+ \draw (A) -- (B);
+ \draw (A) -- (C);
+ \draw (B) -- (D);
+ \draw (B) -- (E);
+ \draw (C) -- (F);
+ \draw (E) -- (F);
+ \draw (E) -- (H);
+ \draw (E) -- (I);
+ \draw (F) -- (G);
+ \draw (F) -- (J);
+ \draw (H) -- (K);
+ \draw (I) -- (J);
+ \draw (K) -- (L);
+ \draw (K) -- (M);
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{1} };

- \node[circle,draw,very thick,color=BBOrange] (A) at (0, 4) {\bbtext{1}};
+ \node[circle,fill,very thick,color=BBCyan] (A) at (0, 4) {\bbtext{1}};
+ \node[circle,draw,very thick] (A) at (0, 4) {\bbtext{1}};
- \node[circle,draw,very thick] (B) at (3, 6) {\bbtext{2}};
+ \node[circle,draw,very thick,color=BBOrange] (B) at (3, 6) {\bbtext{2}};
- \node[circle,draw,very thick] (C) at (3, 2) {\bbtext{3}};
+ \node[circle,draw,very thick,color=BBGreen] (C) at (3, 2) {\bbtext{3}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{1} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{2 3} };
- \draw (A) -- (B);
- \draw (A) -- (C);
+ \draw[-latex,very thick] (A) -- (B);
+ \draw[-latex,very thick] (A) -- (C);

- \node[circle,draw,very thick,color=BBOrange] (B) at (3, 6) {\bbtext{2}};
+ \node[circle,fill,very thick,color=BBCyan] (B) at (3, 6) {\bbtext{2}};
+ \node[circle,draw,very thick] (B) at (3, 6) {\bbtext{2}};
- \draw (B) -- (D);
- \draw (B) -- (E);
+ \draw[-latex,very thick] (B) -- (D);
+ \draw[-latex,very thick] (B) -- (E);
- \node[circle,draw,very thick,color=BBGreen] (C) at (3, 2) {\bbtext{3}};
+ \node[circle,draw,very thick,color=BBOrange] (C) at (3, 2) {\bbtext{3}};
- \node[circle,draw,very thick] (D) at (6, 7) {\bbtext{4}};
- \node[circle,draw,very thick] (E) at (6, 5) {\bbtext{5}};
+ \node[circle,draw,very thick,color=BBGreen] (D) at (6, 7) {\bbtext{4}};
+ \node[circle,draw,very thick,color=BBGreen] (E) at (6, 5) {\bbtext{5}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{2 3} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{3 4 5} };

- \node[circle,draw,very thick,color=BBOrange] (C) at (3, 2) {\bbtext{3}};
+ \node[circle,fill,very thick,color=BBCyan] (C) at (3, 2) {\bbtext{3}};
+ \node[circle,draw,very thick] (C) at (3, 2) {\bbtext{3}};
- \node[circle,draw,very thick,color=BBGreen] (D) at (6, 7) {\bbtext{4}};
+ \node[circle,draw,very thick,color=BBOrange] (D) at (6, 7) {\bbtext{4}};
- \draw (C) -- (F);
+ \draw[-latex,very thick] (C) -- (F);
- \node[circle,draw,very thick] (F) at (6, 3) {\bbtext{6}};
+ \node[circle,draw,very thick,color=BBGreen] (F) at (6, 3) {\bbtext{6}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{3 4 5} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{4 5 6} };

- \node[circle,draw,very thick,color=BBOrange] (D) at (6, 7) {\bbtext{4}};
+ \node[circle,fill,very thick,color=BBCyan] (D) at (6, 7) {\bbtext{4}};
+ \node[circle,draw,very thick] (D) at (6, 7) {\bbtext{4}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{4 5 6} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{5 6} };
- \node[circle,draw,very thick,color=BBGreen] (E) at (6, 5) {\bbtext{5}};
+ \node[circle,draw,very thick,color=BBOrange] (E) at (6, 5) {\bbtext{5}};

- \node[circle,draw,very thick,color=BBOrange] (E) at (6, 5) {\bbtext{5}};
+ \node[circle,fill,very thick,color=BBCyan] (E) at (6, 5) {\bbtext{5}};
+ \node[circle,draw,very thick] (E) at (6, 5) {\bbtext{5}};
- \node[circle,draw,very thick,color=BBGreen] (F) at (6, 3) {\bbtext{6}};
+ \node[circle,draw,very thick,color=BBOrange] (F) at (6, 3) {\bbtext{6}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{5 6} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{6 8 9} };
- \draw (E) -- (H);
- \draw (E) -- (I);
+ \draw[-latex,very thick] (E) -- (H);
+ \draw[-latex,very thick] (E) -- (I);
- \node[circle,draw,very thick] (H) at (9, 6) {\bbtext{8}};
- \node[circle,draw,very thick] (I) at (9, 4) {\bbtext{9}};
+ \node[circle,draw,very thick,color=BBGreen] (H) at (9, 6) {\bbtext{8}};
+ \node[circle,draw,very thick,color=BBGreen] (I) at (9, 4) {\bbtext{9}};

- \node[circle,draw,very thick,color=BBOrange] (F) at (6, 3) {\bbtext{6}};
+ \node[circle,fill,very thick,color=BBCyan] (F) at (6, 3) {\bbtext{6}};
+ \node[circle,draw,very thick] (F) at (6, 3) {\bbtext{6}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{6 8 9} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{8 9 7 10} };
- \node[circle,draw,very thick,color=BBGreen] (H) at (9, 6) {\bbtext{8}};
+ \node[circle,draw,very thick,color=BBOrange] (H) at (9, 6) {\bbtext{8}};
- \draw (F) -- (G);
+ \draw[-latex,very thick] (F) -- (G);
- \draw (F) -- (J);
+ \draw[-latex,very thick] (F) -- (J);
- \node[circle,draw,very thick] (G) at (6, 1) {\bbtext{7}};
- \node[circle,draw,very thick] (J) at (9, 2) {\bbtext{10}};
+ \node[circle,draw,very thick,color=BBGreen] (G) at (6, 1) {\bbtext{7}};
+ \node[circle,draw,very thick,color=BBGreen] (J) at (9, 2) {\bbtext{10}};

- \node[circle,draw,very thick,color=BBOrange] (H) at (9, 6) {\bbtext{8}};
+ \node[circle,fill,very thick,color=BBCyan] (H) at (9, 6) {\bbtext{8}};
+ \node[circle,draw,very thick] (H) at (9, 6) {\bbtext{8}};
- \node[circle,draw,very thick,color=BBGreen] (I) at (9, 4) {\bbtext{9}};
+ \node[circle,draw,very thick,color=BBOrange] (I) at (9, 4) {\bbtext{9}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{8 9 7 10} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{9 7 10 11} };
- \draw (H) -- (K);
+ \draw[-latex,very thick] (H) -- (K);
- \node[circle,draw,very thick] (K) at (11, 5) {\bbtext{11}};
+ \node[circle,draw,very thick,color=BBGreen] (K) at (11, 5) {\bbtext{11}};

- \node[circle,draw,very thick,color=BBOrange] (I) at (9, 4) {\bbtext{9}};
+ \node[circle,fill,very thick,color=BBCyan] (I) at (9, 4) {\bbtext{9}};
+ \node[circle,draw,very thick] (I) at (9, 4) {\bbtext{9}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{9 7 10 11} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{7 10 11} };
- \node[circle,draw,very thick,color=BBGreen] (G) at (6, 1) {\bbtext{7}};
+ \node[circle,draw,very thick,color=BBOrange] (G) at (6, 1) {\bbtext{7}};

- \node[circle,draw,very thick,color=BBOrange] (G) at (6, 1) {\bbtext{7}};
+ \node[circle,fill,very thick,color=BBCyan] (G) at (6, 1) {\bbtext{7}};
+ \node[circle,draw,very thick] (G) at (6, 1) {\bbtext{7}};
- \node[circle,draw,very thick,color=BBGreen] (J) at (9, 2) {\bbtext{10}};
+ \node[circle,draw,very thick,color=BBOrange] (J) at (9, 2) {\bbtext{10}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{7 10 11} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{10 11} };

- \node[circle,draw,very thick,color=BBOrange] (J) at (9, 2) {\bbtext{10}};
+ \node[circle,fill,very thick,color=BBCyan] (J) at (9, 2) {\bbtext{10}};
+ \node[circle,draw,very thick] (J) at (9, 2) {\bbtext{10}};
- \node[circle,draw,very thick,color=BBGreen] (K) at (11, 5) {\bbtext{11}};
+ \node[circle,draw,very thick,color=BBOrange] (K) at (11, 5) {\bbtext{11}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{10 11} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{11} };

- \node[circle,draw,very thick,color=BBOrange] (K) at (11, 5) {\bbtext{11}};
+ \node[circle,fill,very thick,color=BBCyan] (K) at (11, 5) {\bbtext{11}};
+ \node[circle,draw,very thick] (K) at (11, 5) {\bbtext{11}};
- \draw (K) -- (L);
+ \draw[-latex,very thick] (K) -- (L);
- \draw (K) -- (M);
+ \draw[-latex,very thick] (K) -- (M);
- \node[circle,draw,very thick] (L) at (11, 3) {\bbtext{12}};
- \node[circle,draw,very thick] (M) at (13, 4) {\bbtext{13}};
+ \node[circle,draw,very thick,color=BBOrange] (L) at (11, 3) {\bbtext{12}};
+ \node[circle,draw,very thick,color=BBGreen] (M) at (13, 4) {\bbtext{13}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{11} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{12 13} };

- \node[circle,draw,very thick,color=BBOrange] (L) at (11, 3) {\bbtext{12}};
+ \node[circle,fill,very thick,color=BBCyan] (L) at (11, 3) {\bbtext{12}};
+ \node[circle,draw,very thick] (L) at (11, 3) {\bbtext{12}};
- \node[circle,draw,very thick,color=BBGreen] (M) at (13, 4) {\bbtext{13}};
+ \node[circle,draw,very thick,color=BBOrange] (M) at (13, 4) {\bbtext{13}};
- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{12 13} };
+ \node at (1, 0.5) { \bbbold{Fila:} \bbtext{13} };

- \node at (1, 0.5) { \bbbold{Fila:} \bbtext{13} };
- \node[circle,draw,very thick,color=BBOrange] (M) at (13, 4) {\bbtext{13}};
+ \node[circle,fill,very thick,color=BBCyan] (M) at (13, 4) {\bbtext{13}};
+ \node[circle,draw,very thick] (M) at (13, 4) {\bbtext{13}};

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Características da BFS} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{Um subproduto da BFS são as distâncias, em arestas, até $s$}};

+ \node[anchor=west] at (1, 4) { $\star$ \bbtext{A DFS e a BFS visitam os mesmos vértices, em ordem distintas} };

+ \node[anchor=west] at (1, 3) { $\star$ \bbbold{Complexidade:} \bbtext{$O(N + M)$, a mesma da DFS} };

+ \node[anchor=west] at (1, 2) { $\star$ \bbtext{Em matrizes de adjacências, a complexidade é $O(N^2)$} };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Implementação da BFS} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{Mais elaborada do que a da DFS, pois não usa recursão } };

+ \node[anchor=west] at (1, 4) { $\star$ \bbtext{Ela demanda uma fila para a manutenção da ordem de travessia} };

+ \node[anchor=west] at (1, 3) { $\star$ \bbtext{O vetor \texttt{dist[$u$]} armazena a distância de $u$ até $s$, em arestas}};

## Frame
+ \begin{center}\inputcode{cpp}{codes/bfs.cpp}\end{center}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Problemas sugeridos} };
+ \node[anchor=west] at (0.5, 5) { $1.$ \bbtext{AtCoder Beginner Contest 132 -- Problem E: Hopscotch Addict} };
+ \node[anchor=west] at (0.5, 4) { $2.$ \bbtext{Codeforces Beta Round \#3 -- Problem A: Shortest Path of the King} };
+ \node[anchor=west] at (0.5, 3) { $3.$ \bbtext{Codeforces Round \#470 (rated, Div. 2) -- Problem A: Protect Sheep} };
+ \node[anchor=west] at (0.5, 2) { $4.$ \bbtext{OJ 10687 -- Monitoring the Amazon} };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Referências} };
+ \node[anchor=west] at (1, 5) { $1.$ \bbbold{FILIPEK}, \bbtext{Bartlomej}. \bbenglish{C++17 in Detail,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 4) { $2.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.} };
+ \node[anchor=west] at (1, 3) { $3.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 2) { $4.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.} };

## End
