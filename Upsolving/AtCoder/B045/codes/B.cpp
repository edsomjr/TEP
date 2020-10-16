#include <bits/stdc++.h>

using namespace std;

string solve(const string& s)
{
    string res;

    for (auto c : s)
    {
        if (c == '0' or c == '1')
            res.push_back(c);
        else if (not res.empty())
            res.pop_back();
    }

    return res;
}

int main()
{
    string s;
    cin >> s;

    auto ans = solve(s);

    cout << ans << '\n';

    return 0;
}
