#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll N, ll K)
{
    return (K + N - 1)/N;
}

int main()
{
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    cout << solve(N, K) << '\n';

    return 0;
}
