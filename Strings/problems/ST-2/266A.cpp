#include <bits/stdc++.h>

using namespace std;

int solve(const string& s)
{
    int ans = 0;
    char last = ' ';

    for (const auto& c : s)
    {
        if (c == last)
            ++ans;
        else
            last = c;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    string s;

    cin >> n >> s;

    auto ans = solve(s);

    cout << ans << '\n';

    return 0;
}
