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

+ \draw[-latex,thick,color=BBViolet] (A) to [bend right] node[below left, pos=0.3] { \tiny $(\mathrm{prev}(\mbox{\bbtext{C}}), \mbox{\bbtext{C}})$ } (C);

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
+ \node[anchor=west] at (0, 6.5) { \Large \bbbold{Caminhos mínimos e ciclos negativos} };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Problemas sugeridos} };
+ \node[anchor=west] at (1, 5) { $1.$ \bbtext{AtCoder Beginner Contest 088 -- Problem D: Repainting } };
+ \node[anchor=west] at (1, 4) { $2.$ \bbtext{Codeforces Beta Round \#3 -- Problem A: Shortest path of the king } };
+ \node[anchor=west] at (1, 3) { $3.$ \bbtext{OJ 10000 -- Longest Paths } };
+ \node[anchor=west] at (1, 2) { $4.$ \bbtext{OJ 10959 -- The Party, Part I } };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Referências} };
+ \node[anchor=west] at (1, 6) { $1.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.} };
+ \node[anchor=west] at (1, 5) { $2.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 4) { $3.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.} };
+ \node[anchor=west] at (1, 3) { $4.$ \bbbold{Wikipédia}, \bbenglish{Bellman-Ford algorithm.} \bbtext{Acesso em 07/07/2021.} };
+ \node[anchor=west] at (1, 2) { $5.$ \bbbold{Wikipédia}, \bbenglish{L. R. Ford Jr.} \bbtext{Acesso em 07/07/2021.} };
+ \node[anchor=west] at (1, 1) { $6.$ \bbbold{Wikipédia}, \bbenglish{Richard E. Bellman.} \bbtext{Acesso em 07/07/2021.} };

## End
