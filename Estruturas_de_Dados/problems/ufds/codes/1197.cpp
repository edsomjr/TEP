#include <bits/stdc++.h>

using namespace std;

class UFDS
{
    std::vector<int> size, ps;

public:
    UFDS(int N) : size(N + 1, 1), ps(N + 1)
    {
        std::iota(ps.begin(), ps.end(), 0);
    }

    int find_set(int x)
    {
        return x == ps[x] ? x : (ps[x] = find_set(ps[x]));
    }

    bool same_set(int x, int y) { return find_set(x) == find_set(y); }

    void union_set(int x, int y)
    {
        if (same_set(x, y))
            return;

        int p = find_set(x);
        int q = find_set(y);

        if (size[p] < size[q])
            std::swap(p, q);

        ps[q] = p;
        size[p] += size[q];
    }

    int get_size(int x) { return size[find_set(x)]; }
};

int main()
{
    ios::sync_with_stdio(false);

    int n, m;

    while (cin >> n >> m, n | m)
    {
        UFDS ufds(n);

        while (m--)
        {
            int k;
            cin >> k;

            if (k == 0) continue;

            int x;
            cin >> x;
            --k;

            while (k--)
            {
                int y;
                cin >> y;

                ufds.union_set(x, y);
            }
        }

        cout << ufds.get_size(0) << '\n';
    }

    return 0;
}
