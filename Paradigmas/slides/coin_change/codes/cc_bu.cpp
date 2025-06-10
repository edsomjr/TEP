#include <bits/stdc++.h>

using namespace std;

const int MAX { 1'010'000 }, oo { 1'000'000'010 };
int st[MAX];

int coin_change(int M, const vector<int>& cs)
{
    for (int m = 1; m <= M; ++m)
        st[m] = oo;

    st[0] = 0;

   for (auto c : cs)
        for (int m = c; m <= M; ++m)
            st[m] = min(st[m], st[m - c] + 1);

    return st[M]; 
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> cs(N);

    for (int i = 0; i < N; ++i)
        cin >> cs[i];

    cout << coin_change(M, cs) << '\n';

    return 0;
}
