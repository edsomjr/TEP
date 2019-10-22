#include <bits/stdc++.h>
using namespace std;
using edge = tuple<int, int, int>;
const int MAX { 100010 }, oo { 1000000010 };
int dist[MAX], pred[MAX];
void bellman_ford(int s, int N, const vector<edge>& edges)
{
    for (int i = 1; i <= N; ++i) {
        dist[i] = oo;
        pred[i] = -1;
    }
    dist[s] = 0;
    pred[s] = s;
    for (int i = 1; i <= N - 1; i++)
        for (const auto& [u, v, w] : edges)
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
}
int main()
{
    vector<edge> edges { edge(1, 2, 9), edge(1, 3, 7), edge(1, 4, 4),
                         edge(1, 5, 2), edge(2, 3, 1), edge(2, 6, 3), edge(3, 4, 2),
                         edge(4, 5, 1), edge(5, 6, 11) };
    for (int i = edges.size() - 1; i >= 0; --i)
    {
        const auto& [u, v, w] = edges[i];
        edges.push_back(edge(v, u, w));
    }
    bellman_ford(1, 6, edges);
    for (int u = 1; u <= 6; ++u)
    {
        cout << "dist(1," << u << ") = " << dist[u] << endl;
        vector<int> path;
        auto p = u;
        while (p != 1) {
            path.push_back(p);
            p = pred[p];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << (i + 1 == path.size() ? "\n" : " -> ");
    }
    return 0;
}