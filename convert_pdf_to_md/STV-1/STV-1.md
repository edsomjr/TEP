## Faculdade UnB Gama
Sumário
1. Definição
2. Implementação
## Definição
Travessia de um grafo
* Uma travessia de um grafo consiste em visitar todos os nós
alcançáveis a partir de um nó inicial s
* Cada nó deve ser processado uma única vez, embora a travessia
possar passar por um nó mais de uma vez
* Uma travessia T1 é diferente de uma travessia T2 se ambas diferem
na ordem de visitação dos vértices
* Um grafo conectado com N nós tem N! travessias possíveis
* Dentre todas estas travessias, duas se destacam pela aplicabilidade
em situações práticas: a travessia por profundidade e a travessia por
largura.
## Depth-First Search
* A travessia por profundidade (Depth-First Search – DFS) segue, a
partir do nó inicial s, um caminho único, enquanto encontrar novos
nós
* Quando não for possível encontrar novos nós, a DFS retorna ao nó
anterior e retoma o caminho usando o próximo nó encontrado
* A DFS mantém um registro dos nós visitados, de forma que cada nó
seja processado uma única vez
* Em um grafo conectado com N nós e M arestas, a complexidade da
DFS é O(N + M), pois cada nó e cada aresta é processada uma
única vez
* Se o grafo for representado como matrizes de adjacências, a
complexidade é O(N2)
##  Visualização da DFS
![](images/movie.gif)
Para acessar álbum de imagens [clique aqui](images/).

## Implementação da DFS em C++
```C++
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using ii = pair<int, int>;
const int MAX { 100010 };
bitset<MAX> visited;
vector<int> adj[MAX];
void dfs(int u)
{
    if (visited[u]) return;
    visited[u] = true;
    cout << u << " ";
    for (const auto& v : adj[u])
        dfs(v);
}
int main()
{
    ii edges[] { ii(1, 2), ii(1, 3), ii(2, 4), ii(2, 5), ii(3, 6),
                 ii(5, 6), ii(5, 8), ii(5, 9), ii(6, 7), ii(6, 10), ii(8, 11),
                 ii(9, 10), ii(11, 12), ii(11, 13)
               };
    for (const auto& [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.reset();
    dfs(1);
    cout << endl;
    return 0;
}
```
## Referências
1. HALIM, Felix; HALIM, Steve. Competitive Programming 3, 2010.
2. LAAKSONEN, Antti. Competitive Programmer’s Handbook, 2018.
3. SKIENA, Steven S.; REVILLA, Miguel A. Programming
Challenges, 2003.
4. FILIPEK, Bartlomiej. C++17 in Detail, 20181.
1https://leanpub.com/cpp17indetail

## Lista de Exercicios - dfs
* Dfs1, https://a2oj.com/category?ID=13
* Dfs2, https://a2oj.com/category?ID=234
* Dfs3, https://a2oj.com/category?ID=413
