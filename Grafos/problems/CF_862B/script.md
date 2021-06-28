## Frame
+ \bbcover{Codeforces Round \#435 (Div. 2)}{Problem B -- Mahmoud and Ehab and the bipartiteness}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text
+ \bbenglish{Mahmoud and Ehab continue their adventures! As everybody in the evil land knows, Dr. Evil likes bipartite graphs, especially trees.}
+
+ \vspace{0.1in}
+ 
+ \bbenglish{A tree is a connected acyclic graph. A bipartite graph is a graph, whose vertices can be partitioned into $2$ sets in such a way, that for each edge $(u, v)$ that belongs to the graph, $u$ and $v$ belong to different sets. You can find more formal definitions of a tree and a bipartite graph in the notes section below.}
+
+ \vspace{0.1in}
+ 
+ \bbenglish{Dr. Evil gave Mahmoud and Ehab a tree consisting of $n$ nodes and asked them to add edges to it in such a way, that the graph is still bipartite. Besides, after adding these edges the graph should be simple (doesn't contain loops or multiple edges). What is the maximum number of edges they can add?}
+
+ \vspace{0.1in}
+ 
+ \bbenglish{A loop is an edge, which connects a node with itself. Graph doesn't contain multiple edges when for each pair of nodes there is no more than one edge between them. \bbbold{A cycle and a loop aren't the same}.}

## Text
+ \bbtext{Mahmoud e Ehab continuam suas aventuras! Como todos na terra do mal sabem, Dr. Evil gosta de grafos bipartidos, especialmente árvores.}
+
+ \vspace{0.1in}
+ 
+ \bbtext{Uma árvore é um grafo conectado acíclico. Um grafo bipartido é um grafo cujos vértices podem ser particionados em $2$ conjuntos de forma que, para cada aresta $(u, v)$ que pertence ao grafo, $u$ e $v$ pertencem a conjuntos diferentes. Você pode encontrar definições mais formais de árvore e grafo bipartido na seção de notas abaixo.}
+
+ \vspace{0.1in}
+ 
+ \bbtext{Dr. Evil deu a Mahmoud e Ehab uma árvore composta por $n$ vértices e pediu a eles para adicionarem arestas ao grafo de modo que ele permaneça ainda bipartido. Além disso, após adicionar as arestas o grafo ainda deve ser simples (não pode conter \bbenglish{loops} ou arestas múltiplas). Qual é o número máximo de arestas que eles podem adicionar?}
+
+ \vspace{0.1in}
+ 
+ \bbtext{Um \bbenglish{loop} é uma aresta que conecta o vértice a si mesmo. Grafos não contém múltiplas arestas quando para cada par de vértices existe no máximo uma aresta entre eles. \bbbold{Um ciclo e um \textit{loop} não são a mesma coisa}.}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbenglish{The first line of input contains an integer $n$ -- the number of nodes in the tree $(1\leq n\leq 10^5)$.}
+
+ \vspace{0.1in}
+
+ \bbenglish{The next $n - 1$ lines contain integers $u$ and $v$ $(1\leq u, v\leq n, u\neq v)$ -- the description of the edges of the tree.}
+
+ \vspace{0.1in}
+
+ \bbenglish{It's guaranteed that the given graph is a tree.}
+
+ \vspace{0.2in}
+
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbenglish{Output one integer -- the maximum number of edges that Mahmoud and Ehab can add to the tree while fulfilling the conditions.}

## Text
+ \bbbold{Entrada}
+
+ \vspace{0.1in}
+
+ \bbtext{A primeira linha da entrada contém um inteiro $n$ -- o número de vértices na árvore $(1\leq n\leq 10^5)$.}
+
+ \vspace{0.1in}
+
+ \bbtext{As próximas $n - 1$ linhas contém os inteiros $u$ e $v$ $(1\leq u, v\leq n, u\neq v)$ -- a descrição das arestas da árvore.}
+
+ \vspace{0.1in}
+
+ \bbtext{É garantido que o grafo dado é um árvore.}
+
+ \vspace{0.2in}
+
+ \bbbold{Saída}
+
+ \vspace{0.1in}
+
+ \bbtext{Imprima um número -- o máximo de arestas que Mahmoud e Ehab podem adicionar à árvore respeitando as condições impostas.}

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{3} };

+ \node at (1.25, 5) { \footnotesize \bbcomment{\# de vértices} };
+ \draw[->,color=BBViolet] (1.25, 5.2) -- (1.25, 5.8);

+ \node[draw,very thick,circle] (A) at (6, 2) { \bbtext{1} };
+ \node[draw,very thick,circle] (B) at (9, 6) { \bbtext{2} };
+ \node[draw,very thick,circle] (C) at (12, 2) { \bbtext{3} };

- \node at (1.25, 5) { \footnotesize \bbcomment{\# de vértices} };
- \draw[->,color=BBViolet] (1.25, 5.2) -- (1.25, 5.8);
+ \node[anchor=west] at (1, 5) { \bbtext{1 2} };

+ \node at (1.4, 4) { \footnotesize \bbcomment{primeira aresta} };
+ \draw[->,color=BBViolet] (1.4, 4.2) -- (1.4, 4.8);

+ \draw[thick] (A) to (B);

- \node at (1.4, 4) { \footnotesize \bbcomment{primeira aresta} };
- \draw[->,color=BBViolet] (1.4, 4.2) -- (1.4, 4.8);
+ \node[anchor=west] at (1, 4) { \bbtext{1 3} };

+ \node at (1.4, 3) { \footnotesize \bbcomment{segunda aresta} };
+ \draw[->,color=BBViolet] (1.4, 3.2) -- (1.4, 3.8);

+ \draw[thick] (A) to (C);

- \node at (1.4, 3) { \footnotesize \bbcomment{segunda aresta} };
- \draw[->,color=BBViolet] (1.4, 3.2) -- (1.4, 3.8);
+ \node[anchor=west] (D) at (10, 7) { \footnotesize \bbcomment{$G$ é bipartido} };
+ \draw[->,color=BBViolet] (D) to [bend left] (B);
- \node[draw,very thick,circle] (A) at (6, 2) { \bbtext{1} };
- \node[draw,very thick,circle] (B) at (9, 6) { \bbtext{2} };
- \node[draw,very thick,circle] (C) at (12, 2) { \bbtext{3} };
+ \node[fill,color=BBGreen,circle] (A) at (6, 2) { \bbtext{1} };
+ \node[fill,color=BBCyan,circle] (B) at (9, 6) { \bbtext{2} };
+ \node[fill,color=BBCyan,circle] (C) at (12, 2) { \bbtext{3} };
+ \node[draw,very thick,circle] (A) at (6, 2) { \bbtext{1} };
+ \node[draw,very thick,circle] (B) at (9, 6) { \bbtext{2} };
+ \node[draw,very thick,circle] (C) at (12, 2) { \bbtext{3} };

+ \draw[thick] (B) to node { \Large \bbalert{X} } (C);

+ \draw[-latex,very thick] (1.4, 3.0) to (1.4, 3.7);
+ \node at (1.4, 2.7) { \bbinfo{0} };

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (0.5, 6) { \bbtext{5} };

+ \node[draw,very thick,circle] (A) at (4, 4) { \bbtext{1} };
+ \node[draw,very thick,circle] (B) at (8, 7) { \bbtext{2} };
+ \node[draw,very thick,circle] (C) at (12, 4) { \bbtext{3} };
+ \node[draw,very thick,circle] (D) at (10, 1) { \bbtext{4} };
+ \node[draw,very thick,circle] (E) at (6, 1) { \bbtext{5} };

+ \node[anchor=west] at (0.5, 5.5) { \bbtext{1 2} };

+ \draw[thick] (A) to (B);

+ \node[anchor=west] at (0.5, 5.0) { \bbtext{2 3} };

+ \draw[thick] (B) to (C);

+ \node[anchor=west] at (0.5, 4.5) { \bbtext{3 4} };

+ \draw[thick] (C) to (D);

+ \node[anchor=west] at (0.5, 4.0) { \bbtext{4 5} };

+ \draw[thick] (D) to (E);

- \node[draw,very thick,circle] (A) at (4, 4) { \bbtext{1} };
- \node[draw,very thick,circle] (B) at (8, 7) { \bbtext{2} };
- \node[draw,very thick,circle] (C) at (12, 4) { \bbtext{3} };
- \node[draw,very thick,circle] (D) at (10, 1) { \bbtext{4} };
- \node[draw,very thick,circle] (E) at (6, 1) { \bbtext{5} };
+ \node[fill,color=BBCyan,circle] (A) at (4, 4) { \bbtext{1} };
+ \node[fill,color=BBGreen,circle] (B) at (8, 7) { \bbtext{2} };
+ \node[fill,color=BBCyan,circle] (C) at (12, 4) { \bbtext{3} };
+ \node[fill,color=BBGreen,circle] (D) at (10, 1) { \bbtext{4} };
+ \node[fill,color=BBCyan,circle] (E) at (6, 1) { \bbtext{5} };
+ \node[draw,very thick,circle] (A) at (4, 4) { \bbtext{1} };
+ \node[draw,very thick,circle] (B) at (8, 7) { \bbtext{2} };
+ \node[draw,very thick,circle] (C) at (12, 4) { \bbtext{3} };
+ \node[draw,very thick,circle] (D) at (10, 1) { \bbtext{4} };
+ \node[draw,very thick,circle] (E) at (6, 1) { \bbtext{5} };

+ \draw[thick,color=BBOrange] (A) to (D);
+ \draw[thick,color=BBOrange] (B) to (E);

+ \draw[-latex,very thick] (0.9, 3.0) to (0.9, 3.7);
+ \node at (0.9, 2.7) { \bbinfo{2} };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Solução} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{Para cada estudante $a$ são necessárias, no máximo, $n + 1$ verificações} };

+ \node[anchor=west] at (1, 4) { $\star$ \bbtext{Estas verificações podem ser feitas por meio de uma DFS} };

+ \node[anchor=west] at (1, 3) { $\star$ \bbtext{Há $n$ estudantes distintos} };

+ \node[anchor=west] at (1, 2) { $\star$ \bbtext{A complexidade da solução é $O(n^2)$} };

## Frame
+ \inputsnippet{cpp}{11}{30}{codes/862B.cpp}

## End
