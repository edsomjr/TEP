#include <bits/stdc++.h>

int solve(int N, int A, const std::vector<int>& xs)
{
    int ans = 0;

    for (long long s = 1; s < (1LL << N); ++s)
    {
        int sum = 0, m = 0;

        for (long long i = 0; i < N; ++i)
            if (s & (1LL << i))
                sum += xs[i], ++m;

        if (sum % m == 0 and sum / m == A)
            ++ans;
    }

    return ans;
}

int main()
{
    int N, A;
    std::cin >> N >> A;

    std::vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        std::cin >> xs[i];

    auto ans = solve(N, A, xs);

    std::cout << ans << '\n';

    return 0;
}
