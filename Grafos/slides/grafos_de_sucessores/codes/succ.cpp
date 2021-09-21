#include <bits/stdc++.h>

using namespace std;

const int Nmax { 100010 }, iMax { 30 };

int S[Nmax][iMax];

void precomp(int N, int M, const vector<int>& s)
{
    for (int u = 1; u <= N; ++u)
        S[u][0] = s[u];

    for (int i = 1; i <= M; ++i)
        for (int u = 1; u <= N; ++u)
            S[u][i] = S[S[u][i - 1]][i - 1];
}

int succ(int u, int k)
{
    for (int i = 0; (1 << i) <= k; ++i)
        if (k & (1 << i))
            u = S[u][i];

    return u;
}

int main()
{
    vector<int> s { 0, 2, 3, 5, 3, 6, 1 };

    precomp(6, 8, s);

    cout << succ(4, 14) << '\n';

    return 0;
}
