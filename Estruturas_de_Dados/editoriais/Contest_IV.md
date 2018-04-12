Contest IV
==========

Problema A
----------

Problema B
----------

Problema C
----------

Problema D
----------

[Problema E](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2737)
----------

Considere um grupo de pessoas P = {p1, p2, ..., pn} e que cada pessoa pi possui uma dívida ci. É fácil ver que elas conseguem pagar as dívidas entre si se c1+c2+...+cn=0. Portanto, basta analisar os diferentes grupos de amigos existentes e verificar se a soma das dívidas de cada um deles resulta em zero. Duas técnicas diferentes podem ser utilizadas para implementar essa solução:

### Disjoint Set (Union-Find)

Criar uma estrutura Union Find para o conjunto P. Inicialmente, todos os amigos possuem nenhuma amizade entre si. Após ler um laço de amizade entre uma pessoa pi e pj, aplicar a união entre elas. Finalmente, deve-se passar por todos os conjuntos montados e verificar se a soma das dívidas resulta em 0 em cada um deles.

**Implementação em C++:**

```C++
#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
int pset[MAX], cost[MAX];

int find_set(int i)
{
	return pset[i] == i ? i : pset[i] = find_set(pset[i]);
}

void union_sets(int i, int j)
{
	int pi = find_set(i), pj = find_set(j);
	if(pi != pj)
		pset[pi] = pj;
}

int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++)
		{
			cin >> cost[i];
			pset[i] = i;
		}
		for(int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			union_sets(x, y);
		}
		map<int, int> sum;
		for(int i = 0; i < n; i++)
			sum[find_set(i)] += cost[i];
		bool ok = 1;
		for(auto i : sum)
			ok &= i.second == 0;
		cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	}

	return 0;
}
```

### Busca em profundidade (DFS)

Outra forma de solucionar o problema é aplicar uma DFS em um grafo cujos nós representam os amigos e as arestas os laços de amizades entre eles. Logo, basta rodar uma DFS para cada nó não visitado e verificar se a soma das dívidas resulta em 0.

**Implementação em C++:**

```C++
#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;

bool visited[MAX];
int cost[MAX];
int sum = 0;

void dfs(int u, vector<int> adj[])
{
	visited[u] = 1;
	sum += cost[u];
	for(auto i : adj[u])
		if(!visited[i])
			dfs(i, adj);
}

int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			cin >> cost[i];
		vector<int> adj[n];
		for(int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(visited, 0, n);
		bool ok = 1;
		for(int i = 0; i < n; i++)
			if(!visited[i])
			{
				dfs(i, adj);
				ok &= sum == 0;
			}
		cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	}

	return 0;
}
```

[Problema F](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3638)
------------

O contexto do problema explica que uma espécie de pneumonia vem contaminando boa parte da população mundial. Uma universidade se deu conta do risco e, por isso, tem interesse de analisar os grupos de estudo formados por alguns alunos, pois a taxa de contaminação da doença é elevada. Em específico, se um aluno _X_ é suspeito de ter a doença, então um aluno _Y_ presente em algum grupo de estudo que _X_ também está presente também é. Dada essa definição, a universidade tem interesse em saber quantos alunos são suspeitos de ter a doença, dado que o aluno _0_ é um suspeito.

O _input_ é composto por _1 <= N <= 10^4_ alunos e _0 <= M <= 500_ grupos de estudo.

A primeira observação simples a se fazer é que a suspeita de alunos é transitiva; isto é: se um aluno _X_ é suspeito e um aluno _Y_ está em algum grupo de estudo que _X_ está, então _Y_ passa a ser suspeito. Logo após, se o aluno _Z_ está em algum grupo de estudo que _Y_ está mas _X_ não, _Z_ passa a ser suspeito do mesmo jeito, pois _Y_ foi considerado suspeito por estar em um grupo com _X_.

Essa primeira observação pode ser um bom incentivo para enxergarmos as estruturas lógicas do problema como um grafo. Isto é, modelamos os alunos comos nós e as arestas entre dois alunos como a presença deles em algum mesmo grupo; em outras palavras, uma aresta existe entre dois alunos caso os dois estejam em um mesmo grupo qualquer.

A outra observação chave é: a única fonte contaminação é o aluno _0_; ou seja, apenas os alunos presentes no mesmo [componente conectado](https://en.wikipedia.org/wiki/Connected_component_%28graph_theory%29)  que o aluno _0_ estarão infectados. Então, a resposta para o problema é simplesmente o tamanho do componente conectado em que o aluno _0_ está presente.

Com as informações acima, podemos resolver o problema utilizando a estrutura de dados [Union Find Disjoint Sets (UFDS)](https://en.wikipedia.org/wiki/Disjoint-set_data_structure).

Para cada grupo de estudos lido no input, uniremos (criaremos uma aresta, teoricamente) todos os pares de alunos presentes nesse grupo com a função _union_ do UFDS. Se um grupo de estudos lido tem tamanho _S_, então esse passo faria _O(S^2)_ uniões, pois fazemos uma para cada par de alunos presente no grupo. Uma observação simples é: se fixarmos o primeiro aluno desse grupo e unirmos ele com todos os outros, então todos os alunos desse grupo já estarão no mesmo conjunto do UFDS. Então, esse passo pode ser otimizado como citado acima para _O(S)_ uniões.

Se mantermos e atualizarmos um vetor _size_ para guardar os tamanhos do conjuntos do UFDS ao longo das uniões feitas pelas função _union_, basta imprimir _size[set(0)]_ ao final do passo descrito no parágrafo acima como resposta.

A complexidade final do algoritmo é dada pela soma das quantidades de uniões feitas nos grupos. O pior caso é quando todos os _M_ grupos são compostos por todos os _N_ alunos, fazendo com que haja _N_ uniões para cada grupo. Portanto, a complexidade final é _O(NM)_, assumindo que a complexidade da função _union_ é _O(1)_ amortizada. 

Abaixo segue um código C++ aceito nesse problema como sugestão de implementação:
```C++
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e4 + 5;
const int MAX_M = 5e2 + 5;

int pset[MAX_N];
int size[MAX_N];
int n, m;

void reset_UFDS() {
	for(int i = 0; i < n; i++) {
		pset[i] = i;
		size[i] = 1; // o set inicia com tamanho 1, pois apenas i está presente nele inicialmente
	}
}

int find_set(int i) {
	if(pset[i] == i) {
		return i;
	}
	return pset[i] = find_set(pset[i]);
}

void make_union(int i, int j) {
	int i_set = find_set(i);
	int j_set = find_set(j);

	if(i_set != j_set) { 
		size[j_set] += size[i_set];
		pset[i_set] = j_set; // unindo o set de i no set de j
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	while(cin >> n >> m, n | m) {
		reset_UFDS();

		for(int i = 0; i < m; i++) {
			int group_size;
			cin >> group_size;

			vector<int> students(group_size);
			for(int j = 0; j < group_size; j++) {
				cin >> students[j];
			}

			for(int j = 1; j < group_size; j++) {
				make_union(students[0], students[j]);
			}
		}

		cout << size[find_set(0)] << '\n';
	}

	return 0;
}
```
