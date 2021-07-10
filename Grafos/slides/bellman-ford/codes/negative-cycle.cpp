#include <bits/stdc++.h>

using namespace std;
using edge = tuple<int, int, int>;

bool has_negative_cycle(int s, int N, const vector<edge>& edges)
{
    const int oo { 1000000010 };

    vector<int> dist(N + 1, oo);
    dist[s] = 0;

    for (int i = 1; i <= N - 1; i++)
        for (auto [u, v, w] : edges)
            if (dist[u] < oo and dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;

    for (auto [u, v, w] : edges)
        if (dist[u] < oo and dist[v] > dist[u] + w)
            return true;

    return false;
}

int main()
{
    vector<edge> edges { edge(1, 2, 9), edge(1, 3, 7), edge(1, 4, 4), 
        edge(1, 5, 2), edge(2, 3, 1), edge(2, 6, 3), edge(3, 4, 2),
        edge(4, 5, 1), edge(5, 6, 11) };

    for (int i = (int) edges.size() - 1; i >= 0; --i)
    {
        const auto& [u, v, w] = edges[i];
        edges.push_back(edge(v, u, w));
    }

    sort(edges.begin(), edges.end());

    cout << "G " << (has_negative_cycle(1, 6, edges) ? "tem " : "não tem ") <<
        "ciclo negativo\n";

    return 0;
} 
