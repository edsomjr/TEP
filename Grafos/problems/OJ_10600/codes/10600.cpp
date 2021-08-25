#include <bits/stdc++.h>

using namespace std;
using edge = tuple<int, int, int>;

const int oo { 2000000010 };

class UnionFind
{
    vector<int> parent, rank;

public:
    UnionFind(int N) : parent(N + 1), rank(N + 1, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    bool same_set(int i, int j)
    {
        return find_set(i) == find_set(j);        
    }

    void union_set(int i, int j)
    {
        if (same_set(i, j))
            return;

        int p = find_set(i);
        int q = find_set(j);

        if (rank[p] > rank[q])
            parent[q] = p;
        else if (rank[q] > rank[p])
            parent[p] = q;
        else 
        {
            parent[q] = p;
            ++rank[p];
        }
    }

    int find_set(int i)
    {
        return parent[i] == i ? i : (parent[i] = find_set(parent[i]));
    }
};

pair<int, vector<int>>
kruskal(int N, vector<edge>& es, int blocked = -1)
{
    vector<int> mst;
    UnionFind ufds(N);
    int cost = 0;

    for (int i = 0; i < (int) es.size(); ++i)
    {
        auto [w, u, v] = es[i];

        if (i != blocked and not ufds.same_set(u, v)) {
            cost += w;
            ufds.union_set(u, v);
            mst.emplace_back(i);
        }
    }

    return { (int) mst.size() == N - 1 ? cost : oo, mst };
}

pair<int, int> solve(int N, vector<edge>& es)
{
    sort(es.begin(), es.end());

    auto [best, mst] = kruskal(N, es);
    int _2nd_best = oo;

    for (auto blocked : mst)
    {
        auto [cost, __] = kruskal(N, es, blocked);
        _2nd_best = min(_2nd_best, cost);
    }

    return { best, _2nd_best };
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<edge> es(M);

        for (int i = 0; i < M; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;

            es[i] = edge(w, u, v);
        }

        auto [x, y] = solve(N, es);

        cout << x << ' ' << y << '\n';
    }

    return 0;
}
