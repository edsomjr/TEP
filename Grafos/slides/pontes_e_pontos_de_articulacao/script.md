## Frame
+ \bbcover{Grafos}{Pontes e Pontos de Articulação}{Prof. Edson Alves}{Faculdade UnB Gama}

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Pontes} };

+ \node[anchor=west] at (1, 6) { \bbtext{Seja $G(V, E)$ um grafo não-direcionado conectado. Uma aresta $e\in E$ é uma } };
+ \node[anchor=west] at (0.5, 5) { \bbtext{\bbbold{ponte} se a exclusão de $e$ torna o grafo $G$ desconectado.} };

+ \node[circle, draw, very thick] (A) at (4, 3) { \bbtext{1} };
+ \node[circle, draw, very thick] (B) at (4, 1) { \bbtext{2} };
+ \node[circle, draw, very thick] (C) at (6, 2) { \bbtext{3} };
+ \node[circle, draw, very thick] (D) at (8, 2) { \bbtext{4} };
+ \node[circle, draw, very thick] (E) at (10, 3) { \bbtext{5} };
+ \node[circle, draw, very thick] (F) at (10, 1) { \bbtext{6} };
+ \draw[very thick] (A) to (B);
+ \draw[very thick] (A) to (C);
+ \draw[very thick] (B) to (C);
+ \draw[very thick] (D) to (C);
+ \draw[very thick] (D) to (E);
+ \draw[very thick] (D) to (F);
+ \draw[very thick] (E) to (F);

+ \draw[-latex,color=BBViolet] (7, 2.8) to (7, 2.1);
+ \node at (7,3) { \footnotesize \bbcomment{ponte} };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Árvore gerada pela DFS} };

+ \node[anchor=west] at (1, 6) { $\star$ \bbtext{Uma DFS num grafo $G$ gera uma árvore} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{Os vértices são os mesmos de $G$ } };

+ \node[anchor=west] at (1, 4) { $\star$ \bbtext{As arestas dependem da ordem de descoberta dos vértices} };

+ \node[anchor=west] at (1, 3) { $\star$ \bbtext{Esta ordem também determina uma permutação dos vértices} };

+ \node[anchor=west] at (1, 2) { $\star$ \bbtext{O índice de cada vértice nesta permutação tem importantes propriedades} };

## Scene
+ \node[anchor=west] at (0, 7.5) { \bbbold{Grafo} };
+ \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
+ \draw[thick] (A) to (B);
+ \draw[thick] (A) to (C);
+ \draw[thick] (B) to (C);
+ \draw[thick] (D) to (C);
+ \draw[thick] (D) to (E);
+ \draw[thick] (D) to (F);
+ \draw[thick] (E) to (F);

+ \node[anchor=west] at (6, 7.5) { \bbbold{Árvore gerada pelo DFS} };

- \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, fill, color=BBCyan] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };

+ \node[circle, draw, very thick] (D1) at (9, 6.5) { \bbtext{4}$^1$ };

- \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, fill, color=BBCyan] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
- \draw[thick] (D) to (C);
+ \draw[-latex,very thick] (D) to (C);

+ \node[circle, draw, very thick] (C1) at (7, 4.5) { \bbtext{3}$^2$ };
+ \draw[-latex,very thick] (D1) to (C1);

- \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, fill, color=BBCyan] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
- \draw[thick] (A) to (C);
+ \draw[-latex,very thick] (C) to (A);

+ \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3$ };
+ \draw[-latex,very thick] (C1) to (A1);

- \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, fill, color=BBCyan] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
- \draw[thick] (A) to (B);
+ \draw[-latex,very thick] (A) to (B);

+ \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4$ };
+ \draw[-latex,very thick] (A1) to (B1);

- \draw[thick] (B) to (C);
+ \draw[-latex,dashed,thick] (B) to (C);

