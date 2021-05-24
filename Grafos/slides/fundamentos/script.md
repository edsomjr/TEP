## Frame
+ \bbcover{Grafos}{Fundamentos}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene
+ \node[anchor=west] at (1, 6) { \Large \bbbold{Por que estudar grafos?} };

+ \node[anchor=west] at (2, 5) { $\star$ \bbtext{Os grafos abstraem todas as outras estruturas de dados } };

+ \node[anchor=west] at (2, 4) { $\star$ \bbtext{Grafos modelam muitos problemas reais} };

+ \node[anchor=west] at (2, 3) { $\star$ \bbtext{Travessias em grafos são eficientes e úteis} };

+ \node[anchor=west] at (2, 2) { $\star$ \bbtext{Algoritmos clássicos resolvem problemas recorrentes} };

## Scene
+ \node[anchor=west] at (0.5, 7) { \LARGE \bbbold{Grafo} };

+ \node[draw,circle,very thick] (A) at (2, 4) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (4, 6) { \bbtext{2} };
+ \node[draw,circle,very thick] (C) at (6, 1) { \bbtext{3} };
+ \node[draw,circle,very thick] (D) at (8, 3) { \bbtext{4} };
+ \node[draw,circle,very thick] (E) at (10, 2) { \bbtext{5} };
+ \node[draw,circle,very thick] (F) at (12, 5) { \bbtext{6} };
+ \node[draw,circle,very thick] (G) at (9, 7) { \bbtext{7} };
+ \node[anchor=west] (H) at (10, 7) { \footnotesize \bbcomment{vértice} };
+ \draw[->,color=BBViolet] (H) to (G);

+ \draw[-latex,very thick] (A) to (B);
+ \draw[-latex,very thick] (A) to (D);
+ \draw[-latex,very thick] (A) to (F);
+ \draw[-latex,very thick] (A) to (G);
+ \draw[-latex,very thick] (B) to (D);
+ \draw[-latex,very thick] (B) to (F);
+ \draw[-latex,very thick] (D) to (E);
+ \draw[-latex,very thick] (F) to (G);
+ \draw[-latex,very thick] (G) to (D);
+ \node[anchor=west] (I) at (4, 2) { \footnotesize \bbcomment{aresta} };
+ \draw[->,color=BBViolet] (I) to (5, 3.5);

+ \node[anchor=east] (J) at (2.5, 5.5) { \footnotesize \bbcomment{(1, 2)} };
+ \draw[->,color=BBViolet] (J) to (3, 5);

+ \draw[-latex,very thick] (F) to [bend left] (E);
+ \draw[-latex,very thick] (F) to [bend right] (E);
+ \node[anchor=west] (K) at (11, 1.5) { \footnotesize \bbcomment{multiarestas} };
+ \draw[->,color=BBViolet] (K) to (11, 2.5);
+ \draw[->,color=BBViolet] (K) to (11, 4.35);

+ \draw[-latex,very thick] (A) to [loop left] node {\footnotesize \bbcomment{autoloop}} (A);

+ \node[anchor=east] (L) at (5, 1) { \footnotesize \bbcomment{isolado} };
+ \draw[->,color=BBViolet] (L) to (C);

## Scene
+ \node[anchor=west] at (0.5, 7) { \LARGE \bbbold{Grafo simples} };
+ \node[draw,circle,very thick] (A) at (3, 4) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (3, 1) { \bbtext{2} };
+ \node[draw,circle,very thick] (C) at (7, 6) { \bbtext{3} };
+ \node[draw,circle,very thick] (D) at (11, 4) { \bbtext{4} };
+ \node[draw,circle,very thick] (E) at (11, 1) { \bbtext{5} };
+ \draw[-latex,very thick] (A) to (B);
+ \draw[-latex,very thick] (A) to (C);
+ \draw[-latex,very thick] (B) to (D);
+ \draw[-latex,very thick] (C) to (D);
+ \draw[-latex,very thick] (C) to (E);
+ \draw[-latex,very thick] (E) to (A);

## Scene
+ \node[anchor=west] at (0.5, 7) { \LARGE \bbbold{Multigrafo} };
+ \node[draw,circle,very thick] (A) at (3, 4) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (7, 4) { \bbtext{2} };
+ \node[draw,circle,very thick] (C) at (11, 4) { \bbtext{3} };
+ \draw[-latex,very thick] (A) to [loop left] (A);
+ \draw[-latex,very thick] (A) to (B);
+ \draw[-latex,very thick] (B) to [bend left] (C);
+ \draw[-latex,very thick] (B) to [bend right] (C);

