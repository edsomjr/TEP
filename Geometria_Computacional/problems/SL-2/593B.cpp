#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll oo { 1000000000000000000LL };

struct Line
{
    ll k, b;

    ll eval(ll x) const { return k*x + b; }
};

bool solve(ll x1, ll x2, vector<Line>& lines)
{
    // Ordenação por coordenada y em x1, depois em x2
    sort(lines.begin(), lines.end(), [&](const Line& r, const Line& s) {
        if (r.eval(x1) != s.eval(x1))
            return r.eval(x1) < s.eval(x1);

        return r.eval(x2) < s.eval(x2);
    });

    auto max_y = -oo;

    for (const auto& r : lines)
    {
        auto y = r.eval(x2);

        if (y < max_y)
            return true;

        max_y = max(y, max_y);
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int x1, x2;
    cin >> x1 >> x2;

    vector<Line> lines(n);

    for (int i = 0; i < n; ++i)
        cin >> lines[i].k >> lines[i].b;

    auto ans = solve(x1, x2, lines);

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}
