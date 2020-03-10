#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{
    int N;
    std::vector<int> ns;

public:
    SegmentTree(int n) : N(n), ns(4*N, 0) { }

    void update(int i, int value)
    {
        update(1, 0, N - 1, i, value);
    }

    int RSQ(int a, int b)
    {
        return RSQ(1, 0, N - 1, a, b);
    }

private:
    void update(int node, int L, int R, int i, int value)
    {   
        if (i > R or i < L)
            return;
        
        ns[node] += value;

        if (L == R)
            return;

        update(2*node, L, (L+R)/2, i, value);
        update(2*node + 1, (L+R)/2 + 1, R, i, value);
    } 

    int RSQ(int node, int L, int R, int a, int b)
    {
        if (a > R or b < L)
            return 0;

        if (a <= L and R <= b)
            return ns[node];

        auto x = RSQ(2*node, L, (L + R)/2, a, b);
        auto y = RSQ(2*node + 1, (L + R)/2 + 1, R, a, b);

        return x + y;
    }
};

int main()
{
    int N, K;

    while (cin >> N >> K) {
        vector<int> xs(N);
        SegmentTree zeroes(N), negatives(N);

        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
    
            if (x == 0)
                zeroes.update(i, 1);
            else if (x < 0)
                negatives.update(i, 1);
        }

        while (K--)
        {
            string cmd;
            int x, y;

            cin >> cmd >> x >> y;

            switch (cmd.front()) {
            case 'C':
                --x;

                zeroes.update(x, -zeroes.RSQ(x, x));
                negatives.update(x, -negatives.RSQ(x, x));

                if (y == 0)
                    zeroes.update(x, 1);
                else if (y < 0)
                    negatives.update(x, 1);

                break;
            default:
                --x; --y;

                if (zeroes.RSQ(x, y))
                    cout << 0;
                else
                    cout << (negatives.RSQ(x, y) % 2 ? '-' : '+');
            }
        }

        cout << '\n';
    }

    return 0;
}
