## Frame
+ \bbcover{Grafos}{Travessia por profundidade}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Definição de travessia } };

+ \node[anchor=west] at (1, 5) { \bbtext{Uma travessia consiste em visitar todos os nós atingíveis a partir de um}};
+ \node[anchor=west] at (0.5, 4) { \bbtext{vértice de partida $s$, em alguma ordem. Cada vértice deve ser visitado}};
+ \node[anchor=west] at (0.5, 3) { \bbtext{exatamente uma vez.}};

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Características da travessias} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{Duas travessias são distintas se as ordens de visitação são diferentes}};

+ \node[anchor=west] at (1, 4) { $\star$ \bbtext{Um grafo conectado com $N$ vértices tem $N!$ travessias distintas} };

+ \node[anchor=west] at (1, 3) { $\star$ \bbbold{Travessias notáveis:} \bbtext{por profundidade e por extensão}};

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Travessia por profundidade} \bbenglish{(Depth-first search)} };

+ \node[anchor=west] at (1, 6) { \bbtext{Seja $s$ o vértice de partida e $u$ o vértice observado no momento. As regras} };
+ \node[anchor=west] at (0.5, 5.5) { \bbtext{abaixo definem a DFS:} };

+ \node[anchor=west] at (2, 4.5) { $1.$ \bbtext{Faça $u = s$}};

+ \node[anchor=west] at (2, 3.5) { $2.$ \bbtext{Visite $u$}};

+ \node[anchor=west] at (2, 2.5) { $3.1$ \bbtext{Se $u$ tive ao menos um vizinho $v$ ainda não visitado, faça $u = v$}};

+ \node[anchor=west] at (2, 1.5) { $3.2$ \bbtext{Caso contrário, volte para o vértice que descobriu $u$}};

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

- \node[circle,draw,very thick,color=BBOrange] (A) at (0, 4) {\bbtext{1}};
- \node[circle,draw,very thick] (B) at (3, 6) {\bbtext{2}};
- \draw (A) -- (B);
+ \node[circle,fill,very thick,color=BBCyan] (A) at (0, 4) {\bbtext{1}};
+ \node[circle,draw,very thick] (A) at (0, 4) {\bbtext{1}};
+ \node[circle,draw,very thick,color=BBOrange] (B) at (3, 6) {\bbtext{2}};
+ \draw[-latex,very thick] (A) -- (B);

- \node[circle,draw,very thick,color=BBOrange] (B) at (3, 6) {\bbtext{2}};
- \node[circle,draw,very thick] (D) at (6, 7) {\bbtext{4}};
- \draw (B) -- (D);
+ \node[circle,fill,very thick,color=BBCyan] (B) at (3, 6) {\bbtext{2}};
+ \node[circle,draw,very thick] (B) at (3, 6) {\bbtext{2}};
+ \node[circle,draw,very thick,color=BBOrange] (D) at (6, 7) {\bbtext{4}};
+ \draw[-latex,very thick] (B) -- (D);

- \node[circle,draw,very thick,color=BBOrange] (D) at (6, 7) {\bbtext{4}};
+ \node[circle,fill,very thick,color=BBCyan] (D) at (6, 7) {\bbtext{4}};
+ \node[circle,draw,very thick] (D) at (6, 7) {\bbtext{4}};
+ \draw[->,color=BBViolet] (D) to [bend right] (B);

- \draw (B) -- (E);
- \node[circle,draw,very thick] (E) at (6, 5) {\bbtext{5}};
+ \node[circle,draw,very thick,color=BBOrange] (E) at (6, 5) {\bbtext{5}};
+ \draw[-latex,very thick] (B) -- (E);

- \node[circle,draw,very thick,color=BBOrange] (E) at (6, 5) {\bbtext{5}};
- \draw (E) -- (F);
- \node[circle,draw,very thick] (F) at (6, 3) {\bbtext{6}};
+ \node[circle,fill,very thick,color=BBCyan] (E) at (6, 5) {\bbtext{5}};
+ \node[circle,draw,very thick] (E) at (6, 5) {\bbtext{5}};
+ \node[circle,draw,very thick,color=BBOrange] (F) at (6, 3) {\bbtext{6}};
+ \draw[-latex,very thick] (E) -- (F);

