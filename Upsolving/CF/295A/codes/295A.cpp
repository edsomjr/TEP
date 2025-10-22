#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

class BITree {
private:
    vector<ll> ts;
    size_t N;

public:
    BITree(size_t n) : ts(n + 1, 0), N(n) {}

    ll value_at(int i)
    {
        return RSQ(i);
    }

    void range_add(size_t i, size_t j, ll x)
    {
        add(i, x);
        add(j + 1, -x);
    }

private:
    int LSB(int n) { return n & (-n); }

    ll RSQ(int i)
    {
        ll sum = 0;

        while (i >= 1) {
            sum += ts[i];
            i -= LSB(i);
        }

        return sum;
    }

    void add(size_t i, ll x)
    {
        while (i <= N)
        {
            ts[i] += x;
            i += LSB(i);
        }
    }
};

struct Op
{
    int L, R;
    ll d;
};

vector<ll> solve(int N, int M, const vector<int>& as, 
                 const vector<Op>& ops, const vector<ii>& qs)
{
    BITree op_tree(M);

    for (const auto& q : qs)
        op_tree.range_add(q.first, q.second, 1);

    BITree ft(N);

    for (int i = 1; i <= M; ++i)
    {
        auto x = op_tree.value_at(i);
        ft.range_add(ops[i].L, ops[i].R, x * ops[i].d);
    }

    vector<ll> ans(N + 1);

    for (int i = 1; i <= N; ++i)
        ans[i] = as[i] + ft.value_at(i);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> as(N + 1);

    for (int i = 1; i <= N; ++i)
        cin >> as[i];

    vector<Op> ops(M + 1);

    for (int i = 1; i <= M; ++i) {
        int L, R, d;
        cin >> L >> R >> d;

        ops[i] = Op { L, R, d };
    }

    vector<ii> qs(K);

    for (int i = 0; i < K; ++i)
        cin >> qs[i].first >> qs[i].second;

    auto ans = solve(N, M, as, ops, qs);

    for (size_t i = 1; i < ans.size(); ++i)
        cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');

    return 0;
}