\draw[-latex,thick,dashed,color=BBViolet] (B1) to (C1);
- \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, fill, color=BBCyan] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
- \draw[thick] (D) to (E);
+ \draw[-latex,very thick] (D) to (E);

+ \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5$ };
+ \draw[-latex,very thick] (D1) to (E1);

- \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
+ \node[circle, fill, color=BBCyan] (F) at (4, 0.5) { \bbtext{6} };
+ \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
- \draw[thick] (E) to (F);
+ \draw[-latex,very thick] (E) to (F);

+ \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6$ };
+ \draw[-latex,very thick] (E1) to (F1);

- \draw[thick] (D) to (F);
+ \draw[latex-,dashed,thick] (D) to (F);

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Propriedades dos índices da permutação} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{Seja $i_s(u)$ o índice do vértice $u$ na permutação gerada pela DFS que tem } };
+ \node[anchor=west] at (0.5, 4.5) { \bbtext{$s$ como vértice inicial} };

+ \node[anchor=west] at (1, 3.5) { $\star$ \bbtext{Se $i_s(u) < i_s(v)$ então ou $u$ é ancestral de $v$ ou $u$ está em uma subárvore } };
+ \node[anchor=west] at (0.5, 3.0) { \bbtext{de $s$ da subárvore que contém $v$ } };

+ \node[anchor=west] at (1, 2) { $\star$ \bbtext{Se $(u, v)\in E$ e $i_s(v) < i_s(u)$, então $(u, v)$ é uma aresta \bbbold{reversa} } };

## Scene
+ \node[anchor=west] at (0, 7.5) { \bbbold{Grafo} };
+ \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
+ \draw[thick] (A) to (B);
+ \draw[thick] (A) to (C);
+ \draw[thick] (B) to (C);
+ \draw[thick] (D) to (C);
+ \draw[thick] (D) to (E);
+ \draw[thick] (D) to (F);
+ \draw[thick] (E) to (F);
+ \node[anchor=west] at (6, 7.5) { \bbbold{Árvore gerada pelo DFS} };
- \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, fill, color=BBCyan] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, draw, very thick] (D1) at (9, 6.5) { \bbtext{4}$^1$ };
- \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, fill, color=BBCyan] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
- \draw[thick] (D) to (C);
+ \draw[-latex,very thick] (D) to (C);
+ \node[circle, draw, very thick] (C1) at (7, 4.5) { \bbtext{3}$^2$ };
+ \draw[-latex,very thick] (D1) to (C1);
- \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, fill, color=BBCyan] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
- \draw[thick] (A) to (C);
+ \draw[-latex,very thick] (C) to (A);
+ \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3$ };
+ \draw[-latex,very thick] (C1) to (A1);
- \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, fill, color=BBCyan] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
- \draw[thick] (A) to (B);
+ \draw[-latex,very thick] (A) to (B);
+ \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4$ };
+ \draw[-latex,very thick] (A1) to (B1);
- \draw[thick] (B) to (C);
+ \draw[-latex,dashed,thick] (B) to (C);
+ \draw[-latex,thick,dashed,color=BBViolet] (B1) to (C1);
+ \draw[-latex,thick,dashed,color=BBViolet] (F1) to [bend left] (D1);
- \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, fill, color=BBCyan] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
- \draw[thick] (D) to (E);
+ \draw[-latex,very thick] (D) to (E);
+ \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5$ };
+ \draw[-latex,very thick] (D1) to (E1);
- \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
+ \node[circle, fill, color=BBCyan] (F) at (4, 0.5) { \bbtext{6} };
+ \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
- \draw[thick] (E) to (F);
+ \draw[-latex,very thick] (E) to (F);
+ \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6$ };
+ \draw[-latex,very thick] (E1) to (F1);
- \draw[thick] (D) to (F);
+ \draw[latex-,dashed,thick] (D) to (F);
+ \node[anchor=east] at (6.8, 2.5) { \footnotesize \bbcomment{aresta reversa} };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Menor ancestral alcançável} };

