#include <bits/stdc++.h>

using namespace std;

map<char, char> open { { '>', '<' }, { ']', '[' }, { '}', '{' }, { ')', '(' } };

int solve(const string& S)
{
    stack<char> st;
    int ans = 0;

    for (const auto& c : S)
    {
        switch (c) {
        case '(':
        case '<':
        case '{':
        case '[':
            st.push(c);
            break;

        default:
            if (st.empty())
                return -1;

            ans += (open[c] == st.top() ? 0 : 1);
            st.pop();
        }
    }

    return st.empty() ? ans : -1;
}

int main()
{
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    auto ans = solve(S);

    if (ans == -1)
        cout << "Impossible\n";
    else
        cout << ans << '\n';

    return 0;
}
