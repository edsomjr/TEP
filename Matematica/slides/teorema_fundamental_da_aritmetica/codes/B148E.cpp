#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll N)
{
    if (N % 2)
        return 0;

    N /= 2;

    ll ans = 0, base = 5;;

    while (N >= base)
    {
        ans += (N / base);
        base *= 5;
    }
 
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    auto ans = solve(N);

    cout << ans << '\n';

    return 0;
}

