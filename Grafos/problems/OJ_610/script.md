## Frame
+ \bbcover{OJ 610}{Street Directions}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text
+ \bbenglish{According to the Automobile Collision Monitor (ACM), most fatal traffic accidents occur on twoway streets. In order to reduce the number of fatalities caused by traffic accidents, the mayor wants to convert as many streets as possible into one-way streets. You have been hired to perform this conversion, so that from each intersection, it is possible for a motorist to drive to all the other intersections following some route.}
+
+ \vspace{0.2in}
+ 
+ \bbenglish{You will be given a list of streets (all two-way) of the city. Each street connects two intersections, and does not go through an intersection. At most four streets meet at each intersection, and there is at most one street connecting any pair of intersections. It is possible for an intersection to be the end point of only one street. You may assume that it is possible for a motorist to drive from each destination to any other destination when every street is a two-way street.}

## Text
+ \bbtext{De acordo com o Automobile Collision Monitor (ACM), a maioria dos acidentes fatais de transito acontecem em vias de mão dupla. Para reduzir o número de fatalidades causadas por acidentes de trânsito, o prefeito quer tornar tantas vias quanto possíveis em vias de mão única. Você foi contratado para esta tarefa, de modo que, para cada interseção entre vias, os motoristas serão capazes de chegar a todas demais interseções por alguma rota.}
+
+ \vspace{0.2in}
+ 
+ \bbtext{Você irá receber uma lista de vias (todas de mão dupla) da cidade. Cada via conecta duas interseções, e não atravessa nenhuma interseção. No máximo quatro vias atingem cada interseção, e há no máximo uma via conectando qualquer par de interseções. É possível que uma interseção serja o ponto final de uma única via. Você pode assumir que é possível para um motorista ir a qualquer interseção a partir de qualquer interseção quando todas as vias são de mão dupla.}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbenglish{The input consists of a number of cases. The first line of each case contains two integers $n$ and $m$. The number of intersections is $n$ $(2\leq n\leq 1000)$, and the number of streets is $m$. The next $m$ lines contain the intersections incident to each of the $m$ streets. The intersections are numbered from $1$ to $n$, and each street is listed once. If the pair $i$ $j$ is present, $j$ $i$ will not be present. End of input is indicated by $n = m = 0$.}

## Text
+ \bbbold{Entrada}
+
+ \vspace{0.1in}
+
+ \bbtext{A entrada é composta por uma série de casos de teste. A primeira linha de cada caso de teste contém dois inteiros $n$ e $m$. O número de interseções é $n$ $(2\leq n\leq 1000)$, e o número de vias é $m$. As próximas $m$ linhas contém as interseções conectadas por cada uma das $m$ vias. As interseções são numeradas de $1$ a $n$, e cada via é lista uma única vez. Se o par $i$ $j$ está presente, $j$ $i$ não estará. O fim da entrada é indicado por $n = m = 0$.}

