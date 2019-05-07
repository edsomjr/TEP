#include <bits/stdc++.h>

using namespace std;

struct BITree {
    vector<int> ts;
    size_t N;

    BITree(size_t n) : ts(n + 1, 0), N(n) {}

    int LSB(int n) { return n & (-n); }

    void add(size_t i, int x)
    {
        while (i <= N)
        {
            ts[i] += x;
            i += LSB(i);
        }
    }

    int RSQ(size_t i, size_t j)
    {
        return RSQ(j) - RSQ(i - 1);
    }

    int RSQ(size_t k)
    {
        int sum = 0;

        while (k)
        {
            sum += ts[k];
            k -= LSB(k);
        }

        return sum;
    }

    void reset(size_t i)
    {
        if (RSQ(i, i) == 1)
            add(i, -1);
    }
};

int main()
{
    ios::sync_with_stdio(false);

    size_t N, M;

    while (cin >> N >> M)
    {
        BITree ft(N);

        for (size_t i = 1; i <= N; ++i)
        {
            ft.add(i, 1);

            for (size_t j = 1; j <= M; ++j)
            {
                int goals;
                cin >> goals;

                if (goals == 0) 
                    ft.reset(i);
            }
        }

        cout << ft.RSQ(1, N) << '\n';
    }

    return 0;
}
