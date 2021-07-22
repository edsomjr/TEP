## Frame
+ \bbcover{AtCoder Beginner Contest 143}{Problem E: Travel by Car}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text
+ \bbenglish{There are $N$ towns numbered $1$ to $N$ and $M$ roads. The $i$-th road connects Town $A_i$ and Town $B_i$ bidirectionally and has a length of $C_i$.}
+
+ \vspace{0.1in}
+ 
+ \bbenglish{Takahashi will travel between these towns by car, passing through these roads. The fuel tank of his car can contain at most $L$ liters of fuel, and one liter of fuel is consumed for each unit distance traveled. When visiting a town while traveling, he can full the tank (or choose not to do so). Travel that results in the tank becoming empty halfway on the road cannot be done.}
+
+ \vspace{0.1in}
+ 
+ \bbenglish{Process the following $Q$ queries: \begin{itemize} \item \bbenglish{The tank is now full. Find the minimum number of times he needs to full his tank while traveling from Town $s_i$ to Town $t_i$. If Town $t_i$ is unreachable, print $−1$.} \end{itemize}}

## Text
+ \bbtext{Há $N$ cidades numeradas de $1$ a $N$ e $M$ estradas. A $i$-ésima estrada conecta a Cidade $A_i$ à Cidade $B_i$ bidirecionalmente e tem comprimento $C_i$.}
+
+ \vspace{0.1in}
+ 
+ \bbtext{Takahashi irá viajar de carro entre estas cidades, passando por estas estradas. O tanque de gasolina de seu carro por conter, no máximo, $L$ litros de gasolina, e um litro de gasolina é consumido para cada unidade de distância viajada. Quando ele visita uma cidade, ele pode encher seu tanque (ou escolher não o fazê-lo). Viagens nas quais o tanque se esvazia ao longo de uma estrada não podem ser feitas.}
+
+ \vspace{0.1in}
+ 
+ \bbtext{Responda às seguintes $Q$ consultas: \begin{itemize} \item \bbtext{O tanque está cheio. Encontre o número mínimo de vezes que ele precisará encher o tanque para viajar da Cidade $s_i$ para a Cidade $t_i$. Se a Cidade $t_i$ é inatingível, imprima $−1$.} \end{itemize}}

## Text
+ \bbbold{Constraints}
+
+ \vspace{0.1in}
+
+ \begin{footnotesize}
+ \begin{itemize}
+ \item \bbenglish{All values in input are integers.}
+ \item $2\leq N\leq 300$
+ \item $0\leq M \leq \frac{N(N - 1)}{2}$
+ \item $1\leq L\leq 10^9$
+ \item $\leq A_i, B_i\leq N$
+ \item $A_i\neq B_i$
+ \item $(A_i, B_i)\neq (A_j, B_j)$ \bbenglish{(if $i\neq j$)}
+ \item $(A_i, B_i)\neq (B_j, A_j)$ \bbenglish{(if $i\neq j$)}
+ \item $1\leq C_i\leq 10^9$
+ \item $1\leq Q\leq N(N - 1)$
+ \item $1\leq s_i, t_i\leq N$
+ \item $s_i\neq t_i$
+ \item $(s_i, t_i)\neq (s_j, t_j)$ \bbenglish{(if $i\neq j$)}
+ \end{itemize}
+ \end{footnotesize}

## Text
+ \bbbold{Restrições}
+
+ \vspace{0.1in}
+
+ \begin{footnotesize}
+ \begin{itemize}
+ \item \bbtext{Todos os valores da entrada são inteiros.}
+ \item $2\leq N\leq 300$
+ \item $0\leq M \leq \frac{N(N - 1)}{2}$
+ \item $1\leq L\leq 10^9$
+ \item $\leq A_i, B_i\leq N$
+ \item $A_i\neq B_i$
+ \item $(A_i, B_i)\neq (A_j, B_j)$ \bbtext{(se $i\neq j$)}
+ \item $(A_i, B_i)\neq (B_j, A_j)$ \bbtext{(se $i\neq j$)}
+ \item $1\leq C_i\leq 10^9$
+ \item $1\leq Q\leq N(N - 1)$
+ \item $1\leq s_i, t_i\leq N$
+ \item $s_i\neq t_i$
+ \item $(s_i, t_i)\neq (s_j, t_j)$ \bbtext{(se $i\neq j$)}
+ \end{itemize}
+ \end{footnotesize}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbenglish{Input is given from Standard Input in the following format:}
+ \[
+ \begin{matrix}
+      N & M & L \\
+      A_1 & B_1 & C_1 \\
+      \vdots \\
+      A_M & B_M & C_M \\
+      Q \\
+      s_1 & t_1 \\
+      \vdots \\
+      s_Q & t_Q
+ \end{matrix}
+ \]

