
#include <bits/stdc++.h>

using namespace std;

auto pge(const vector<int>& as)
{
    auto N = (int) as.size();
    vector<int> dp(N, -1);

    for (int i = 1; i < N; ++i)
    {
        auto j = i - 1;

        while (j >= 0 and as[j] <= as[i])
            j = dp[j];

        dp[i] = j;
    }

    return dp;
}

auto nge(const vector<int>& as)
{
    auto N = (int) as.size();
    vector<int> dp(N, N);

    for (int i = N - 2; i >= 0; --i)
    {
        auto j = i + 1;

        while (j < N and as[j] <= as[i])
            j = dp[j];

        dp[i] = j;
    }

    return dp;
}

int main()
{
    vector<int> as { 1, 4, 3, 4, 2, 1, 3 };
    auto is = pge(as);
    auto js = nge(as);

    cout << "i:   ";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << setfill(' ') << i << (i + 1 == as.size() ? '\n' : ' ');

    cout << "as:  ";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << setfill(' ') << as[i] << (i + 1 == as.size() ? '\n' : ' ');

    cout << "pge: ";
    for (size_t i = 0; i < is.size(); ++i)
        cout << setw(2) << setfill(' ') << is[i] << (i + 1 == is.size() ? '\n' : ' ');

    cout << "nge: ";
    for (size_t i = 0; i < js.size(); ++i)
        cout << setw(2) << setfill(' ') << js[i] << (i + 1 == js.size() ? '\n' : ' ');

    return 0;
}
