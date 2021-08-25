#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<double, int, int>;

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

double msf(int k, int N, vector<edge>& es)
{
    sort(es.begin(), es.end());

    double cost = 0;
    int cc = N;
    UnionFind ufds(N);

    for (auto [w, u, v] : es) {
        if (not ufds.same_set(u, v)) {
            cost = max(cost, w);
            ufds.union_set(u, v);

            if (--cc == k)
                return cost;
        }
    }

    return cost;
}

double solve(int S, int P, const vector<ii>& ps)
{
    vector<edge> es;

    for (int i = 1; i <= P; ++i)
    {
        auto [x, y] = ps[i];

        for (int j = i + 1; j <= P; ++j)
        {
            auto [z, w] = ps[j];
            auto dist = hypot(x - z, y - w);

            es.emplace_back(dist, i, j);
            es.emplace_back(dist, j, i);
        }
    }

    return msf(S, P, es);
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    while (N--)
    {
        int S, P;
        cin >> S >> P;

        vector<ii> ps(P + 1);

        for (int i = 1; i <= P; ++i)
            cin >> ps[i].first >> ps[i].second;

        auto ans = solve(S, P, ps);

        cout << setprecision(2) << fixed << ans << '\n';
    }

    return 0;
}