- \draw (C) -- (F);
- \node[circle,draw,very thick,color=BBOrange] (F) at (6, 3) {\bbtext{6}};
- \node[circle,draw,very thick] (C) at (3, 2) {\bbtext{3}};
+ \node[circle,fill,very thick,color=BBCyan] (F) at (6, 3) {\bbtext{6}};
+ \node[circle,draw,very thick] (F) at (6, 3) {\bbtext{6}};
+ \node[circle,draw,very thick,color=BBOrange] (C) at (3, 2) {\bbtext{3}};
+ \draw[-latex,very thick] (F) -- (C);

- \node[circle,draw,very thick,color=BBOrange] (C) at (3, 2) {\bbtext{3}};
+ \node[circle,fill,very thick,color=BBCyan] (C) at (3, 2) {\bbtext{3}};
+ \node[circle,draw,very thick] (C) at (3, 2) {\bbtext{3}};
+ \draw[->,color=BBViolet] (C) to [bend right] (F);

- \draw (F) -- (G);
+ \draw[-latex,very thick] (F) -- (G);
- \node[circle,draw,very thick] (G) at (6, 1) {\bbtext{7}};
+ \node[circle,draw,very thick,color=BBOrange] (G) at (6, 1) {\bbtext{7}};

- \node[circle,draw,very thick,color=BBOrange] (G) at (6, 1) {\bbtext{7}};
+ \node[circle,fill,very thick,color=BBCyan] (G) at (6, 1) {\bbtext{7}};
+ \node[circle,draw,very thick] (G) at (6, 1) {\bbtext{7}};
+ \draw[->,color=BBViolet] (G) to [bend left] (F);

- \node[circle,draw,very thick] (J) at (9, 2) {\bbtext{10}};
- \draw (F) -- (J);
+ \node[circle,draw,very thick,color=BBOrange] (J) at (9, 2) {\bbtext{10}};
+ \draw[-latex,very thick] (F) -- (J);

- \node[circle,draw,very thick] (I) at (9, 4) {\bbtext{9}};
- \node[circle,draw,very thick,color=BBOrange] (J) at (9, 2) {\bbtext{10}};
- \draw (I) -- (J);
+ \node[circle,draw,very thick,color=BBOrange] (I) at (9, 4) {\bbtext{9}};
+ \node[circle,fill,very thick,color=BBCyan] (J) at (9, 2) {\bbtext{10}};
+ \node[circle,draw,very thick] (J) at (9, 2) {\bbtext{10}};
+ \draw[-latex,very thick] (J) -- (I);

- \node[circle,draw,very thick,color=BBOrange] (I) at (9, 4) {\bbtext{9}};
+ \node[circle,fill,very thick,color=BBCyan] (I) at (9, 4) {\bbtext{9}};
+ \node[circle,draw,very thick] (I) at (9, 4) {\bbtext{9}};
+ \draw[->,color=BBViolet] (I) to [bend left] (J);

+ \draw[->,color=BBViolet] (J) to [bend left] (F);

+ \draw[->,color=BBViolet] (F) to [bend left] (E);

- \draw (E) -- (H);
- \node[circle,draw,very thick] (H) at (9, 6) {\bbtext{8}};
+ \node[circle,draw,very thick,color=BBOrange] (H) at (9, 6) {\bbtext{8}};
+ \draw[-latex,very thick] (E) -- (H);

- \draw (H) -- (K);
- \node[circle,draw,very thick,color=BBOrange] (H) at (9, 6) {\bbtext{8}};
- \node[circle,draw,very thick] (K) at (11, 5) {\bbtext{11}};
+ \node[circle,draw,very thick,color=BBOrange] (K) at (11, 5) {\bbtext{11}};
+ \node[circle,fill,very thick,color=BBCyan] (H) at (9, 6) {\bbtext{8}};
+ \node[circle,draw,very thick] (H) at (9, 6) {\bbtext{8}};
+ \draw[-latex,very thick] (H) -- (K);

