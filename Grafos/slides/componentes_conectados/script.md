## Frame
+ \bbcover{Grafos}{Componentes Conectados}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Grafos conectados} };

+ \node[anchor=west] at (1, 5) { \bbtext{Um grafo não-direcionado $G(V, E)$ é dito \bbbold{conectado} se, para qualquer} };
+ \node[anchor=west] at (0.5, 4.25) { \bbtext{par de vértices $u, v\in V$, existe ao menos um caminho de $u$ a $v$.} };

## Scene
+ \node[anchor=west] at (0, 7.5) { \Large \bbbold{Grafo conectado} };
+ \node[circle,draw,very thick] (A) at (0, 4) {\bbtext{1}};
+ \node[circle,draw,very thick] (B) at (3, 6) {\bbtext{2}};
+ \node[circle,draw,very thick] (C) at (2, 1) {\bbtext{3}};
+ \node[circle,draw,very thick] (D) at (6, 5) {\bbtext{4}};
+ \node[circle,draw,very thick] (E) at (7, 2) {\bbtext{5}};
+ \node[circle,draw,very thick] (F) at (9, 3) {\bbtext{6}};
+ \node[circle,draw,very thick] (G) at (10, 7) {\bbtext{7}};
+ \node[circle,draw,very thick] (H) at (9, 1) {\bbtext{8}};
+ \node[circle,draw,very thick] (I) at (13, 5) {\bbtext{9}};
+ \node[circle,draw,very thick] (J) at (12, 2) {\bbtext{10}};
+ \draw[very thick] (A) -- (B);
+ \draw[very thick] (A) -- (C);
+ \draw[very thick] (A) -- (D);
+ \draw[,very thick] (A) -- (F);
+ \draw[very thick] (B) -- (G);
+ \draw[very thick] (C) -- (G);
+ \draw[very thick] (D) -- (I);
+ \draw[very thick] (D) -- (J);
+ \draw[very thick] (E) -- (F);
+ \draw[very thick] (E) -- (G);
+ \draw[very thick] (E) -- (J);
+ \draw[very thick] (F) -- (H);
+ \draw[very thick] (F) -- (I);
+ \draw[very thick] (G) -- (J);
+ \draw[very thick] (H) -- (J);
+ \draw[very thick] (I) -- (J);

## Scene
+ \node[anchor=west] at (0, 7.5) { \Large \bbbold{Grafo não-conectado} };
+ \node[circle,draw,very thick] (A) at (3, 6) {\bbtext{1}};
+ \node[circle,draw,very thick] (B) at (3, 2) {\bbtext{2}};
+ \node[circle,draw,very thick] (C) at (9, 4) {\bbtext{3}};
+ \node[circle,draw,very thick] (D) at (6, 4) {\bbtext{4}};
+ \node[circle,draw,very thick] (E) at (12, 2) {\bbtext{5}};
+ \node[circle,draw,very thick] (F) at (12, 6) {\bbtext{6}};
+ \draw[very thick] (A) -- (B);
+ \draw[very thick] (A) -- (C);
+ \draw[very thick] (B) -- (C);
+ \draw[very thick] (D) -- (E);
+ \draw[very thick] (D) -- (F);
+ \draw[very thick] (E) -- (F);

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Componente conectado} };

+ \node[anchor=west] at (1, 5) { \bbtext{O componente conectado do grafo $G(V,E)$ que contém o vértice $u$ é o maior} };
+ \node[anchor=west] at (0.5, 4.25) { \bbtext{subgrafo conectado $S(V', E')$ de $G$ tal que $u\in V'$. Os elementos de $V'$ podem} };
+ \node[anchor=west] at (0.5, 3.5) { \bbtext{ ser determinados por meio de uma travessia com início em $u$. } };

## Scene
+ \node[circle, draw, very thick] (A) at (0, 3) { \bbtext{1} };
+ \node[circle, draw, very thick] (B) at (2, 7) { \bbtext{2} };
+ \node[circle, draw, very thick] (C) at (2, 1) { \bbtext{3} };
+ \node[circle, draw, very thick] (D) at (4, 3) { \bbtext{4} };
+ \node[circle, draw, very thick] (E) at (6, 5.5) { \bbtext{5} };
+ \node[circle, draw, very thick] (F) at (6, 2) { \bbtext{6} };
+ \node[circle, draw, very thick] (G) at (11, 1) { \bbtext{7} };
+ \node[circle, draw, very thick] (H) at (9, 5) { \bbtext{8} };
+ \node[circle, draw, very thick] (I) at (8, 4) { \bbtext{9} };
+ \node[circle, draw, very thick] (J) at (12, 5) { \bbtext{10} };
+ \draw[thick] (A) to (B);
+ \draw[thick] (A) to (H);
+ \draw[thick] (B) to (J);
+ \draw[thick] (D) to (E);
+ \draw[thick] (D) to (I);
+ \draw[thick] (E) to (I);
+ \draw[thick] (C) to (G);

