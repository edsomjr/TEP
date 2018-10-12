Simulações
==========

Muitos problemas matemáticos consistem em simular exatamente os passos ou critérios descritos no
problema. Neste sentido, a técnica fundamental para a solução de tais problemas é a busca
completa (força bruta), sendo que a poda é crucial em problemas mais difíceis.

Vários destes problemas tem solução fechada, na forma de uma expressão geral, a qual pode não
ser óbvia. Nestes casos, se o tamanho da entrada permitir que a solução de busca completa 
seja aceita dentro
do limite de tempo estabelecido, é melhor usar tal solução ao invés de tentar encontrar a solução
fechada, o que pode tomar um tempo precioso da equipe.

A poda pode e deve ser aplicada quando possível. Nos problemas de simulação, a poda é baseada nas 
propriedades das expressões que modelam o problema (identidades trigonométricas, propriedades
das operações fundamentais, zeros de polinômios, dentre outros). Contudo, a poda é um recurso 
para diminuir o tempo de execução (ou mesmo a complexidade assintótica, em alguns casos), de modo
que deve ser considerada apenas quando a solução mais simples, sem poda, não atingir o limite
de tempo estabelecido.

Exemplo
-------

É comum em problemas de matemática que surja a seguinte questão: dado um inteiro
_N_ positivo, qual é o maior inteiro _m_ tal que N &#8805; _m_(_m_ + 1)/2. Há três abordagens
possíveis para este problema, com diferentes complexidades e características.

#### Busca completa

Uma possível solução para este problema consiste em testar, um a um, todos os inteiros menores ou
iguais a _N_ em busca da resposta, com complexidade _O(N)_.
```C++
int solve(int N)
{
    int m = 1;

    for (int i = 2; i <= N; ++i)
        if (i*(i + 1)/2 <= N)
            m = i;

    return m;
}
```

A implementação acima, embora correta para valores pequenos de _N_, falha no caso geral: se
1 &#8804; N &#8804; 10&#8313;, por exemplo, teremos um _overflow_ na condição do `if`, 
comprometendo
a corretude do resultado. Além disso, o algoritmo testa vários valores desnecessariamente: se
_i_ for maior do que a raiz quadrada de _N_, a condição sempre será falsa. Fazendo este
ajuste e corrigindo o tipo base para `long long`, temos uma nova solução com complexidade
_O(&#8730;N)_.
```C++
long long solve2(long long N)
{
    long long m = 1;

    for (long long i = 2; i * i <= N; ++i)
        if (i*(i + 1)/2 <= N)
            i = m;

    return m;
}
```

Embora seja nítido o ganho de performance e de complexidade, ainda é possível melhorar esta
complexidade, usando para tal uma busca binária.

#### Busca binária

Podemos determinar o valor de _m_ por meio da busca binária: sabendo que a solução se encontra
no intervalo [1, _N_], podemos, a cada etapa, testar o elemento médio do intervalo como
possível solução e atualizar a mesma, quando for o caso. Assim, teremos uma solução com 
complexidade _O(N log N)_.
```C++
long long solve3(long long N)
{
    long long m = 1, a = 1, b = N;

    while (a <= b)
    {
        long long c = (a + b)/2;

        if (c*(c + 1)/2 <= N)
        {
            m = max(m, c);
            a = c + 1;
        } else
            b = c - 1;
    }

    return m;
}
```

Esta abordagem, embora não seja a mais eficiente em termos de complexidade, tem uma grande
vantagem: como trabalhamos apenas com números inteiros (a divisão `c*(c + 1)/2` resulta sempre em 
um inteiro), não há possíveis erros devido a precisão. A solução fechada, em _O(1)_,
depende de aritmética de ponto flutuante, o que pode levar ao resultado errado em determinados
casos.

#### Solução fechada

Efetivamente o problema ser resolvido consiste em determinar o zero positivo do polinômio
_p(m) = m² + m - 2N_. Pelo teorema de Báskara temos que _m = (-1 + &#8730;(1 + 8m))/2_, um 
número real. A solução deseja seria, portanto, `floor(m)`, o maior inteiro menor ou igual a 
_m_. Como podemos ter um erro de precisão numérica, efetivamente a solução pode ficar errada
para menos: isto pode ser testado e corrigido, se necessário.
```C++
long long solve4(long long N)
{
    long long m = (-1 + sqrt(1 + 8*m))/2;

    return (m + 1)*(m + 2)/2 <= N ? m + 1 : m;
}
```

### Exercícios

1. UVA
    1. [616 - Coconuts, Revisited](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=557)
    1. [834 - Continued Fractions](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=775)
    1. [1225 - Digit Counting](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3666)
    1. [10346 - Peter's Smokes](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1287)
    1. [11254 - Consecutive Integers](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2221) 

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.
