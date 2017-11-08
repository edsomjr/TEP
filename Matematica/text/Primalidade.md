Números Primos
==============

O estudo dos números primos é parte central da Teoria dos Números. O Teorema Fundamental da 
Aritmética, que estabelece que todos os números naturais ou são primos ou são produto de primos,
mostra a importância fundamental de tais números. Nesta seção veremos os principais conceitos
e resultados associados aos números primos que aparecem com frequência em maratonas de 
programação.

Conceitos Fundamentais
----------------------

Seja _p_ um número inteiro positivo. Dizemos que _p_ é **primo** se ele possui exatamente dois
divisores positivos (a saber, o próprio _p_ e o número um, caso _p_ seja diferente de um). Veja
que, segundo esta definição, o número 1 não é primo, pois possui um único divisor positivo.

Ainda segundo a definição, o menor número primo, e o único que é par, é o número 2. Os próximos
números primos são, a saber, 3, 5, 7, 11, 13, 17, 19, 23, ...

Também decorre da definição que se _p_ e _q_ são primos e _p_ divide _q_, então _p = q_. Outra
consequência relacionada à divisibilidade é que, se _p_ é primo e divide o produto _ab_, então
_p_ divide _a_ ou _p_ divide _b_ (aqui o **ou** é inclusivo: pode acontecer que _p_ divida 
ambos).

Um número natural _m > 1_ que não é primo é denominado **composto**. 

O primeiro problema que surge em relação aos primeiro é o da **identificação**: dado um inteiro
positivo _n_, como identificar se ele é ou não primo? Trataremos desta questão na próxima seção.

Identificação de números primos
-------------------------------

Para se determinar se um inteiro positivo _n_ é ou não primo podemos recorrer diretamente à
definição de primos e fazer uma busca completa dos possíveis divisores: caso encontremos um
divisor que seja diferente de um ou do próprio _n_, então _n_ será composto. Veja a 
implementação abaixo.
```C++
bool is_prime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i < n; ++i)
        if (n % i == 0)
            return false;

    return true;
}
``` 

A implementação acima, embora seja de fácil entendimento e codificação, tem complexidade _O(n)_,
com o agravante que a principal operação realizada no laço é a divisão inteira, que é 
computacionalmente exigente (ao contrário da adição e multiplicação que, em geral, podem ser 
feita em um ciclo do processador). Esta implementação também faz muitas operações "desnecessárias":
por exemplo, se o número for ímpar, qualquer tentativa de se encontrar um divisor par é 
infrutífera. Veja a segunda versão da implementação, que reduz a quantidade de operações
realizadas.
```C++
bool is_prime2(int n)
{
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i < n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}
```

Embora a nova versão realize um número reduzido de operações em relação à versão anterior, a
complexidade não foi reduzida, permanecendo em _O(n)_. Para reduzirmos a complexidade, temos que
observar que devemos procurar um possível divisor não até _n_, mas apenas até a sua raiz 
quadrada. Isto se deve ao fato de que se _d_ divide _n_, então _n = dk_, e ou _d_ ou _k_ devem
ser menores ou iguais à raiz quadrada de _n_, pois se ambos fossem maiores o produto _dk_ seria
maior do que _n_, uma contradição. Isto nos leva a terceira versão, agora com complexidade
_O(sqrt(n))_.
```C++
#include <cmath>

bool is_prime3(int n)
{
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;

    return true;
}
```

É possível reduzir ainda a complexidade desta implementação, uma vez que os candidatos à 
divisores são os ímpares entre 3 e a raiz de _n_. Se tivermos, precomputados, os primos menores
ou iguais a raiz _n_, e usar apenas primos como candidatos a divisores, a complexidade se torna
_O(pi(n))_, onde a função _pi(n)_ retorna o número de primos menores ou iguais a _n_. 
Na prática, se desejamos identificar um ou poucos números, a implementação acima é suficiente;
para muitas identificações, pode ser útil gerar uma lista de primos de antemão, que permitirá
a identificação imediata de números dentro do seu intervalo e acelerará a complexidade da
rotina acima para números menores ou iguais ao quadrado do maior primo pré-computado.

Gerar um lista com os _N_ primeiros primos é a próxima tarefa, a ser explicada na próxima seção.

Listagem dos _N_ primeiros primos
---------------------------------

Uma maneira de se gerar os _N_ primeiros primos seria iterar sobre estes inteiros, e para cada
um deles chamar a função `is_prime3()`. A complexidade seria _O(N*pi(N))_.
```C++
vector<int> primes(int N)
{
    vector<int> ps;

    for (int i = 2; i <= N; ++i)
        if (is_prime3(i))
            ps.push_back(i);

    return ps;
}
```

Contudo, há uma forma mais eficiente de gerar esta lista, usando o Crivo de Erastótenes. A ideia
do crivo é "eliminar" os números compostos, que podem ser identificados imediatamente como
múltiplos de um primo dado. Para ilustrar a ideia, considere _N = 50_. Inicialmente listamos todos
os números positivos menores ou iguais a _N_:

         1    2    3    4    5    6    7    8    9   10
        11   12   13   14   15   16   17   18   19   20
        21   22   23   24   25   26   27   28   29   30
        31   32   33   34   35   36   37   38   39   40
        41   42   43   44   45   46   47   48   49   50

Inicialmente podemos "crivar" o 1, que não é primo:

         x    2    3    4    5    6    7    8    9   10
        11   12   13   14   15   16   17   18   19   20
        21   22   23   24   25   26   27   28   29   30
        31   32   33   34   35   36   37   38   39   40
        41   42   43   44   45   46   47   48   49   50

