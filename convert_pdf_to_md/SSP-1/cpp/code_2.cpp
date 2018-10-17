bool has_negative_cycle(int s, int N, const vector<edge>& edges)
{
    for (int i = 1; i <= N; ++i)
        dist[i] = oo;
    dist[s] = 0;
    for (int i = 1; i <= N - 1; i++)
        for (const auto& [u, v, w] : edges)
            dist[v] = min(dist[v], dist[u] + w);
    for (const auto& [u, v, w] : edges)
        if (dist[v] > dist[u] + w)
            return true;
    return false;
}