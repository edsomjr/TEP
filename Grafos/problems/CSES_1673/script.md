## Frame
+ \bbcover{CSES 1673}{High Score}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text
+ \bbenglish{You play a game consisting of $n$ rooms and $m$ tunnels. Your initial score is $0$, and each tunnel increases your score by $x$ where $x$ may be both positive or negative. You may go through a tunnel several times.}
+
+ \vspace{0.1in}
+ 
+ \bbenglish{Your task is to walk from room $1$ to room $n$. What is the maximum score you can get?}

## Text
+ \bbtext{Você vai jogar um jogo composto por $n$ salas e $m$ túneis. Sua pontuação inicial é igual a $0$, e cada túnel aumenta sua pontuação em $x$ unidades, onde $x$ pode ser tanto positivo quanto negativo. Você pode passar por um mesmo túnel várias vezes.}
+
+ \vspace{0.1in}
+ 
+ \bbtext{Sua tarefa é ir da sala $1$ para a sala $n$. Qual é a maior pontuação que você pode obter?}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbenglish{The first input line has two integers $n$ and $m$: the number of rooms and tunnels. The rooms are numbered $1, 2, \ldots , n$.}
+
+ \vspace{0.1in}
+
+ \bbenglish{Then, there are m lines describing the tunnels. Each line has three integers $a, b$ and $x$: the tunnel starts at room $a$, ends at room $b$, and it increases your score by $x$. All tunnels are one-way tunnels.}
+
+ \vspace{0.1in}
+
+ \bbenglish{You can assume that it is possible to get from room $1$ to room $n$.}
+
+ \vspace{0.2in}
+
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbenglish{Print one integer: the maximum score you can get. However, if you can get an arbitrarily large score, print $-1$.}

## Text
+ \bbbold{Entrada}
+
+ \vspace{0.1in}
+
+ \bbtext{A primeira linha da entrada contém dois inteiros $n$ e $m$: o número de salas e de túneis. As salas são numeradas $1, 2, \ldots , n$.}
+
+ \vspace{0.1in}
+
+ \bbtext{As $m$ linhas seguintes descrevem os túneis. Cada linha tem três inteiros $a, b$ e $x$: o túnel começa na sala $a$, termina na sala $b$ e aumenta sua pontuação em $x$ unidades. Todos os túneis são de mão única.}
+
+ \vspace{0.1in}
+
+ \bbtext{Assuma que é possível ir da sala $1$ para a sala $n$.}
+
+ \vspace{0.2in}
+
+ \bbbold{Saída}
+
+ \vspace{0.1in}
+
+ \bbtext{Imprima um inteiro: a pontuação máxima que você pode obter. Contudo, se você pode obter uma pontuação arbitrariamente grande, imprima $-1$.}

## Text
+ \bbbold{Constraints}
+
+ \vspace{0.1in}
+
+ \begin{itemize} \item $1\leq 2500\leq n$ \item $1\leq 5000\leq m$ \item $1\leq a, b\leq n$ \item $-10^9 \leq x\leq 10^9$\end{itemize}

## Text
+ \bbbold{Restrições}
+
+ \vspace{0.1in}
+
+ \begin{itemize} \item $1\leq 2500\leq n$ \item $1\leq 5000\leq m$ \item $1\leq a, b\leq n$ \item $-10^9 \leq x\leq 10^9$\end{itemize}

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{4 5} };

