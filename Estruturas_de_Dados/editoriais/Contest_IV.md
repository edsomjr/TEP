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

Problema F
----------
