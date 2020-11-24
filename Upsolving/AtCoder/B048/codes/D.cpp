#include <bits/stdc++.h>

using namespace std;

string solve(const string& s)
{
    int x = s.front() == s.back() ? 1 : 0;
    int y = s.size() % 2;

    return x == y ? "Second" : "First";
}

int main()
{
    string s;
    cin >> s;

    cout << solve(s) << '\n';

    return 0;
}
