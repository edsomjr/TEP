#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

class SegmentTree
{
public:

    SegmentTree(const std::vector<ii>& xs) : N(xs.size()), ns(4*N)
    {
        for (size_t i = 0; i < xs.size(); ++i)
            update(i, xs[i]);
    }

    void update(int i, const ii& value)
    {
        update(1, 0, N - 1, i, value);
    }

    ll query(int a, int b)
    {
        auto ans = RSQ(1, 0, N - 1, a, b);
        return ans.first + ans.second;
    }

private:

    int N;
    std::vector<ii> ns;

    void update(int node, int L, int R, int i, const ii& value) {   
        if (i > R or i < L)
            return;
        
        if (L == R)
        {
            ns[node] = value;
            return;
        }

        update(2*node, L, (L+R)/2, i, value);
        update(2*node + 1, (L+R)/2 + 1, R, i, value);

        vector<ll> ys { ns[2*node].first, ns[2*node + 1].first,
            ns[2*node].second, ns[2*node + 1].second };

        sort(ys.begin(), ys.end());

        ns[node] = ii(ys[3], ys[2]);
    } 

    ii RSQ(int node, int L, int R, int a, int b) {
        if (a > R or b < L)
            return ii(0, 0);

        if (a <= L and R <= b)
            return ns[node];

        auto x = RSQ(2*node, L, (L + R)/2, a, b);
        auto y = RSQ(2*node + 1, (L + R)/2 + 1, R, a, b);

        vector<ll> ys { x.first, x.second, y.first, y.second };

        sort(ys.begin(), ys.end());

        return ii(ys[3], ys[2]);
    }
};

int main()
{
    ios::sync_with_stdio(false);

    int N; cin >> N;

    vector<ii> xs(N, ii(0, 0));

    for (int i = 0; i < N; ++i)
        cin >> xs[i].first;

    auto tree = SegmentTree(xs);
    int Q; cin >> Q;

    while (Q--) {
        string cmd;
        int x, y;

        cin >> cmd >> x >> y;

        switch (cmd.front()) {
        case 'U':
            tree.update(x - 1, ii(y, 0));
            break;
        default:
            cout << tree.query(x - 1, y - 1) << '\n';
        }
    }

    return 0;
}
