#include <bits/stdc++.h>

using namespace std;

string candidates(const string& x)
{
    vector<int> hist(10, 0);
    string cs;

    for (auto c : x)
        hist[c - '0']++;

    for (int i = 9; i >= 0; --i)
        if (hist[i] < 2)
            cs.push_back(i + '0');

    return cs;
}

string ans;

void backtracking(string& L, size_t N, const string& U)
{
    if (not ans.empty())
        return;

    if (L > U)
        return;

    if (L.size() == N)
        ans = L;

    auto cs = candidates(L);

    for (auto c : cs)
    {
        L.push_back(c);
        backtracking(L, N, U);
        L.pop_back();
    }
}

long long solve(string U)
{
    string xs;
    ans = "";
    
    backtracking(xs, U.size(), U);

    return stoll(ans);
}

int main() {
    ios::sync_with_stdio(false);

    string U;

    while (cin >> U)
        cout << solve(U) << '\n';

    return 0;
}
