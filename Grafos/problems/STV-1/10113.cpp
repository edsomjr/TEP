#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<long, long>;

const int MAX { 70 };

ii adj[MAX][MAX];
bitset<MAX> found;
map<string, int> label;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ii dfs(int u, int w, const ii& prev = ii(1, 1))
{
    found[u] = true;

    auto ans = ii(-1, -1);
    int N = label.size();

    for (int v = 1; v <= N; ++v)
    {
        auto p = adj[u][v];

        if (found[v] or p == ii(0, 0))
            continue;

        // Taxa de conversão de v para w
        auto m = prev.first * p.first;
        auto n = prev.second * p.second;
        auto d = gcd(m, n);

        m /= d;
        n /= d;

        if (v == w)
            return ii(m, n);

        ans = dfs(v, w, ii(m, n));

        if (ans != ii(-1, -1))
            return ans;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    string cmd, from, to, equals;
    int idx = 0;

    while (cin >> cmd)
    {
        switch (cmd[0]) {
        case '!':
            {
                ll m, n;

                cin >> m >> from >> equals >> n >> to;

                if (label.count(from) == 0)
                    label[from] = ++idx;

                if (label.count(to) == 0)
                    label[to] = ++idx;

                auto d = gcd(m, n);
                auto u = label[from], v = label[to];

                adj[u][v] = ii(m/d, n/d);
                adj[v][u] = ii(n/d, m/d);
            }

        break;

        case '?':
            {
                cin >> from >> equals >> to;

                auto u = label[from], v = label[to];

                found.reset();
                auto p = dfs(u, v);

                if (p == ii(-1, -1))
                {
                    cout << "? " << from << " = ? " << to << '\n';
                    break;
                }

                cout << p.first << " " << from << " = " << p.second 
                    << " " << to << '\n';
            }
        }
    }

    return 0;
}
