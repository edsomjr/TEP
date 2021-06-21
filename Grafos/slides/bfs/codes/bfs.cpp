vector<int> bfs(int s, int N) {
    vector<int> dist(N + 1, oo);
    queue<int> q;

    dist[s] = 0; q.push(s);

    while (not q.empty())
    {
        auto u = q.front(); q.pop();

        // visita/processa u

        for (auto v : adj[u]) {
            if (dist[v] == oo) {
                dist[v] = dist[u] + 1; q.push(v);
            }
        }
    }

    return dist;
}
