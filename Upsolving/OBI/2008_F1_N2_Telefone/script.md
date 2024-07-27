## Frame
\bbcover{OBI 2008 - Nível 2: Fase 1}{Telefone}{Prof. Edson Alves}{Faculdade UnB Gama}

## Text

\bbtext{As primeiras redes públicas de telefonia foram construídas pela AT\&T; no começo do século XX. Elas permitiam que seus assinantes conversassem com a ajuda de uma telefonista, que conectava as linhas dos assinantes com um cabo especial.}

\vspace{0.1in}

\bbtext{Essas redes evoluíram muito desde então, com a ajuda de vários avanços tecnológicos. Hoje em dia, essas redes atendem centenas de milhões de assinantes; ao invés de falar diretamente com uma telefonista, você pode simplesmente discar o número da pessoa desejada no telefone.}

\vspace{0.1in}

\bbtext{Cada assinante recebe um número de telefone -- por exemplo, 55-98-234-5678. Qualquer pessoa que discar esse número consegue então falar com a pessoa do outro lado da linha. Os hifens no número de telefone são só para facilitar a leitura, e não são discados no telefone.}

\vspace{0.1in}

\bbtext{Para que fique mais fácil de se lembrar de um número de telefone, muitas companhias divulgam números que contém letras no lugar de dígitos. Para convertê-los de volta para dígitos, a maioria dos telefones tem letras nas suas teclas:}

## Text

\begin{center}
    \includegraphics[scale=0.8]{telefone.png}
\end{center}

\bbtext{Ao invés de discar uma letra, disca-se a tecla que contém aquela letra. Por exemplo, se você quiser discar o número 0800-FALE-SBC, você na realidade discaria 0800-3253-722.}

\vspace{0.1in}

\bbtext{A sua avó tem reclamado de problemas de vista -- em particular, ela não consegue mais enxergar as letrinhas nas teclas do telefone, e por isso queria que você fizesse um programa que convertesse as letras em um número de telefone para dígitos.}

## Text

\bbbold{Entrada}

\vspace{0.2in}

\bbtext{A primeira linha da entrada contém um inteiro $N$, o número de valores sorteados. A segunda linha contém $N$
valores, $V_1, V_2, \ldots, V_N$, na ordem de sorteio, separados por um espaço em branco.}

\vspace{0.2in}

\bbbold{Saída}

\vspace{0.2in}

\bbtext{Seu programa deve imprimir apenas uma linha, contendo apenas um inteiro, indicando o número de pontos do
participante.}

\vspace{0.2in}

\bbbold{Restrições}
\vspace{-0.1in}

\bbtext{
\begin{itemize}
    \item $1\leq N\leq 10^4$
    \item $-2^{31}\leq V_i\leq 2^{31} - 1$\bbtext{, para} $i = 1, 2, \ldots, N$
\end{itemize}
}
## Scene

header => Node
    @header.y = 7
    @header.text = \bbbold{Exemplo de entrada e saída}
    @header.anchor = west

---

line1 => Node
    @line1.x = 1
    @line1.y = 6
    @line1.text = \bbtext{\texttt{11} }
    @line1.anchor = west

---

arrow => Edge
    &arrow.->
    @arrow.x = 1.35
    @arrow.y = 5.00
    @arrow.u = 1.35
    @arrow.v = 5.75
    @arrow.color = BBViolet