+ \node[anchor=west] at (1, 6) { $\star$ \bbtext{Seja $\mu_s(u)$ o menor índice dentre todos os vértices atingíveis a partir da} };
+ \node[anchor=west] at (0.5, 5.5) { \bbtext{subárvore (ou subgrafo) cuja raiz é $u$ } };

+ \node[anchor=west] at (1, 4.5) { $\star$ \bbtext{A DFS a partir de $u$ gera uma subárvore se não houverem arestas reversas } };

+ \node[anchor=west] at (1, 3.5) { $\star$ \bbtext{Neste caso, $i_s(w) = \mu_s(w)$ para todo vértice $w$ nesta subárvore } };

+ \node[anchor=west] at (1, 2.5) { $\star$ \bbtext{As arestas reversas impactam nos valores de $\mu_s(u)$ } };

+ \node[anchor=west] at (1, 1.5) { $\star$ \bbtext{Se $(u, v)$ é aresta reversa, então $\mu_s(u) = \min\{ \mu_s(u), i_s(v) \}$ } };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Identificação de pontes} };

+ \node[anchor=west] at (1, 5) { \bbtext{Seja $G(V, E)$ um grafo conectado e $s\in V$ o vértice de partida de uma DFS. } };
+ \node[anchor=west] at (0.5, 4) { \bbtext{A aresta $(u, v)\in E$ é uma ponte se $\mu_s(v) > i_s(u)$. } }; 

+ \node[anchor=west] at (1, 2) { \bbbold{Definição}: \bbtext{Se $G$ não pontes ele é denominado \bbbold{biconectado.} } };

## Scene
+ \node[anchor=west] at (0, 7.5) { \bbbold{Grafo} };
+ \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
+ \draw[thick] (A) to (B);
+ \draw[thick] (A) to (C);
+ \draw[thick] (B) to (C);
+ \draw[thick] (D) to (C);
+ \draw[thick] (D) to (E);
+ \draw[thick] (D) to (F);
+ \draw[thick] (E) to (F);

+ \node[anchor=west] at (6, 7.5) { \bbbold{Árvore gerada pelo DFS} };

- \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, fill, color=BBCyan] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };

+ \node[circle, draw, very thick] (D1) at (9, 6.5) { \bbtext{4}$^1_{\textcolor{BBRed}{1}}$ };

- \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, fill, color=BBCyan] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
- \draw[thick] (D) to (C);
+ \draw[-latex,very thick] (D) to (C);

+ \node[circle, draw, very thick] (C1) at (7, 4.5) { \bbtext{3}$^2_{\textcolor{BBRed}{2}}$ };
+ \draw[-latex,very thick] (D1) to (C1);

- \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, fill, color=BBCyan] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
- \draw[thick] (A) to (C);
+ \draw[-latex,very thick] (C) to (A);

+ \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3_{\textcolor{BBRed}{3}}$ };
+ \draw[-latex,very thick] (C1) to (A1);

- \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, fill, color=BBCyan] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
- \draw[thick] (A) to (B);
+ \draw[-latex,very thick] (A) to (B);

+ \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4_{\textcolor{BBRed}{4}}$ };
+ \draw[-latex,very thick] (A1) to (B1);

- \draw[thick] (B) to (C);
+ \draw[-latex,dashed,thick] (B) to (C);

+ \draw[-latex,thick,dashed,color=BBViolet] (B1) to (C1);
- \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4_{\textcolor{BBRed}{4}}$ };
+ \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4_{\textcolor{BBViolet}{2}}$ };

+ \draw[-latex,dashed,thick,color=BBGreen] (B) to [bend right] (A);
- \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4_{\textcolor{BBViolet}{2}}$ };
+ \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4_{\textcolor{BBRed}{2}}$ };
- \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3_{\textcolor{BBRed}{3}}$ };
+ \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3_{\textcolor{BBViolet}{2}}$ };

