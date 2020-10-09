#include <bits/stdc++.h>

using namespace std;

pair<int, int> solve(const string& s)
{
    int N = (int) s.size();

    // Caso 1: dois caracteres consecutivos
    for (int i = 1; i < N; ++i)
        if (s[i] == s[i - 1])
            return { i, i + 1 };

    // Caso 2: três caracteres consecutivos, extremos iguais 
    for (int i = 2; i < N; ++i)
        if (s[i] == s[i - 2])
            return { i - 1, i + 1 };

    return { -1, -1 };
}

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    auto ans = solve(s);

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}