O próximo número da sequência (2) é primo. Devemos, portanto, crivar todos os seus múltiplos, que
serão compostos, resultando em

         x    2    3    x    5    x    7    x    9    x
        11    x   13    x   15    x   17    x   19    x
        21    x   23    x   25    x   27    x   29    x
        31    x   33    x   35    x   37    x   39    x
        41    x   43    x   45    x   47    x   49    x

Seguindo a sequência, o próximo número não crivado (3), também é primo. Vamos eliminar os seus
múltiplos que não foram crivados ainda:

         x    2    3    x    5    x    7    x    x    x
        11    x   13    x    x    x   17    x   19    x
         x    x   23    x   25    x    x    x   29    x
        31    x    x    x   35    x   37    x    x    x
        41    x   43    x    x    x   47    x   49    x

O próximo não crivado é 5. Novamente removendo seus múltiplos teremos:

         x    2    3    x    5    x    7    x    x    x
        11    x   13    x    x    x   17    x   19    x
         x    x   23    x    x    x    x    x   29    x
        31    x    x    x    x    x   37    x    x    x
        41    x   43    x    x    x   47    x   49    x

Seguindo com o 7, temos

         x    2    3    x    5    x    7    x    x    x
        11    x   13    x    x    x   17    x   19    x
         x    x   23    x    x    x    x    x   29    x
        31    x    x    x    x    x   37    x    x    x
        41    x   43    x    x    x   47    x    x    x

Como o próximo número, 11, é maior do que a raiz quadrada de 50, podemos interromper o processo:
os números não crivados formam a relação de todos os primos menores ou iguais a `N`. Abaixo
uma implementação em C++: o vetor de _bits_ `sieve` é usado para marcar os números (zero ou falso
indica que o número é composto).
```C++
#include <bitset>
#include <vector>

vector<int> primes(int N)
{
    bitset<MAX> sieve;      // MAX deve ser maior ou igual a N
    vector<int> ps;

    sieve.set();            // Todos são "potencialmente" primos
    sieve[1] = false;       // 1 não é primo

    for (int i = 2; i <= N; ++i)
    {
        if (sieve[i])       // i é primo
        {
            ps.push_back(i);

            for (int j = 2 * i; j <= N; j += i)
                sieve[j] = false;
        }
    }

    return ps;
}
```

Na implementação acima, para cada `i` são crivados `n/i` números. Logo o número total de
operações é aproximadamente `n` vezes o número harmônico, isto é,

    n + n/2 + n/3 + ... + n/n = n(1 + 1/2 + 1/3 + ... + 1/n) <= n log n

pois `log n` é o valor da integral de 1 até `n` da função `1/x`. Veja que a aproximação acima
considera os valores de `i` compostos, e usamos apenas primos: uma melhor aproximação seria

    n/2 + n/3 + n/5 + n/7 + n/11 + ... <= n log log n

pelo segundo teorema de Merten. Logo a complexidade do crivo é _O(N log log N)_.

A implementação acima, sem otimização, gera os primos de 1 a 10^7 em aproximadamente 1 segundo
(957 ms) em um i7 com 8 GHz de memória. É possível diminuir a constante de complexidade e 
obter um melhor tempo de execução, como veremos a seguir.

Primeiramente, podemos tratar os números pares à parte: 2 é o único primo par, e os demais pares
compostos não contribuem para o crivo. Ignorando também o 1, temos esta segunda versão do crivo:
```C++
vector<int> primes2(int N)
{
    bitset<MAX> sieve;      // MAX deve ser maior ou igual a N
    vector<int> ps;

    sieve.set();            // Todos são "potencialmente" primos

    ps.push_back(2);        // Os pares são tratados à parte

    for (int i = 3; i <= N; i += 2)     // Apenas ímpares são verificados agora
    {
        if (sieve[i])       // i é primo
        {
            ps.push_back(i);

            for (int j = 2 * i; j <= N; j += i)
                sieve[j] = false;
        }
    }

    return ps;
}
```

Esta nova versão gera os mesmos primos em aproximadamente 720 ms. 
Veja que, embora só passemos por primos no laço externo, no laço interno passamos por pares
desnecessariamente. Outra observação importante: o crivo deve começar no quadrado de `i`, pois
quaisquer múltiplos anteriores já foram crivados ou ignorados. Assim temos a terceira versão
do crivo:
```C++
vector<long long> primes(long long N)
{
    bitset<MAX> sieve;      // MAX deve ser maior ou igual a N
    vector<long long> ps;

    sieve.set();            // Todos são "potencialmente" primos

    ps.push_back(2);        // Os pares são tratados à parte

    for (long long i = 3; i <= N; i += 2)     // Apenas ímpares são verificados agora
    {
        if (sieve[i])       // i é primo
        {
            ps.push_back(i);

            for (long long j = i * i; j <= N; j += 2*i)
                sieve[j] = false;
        }
    }

    return ps;
}
```

Para evitar problemas de _overflow_ com a condição do laço interno, o tipo de dado foi alterado
para `long long`. Esta nova versão roda em aproximadamente 360 ms. 

Uma maneira de verificar rapidamente se o crivo está produzindo os primos corretamente é checar
o número de primos gerados, segundo a tabela abaixo, retirada de [primes.utm.edu](https://primes.utm.edu/howmany.html):

        n           pi(n)
        10          4
        100         25
        1000        168
        10000       1229
        100000      9592
        1000000     78498
        10000000    664579


Referências
-----------

PRIMES.UTM.EDU. [How Many Primes Are There?](https://primes.utm.edu/howmany.html). Acesso eme 08/11/2017.

WIKIPEDIA. [Harmonic Number](https://en.wikipedia.org/wiki/Harmonic_number). Acesso em 08/11/2017.

WIKIPEDIA. [Mertens' theorems](https://en.wikipedia.org/wiki/Mertens%27_theorems). Acesso eme 08/11/2017.
