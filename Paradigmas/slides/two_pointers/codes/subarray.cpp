#include <bits/stdc++.h>

using namespace std;

size_t max_subarray(const vector<int>& xs, size_t K) {
    auto N = xs.size(), L = 0ul, R = 0ul, odds = 0ul, ans = 0ul;

    while (L < N) {
        R = max(L, R);

        while (R < N and (xs[R] % 2 == 0 or odds < K))
            odds += (xs[R++] % 2);

        ans = max(ans, R - L);
        odds = max(odds - (xs[L] % 2), 0ul);
        ++L;
    }

    return ans;
}

int main()
{
    vector<int> xs { 1, 3, 5, 4, 5 }, ys { 1, 3, 5 };

    cout << max_subarray(xs, 1) << '\n';
    cout << max_subarray(xs, 2) << '\n';
    cout << max_subarray(xs, 3) << '\n';
    cout << max_subarray(ys, 0) << '\n';

    return 0;
}
