#include <iostream>
#include <functional>
#include <vector>
#include <bitset>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };
bitset<MAX> visited;
vector<int> adj[MAX];

void dfs(int u, function<void(int)> process) {
    if (visited[u]) return;
    visited[u] = true;

    process(u);

    for (const auto& v : adj[u])
        dfs(v, process);
}

bool has_cycle(int N) {
    visited.reset();

    for (int u = 1; u <= N; ++u) 
        if (not visited[u])
        {
            vector<int> cs;
            size_t edges = 0;

            dfs(u, [&](int u) {
                cs.push_back(u); 

                for (const auto& v : adj[u])
                    edges += (visited[v] ? 0 : 1);
            });

            if (edges >= cs.size()) return true;
        }

    return false;
}

int main()
{
    ii edges[] { ii(1,2), ii(2,3), ii(2,4), ii(2,6), ii(4,5), ii(4,6) };

    for (const auto& [u, v] : edges)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Tem ciclo? " << (has_cycle(6) ? "Sim" : "Nao") << endl;

    return 0;
}