## Text
+ \bbbold{Entrada}
+
+ \vspace{0.1in}
+
+ \bbtext{A entrada é dada na Entrada Padrão no seguinte formato:}
+ \[
+ \begin{matrix}
+      N & M & L \\
+      A_1 & B_1 & C_1 \\
+      \vdots \\
+      A_M & B_M & C_M \\
+      Q \\
+      s_1 & t_1 \\
+      \vdots \\
+      s_Q & t_Q
+ \end{matrix}
+ \]

## Text
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbenglish{Print $Q$ lines.}
+
+ \vspace{0.1in}
+
+ \bbenglish{The $i$-th line should contain the minimum number of times the tank needs to be fulled while traveling from Town $s_i$ to Town $t_i$. If Town $t_i$ is unreachable, the line should contain $-1$ instead.}

## Text
+ \bbbold{Saída}
+
+ \vspace{0.1in}
+
+ \bbtext{Imprima $Q$ linhas.}
+
+ \vspace{0.1in}
+
+ \bbtext{A $i$-ésima linha deve conter o número mínimo de vezes que o tanque tem que ser reabastecido para se viajar da Cidade $s_i$ para a Cidade $t_i$. Se a Cidade $t_i$ é inatingível, imprima o número $-1$.}

## Scene
+ \node[anchor=west] at (0, 7.5) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6.5) { \bbtext{3 2 5} };

