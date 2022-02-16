#include <bits/stdc++.h>

using ll = long long;

ll solve(int N, int M, int A)
{
    ll w = (N + A - 1)/A; 
    ll h = (M + A - 1)/A; 

    return w * h;
}

int main()
{
    int N, M, A;
    std::cin >> N >> M >> A;

    auto ans = solve(N, M, A);
    std::cout << ans << '\n';

    return 0;
}
