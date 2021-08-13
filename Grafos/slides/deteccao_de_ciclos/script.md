## Frame
+ \bbcover{Grafos}{Detecção de ciclos}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Ciclos} };

+ \node[anchor=west] at (1, 6) { \bbtext{Seja $G$ um grafo não-direcionado. Um \bbbold{ciclo} é um caminho, com três ou} };
+ \node[anchor=west] at (0.5, 5.25) { \bbtext{mais arestas distintas, cujos pontos de partida e de chegada são iguais.} };

+ \node[circle,draw,very thick] (A) at (1, 2) {\bbtext{1}};
+ \node[circle,draw,very thick] (B) at (4, 2) {\bbtext{2}};
+ \node[circle,draw,very thick] (C) at (7, 3) {\bbtext{3}};
+ \node[circle,draw,very thick] (D) at (7, 1) {\bbtext{4}};
+ \node[circle,draw,very thick] (E) at (10, 2) {\bbtext{5}};
+ \node[circle,draw,very thick] (F) at (13, 2) {\bbtext{6}};
+ \draw[-latex,very thick] (A) -- (B);
+ \draw[-latex,very thick,color=BBOrange] (B) -- (C);
+ \draw[-latex,very thick,color=BBOrange] (C) -- (E);
+ \draw[-latex,very thick,color=BBOrange] (E) -- (D);
+ \draw[-latex,very thick,color=BBOrange] (D) -- (B);
+ \draw[-latex,very thick] (E) -- (F);

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Grafos acíclicos} };

+ \node[anchor=west] at (1, 6) { \bbtext{Um grafo é dito \bbbold{acíclico} se não possui ciclos. Árvores são grafos acíclicos.} };

+ \node[circle,draw,very thick] (A) at (7, 5) {\bbtext{1}};
+ \node[circle,draw,very thick] (B) at (5, 3) {\bbtext{2}};
+ \node[circle,draw,very thick] (C) at (9, 3) {\bbtext{3}};
+ \node[circle,draw,very thick] (D) at (4, 1) {\bbtext{4}};
+ \node[circle,draw,very thick] (E) at (6, 1) {\bbtext{5}};
+ \node[circle,draw,very thick] (F) at (9, 1) {\bbtext{6}};
+ \draw[very thick] (A) -- (B);
+ \draw[very thick] (A) -- (C);
+ \draw[very thick] (B) -- (D);
+ \draw[very thick] (B) -- (E);
+ \draw[very thick] (C) -- (F);

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Detecção de ciclos} };

+ \node[anchor=west] at (1, 5) { \bbtext{Considere uma travessia por profundidade. Se, durante a travessia, um dos} };
+ \node[anchor=west] at (0.5, 4.25) { \bbtext{dos vizinhos $v$ de $u$ já foi visitado, e $v$ não é o vértice $p$ que descobriu $u$ na} }; 
+ \node[anchor=west] at (0.5, 3.5) { \bbtext{travessia, então existe um ciclo que começa e termina em $u$ e que passa por $v$. } };

## Scene
+ \node[circle, draw, very thick] (A) at (0, 6) { \bbtext{1} };
+ \node[circle, draw, very thick] (B) at (6, 4) { \bbtext{2} };
+ \node[circle, draw, very thick] (C) at (3, 1) { \bbtext{3} };
+ \node[circle, draw, very thick] (D) at (9, 7) { \bbtext{4} };
+ \node[circle, draw, very thick] (E) at (12, 6) { \bbtext{5} };
+ \node[circle, draw, very thick] (F) at (10, 3) { \bbtext{6} };
+ \draw[thick] (A) to (B);
+ \draw[thick] (B) to (C);
+ \draw[thick] (B) to (D);
+ \draw[thick] (B) to (F);
+ \draw[thick] (D) to (F);
+ \draw[thick] (D) to (E);

- \node[circle, draw, very thick] (A) at (0, 6) { \bbtext{1} };
+ \node[circle, fill, color=BBCyan] (A) at (0, 6) { \bbtext{1} };
+ \node[circle, draw, very thick] (A) at (0, 6) { \bbtext{1} };

