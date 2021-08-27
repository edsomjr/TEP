vector<int> min_dist(int s, int N, int w = 1) {
    vector<int> dist(N + 1, oo);
    queue<int> q;

    dist[s] = 0; q.push(s);

    while (not q.empty())
    {
        auto u = q.front(); q.pop();

        for (auto v : adj[u]) {
            if (dist[v] == oo) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }

    return dist;
}