+ \node at (1.25, 4.9) { \footnotesize \bbcomment{\# de cidades} };
+ \draw[->,color=BBViolet] (1.25, 6.2) -- (1.25, 5.2);

+ \node[draw,very thick,circle] (A) at (6, 4) { \bbtext{1} };
+ \node[draw,very thick,circle] (B) at (9, 7) { \bbtext{2} };
+ \node[draw,very thick,circle] (C) at (12, 2) { \bbtext{3} };

- \node at (1.25, 4.9) { \footnotesize \bbcomment{\# de cidades} };
- \draw[->,color=BBViolet] (1.25, 6.2) -- (1.25, 5.2);
+ \node at (1.55, 4.9) { \footnotesize \bbcomment{\# de estradas} };
+ \draw[->,color=BBViolet] (1.55, 6.2) -- (1.55, 5.2);

- \node at (1.55, 4.9) { \footnotesize \bbcomment{\# de estradas} };
- \draw[->,color=BBViolet] (1.55, 6.2) -- (1.55, 5.2);
+ \node at (1.85, 4.9) { \footnotesize \bbcomment{capacidade do tanque} };
+ \draw[->,color=BBViolet] (1.85, 6.2) -- (1.85, 5.2);

- \node at (1.85, 4.9) { \footnotesize \bbcomment{capacidade do tanque} };
- \draw[->,color=BBViolet] (1.85, 6.2) -- (1.85, 5.2);
+ \node[anchor=west] at (1, 6.0) { \bbtext{1 2 3} };
+ \draw[thick] (A) to node[above left] { \bbinfo{3} } (B);

+ \node[anchor=west] at (1, 5.5) { \bbtext{2 3 3} };

+ \draw[thick] (B) to node[above right] { \bbinfo{3} } (C);

+ \node[anchor=west] at (1, 5.0) { \bbtext{2} };

+ \node at (1.25, 3.4) { \footnotesize \bbcomment{\# de consultas} };
+ \draw[->,color=BBViolet] (1.25, 4.7) -- (1.25, 3.7);

- \node at (1.25, 3.4) { \footnotesize \bbcomment{\# de consultas} };
- \draw[->,color=BBViolet] (1.25, 4.7) -- (1.25, 3.7);
+ \node[anchor=west] at (1, 4.5) { \bbtext{3 2} };

- \node[draw,very thick,circle] (B) at (9, 7) { \bbtext{2} };
+ \node[draw,very thick,circle] (B) at (9, 7) { \footnotesize \faFlagCheckered };
- \node[draw,very thick,circle] (C) at (12, 2) { \bbtext{3} };
+ \node[draw,very thick,circle] (C) at (12, 2) { \footnotesize \faCar };
- \draw[thick] (B) to node[above right] { \bbinfo{3} } (C);
+ \draw[thick] (B) to node[above right] { \bbinfo{3} } (C);

- \draw[thick] (B) to node[above right] { \bbinfo{3} } (C);
+ \draw[latex-,color=BBCyan,very thick] (B) to node[above right] { \bbinfo{3} } (C);

+ \node at (1.4, 2.9) { \bbinfo{0} };
+ \draw[-latex,very thick] (1.4, 4.2) -- (1.4, 3.2);

- \draw[latex-,color=BBCyan,very thick] (B) to node[above right] { \bbinfo{3} } (C);
+ \draw[thick] (B) to node[above right] { \bbinfo{3} } (C);
- \node at (1.4, 2.9) { \bbinfo{0} };
- \draw[-latex,very thick] (1.4, 4.2) -- (1.4, 3.2);
+ \node[anchor=west] at (1, 4.0) { \bbtext{1 3} };
- \node[draw,very thick,circle] (B) at (9, 7) { \footnotesize \faFlagCheckered };
+ \node[draw,very thick,circle] (B) at (9, 7) { \bbtext{2} };
- \node[draw,very thick,circle] (C) at (12, 2) { \footnotesize \faCar };
+ \node[draw,very thick,circle] (C) at (12, 2) { \bbtext{3} };
- \draw[thick] (B) to node[above right] { \bbinfo{3} } (C);
+ \draw[thick] (B) to node[above right] { \bbinfo{3} } (C);
- \draw[thick] (A) to node[above left] { \bbinfo{3} } (B);
+ \draw[thick] (A) to node[above left] { \bbinfo{3} } (B);

- \node[draw,very thick,circle] (A) at (6, 4) { \bbtext{1} };
+ \node[draw,very thick,circle] (A) at (6, 4) { \footnotesize \faCar };
- \node[draw,very thick,circle] (C) at (12, 2) { \bbtext{3} };
+ \node[draw,very thick,circle] (C) at (12, 2) { \footnotesize \faFlagCheckered };
- \draw[thick] (B) to node[above right] { \bbinfo{3} } (C);
+ \draw[thick] (B) to node[above right] { \bbinfo{3} } (C);
- \draw[thick] (A) to node[above left] { \bbinfo{3} } (B);
+ \draw[thick] (A) to node[above left] { \bbinfo{3} } (B);

- \draw[thick] (A) to node[above left] { \bbinfo{3} } (B);
+ \draw[-latex,color=BBCyan,very thick] (A) to node[above left] { \bbinfo{3} } (B);

+ \node at (10, 7) { \includegraphics[scale=0.04]{figs/gas-station.png} };

- \draw[thick] (B) to node[above right] { \bbinfo{3} } (C);
+ \draw[-latex,color=BBCyan,very thick] (B) to node[above right] { \bbinfo{3} } (C);

+ \node at (1.4, 2.4) { \bbinfo{1} };
+ \draw[-latex,very thick] (1.4, 3.7) -- (1.4, 2.7);

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Solução} };

+ \node[anchor=west] at (0.5, 6) { $\star$ \bbtext{É possível pré-computar todos os caminhos possíveis usando Dijkstra} };

+ \node[anchor=west] at (0.5, 5) { $\star$ \bbtext{Na fila de prioridades devem ser inseridas a distância e a gasolina restante } };

+ \node[anchor=west] at (0.5, 4) { $\star$ \bbtext{A ordenação deve ser: menor distância, maior gasolina restante } };

+ \node[anchor=west] at (0.5, 3) { $\star$ \bbtext{O relaxamento deve ser feito também para distâncias iguais, porém com } };
+ \node[anchor=west] at (0, 2.5) { \bbtext{mais gasolina restante } };

+ \node[anchor=west] at (0.5, 1.5) { $\star$ \bbtext{Pré-computados os caminhos, cada consulta pode ser respondida em $O(1)$ } };

## Frame
+ \inputsnippet{cpp}{17}{36}{codes/B143E.cpp}

## Frame
+ \inputsnippet{cpp}{38}{57}{codes/B143E.cpp}

## Frame
+ \inputsnippet{cpp}{59}{73}{codes/B143E.cpp}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Créditos} };
+ \node[anchor=west] at (1, 5) { \bbtext{Gas station icon made by Kiranshastry from \bbenglish{www.flaticon.com} } };

## End
