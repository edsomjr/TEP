#include <bits/stdc++.h>

using namespace std;
using ll = unsigned int;
using ii = pair<int, int>;

enum State { NOT_FOUND, FOUND, PROCESSED };
const int MAX { 20010 };

vector<int> adj[MAX];
ll R[MAX][MAX/32];
int cost[MAX], state[MAX];
int ans[MAX];

void dfs(int u, vector<int>& o)
{
    if (state[u] == PROCESSED)
        return;

    state[u] = FOUND;

    for (auto v : adj[u])
        dfs(v, o);

    state[u] = PROCESSED;
    o.emplace_back(u);
}

vector<int> reverse_topological_sort(int N)
{
    vector<int> o;
    memset(state, 0, sizeof state);

    for (int u = 1; u <= N; ++u)
        if (state[u] == NOT_FOUND) 
            dfs(u, o);

    return o;
}

#define setbit(R, u, pos) R[u][pos >> 5] |= (1U << (pos & 0x1f))
#define getbit(R, u, pos) R[u][pos >> 5] & (1U << (pos & 0x1f))
#define sets_union(R, u, v, pos) for (int k = 0; k <= (pos >> 5); ++k) \
                               { R[u][k] |= R[v][k]; }

void solve(int N)
{
    auto o = reverse_topological_sort(N);

    for (int i = 0; i < N; ++i) { 
        auto u = o[i];
        setbit(R, u, i);

        for (auto v : adj[u])
            sets_union(R, u, v, i);
    }

    for (int u = 1; u <= N; ++u) {
        ans[u] = 0;

        for (int i = 0; i < N; ++i)
            if (getbit(R, u, i))
                ans[u] += cost[o[i]];
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int N, M;
        scanf("%d %d", &N, &M);

        for (int u = 1; u <= N; ++u)
        {
            adj[u].clear();

            for (int j = 0; j <= (N >> 5); ++j)
                R[u][j] = 0;
        }

        for (int u = 1; u <= N; ++u)
            scanf("%d", &cost[u]);

        while (M--)
        {
            int u, v;
            scanf("%d %d", &u, &v);

            adj[u].emplace_back(v);
        }

        solve(N);

        for (int u = 1; u <= N; ++u)
            printf("%d%c", ans[u], (u == N ? '\n' : ' '));
    }
}
