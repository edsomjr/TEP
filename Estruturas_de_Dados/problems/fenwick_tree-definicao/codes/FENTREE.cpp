#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct BITree {
    vector<ll> ts;
    size_t N;

    BITree(size_t n) : ts(n + 1, 0), N(n) {}

    ll LSB(ll n) { return n & (-n); }

    void add(size_t i, ll x)
    {
        while (i <= N)
        {
            ts[i] += x;
            i += LSB(i);
        }
    }

    ll RSQ(size_t i, size_t j)
    {
        return RSQ(j) - RSQ(i - 1);
    }

    ll RSQ(size_t k)
    {
        ll sum = 0;

        while (k)
        {
            sum += ts[k];
            k -= LSB(k);
        }

        return sum;
    }
};

int main()
{
    ios::sync_with_stdio(false);

    size_t N;
    cin >> N;

    BITree ft(N);

    for (size_t i = 1; i <= N; ++i)
    {
        int a;
        cin >> a;

        ft.add(i, a);
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        string cmd;
        ll L, R;

        cin >> cmd >> L >> R;

        switch (cmd[0]) {
        case 'q':
            cout << ft.RSQ(L, R) << '\n';
            break;

        default:
            ft.add(L, R);
        }
    }

    return 0;
}
