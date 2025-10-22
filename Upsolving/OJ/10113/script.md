## Frame
+ \bbcover{OJ 10113}{Exchange Rates}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text
+ \bbenglish{Using money to pay for goods and services usually makes life easier, but sometimes people prefer to trade items directly without any money changing hands. In order to ensure a consistent ``price'', traders set an exchange rate between items. The exchange rate between two items $A$ and $B$ is expressed as two positive integers $m$ and $n$, and says that $m$ of item $A$ is worth $n$ of item $B$. For example, 2 stoves might be worth 3 refrigerators. (Mathematically, 1 stove is worth 1.5 refrigerators, but since it’s hard to find half a refrigerator, exchange rates are always expressed using integers.)}
+
+ \vspace{0.1in}
+ 
+ \bbenglish{ Your job is to write a program that, given a list of exchange rates, calculates the exchange rate between any two items.}

## Text
+ \bbtext{Usar dinheiro para pagar por bens e serviços geralmente torna a vida mais fácil, mas algumas vezes as pessoas preferem torcar itens diretamente, sem qualquer uso de dinheiro. Para garantir um ``preço'' consistente, os envolvidos na troca definem uma taxa de conversão entre os itens. A taxa de conversão entre os itens $A$ e $B$ é expressa por meio de dois inteiros positivos $m$ e $n$, e diz que $m$ unidades do item $A$ valem $n$ unidades do item $B$. Por exemplo, 2 fornos podem valer 3 refrigeradores. (Matematicamente, 1 forno vale um refrigerador e meio, mas como é difícil encontrar meio refrigerador, as taxas de conversão são sempre expressas usando inteiros.)}
+
+ \vspace{0.1in}
+ 
+ \bbtext{Sua tarefa á escrever um programa que, dada uma lista de taxas de conversão, calcule a taxa de conversão entre quaisquer dois itens.}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbenglish{The input file contains one or more commands, followed by a line beginning with a period that signals the end of the file. Each command is on a line by itself and is either an assertion or a query. An assertion begins with an exclamation point and has the format}
+\[
+!\ m\ itema = n\ itemb
+\]
+ \bbenglish{where $itema$ and $itemb$ are distinct item names and $m$ and $n$ are both positive integers less than 100.  This command says that $m$ of $itema$ are worth $n$ of $itemb$. A query begins with a question mark, is of the form}
+\[
+?\ itema = itemb
+\]
+ \bbenglish{ and asks for the exchange rate between $itema$ and $itemb$, where $itema$ and $itemb$ are distinct items that have both appeared in previous assertions (although not necessarily the same assertion).}

## Text
+ \bbbold{Input}
+
+ \vspace{0.1in}
+
+ \bbtext{A entrada contém um ou mais comandos, seguidos de uma linha que começa com um ponto final, o qual indica o fim da entrada. Cada comando está contido em uma linha e ou é uma afirmação ou uma consulta. Uma afirmação começa com um ponto de exclamação e tem o formato}
+\[
+!\ m\ itema = n\ itemb
+\]
+ \bbtext{onde $itema$ e $itemb$ são nomes de itens diferntes e $m$ e $n$ são inteiros positivos menores do que 100.  Este comando diz que $m$ unidades do $itema$ valem $n$ unidades do $itemb$. Uma consulta começa com uma exclamação, e tem a forma}
+\[
+?\ itema = itemb
+\]
+ \bbtext{e requer a taxa de conversão entre $itema$ e $itemb$, onde $itema$ e $itemb$ são itens diferentes e ambos aparecerem em afirmativas anteriores (não necessariamente na mesma afirmação).}

## Text
+ \bbbold{Output}
+
+ \vspace{0.1in}
+
+ \bbenglish{For each query, output the exchange rate between $itema$ and $itemb$ based on all the assertions made up to that point. Exchange rates must be in integers and must be reduced to lowest terms. If no exchange rate can be determined at that point, use question marks instead of integers. Format all output exactly as shown in the example.}

## Text
+ \bbbold{Saída}
+
+ \vspace{0.1in}
+
+ \bbtext{Para cada consulta imprima a taxa de conversão entre $itema$ e $itemb$, baseada em todas as afirmativas feitas até o momento. Taxas de conversão devem ser inteiros e não devem ter divisores comuns. Se não é possível determinar a taxa de conversão neste ponto, substitua os inteiros por pontos de interrogação. Formate a saída conforme o exemplo dado.}

