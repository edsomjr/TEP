[Contest III](https://www.codepit.io/#/contest/5ab3ecb401a96e00194077f3/)
==========

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
