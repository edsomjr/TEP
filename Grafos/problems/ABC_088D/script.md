## Frame
+ \bbcover{AtCoder Beginner Contest 088}{Problem D -- Grid Repainting}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text
+ \bbenglish{We have an $H\times W$ grid whose squares are painted black or white. The square at the $i$-th row from the top and the $j$-th column from the left is denoted as $(i, j)$.}
+
+ \vspace{0.2in}
+ 
+ \bbenglish{Snuke would like to play the following game on this grid. At the beginning of the game, there is a character called Kenus at square $(1, 1)$. The player repeatedly moves Kenus up, down, left or right by one square. The game is completed when Kenus reaches square $(H, W)$ passing only white squares.}
+
+ \vspace{0.2in}
+ 
+ \bbenglish{Before Snuke starts the game, he can change the color of some of the white squares to black. However, he cannot change the color of square $(1, 1)$ and $(H, W)$. Also, changes of color must all be carried out before the beginning of the game.}

## Text
+ \bbtext{Nos temos uma malha $H\times W$ cujos quadrados são pintados de preto ou branco. O quadrado na $i$-ésima linha a partir do topo e na $j$-ésima coluna a contar da esquerda é representada pelo par $(i, j)$.}
+
+ \vspace{0.2in}
+ 
+ \bbtext{Snuke gostaria de brincar do seguinte jogo nesta malha. No início do jogo, há um personagem chamada Kenus no quadrado $(1, 1)$. O jogador move Kenus um quadrado para cima, baixo, esquerda ou direita. O jogo termina quando Kenus atinge o quadrado $(H, W)$ passando apenas por quadrados brancos.}
+
+ \vspace{0.2in}
+ 
+ \bbtext{Antes que Snuke inicie o jogo, ele pode mudar a cor de alguns quadrados brancos para pretos. Contudo, ele não pode mudar a cor dos quadrados $(1, 1)$ e $(H, W)$. As mudanças de cores deve ser todas feitas antes do início do jogo.}