+ \draw[-latex,dashed,thick,color=BBGreen] (A) to [bend right] (C);
- \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3_{\textcolor{BBViolet}{2}}$ };
+ \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3_{\textcolor{BBRed}{2}}$ };

+ \draw[-latex,dashed,thick,color=BBGreen] (C) to [bend left] (D);

+ \draw[-latex,color=BBViolet] (2.1, 3.5) to (2.9, 3.5);
+ \node[anchor=east] at (2, 3.5) { \bbcomment{ponte} };

- \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, fill, color=BBCyan] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
- \draw[thick] (D) to (E);
+ \draw[-latex,very thick] (D) to (E);

+ \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5_{\textcolor{BBRed}{5}}$ };
+ \draw[-latex,very thick] (D1) to (E1);

- \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
+ \node[circle, fill, color=BBCyan] (F) at (4, 0.5) { \bbtext{6} };
+ \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
- \draw[thick] (E) to (F);
+ \draw[-latex,very thick] (E) to (F);

+ \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6_{\textcolor{BBRed}{6}}$ };
+ \draw[-latex,very thick] (E1) to (F1);

- \draw[thick] (D) to (F);
+ \draw[latex-,dashed,thick] (D) to (F);

+ \draw[-latex,thick,dashed,color=BBViolet] (F1) to [bend left] (D1);
- \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6_{\textcolor{BBRed}{6}}$ };
+ \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6_{\textcolor{BBViolet}{1}}$ };

+ \draw[-latex,dashed,thick,color=BBGreen] (F) to [bend left] (E);
- \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5_{\textcolor{BBRed}{5}}$ };
+ \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5_{\textcolor{BBViolet}{1}}$ };
- \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6_{\textcolor{BBViolet}{1}}$ };
+ \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6_{\textcolor{BBRed}{1}}$ };

+ \draw[-latex,dashed,thick,color=BBGreen] (E) to [bend left] (D);
- \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5_{\textcolor{BBViolet}{1}}$ };
+ \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5_{\textcolor{BBRed}{1}}$ };

## Frame
+ \begin{center}\inputsnippet{cpp}{10}{25}{codes/bridges.cpp}\end{center}

## Frame
+ \begin{center}\inputsnippet{cpp}{27}{39}{codes/bridges.cpp}\end{center}

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Pontos de articulação} };

+ \node[anchor=west] at (1, 6) { \bbtext{Seja $G(V, E)$ um grafo não-direcionado conectado. Um vértice $u\in V$ é um } };
+ \node[anchor=west] at (0.5, 5.5) { \bbtext{\bbbold{ponto de articulação} se a exclusão de $u$ e de todas as arestas que incidem em } };
+ \node[anchor=west] at (0.5, 5) { \bbtext{$u$ torna o grafo desconectado. } };

+ \node[circle, draw, very thick] (A) at (4, 3) { \bbtext{1} };
+ \node[circle, draw, very thick] (B) at (4, 1) { \bbtext{2} };
+ \node[circle, draw, very thick] (C) at (6, 2) { \bbtext{3} };
+ \node[circle, draw, very thick] (D) at (8, 2) { \bbtext{4} };
+ \node[circle, draw, very thick] (E) at (10, 3) { \bbtext{5} };
+ \node[circle, draw, very thick] (F) at (10, 1) { \bbtext{6} };
+ \draw[very thick] (A) to (B);
+ \draw[very thick] (A) to (C);
+ \draw[very thick] (B) to (C);
+ \draw[very thick] (D) to (C);
+ \draw[very thick] (D) to (E);
+ \draw[very thick] (D) to (F);
+ \draw[very thick] (E) to (F);

+ \node (X) at (7,3.5) { \footnotesize \bbcomment{pontos de articulação} };
+ \draw[-latex,color=BBViolet] (X) to (C);
+ \draw[-latex,color=BBViolet] (X) to (D);

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Identificação de pontos de articulação} };

