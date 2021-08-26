## Frame
+ \bbcover{OJ 10000}{Longest Paths}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text
+ \bbenglish{It is a well known fact that some people do not have their social abilities completely enabled. One example is the lack of talent for calculating distances and intervals of time. This causes some people to always choose the longest way to go from one place to another, with the consequence that they are late to whatever appointments they have, including weddings and programming contests. This can be highly annoying for their friends.}
+
+ \vspace{0.2in}
+ 
+ \bbenglish{César has this kind of problem. When he has to go from one point to another he realizes that he has to visit many people, and thus always chooses the longest path. One of César’s friends, Felipe, has understood the nature of the problem. Felipe thinks that with the help of a computer he might be able to calculate the time that César is going to need to arrive to his destination. That way he could spend his time in something more enjoyable than waiting for César.}

## Text
+ \bbtext{É bem conhecido o fato que algumas pessoas não tem suas habilidades sociais plenamente desenvolvidas. Um exemplo é a falta de talento para calcular distâncias e intervalos de tempo. Isto faz com que algumas pessoas sempre escolham o caminho mais longo de um lugar a outro, e assim elas chegam atrasadas em quaisquer compromissos que elas tenham, incluindo casamentos e maratonas de programação. Este comportamento pode ser irritante para seus amigos.}
+
+ \vspace{0.2in}
+ 
+ \bbtext{César tem este tipo de problema. Quando ele precisa ir de um ponto ao outro ele entende que ele ainda tem que visitar muitas pessoas, e assim ele escolhe o caminho mais longo. Um dos amigos deCésar, Felipe, entendeu a natureza do problema. Felipe imagina que, com a a ajuda de um computador, ele será capaz de calcular o tempo que César levará para chegar ao seu destino. Deste modo ele poderá passasr seu tempo fazendo algo mais divertido do que ficar esperando por César.}

## Text
+ \bbenglish{Your goal is to help Felipe developing a program that computes the length of the longest path that can be constructed in a given graph from a given starting point (César’s residence). You can assume that there is at least one path from this starting point to any destination. Also, the graph has no cycles (there is no path from any node to itself), so César will reach his destination in a finite time. In the same line of reasoning, nodes are not considered directly connected to themselves.}

## Text
+ \bbtext{Seu objetivo é ajudar Felipe, escrevendo um programa que calcula o comprimento do maior caminho em um grafo a partir de um dado ponto de partida (a casa de César). Você pode assumir que há no mínimo um caminho do ponto de partida a qualquer destino e também que o grafo não tem ciclos (não há um caminho de qualquer nó a si mesmo), de modo que César chegará ao seu destino em um espaço de tempo finito. Na mesma linha de raciocínio, considere que um nó não esteja conectado a si mesmo.}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbenglish{The input consists of a number of cases. The first line on each case contains a positive number $n$ $(1 < n\leq 100)$ that specifies the number of points that César might visit (i.e., the number of nodes in the graph).}
+
+ \vspace{0.1in}
+
+ \bbenglish{A value of $n = 0$ indicates the end of the input.}
+
+ \vspace{0.1in}
+
+ \bbenglish{After this, a second number $s$ is provided, indicating the starting point in César’s journey $(1\leq s\leq n)$. Then, you are given a list of pairs of places $p$ and $q$, one pair per line, with the places on each line separated by white-space. The pair ``$p$ $q$'' indicates that César can visit $q$ after $p$.}