## Text
+ \bbenglish{When the game is completed, Snuke's score will be the number of times he changed the color of a square before the beginning of the game. Find the maximum possible score that Snuke can achieve, or print $-1$ if the game cannot be completed, that is, Kenus can never reach square $(H, W)$ regardless of how Snuke changes the color of the squares.}
+
+ \vspace{0.2in}
+ 
+ \bbenglish{The color of the squares are given to you as characters $s_{i,j}$. If square $(i,j)$ is initially painted by white, $s_{i,j}$ is \texttt{.}; if square $(i,j)$ is initially painted by black, $s_{i,j}$ is \texttt{\#}.}
+
+ \vspace{0.1in}
+ 
+ \bbbold{Constraints}
+
+ \vspace{0.1in}
+
+ \begin{itemize} \item $H$ \bbenglish{is an integer between $2$ and $50$ (inclusive).} \item $W$ \bbenglish{is an integer between $2$ and $50$ (inclusive).} \item $s_{i,j}$ \bbenglish{is \texttt{.} or \texttt{\#} $(1\leq i\leq H, 1\leq j\leq W)$.} \item $s_{1,1}$ \bbenglish{and $s_{H,W}$ are \texttt{.}.} \end{itemize}

## Text
+ \bbtext{Quando o jogo termina, a pontuação de Snuke será o número de trocas de cores antes do início do jogo. Determine a maior pontuação possível que Snuke pode alcançar, ou imprima $-1$ se o jogo não pode ser finalizado, isto é, Kenus não pode atingir o quadrado $(H, W)$ independentemente de como Snuke altere as cores dos quadrados.}
+
+ \vspace{0.2in}
+ 
+ \bbtext{As cores dos quadrados são dadas na forma de caracteres $s_{i,j}$. Se o quadrado $(i,j)$ é pintado branco inicialmente, $s_{i,j}$ será \texttt{.}; se $(i,j)$ é pintado preto, $s_{i,j}$ será \texttt{\#}.}
+
+ \vspace{0.1in}
+ 
+ \bbbold{Restrições}
+
+ \vspace{0.1in}
+
+ \begin{itemize} \item $H$ \bbtext{é um inteiro entre $2$ e $50$ (inclusive).} \item $W$ \bbtext{é um inteiro entre $2$ e $50$ (inclusive).} \item $s_{i,j}$ \bbtext{é igual a \texttt{.} ou \texttt{\#} $(1\leq i\leq H, 1\leq j\leq W)$.} \item $s_{1,1}$ \bbtext{e $s_{H,W}$ são iguais a \texttt{.}.} \end{itemize}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbenglish{Input is given from Standard Input in the following format:}
+ \begin{align*}
+       & H\ W \\
+       & s_{1,1}s_{1,2}s_{1,3}\ldots s_{1,W} \\
+       & s_{2,1}s_{2,2}s_{2,3}\ldots s_{2,W} \\
+       & \ \ \vdots\ \ \ \ \ \ \ \ \ \ \vdots \\
+       & s_{H,1}s_{H,2}s_{H,3}\ldots s_{H,W}
+ \end{align*}
+
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbenglish{Print the maximum possible score that Snuke can achieve, or print $-1$ if the game cannot be completed.}

## Text
+ \bbbold{Entrada}
+
+ \vspace{0.1in}
+
+ \bbtext{A entrada é dada na Entrada Padrão no seguinte formato:}
+ \begin{align*}
+       & H\ W \\
+       & s_{1,1}s_{1,2}s_{1,3}\ldots s_{1,W} \\
+       & s_{2,1}s_{2,2}s_{2,3}\ldots s_{2,W} \\
+       & \ \ \vdots\ \ \ \ \ \ \ \ \ \ \vdots \\
+       & s_{H,1}s_{H,2}s_{H,3}\ldots s_{H,W}
+ \end{align*}
+
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbtext{Imprima a maior pontuação possível que Snuke pode conseguir, ou imprima $-1$ se o jogo não pode ser concluído.}

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{\texttt{3 3}} };

+ \node at (1.25, 5) { \footnotesize \bbcomment{$H$} };
+ \draw[->,color=BBViolet] (1.25, 5.2) -- (1.25, 5.8);

+ \node at (2.8, 6) { \footnotesize \bbcomment{$W$} };
+ \draw[->,color=BBViolet] (1.85, 6) -- (2.5, 6);

- \node at (1.25, 5) { \footnotesize \bbcomment{$H$} };
- \draw[->,color=BBViolet] (1.25, 5.2) -- (1.25, 5.8);
- \node at (2.8, 6) { \footnotesize \bbcomment{$W$} };
- \draw[->,color=BBViolet] (1.85, 6) -- (2.5, 6);

+ \node[anchor=west] at (1, 5.5) { \bbtext{\texttt{..\#}} };
+ \node[anchor=west] at (1, 5.0) { \bbtext{\texttt{\#..}} };
+ \node[anchor=west] at (1, 4.5) { \bbtext{\texttt{...}} };

+ \node[anchor=west] at (2.5, 5) { \footnotesize \bbcomment{malha} };
+ \draw[->,color=BBViolet] (1.85, 5) -- (2.5, 5);

- \node[anchor=west] at (2.5, 5) { \footnotesize \bbcomment{malha} };
- \draw[->,color=BBViolet] (1.85, 5) -- (2.5, 5);
+ \draw[very thick] (7, 3) grid (10, 6);
+ \fill[black] (9, 5) rectangle (10, 6);
+ \fill[black] (7, 4) rectangle (8, 5);

+ \node at (7.5, 5.5) { \Large \faMale };
+ \node at (9.5, 3.5) { \faTimesCircleO };

+ \draw[-latex,thick,color=BBViolet] (7.8, 5.5) to (8.5, 5.5) to (8.5, 4.5) to (9.5, 4.5) to (9.5, 3.7);

+ \draw[very thick, fill=BBOrange] (7, 3) rectangle (8, 4);
+ \draw[very thick, fill=BBOrange] (8, 3) rectangle (9, 4);

+ \draw[-latex,very thick] (1.45, 4.2) to (1.45, 3.2);
+ \node at (1.45, 2.9) { \bbinfo{2} };

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{\texttt{10 37}} };

+ \node[anchor=west] at (1, 5.5) { \bbtext{\texttt{.....................................}} };
+ \node[anchor=west] at (1, 5.0) { \bbtext{\texttt{...\#...\#\#\#\#...\#\#\#\#..\#\#\#...\#\#\#...\#\#\#..}} };
+ \node[anchor=west] at (1, 4.5) { \bbtext{\texttt{..\#.\#..\#...\#.\#\#....\#...\#.\#...\#.\#...\#.}} };
+ \node[anchor=west] at (1, 4.0) { \bbtext{\texttt{..\#.\#..\#...\#.\#.....\#...\#.\#...\#.\#...\#.}} };
+ \node[anchor=west] at (1, 3.5) { \bbtext{\texttt{.\#...\#.\#..\#\#.\#.....\#...\#.\#.\#\#\#.\#.\#\#\#.}} };
+ \node[anchor=west] at (1, 3.0) { \bbtext{\texttt{.\#\#\#\#\#.\#\#\#\#..\#.....\#...\#..\#\#....\#\#...}} };
+ \node[anchor=west] at (1, 2.5) { \bbtext{\texttt{.\#...\#.\#...\#.\#.....\#...\#.\#...\#.\#...\#.}} };
+ \node[anchor=west] at (1, 2.0) { \bbtext{\texttt{.\#...\#.\#...\#.\#\#....\#...\#.\#...\#.\#...\#.}} };
+ \node[anchor=west] at (1, 1.5) { \bbtext{\texttt{.\#...\#.\#\#\#\#...\#\#\#\#..\#\#\#...\#\#\#...\#\#\#..}} };
+ \node[anchor=west] at (1, 1.0) { \bbtext{\texttt{.....................................}} };

- \node[anchor=west] at (1, 5.0) { \bbtext{\texttt{...\#...\#\#\#\#...\#\#\#\#..\#\#\#...\#\#\#...\#\#\#..}} };
- \node[anchor=west] at (1, 4.5) { \bbtext{\texttt{..\#.\#..\#...\#.\#\#....\#...\#.\#...\#.\#...\#.}} };
- \node[anchor=west] at (1, 4.0) { \bbtext{\texttt{..\#.\#..\#...\#.\#.....\#...\#.\#...\#.\#...\#.}} };
- \node[anchor=west] at (1, 3.5) { \bbtext{\texttt{.\#...\#.\#..\#\#.\#.....\#...\#.\#.\#\#\#.\#.\#\#\#.}} };
- \node[anchor=west] at (1, 3.0) { \bbtext{\texttt{.\#\#\#\#\#.\#\#\#\#..\#.....\#...\#..\#\#....\#\#...}} };
- \node[anchor=west] at (1, 2.5) { \bbtext{\texttt{.\#...\#.\#...\#.\#.....\#...\#.\#...\#.\#...\#.}} };
- \node[anchor=west] at (1, 2.0) { \bbtext{\texttt{.\#...\#.\#...\#.\#\#....\#...\#.\#...\#.\#...\#.}} };
- \node[anchor=west] at (1, 1.5) { \bbtext{\texttt{.\#...\#.\#\#\#\#...\#\#\#\#..\#\#\#...\#\#\#...\#\#\#..}} };
- \node[anchor=west] at (1, 1.0) { \bbtext{\texttt{.....................................}} };
+ \node[anchor=west] at (1, 5.0) { \bbtext{\texttt{\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\#\textcolor{BBOrange}{\#}.}} };
+ \node[anchor=west] at (1, 4.5) { \bbtext{\texttt{\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#.}} };
+ \node[anchor=west] at (1, 4.0) { \bbtext{\texttt{\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#.}} };
+ \node[anchor=west] at (1, 3.5) { \bbtext{\texttt{\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\#\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\#\#.}} };
+ \node[anchor=west] at (1, 3.0) { \bbtext{\texttt{\textcolor{BBOrange}{\#}\#\#\#\#\#\textcolor{BBOrange}{\#}\#\#\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}.}} };
+ \node[anchor=west] at (1, 2.5) { \bbtext{\texttt{\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#.}} };
+ \node[anchor=west] at (1, 2.0) { \bbtext{\texttt{\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#.}} };
+ \node[anchor=west] at (1, 1.5) { \bbtext{\texttt{\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\textcolor{BBOrange}{\#}\#\#\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\#\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\#\#\#\textcolor{BBOrange}{\#}.}} };
+ \node[anchor=west] at (1, 1.0) { \bbtext{\texttt{\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}\textcolor{BBOrange}{\#}.}} };

+ \draw[-latex,thick] (9, 3.5) to (10, 3.5);
+ \node[anchor=west] at (10, 3.5) { \bbinfo{209} };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Solução} };

+ \node[anchor=west] at (1, 6) { $\star$ \bbtext{Para que exista solução, é preciso que exista ao menos um caminho de} };
+ \node[anchor=west] at (0.5, 5.5) { \bbtext{$(1, 1)$ a $(H, W)$ } };

+ \node[anchor=west] at (1, 4.5) { $\star$ \bbtext{Uma vez identificado um caminho, todos os quadrados brancos que não} };
+ \node[anchor=west] at (0.5, 4.0) { \bbtext{fizerem parte do caminho podem ser pintados de preto } };

+ \node[anchor=west] at (1, 3.0) { $\star$ \bbtext{Deste modo, para maximizar o número de quadrados a serem pintados é } };
+ \node[anchor=west] at (0.5, 2.5) { \bbtext{preciso escolher um caminho mínimo } };

+ \node[anchor=west] at (1, 1.5) { $\star$ \bbtext{Como o custo para ser mover entre quadrados vizinhos é constante, este} };
+ \node[anchor=west] at (0.5, 1.0) { \bbtext{caminho pode ser obtido por meio de uma BFS } };

## Frame
+ \inputsnippet{cpp}{11}{29}{codes/B088D.cpp}

## Frame
+ \inputsnippet{cpp}{30}{48}{codes/B088D.cpp}

## End