+ \node[anchor=west] at (1, 5) { \bbtext{Seja $G(V, E)$ um grafo conectado e $s\in V$ o vértice de partida de uma DFS. } };
+ \node[anchor=west] at (0.5, 4) { \bbtext{A aresta $(u, v)\in E$ é uma ponte se $\mu_s(v) \geq i_s(u)$. } }; 

+ \node[anchor=west] at (1, 2) { \bbbold{Caso especial:} \bbtext{$s$ só é ponto de articulação se ele tem, no mínimo, dois filhos } };

## Scene
+ \node[anchor=west] at (0, 7.5) { \bbbold{Grafo} };
+ \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
+ \draw[thick] (A) to (B);
+ \draw[thick] (A) to (C);
+ \draw[thick] (B) to (C);
+ \draw[thick] (D) to (C);
+ \draw[thick] (D) to (E);
+ \draw[thick] (D) to (F);
+ \draw[thick] (E) to (F);

+ \node[anchor=west] at (6, 7.5) { \bbbold{Árvore gerada pelo DFS} };

- \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, fill, color=BBCyan] (D) at (3, 2.5) { \bbtext{4} };
+ \node[circle, draw, very thick] (D) at (3, 2.5) { \bbtext{4} };

+ \node[circle, draw, very thick] (D1) at (9, 6.5) { \bbtext{4}$^1_{\textcolor{BBRed}{1}}$ };

- \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, fill, color=BBCyan] (C) at (3, 4.5) { \bbtext{3} };
+ \node[circle, draw, very thick] (C) at (3, 4.5) { \bbtext{3} };
- \draw[thick] (D) to (C);
+ \draw[-latex,very thick] (D) to (C);

+ \node[circle, draw, very thick] (C1) at (7, 4.5) { \bbtext{3}$^2_{\textcolor{BBRed}{2}}$ };
+ \draw[-latex,very thick] (D1) to (C1);

- \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, fill, color=BBCyan] (A) at (2, 6.5) { \bbtext{1} };
+ \node[circle, draw, very thick] (A) at (2, 6.5) { \bbtext{1} };
- \draw[thick] (A) to (C);
+ \draw[-latex,very thick] (C) to (A);

+ \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3_{\textcolor{BBRed}{3}}$ };
+ \draw[-latex,very thick] (C1) to (A1);

- \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, fill, color=BBCyan] (B) at (4, 6.5) { \bbtext{2} };
+ \node[circle, draw, very thick] (B) at (4, 6.5) { \bbtext{2} };
- \draw[thick] (A) to (B);
+ \draw[-latex,very thick] (A) to (B);

+ \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4_{\textcolor{BBRed}{4}}$ };
+ \draw[-latex,very thick] (A1) to (B1);

- \draw[thick] (B) to (C);
+ \draw[-latex,dashed,thick] (B) to (C);

+ \draw[-latex,thick,dashed,color=BBViolet] (B1) to (C1);
- \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4_{\textcolor{BBRed}{4}}$ };
+ \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4_{\textcolor{BBViolet}{2}}$ };

+ \draw[-latex,dashed,thick,color=BBGreen] (B) to [bend right] (A);
- \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4_{\textcolor{BBViolet}{2}}$ };
+ \node[circle, draw, very thick] (B1) at (7, 0.5) { \bbtext{2}$^4_{\textcolor{BBRed}{2}}$ };
- \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3_{\textcolor{BBRed}{3}}$ };
+ \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3_{\textcolor{BBViolet}{2}}$ };

+ \draw[-latex,dashed,thick,color=BBGreen] (A) to [bend right] (C);
- \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3_{\textcolor{BBViolet}{2}}$ };
+ \node[circle, draw, very thick] (A1) at (8, 2.5) { \bbtext{1}$^3_{\textcolor{BBRed}{2}}$ };

