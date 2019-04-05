#include <bits/stdc++.h>

using namespace std;

bool solve(const string& S, const string& T)
{
    auto N = S.size();
    map<char, char> s_table, t_table;

    for (size_t i = 0; i < N; ++i)
    {
        auto c = S[i];
        auto d = T[i];
        auto it = s_table.find(c);

        if (it == s_table.end())
        {
            auto jt = t_table.find(d);

            if (jt == t_table.end())
            {
                s_table[c] = d;
                t_table[d] = c;
            } else
                return false;
        } else if (it->second != d)
                return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    string S, T;
    cin >> S >> T;

    auto ans = solve(S, T);

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}
