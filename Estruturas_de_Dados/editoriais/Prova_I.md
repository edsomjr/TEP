Prova I
==========

Problema A
----------

O problema nos pede pra dizer se é possível criar um grafo com **N** nós de tal forma que cada um dos nós esteja conectado a exatamente **L** outros nós, onde um nó não pode estar conectado consigo mesmo.

A primeira observação chave é: se **L** for maior ou igual a **N**, então é impossível criar qualquer grafo da dita forma, porque um nó só pode se conectar a, no máximo, **N - 1** nós (todos os outros menos ele mesmo).

A observação descrita acima é bem fácil de ser enxergada, mas a partir desse ponto chegar numa solução pode não ser tão simples. Para situações como essa, é bem útil tentar derivar propriedades das estruturas do problema com as informações que já temos; por exemplo, uma pergunta útil que podemos fazer é: "quantas arestas existem em um grafo da forma descrita acima?" Se existem **N** nós e cada um está conectado a exatamente **L** arestas, então a resposta deve ser **(N * L) / 2**; dividimos a expressão **(N * L)** por **2** porque uma aresta está ligada a exatamente **2** nós e, por isso, ela é contada **2** vezes em **(N * L)**.

Bom, se o número total de arestas é **(N * L) / 2**, então **(N * L)** deve ser par, caso contrário teríamos uma aresta pela metade, já que a expressão **(N * L) / 2** resultaria em um número não inteiro. Esta é a segunda observação chave do problema.

Acontece que essas duas condições (**L** ser menor que **N** e **(N * L)** ser par) são suficientes para a existência de um grafo da forma requerida.

Dividamos a prova da afirmação acima em dois casos:
* **N** par:
	1. Se **N** for par, podemos repetir o passo no próximo item **L** vezes para montar um grafo que obedece as propriedades
	2. Escolha **N / 2** pares de nós de tal forma que ainda não exista uma aresta entre os nós de todo e qualquer par e, então, crie uma aresta entre eles
	3. É fácil ver que se esse passo for executado **L** vezes, teremos um grafo aceito
	4. O único jeito de algum desses passos falhar é quando algum nó **i** não consegue formar par com nenhum outro elemento **j**: ou seja, se já existir uma aresta entre eles. Isso nunca acontece porque, pra cada passo, todos os nós têm uma aresta adicionada à sua lista de adjacência, e como já sabemos que **L <= N-1** (primeiríssima observação), então, no começo de qualquer passo, a lista de adjacências de qualquer nó **i** terá, no máximo, tamanho **N-2**, implicando que sempre haverá pelo menos um outro nó **j** para formar par com **i**.
* **N** ímpar:
	1. Se **N** for ímpar, vamos excluir, temporariamente, um nó qualquer **X**
	2. Agora, existe um número par de nós. Vamos repetir **L-1** vezes o passo descrito no item **2** do caso do **N** par
	3. O **L**-ésimo passo será um pouco diferente: formamos **[(N - 1) - L] / 2** pares válidos de nós e criamos arestas entre cada um deles (perceba que **(N - 1) - L** é par). Nisso, exatamente **L** nós (os que não foram escolhidos nos pares formados do período anterior) e o nó **X** ainda não estarão conectados a exatamente **L** outros nós. Para resolver isso, basta conectar **X** a cada um dos **L** nós restantes, já que os mesmos estavam conectados a **L - 1** nós (pelo item **2**).

A complexidade final da solução é **O(1)**.

