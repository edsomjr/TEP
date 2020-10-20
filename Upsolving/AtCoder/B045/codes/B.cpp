#include <bits/stdc++.h>

using namespace std;

char solve(string& sa, string& sb, string& sc)
{
    vector<string> xs { sa, sb, sc };
    int next = 0;

    for (int i = 0; i < 3; ++i)
        reverse(xs[i].begin(), xs[i].end());

    while (not xs[next].empty())
    {
        auto c = xs[next].back();
        xs[next].pop_back();
        next = c - 'a';
    }

    return char(next + 'A');
}

int main()
{
    ios::sync_with_stdio(false);

    string sa, sb, sc;
    cin >> sa >> sb >> sc;

    auto ans = solve(sa, sb, sc);

    cout << ans << '\n';

    return 0;
}
