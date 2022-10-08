#include <bits/stdc++.h>

using namespace std;
using Op = int (*)(int, int);

class SegmentTree {
    int N;
    std::vector<int> ns;
    
public:
    SegmentTree(const std::vector<int>& xs) : N(xs.size()), ns(2*N) {
        std::copy(xs.begin(), xs.end(), ns.begin() + N);

        int k = N;
        Op op = [](int x, int y) { return x | y; };
        Op next = [](int x, int y) { return x ^ y; };

        while (k >>= 1) {
            for (int i = k; i < 2*k; ++i)
                ns[i] = op(ns[2*i], ns[2*i + 1]);

            swap(op, next);
        }
    }

    int update(int i, int value)
    {
        int a = i + N - 1;
        ns[a] = value;

        Op op = [](int x, int y) { return x | y; };
        Op next = [](int x, int y) { return x ^ y; };

        while (a >>= 1) {
            ns[a] = op(ns[2*a], ns[2*a + 1]);
            swap(op, next);
        }

        return ns[1];
    }
};

int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> xs(1 << n);

    for (int i = 0; i < (1 << n); ++i)
        cin >> xs[i];

    SegmentTree tree(xs);

    while (m--)
    {
        int p, b;
        cin >> p >> b;

        cout << tree.update(p, b) << '\n';
    }

    return 0;
}