- \draw[thick] (A) to (B);
+ \draw[-latex,very thick] (A) to (B);
- \node[circle, draw, very thick] (B) at (6, 4) { \bbtext{2} };
+ \node[circle, fill, color=BBCyan] (B) at (6, 4) { \bbtext{2} };
+ \node[circle, draw, very thick] (B) at (6, 4) { \bbtext{2} };

- \node[circle, draw, very thick] (C) at (3, 1) { \bbtext{3} };
+ \node[circle, fill, color=BBCyan] (C) at (3, 1) { \bbtext{3} };
+ \node[circle, draw, very thick] (C) at (3, 1) { \bbtext{3} };
- \draw[thick] (B) to (C);
+ \draw[-latex,very thick] (B) to (C);

- \node[circle, draw, very thick] (D) at (9, 7) { \bbtext{4} };
+ \node[circle, fill, color=BBCyan] (D) at (9, 7) { \bbtext{4} };
+ \node[circle, draw, very thick] (D) at (9, 7) { \bbtext{4} };
- \draw[thick] (B) to (D);
+ \draw[-latex,very thick] (B) to (D);

- \node[circle, draw, very thick] (E) at (12, 6) { \bbtext{5} };
+ \node[circle, fill, color=BBCyan] (E) at (12, 6) { \bbtext{5} };
+ \node[circle, draw, very thick] (E) at (12, 6) { \bbtext{5} };
- \draw[thick] (D) to (E);
+ \draw[-latex,very thick] (D) to (E);

- \node[circle, draw, very thick] (F) at (10, 3) { \bbtext{6} };
+ \node[circle, fill, color=BBCyan] (F) at (10, 3) { \bbtext{6} };
+ \node[circle, draw, very thick] (F) at (10, 3) { \bbtext{6} };
- \draw[thick] (D) to (F);
+ \draw[-latex,very thick] (D) to (F);

- \draw[thick] (B) to (F);
+ \draw[-latex,very thick,color=BBOrange] (F) to (B);
- \draw[-latex,very thick] (B) to (D);
+ \draw[-latex,very thick,color=BBOrange] (B) to (D);
- \draw[-latex,very thick] (D) to (F);
+ \draw[-latex,very thick,color=BBOrange] (D) to (F);

## Frame
+ \begin{center}\inputsnippet{cpp}{11}{28}{codes/cycle.cpp}\end{center}

## Frame
+ \begin{center}\inputsnippet{cpp}{30}{39}{codes/cycle.cpp}\end{center}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Grafos não-direcionados e ciclos} };

+ \node[anchor=west] at (1, 5) { \bbtext{Se $G$ é um grafo simples não-direcionado com $V$ vértices e $E$ arestas, } };
+ \node[anchor=west] at (0.5, 4.25) { \bbtext{então $G$ tem ao menos um ciclo se $E \geq V$.} };

## Frame
+ \begin{center}\inputsnippet{cpp}{11}{22}{codes/cycle_connected.cpp}\end{center}

## Frame
+ \begin{center}\inputsnippet{cpp}{24}{44}{codes/cycle_connected.cpp}\end{center}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Problemas sugeridos} };
+ \node[anchor=west] at (0.5, 5) { $1.$ \bbtext{AtCoder Beginner Contest 167 -- Problem D: Teleporter } };
+ \node[anchor=west] at (0.5, 4) { $2.$ \bbtext{AtCoder Beginner Contest 174 -- Problem C: Repsept} };
+ \node[anchor=west] at (0.5, 3) { $3.$ \bbtext{Educational Codeforces Round 36 -- Problem D: Almost Acyclic Graph} };
+ \node[anchor=west] at (0.5, 2) { $4.$ \bbtext{OJ 10116 -- Robot Motion} };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Referências} };
+ \node[anchor=west] at (1, 5) { $1.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.} };
+ \node[anchor=west] at (1, 4) { $2.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 3) { $3.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.} };

## End