## Scene
+ \node[anchor=west] at (0.5, 7) { \LARGE \bbbold{Grafo completo} };
+ \node[draw,circle,very thick] (A) at (5, 1) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (5, 6) { \bbtext{2} };
+ \node[draw,circle,very thick] (C) at (10, 6) { \bbtext{3} };
+ \node[draw,circle,very thick] (D) at (10, 1) { \bbtext{4} };
+ \draw[very thick] (A) to (B);
+ \draw[very thick] (A) to (C);
+ \draw[very thick] (A) to (D);
+ \draw[very thick] (B) to (C);
+ \draw[very thick] (B) to (D);
+ \draw[very thick] (C) to (D);

## Scene
+ \node[anchor=west] at (0.5, 7) { \LARGE \bbbold{Subgrafo} };
+ \node[draw,circle,very thick] (A) at (7, 3) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (7, 7) { \bbtext{2} };
+ \node[draw,circle,very thick] (C) at (4, 1) { \bbtext{3} };
+ \node[draw,circle,very thick] (D) at (10, 1) { \bbtext{4} };
+ \draw[very thick] (A) to (B);
+ \draw[very thick] (A) to (C);
+ \draw[very thick] (A) to (D);
+ \draw[very thick] (B) to (C);
+ \draw[very thick] (B) to (D);
+ \draw[very thick] (C) to (D);

- \node[draw,circle,very thick] (B) at (7, 7) { \bbtext{2} };
- \node[draw,circle,very thick] (C) at (4, 1) { \bbtext{3} };
- \node[draw,circle,very thick] (D) at (10, 1) { \bbtext{4} };
- \draw[very thick] (B) to (C);
- \draw[very thick] (B) to (D);
- \draw[very thick] (C) to (D);
+ \node[draw,circle,very thick,color=BBOrange] (B) at (7, 7) { \bbtext{2} };
+ \node[draw,circle,very thick,color=BBOrange] (C) at (4, 1) { \bbtext{3} };
+ \node[draw,circle,very thick,color=BBOrange] (D) at (10, 1) { \bbtext{4} };
+ \draw[very thick,color=BBOrange] (B) to (C);
+ \draw[very thick,color=BBOrange] (B) to (D);
+ \draw[very thick,color=BBOrange] (C) to (D);

## Scene
+ \node[anchor=west] at (0.5, 7) { \LARGE \bbbold{Grafo não-direcionado} };
+ \node[draw,circle,very thick] (A) at (3, 3) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (7, 5) { \bbtext{2} };
+ \node[draw,circle,very thick] (C) at (7, 1) { \bbtext{3} };
+ \node[draw,circle,very thick] (D) at (11, 3) { \bbtext{4} };
+ \draw[very thick] (A) to (B);
+ \draw[very thick] (A) to (C);
+ \draw[very thick] (B) to (D);
+ \draw[very thick] (C) to (D);

## Scene
+ \node[anchor=west] at (0.5, 7) { \LARGE \bbbold{Grafo direcionado} };
+ \node[draw,circle,very thick] (A) at (2, 1) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (5, 5) { \bbtext{2} };
+ \node[draw,circle,very thick] (C) at (8, 1) { \bbtext{3} };
+ \node[draw,circle,very thick] (D) at (11, 5) { \bbtext{4} };
+ \draw[-latex,very thick] (A) to (B);
+ \draw[-latex,very thick] (B) to (C);
+ \draw[-latex,very thick] (C) to (D);

## Scene
+ \node[anchor=west] at (0.5, 7) { \LARGE \bbbold{Grafo ponderado} };
+ \node[draw,circle,very thick] (A) at (2, 4) { \bbtext{A} };
+ \node[draw,circle,very thick] (B) at (8, 7) { \bbtext{B} };
+ \node[draw,circle,very thick] (C) at (4, 2) { \bbtext{C} };
+ \node[draw,circle,very thick] (D) at (10, 4) { \bbtext{D} };
+ \node[draw,circle,very thick] (E) at (11, 6) { \bbtext{E} };
+ \node[draw,circle,very thick] (F) at (12, 1) { \bbtext{F} };
+ \draw[very thick] (A) -- node[anchor=south,yshift=0.1cm] { \footnotesize $\bbinfo{2}$ } (B);
+ \draw[very thick] (A) -- node[anchor=north east] { \footnotesize $\bbinfo{-1}$ } (C);
+ \draw[very thick] (A) -- node[anchor=north] { \footnotesize $\bbinfo{7}$ } (F);
+ \draw[very thick] (B) -- node[anchor=west,xshift=0.0cm] { \footnotesize $\bbinfo{12}$ } (D);
+ \draw[very thick] (D) -- node[anchor=east,yshift=0.0cm] { \footnotesize $\bbinfo{0}$ } (E);
+ \draw[very thick] (C) -- node[anchor=south,yshift=0.0cm] { \footnotesize $\bbinfo{8}$ } (D);
+ \draw[very thick] (C) -- node[anchor=north,yshift=0.0cm] { \footnotesize $\bbinfo{-3}$ } (F);
+ \draw[very thick] (E) -- node[anchor=west,yshift=0.0cm] { \footnotesize $\bbinfo{1}$ } (F);

