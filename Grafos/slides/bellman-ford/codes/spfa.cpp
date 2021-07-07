#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 100010 }, oo { 1000000010 };
vector<ii> adj[MAX];
int dist[MAX];

void spfa(int s, int N) {
    bitset<MAX> in_queue;

    for (int i = 1; i <= N; ++i)
        dist[i] = oo;

    dist[s] = 0;

    queue<int> q;
    q.push(s);
    in_queue[s] = true;

    while (not q.empty())
    {
        auto u = q.front();
        q.pop();
        in_queue[u] = false;

        for (const auto& [v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;

                if (not in_queue[v])
                {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
}

int main()
{
    vector<edge> edges { edge(1, 2, 9), edge(1, 3, 7), edge(1, 4, 4), 
        edge(1, 5, 2), edge(2, 3, 1), edge(2, 6, 3), edge(3, 4, 2),
        edge(4, 5, 1), edge(5, 6, 11) };

    for (const auto& [u, v, w] : edges)
    {
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    spfa(1, 6);

    for (int u = 1; u <= 6; ++u)
        cout << "Distância minima de 1 a " << u << ": " << dist[u] << '\n';

    return 0;
} 
