#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 10000010 };

class BITree {
private:
    vector<int> ts;
    size_t N;

public:
    BITree(size_t n) : ts(n + 1, 0), N(n) {}

    int RSQ(int i, int j)
    {
        return RSQ(j) - RSQ(i - 1);
    }

private:
    int LSB(int n) { return n & (-n); }

    int RSQ(int i)
    {
        int sum = 0;

        while (i >= 1) {
            sum += ts[i];
            i -= LSB(i);
        }

        return sum;
    }

public:
    void add(size_t i, const int& x)
    {
        if (i == 0)
            return;

        while (i <= N)
        {
            ts[i] += x;
            i += LSB(i);
        }
    }
};

ll solve(const vector<int>& as, int N)
{
    BITree ft(MAX);
    ll ans = 0;

    for (int i = N; i > 0; --i) {
        ans += ft.RSQ(0, as[i] - 1);
        ft.add(as[i], 1);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;

        vector<int> as(N + 1);
    
        for (int i = 1; i <= N; ++i)
            cin >> as[i];

        auto ans = solve(as, N);

        cout << ans << '\n';
    }

    return 0;
}
