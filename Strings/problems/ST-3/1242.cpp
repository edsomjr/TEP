#include <bits/stdc++.h>

using namespace std;

const set<string> matches { "SB", "BS", "CF", "FC" };

int solve(const string& base)
{
    stack<char> a, b;
    stack<char> &prev = a, &next = b;

    for (auto c : base)
        a.push(c);

    bool match = true;
    int ans = 0;

    while (match)
    {
        match = false;

        while (not prev.empty())
        {
            auto c = prev.top(); prev.pop();

            if (next.empty())
            {
                next.push(c);
                continue;
            }

            string comb { c, next.top() };

            if (matches.count(comb))
            {
                match = true;
                ++ans;
                next.pop();
            } else
                next.push(c);
        }

        swap(next, prev);
    }

    return ans;
}
 
int main()
{
    ios::sync_with_stdio(false);

    string base;

    while (getline(cin, base))
    {
        auto ans = solve(base);

        cout << ans << '\n';
    }

    return 0;
}
