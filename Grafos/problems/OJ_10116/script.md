## Frame
+ \bbcover{OJ 10116}{Robot Motion}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text
+ \bbenglish{A robot has been programmed to follow the instructions in its path. Instructions for the next direction the robot is to move are laid down in a grid. The possible instructions are}
+
+ \vspace{0.1in}
+ 
+ \begin{description}
+ \item \bbenglish{\texttt{N} north (up the page)}
+ \item \bbenglish{\texttt{S} south (down the page)}
+ \item \bbenglish{\texttt{E} east (to the right on the page)}
+ \item \bbenglish{\texttt{W} west (to the left on the page)}
+ \end{description}
+
+ \vspace{0.1in}
+ 
+ \bbenglish{For example, suppose the robot starts on the north (top) side of Grid 1 and starts south (down).  The path the robot follows is shown. The robot goes through 10 instructions in the grid before leaving the grid.}

## Text
+ \bbtext{Um robo foi programado para seguir as instruções em seu caminho. A instrução para a próxima direção que o robô deve seguir está escrita em uma malha. As instruções possíveis são}
+
+ \vspace{0.1in}
+ 
+ \begin{description}
+ \item \bbtext{\texttt{N} norte (para cima)}
+ \item \bbtext{\texttt{S} sul (para baixo)}
+ \item \bbtext{\texttt{E} leste (para direita)}
+ \item \bbtext{\texttt{W} oeste (para esquerda)}
+ \end{description}
+
+ \vspace{0.1in}
+ 
+ \bbtext{Por exemplo, suponha que o robô inicie no lado norte (topo) da Malha 1 e siga para sul (baixo). O caminho que o robô segue está na figura. O robô segue 10 instruções na malha antes de deixá-la.}

## Scene
+ \node (A1) at (2, 6) { \bbtext{\huge \texttt{N}} };
+ \node (A2) at (4, 6) { \bbtext{\huge \texttt{E}} };
+ \node (A3) at (6, 6) { \bbtext{\huge \texttt{E}} };
+ \node (A4) at (8, 6) { \bbtext{\huge \texttt{S}} };
+ \node (A5) at (10, 6) { \bbtext{\huge \texttt{W}} };
+ \node (A6) at (12, 6) { \bbtext{\huge \texttt{E}} };
+ \node (B0) at (0.5, 4) { };
+ \node (B1) at (2, 4) { \bbtext{\huge \texttt{W}} };
+ \node (B2) at (4, 4) { \bbtext{\huge \texttt{W}} };
+ \node (B3) at (6, 4) { \bbtext{\huge \texttt{W}} };
+ \node (B4) at (8, 4) { \bbtext{\huge \texttt{E}} };
+ \node (B5) at (10, 4) { \bbtext{\huge \texttt{S}} };
+ \node (B6) at (12, 4) { \bbtext{\huge \texttt{S}} };
+ \node (C1) at (2, 2) { \bbtext{\huge \texttt{S}} };
+ \node (C2) at (4, 2) { \bbtext{\huge \texttt{N}} };
+ \node (C3) at (6, 2) { \bbtext{\huge \texttt{W}} };
+ \node (C4) at (8, 2) { \bbtext{\huge \texttt{W}} };
+ \node (C5) at (10, 2) { \bbtext{\huge \texttt{W}} };
+ \node (C6) at (12, 2) { \bbtext{\huge \texttt{W}} };
+ \node (D) at (7, 1) { \bbtext{Malha 1} };
+ \node (E) at (10, 7) { \LARGE \faAndroid };
+ \draw[-latex,very thick] (A5) to (A4);
+ \draw[-latex,very thick] (A4) to (B4);
+ \draw[-latex,very thick] (B4) to (B5);
+ \draw[-latex,very thick] (B5) to (C5);
+ \draw[-latex,very thick] (C5) to (C4);
+ \draw[-latex,very thick] (C4) to (C3);
+ \draw[-latex,very thick] (C3) to (C2);
+ \draw[-latex,very thick] (C2) to (B2);
+ \draw[-latex,very thick] (B2) to (B1);
+ \draw[-latex,very thick] (B1) to (B0);

