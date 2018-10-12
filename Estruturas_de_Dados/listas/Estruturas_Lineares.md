# Parte A

1. **Complete a sentença**: Em uma estrutura linear, os elementos formam uma `______________`
1. Marque as estruturas abaixo que são estruturas lineares:
    - [ ] _array_
    - [ ] árvore binária de busca
    - [ ] fila
    - [ ] grafo
    - [ ] heap
    - [ ] lista
    - [ ] pilha
    - [ ] vetor
1. Marque as bibliotecas de C++ abaixo que implementam estruturas lineares:
    - [ ] `bitset`
    - [ ] `deque`
    - [ ] `map`
    - [ ] `queue`
    - [ ] `set`
    - [ ] `stack`
    - [ ] `vector`
1. **Preencha os espaços com uma das opções sugeridas**: Um tipo de dado abstrato é definido pela sua `______________` (implementação/interface). Cada tipo de dado abstrato tem `______________` (uma única implementação/várias implementações possíveis) e `______________` (uma única interface/várias interfaces possíveis).
1. Defina:
    1. uma lista encadeada
    1. uma lista duplamente encadeada
    1. uma lista auto-organizável
    1. uma _skip list_
1. Em uma estrutura FIFO:
    - [ ] O primeiro elemento a entrar é o primeiro a sair
    - [ ] O primeiro elemento a entrar é o último a sair
    - [ ] O último elemento a entrar é o primeiro a sair
    - [ ] O último elemento a entrar é o último a sair
1. Em uma estrutura LIFO:
    - [ ] O primeiro elemento a entrar é o primeiro a sair
    - [ ] O primeiro elemento a entrar é o último a sair
    - [ ] O último elemento a entrar é o primeiro a sair
    - [ ] O último elemento a entrar é o último a sair
1. Complete o quadro abaixo assinalando, em cada coluna, as operações "eficientes" da estrutura:

    |         Característica         | _array_ | vetor | lista | pilha | fila |
    |:------------------------------:|:-------:|:-----:|:-----:|:-----:|:----:|
    | Acesso aleatório aos elementos |         |       |       |       |      |
    | Inserção                       |         |       |       |       |      |
    | Inserção no início             |         |       |       |       |      |
    | Inserção no fim                |    x    |       |       |       |      |
    | Remoção                        |         |       |       |       |      |
    | Remoção no início              |         |       |       |       |      |
    | Remoção no fim                 |         |   x   |       |       |      |
    | Busca                          |         |       |       |       |      |

# Parte B

1. Dê uma definição precisa de estrutura linear.
1. Usando a definição acima, quais das estruturas listadas a seguir seriam consideradas estruturas lineares?
    - [ ] _arrays_
    - [ ] filas
    - [ ] listas circulares
    - [ ] listas com prioridades
    - [ ] pilhas
    - [ ] _skpip lists_
1. Implemente, em C++, uma lista circular.
1. Escreva um algoritmo, em pseudocódigo, que implemente a inserção de um elemento em uma lista duplamente encadeada.
1. Quais são as vantagens e as desvantagens de se substituir uma lista duplamente encadeada por uma lista simplesmente encadeada?
1. O algoritmo abaixo implementa uma pilha em Python. Reimplemente o mesmo código em C++.

    ```python
    class Stack:

        def __init__(self):
            self.elemes = []

        def push(self, x):
            self.elems.append(x)

        def pop(self):
            return self.elems.pop()

        def __str__(self):
            xs = [str(x) for x in self.elems[::-1]]
            return '(' + ' '.join(xs) + ')'

        def empty(self):
            return len(self.elems) == 0

    if __name__ == '__main__':

        s = Stack()
        print 'Nova pilha = {}, vazia? {}'.format(s, s.empty())

        s.push(1)
        s.push(2)
        s.push(3)
        print 'Apos insercoes =', s

        print 'topo = {}'.format(s.pop())
        print 'nova pilha = {}, vazia? {}'.format(s, s.empty())
    ```
1. O pseudocódigo abaixo implementa a remoção de um elemento em uma lista encadeada. Implemente o algoritmo em sua linguagem de preferência.

    ```ruby
    # Algoritmo 1: Remoção de elemento de lista encadeada
    # Entrada: Uma lista encadeada L e a posição do elemento n a ser removido
    # Saída: A lista remanescente, após a remoção do n-ésimo elemento

    if L.size >= n then
      return
    end if

    p <- L.head
    q <- null
    i <- 1

    while i < n do
      q <- p
      q <- p.next
      i <- i + 1
    end while

    if q != null then
      q.next <- p.next
    end if

    L.head <- p.next
    delete p

    return
    ```
