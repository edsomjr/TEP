Princípio da Inclusão/Exclusão
==============================

O **Princípio da Inclusão/Exclusão** é a generalização do Princípio Aditivo, para os casos onde
2 ou mais conjuntos tem interseção não-vazia. Abaixo apresentaremos os casos particulares para
2 e 3 conjuntos, e em seguida a formulação geral para _N_ conjuntos.

União de 2 conjuntos
--------------------

Sejam _A_ e _B_ dois conjuntos com interseção _A&#8745;B_ não-vazia. Quantos são os elementos do 
conjunto união _A&#8746;B_? A princípio a expressão |_A&#8746;B_| = |_A_| + |_B_| pode parecer 
correta, mas há um problema: quando somamos todos os elementos do conjunto _A_, somamos 
também os elementos da interseção _A&#8745;B_; ao somarmos os elementos de _B_, os elementos da 
interseção são novamente somados, de modo que a expressão proposta conta elementos duplicados.

Esta duplicação pode ser removida descontado uma vez cada elemento dobrado. Assim

        | A ou B | = | A | + | B | - | A e B |

A expressão acima é o Princípio da Inclusão/Exclusão para dois conjuntos.

União de 3 conjuntos
--------------------

Para o caso de 3 conjuntos, devemos atentar as possíveis interseções entre os conjuntos e os
efeitos colaterais da soma e subtração de cada uma. Na soma

        | A ou B ou C | = | A | + | B | + | C |

as interseções _A&#8745;B_, _A&#8745;C_ e _B&#8745;C_ são contadas duas vezes, e a interseção
_A&#8745;B&#8745;C_ três vezes!. Ao remover as duplicatas, ficamos com

        | A ou B ou C | = | A | + | B | + | C | - | A e B | - | A e C | - | B e C |

As duplicatas foram removidas, mas a interseção _A&#8745;B&#8745;C_ foi removida completamente
(três vezes), de modo que não está mais sendo contada. A última correção necessária, portanto,
é incluir a interseção ausente:

        | A ou B ou C | = | A | + | B | + | C | - | A e B | - | A e C | - | B e C |
                        + | A e B e C |

Este é o Princípio da Inclusão/Exclusão para três conjuntos.

Caso Geral
----------

Seja _S{i}_ o somatório com _i_ variando de 1 a _N_. Para _N_ conjuntos _A1, A2, ..., AN_, temos
que

        | A1 e A2 e ... e AN | = S{i} | Ai | - S{i<j}| Ai e Aj | + S{i<j<k}| Ai e Aj e Ak | 
                               + ... + (-1)^N | A1 e A2 e ... e AN |

Veja que o número de elementos dos próprios, e de suas interseções em quantidade par, são somados
ao total; já as interseções em quantidade ímpar são removidas.

Aplicações
----------

A seguir apresentaremos duas aplicações do Princípio da Inclusão/Exclusão.

### Permutações caóticas

Uma permutação de _N_ elementos é dita **caótica** se nenhum dos _N_ elementos ocupa, na 
permutação, a mesma posição que ocupava na posicionamento original (isto é, o elemento _i_ não
ocupa a _i_-ésima posição).

Podemos contar o total de permutações caóticas _D(N)_ (D de _derangement_, em inglês) da
seguinte forma: seja _Ak_ o conjunto das permutações nas quais o elemento _k_ ocupa a _k_-ésima
posição. Assim

        D(N) = P(N) - S{i} | Ai | + S{i<j}| Ai e Aj | - S{i<j<k}| Ai e Aj e Ak | 
             + ... + (-1)^N | A1 e A2 e ... e AN |

onde _P(N)_ é o total de permutações de _N_ elementos. Observe que |_Ai_| = (_N_ - 1)! (pois 
o elemento _i_ está fixo), |_Ai_ e _Aj_| = (_N_ - 2)! (dois elementos fixos), e assim por diante.
Logo

        D(N) = N! - binom(n, 1)(N - 1)! + binom(n, 2)(N - 2)! - ... + (-1)^N binom(N,N)

o que nos dá

        D(N) = N!(1 - 1/1! + 1/2! - 1/3! + ... + (-1)^N/N!)

Na prática, para computar _D(N)_ é melhor utilizar a seguinte recorrência. Para _N_ = 1, não 
há permutações caóticas entre as 1! possíveis. Para o caso _N_ = 2, há uma permutação caótica
entre as 2 possíveis. Assim os casos base são

        D(1) = 0
        D(2) = 1

Para computar _D(N)_ devemos decidir o que fazer com o primeiro elemento. Temos duas situações
possíveis

1. Trocar 1 com _j_, de forma que cada um ocupe a posição do outro;
1. Passar um elemento _j_ para a posição 1, mas não escrever 1 na posição do _j_.

