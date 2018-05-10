[Contest III](https://www.codepit.io/#/contest/5ab3ecb401a96e00194077f3/view)
==========

[Problema A](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2180)
----------

O problema fornece o nome vários cursos e o nome dos alunos inscritos em cada curso e pede para imprimirmos a quantidade de alunos inscritos em cada curso, sendo que um mesmo aluno inscrito várias vezes no mesmo curso só deve ser contado uma vez e um aluno inscrito em mais de um curso deve ter a inscrição alunada de todos os cursos em que se inscreveu.

Para resolver este problemas usaremos a estrutura [map](http://www.cplusplus.com/reference/map/map/), teremos um map que relacinará cada curso à quantidade de alunos inscritos nele, chamaremos este map de "qtdProjeto", um segundo map que indicará em qual curso cada aluno está inscrito, chamaremos este de "estudante".

Inicialmente iremos atribuir um identificador inteiro para cada curso, de acordo com a ordem dada na entrada, o primeiro curso será identificado com o número 1 o segundo com o número 2 e assim por diante, com isso podemos fazer com que o map "qtdProjeto" tenha a chave e o valor como inteiros, isso irá melhorar a complexidade de tempo do programa. Guardaremos os nomes dos cursos em um vetor para recuperá-los para imprimir a saída.

Após atribuir o identificador ao curso devemos inicializar o map "qtdProjeto" com o valor 0 para para cada curso, e começar a ler o nome dos alunos que se inscreveram neste curso.

Ao ler o nome de um aluno podemos nos deparar com três casos distintos:

1. O nome deste aluno apareceu pela primeira vez.

	Neste caso iremos incrementar a quantidade de alunos inscritos no curso atual em 1 e atribuiremos à chave do estudante atual no map "estudante" o valor do identificador do curso atual.

2. O nome deste aluno já apareceu anteriormente na lista de alunos do curso atual.

	Neste caso não iremos fazer nada.

3. O nome deste aluno apareceu na lista de alunos de outro curso.

	Neste caso devemos eliminar a incrição deste aluno no curso em que ele se inscreveu, sabemos o identificador do curso em que este aluno está incrito através do map "estudante" e podemos utilizar este identificador para decrementar em 1 a quantidade de alunos inscritos no curso. Também precisamos garantir que este aluno não será inscrito em nenhum curso futuramente e que não decrementaremos novamente a quantidade de alunos do curso em que ele foi inscrito, para isso atribuiremos o valor -1 ao valor deste aluno no map "estudante", assim quando escontrarmos um aluno que possui o valor -1 no map saberemos que ele já foi eliminado.


Após realizar o procedimento descrito acima para todos os cursos e alunos de um caso de teste, já possuiremos toda a informação necessária para gerar a saída correta, só resta organizar os dados do map "qtdProjeto", para isso é possível utilizar um vetor que conterá as chaves e valores do map, substituindo os identificadores dos cursos pelos nomes originais que armazenamos anteriormente, e utilizando a função [sort](http://www.cplusplus.com/reference/algorithm/sort/) para ordenar este vetor de acordo com o formato de saída solicitado pelo problema, mostrando primeiro os cursos com maior quantidade de alunos inscritos e em caso de empate o curso com [menor nome lexicograficamente](https://pt.wikipedia.org/wiki/Ordem_lexicográfica) deverá aparecer primeiro.

A complexidade de tempo para acessar um elemento no map é O(log(tamanho do map) * (tempo de comparação entre chaves)), a função sort executa em tempo O(log(quantidade de elementos a serem ordenados) * (tempo para comparar dois elementos)), sendo M o maior tamanho possível para uma string da entrada e N a quantidade de strings fornecidas em cada caso de teste, a complexidade total destá solução é O(log(N) * M) por caso de teste.

Caso não tivéssemos utilizado um indentificador inteiro para cada curso e mativéssemos a chave do map "qtdProjeto" como o nome do curso (string), sendo T o maior tamanho possível do nome de um curso, X a maior quantidade de alunos em um curso e Y a quantidade de cursos, a complexidade desta solução seria O(T * X * log(Y)), como o limite do valor de T não é fornecido pelo enunciado é possível que está solução fosse muito lenta. É provável que o limite para o tamanho do nome dos cursos seja o mesmo que o limite do tamanho dos nomes dos alunos, neste caso a diferença entre a complexidade de tempo utilizando a chave de "qtdProjeto" como string ou inteiro seria uma constante.

**Implementação em C++:**

```C++
#include<bits/stdc++.h>

using namespace std;

int main(){
	int continua = 1;
	while(continua){
		int id = 0;
		string s;
		string projeto;
		vector<string> pjts;
		map<string, int> estudante;
		map<int, int> qtdProjeto;
		while(1){
			getline(cin, s);
			if(s.size() == 1 && (s[0] == '0' || s[0] == '1')){
				continua = s[0] - '0';
				break;
			}
			if(s[0] >= 'A' && s[0] <= 'Z'){
				projeto = s;
				id++;
				pjts.push_back(projeto);
				qtdProjeto[id] = 0;
			}
			else{
				if(!estudante[s]){
					estudante[s] = id;
					qtdProjeto[id]++;
				}
				else if(estudante[s] != id && estudante[s] != -1){
					qtdProjeto[estudante[s]]--;
					estudante[s] = -1;
				}
			}
		}
		vector<pair<int, string>> ans;
		for(auto x : qtdProjeto){
			ans.emplace_back(-x.second, pjts[x.first-1]);
		}
		sort(ans.begin(), ans.end());
		for(auto x : ans){
			cout << x.second << " " << -x.first << "\n";
		}
	}
```

[Problema B](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2283)
----------
O problema informa uma lista de ingredientes e o custo de cada ingrediente que pode ser encontrada em um mercado. Depois é informado uma lista de receitas: cada receita usa uma quantidade _x_ da lista de ingredientes. O problema pede para analisar se o custo de cada receita excede ou não um valor _b_ informado. No final, printar todas as receitas que não excederam o valor _b_ em ordem de custo e, em caso de empate, usar a ordem lexicográfica das receitas.

Uma forma inteligente de resolver o problema é utilizar alguma estrutura de dados que possamos entrar com uma string e retorne um inteiro. Com isso, podemos guardar a lista de ingredientes e seus respectivos custos. Na implementação abaixo, foi utilizado um mapa que mapeia uma string para um int (map<string, int>). Portanto, conforme as receitas forem sendo lidas, bastar ir acessando os custos dos ingredientes e multiplicar pela quantidade a ser utilizada, incrementando numa variável de soma. No final, basta analisar se a soma excede o valor _b_. Se não, guardar a receita em uma estrutura de dados capaz de, no final, printar todas as receitas em ordem de custo. Na implementação abaixo, foi utilizada a estrutura set<pair<int, string>>, já que a estrutura set do C++ já guarda seus valores ordenados. Um set de pares ordena o primeiro valor do pair<> e, em caso de empate, ordena o segunda valor, que é o que o problema pede.

Caso o problema seja implementado em C++, deve-se atentar para ler toda a linha (incluindo espaços) do título e das receitas. Uma forma de fazer isso é utilizando o comando getline(cin, s) tomando cuidado para sempre retirar o caractere de quebra de linha '\n' no buffer com getchar().

**Implementação em C++:**

```C++
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t, getchar();
	while(t--)
	{
		string titulo;
		getline(cin, titulo);
		//Printar titulo com letras maiusculas
		for(auto i : titulo)
			cout << (char) toupper(i);
		cout << endl;

		int m, n, b;
		cin >> m >> n >> b, getchar();
		map<string, int> ingredientes;
		set<pair<int, string>> receitas;

		while(m--)
		{
			string ing;
			int custo;
			cin >> ing >> custo, getchar();
			ingredientes[ing] = custo;
		}

		while(n--)
		{
			string receita;
			getline(cin, receita);
			int v, custo = 0;
			cin >> v, getchar();
			for(int j = 0; j < v; j++)
			{
				int quantidade;
				string ing;
				cin >> ing >> quantidade, getchar();
				custo += quantidade*ingredientes[ing];
			}

			if(custo <= b)
				receitas.insert({custo, receita});
		}

		if(receitas.empty())
		{
			cout << "Too expensive!" << endl << endl;
			continue;
		}

		for(auto i : receitas)
			cout << i.second << endl;
		cout << endl;
	}

	return 0;
}
```


[Problema F](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=583)
----------

O problema dá a lista de palavras de um dicionário _D_ . A seguir, uma lista de consultas cada uma tem uma palavra _S_ e você deve printar todas as [permutações](https://pt.wikipedia.org/wiki/Permuta%C3%A7%C3%A3o) de _S_ que ocorrem em _D_ ou informar que não existe nenhuma permutação de _S_ em _D_.

Podemos abordar este problema de várias formas, mostrarei da mais direta pela explicação acima. Precisamos de um jeito de armazenar strings do dicionário e pesquisar se uma string pertence ao dicionário, podemos usar um `set<string>` para resolver isto eficientemente.

A seguir precisamos de um jeito de passar por todas as permutações de uma string. Temos a função [next_permutation](http://www.cplusplus.com/reference/algorithm/next_permutation/) no c++ que muda um vetor para a sua próxima permutação. Só é preciso tomar cuidado para ordenar a string no começo para não pular nenhuma permutação no caminho.

```c++
#include <bits/stdc++.h>

using namespace std;

char s[10];

int main(){
	set<string> dicionario;

	while(scanf("%s", s) && strcmp(s, "XXXXXX")){
		dicionario.insert(s);
	}

	while(scanf("%s", s) && strcmp(s, "XXXXXX")){
		int n = strlen(s);
		sort(s, s+n);

		bool tem_pelo_menos_uma = false;
		do{
			if(dicionario.count(s)){ // verifica se a permutação atual está no dicionário
				tem_pelo_menos_uma = true;
				printf("%s\n", s);
			}
		}while(next_permutation(s, s+n));

		if(!tem_pelo_menos_uma) printf("NOT A VALID WORD\n");

		printf("******\n");
	}
	return 0;
}
```