## Text
+ \bbbold{Entrada}
+
+ \vspace{0.1in}
+
+ \bbtext{A entrada é composta por uma série de casos de teste. A primeira linha de cada caso contém um inteiro positivo $n$ $(1 < n\leq 100)$ que indica o número de pontos que César pode visitar (isto é, o número de nós no grafo).}
+
+ \vspace{0.1in}
+
+ \bbtext{O valor $n = 0$ indica o fim da entrada.}
+
+ \vspace{0.1in}
+
+ \bbtext{A linha seguinte contém um inteiro $s$, indicando o ponto de partida da jornada de César $(1\leq s\leq n)$. Então, há uma lista de pares de localidades $p$ e $q$, um par por linha, com as localizações separadas por um espaço em branco. O par ``$p$ $q$'' indica que César pode visitar $q$ após $p$.}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbenglish{A pair of zeros (`\texttt{0 0}') indicates the end of the case.}
+
+ \vspace{0.1in}
+
+ \bbenglish{As mentioned before, you can assume that the graphs provided will not be cyclic and that every place will be reachable from the starting place.}
+
+ \vspace{0.2in}
+
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbenglish{For each test case you have to find the length of the longest path that begins at the starting place.  You also have to print the number of the final place of such longest path. If there are several paths of maximum length, print the final place with smallest number.}
+
+ \vspace{0.1in}
+
+ \bbenglish{Print a new line after each test case.}

## Text
+ \bbbold{Entrada}
+
+ \vspace{0.1in}
+
+ \bbtext{Um par de zeros (`\texttt{0 0}') indica o fim do caso de teste.}
+
+ \vspace{0.1in}
+
+ \bbtext{Como dito antes, você pode assumir que o grafo em questão não tem ciclos e que qualquer localidade pode ser alcançada saindo do ponto de partida.}
+
+ \vspace{0.2in}
+
+ \bbbold{Saída}
+
+ \vspace{0.1in}
+
+ \bbtext{Para cada caso de teste você deve determinar o comprimento do maior caminho que inicia no ponto de partida.  Você também deve imprimir o número da localidade que finaliza tal caminho. Se há vários caminhos de comprimento máximo, imprima a localização final de menor identificador. }
+
+ \vspace{0.1in}
+
+ \bbtext{Imprima uma nova linha após cada caso de teste.}

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{2} };

+ \node[anchor=west] at (2, 6) { \footnotesize \bbcomment{\# de localidades} };
+ \draw[->,color=BBViolet] (2.0, 6) -- (1.5, 6);

+ \node[draw,circle,very thick] (A) at (8, 4) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (11, 4) { \bbtext{2} };

- \node[anchor=west] at (2, 6) { \footnotesize \bbcomment{\# de localidades} };
- \draw[->,color=BBViolet] (2.0, 6) -- (1.5, 6);

+ \node[anchor=west] at (1, 5.5) { \bbtext{1} };

+ \node[anchor=west] at (2, 5.5) { \footnotesize \bbcomment{ponto de partida} };
+ \draw[->,color=BBViolet] (2.0, 5.5) -- (1.5, 5.5);

- \node[draw,circle,very thick] (A) at (8, 4) { \bbtext{1} };
+ \node[draw,circle,very thick,fill=BBGreen] (A) at (8, 4) { \bbtext{1} };

- \node[anchor=west] at (2, 5.5) { \footnotesize \bbcomment{ponto de partida} };
- \draw[->,color=BBViolet] (2.0, 5.5) -- (1.5, 5.5);

+ \node[anchor=west] at (1, 5) { \bbtext{1 2} };

+ \node[anchor=west] at (2.3, 5) { \footnotesize \bbcomment{conexão entre localidades} };
+ \draw[->,color=BBViolet] (2.3, 5) -- (1.8, 5);

+ \draw[-latex,thick] (A) to (B);

- \node[anchor=west] at (2.3, 5) { \footnotesize \bbcomment{conexão entre localidades} };
- \draw[->,color=BBViolet] (2.3, 5) -- (1.8, 5);

+ \node[anchor=west] at (1, 4.5) { \bbtext{0 0} };

+ \node[anchor=west] at (2.3, 4.5) { \footnotesize \bbcomment{fim do caso de teste} };
+ \draw[->,color=BBViolet] (2.3, 4.5) -- (1.8, 4.5);

- \node[anchor=west] at (2.3, 4.5) { \footnotesize \bbcomment{fim do caso de teste} };
- \draw[->,color=BBViolet] (2.3, 4.5) -- (1.8, 4.5);

- \node[draw,circle,very thick] (B) at (11, 4) { \bbtext{2} };
+ \node[draw,circle,very thick,fill=BBCyan] (B) at (11, 4) { \bbtext{2} };
- \draw[-latex,thick] (A) to (B);
+ \draw[-latex,thick,color=BBCyan] (A) to (B);

+ \draw[-latex,very thick] (1.4, 3.3) to (1.4, 4.3);
+ \node at (1.4, 3) { \bbinfo{1, 2} };

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{5} };

+ \node[draw,circle,very thick] (A) at (6, 4) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (9, 7) { \bbtext{2} };
+ \node[draw,circle,very thick] (C) at (12, 4) { \bbtext{3} };
+ \node[draw,circle,very thick] (D) at (12, 1) { \bbtext{4} };
+ \node[draw,circle,very thick] (E) at (6, 1) { \bbtext{5} };

+ \node[anchor=west] at (1, 5.5) { \bbtext{3} };

- \node[draw,circle,very thick] (C) at (12, 4) { \bbtext{3} };
+ \node[draw,circle,very thick,fill=BBGreen] (C) at (12, 4) { \bbtext{3} };

+ \node[anchor=west] at (1, 5.0) { \bbtext{1 2} };

+ \draw[-latex,thick] (A) to (B);

+ \node[anchor=west] at (1, 4.5) { \bbtext{3 5} };

+ \draw[-latex,thick] (C) to (E);

+ \node[anchor=west] at (1, 4.0) { \bbtext{3 1} };

+ \draw[-latex,thick] (C) to (A);

+ \node[anchor=west] at (1, 3.5) { \bbtext{2 4} };

+ \draw[-latex,thick] (B) to (D);

+ \node[anchor=west] at (1, 3.0) { \bbtext{4 5} };

+ \draw[-latex,thick] (D) to (E);

+ \node[anchor=west] at (1, 2.5) { \bbtext{0 0} };

- \draw[-latex,thick] (C) to (A);
+ \draw[-latex,thick,color=BBCyan] (C) to (A);
- \node[draw,circle,very thick] (A) at (6, 4) { \bbtext{1} };
+ \node[draw,circle,very thick,fill=BBCyan] (A) at (6, 4) { \bbtext{1} };

- \draw[-latex,thick,color=BBCyan] (C) to (A);
+ \draw[-latex,thick,color=BBViolet] (C) to (A);
- \draw[-latex,thick] (A) to (B);
+ \draw[-latex,thick,color=BBViolet] (A) to (B);
- \node[draw,circle,very thick] (B) at (9, 7) { \bbtext{2} };
+ \node[draw,circle,very thick,fill=BBViolet] (B) at (9, 7) { \bbtext{2} };

- \draw[-latex,thick,color=BBViolet] (C) to (A);
+ \draw[-latex,thick,color=BBOrange] (C) to (A);
- \draw[-latex,thick,color=BBViolet] (A) to (B);
+ \draw[-latex,thick,color=BBOrange] (A) to (B);
- \node[draw,circle,very thick] (D) at (12, 1) { \bbtext{4} };
+ \node[draw,circle,very thick,fill=BBOrange] (D) at (12, 1) { \bbtext{4} };
- \draw[-latex,thick] (B) to (D);
+ \draw[-latex,thick,color=BBOrange] (B) to (D);

- \draw[-latex,thick,color=BBOrange] (C) to (A);
+ \draw[-latex,thick,color=BBRed] (C) to (A);
- \draw[-latex,thick,color=BBOrange] (A) to (B);
+ \draw[-latex,thick,color=BBRed] (A) to (B);
- \draw[-latex,thick,color=BBOrange] (B) to (D);
+ \draw[-latex,thick,color=BBRed] (B) to (D);
- \draw[-latex,thick] (D) to (E);
+ \draw[-latex,thick,color=BBRed] (D) to (E);
- \node[draw,circle,very thick] (E) at (6, 1) { \bbtext{5} };
+ \node[draw,circle,very thick,fill=BBRed] (E) at (6, 1) { \bbtext{5} };

+ \draw[-latex,very thick] (1.4, 2.3) to (1.4, 1.3);
+ \node at (1.4, 1) { \bbinfo{4, 5} };

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{5} };

+ \node[draw,circle,very thick] (A) at (6, 4) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (9, 7) { \bbtext{2} };
+ \node[draw,circle,very thick] (C) at (12, 4) { \bbtext{3} };
+ \node[draw,circle,very thick] (D) at (12, 1) { \bbtext{4} };
+ \node[draw,circle,very thick] (E) at (6, 1) { \bbtext{5} };

+ \node[anchor=west] at (1, 5.5) { \bbtext{5} };

- \node[draw,circle,very thick] (E) at (6, 1) { \bbtext{5} };
+ \node[draw,circle,very thick,fill=BBGreen] (E) at (6, 1) { \bbtext{5} };

+ \node[anchor=west] at (1, 5.0) { \bbtext{5 1} };

+ \draw[-latex,thick] (E) to (A);

+ \node[anchor=west] at (1, 4.5) { \bbtext{5 2} };

+ \draw[-latex,thick] (E) to (B);

+ \node[anchor=west] at (1, 4.0) { \bbtext{5 3} };

+ \draw[-latex,thick] (E) to (C);

+ \node[anchor=west] at (1, 3.5) { \bbtext{5 4} };

+ \draw[-latex,thick] (E) to (D);

+ \node[anchor=west] at (1, 3.0) { \bbtext{4 1} };

+ \draw[-latex,thick] (D) to (A);

+ \node[anchor=west] at (1, 2.5) { \bbtext{4 2} };

+ \draw[-latex,thick] (D) to (B);

+ \node[anchor=west] at (1, 2.0) { \bbtext{0 0} };

- \node[draw,circle,very thick] (C) at (12, 4) { \bbtext{3} };
- \node[draw,circle,very thick] (D) at (12, 1) { \bbtext{4} };
+ \node[draw,circle,very thick,fill=BBCyan] (C) at (12, 4) { \bbtext{3} };
+ \node[draw,circle,very thick,fill=BBCyan] (D) at (12, 1) { \bbtext{4} };
- \draw[-latex,thick] (E) to (C);
- \draw[-latex,thick] (E) to (D);
+ \draw[-latex,thick,color=BBCyan] (E) to (C);
+ \draw[-latex,thick,color=BBCyan] (E) to (D);

- \node[draw,circle,very thick] (A) at (6, 4) { \bbtext{1} };
- \node[draw,circle,very thick] (B) at (9, 7) { \bbtext{2} };
+ \node[draw,circle,very thick,fill=BBViolet] (A) at (6, 4) { \bbtext{1} };
+ \node[draw,circle,very thick,fill=BBViolet] (B) at (9, 7) { \bbtext{2} };
- \draw[-latex,thick,color=BBCyan] (E) to (D);
+ \draw[-latex,thick,color=BBViolet] (E) to (D);
- \draw[-latex,thick] (D) to (B);
- \draw[-latex,thick] (D) to (A);
+ \draw[-latex,thick,color=BBViolet] (D) to (B);
+ \draw[-latex,thick,color=BBViolet] (D) to (A);

+ \draw[-latex,very thick] (1.4, 1.7) to (1.4, 0.7);
+ \node at (1.4, 0.5) { \bbinfo{2, 1} };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Solução} };

+ \node[anchor=west] at (0.5, 6) { $\star$ \bbtext{A BFS pode ser modificada para computar as distâncias máximas } };

+ \node[anchor=west] at (0.5, 5) { $\star$ \bbtext{Esta modificação, contudo, altera a complexidade da travessia} };

+ \node[anchor=west] at (0.5, 4) { $\star$ \bbtext{Isto porque um mesmo nó pode entrar até $N - 1$ vezes na fila } };

+ \node[anchor=west] at (0.5, 3) { $\star$ \bbtext{Assim complexidade no pior caso será $O(N^2)$} };

+ \node[anchor=west] at (0.5, 2) { $\star$ \bbtext{Se o grafo tiver ciclos, esta travessia modificada entrará em um laço infinito! } };

## Frame
+ \inputsnippet{cpp}{9}{28}{codes/10000.cpp}

## Frame
+ \inputsnippet{cpp}{30}{44}{codes/10000.cpp}

## End
