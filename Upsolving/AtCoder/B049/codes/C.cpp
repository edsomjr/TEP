#include <bits/stdc++.h>

using namespace std;

vector<pair<string, size_t>> words {
    { "dream", 5 }, { "dreamer", 7 }, { "erase", 5 }, { "eraser", 6 } };

bool solve(string& s)
{
    while (not s.empty())
    {
        bool ok = false;

        for (auto [w, size] : words)
        {
            if (size <= s.size() and s.substr(s.size() - size) == w)
            {
                ok = true;

                while (size--)
                    s.pop_back();
            }
        }

        if (not ok)
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    cout << (solve(s) ? "YES" : "NO") << '\n';

    return 0;
}
