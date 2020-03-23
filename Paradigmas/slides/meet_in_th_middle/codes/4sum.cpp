#include <bits/stdc++.h>

using namespace std;

vector<int> _4sum(const vector<int>& xs)
{
    using ii = pair<int, int>;
    unordered_map<int, ii> ps;

    for (auto x : xs)
        for (auto y : xs)
            ps[x + y] = ii(x, y);

    for (auto [s, p] : ps)
        if (ps.count(-s))
            return { p.first, p.second, ps[-s].first, ps[-s].second };

    return { };
}

int main()
{
    vector<int> xs { 2, 3, 1, 0, -4, -1 };

    auto ans = _4sum(xs);

    if (ans.empty())
        cout << "Nao ha solucao\n";
    else
        for (int i = 0; i < 4; ++i)
            cout << ans[i] << (i == 3 ? '\n' : ' ');

    return 0;
}

