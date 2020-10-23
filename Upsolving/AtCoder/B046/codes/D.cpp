#include <bits/stdc++.h>

using namespace std;

int solve(int N, const string& s)
{
    int p = 0;

    for (auto c : s)
        p += (c == 'p' ? 1 : 0);

    int P = N/2;

    return P - p;
}

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    auto ans = solve((int) s.size(), s);

    cout << ans << '\n';

    return 0;
}
