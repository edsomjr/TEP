#include <bits/stdc++.h>

using namespace std;
using edge = tuple<int, int, int>;

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

pair<int, unordered_set<int>>
kruskal(int N, vector<edge>& es, int blocked = -1)
{
    unordered_set<int> mst;
    UnionFind ufds(N);
    int cost = 0;

    for (size_t i = 0; i < es.size(); ++i)
    {
        auto [w, u, v] = es[i];

        if (i != blocked and not ufds.same_set(u, v)) {
            cost += w;
            ufds.union_set(u, v);
            mst.insert(i);
        }
    }

    return { cost, mst };
}

int second_best(int N, vector<edge>& es)
{
    sort(es.begin(), es.end());

    auto [_, mst] = kruskall(N, es);
    int best = 0;

    for (auto blocked : mst)
    {
        auto [cost, __] = kruskal(N, es, blocked);
        best = max(best, cost);
    }

    return best;
}

int main()
{
    vector<edge> es { { 1, 2, 3 }, { 1, 4, 5 }, { 2, 4, 1 }, { 2, 1, 5 }, { 3, 3, 4 },
        { 4, 2, 1 }, { 5, 3, 1 }, { 7, 3, 6 }, { 8, 6, 5 } };

    auto mst = second_best(6, es);

    cout << mst << '\n';

    return 0;
}
