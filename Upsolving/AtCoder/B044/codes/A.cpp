#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    auto ans = X*min(N, K) + Y*max(0, N - K);

    cout << ans << '\n';

    return 0;
}
