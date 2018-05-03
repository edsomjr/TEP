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

Observe que o problema oferece o input de números de até 10^1000. Isso não pode ser representado diretamente como valor numa arquitetura de 64 bits (2^64 < 10^20). Logo, o input deve ser lido de outra forma, como por exemplo, uma string. Lidos os números como strings, como pode ser efetuado a soma deles? Ora, basta usar o algoritmo que aprendemos desde cedo na escola: alinhamos os números um embaixo do outro, começamos pelo último dígito e vamos somando da direita para a esquerda sempre fazendo a propagação de carrys. Para esse problema, devemos computar além da soma correta, a soma incorreta que Pedrinho faz (sem a propagação de carrys). Alguns cuidados devem ser tomados como:

1. Alinhar as duas strings para realizar a soma. Uma forma de fazer isso é acrescentando zeros à esquerda do menor número. Para isso, vamos criar uma string com zeros com o tamanho que falta em O(n) e concatená-la à esquerda da menor string em O(n). Evitar de adicionar zeros à esquerda um por um (b = "0" + b), pois a complexidade se torna O(n^2).
2. Ao acessar uma posição da string, não se recebe o valor numérico dele, mas o valor de seu caractere na tabela ASCII. Para computar o seu valor numérico, devemos retirar o caractere com o valor excedente, no caso o '0'.
3. Não esquecer de acrescentar o último carry no resultado certo final.
4. Retirar zeros à esquerda dos valores finais. Para isso, vamos contar quantos zeros a string possui à esquerda em O(n) e usar o comando erase do C++ para remover os zeros em O(n). Evitar de remover zeros à esquerda um por um, pois a complexidade se torna O(n^2).

Ao printar a resposta, basta ver se as strings são iguais ou diferentes. Como varremos cada posição da string uma vez da direita para esquerda, é fácil ver que a complexidade da solução é O(n), em que n é a quantidade de dígitos do maior número da entrada. Como temos 100 casos de teste, no total teremos cerca de 100*O(n) = 10^5 < 10^6 operações que cabe confortavelmente nos limites do problema.

Abaixo segue um código **C++** aceito nesse problema como sugestão de implementação:
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int casos = 1; casos <= t; casos++)
	{
		string a, b;
		cin >> a >> b;

		//assumiremos "a" como sendo a maior string
		if(b.size() > a.size())
			swap(a, b);
		int size = a.size();

		//adicionando zeros a esquerda da menor string
		string zeros(size-b.size(), '0');
		b = zeros + b;

		//inicializando as strings com tamanho size
		string certo(size, '0'), errado(size, '0');
		int carry = 0;

		for(int i = size-1; i >= 0; i--)
		{
			errado[i] = (a[i] - '0' + b[i] - '0') % 10 + '0';
			certo[i] = (a[i] - '0' + b[i] - '0' + carry) % 10 + '0';
			carry = (carry + a[i] - '0' + b[i] - '0') / 10;
		}

		//adicionando o carry a esquerda do resultado certo
		if(carry != 0)
			certo = to_string(carry) + certo;

		//removendo zeros a esquerda
		int count = 0;
		while(errado[count] == '0' && count < size-1)
			count++;
		errado.erase(0, count);
		count = 0;
		while(certo[count] == '0' && count < size-1)
			count++;
		certo.erase(0, count);

		cout << "Caso " << casos << ": ";
		if(certo == errado)
			cout << "Ok" << endl;
		else
			cout << errado << " != " << certo << endl;

	}

	return 0;
}


```

Problema C
----------

Problema D
----------

Problema E
----------

Problema F
----------
