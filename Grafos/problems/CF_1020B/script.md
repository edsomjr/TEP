## Frame
+ \bbcover{Codeforces Round \#503 (Div. 2)}{Problem B -- Badge}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text
+ \bbenglish{In Summer Informatics School, if a student doesn't behave well, teachers make a hole in his badge. And today one of the teachers caught a group of $n$ students doing yet another trick.}
+
+ \vspace{0.2in}
+ 
+ \bbenglish{Let's assume that all these students are numbered from $1$ to $n$. The teacher came to student $a$ and put a hole in his badge. The student, however, claimed that the main culprit is some other student $p_a$.}
+
+ \vspace{0.2in}
+ 
+ \bbenglish{After that, the teacher came to student $p_a$ and made a hole in his badge as well. The student in reply said that the main culprit was student $p_{p_a}$}.

## Text
+ \bbtext{Na Escola de Verão de Informática, se um estudante não se comporta bem, os professores fazem um furo em sua insígnia. Hoje um dos professores flagrou um grupo de $n$ estudantes fazendo outra travessura.}
+
+ \vspace{0.2in}
+ 
+ \bbtext{Assuma que os estudantes estão numerados de $1$ a $n$. O professor foi ao estudante $a$ e furou sua insígnia. O estudante, porém, afirmou que o principal culpado é algum outro estudante $p_a$.}
+
+ \vspace{0.2in}
+ 
+ \bbtext{Após isso, o professor foi ao estudante $p_a$ e furou sua insígnia também. Em resposta o estudante disse que o culpado foi o estudante $p_{p_a}$}.

## Text
+ \bbenglish{This process went on for a while, but, since the number of students was finite, eventually the teacher came to the student, who already had a hole in his badge.}
+
+ \vspace{0.2in}
+ 
+ \bbenglish{After that, the teacher put a second hole in the student's badge and decided that he is done with this process, and went to the sauna.}
+
+ \vspace{0.2in}
+ 
+ \bbenglish{You don't know the first student who was caught by the teacher. However, you know all the numbers $p_i$. Your task is to find out for every student $a$, who would be the student with two holes in the badge if the first caught student was $a$.}

## Text
+ \bbtext{Este processo continou mas, como o número de estudantes é finito, em algum momento o professor chegou em um estudante que já tinha um furo em sua insígnia.}
+
+ \vspace{0.2in}
+ 
+ \bbtext{Após isso, o professor fez um segundo furo na insígnia do estudante, decidiu que o processo estava encerrado e foi para a sauna.}
+
+ \vspace{0.2in}
+ 
+ \bbtext{Você não sabe quem foi o primeiro estudante que foi pego pelo professor. Contudo, você conhece todos os valores $p_i$. Sua tarefa é determinar, para cada estudante $a$, quem será o estudante com dois furos na insígnia se o primeiro a ser pego foi $a$.}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbenglish{The first line contains a single integer $n$ $(2\leq n\leq 5000)$ -- the number of planes.}
+
+ \vspace{0.1in}
+
+ \bbenglish{The second line contains $n$ integers $f_1, f_2, \ldots, f_n$ $(1\leq f_i\leq n, f_i\neq i)$, meaning that the $i$-th plane likes the $f_i$-th.}
+
+ \vspace{0.2in}
+
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbenglish{Output «\texttt{YES}» if there is a love triangle consisting of planes on Earth. Otherwise, output «\texttt{NO}».}

## Text
+ \bbbold{Entrada}
+
+ \vspace{0.1in}
+
+ \bbtext{A primeira linha contém um único inteiro $n$ $(2\leq n\leq 5000)$ -- o número de aviões.}
+
+ \vspace{0.1in}
+
+ \bbtext{A segunda linha contém $n$ inteiros $f_1, f_2, \ldots, f_n$ $(1\leq f_i\leq n, f_i\neq i)$, os quais indicam que o $i$-ésimo avião gosta do $f_i$-ésimo avião.}
+
+ \vspace{0.2in}
+
+ \bbbold{Saída}
+
+ \vspace{0.1in}
+
+ \bbtext{Imprima «\texttt{YES}» se há um triângulo amoroso entre os aviões na Terra. Caso contrário, imprima «\texttt{NO}».}

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node at (1, 6) { \bbtext{5} };

+ \node at (1, 5) { \footnotesize \bbcomment{\# de aviões} };
+ \draw[->,color=BBViolet] (1, 5.2) -- (1, 5.8);

- \node at (1, 5) { \footnotesize \bbcomment{\# de aviões} };
- \draw[->,color=BBViolet] (1, 5.2) -- (1, 5.8);
+ \node at (1, 5) { \bbtext{2} };
+ \node at (1.5, 5) { \bbtext{4} };
+ \node at (2, 5) { \bbtext{5} };
+ \node at (2.5, 5) { \bbtext{1} };
+ \node at (3, 5) { \bbtext{3} };

+ \node at (1, 4) { $f_1$ };
+ \node at (1.5, 4) { $f_2$ };
+ \node at (2, 4) { $f_3$ };
+ \node at (2.5, 4) { $f_4$ };
+ \node at (3, 4) { $f_5$ };
+ \draw[->,color=BBViolet] (1, 4.3) to (1, 4.7);
+ \draw[->,color=BBViolet] (1.5, 4.3) to (1.5, 4.7);
+ \draw[->,color=BBViolet] (2, 4.3) to (2, 4.7);
+ \draw[->,color=BBViolet] (2.5, 4.3) to (2.5, 4.7);
+ \draw[->,color=BBViolet] (3, 4.3) to (3, 4.7);

- \node at (1, 4) { $f_1$ };
- \node at (1.5, 4) { $f_2$ };
- \node at (2, 4) { $f_3$ };
- \node at (2.5, 4) { $f_4$ };
- \node at (3, 4) { $f_5$ };
- \draw[->,color=BBViolet] (1, 4.3) to (1, 4.7);
- \draw[->,color=BBViolet] (1.5, 4.3) to (1.5, 4.7);
- \draw[->,color=BBViolet] (2, 4.3) to (2, 4.7);
- \draw[->,color=BBViolet] (2.5, 4.3) to (2.5, 4.7);
- \draw[->,color=BBViolet] (3, 4.3) to (3, 4.7);
+ \node[draw,circle,very thick] (A1) at (6, 4) { \bbtext{1} };
+ \node[draw,circle,very thick] (A2) at (9, 7) { \bbtext{2} };
+ \node[draw,circle,very thick] (A3) at (12, 4) { \bbtext{3} };
+ \node[draw,circle,very thick] (A4) at (11, 1) { \bbtext{4} };
+ \node[draw,circle,very thick] (A5) at (7, 1) { \bbtext{5} };

+ \draw[-latex,very thick] (A1) to (A2);

+ \draw[-latex,very thick] (A2) to (A4);

+ \draw[-latex,very thick] (A3) [bend left] to (A5);

- \draw[-latex,very thick] (A1) to (A2);
- \draw[-latex,very thick] (A2) to (A4);
+ \draw[-latex,very thick,color=BBOrange] (A1) to (A2);
+ \draw[-latex,very thick,color=BBOrange] (A2) to (A4);
+ \draw[-latex,very thick,color=BBOrange] (A4) to (A1);
+ \draw[-latex,very thick] (3.5, 5) to (4, 5);
+ \node[anchor=west] at (4, 5) { \bbinfo{\tt YES} };

+ \draw[-latex,very thick] (A5) [bend left] to (A3);

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };
+ \node at (1, 6) { \bbtext{5} };
+ \node at (1, 5) { \bbtext{5} };
+ \node at (1.5, 5) { \bbtext{5} };
+ \node at (2, 5) { \bbtext{5} };
+ \node at (2.5, 5) { \bbtext{5} };
+ \node at (3, 5) { \bbtext{1} };

+ \node[draw,circle,very thick] (A1) at (6, 4) { \bbtext{1} };
+ \node[draw,circle,very thick] (A2) at (9, 7) { \bbtext{2} };
+ \node[draw,circle,very thick] (A3) at (12, 4) { \bbtext{3} };
+ \node[draw,circle,very thick] (A4) at (11, 1) { \bbtext{4} };
+ \node[draw,circle,very thick] (A5) at (7, 1) { \bbtext{5} };

+ \draw[-latex,very thick] (A1) [bend left] to (A5);
+ \draw[-latex,very thick] (A2) to (A5);
+ \draw[-latex,very thick] (A3) to (A5);
+ \draw[-latex,very thick] (A4) to (A5);
+ \draw[-latex,very thick] (A5) [bend left] to (A1);

+ \draw[-latex,very thick] (3.5, 5) to (4, 5);
+ \node[anchor=west] at (4, 5) { \bbinfo{\tt NO} };

## Scene
+ \node[anchor=west] at (0, 7) { \Large \bbbold{Solução} };

+ \node[draw,circle,very thick] (A) at (2, 5) { \bbtext{A} };

+ \node[draw,circle,very thick] (B) at (5, 5) { \bbtext{B} };
+ \draw[-latex,very thick] (A) to node[anchor=south] { $f(A)$ } (B);

+ \node[draw,circle,very thick] (C) at (8, 5) { \bbtext{C} };
+ \draw[-latex,very thick] (B) to node[anchor=south] { $f(B)$ } (C);

+ \node[draw,circle,very thick] (X) at (11, 5) { \bbtext{X} };
+ \draw[-latex,very thick] (C) to node[anchor=south] { $f(C)$ } (X);

+ \draw[-latex,very thick] (B) to [bend right] node[anchor=north] { $f(f(A))$ } (C);

+ \draw[-latex,very thick] (C) to [bend right] node[anchor=north] { $f(f(f(A)))$ } (X);

+ \node at (6.5, 2) { \Large { $A = f(f(f(A)))$ \bbtext{?} } };

## Frame
+ \inputsnippet{cpp}{1}{18}{codes/939A.cpp}

## Frame
+ \inputsnippet{cpp}{19}{36}{codes/939A.cpp}

## End
