#include <bits/stdc++.h>

using namespace std;

int solve(const string& s)
{
    int ans = 0, N = (int) s.size();

    int L = 0;

    while (L < N)
    {
        auto R = L;

        while (R < N and s[R] == s[L])
            ++R;

        if (R == N)
            break;

        ++ans;
        L = R;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    auto ans = solve(s);

    cout << ans << '\n';

    return 0;
}
