Logaritmos e Exponenciais
=========================

Os logaritmos e as exponencias aparecem, direta e indiretamente, em problemas de maratona, em
especial em problemas que tratam de grandes números. Sendo implementados, primariamente, como
funções reais, é preciso estar atento a possíveis problemas de precisão numérica.

Dito isto, o fundamental é conhecer bem os conceitos e as propriedades dos logaritmos e
exponenciais.

Exponenciais
------------

### Definição

Sejam _a, n_ dois números naturais. Então podemos definir _a_&#8319; (lê-se "_a_ elevado a _n_")
através da seguinte relação de recorrência, onde chamamos _a_ de **base** e _n_ de 
**expoente**:

* _a_¹ = _a_
* _a_&#8319; = _a_ x _a_&#8319;&#8315;¹

Em termos mais simples, a **exponenciação** é uma multiplicação repetida: basta multiplicar
_a_ por ele mesmo _n_ vezes. 

Como a operação de multiplicação de naturais é associativa, temos a primeira propriedade da
exponenciação: basta agrupar os termos do produto em dois conjuntos com _n_ e _m_ elementos
cada:

* _a_^{_n + m_} = _a_^{_n_} x _a_^{_m_} (exponencial da soma)

Também são decorrentes da multiplicação as propriedades

* (_a_^{_n_})^{m} = _a_^{_nm_} (exponencial da exponencial)
* (_ab_)&#8319; = _a_&#8319; x _b_&#8319; (exponencial do produto)

Podemos definir que, para qualquer _a_ natural,

* _a_&#8304; = 1

A título de curiosidade, 0&#8304; é uma indeterminação (para qualquer outro expoente natural,
0&#8319; = 0).

Esta definição é a que aprendemos no ensino fundamental e médio, e que servem bem para 
observar e aprender as propriedades fundamentais da exponenciação, porém é útil, na prática,
conhecer as definições de exponencial para outros tipos de expoente.

### Expoentes inteiros

Sejam _a, n_ dois números inteiros, com _a > 0_. Então podemos reescrever a recorrência 
anterior como

* _a_¹ = _a_
* _a_&#8319;&#8315;¹ = _a_&#8319; / _a_ 

Partindo do caso base temos que

* _a_&#8304; = _a_¹ / _a_ = 1 (daí a definição anterior para expoente igual a zero)
* _a_&#8315;¹ = _a_&#8304; / _a_  = 1 / _a_
* _a_&#8315;&#8319; = = 1 / _a_&#8319;

Assim podemos passar a trabalhar com expoentes negativos, e as propriedades já identificadas
são preservadas. Esta recorrência justifica a notação _a_&#8315;¹ para o inverso multiplicativo
de _a_, uma vez que _a_&#8315;¹ x _a_ = (1 / _a_) x _a_ = 1.

### Expoentes racionais

Sejam _a, n_ dois números inteiros, com _a > 0_. Qual seria o significado de _a_^{1/_n_}? 
Segundo as propriedades já descritas, este número seria a solução da equação _x_&#8319; = a.
A esta solução damos o nome de **raiz _n_-ésima de _a_**, e a usaremos para  definir a exponencial
para expoentes (e bases) racionais.

Sejam _n, m_ números inteiros com _m_ diferente de zero, e _a_ um número racional positivo. Então
_a_^{_n_/_m_} = (_a_^{1/_m_})&#8319;. 

Observe que esta definição pode ser estendida para bases negativas, desde que o **radical** 
(o fator 1 / _m_ do expoente) seja ímpar (mais precisamente, _m_ é ímpar). Por exemplo,
_x_³ = -1 tem solução nos racionais (_x_ = 1), mas _x_² = -1 não.

Bases negativas, em geral, podem violar a propriedade da exponencial da exponencial (por exemplo,
calcule ((-2)^{3/4})^{4/3} usando e não usando a referida propriedade e veja o resultado!), por 
isso a restrição comum de bases positivas.

### Expoentes reais

<!-- 
1. Definição de potenciação: natural, inteiro, racional, real
1. Exponenciação rápida
1. Definição do e
1. Serie de potência da exponencial
1. Exponenciais complexas
1. Definição de logaritmo
1. Propriedades
1. Definição por integral ou derivada de a^x
1. Mudança de base
1. Relação logaritmos/exponencial
-->

Logaritmos
----------

Sejam _a, x_ dois números reais tais que _a > 1_. Dizemos que _n_ é o logaritmo de _x_ na base
_a_ se _a&#8319; = x_. **Notação**: _n_ = log&#8336; _x_.

Duas importantes propriedades decorrente diretamente desta definição:

1. como a base _a_ é estritamente maior do que 1, o logaritmo não está definido para valores de 
_x_ menores ou iguais a zero;
1. log&#8336; 1 = 0, qualquer que seja a base _a_.

Referências
-----------

WIKIPEDIA. [Exponentiation](https://en.wikipedia.org/wiki/Exponentiation). Acesso em 22 de agosto de 2017.
