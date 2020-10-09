#include <bits/stdc++.h>

using namespace std;

int pieces(double x, int N, const vector<int>& hs)
{
    auto L = 0, res = 0;

    while (L < N)
    {
        if (hs[L] <= x)
        {
            ++L;
            continue;
        }

        auto R = L + 1;

        while (R < N and hs[R] > x)
            ++R;

        ++res;
        L = R;
    }

    return res + 1;
}

int solve(int N, const vector<int>& hs)
{
    int M = *max_element(hs.begin(), hs.end()), ans = 2;

    for (int i = 1; i <= M; ++i)
        ans = max(ans, pieces(i, N, hs));

   return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> hs(N);

    for (int i = 0; i < N; ++i)
        cin >> hs[i];

    auto ans = solve(N, hs);

    cout << ans << '\n';

    return 0;
}
