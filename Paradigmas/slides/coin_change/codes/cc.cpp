#include <bits/stdc++.h>

using namespace std;

const int MAX { 1010 }, oo { 1000000010 };
int st[MAX];

int coin_change(int m, const vector<int>& cs)
{
    if (m == 0)
        return 0;

    if (st[m] != -1)
        return st[m];

    auto res = oo;

    for (auto c : cs)
        if (c <= m)
            res = min(res, coin_change(m - c, cs) + 1);

    st[m] = res;
    return res; 
}

int main()
{
    memset(st, -1, sizeof st);

    int N, M;
    cin >> N >> M;

    vector<int> cs(N);

    for (int i = 0; i < N; ++i)
        cin >> cs[i];

    cout << coin_change(M, cs) << '\n';

    return 0;
}
