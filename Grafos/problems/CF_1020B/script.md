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
+ \bbtext{Assuma que os estudantes estão numerados de $1$ a $n$. O professor foi ao estudante $a$ e furou sua insígnia. O estudante, porém, afirmou que o principal culpado é o estudante $p_a$.}
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
+ \bbenglish{The first line of the input contains the only integer $n$ $(1\leq n\leq 1000)$ -- the number of the naughty students.}
+
+ \vspace{0.1in}
+
+ \bbenglish{The second line contains $n$ integers $p_1, \ldots, p_n$ $(1\leq p_i\leq n)$, where $p_i$ indicates the student who was reported to the teacher by student $i$.}
+
+ \vspace{0.2in}
+
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbenglish{For every student $a$ from $1$ to $n$ print which student would receive two holes in the badge, if $a$ was the first student caught by the teacher.}

## Text
+ \bbbold{Entrada}
+
+ \vspace{0.1in}
+
+ \bbtext{A primeira linha da entrada contém um único inteiro $n$ $(1\leq n\leq 1000)$ -- o número de estudantes malcriados.}
+
+ \vspace{0.1in}
+
+ \bbtext{A segunda linha contém $n$ inteiros $p_1, \ldots, p_n$ $(1\leq p_i\leq n)$, onde $p_i$ indica o estudante que foi acusado ao professor pelo estudante $i$.}
+
+ \vspace{0.2in}
+
+ \bbbold{Saída}
+
+ \vspace{0.1in}
+
+ \bbtext{Para cada estudante $a$ de $1$ a $n$ imprima qual estudante irá receber dois furos em sua insígnia, se $a$ foid o primeiro estudante capturado pelo professor.}

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node at (1, 6) { \bbtext{3} };

+ \node at (1, 5) { \footnotesize \bbcomment{\# de estudantes} };
+ \draw[->,color=BBViolet] (1, 5.2) -- (1, 5.8);

- \node at (1, 5) { \footnotesize \bbcomment{\# de estudantes} };
- \draw[->,color=BBViolet] (1, 5.2) -- (1, 5.8);
+ \node at (1, 5) { \bbtext{2} };
+ \node at (1.5, 5) { \bbtext{3} };
+ \node at (2, 5) { \bbtext{2} };

+ \node at (1, 4) { $p_1$ };
+ \node at (1.5, 4) { $p_2$ };
+ \node at (2, 4) { $p_3$ };
+ \draw[->,color=BBViolet] (1, 4.3) to (1, 4.7);
+ \draw[->,color=BBViolet] (1.5, 4.3) to (1.5, 4.7);
+ \draw[->,color=BBViolet] (2, 4.3) to (2, 4.7);

- \node at (1, 4) { $p_1$ };
- \node at (1.5, 4) { $p_2$ };
- \node at (2, 4) { $p_3$ };
- \draw[->,color=BBViolet] (1, 4.3) to (1, 4.7);
- \draw[->,color=BBViolet] (1.5, 4.3) to (1.5, 4.7);
- \draw[->,color=BBViolet] (2, 4.3) to (2, 4.7);
+ \node[draw,circle,very thick] (A1) at (6, 4) { \bbtext{1} };
+ \node[draw,circle,very thick] (A2) at (9, 7) { \bbtext{2} };
+ \node[draw,circle,very thick] (A3) at (12, 4) { \bbtext{3} };

+ \draw[-latex,very thick] (A1) to (A2);

+ \draw[-latex,very thick] (A2) to [bend left] (A3);

+ \draw[-latex,very thick] (A3) to [bend left] (A2);

+ \draw[-latex] (1, 4.7) to (1, 4.3);
+ \node at (1, 4) { \bbinfo{2} };

- \draw[-latex,very thick] (A1) to (A2);
- \draw[-latex,very thick] (A2) to [bend left] (A3);
- \draw[-latex,very thick] (A3) to [bend left] (A2);

+ \draw[-latex,very thick] (A2) to [bend left] (A3);

+ \draw[-latex,very thick] (A3) to [bend left] (A2);

+ \draw[-latex] (1.5, 4.7) to (1.5, 4.3);
+ \node at (1.5, 4) { \bbinfo{2} };

- \draw[-latex,very thick] (A2) to [bend left] (A3);
- \draw[-latex,very thick] (A3) to [bend left] (A2);

+ \draw[-latex,very thick] (A3) to [bend left] (A2);

+ \draw[-latex,very thick] (A2) to [bend left] (A3);

+ \draw[-latex] (2, 4.7) to (2, 4.3);
+ \node at (2, 4) { \bbinfo{3} };

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node at (1, 6) { \bbtext{3} };
+ \node at (1, 5) { \bbtext{1} };
+ \node at (1.5, 5) { \bbtext{2} };
+ \node at (2, 5) { \bbtext{3} };

+ \node[draw,circle,very thick] (A1) at (6, 4) { \bbtext{1} };
+ \node[draw,circle,very thick] (A2) at (9, 7) { \bbtext{2} };
+ \node[draw,circle,very thick] (A3) at (12, 4) { \bbtext{3} };

+ \draw[-latex,very thick] (A1) [loop left] to (A1);
+ \draw[-latex,very thick] (A2) [loop left] to (A2);
+ \draw[-latex,very thick] (A3) [loop left] to (A3);

+ \draw[-latex] (1, 4.7) to (1, 4.3);
+ \node at (1, 4) { \bbinfo{1} };
+ \draw[-latex] (1.5, 4.7) to (1.5, 4.3);
+ \node at (1.5, 4) { \bbinfo{2} };
+ \draw[-latex] (2, 4.7) to (2, 4.3);
+ \node at (2, 4) { \bbinfo{3} };

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Solução} };

+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{Para cada estudante $a$ são necessárias, no máximo, $n + 1$ verificações} };

+ \node[anchor=west] at (1, 4) { $\star$ \bbtext{Estas verificações podem ser feitas por meio de uma DFS} };

+ \node[anchor=west] at (1, 3) { $\star$ \bbtext{Há $n$ estudantes distintos} };

+ \node[anchor=west] at (1, 2) { $\star$ \bbtext{A complexidade da solução é $O(n^2)$} };

## Frame
+ \inputsnippet{cpp}{1}{18}{codes/1020B.cpp}

## Frame
+ \inputsnippet{cpp}{19}{31}{codes/1020B.cpp}

## End