+ \node at (1.25, 5) { \footnotesize \bbcomment{\# de salas} };
+ \draw[->,color=BBViolet] (1.25, 5.2) -- (1.25, 5.8);

+ \node[draw,very thick,circle] (A) at (6, 4) { \bbtext{1} };
+ \node[draw,very thick,circle] (B) at (9, 7) { \bbtext{2} };
+ \node[draw,very thick,circle] (C) at (12, 4) { \bbtext{3} };
+ \node[draw,very thick,circle] (D) at (9, 1) { \bbtext{4} };

+ \node[anchor=west] at (2.75, 6) { \footnotesize \bbcomment{\# de túneis} };
+ \draw[->,color=BBViolet] (1.75, 6) -- (2.75, 6);

- \node at (1.25, 5) { \footnotesize \bbcomment{\# de salas} };
- \draw[->,color=BBViolet] (1.25, 5.2) -- (1.25, 5.8);
- \node[anchor=west] at (2.75, 6) { \footnotesize \bbcomment{\# de túneis} };
- \draw[->,color=BBViolet] (1.75, 6) -- (2.75, 6);

+ \node[anchor=west] at (1, 5) { \bbtext{1 2 3} };

+ \node at (1.25, 4) { \footnotesize $a$ };
+ \draw[->,color=BBViolet] (1.25, 4.2) -- (1.25, 4.8);

+ \node at (1.55, 4) { \footnotesize $b$ };
+ \draw[->,color=BBViolet] (1.55, 4.2) -- (1.55, 4.8);

+ \node at (1.88, 4) { \footnotesize $x$ };
+ \draw[->,color=BBViolet] (1.88, 4.2) -- (1.88, 4.8);

- \node at (1.25, 4) { \footnotesize $a$ };
- \node at (1.55, 4) { \footnotesize $b$ };
- \node at (1.88, 4) { \footnotesize $x$ };
- \draw[->,color=BBViolet] (1.25, 4.2) -- (1.25, 4.8);
- \draw[->,color=BBViolet] (1.55, 4.2) -- (1.55, 4.8);
- \draw[->,color=BBViolet] (1.88, 4.2) -- (1.88, 4.8);
+ \draw[-latex,thick] (A) to node[above] { \bbinfo{3} } (B);

+ \node[anchor=west] at (1, 4.5) { \bbtext{2 4 -1} };

+ \draw[-latex,thick] (B) to node[right,pos=0.3] { \bbinfo{-1} } (D);

+ \node[anchor=west] at (1, 4.0) { \bbtext{1 3 -2} };

+ \draw[-latex,thick] (A) to node[above,pos=0.3] { \bbinfo{-2} } (C);

+ \node[anchor=west] at (1, 3.5) { \bbtext{3 4 7} };

+ \draw[-latex,thick] (C) to node[above] { \bbinfo{7} } (D);

+ \node[anchor=west] at (1, 3.0) { \bbtext{1 4 4} };

+ \draw[-latex,thick] (A) to node[above] { \bbinfo{4} } (D);

+ \draw[-latex,very thick,color=BBRed,dashed] (1, 2) to (2.0, 2);
+ \node[anchor=west] at (2.0, 2) { $3 - 1 = 2$ };
- \draw[-latex,thick] (A) to node[above] { \bbinfo{3} } (B);
- \draw[-latex,thick] (B) to node[right,pos=0.3] { \bbinfo{-1} } (D);
+ \draw[-latex,very thick,color=BBRed,dashed] (A) to node[above] { \bbinfo{3} } (B);
+ \draw[-latex,very thick,color=BBRed,dashed] (B) to node[right,pos=0.3] { \bbinfo{-1} } (D);

+ \draw[-latex,very thick,color=BBViolet,dashed] (1, 1.5) to (2.0, 1.5);
+ \node[anchor=west] at (2.0, 1.5) { $4$ };
- \draw[-latex,thick] (A) to node[above] { \bbinfo{4} } (D);
+ \draw[-latex,very thick,color=BBViolet,dashed] (A) to node[above] { \bbinfo{4} } (D);

+ \draw[-latex,very thick,color=BBGreen] (1, 1.0) to (2.0, 1.0);
+ \node[anchor=west] at (2.0, 1.0) { $7 - 2 = 5$ };
- \draw[-latex,thick] (A) to node[above,pos=0.3] { \bbinfo{-2} } (C);
+ \draw[-latex,very thick,color=BBGreen] (A) to node[above,pos=0.3] { \bbinfo{-2} } (C);
- \draw[-latex,thick] (C) to node[above] { \bbinfo{7} } (D);
+ \draw[-latex,very thick,color=BBGreen] (C) to node[above] { \bbinfo{7} } (D);

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Solução} };

## Frame
+ \inputsnippet{cpp}{31}{50}{codes/1673.cpp}

## Frame
+ \inputsnippet{cpp}{14}{29}{codes/1673.cpp}

## End
