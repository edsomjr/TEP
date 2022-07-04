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

string rev(const string& S)
{
    auto P { S };
    reverse(P.begin(), P.end());

    return P;
}

int search(const string& S, const string& P, char delim = '#')
{
    string T { P + delim + S }, R { rev(P) + delim + rev(S) };
    auto zT = z(T), zR = z(R);
    int occ = 0, n = S.size(), m = P.size();

    // Como as string estão indexadas a partir de 0, o índice de k de j em R é igual a n - i + 1
    for (int i = 0; i < n; i++)
        occ += (zT[i + m + 1] + zR[n - i + 1] >= m - 1) ? 1 : 0;

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
    auto S = "rabanete", P = "abane";
    string S1 { S };
    reverse(S1.begin(), S1.end());

    print_table(S, P);
    cout << '\n';
    print_table(S1, P);

    cout << search(S, P) << '\n';

    return 0;
}
