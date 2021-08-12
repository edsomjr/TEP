// Codeforces Round #250 - Problem C: The Child and Toy (https://codeforces.com/contest/437/problem/C)
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

#define REP(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define REPN(i, N) for (int (i) = 0; (i) < N; (i)++)

const int MAX { 1010 };

int vs[MAX];
vector<int> adj[MAX];
bitset<MAX> deleted;

void solve(int N)
{
    priority_queue<ii> pq;

    REP(u, 1, N)
        pq.push(ii(vs[u], u));

    auto ans = 0;

    // A melhor estratégia é deletar os vértices em ordem decrescente de custo
    // Prova: cada aresta (u, v) contribui com vs[u] ou vs[v] ao final. Se o maior for 
    // excluído, a aresta contribui apenas com min(vs[u], vs[v])
    while (not pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        int u = p.second; 
        int cost = 0;

        for (const auto& v : adj[u])
            if (not deleted[v])
                cost += vs[v];

        ans += cost;
        deleted[u] = true;
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    REP(i, 1, N)
        cin >> vs[i];

    REPN(i, M)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(N);

    return 0;
}
