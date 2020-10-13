#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 55 };
ll st[MAX][2*MAX*MAX];

ll dp(int i, int sum, int N, int A, const vector<int>& xs)
{
    if (i == N)
        return (sum == N*A ? 1 : 0);

    if (st[i][sum] != -1)
        return st[i][sum];

    st[i][sum] = dp(i + 1, sum, N, A, xs) + 
               dp(i + 1, sum - A + xs[i], N, A, xs);

    return st[i][sum];
}

ll solve(int N, int A, const vector<int>& xs)
{
    memset(st, -1, sizeof st);
    return dp(0, N*A, N, A, xs) - 1;
}

int main()
{
    int N, A;
    cin >> N >> A;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    cout << solve(N, A, xs) << '\n';

    return 0;
}
