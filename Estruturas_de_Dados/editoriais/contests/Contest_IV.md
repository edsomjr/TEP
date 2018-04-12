# Problema A
_TODO_

# Problema B
_TODO_

# Problema C
_TODO_

# Problema D
_TODO_

# Problema E
_TODO_

# Problema F

O contexto do problema explica que uma espécie de pneumonia vem contaminando boa parte da população mundial. Uma universidade se deu conta do risco e, por isso, tem interesse de analisar os grupos de estudo formados por alguns alunos, pois a taxa de contaminação da doença é elevada. Em específico, se um aluno _X_ é suspeito de ter a doença, então um aluno _Y_ presente em algum grupo de estudo que _X_ também está presente também é. Dada essa definição, a universidade tem interesse em saber quantos alunos são suspeitos de ter a doença, dado que o aluno _0_ é um suspeito.

O _input_ é composto por _1 <= N <= 10^4_ alunos e _0 <= M <= 500_ grupos de estudo.

A primeira observação simples a se fazer é que a suspeita de alunos é transitiva; isto é: se um aluno _X_ é suspeito e um aluno _Y_ está em algum grupo de estudo que _X_ está, então _Y_ passa a ser suspeito. Logo após, se o aluno _Z_ está em algum grupo de estudo que _Y_ está mas _X_ não, _Z_ passa a ser suspeito do mesmo jeito, pois _Y_ foi considerado suspeito por estar em um grupo com _X_.

Essa primeira observação pode ser um bom incentivo para enxergarmos as estruturas lógicas do problema como um grafo. Isto é, modelamos os alunos comos nós e as arestas entre dois alunos como a presença deles em algum mesmo grupo; em outras palavras, uma aresta existe entre dois alunos caso os dois estejam em um mesmo grupo qualquer.

A outra observação chave é: a única fonte contaminação é o aluno _0_; ou seja, apenas os alunos presentes no mesmo [componente conectado](https://en.wikipedia.org/wiki/Connected_component_%28graph_theory%29)  que o aluno _0_ estarão infectados. Então, a resposta para o problema é simplesmente o tamanho do componente conectado em que o aluno _0_ está presente.

Com as informações acima, podemos resolver o problema utilizando a estrutura de dados [Union Find Disjoint Sets (UFDS)](https://en.wikipedia.org/wiki/Disjoint-set_data_structure).

Para cada grupo de estudos lido no input, uniremos (criaremos uma aresta teoricamente) todos os pares de alunos presente nesse grupo com a função _union_ do UFDS. Se um grupo de estudos lido tem tamanho _S_, então esse passo faria _O(S^2)_ uniões, pois fazemos uma para cada par de alunos presente no grupo. Uma observação simples é: se fixarmos o primeiro aluno desse grupo e unirmos ele com todos os outros, então todos os alunos desse grupo já estarão no mesmo conjunto do UFDS. Então, esse passo pode ser otimizado como citado acima para _O(S)_ uniões.

Se mantermos e atualizarmos um vetor _size_ para guardar os tamanhos do conjuntos do UFDS ao longo das uniões feitas pelas função _union_, basta imprimir _size[set(0)]_ ao final do passo descrito no parágrafo acima como resposta.

A complexidade final do algoritmo é dada pela soma das quantidades de uniões feitas nos grupos. O pior caso é quando todos os _M_ grupos contém todos os _N_ alunos, fazendo com que haja _N_ uniões para cada grupo. Portanto a complexidade final é _O(NM)_, assumindo que a complexidade da função _union_ é _O(1)_ amortizada. 

Abaixo segue um código C++ aceito nesse problema como sugestão de implementação:
```cpp
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
