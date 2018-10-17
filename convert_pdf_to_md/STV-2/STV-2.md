## Definição
Breadth-First Search
* A travessia por largura (Breadth-First Search – BFS) visita os nós
em ordem crescente em relação à distância ao nó inicial s
* Desta forma, um subproduto da BFS é a distância de todos os nós
que conectados até s
* A implementação da BFS é mais trabalhosa do que a da DFS,
porque não se vale de recursão, sendo necessário o uso de uma fila
explicitamente
* Ambas travessias visitam os mesmos nós, porém em ordens
diferentes
* A complexidade da BFS é O(N + M), onde N é o número de
vértices e M o número de arestas do grafo conectado
* No caso de uma representação por matrizes de adjacência, a
complexidade é O(N2)
* Primeiramente são visitados todos os vizinhos do nó inicial s
* Em seguida são visitados os vizinhos de cada vizinho, e assim
sucessivamente
* Uma fila é mantida para manter a ordem dos vértices a serem
visitados
* A fila é processada retirando-se o primeiro da elemento da fila e
enfileirando-se todos os vizinhos deste nó que ainda não foram
* Antes de ser inserido na fila, o nó é marcado como visitado
##  Visualização da BFS
![](images/vis-0/movie.gif)
Para acessar álbum de imagens [clique aqui](images/vis-0/).

## Implementação da BFS em C++
```C++
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;
using ii = pair<int, int>;
const int MAX { 100010 };
vector<int> adj[MAX];
bitset<MAX> visited;
int dist[MAX];
void bfs(int s)
{
    queue<int> q;
    visited.reset();
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    while (not q.empty())
    {
        auto u = q.front();
        q.pop();
        cout << u << " ";
        for (const auto& v : adj[u])
        {
            if (visited[v])
                continue;
            visited[v] = true;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
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
    bfs(1);
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

## Lista de Exercicios - Bfs
* Bfs1, https://a2oj.com/category?ID=13
