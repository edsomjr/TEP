#include <bits/stdc++.h>

using namespace std;

size_t max_subarray(const vector<int>& xs, size_t K)
{
    auto N = xs.size(), L = 0ul, R = 0ul, odds = 0ul, ans = 0ul;

    while (L < N)
    {
        odds += (xs[L] % 2);

        if (odds <= K)
        {
            R = max(L + 1, R);

            while (R < N and (xs[R] % 2 == 0 or odds < K))
            {
                odds += (xs[R] % 2);
                ++R;
            }

            ans = max(ans, R - L);
        }
 
        odds -= (xs[L] % 2);
        ++L;
    }

    return ans;
}

int main()
{
    vector<int> xs { 1, 2, 3, 4, 5 }, ys { 1, 3, 5 };

    cout << max_subarray(xs, 1) << '\n';
    cout << max_subarray(xs, 2) << '\n';
    cout << max_subarray(ys, 0) << '\n';

    return 0;
}