## Text
+ \bbbold{Notes}
+
+ \vspace{0.1in}
+
+ \begin{itemize}
+    \item \bbenglish{Item names will have length at most 20 and will contain only lowercase letters.}
+    \item \bbenglish{Only the singular form of an item name will be used (no plurals).}
+    \item \bbenglish{There will be at most 60 distinct items.}
+    \item \bbenglish{There will be at most one assertion for any pair of distinct items.}
+    \item \bbenglish{There will be no contradictory assertions. For example, “2 pig = 1 cow”, “2 cow = 1 horse”, and “2 horse = 3 pig” are contradictory.}
+    \item \bbenglish{Assertions are not necessarily in lowest terms, but output must be.}
+    \item \bbenglish{Although assertions use numbers less than 100, queries may result in larger numbers that will not exceed 10000 when reduced to lowest terms}
+ \end{itemize}

## Text
+ \bbbold{Notas}
+
+ \vspace{0.1in}
+
+ \begin{itemize}
+    \item \bbtext{Nomes dos itens são compostos por, no máximo, 20 caracteres alfabéticos minúsculos.}
+    \item \bbtext{Apenas a forma singular do nome do item será usada (sem plurais).}
+    \item \bbtext{Haverão, no máximo, 60 itens diferentes.}
+    \item \bbtext{Haverá no máximo uma afirmativa para qualquer par de itens distintos.}
+    \item \bbtext{Não haverão afirmativas contraditórias. Por exemplo, ``2 porco = 1 vaca'', ``2 vaca = 1 cavalo'' e ``2 cavalo = 3 porco'' são contraditórias.}
+    \item \bbtext{Afirmativas podem conter divisores comuns, mas a saída não deve conter divisores comuns.}
+    \item \bbtext{Embora as afirmativas usem números menores do que 100, as respostas das consultas podem ser números maiores, os quais não excedem 10000 quando eliminados os divisores comuns.}
+ \end{itemize}

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Exemplo de entrada e saída} };

+ \node[anchor=west] at (1, 6) { \bbtext{! 6 shirt = 15 sock} };

+ \node[draw,circle,very thick] (C) at (10, 1) {\includegraphics[scale=0.2]{figs/shirt.png}};
+ \node[draw,circle,very thick] (A) at (7, 4) {\includegraphics[scale=0.2]{figs/socks.png}};
+ \draw[very thick] (C) to node[below,pos=0.2] { \footnotesize \bbtext{6} } node[above,pos=0.75] { \footnotesize \bbtext{15} } (A);

+ \node[anchor=west] at (1, 5) { \bbtext{! 47 underwear = 9 pant} };

+ \node[draw,circle,very thick] (B) at (10, 7) {\includegraphics[scale=0.2]{figs/pants.png}};
+ \node[draw,circle,very thick] (D) at (13, 4) {\includegraphics[scale=0.2]{figs/underwear.png}};
+ \draw[very thick] (D) to node[below,pos=0.2] { \footnotesize \bbtext{47} } node[above,pos=0.75] { \footnotesize \bbtext{9} } (B);

+ \node[anchor=west] at (1, 4) { \bbtext{? sock = shirt } };

+ \draw[very thick,color=BBOrange] (A) to [bend left] node[above,pos=0.1] { \footnotesize \bbinfo{5} } node[above right,pos=0.9] { \footnotesize \bbinfo{2} } (C);

- \draw[very thick,color=BBOrange] (A) to [bend left] node[above,pos=0.1] { \footnotesize \bbinfo{5} } node[above right,pos=0.9] { \footnotesize \bbinfo{2} } (C);
+ \node[anchor=west] at (1, 3) { \bbtext{? shirt = pant } };

+ \draw[very thick,color=BBOrange] (C) to node[right,pos=0.1] { \footnotesize \bbinfo{?} } node[right,pos=0.9] { \footnotesize \bbinfo{?} } (B);

- \draw[very thick,color=BBOrange] (C) to node[right,pos=0.1] { \footnotesize \bbinfo{?} } node[right,pos=0.9] { \footnotesize \bbinfo{?} } (B);
+ \node[anchor=west] at (1, 2) { \bbtext{! 2 sock = 1 underwear } };

+ \draw[very thick] (A) to node[below,pos=0.1] { \footnotesize \bbtext{2} } node[below,pos=0.9] { \footnotesize \bbtext{1} } (D);

+ \node[anchor=west] at (1, 1) { \bbtext{? shirt = pant } };

+ \draw[very thick,color=BBOrange] (B) to [bend left] node[above,pos=0.2] { \footnotesize \bbinfo{9} } node[right,pos=0.9] { \footnotesize \bbinfo{47} } (D);

- \draw[very thick,color=BBOrange] (B) to [bend left] node[above,pos=0.2] { \footnotesize \bbinfo{9} } node[right,pos=0.9] { \footnotesize \bbinfo{47} } (D);
+ \draw[very thick,color=BBOrange] (B) to [bend right] node[below,pos=0.1] { \footnotesize \bbinfo{9} } node[left,pos=0.9] { \footnotesize \bbinfo{94} } (A);