- \node[circle, draw, very thick] (A) at (0, 3) { \bbtext{1} };
+ \node[circle, fill, color=BBCyan] (A) at (0, 3) { \bbtext{1} };
+ \node[circle, draw, very thick] (A) at (0, 3) { \bbtext{1} };

- \node[circle, draw, very thick] (B) at (2, 7) { \bbtext{2} };
+ \node[circle, fill, color=BBCyan] (B) at (2, 7) { \bbtext{2} };
+ \node[circle, draw, very thick] (B) at (2, 7) { \bbtext{2} };
- \draw[thick] (A) to (B);
+ \draw[-latex,very thick] (A) to (B);

- \node[circle, draw, very thick] (J) at (12, 5) { \bbtext{10} };
+ \node[circle, fill, color=BBCyan] (J) at (12, 5) { \bbtext{10} };
+ \node[circle, draw, very thick] (J) at (12, 5) { \bbtext{10} };
- \draw[thick] (B) to (J);
+ \draw[-latex, very thick] (B) to (J);

- \node[circle, draw, very thick] (H) at (9, 5) { \bbtext{8} };
+ \node[circle, fill, color=BBCyan] (H) at (9, 5) { \bbtext{8} };
+ \node[circle, draw, very thick] (H) at (9, 5) { \bbtext{8} };
- \draw[thick] (A) to (H);
+ \draw[-latex,very thick] (A) to (H);

- \node[circle, draw, very thick] (D) at (4, 3) { \bbtext{4} };
+ \node[circle, fill, color=BBOrange] (D) at (4, 3) { \bbtext{4} };
+ \node[circle, draw, very thick] (D) at (4, 3) { \bbtext{4} };

- \node[circle, draw, very thick] (E) at (6, 5.5) { \bbtext{5} };
+ \node[circle, fill, color=BBOrange] (E) at (6, 5.5) { \bbtext{5} };
+ \node[circle, draw, very thick] (E) at (6, 5.5) { \bbtext{5} };
- \draw[thick] (D) to (E);
+ \draw[-latex,very thick] (D) to (E);

- \node[circle, draw, very thick] (I) at (8, 4) { \bbtext{9} };
+ \node[circle, fill, color=BBOrange] (I) at (8, 4) { \bbtext{9} };
+ \node[circle, draw, very thick] (I) at (8, 4) { \bbtext{9} };
- \draw[thick] (E) to (I);
+ \draw[-latex,very thick] (E) to (I);

- \node[circle, draw, very thick] (F) at (6, 2) { \bbtext{6} };
+ \node[circle, fill, color=BBGreen] (F) at (6, 2) { \bbtext{6} };
+ \node[circle, draw, very thick] (F) at (6, 2) { \bbtext{6} };

- \node[circle, draw, very thick] (C) at (2, 1) { \bbtext{3} };
+ \node[circle, fill, color=BBRed] (C) at (2, 1) { \bbtext{3} };
+ \node[circle, draw, very thick] (C) at (2, 1) { \bbtext{3} };

- \node[circle, draw, very thick] (G) at (11, 1) { \bbtext{7} };
+ \node[circle, fill, color=BBRed] (G) at (11, 1) { \bbtext{7} };
+ \node[circle, draw, very thick] (G) at (11, 1) { \bbtext{7} };
- \draw[thick] (C) to (G);
+ \draw[-latex,very thick] (C) to (G);

## Frame
+ \begin{center}\inputsnippet{cpp}{23}{40}{codes/cc.cpp}\end{center}

## Frame
+ \begin{center}\inputsnippet{cpp}{10}{21}{codes/cc.cpp}\end{center}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Grafos conectados e componentes conectados} };

+ \node[anchor=west] at (1, 5) { \bbtext{Um grafo não-direcionado $G$ é conectado se, e somente se, $G$ tem um} };
+ \node[anchor=west] at (0.5, 4.25) { \bbtext{único componente conectado.} };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Problemas sugeridos} };
+ \node[anchor=west] at (0.5, 5) { $1.$ \bbtext{AtCoder Beginner Contest 049 -- Problem D: Connectivity } };
+ \node[anchor=west] at (0.5, 4) { $2.$ \bbtext{Educational Codeforces Round 5 - Problem C: The Labyrinth} };
+ \node[anchor=west] at (0.5, 3) { $3.$ \bbtext{Educational Codeforces Round 33 (Rated for Div. 2) -- Problem C: Rumor} };
+ \node[anchor=west] at (0.5, 2) { $4.$ \bbtext{OJ 11094 -- Continents} };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Referências} };
+ \node[anchor=west] at (1, 5) { $1.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.} };
+ \node[anchor=west] at (1, 4) { $2.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 3) { $3.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.} };

## End