Abaixo segue um código **C++** aceito nesse problema como sugestão de implementação:
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	int kase = 1;
	
	while(t--) {
		int N, L;
		cin >> N >> L;

		int P = N * L;

		cout << "Caso " << kase++ << ": ";

		if(L < N && P % 2 == 0) {
			cout << "Sim" << '\n';
		}
		else {
			cout << "Nao" << '\n';
		}
	}

	return 0;
}
```


Problema B
----------

Problema C
----------

Problema D
----------

Problema E
----------

Problema F
----------

Vamos supor que modelamos uma função **F(N, H)** com o seguinte significado:
		
	F(N, H) - quantidade de permutações que resultam em uma árvore binária de busca de N nós e altura H

A resposta, então, seria dada pela seguinte expressão:

<p align="center">
  <img src="imagens/P1_F.gif" alt="Resposta F"/>
</p>

Para construir a recorrência da função **F(N, H)**, precisamos de um caso base e de um caso geral:

**Caso Base (H = 0)**

O único jeito de termos uma árvore binária de altura **0** é tendo **0** nós. Ou seja, caso **H = 0**, retornaremos **1** se **N = 0** e **0** caso contrário.

**Caso Geral (H > 0)**

Caso **H > 0**, então a árvore a ser construída terá **2** filhos, mesmo que esses tenham altura **0**. Para construirmos uma árvore de altura **H**, pelo menos um de seus filhos tem que ter altura **H - 1**.

Além disso, um dos **N** nós tem de ser considerado como raiz da árvore a ser construída.

Suponha que os elementos da árvore estão enumerados de **1** a **N**; logo, se colocarmos um elemento **i** como raiz da árvore, os elementos **{1, 2, ..., i - 1}** estarão alocados na subárvore do filho esquerdo da raiz e o elementos **{i + 1, i + 2, ..., N}** estarão alocados na subárvore do filho direito da raiz. Ou seja, se o elemento **i** for colocado como raiz da árvore, a árvore do filho esquerdo terá tamanho **i - 1** e a árvore do filho direito terá tamanho **N - i**.

Para calcular, então, o valor de **F(N, H)**, temos de considerar todos os elementos **i** como sendo raiz da árvore atual e todas as alturas possíveis para seu filho esquerdo e direito, desde que pelo menos um dos dois tenha altura **H - 1**. O trecho de código a seguir explicita, de forma simplificada, essa ideia:

```cpp
long long F(int N, int H) {
 // some code
 // ...
 // ...
 // ...
 
 long long total = 0;
 for(int i = 1; i <= N; i++) { // nó a ser escolhido como raiz
   for(int j = 0; j < H; j++) { // altura do filho esquerdo
     for(int k = 0; k < H; k++) { // altura do filho direito
       if(j == H - 1 || k == H - 1) {
         total += F(i - 1, j) * F(N - i, k); 
       }
     }
   }
 }
 // some code
 // ...
 // ...
 // ...
```

Isto é, para cada nó **i** fixado como raiz, temos inúmera formas de criar as subárvores do filho esquerdo e do direito. Pra cada par de formas em que as alturas dos filhos são complementares, multiplicamos suas quantidades e somamos ao total, pois assim consideramos todas as possibilidades para a tripla **(i, j, k)**.

Acontece que isso não é o bastante. Esse trecho de código funcionaria caso o objetivo de **F(N, H)** fosse calcular a quantidade de árvores binárias de busca com **N** elementos e altura **H**. Porém, o que queremos é a quantidade de **permutações** que resultam em uma árvore binária de busca com **N** elementos e altura **H**. O problema é que não existe uma bijeção entre as ditas permutações e as árvores de busca; isto é, podem existir **2** ou mais permutações que resultarão em uma mesma árvore, como, por exemplo: **{2, 1, 3}** e **{2, 3, 1}**.

Podemos resolver isso multiplicando o resultado de cada tripla **(i, j, k)** por **C(N - 1, i - 1)**, onde **C(N, K)** representa o [binômio de newton](https://en.wikipedia.org/wiki/Binomial_theorem). **C(N, K)** também pode ser enxergado como o total de formas de escolher **K** objetos entre **N** objetos sem que a ordem dos objetos importe. A pequena alteração pode ser vista no mesmo trecho de código de cima modificado:

```cpp
long long F(int N, int H) {
 // some code
 // ...
 // ...
 // ...
 
 long long total = 0;
 for(int i = 1; i <= N; i++) { // nó a ser escolhido como raiz
   for(int j = 0; j < H; j++) { // altura do filho esquerdo
     for(int k = 0; k < H; k++) { // altura do filho direito
       if(j == H - 1 || k == H - 1) {
         total += F(i - 1, j) * F(N - i, k) * C(N - 1, i - 1); 
       }
     }
   }
 }
 // some code
 // ...
 // ...
 // ...
```
A intuição por trás da multiplicação por **C(N - 1, i - 1)** é: se estamos criando uma árvore de **N** elementos no momento, então algumas permutações que representam essa árvore também estão sendo criadas. Como fixamos o elemento **i** como a raiz da árvore, então ele é o primeiro elemento de todas as permutações que representam essa árvore; ou seja, sobrarão, nas permutações, **N - 1** posições livres que serão preenchidas a depender de como as árvores da esquerda e da direita são montadas.

Como todos os elementos da árvore esquerda são menores que **i** e todos os elementos da árvore direita são maiores que **i**, então qualquer elemento da árvore direita é maior que qualquer elemento da árvore esquerda. Assim, a ordem de qualquer elemento da árvore esquerda em relação a qualquer elemento da árvore direita nas permutações não importa. Em outras palavras, não importa qual vem antes ou depois, os elementos menores que **i** sempre vão ser jogados para a esquerda e os maiores para a direita. O que importa, somente, é a ordem relativa entre os elementos de cada subárvore, separadamente.

Finalmente, como a árvore da esquerda tem exatamente **i - 1** elementos, temos de escolher **i - 1** posições das **N - 1** restantes para colocá-los, enquanto a ordem relativa dos mesmos é tratada pela própria função chamada para o filho esquerdo (e, analogamente, para o filho direito).

Como a solução tem várias subestruturas (e essas sendo ótimas) que são calculadas várias e várias vezes, podemos utilizar [programação dinâmica](https://en.wikipedia.org/wiki/Dynamic_programming) **(DP)** para memorizar informações e não calculá-las novamente.

Como existem **N^2** estados possíveis para a **DP** e as transições acontecem em **N^2** (os **3** for rodam em **N^2** por causa do if da altura **H - 1**), a complexidade final da solução é **O(N^4)**, o que é mais do que suficiente para **N = 20**.

Abaixo segue um código **C++** como sugestão de implementação:
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 20 + 5;

ll memo[MAX][MAX];
ll comb[MAX][MAX];

ll roll(int nodes, int height) {
	if(height == 0) {
		return nodes == 0;
	}

	ll &ans = memo[nodes][height];
	if(~ans) {
		return ans;
	}

	ans = 0;
	for(int i = 1; i <= nodes; i++) {
		for(int j = 0; j < height; j++) {
			for(int k = 0; k < height; k++) {
				if(j == height - 1 || k == height - 1) {
					ans += roll(i - 1, j) * roll(nodes - i, k) * comb[nodes - 1][i - 1];
				}
			}
		}
	}

	return ans;
}

int main() {
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j <= i; j++) {
			if(i == j || j == 0) {
				comb[i][j] = 1;
			}
			else {
				comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
			}
		}
	}

	memset(memo, -1, sizeof memo);

	int t;
	scanf("%d", &t);

	for(int kase = 1; kase <= t; kase++) {
		int n;
		scanf("%d", &n);

		ll f = 1; // N!
		for(int i = 1; i <= n; i++) {
			f *= i;
		}

		double ans = 0.0;
		for(int i = 1; i <= n; i++) {
			ll total = roll(n, i);

			double prob = (double) total / (double) f;
			ans += i * prob;
		}

		printf("Caso %d: %.8lf\n", kase, ans);
	}

	return 0;
}
```