## Scene
+ \node[anchor=west] at (0.5, 7) { \LARGE \bbbold{Grafo esparso} };
+ \node[draw,circle,very thick] (A) at (2, 3) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (5, 1) { \bbtext{2} };
+ \node[draw,circle,very thick] (C) at (5, 5) { \bbtext{3} };
+ \node[draw,circle,very thick] (D) at (8, 1) { \bbtext{4} };
+ \node[draw,circle,very thick] (E) at (8, 5) { \bbtext{5} };
+ \node[draw,circle,very thick] (F) at (11, 3) { \bbtext{6} };
+ \draw[very thick] (A) to (C);
+ \draw[very thick] (A) to (F);
+ \draw[very thick] (B) to (C);
+ \draw[very thick] (B) to (E);
+ \draw[very thick] (C) to (E);

- \node[anchor=west] at (0.5, 7) { \LARGE \bbbold{Grafo esparso} };
+ \node[anchor=west] at (0.5, 7) { \LARGE \bbbold{Grafo denso} };
+ \draw[very thick] (A) to (B);
+ \draw[very thick] (A) to (D);
+ \draw[very thick] (A) to (E);
+ \draw[very thick] (A) to (F);
+ \draw[very thick] (B) to (D);
+ \draw[very thick] (B) to (F);
+ \draw[very thick] (C) to (D);
+ \draw[very thick] (C) to (F);
+ \draw[very thick] (D) to (E);
+ \draw[very thick] (D) to (F);
+ \draw[very thick] (E) to (F);

## Scene
+ \node[anchor=west] at (1, 6) { \Large \bbbold{Graus} };

