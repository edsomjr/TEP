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
        ii(9, 10), ii(11, 12), ii(11, 13) };

    for (const auto& [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    cout << endl;

    return 0;
} 
