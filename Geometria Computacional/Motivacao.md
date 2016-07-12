Motivação
---------

A Geometria Computacional é um tópico frequente em maratonas de programação. 
Contudo, os competidores devem postergar a solução de problemas desta área 
para o meio ou o fim do _contest_, pois a probabilidade de um AC é baixa porque
tais problemas

1. possuem muitos _corner cases_, e estes casos especiais devem ser tratados
com atenção e cuidado;
1. podem receber WA devido erros de precisão inerentes às variáveis em ponto 
flutuante;
1. envolvem operações que são triviais quando feitas com caneta e lápis, mas se
tornam razoavelmente complicadas quando precisam ser implementadas em computador;
1. a codificação da solução pode ser longa e tediosa.

Para atacar tais problemas, o competidor tem que se preparar previamente, 
registrando, em suas anotações, as fórmulas básicas e implementações testadas
dos algoritmos clássicos da geometria.

Na implementação da solução de problemas de Geometria Computacional, o ideal é

1. tratar todos os _corner cases_ ou procurar implementações que os evite;
1. evitar o uso de variáveis do tipo ponto flutuante sempre que possível;
1. se não for possível, definir um limiar _e_ (em geral, _e = 10^{-9}_) para
o teste de igualdades:
    1. _a == b <=> fabs(a - b) < e_;
    1. _a >= 0 <=> a > -e_;
    1. _a <= 0 <=> a < e_;

### Referências

HALIM, Steve; HALIM, Felix. [Competitive Programming 3](http://cpbook.net/), Lulu, 2013.

SKIENA, Steven S.; REVILLA, Miguel A. [Programming Challenges: The Programming Contest Training Manual](http://www.programming-challenges.com/), Springer, 2002.
