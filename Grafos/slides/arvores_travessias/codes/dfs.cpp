void dfs(int u, int p)
{
    // visita/processa u

    for (auto v : adj[u])
        if (v != p)
            dfs(v, u);
}