## Scene
+ \node (A1) at (2, 7) { \bbtext{\huge \texttt{S}} };
+ \node (A2) at (4, 7) { \bbtext{\huge \texttt{E}} };
+ \node (A3) at (6, 7) { \bbtext{\huge \texttt{S}} };
+ \node (A4) at (8, 7) { \bbtext{\huge \texttt{W}} };
+ \node (A5) at (10, 7) { \bbtext{\huge \texttt{E}} };
+ \node (B1) at (2, 5) { \bbtext{\huge \texttt{E}} };
+ \node (B2) at (4, 5) { \bbtext{\huge \texttt{E}} };
+ \node (B3) at (6, 5) { \bbtext{\huge \texttt{S}} };
+ \node (B4) at (8, 5) { \bbtext{\huge \texttt{N}} };
+ \node (B5) at (10, 5) { \bbtext{\huge \texttt{W}} };
+ \node (C1) at (2, 3) { \bbtext{\huge \texttt{N}} };
+ \node (C2) at (4, 3) { \bbtext{\huge \texttt{W}} };
+ \node (C3) at (6, 3) { \bbtext{\huge \texttt{E}} };
+ \node (C4) at (8, 3) { \bbtext{\huge \texttt{E}} };
+ \node (C5) at (10, 3) { \bbtext{\huge \texttt{N}} };
+ \node (D1) at (2, 1) { \bbtext{\huge \texttt{E}} };
+ \node (D2) at (4, 1) { \bbtext{\huge \texttt{W}} };
+ \node (D3) at (6, 1) { \bbtext{\huge \texttt{S}} };
+ \node (D4) at (8, 1) { \bbtext{\huge \texttt{E}} };
+ \node (D5) at (10, 1) { \bbtext{\huge \texttt{N}} };
+ \node[anchor=west] at (12, 4) { \bbtext{Malha 2} };
+ \node at (2, 8) { \LARGE \faAndroid };
+ \draw[-latex,very thick] (A1) to (B1);
+ \draw[-latex,very thick] (B1) to (B2);
+ \draw[-latex,very thick] (B2) to (B3);
+ \draw[-latex,very thick] (B3) to (C3);
+ \draw[-latex,very thick] (C3) to (C4);
+ \draw[-latex,very thick] (C4) to (C5);
+ \draw[-latex,very thick] (C5) to (B5);
+ \draw[-latex,very thick] (B5) to (B4);
+ \draw[-latex,very thick] (B4) to (A4);
+ \draw[-latex,very thick] (A4) to (A3);
+ \draw[-latex,very thick] (A3) to (B3);

## Text
+ \bbenglish{Compare what happens in Grid 2: the robot goes through 3 instructions only once, and then starts a loop through 8 instructions, and never exits.}
+
+ \vspace{0.1in}
+ 
+ \bbenglish{You are to write a program that determines how long it takes a robot to get out of the grid or how the robot loops around.}

## Text
+ \bbtext{Compare com o que acontece na Malha 2: o robô segue 3 instruções uma única vez, e então inicia um laço de 8 instruções, e nunca abandona a malha.}
+
+ \vspace{0.1in}
+ 
+ \bbtext{Você deve escrever um programa que determina quantas instruções o robô segue antes de sair da malha ou a forma que o robô entra em um laço infinito.}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbenglish{There will be one or more grids for robots to navigate. The data for each is in the following form.  On the first line are three integers separated by blanks: the number of rows in the grid, the number of columns in the grid, and the number of the column in which the robot enters from the north. The possible entry columns are numbered starting with one at the left. Then come the rows of the direction instructions. Each grid will have at least one and at most $10$ rows and columns of instructions. The lines of instructions contain only the characters \texttt{N}, \texttt{S}, \texttt{E}, or \texttt{W} with no blanks.}
+
+ \vspace{0.1in}
+
+ \bbenglish{The end of input is indicated by a row containing \texttt{0 0 0}.}

