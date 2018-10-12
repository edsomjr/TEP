# Parte A

1. **Complete a sentença**: Em uma estrutura não-linear, os elementos são organizados de forma `______________`
1. Qual é a complexidade das operações de inserção/remoção/busca na estrutura `map` do C++?
1. Das estruturas disponı́veis na API do C++ listadas abaixo, quais delas são implementadas usando árvores binárias de busca balanceadas?
    - [ ] `map`
    - [ ] `set`
    - [ ] `bitset`
    - [ ] `priority_queue`
1. Descreva brevemente, com um exemplo de uso, cada uma das estruturas de C++ abaixo:
    1. `map`
    1. `set`
    1. `multimap`
    1. `multiset`
1. Quais estruturas em C++ são implementadas usando o conceito de _hash_? Qual é a complexidade média esperada para as operações de inserção e remoção?
1. Defina o conceito de iteradores em C++ e dê um exemplo de uso em uma estrutura não-linear.
1. Declare uma `priority_queue` de elementos do tipo `double` que mantenha, em seu topo, o menor dentre os elementos já inseridos.

# Parte B

1. Qual é a diferença entre uma _heap_ e uma árvore binária de busca? Qual operação da árvore binária de busca não se aplica às _heaps_?
1. Qual é a diferença entre os três algoritmos de ordenação da API do C++, a saber: `sort`, `partial_sort` e `stable_sort`? Determine a complexidade assintótica de cada um deles.
1. Em competições de programação que permitem ao participante _“hackear”_ o código de outros participantes é desaconselhado o uso das estruturas `unordered_set` e `unordered_map`. Justifique o porquê e apresente uma alternativa à estas estruturas.
1. A propriedade de uma _heap_ binária pode ser violada caso exista algum nó cujo valor seja maior do que o valor de seu nó pai. O algoritmo abaixo restaura a propriedade da _heap_:
    ```ruby
    # Algoritmo 1: Restauração da propriedade da heap binária
    # Entrada: O ı́ndice i do nó a ser corrigido.
    # Saída: Ao final do procedimento, a propriedade da heap está garantida.
    procedure swin(i)

        p ← i/2

        if i > 1 and value(i) > value(p) then
            swap(i, j)
            swin(p)
        end if

    end procedure
    ``` Implemente o pseudocódigo acima em C++.
1. O algoritmo abaixo implementa uma heap em Python. Reimplemente o mesmo código em C++.
    ```python
    class Heap:

        def __init__(self):

            self.N = 0
            self.xs = [0]       


        def add(self, x):

            self.N += 1

            if len(self.xs) > self.N:
                self.xs[self.N] = x
            else:
                self.xs.append(x)

            self._swin(self.N)


        def empty(self):

            return self.N == 0

        
        def extract_max(self):
            M = self._top()
            self._pop()
            return M

            
        def _top(self):

            return self.xs[self.N]


        def _pop(self):

            self.xs[1], self.xs[self.N] = self.xs[self.N], self.xs[1]
            del self.xs[-1]
            self.N -= 1
            self._sink(1)


        def __str__(self):

            if len(self.xs[1:]) > 0:
                return ','.join([str(x) for x in self.xs[1:]])
            else:
                return ''


        def _parent(self, i):

            return i/2


        def _left(self, i):
            
            return 2*i


        def _right(self, i):

            return 2*i + 1


        def _swin(self, i):

            p = self._parent(i)

            if i > 1 and self.xs[i] > self.xs[p]:
                self.xs[i], self.xs[p] = self.xs[p], self.xs[i]
                self._swin(p)

        def _sink(self, i):

            L = self._left(i)
            R = self._right(i)

            if R <= self.N and self.xs[R] > self.xs[L]:
                M = R
            else:
                M = L

            if M <= self.N and self.xs[M] > self.xs[i]:
                self.xs[i], self.xs[M] = self.xs[M], self.xs[i]
                self._sink(M)
    ```
