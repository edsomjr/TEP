#include <bits/stdc++.h>

using namespace std;

class BITree
{
private:
    int N;
    vector<int> ft, zs;

    int LSB(int n) { return n & -n; }
 
public:
    BITree(int n) : N(n), ft(N + 1, 1), zs(N + 1, 0) { }

    int RPQ(int i, int j)
    {
        auto p = RPQ(j) / RPQ(i - 1);
        auto z = RSQ(i, j);
        return z ? 0 : p;
    }

    void update(int i, int v)
    {
        // Remove o elemento
        auto x = RPQ(i, i);
        x ? multiply(i, x/abs(x)) : add(i, -1);

        // Insere o novo elemento
        v ? multiply(i, v/abs(v)) : add(i, 1);
    }
    
private:
    int RPQ(int i)
    {
        int prod = 1;

        while (i)
        {
            prod *= ft[i];
            i -= LSB(i);
        }

        return prod;
    }

    int RSQ(int i, int j)
    {
        return RSQ(j) - RSQ(i - 1);
    }

    int RSQ(int i)
    {
        int sum = 0;

        while (i)
        {
            sum += zs[i];
            i -= LSB(i);
        }

        return sum;
    }

    void multiply(int i, int v)
    {
        while (i <= N)
        {
            ft[i] *= v;
            i += LSB(i);
        }
    }

    void add(int i, int v)
    {
        while (i <= N)
        {
            zs[i] += v;
            i += LSB(i);
        }
    }
};

struct Query {
    char c;
    int i, j;
};

string solve(BITree& ft, const vector<Query>& qs)
{
    ostringstream os;

    for (const auto& q : qs)
    {
        switch (q.c) {
        case 'C':
            ft.update(q.i, q.j);
            break;

        default:
            auto p = ft.RPQ(q.i, q.j);
            os << (p ? (p > 0 ? '+' : '-') : '0');
        }
    }

    return os.str();
}

int main()
{
    ios::sync_with_stdio(false);
    int N, K;

    while (cin >> N >> K)
    {
        BITree ft(N);

        for (int i = 1; i <= N; ++i)
        {
            int x;
            cin >> x;

            ft.update(i, x);
        }

        vector<Query> qs;

        while (K--)
        {
            string c;
            int i, j;

            cin >> c >> i >> j;

            qs.push_back({ c[0], i, j });
        }

        auto ans = solve(ft, qs);

        cout << ans << '\n';
    }

    return 0;
}