## Text
+ \bbbold{Entrada}
+
+ \vspace{0.1in}
+
+ \bbtext{Haverão uma ou mais malhas para o robô caminhar. As informações para cada malha seguem o seguinte formato.  Na primeira linha há três inteiros separados por um espaço em branco: o número de linhas da malha, o número de colunas da malha e o número da coluna na qual o robô entra na malha a partir do topo. As possíveis colunas de entrada são numeradas a partir de um da esquerda para a direita. Então seguem as linhas com as instruções de direção. Cada malha terá no mínimo uma e no máximo $10$ linhas e colunas de instruções. As linhas e instruções contém apenas os caracteres \texttt{N}, \texttt{S}, \texttt{E}, ou \texttt{W} sem espaços em branco.}
+
+ \vspace{0.1in}
+
+ \bbtext{O fim da entrada é indicado por um linha contendo \texttt{0 0 0}.}

## Text
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbenglish{For each grid in the input there is one line of output. Either the robot follows a certain number of instructions and exits the grid on any one the four sides or else the robot follows the instructions on a certain number of locations once, and then the instructions on some number of locations repeatedly.  The sample input below corresponds to the two grids above and illustrates the two forms of output.  The word ``\texttt{step}'' is always immediately followed by ``\texttt{(s)}'' whether or not the number before it is $1$.}

## Text
+ \bbbold{Saída}
+
+ \vspace{0.1in}
+
+ \bbtext{Para cada malha da entrada deve haver uma linha na saída. Ou o robô segue um certo número de instruções e deixa a malha por qualquer um dos quatro lados ou o robô segue um certo número de instruções uma única vez e então segue um certo número de instruções repetidamente. O exemplo abaixo corresponde as malhas apresentadas acima e ilustra os dois formatos da saída. A palavra ``\texttt{step}'' é sempre imediatamente seguida por ``\texttt{(s)}'' independetemente se o número que a antecede é $1$ ou não.}

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6.0) { \bbtext{\texttt{3 6 5}} };
+ \node[anchor=west] at (1, 5.5) { \bbtext{\texttt{NEESWE}} };
+ \node[anchor=west] at (1, 5.0) { \bbtext{\texttt{WWWESS}} };
+ \node[anchor=west] at (1, 4.5) { \bbtext{\texttt{SNWWWW}} };
+ \node[anchor=west] at (1, 4.0) { \bbtext{\texttt{4 5 1}} };
+ \node[anchor=west] at (1, 3.5) { \bbtext{\texttt{SESWE}} };
+ \node[anchor=west] at (1, 3.0) { \bbtext{\texttt{EESNW}} };
+ \node[anchor=west] at (1, 2.5) { \bbtext{\texttt{NWEEN}} };
+ \node[anchor=west] at (1, 2.0) { \bbtext{\texttt{EWSEN}} };
+ \node[anchor=west] at (1, 1.5) { \bbtext{\texttt{0 0 0}} };

+ \draw[-latex,very thick] (3, 5.25) to (4.2, 5.25);
+ \node[anchor=west] at (4.5, 5.25) { \bbinfo{\texttt{10 step(s) to exit} } };

+ \draw[-latex,very thick] (3, 3) to (4.2, 3);
+ \node[anchor=west] at (4.5, 3) { \bbinfo{\texttt{3 step(s) before a loop of 8 step(s)} } };

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Solução} };

+ \node[anchor=west] at (1, 6) { $\star$ \bbtext{O grau de saída de cada vértice é igual a $1$} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{A medida que a travessia avança, deve ser registrada a distância do vértice} };
+ \node[anchor=west] at (0.5, 4.5) { \bbtext{atual e o ponto de partida do robô } };

+ \node[anchor=west] at (1, 3.5) { $\star$ \bbtext{Caso o robô abandone a malha, a saída será o número de passos } };

+ \node[anchor=west] at (1, 2.5) { $\star$ \bbtext{Se a travessia atingir um nó da malha já visitado, o robô entrará em \bbenglish{loop} } };

## Frame
+ \inputsnippet{cpp}{11}{30}{codes/10116.cpp}

# End