## Text
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbenglish{For each case, print the case number (starting from $1$) followed by a blank line. Next, print on separate lines each street as the pair $i$ $j$ to indicate that the street has been assigned the direction going from intersection $i$ to intersection $j$. For a street that cannot be converted into a one-way street, print both $i$ $j$ and $j$ $i$ on two different lines. The list of streets can be printed in any order. Terminate each case with a line containing a single `\texttt{\#}' character.}
+
+ \vspace{0.2in}
+
+ \bbenglish{\bbbold{Note}: There may be many possible direction assignments satisfying the requirements. Any such assignment is acceptable.}

## Text
+ \bbbold{Saída}
+
+ \vspace{0.1in}
+
+ \bbtext{Para cada caso de teste, imprima o número do caso (começando em $1$) seguido de uma linha em branco. Em seguida, imprima em linhas separadas cada via como um par $i$ $j$, indicando que foi atribuído à via o sentido que parte da interseção $i$ para a interseção $j$. Se uma via não puder ser convertida para uma via de mão única, imprima ambos $i$ $j$ e $j$ $i$ em duas linhas diferentes. A lista de vias pode ser impressa em qualquer ordem. Finalize cada caso com uma linha contendo o caractere `\texttt{\#}'.}
+
+ \vspace{0.2in}
+
+ \bbtext{\bbbold{Nota}: Há muitas maneiras distintas de atribuição das vias que satisfazem os requisitos. Qualquer uma delas é aceitável.}

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{7 10} };

+ \node[anchor=west] at (0.5, 5) { \footnotesize \bbcomment{\# de interseções} };
+ \draw[->,color=BBViolet] (1.25, 5.2) -- (1.25, 5.8);

+ \node[anchor=west] at (2.9, 6) { \footnotesize \bbcomment{\# de vias} };
+ \draw[->,color=BBViolet] (2.0, 6) -- (2.8, 6);

- \node[anchor=west] at (0.5, 5) { \footnotesize \bbcomment{\# de interseções} };
- \draw[->,color=BBViolet] (1.25, 5.2) -- (1.25, 5.8);
- \node[anchor=west] at (2.9, 6) { \footnotesize \bbcomment{\# de vias} };
- \draw[->,color=BBViolet] (2.0, 6) -- (2.8, 6);
+ \node[circle,draw,very thick] (A) at (6, 4) { \bbtext{1} };
+ \node[circle,draw,very thick] (B) at (8, 6) { \bbtext{2} };
+ \node[circle,draw,very thick] (C) at (10, 6) { \bbtext{3} };
+ \node[circle,draw,very thick] (D) at (12, 6) { \bbtext{4} };
+ \node[circle,draw,very thick] (E) at (12, 2) { \bbtext{5} };
+ \node[circle,draw,very thick] (F) at (10, 2) { \bbtext{6} };
+ \node[circle,draw,very thick] (G) at (8, 2) { \bbtext{7} };

+ \node[anchor=west] at (1, 5.5) { \bbtext{1 2} };

+ \draw[thick] (A) to (B);

+ \node[anchor=west] at (1, 5.0) { \bbtext{1 3} };

+ \draw[thick] (A) to (C);

+ \node[anchor=west] at (1, 4.5) { \bbtext{2 4} };

+ \draw[thick] (B) to [bend left] (D);

+ \node[anchor=west] at (1, 4.0) { \bbtext{3 4} };

+ \draw[thick] (C) to (D);

+ \node[anchor=west] at (1, 3.5) { \bbtext{4 5} };

+ \draw[thick] (D) to (E);

+ \node[anchor=west] at (1, 3.0) { \bbtext{4 6} };

+ \draw[thick] (D) to (F);

+ \node[anchor=west] at (1, 2.5) { \bbtext{5 7} };

+ \draw[thick] (E) to [bend left] (G);

+ \node[anchor=west] at (1, 2.0) { \bbtext{6 7} };

+ \draw[thick] (F) to (G);

+ \node[anchor=west] at (1, 1.5) { \bbtext{2 5} };

+ \draw[thick] (B) to (E);

+ \node[anchor=west] at (1, 1.0) { \bbtext{3 6} };

+ \draw[thick] (C) to (F);

- \draw[thick] (A) to (B);
+ \draw[-latex,color=BBOrange,very thick] (A) to (B);

- \draw[thick] (B) to [bend left] (D);
+ \draw[-latex,color=BBOrange,very thick] (B) to [bend left] (D);

- \draw[thick] (C) to (D);
+ \draw[-latex,color=BBOrange,very thick] (D) to (C);

- \draw[thick] (A) to (C);
+ \draw[-latex,color=BBOrange,very thick] (C) to (A);

- \draw[thick] (C) to (F);
+ \draw[-latex,color=BBOrange,very thick] (C) to (F);

- \draw[thick] (D) to (F);
+ \draw[-latex,color=BBOrange,very thick] (F) to (D);

- \draw[thick] (D) to (E);
+ \draw[-latex,color=BBOrange,very thick] (D) to (E);

- \draw[thick] (B) to (E);
+ \draw[-latex,color=BBOrange,very thick] (E) to (B);

- \draw[thick] (E) to [bend left] (G);
+ \draw[-latex,color=BBOrange,very thick] (E) to [bend left] (G);

- \draw[thick] (F) to (G);
+ \draw[-latex,color=BBOrange,very thick] (G) to (F);

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{7 9} };

+ \node[circle,draw,very thick] (A) at (6, 4) { \bbtext{1} };
+ \node[circle,draw,very thick] (B) at (8, 6) { \bbtext{2} };
+ \node[circle,draw,very thick] (C) at (10, 6) { \bbtext{3} };
+ \node[circle,draw,very thick] (D) at (12, 6) { \bbtext{4} };
+ \node[circle,draw,very thick] (E) at (12, 2) { \bbtext{5} };
+ \node[circle,draw,very thick] (F) at (10, 2) { \bbtext{6} };
+ \node[circle,draw,very thick] (G) at (8, 2) { \bbtext{7} };

+ \node[anchor=west] at (1, 5.5) { \bbtext{1 2} };

+ \draw[thick] (A) to (B);

+ \node[anchor=west] at (1, 5.0) { \bbtext{1 3} };

+ \draw[thick] (A) to (C);

+ \node[anchor=west] at (1, 4.5) { \bbtext{1 4} };

+ \draw[thick] (A) to (D);

+ \node[anchor=west] at (1, 4.0) { \bbtext{2 4} };

+ \draw[thick] (B) to [bend left] (D);

+ \node[anchor=west] at (1, 3.5) { \bbtext{3 4} };

+ \draw[thick] (C) to (D);

+ \node[anchor=west] at (1, 3.0) { \bbtext{4 5} };

+ \draw[thick] (D) to (E);

+ \node[anchor=west] at (1, 2.5) { \bbtext{5 6} };

+ \draw[thick] (E) to (F);

+ \node[anchor=west] at (1, 2.0) { \bbtext{5 7} };

+ \draw[thick] (E) to [bend left] (G);

+ \node[anchor=west] at (1, 1.5) { \bbtext{7 6} };

+ \draw[thick] (F) to (G);

- \draw[thick] (A) to (B);
+ \draw[-latex,color=BBOrange,very thick] (A) to (B);

- \draw[thick] (B) to [bend left] (D);
+ \draw[-latex,color=BBOrange,very thick] (B) to [bend left] (D);

- \draw[thick] (C) to (D);
+ \draw[-latex,color=BBOrange,very thick] (D) to (C);

- \draw[thick] (A) to (C);
+ \draw[-latex,color=BBOrange,very thick] (C) to (A);

- \draw[thick] (A) to (D);
+ \draw[-latex,color=BBOrange,very thick] (D) to (A);

- \draw[thick] (D) to (E);
+ \draw[-latex,color=BBOrange,very thick] (D) to [bend left] (E);
+ \draw[-latex,color=BBOrange,very thick] (E) to [bend left] (D);

- \draw[thick] (E) to (F);
+ \draw[-latex,color=BBOrange,very thick] (E) to (F);

- \draw[thick] (F) to (G);
+ \draw[-latex,color=BBOrange,very thick] (F) to (G);

- \draw[thick] (E) to [bend left] (G);
+ \draw[-latex,color=BBOrange,very thick] (G) to [bend right] (E);

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Solução} };

+ \node[anchor=west] at (0.5, 5) { $\star$ \bbtext{Se a exclusão de uma via não desconecta do grafo, ela pode ser de mão única} };

+ \node[anchor=west] at (0.5, 4) { $\star$ \bbtext{O sentido da mão única pode ser obtido por meio de uma DFS } };

+ \node[anchor=west] at (0.5, 3) { $\star$ \bbtext{As pontes devem preservar a mão dupla} };

## Frame
+ \inputsnippet{cpp}{11}{30}{codes/610.cpp}

## Frame
+ \inputsnippet{cpp}{32}{44}{codes/610.cpp}

## End
