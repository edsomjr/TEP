#include <bits/stdc++.h>

using namespace std;

vector<int> z(const string &s)
{
    int n = s.size(), L = 0, R = 0;
    vector<int> zs(n, 0);

    for (int i = 1; i < n; i++)
    {
        if (i <= R)
            zs[i] = min(zs[i - L], R - i + 1);

        while (zs[i] + i < n && s[zs[i]] == s[i + zs[i]])
            zs[i]++;

        if (R < i + zs[i] - 1)
            L = i, R = i + zs[i] - 1;
    }

    return zs;
}

int search(const string& S, const string& P, char delim = '#')
{
    string T { P + delim + S };
    auto zs = z(T);
    int occ = 0, m = P.size();

    for (const auto x : zs)
        occ += (x == m ? 1 : 0);

    return occ;
}

void print_table(const string& S, const string& P, char delim = '#')
{
    string T { P + delim + S };
    auto zs = z(T);
    int n = zs.size();

    printf("   i   |");

    for (int i = 1; i <= n; ++i)
        printf("%3d", i);

    printf("\n   T   |");

    for (int i = 1; i <= n; ++i)
        printf("%3c", T[i - 1]);

    printf("\n zs[i] |");

    for (int i = 1; i <= n; ++i)
        printf("%3d", zs[i - 1]);

    printf("\n");
}

int main()
{
    auto S = "banana", P = "ana";

    print_table(S, P);
    cout << search(S, P) << '\n';

    return 0;
}
