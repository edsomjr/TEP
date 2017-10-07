Funções Geradoras
=================

As funções geradoras constituem uma poderosa ferramenta em Análise Combinatória, permitindo a
solução de diferentes problemas de forma sistemática. Primeiramente apresentaremos uma motivação
para tais funções, e em seguida apresentaremos sua formalização, conceitos associados e 
aplicação prática.

Motivação
---------

Carlos quer comprar 6 camisetas de um mesmo modelo, e há 3 opções de cores a disposição: amarelo,
branco, e celeste. De quantas maneiras ele pode adquirir as 6 camisetas, se ele deseja comprar ao
menos uma de cada cor, e no máximo 3 brancas, 2 amarelas e 2 celestes?

Sejam _xa, xb_ e _xc_ as quantidades de camisetas de cada cor que serão adquiridas. O problema se
trata de encontrar todas as soluções da equação

        xa + xb + xc = 6

com 1 <= xa <= 3, 1 <= xb, xb <= 2. Observe que, se tivéssemos apenas as restrições inferiores,
o problema seria o problema das soluções de equações lineares com coeficientes unitários, com
_xi > 0_, já apresentado anteriormente, cuja solução é _binom(6 - 1, 3 - 1) = binom(5, 2) = 10_.
Como tratar, porém, as restrições do lado direito das desigualdades que envolvem as variáveis
_xi_?

Uma maneira de se abordar tal problema seria o uso do Princípio da Inclusão/Exclusão: defina os
conjuntos

        A = { solução de xa + xb + xc = 6 com xa > 3 }
        B = { solução de xa + xb + xc = 6 com xb > 2 }
        C = { solução de xa + xb + xc = 6 com xc > 2 }

Então o número de soluções _S_ do problema com as restrições apresentadas seria igual a

        S = binom(5, 2) - | A | - | B | - | C | 
          + | A e B | + | A e C | + | B e C | - | A e B e C |

Resolvendo cada problema usando mudança de variáveis teríamos

        S = 10 - 1 - 3 - 3 + 0 + 0 + 0 - 0 = 3

A título de curiosidade, as soluções seriam

        xa = 2, xb = 2, xc = 2
        xa = 3, xb = 1, xc = 2
        xa = 3, xb = 2, xc = 1

Esta abordagem, porém, é demasiadamente trabalhosa, uma vez que passamos de um problema para 8
deles, antes de se determinar a solução. E o número de problemas sobe exponencialmente a 
medida que o número de variáveis aumenta.

Uma abordagem diferente seria usar polinômios para representar as possíveis escolhas para
cada variável. Para as camisetas amarelas, usaríamos o polinômio

        ax + a²x² + a³x³

onde o grau do termo _x_ ou da constante _a_ indicam o número de camisetas amarelas. Para as
demais cores teríamos

        bx + b²x²

e

        cx + c²x²

O produto deste polinômios seria, de acordo com a propriedade distributiva,

        (ax + a²x² + a³x³)(bx + b²x²)(cx + c²x²) =
            (abc)x³ + (abc² + ab²c + a²bc)x^4 + (ab²c² + a²bc² + a²b²c + a³bc)x^5 +
            (a²b²c² + a³bc² + a³b²c)x^6 + (a³b²c²)x^7

Veja que o coeficiente do termo _x^6_ nos fornece justamente as três soluções desejadas, onde
os expoentes das constantes _a, b, c_ indicam o número de itens da referida cor que foram
escolhidos. Veja que se fizéssemos _a = b = c = 1_, teríamos
 
        (x + x² + x³)(x + x²)(x + x²) = x³ + 3x^4 + 4x^5 + 3x^6 + x^7

O coeficiente de _x^5_ agora informa a quantidade de maneiras, mas não discrimina as maneiras em
si. De fato, os coeficientes de cada um dos termos do polinômio são as soluções do problema para
3, 4, 5, 6 e 7 camisas no total. O problema não tem solução para 2 ou menos ou 8 ou mais camisas.
Por conta desta propriedade, o polinômio _x³ + 3x^4 + 4x^5 + 3x^6 + x^7_ é chamado função 
geradora _f(x)_ do problema.