- \draw (K) -- (L);
- \node[circle,draw,very thick,color=BBOrange] (K) at (11, 5) {\bbtext{11}};
- \node[circle,draw,very thick] (L) at (11, 3) {\bbtext{12}};
+ \node[circle,draw,very thick,color=BBOrange] (L) at (11, 3) {\bbtext{12}};
+ \node[circle,fill,very thick,color=BBCyan] (K) at (11, 5) {\bbtext{11}};
+ \node[circle,draw,very thick] (K) at (11, 5) {\bbtext{11}};
+ \draw[-latex,very thick] (K) -- (L);

- \node[circle,draw,very thick,color=BBOrange] (L) at (11, 3) {\bbtext{12}};
+ \node[circle,fill,very thick,color=BBCyan] (L) at (11, 3) {\bbtext{12}};
+ \node[circle,draw,very thick] (L) at (11, 3) {\bbtext{12}};
+ \draw[->,color=BBViolet] (L) to [bend left] (K);

- \draw (K) -- (M);
+ \draw[-latex,very thick] (K) -- (M);
- \node[circle,draw,very thick] (M) at (13, 4) {\bbtext{13}};
+ \node[circle,draw,very thick,color=BBOrange] (M) at (13, 4) {\bbtext{13}};

- \node[circle,draw,very thick,color=BBOrange] (M) at (13, 4) {\bbtext{13}};
+ \node[circle,fill,very thick,color=BBCyan] (M) at (13, 4) {\bbtext{13}};
+ \node[circle,draw,very thick] (M) at (13, 4) {\bbtext{13}};
+ \draw[->,color=BBViolet] (M) to [bend right] (K);

+ \draw[->,color=BBViolet] (K) to [bend right] (H);

+ \draw[->,color=BBViolet] (H) to [bend right] (E);

+ \draw[->,color=BBViolet] (E) to [bend left] (B);

+ \draw[->,color=BBViolet] (B) to [bend right] (A);

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Características da DFS} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{Cada nó é visitado uma única vez} };

+ \node[anchor=west] at (1, 4) { $\star$ \bbbold{Complexidade:} \bbtext{$O(N + M)$ em listas de adjacências} };

+ \node[anchor=west] at (1, 3) { $\star$ \bbtext{Em matrizes de adjacência a complexidade é $O(N^2)$ }};

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Implementação da DFS} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{A DFS pode ser implementada por recursão} };

+ \node[anchor=west] at (1, 4) { $\star$ \bbbold{Caso-base:} \bbtext{vértice já visitado} };

+ \node[anchor=west] at (1, 3) { $\star$ \bbbold{Chamada recursiva:} \bbtext{vizinhos de $u$ ainda não visitados} };

## Frame
+ \begin{center}\inputcode{cpp}{codes/dfs.cpp}\end{center}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Problemas sugeridos} };
+ \node[anchor=west] at (0.5, 5) { $1.$ \bbtext{Codeforces Round \#453 (Div. 2) -- Problem B: Coloring a Tree} };
+ \node[anchor=west] at (0.5, 4) { $2.$ \bbtext{Codeforces Round \#503 (by SIS, Div. 2) -- Problem B: Badge} };
+ \node[anchor=west] at (0.5, 3) { $3.$ \bbtext{OJ 10113 -- Exchange Rates} };
+ \node[anchor=west] at (0.5, 2) { $4.$ \bbtext{OJ 12442 -- Forwarding Emails} };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Referências} };
+ \node[anchor=west] at (1, 5) { $1.$ \bbbold{FILIPEK}, \bbtext{Bartlomej}. \bbenglish{C++17 in Detail,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 4) { $2.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.} };
+ \node[anchor=west] at (1, 3) { $3.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 2) { $4.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.} };

## End
