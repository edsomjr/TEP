#include <bits/stdc++.h>

using namespace std;

using ll = long long;

auto pge(const vector<ll>& as)
{
    auto N = (int) as.size();
    vector<ll> dp(N, -1);

    for (int i = 1; i < N; ++i)
    {
        ll j = i - 1;

        while (j >= 0 and as[j] <= as[i])
            j = dp[j];

        dp[i] = j;
    }

    return dp;
}

auto ngee(const vector<ll>& as)
{
    auto N = (int) as.size();
    vector<ll> dp(N, N);

    for (int i = N - 2; i >= 0; --i)
    {
        ll j = i + 1;

        while (j < N and as[j] < as[i])
            j = dp[j];

        dp[i] = j;
    }

    return dp;
}

auto sum_of_subarray_maximums(const vector<ll>& as)
{
    auto N = (int) as.size();
    auto L = pge(as), R = ngee(as);
    ll sum = 0;

    for (int i = 0; i < N; ++i)
        sum += as[i]*(i - L[i])*(R[i] - i);

    return sum;
}

int main()
{
    vector<ll> as { 1, 4, 3, 4, 2, 1, 3 };

    cout << sum_of_subarray_maximums(as) << '\n';

    return 0;
}
