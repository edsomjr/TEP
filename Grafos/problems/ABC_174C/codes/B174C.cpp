#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 1000010 };

bitset<MAX> found;

int solve(int K)
{
    ll r = 0;

    for (int i = 1; i < MAX; ++i)
    {
        r = (10*r + 7) % K;

        if (r == 0)
            return i;

        if (found[r])
            return -1;

        found[r] = true;
    }
        
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);

    int K;
    cin >> K;

    auto ans = solve(K);

    cout << ans << '\n';

    return 0;
}