Conceitos Fundamentais
----------------------

Uma **série de potências** _S(x)_ é definida por uma sequência de coeficientes (_ai_) de modo que

        S(x) = sum{i=0..oo} aix^i

Da própria definição de série de potência podemos observar que qualquer polinômio _p(x)_ é uma
série de potência.

Considere um problema de combinatório _P(i)_ que dependa de um parâmetro _i_. Se a série de 
potências _S(x)_ é tal que a sequência de seus coeficientes (_ai_) são as soluções do problema
para o valor _i_, dizemos que _S(x)_ é a função geradora _f(x)_ do problema _P(i)_.

Por exemplo, considere o problema de se escolher _i_ elementos distintos dentre _n_ elementos,
todos distintos. A função geradora deste problema é a função _f(x)_

        f(x) = binom(n, 0) + binom(n, 1)x + binom(n, 2)x² + ... + binom(n, n)x^n

A expressão acima, embora correta, não é muito compacta. Na prática, desejamos encontrar para
_f(x)_ a expressão o mais sucinta possível. Das propriedades dos números binomiais temos que

        f(x) = (1 + x)^n

Uma função geradora fundamental é a função associada a sequência de uns (1, 1, 1, ....):

        f(x) = 1 + x + x^2 + .... = 1/(1 - x)

A soma infinita é igual a 1/(1 - x) nos casos em que _|x| < 1_. Porém, no estudo de funções
geradoras, não se atribui valores à variável _x_, de modo que não há preocupação com questões
de convergência. Tais séries são denominadas **séries formais**.

Soluções das Equações Lineares com Coeficientes Constantes: Uma Nova Perspectiva
--------------------------------------------------------------------------------

Voltemos ao problema de se contar o número de soluções distintas da equação

        x1 + x2 + ... + xr = n

com _xi > 0_. Associaremos o polinômio

        1 + x + x² + ...

a cada variável _xi_, o qual representa todos os valores possíveis para cada variável. A função
geradora será dada pelo produto destes polinômio, isto é,

        f(x) = (1 + x + x² + ...)(1 + x + x² + ...) ... (1 + x + x² + ...)
             = (1 + x + x² + ...)^r

Usando a soma da PG infinita temos que

        f(x) = 1/(1 - x)^r = (1 - x)^{-r}

Para se determinar o coeficiente do termo _xn_ de _f(x)_, podemos usar a série de Taylor com 
_a = 0_, de (1 - _x_)^_u_, para um _u_ real. Isto nos leva ao coeficiente binomial generalizado:

        binom_g(u, k) = u(u - 1)(u - 2) ... (u - k + 1)/k!

onde _k_ é um inteiro não-negativo e _u_ um número real. Por exemplo

        binom_g(1/2, 4) = (1/2)(-1/2)(-3/2)(-5/2)/4! = -15/384

Assim, o termo _xn_ de _f(x)_ terá coeficiente igual a

        (-1)^n binom_g(-r, n) = (-1)^n (-r)(-r - 1)(-r - 2) ... (-r - n + 1)/n!
                              = (-1)^n [(-1)^n r(r + 1)(r + 2) ... (r + n - 1)/n!
                              = [1 x 2 x ... x (r - 1)][r(r + 1)(r + 2) ... (r + n - 1)/(n!(r - 1)!)
                              = (n + r - 1)!/[n!(r - 1)!]
                              = binom(n + r - 1, r - 1)

a qual é a solução encontrada anteriormente. A igualdade acima é verdadeira sempre que _r_ for
um inteiro positivo.

<!-- Adicionar texto sobre funções geradoras exponenciais, e as propriedades das funções geradoras -->

Referências
-----------

SANTOS, José Plínio O., MELLO, Margarida P., MURARI, Idani T. [Introdução à Análise Combinatória](http://www.vestseller.com.br/matematica/introduc-o-a-analise-combinatoria-jose-plinio-margarida-mello-idani-murari), Editora Ciência Moderna, 2007.
