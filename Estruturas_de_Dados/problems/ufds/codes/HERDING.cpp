#include <bits/stdc++.h>

using namespace std;

const int MAX { 1010 };
string A[MAX];

class UFDS {
    std::vector<int> size, ps;
    int count;

public:
    UFDS(int N) : size(N + 1, 1), ps(N + 1), count(N)
    {
        std::iota(ps.begin(), ps.end(), 0);
    }

    int find_set(int x)
    {
        return x == ps[x] ? x : (ps[x] = find_set(ps[x]));
    }

    bool same_set(int x, int y)
    {
        return find_set(x) == find_set(y);        
    }

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
        --count;
    }

    int get_count() const { return count; }
};

int solve(int n, int m)
{
    UFDS ufds(n*m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int x = i, y = j;

            switch (A[i][j]) {
            case 'N':
                --x;
                break;

            case 'S':
                ++x;
                break;

            case 'E':
                ++y;
                break;

            case 'W':
                --y;
                break;
            }

            auto u = j + i*m;
            auto v = y + x*m;
            ufds.union_set(u, v);
        }
    }

    return ufds.get_count();
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> A[i];

    cout << solve(n, m) << '\n';

    return 0;
}
