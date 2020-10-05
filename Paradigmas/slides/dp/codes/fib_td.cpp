#include <bits/stdc++.h>

using namespace std;

const int MAX { 200010 };

int st[MAX];

int F(int N)
{
    if (N == 0 or N == 1)
        return N;

    if (st[N] != -1)
        return st[N];

    auto res = F(N - 1) + F(N - 2);

    st[N] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    memset(st, -1, sizeof st);

    int N;
    cin >> N;

    cout << F(N) << endl;

    return 0;
}
