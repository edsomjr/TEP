#include <bits/stdc++.h>

using namespace std;

const int MAX { 1000 };

int a[MAX], b[MAX];

int edit(const string& s, const string& t)
{
    const int c_i = 1, c_r = 1, c_s = 1;      // Custos iguais a um
    int m = s.size(), n = t.size(), *prev = a, *line = b;

    for (int j = 1; j <= n; ++j)
        prev[j] = j*c_i;

    for (int i = 1; i <= m; ++i)
    {
        line[0] = i*c_r;

        for (int j = 1; j <= n; ++j) {
            int insertion = line[j - 1] + c_i;
            int deletion = prev[j] + c_r;
            int change = prev[j-1] + c_s*(s[i-1] == t[j-1] ? 0 : 1);
            line[j] = min({ insertion, deletion, change });
        }

        swap(line, prev);
    }

    return prev[n];
}

int main()
{
    string s { "TEP" }, t { "ACCEPTED" };
    cout << edit(s, t) << '\n';

    return 0;
}