+ \node[anchor=west] at (2, 5) { $\star$ \bbtext{Grau de entrada $g_i(u)$: \# vértices que chegam em $u$} };

+ \node[anchor=west] at (2, 4) { $\star$ \bbtext{Grau de saída $g_o(u)$: \# vértices que partem de $u$} };

+ \node[anchor=west] at (2, 3) { $\star$ \bbtext{Se $G$ é não-direcionado, então $g_i(u) = g_o(u)$, $\forall u\in V$} };

## Scene
+ \node[draw,circle,very thick] (A) at (1, 4) { \bbtext{A} };
+ \node[draw,circle,very thick] (B) at (3, 7) { \bbtext{B} };
+ \node[draw,circle,very thick] (C) at (2, 2) { \bbtext{C} };
+ \node[draw,circle,very thick] (D) at (5, 4) { \bbtext{D} };
+ \node[draw,circle,very thick] (E) at (7, 6) { \bbtext{E} };
+ \node[draw,circle,very thick] (F) at (8, 1) { \bbtext{F} };
+ \draw[-latex,very thick] (A) to [bend left] (B);
+ \draw[-latex,very thick] (B) to [bend left] (A);
+ \draw[-latex,very thick] (A) to [bend left] (C);
+ \draw[-latex,very thick] (C) to [bend left] (A);
+ \draw[-latex,very thick] (D) to [bend left] (C);
+ \draw[-latex,very thick] (C) to [bend left] (D);
+ \draw[-latex,very thick] (B) to [bend left] (E);
+ \draw[-latex,very thick] (E) to [bend left] (B);
+ \draw[-latex,very thick] (A) -- (D);
+ \draw[-latex,very thick] (A) -- (F);
+ \draw[-latex,very thick] (B) -- (D);
+ \draw[-latex,very thick] (C) to [bend right] (F);
+ \draw[-latex,very thick] (F) -- (D);
+ \draw[-latex,very thick] (E) -- (F);
+ \draw[thick] (11, 1) -- (11, 8);
+ \draw[thick] (10, 7) -- (13, 7);
+ \node at (10.5, 7.5) { $u$ };
+ \node at (11.5, 7.5) { $g_i(u)$ };
+ \node at (12.5, 7.5) { $g_o(u)$ };

+ \node at (10.5, 6.5) { \bbtext{A} };
+ \node at (11.5, 6.5) { \bbinfo{2} };
+ \node at (12.5, 6.5) { \bbinfo{4} };

+ \node at (10.5, 5.5) { \bbtext{B} };
+ \node at (11.5, 5.5) { \bbinfo{2} };
+ \node at (12.5, 5.5) { \bbinfo{3} };

+ \node at (10.5, 4.5) { \bbtext{C} };
+ \node at (11.5, 4.5) { \bbinfo{2} };
+ \node at (12.5, 4.5) { \bbinfo{3} };

+ \node at (10.5, 3.5) { \bbtext{D} };
+ \node at (11.5, 3.5) { \bbinfo{4} };
+ \node at (12.5, 3.5) { \bbinfo{1} };

+ \node at (10.5, 2.5) { \bbtext{E} };
+ \node at (11.5, 2.5) { \bbinfo{1} };
+ \node at (12.5, 2.5) { \bbinfo{2} };

+ \node at (10.5, 1.5) { \bbtext{F} };
+ \node at (11.5, 1.5) { \bbinfo{3} };
+ \node at (12.5, 1.5) { \bbinfo{1} };

## Scene
+ \node[anchor=west] at (1, 6) { \Large \bbbold{Caminhos} };
+ \node[anchor=west] at (2, 5) { \bbtext{Um caminho é uma sequência não-nula de vértices da forma} };
+ \node[anchor=west] at (3, 4) { $ (u, w_1), (w_1, w_2), (w_2, w_3), \ldots, (w_{n-1}, w_n), (w_n, v) $ };
+ \node[anchor=west] at (1, 3) { \bbtext{onde $u$ é o ponto de partida e $v$ o ponto de chegada} };

+ \draw[->,color=BBViolet] (3.9, 4.2) to [bend left] (4.8, 4.2);
+ \draw[->,color=BBViolet] (5.4, 3.7) to [bend right] (6.4, 3.7);
+ \draw[->,color=BBViolet] (6.9, 4.2) to [bend left] (7.5, 4.2);
+ \draw[->,color=BBViolet] (8.0, 3.7) to [bend right] (8.8, 3.7);
+ \draw[->,color=BBViolet] (9.5, 4.2) to [bend left] (10.5, 4.2);

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Grafo conectado} };
+ \node[draw,circle,very thick] (A) at (3, 4) { \bbtext{A} };
+ \node[draw,circle,very thick] (B) at (6, 7) { \bbtext{B} };
+ \node[draw,circle,very thick] (C) at (5, 2) { \bbtext{C} };
+ \node[draw,circle,very thick] (D) at (8, 4) { \bbtext{D} };
+ \node[draw,circle,very thick] (E) at (10, 6) { \bbtext{E} };
+ \node[draw,circle,very thick] (F) at (11, 1) { \bbtext{F} };
+ \draw[very thick] (A) to (B);
+ \draw[very thick] (A) to (C);
+ \draw[very thick] (A) to (D);
+ \draw[very thick] (A) to (F);
+ \draw[very thick] (B) to (D);
+ \draw[very thick] (B) to (E);
+ \draw[very thick] (C) to (D);
+ \draw[very thick] (C) to (F);
+ \draw[very thick] (D) to (F);
+ \draw[very thick] (E) to (F);

- \draw[very thick] (A) to (D);
+ \draw[very thick,color=BBGreen] (A) to (D);
- \draw[very thick] (B) to (D);
+ \draw[very thick,color=BBGreen] (B) to (D);
- \draw[very thick] (B) to (E);
+ \draw[very thick,color=BBGreen] (B) to (E);
- \draw[very thick] (E) to (F);
+ \draw[very thick,color=BBGreen] (E) to (F);

- \draw[very thick] (D) to (F);
+ \draw[very thick,color=BBCyan] (D) to (F);

- \draw[very thick] (A) to (C);
+ \draw[very thick,color=BBOrange] (A) to (C);
- \draw[very thick] (A) to (F);
+ \draw[very thick,color=BBOrange] (A) to (F);
- \draw[very thick] (C) to (F);
+ \draw[very thick,color=BBOrange] (C) to (F);
+ \node at (8, 1) { \footnotesize \bbcomment{ciclo} };
+ \draw[->,color=BBViolet] (8, 1.2) to (8, 1.5);

## Scene

+ \node[anchor=west] at (0, 6) { \Large \bbbold{Referências} };
+ \node[anchor=west] at (1, 5) { $1.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.} };
+ \node[anchor=west] at (1, 4) { $2.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 3) { $3.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.} };

## End
