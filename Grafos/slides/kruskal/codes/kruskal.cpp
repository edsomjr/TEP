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

int kruskal(int N, vector<edge>& es)
{
    sort(es.begin(), es.end());

    int cost = 0;
    UnionFind ufds(N);

    for (auto [w, u, v] : es)
    {
        if (not ufds.same_set(u, v))
        {
            cost += w;
            ufds.union_set(u, v);
        }
    }

    return cost;
}

int main()
{
    vector<edge> es { { 1, 2, 3 }, { 1, 4, 5 }, { 2, 4, 1 }, { 2, 1, 5 }, { 3, 3, 4 },
        { 4, 2, 1 }, { 5, 3, 1 }, { 7, 3, 6 }, { 8, 6, 5 } };

    auto mst = kruskal(6, es);

    cout << mst << '\n';

    return 0;
}