- \draw[very thick,color=BBOrange] (B) to [bend right] node[below,pos=0.1] { \footnotesize \bbinfo{9} } node[left,pos=0.9] { \footnotesize \bbinfo{94} } (A);
+ \draw[very thick,color=BBOrange] (B) to node[right,pos=0.1] { \footnotesize \bbinfo{45} } node[right,pos=0.9] { \footnotesize \bbinfo{188} } (C);

## Scene
+ \node[anchor=west] at (0, 7) { \bbbold{Solução} };

+ \node[draw,circle,very thick] (A) at (3, 3) { \bbtext{1} };
+ \node[draw,circle,very thick] (B) at (6, 1) { \bbtext{2} };
+ \node[draw,circle,very thick] (C) at (6, 5) { \bbtext{3} };
+ \node[draw,circle,very thick] (D) at (9, 2) { \bbtext{4} };
+ \node[draw,circle,very thick] (E) at (9, 4) { \bbtext{5} };
+ \node[draw,circle,very thick] (F) at (12, 3) { \bbtext{6} };
+ \draw[very thick] (A) to (B);
+ \draw[very thick] (A) to (C);
+ \draw[very thick] (B) to (E);
+ \draw[very thick] (C) to (E);
+ \draw[very thick] (E) to (F);

+ \node[anchor=west] at (1, 6) { \bbtext{Só há conversão entre objetos se há ao menos um caminho entre eles} };

+ \draw[-latex,very thick,color=BBOrange] (A) to node[above] { \bbinfo{Ok} } (F);

- \draw[-latex,very thick,color=BBOrange] (A) to node[above] { \bbinfo{Ok} } (F);
+ \draw[-latex,very thick,color=BBRed] (A) to node { \bbalert{x} } (D);

- \draw[-latex,very thick,color=BBRed] (A) to node { \bbalert{x} } (D);
- \node[anchor=west] at (1, 6) { \bbtext{Só há conversão entre objetos se há ao menos um caminho entre eles} };
+ \node[anchor=west] at (1, 6) { \bbtext{Pela consistência da entrada este caminho não precisa ser único} };

+ \draw[-latex,color=BBViolet] (A) to [bend left] (C);
+ \draw[-latex,color=BBViolet] (C) to [bend left] (E);
+ \draw[-latex,color=BBViolet] (E) to [bend left] (F);

- \draw[-latex,color=BBViolet] (A) to [bend left] (C);
- \draw[-latex,color=BBViolet] (C) to [bend left] (E);
- \draw[-latex,color=BBViolet] (E) to [bend left] (F);
+ \draw[-latex,color=BBViolet] (A) to [bend right] (B);
+ \draw[-latex,color=BBViolet] (B) to [bend right] (E);
+ \draw[-latex,color=BBViolet] (E) to [bend left] (F);

- \draw[-latex,color=BBViolet] (A) to [bend right] (B);
- \draw[-latex,color=BBViolet] (B) to [bend right] (E);
- \draw[-latex,color=BBViolet] (E) to [bend left] (F);
- \node[anchor=west] at (1, 6) { \bbtext{Pela consistência da entrada este caminho não precisa ser único} };
+ \node[anchor=west] at (1, 6) { \bbtext{As taxas de conversão compõem por multiplicação} };

- \draw[very thick] (A) to (C);
- \draw[very thick] (C) to (E);
+ \draw[very thick] (A) to node[above,pos=0.1] { \footnotesize \bbcomment{x} } node[below,pos=0.9] { \footnotesize \bbcomment{y} } (C);
+ \draw[very thick] (C) to node[below,pos=0.1] { \footnotesize \bbcomment{z} } node[above,pos=0.9] { \footnotesize \bbcomment{w} } (E);

+ \draw[-latex,very thick,color=BBOrange] (A) to node[below,pos=0.1] { \footnotesize \bbinfo{xz/d} } node[below,pos=0.85] { \footnotesize \bbinfo{yw/d} } (E);
- \node[anchor=west] at (1, 6) { \bbtext{As taxas de conversão compõem por multiplicação} };
+ \node[anchor=west] at (1, 6) { \bbtext{As taxas de conversão compõem por multiplicação ($d = gcd(xz, yw)$)} };

## Frame
+ \inputsnippet{cpp}{14}{34}{codes/10113.cpp}

## Frame
+ \inputsnippet{cpp}{44}{60}{codes/10113.cpp}

## Frame
+ \inputsnippet{cpp}{62}{75}{codes/10113.cpp}

## Scene
+ \node[anchor=west] at (0, 6) { \Large \bbbold{Créditos} };
+ \node[anchor=west] at (1, 5) { $\star$ \bbtext{Male clothes and accessories thin line icon set 2 by Amonrat } };
+ \node[anchor=west] at (0.5, 4.5) { \bbtext{rungreangfangsai from \bbenglish{www.vecteezy.com} } };

kk
# End