Tanto no primeiro quanto no segundo cenário temos (_N_ - 1) valores possíveis para _j_. No primeiro
caso, após a troca de ambos, restam _N_ - 2 elementos a serem posicionados, o que pode ser 
feito de _D(N - 2)_ maneiras; no segundo caso, como 1 não pode ocupar a posição _j_, ficamos
na mesma situação de posicionar _N_ - 1 elementos, pois o 1 faz o papel do _j_, o que pode ser
feito de _D(N - 1)_ maneiras. Assim

        D(N) = (N - 1)(D(N - 1) + D(N - 2))

Os primeiros valores para esta sequência são 1, 0, 1, 2, 9, 44, 265, 1854, 14833, 133496, 1334961, 14684570, 176214841, 2290792932, ...

Uma notação alternativa para _D(N)_ é _!n_, que faz referência as permutações (que seriam _n!_).

### Número de funções

Sejam _A_ e _B_ dois conjuntos com _n_ e _m_ elementos, respectivamente. Quantas são as funções
_f: A -> B_?

Esta é uma pergunta relativamente fácil de responder: seja F = {funções _f: A -> B_}. 
Cada um dos elementos de _A_ devem estar
associados a um único elemento de _B_. Assim temos, para cada um dos _n_ elementos, _m_ escolhas
possíveis. Pelo Princípio Multiplicativo temos que

        | F | = m^n

A pergunta se torna mais interessante, porém, se adicionarmos algumas restrições. A primeira
variante seria: quantas são as funções **bijetoras** de _A_ em _B_?

Para que existam funções bijetoras de _A_ em _B_, é necessário que _n = m_. Neste caso, seja 
J = {_f: A -> B_ | _f_ é bijetora}. Agora, cada um elemento de _A_ tem que estar associado a um
único elemento de _B_, e cada elemento de _B_ deve estar associado a um único elemento de _A_,
e todos os elementos de _B_ devem estar associados a algum elemento de _A_.
Assim, o primeiro elemento de _A_ tem _n_ escolhas, o segundo tem _(n - 1)_, o terceiro _(n - 2)_,
e assim por diante. Portanto,

        | J | = n x (n - 1) x (n - 2) x ... x 2 x 1 = P(n) = n!

A segunda variante da pergunta é: quantas são as funções **injetoras** de _A_ em _B_?

Para que existam funções injetoras de _A_ em _B_, é necessário que _n <= m_. Neste caso, seja 
I = {_f: A -> B_ | _f_ é injetora}. Agora, cada um elemento de _A_ tem que estar associado a um
único elemento de _B_, e cada elemento de _B_ deve estar associado a um único elemento de _A_.
Assim, o primeiro elemento de _A_ tem _m_ escolhas, o segundo tem _(m - 1)_, o terceiro _(m - 2)_,
e assim por diante. Portanto,

        | I | = m x (m - 1) x (m - 2) x ... x (m - n + 1) = A(m, n) = m!/(m - n)!

Por fim, a mais interessante variação da pergunta: quantas são as funções **sobrejetoras** de
_A_ em _B_?

Precisamos, neste cenários, que _n >= m_. Seja _S_ = {_f: A-> B_ | _f_ é sobrejetora} e defina 
_Ck_ = {_f: A -> B_ | _f(ai) != bk_, para todos
elementos _ai_ de _A_}. Veja que uma função deixa de ser sobrejetora se pertencer a ao menos um
dos conjuntos _Ck_. Pelo Princípio da Inclusão/Exclusão temos que

        | S | = | F | - S{i} | Ci | + S{i<j}| Ci e Cj | - S{i<j<k}| Ci e Cj e Ck | 
             + ... + (-1)^N | C1 e C2 e ... e CN |

Observe que |_Ci_| = (_m_ - 1)^_n_, |_Ci_ e _Cj_| = (_m_ - 2)^_n_, e assim por diante, de modo que

        | S | = m^n - binom(m, 1) (m - 1)^n + binom(m, 1) (m - 2)^n 
              + ... + (-1)^m (binom(m, m) (m - m)^n
o que nos dá

        | S | = S{i} (-1)^i binom(m, i) (m - i)^n,

para _i_ variando de 0 a _m_.

Este valor coincide com o número de maneiras de se distribuir _n_ bolas distintas em _m_ 
caixas distintas, sem que nenhuma caixa fique vazia.

Deste mesmo resultado pode-se deduzir este outro importante resultado: há _T = | S | / m!_ maneiras
de se distribuir _n_ bolas distintas em _m_ caixas iguais, sem que nenhuma caixa fique vazia.

Referências
-----------

SANTOS, José Plínio O., MELLO, Margarida P., MURARI, Idani T. [Introdução à Análise Combinatória](http://www.vestseller.com.br/matematica/introduc-o-a-analise-combinatoria-jose-plinio-margarida-mello-idani-murari), Editora Ciência Moderna, 2007.