+ \node[color=BBViolet] at (1.3, 3.7) { \bbcomment{ponto de} };
+ \node[color=BBViolet] at (1.3, 3.3) { \bbcomment{articulação} };
+ \draw[-latex,color=BBViolet] (2, 4.0) to (C);

+ \draw[-latex,dashed,thick,color=BBGreen] (C) to [bend left] (D);

- \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, fill, color=BBCyan] (E) at (2, 0.5) { \bbtext{5} };
+ \node[circle, draw, very thick] (E) at (2, 0.5) { \bbtext{5} };
- \draw[thick] (D) to (E);
+ \draw[-latex,very thick] (D) to (E);

+ \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5_{\textcolor{BBRed}{5}}$ };
+ \draw[-latex,very thick] (D1) to (E1);

- \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
+ \node[circle, fill, color=BBCyan] (F) at (4, 0.5) { \bbtext{6} };
+ \node[circle, draw, very thick] (F) at (4, 0.5) { \bbtext{6} };
- \draw[thick] (E) to (F);
+ \draw[-latex,very thick] (E) to (F);

+ \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6_{\textcolor{BBRed}{6}}$ };
+ \draw[-latex,very thick] (E1) to (F1);

- \draw[thick] (D) to (F);
+ \draw[latex-,dashed,thick] (D) to (F);

+ \draw[-latex,thick,dashed,color=BBViolet] (F1) to [bend left] (D1);
- \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6_{\textcolor{BBRed}{6}}$ };
+ \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6_{\textcolor{BBViolet}{1}}$ };

+ \draw[-latex,dashed,thick,color=BBGreen] (F) to [bend left] (E);
- \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5_{\textcolor{BBRed}{5}}$ };
+ \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5_{\textcolor{BBViolet}{1}}$ };
- \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6_{\textcolor{BBViolet}{1}}$ };
+ \node[circle, draw, very thick] (F1) at (12, 2.5) { \bbtext{6}$^6_{\textcolor{BBRed}{1}}$ };

+ \draw[-latex,dashed,thick,color=BBGreen] (E) to [bend left] (D);
- \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5_{\textcolor{BBViolet}{1}}$ };
+ \node[circle, draw, very thick] (E1) at (11, 4.5) { \bbtext{5}$^5_{\textcolor{BBRed}{1}}$ };

+ \draw[-latex,color=BBViolet] (2, 3.0) to (D);

## Frame
+ \begin{center}\inputsnippet{cpp}{10}{29}{codes/articulation_points.cpp}\end{center}

## Frame
+ \begin{center}\inputsnippet{cpp}{31}{48}{codes/articulation_points.cpp}\end{center}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Problemas sugeridos} };
+ \node[anchor=west] at (0.5, 5) { $1.$ \bbtext{AtCoder Beginner Contest 075 -- Problem C: Bridge } };
+ \node[anchor=west] at (0.5, 4) { $2.$ \bbtext{OJ 315 -- Network } };
+ \node[anchor=west] at (0.5, 3) { $3.$ \bbtext{OJ 610 -- Street Directions } };
+ \node[anchor=west] at (0.5, 2) { $4.$ \bbtext{SPOJ SUBMERGE -- Submerging Islands } };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Referências} };
+ \node[anchor=west] at (1, 5) { $1.$ \bbbold{HALIM}, \bbtext{Felix}; \bbbold{HALIM}, \bbtext{Steve}. \bbenglish{Competitive Programming 3,} \bbtext{2010.} };
+ \node[anchor=west] at (1, 4) { $2.$ \bbbold{LAAKSONEN}, \bbtext{Antti}. \bbenglish{Competitive Programmer's Handbook,} \bbtext{2018.} };
+ \node[anchor=west] at (1, 3) { $3.$ \bbbold{SKIENA}, \bbtext{Steven}; \bbbold{REVILLA}, \bbtext{Miguel}. \bbenglish{Programming Challenges,} \bbtext{2003.} };

## End
