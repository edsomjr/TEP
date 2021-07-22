#include <bits/stdc++.h>

using namespace std;
using sii = tuple<string, int, int>;
using ii = pair<int, int>;

map<string, vector<sii>> adj;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

ii dfs(const string& u, const string& b, int x, int y, set<string>& found)
{
    if (found.count(u))
        return ii(0, 0);

    if (u == b)
        return ii(x, y);

    found.insert(u);

    for (auto [v, z, w] : adj[u])
    {
        auto p = x*z, q = y*w, d = gcd(p, q);
        auto [r, s] = dfs(v, b, p/d, q/d, found);

        if (r and s)
            return ii(r, s);
    }

    return ii(0, 0);
}

int main()
{
    ios::sync_with_stdio(false);

    string cmd;

    while (cin >> cmd, cmd.front() != '.')
    {
        switch (cmd.front()) {
        case '!':
        {
            int x, y;
            string a, b, sep;

            cin >> x >> a >> sep >> y >> b;

            auto d = gcd(x, y);
            x /= d;
            y /= d;

            adj[a].emplace_back(b, x, y);
            adj[b].emplace_back(a, y, x);
 
            break;
        }

        case '?':
        {
            string a, b, sep;
            cin >> a >> sep >> b;

            set<string> found;

            auto [x, y] = dfs(a, b, 1, 1, found);

            if (x and y)
                cout << x << ' ' << a << " = " << y << ' ' << b << '\n';
            else
                cout << "? " << a << " = ? " << b << '\n';
        }
        }
    }

    return 0;
}
