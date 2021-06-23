## Frame
+ \bbcover{AtCoder Beginner Contest 174}{Problem C -- Repsept}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text
+ \bbenglish{Takahashi loves the number $7$ and multiples of $K$.}
+
+ \vspace{0.2in}
+ 
+ \bbenglish{Where is the first occurrence of a multiple of $K$ in the sequence $7, 77, 777, \ldots$? (Also see Output and Sample Input/Output below.)}
+
+ \vspace{0.2in}
+ 
+ \bbenglish{If the sequence contains no multiples of $K$, print \bbalert{\tt -1} instead.}
+
+ \vspace{0.2in}
+
+ \bbbold{Constraints}
+
+ \begin{itemize} \item $1\leq K\leq 10^6$ \item $K$ \bbenglish{is an integer.} \end{itemize}

## Text
+ \bbtext{Takahashi ama o número $7$ e múltiplos de $K$.}
+
+ \vspace{0.2in}
+ 
+ \bbtext{Qual é a primeira ocorrência de um múltiplo de $K$ na sequência $7, 77, 777, \ldots$? (Veja também a Saída e os Exemplos abaixo.)}
+
+ \vspace{0.2in}
+ 
+ \bbtext{Se a sequência não contém múltiplos de $K$, imprima \bbalert{\tt -1}.}
+
+ \vspace{0.2in}
+
+ \bbbold{Restrições}
+
+ \begin{itemize} \item $1\leq K\leq 10^6$ \item $K$ \bbtext{é um inteiro.} \end{itemize}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbenglish{Input is given from Standard Input in the following format:}
+ \[
+      K
+ \]
+ \vspace{0.1in}
+
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbenglish{Print an integer representing the position of the first occurrence of a multiple of $K$. (For example, if the first occurrence is the fourth element of the sequence, print \bbalert{\tt 4}.)}

## Text
+ \bbbold{Entrada}
+
+ \vspace{0.1in}
+
+ \bbtext{A entrada é dada na Entrada Padrão no seguinte formato:}
+ \[
+      K
+ \]
+ \vspace{0.1in}
+
+ \bbbold{Saída}
+
+ \vspace{0.1in}
+
+ \bbtext{Imprima um inteiro que represente a posição da primeira ocorrência de um múltiplo de $K$. (Por exemplo, se a primeira ocorrência é o quarto elemento da sequência, imprima \bbalert{\tt 4}.)}

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{101} };

+ \node at (1.5, 5) { \footnotesize \bbcomment{$K$} };
+ \draw[->,color=BBViolet] (1.5, 5.2) -- (1.5, 5.8);

- \node at (1.5, 5) { \footnotesize \bbcomment{$K$} };
- \draw[->,color=BBViolet] (1.5, 5.2) -- (1.5, 5.8);
+ \node[anchor=west] at (2, 5) { $\star\ \ 7 = 101\times 0 + 7$ };

+ \node[anchor=west] at (2, 4) { $\star\ \ 77 = 101\times 0 + 77$ };

+ \node[anchor=west] at (2, 3) { $\star\ \ 777 = 101\times 7 + 70$ };

+ \node[anchor=west] at (2, 2) { $\star\ \ \mathbf{7777 = 101\times 77 + 0}$ };

+ \draw[-latex,very thick] (2, 6) -- (2.9, 6);
+ \node[anchor=west] at (3.0, 6) { \bbinfo{4} };

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{2} };

+ \node[anchor=west] at (2, 5) { $\star\ \ 7 = 2\times 3 + 1$ };

+ \node[anchor=west] at (2, 4) { $\star\ \ 77 = 2\times 37 + 1$ };

+ \draw[-latex,color=BBViolet] (5.25, 4) to [bend right] (4.85, 5);

+ \draw[-latex,very thick] (1.6, 6) -- (2.5, 6);
+ \node[anchor=west] at (2.6, 6) { \bbalert{-1} };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Solução} };

+ \node[anchor=west] at (1, 6) { $\star$ \bbtext{Os restos da divisão dos elementos de $7, 77, 777, \ldots$ formam a sequência $x_i$,} };
+ \node[anchor=west] at (0.5, 5.5) { \bbtext{onde $x_0 = 0$ e} };
+ \node[anchor=west] at (4, 5) { $x_i = \Mod{10x_{i - 1} + 7}{K}, \ \ \ \ i = 1, 2, 3, \ldots$ };

+ \node[anchor=west] at (1, 4) { $\star$ \bbtext{Observe que $x_i$ depende apenas de $x_{i - 1}$ } };

+ \node[anchor=west] at (1, 3) { $\star$ \bbtext{Assim, se existir um $j > i > 0$ tal que $x_j = x_i$, a sequência se repetirá} };
+ \node[anchor=west] at (0.5, 2.5) { \bbtext{a partir deste ponto e a solução será \bbalert{-1}} };

+ \node[anchor=west] at (1, 1.5) { $\star$ \bbtext{Se $x_j = 0$ e $x_i \neq 0$ para $1 < i < j$, então a resposta é $j$ } };

## Frame
+ \inputsnippet{cpp}{10}{28}{codes/B174C.cpp}

## End
