Motivação
---------

A Geometria Computacional é uma área recente (anos 70), mas ainda assim é um
tópico frequente em maratonas de programação.
Contudo, os competidores devem postergar a solução de problemas desta área
para o meio ou o fim do _contest_, pois a probabilidade de um AC é baixa por
tais problemas

1. possuírem muitos _corner cases_, e estes casos especiais devem ser tratados
com atenção e cuidado;
1. poderem receber WA devido erros de precisão inerentes às variáveis em ponto
flutuante;
1. envolverem operações que são triviais quando feitas com caneta e lápis, mas se
tornam razoavelmente complicadas quando precisam ser implementadas em computador;
1. apresentarem uma solução cuja codificação pode ser longa e tediosa.

Para atacar tais problemas, o competidor tem que se preparar previamente,
registrando, em suas anotações, as fórmulas básicas e implementações testadas
dos algoritmos clássicos da geometria.

Na implementação da solução de problemas de Geometria Computacional, valem as
seguintes observações e dicas:

1. tratar todos os _corner cases_ ou procurar implementações que os evitem;
1. evitar o uso de variáveis do tipo ponto flutuante sempre que possível;
1. se não for possível, definir um limiar _e_ (em geral, _e = 10^{-9}_) para
o teste de igualdades:
    1. _a == b <=> fabs(a - b) < e_;
    1. _a >= 0 <=> a > -e_;
    1. _a <= 0 <=> a < e_;
    ```C++
    // Comparação de igualdade entre variáveis do tipo ponto flutuante
    #define EPS 1e-9

    bool equals(double a, double b)
    {
        return fabs(a - b) < EPS;
    }
    ```
1. caso seja necessário usar variáveis do tipo ponto flutuante, utilizar
**double** ao invés de **float**;
1. tomar cuidado com a impressão do zero: em determinados casos, pode ser
impresso o sinal de negativo!
1. atentar às retas verticais, as quais podem constituir casos especiais do
problema.

Há 3 abordagens possíveis para um problema de Geometria Computacional:

1. **Geometria Analítica**: as figuras geométricas são localizadas no espaço
através das coordenadas de seus pontos/vértices. São usadas equações para
representar figuras e relações, e novas relações podem ser deduzidas através
da combinação e manipulação destas expressões. É a abordagem mais comum das
três;
1. **Geometria Plana**: as figuras são descritas por suas propriedades, e a
posição absoluta no espaço não é importante, apenas a distância relativa entre
duas ou mais figuras. As relações são descobertas através de simetrias e
semelhanças. É a abordagem menos comum, mas pode simplificar os problemas
quando bem utilizada;
1. **Álgebra Linear**: segmentos de retas são interpretados como vetores, e
transformações como rotações e translações podem simplificar problemas ao
deslocá-las para uma nova origem. Muito útil para descobrir relações que
seriam muito trabalhosas de se verificar utilizando apenas a Geometria
Analítica.

Um bom competidor deve dominar as três abordagens, principalmente a primeira e
a última. A primeira leva a fórmulas fechadas em vários casos, e é útil para
montar o material de consulta. As técnicas da terceira podem ser utilizadas
nas maratonas para procurar relações, simplificar problemas ou evitar
_corner cases_, e deve ser praticada sempre que possível.

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

O'ROURKE, Joseph. [Computational Geometry in C](https://www.amazon.com.br/Computational-Geometry-Associate-Professor-Computer/dp/0521649765/ref=sr_1_1?ie=UTF8&qid=1471650316&sr=8-1&keywords=computational+geometry+in+c), 2nd edition, Cambridge University Press, 1998.

SKIENA, Steven S.; REVILLA, Miguel A. [Programming Challenges: The Programming Contest Training Manual](http://www.programming-challenges.com/), Springer, 2002.