r => Node
    @r.x = 0.5
    @r.y = 4.75
    @r.text = \footnotesize \bbcomment{\# de valores sorteados}
    @r.anchor = west

---
-r
-arrow

line2 => Node
    @line2.x = 1
    @line2.y = 5.5
    @line2.text = \bbtext{\texttt{30 30 30 30 40 40 40 40 40 30 30}}
    @line2.anchor = west

---

+r
+arrow

    @arrow.x = 4.35
    @arrow.y = 5.00
    @arrow.u = 4.35
    @arrow.v = 3.75
 
    @r.x = 3.25
    @r.y = 3.25
    @r.text = \footnotesize \bbcomment{Números sorteados}

---

-r
-arrow

node1 => Node
    @node1.x = 2
    @node1.y = 3
    @node1.text = \bbtext{\texttt{30}}
    &node1.draw
    &node1.very thick
    &node1.circle

node2 => Node
    @node2.x = 3
    @node2.y = 3
    @node2.text = \bbtext{\texttt{30}}
    &node2.draw
    &node2.very thick
    &node2.circle

node3 => Node
    @node3.x = 4
    @node3.y = 3
    @node3.text = \bbtext{\texttt{30}}
    &node3.draw
    &node3.very thick
    &node3.circle

node4 => Node
    @node4.x = 5
    @node4.y = 3
    @node4.text = \bbtext{\texttt{30}}
    &node4.draw
    &node4.very thick
    &node4.circle

node5 => Node
    @node5.x = 6
    @node5.y = 3
    @node5.text = \bbtext{\texttt{40}}
    &node5.draw
    &node5.very thick
    &node5.circle

node6 => Node
    @node6.x = 7
    @node6.y = 3
    @node6.text = \bbtext{\texttt{40}}
    &node6.draw
    &node6.very thick
    &node6.circle

node7 => Node
    @node7.x = 8
    @node7.y = 3
    @node7.text = \bbtext{\texttt{40}}
    &node7.draw
    &node7.very thick
    &node7.circle

node8 => Node
    @node8.x = 9
    @node8.y = 3
    @node8.text = \bbtext{\texttt{40}}
    &node8.draw
    &node8.very thick
    &node8.circle

node9 => Node
    @node9.x = 10
    @node9.y = 3
    @node9.text = \bbtext{\texttt{40}}
    &node9.draw
    &node9.very thick
    &node9.circle

node10 => Node
    @node10.x = 11
    @node10.y = 3
    @node10.text = \bbtext{\texttt{30}}
    &node10.draw
    &node10.very thick
    &node10.circle

node11 => Node
    @node11.x = 12
    @node11.y = 3
    @node11.text = \bbtext{\texttt{30}}
    &node11.draw
    &node11.very thick
    &node11.circle

---

    @node1.fill = BBGreen
    @node2.fill = BBGreen
    @node3.fill = BBGreen
    @node4.fill = BBGreen

---

    @node1.fill = BBWhite
    @node2.fill = BBWhite
    @node3.fill = BBWhite
    @node4.fill = BBWhite

    @node5.fill = BBCyan
    @node6.fill = BBCyan
    @node7.fill = BBCyan
    @node8.fill = BBCyan
    @node9.fill = BBCyan

---

    @node4.fill = BBWhite
    @node5.fill = BBWhite
    @node6.fill = BBWhite
    @node7.fill = BBWhite
    @node8.fill = BBWhite
    @node9.fill = BBWhite

    @node10.fill = BBOrange
    @node11.fill = BBOrange

---

+r
+arrow

    @arrow.x = 8
    @arrow.u = 10
    @arrow.y = 5.5
    @arrow.v = 5.5
    @arrow.color = BBBlack
    &arrow.-latex
    &arrow.thick

    @r.x = 10.25
    @r.y = 5.5
    @r.text = \footnotesize \bboutput{5}
    @r.anchor = west


## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Solução}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{O problema consiste em identificar as sequências de números consecutivos}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Uma vez identificadas, a resposta será o tamanho da maior delas}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{Uma possível solução usa um laço e mantém o registro do último elemento visto}
    @c.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 3
    @d.text = $\star$ \bbtext{Este registro deve ser inicializado com o primeiro elemento do vetor}
    @d.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 2
    @e.text = $\star$ \bbtext{É preciso fazer uma última verificação, após o encerramento do laço, para verificar}
    @e.anchor = west

e1 => Node
    @e1.x = 0.5
    @e1.y = 1.25
    @e1.text = \bbtext{a última sequência de números consecutivos}
    @e1.anchor = west

## Scene

title => Node
    @title.x = 0
    @title.y = 7
    @title.text = \Large \bbbold{Bônus}
    @title.anchor = west

---

a => Node
    @a.x = 1
    @a.y = 6
    @a.text = $\star$ \bbtext{Há uma solução alternativa para este problema}
    @a.anchor = west

---

b => Node
    @b.x = 1
    @b.y = 5
    @b.text = $\star$ \bbtext{Ela é baseada em uma técnica denominada \bbbold{dois ponteiros}}
    @b.anchor = west

---

c => Node
    @c.x = 1
    @c.y = 4
    @c.text = $\star$ \bbtext{Esta técnica usa duas variáveis inteiras (\code{c}{L} e \code{c}{R}) para identificar subintervalos}
    @c.anchor = west

c1 => Node
    @c1.x = 0.5
    @c1.y = 3.25
    @c1.text = \bbtext{\code{c}{[L, R)} de elementos com características comuns}
    @c1.anchor = west

---

d => Node
    @d.x = 1
    @d.y = 2.25
    @d.text = $\star$ \bbtext{Como ambas variáveis apontam para cada elemento no máximo uma única vez, }
    @d.anchor = west

d1 => Node
    @d1.x = 0.5
    @d1.y = 1.5
    @d1.text = \bbtext{a eficiência é a mesma da solução anterior}
    @d1.anchor = west

---

e => Node
    @e.x = 1
    @e.y = 0.5
    @e.text = $\star$ \bbtext{Esta abordagem dispensa o último teste}
    @e.anchor = west

## End
