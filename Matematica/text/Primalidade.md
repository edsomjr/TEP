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

bool is_prime2(int n)
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

