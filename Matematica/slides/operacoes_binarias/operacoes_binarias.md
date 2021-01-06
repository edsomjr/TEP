---
theme: gaia
backgroundColor: black
color: lightGray
headingDivider: 2
---

<style>
    section {
        font-size: 30px;
    }

    h1 {
        font-size: 70px;
    }
</style>

<!-- _class: lead -->
# Matemática

*__Operações Binárias__*

Prof. Edson Alves
Faculdade UnB Gama

## Operações _bit_ a _bit_

- As operações _bit_ a _bit_ se comportam da mesma maneira do que suas equivalentes da lógica booleana, considerando o valor `0` (zero) como falso e `1` (um) como verdadeiro

- As representações binárias dos operandos devem estar alinhadas (com o mesmo número de dígitos) antes da operação

- Se necessário, devem ser adicionados zeros à esquerda

## Operações _bit_ a _bit_

- A operação `&` (e, _and_) resulta em verdadeiro somente quando os ambos _bits_ são verdadeiros 

- A operação `|` (ou, _or_) resulta em falso somente quando ambos _bits_ são falsos

- A operação `^` (ou exclusivo, _xor_) resulta em falso somente quando ambos _bits_ são iguais

- A operação `~` (negação, _not_) é unária e inverte todos os _bits_ do operando

## Visualização das operações _bit_ a _bit_

![bg invert 45%](figs/ops.svg)

## Deslocamentos binários

- O operador `<<` (deslocamento à esquerda, _left shift_) adiciona o número indicado ($k$) de _bits_ iguais a zero à direita do número

- A operação equivale à uma multiplicação por $2^k$, de modo que é preciso tomar cuidado com um possível _overflow_ 

- O operador `>>` (deslocamento à direita, _right shift_) adiciona o número indicado ($k$) de _bits_ iguais a zero à esquerda do número

- A mesma quantidade de _bits_ à direita são desprezados

## Deslocamentos binários

- Se o sinal é propagado, a operação é denominada deslocamento à direita aritmético; caso contrário, deslocamento à direita binário

- No caso do operador aritmético, a operação equivale à uma divisão inteira euclidiana por $2^k$

- Em C/C++, o operador `>>` é aritmético e a divisão inteira (`/`) não é euclidiana (é a divisão de menor resto)

## Exemplos de deslocamentos binários

```C++
int main()
{
    int a = 12345, b = -98;

    cout << (a << 2) << endl;   // 49380
    cout << (a >> 3) << endl;   // 1543

    cout << (b << 2) << endl;   // -392
    cout << (b >> 3) << endl;   // -13

    cout << b / 8 << endl;      // -12

    return 0;
}
```

## Máscaras binárias

- Uma máscara binária é um padrão binário que permite a localização, extração ou alteração de determinados _bits_ de uma representação binária

- A máscara `(1 << k)` corresponde a todos os _bits_ iguais a zero, exceto o $k$-ésimo _bit_, que é igual a um

- Esta máscara permite a leitura do $k$-ésimo _bit_ de um número através do operador `&`

## Máscaras binárias

- Esta mesma máscara permite ligar o $k$-ésimo _bit_ de um número através do operador `|`

- A negação desta máscara (`~(1 << k)`) permite desligar o $k$-ésimo _bit_ de um número por meio do operador `&`

- A máscara `(1 << k) - 1)`} permite a extração dos $k$ _bits_ menos significativos de um número através do operador `&`

## Exemplo de uso de máscaras binárias

```C++
unsigned long rotate_right(unsigned long n, int k)
{
    unsigned long R = (n >> k);
    unsigned L = n & ((1 << k) - 1);

    return L << (8*sizeof(unsigned long) - k) | R;
}

int main() {
    unsigned long n = 0x12345678;

    printf("0x%08lx\n", rotate_right(n, 8));  // 0x78123456
    printf("0x%08lx\n", rotate_right(n, 16)); // 0x56781234
    printf("0x%08lx\n", rotate_right(n, 3));  // 0x02468acf

    return 0;
}
```

## _Bit_ menos significativo

- O _bit_ menos significativo (_least significant bit_ - LSB) de um inteiro $n$ pode ser extraído em $O(1)$

- Basta fazer a conjunção de $n$ com seu simétrico $-n$

- Em C/C++, `LSB(n) = n & -n`

- É possível desligar o LSB com a expressão `(n & ~LSB(n))`

- Porém a expressão `CLSB(n) = n & (n - 1)` é equivalente, gerando o mesmo resultado porém com uma sintaxe mais simples e eficiente

- A rotina `CLSB(n)` pode ser usada para contar o número de _bits_ ligados de $n$, com complexidade $O(m)$, onde $m$ é o número de _bits_ ligados de $n$

## Exemplo de rotinas com LSB em C++

```C++
int LSB(int n) { return n & -n; }
int CLSB(int n) { return n & (n - 1); }

int bit_count(int n)
{
    int count = 0;

    while (n)
    {
        ++count;
        n &= (n - 1);
    }

    return count;
}
```

## Funções do GCC

- O GCC oferece uma série de funções de baixo nível para manipulação binária

- A função `__builtin_popcount(x)` retorna o número de _bits_ ligados de $x$

- A função `__builtin_clz(x)` retorna o número de zeros à esquerda na representação binária de $x$ (_clz - count leading zeroes_)

- A função `__builtin_ctz(x)` o número de zeros à direita na representação binária de $x$ (_ctz - count trailing zeroes_)

- As duas funções anteriores tem comportamento indefinido se $x$ é igual a zero

- A função `__builtin_ffs(x)` retorna 1 mais o índice do _bit_ menos significativo de $x$, ou zero, se $x$ é igual a zero


## Exemplos de uso das funções do GCC

```C++
int main()
{
    int x = 1968;       // 123 x 16 = 11110110000

    cout << __builtin_popcount(x) << '\n';      // 6
    cout << __builtin_ffs(x) << '\n';           // 5
    cout << __builtin_clz(x) << '\n';           // 21
    cout << __builtin_ctz(x) << '\n';           // 4

    return 0;
}
```
## Problemas

- AtCoder
    1. [ABC 091D - Two Sequences](https://atcoder.jp/contests/abc091/tasks/arc092_b)
    1. [ABC 121D - XOR World](https://atcoder.jp/contests/abc121/tasks/abc121_d)
    1. [ABC 147D - Xor Sum 4](https://atcoder.jp/contests/abc147/tasks/abc147_d)
- Codeforces
    1. [1152B - Neko Performs Cat Furrier Transform](https://codeforces.com/problemset/problem/1152/B)
- OJ
    1. [377 - Cowculations](http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=313)

## Referências

1. **HALIM**, Felix; **HALIM**, Steve. _Competitive Programming 3_, 2010.
1. **LAAKSONEN**, Antti. _Competitive Programmer's Handbook_, 2018.
1. **SKIENA**, Steven S.; **REVILLA**, Miguel A. _Programming Challenges_, 2003.
