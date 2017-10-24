Partições
=========

Uma **partição** de um inteiro positivo _N_ corresponde a um conjunto de inteiros positivos
{_a1, a2, ..., ak_} tais que _a1 + a2 + ... + ak = N_.

Por exemplo, para _N_ = 5 temos 7 partições distintas:

        5
        4 + 1
        3 + 2
        3 + 1 + 1
        2 + 2 + 1
        2 + 1 + 1 + 1
        1 + 1 + 1 + 1 + 1

Denotaremos _p(N)_ o total de partições de _N_. Primeiramente veremos como é possível computar
o valor de _p(N)_, em seguida veremos algumas propriedades e conceitos associados às partições.

Cálculo de _p(N)_
-----------------

Podemos interpretar o problema das partições como um problema do troco, onde as "moedas" seriam
os inteiros positivos de 1 a _N_. O estado seria dado pelo par (_N, M_), onde _N_ é o inteiro a
ser particionado e _M_ a próxima moeda a ser escolhida, se possível. Os casos bases seriam:

        state[0][M] = 1             // Uma única partição de zero: o conjunto vazio
        state[N][1] = 1             // Há uma única maneria de se particionar um número como somas de uns
        state[N][0] = 0             // As partições deve ser compostas apenas por números positivos

As transições serão dadas por

        state[N][M] = state[N][M - 1],  se M > N    // Não é possível pegar M: seguir para a próxima moeda estritamente menor que M
        state[N][M] = state[N - M][M] + state[N][M - 1],  se M <= N     // Ou pegar M ou ignorá-lo

Esta modelagem serve como base para a implementação abaixo, escrita em C++. Os elementos do vetor 
`state` devem ser inicializados, inicialmente, com o valor -1. 
```C++
ll dp(int N, int M)
{
    if (N == 0 or M == 1)
        return 1;

    if (M == 0)
        return 0;

    if (state[N][M] != -1)
        return state[N][M];

    auto& res = state[N][M];

    res = dp(N, M - 1);

    if (N >= M)
        res += dp(N - M, M);

    return res;
}

ll p(int N)
{
    return dp(N, N);
}
```

A implementação acima tem complexidade _O(N²)_, o que permite computar _p(N)_ para valores de
_N_ menores ou iguais a 10³.

Cada estado (_N, M_) da modelagem acima significa "o número de partições de _N_ que utilizam
valores, menores ou iguais a _M_". Podemos usar uma modelagem semelhante, mas como significado
ligeiramente diferente, o que será útil na definição de novos conceitos.

Seja _p(N, K)_ o número de partições de _N_ cujo maior elemento é igual a _K_. Os casos bases 
são

        p(0, 0) = 1                 // Uma única partição de zero com K = 0: { 0 }
        p(N, K) = 0,    se N <= 0   // As partições são contadas para inteiros positivos 
        p(N, K) = 0,    se K <= 0   // Os elementos da partição devem ser inteiros positivos

A transição seria

        p(N, K) = p(N - K, K) + p(N - 1, K - 1)

O primeiro termo da transição corresponde a tomar um termo _K_, que já garante a propriedade,
e tomar todas as possíveis partições de _N - K_ com a mesma restrição; a segunda parte 
corresponde às partições do antecessor _N - 1_ que tem elemento máximo _K - 1_: neste cenário,
basta escolher um dos elementos _K - 1_, somar +1 a ele e obter uma partição de _N_ com elemento
máximo _K_.

Para verificar que esta transição conta todos as partições com máximo _K_ corretamente, veja que
a primeira parte contabiliza as partições do caso especial _N = K_ e aquelas que tem dois
ou mais termos iguais a _K_; já a segunda parte conta apenas as partições que tem exatamente
um elemento igual a _K_.

O código abaixo computa a função _p(N, K)_, que será notada como _pk_.
```C++
ll pk(int N, int K)
{
    if (N == 0 and K == 0)
        return 1;

    if (N <= 0 or K <= 0)
        return 0;

    if (state[N][K] != -1)
        return state[N][K];

    auto& res = state[N][K];

    res = pk(N - K, K) + pk(N - 1, K - 1);

    return res;
}
```

Observe que _p(N) = pk(N, 1) + pk(N, 2) + ... + pk(N, N)_.

Gráfico de uma partição
-----------------------

É possível representar uma partição graficamente, e desta representação derivar uma importante
propriedade. Considere a partição 5 + 4 + 3 + 1 de 13. Vamos escrever cada valor em uma 
coluna:

        o  o  o  o 
        o  o  o
        o  o  o
        o  o
        o

Se observamos a transposta desta matriz,

        o  o  o  o  o
        o  o  o  o
        o  o  o
        o

suas colunas fornecem uma nova partição de 13: 4 + 3 + 3 + 2 + 1, a qual contém exatamente
5 elementos. A partição obtida através da transporta de uma partição dada é denominada
a **conjugada** da partição.

A relação entre uma partição e sua conjugada é que a conjugada contém o mesmo número de termos
que o maior termo da partição. Seja _q(N, K)_ a função que representa o número de partições de
_N_ que tem exatamente _K_ elementos. Então temos a importante relação:

        p(N, K) = q(N, K)

Uma partição é denominada **autoconjugada** se ela é igual a sua conjugada. Por exemplo,
a partição 3 + 2 + 1 de 6 é autoconjugada: veja sua matriz abaixo

        o  o  o
        o  o
        o

As partições autoconjugadas também tem uma importante propriedade. Considere a partição
6 + 5 + 4 + 4 + 2 + 1 de 22, e veja a separação em níveis feitas pelas barras:

        o   o   o   o   o   o
          |------------------
        o | o   o   o   o
          |   |----------
        o | o | o   o
          |   |   |--
        o | o | o | o
          |   |
        o | o |
          |
        o | 

Esta é uma permutação autoconjugada, e a soma dos elementos de cada nível gera a partição
11 + 7 + 3 + 1, uma partição de 22 que contém apenas números ímpares distintos. Isto
nos leva a outro importante resultado: _o número de partições autoconjugadas de N é igual ao
número de partições de N que contém apenas fatores ímpares distintos_.

Por fim, a função _q(N, K)_ tem uma importante interpretação combinatorial: ela determina o 
número de maneiras de se distribuir _n_ objetos idênticos, em _k_ caixas idênticas, sem que
nenhuma das caixas fique vazia.

Referências
-----------

SANTOS, José Plínio O., MELLO, Margarida P., MURARI, Idani T. [Introdução à Análise Combinatória](http://www.vestseller.com.br/matematica/introduc-o-a-analise-combinatoria-jose-plinio-margarida-mello-idani-murari), Editora Ciência Moderna, 2007.

WIKIPEDIA. [Partition](https://en.wikipedia.org/wiki/Partition_(number_theory)). Acesso em 06/10/2017.

