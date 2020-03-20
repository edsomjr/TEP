#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int>& as)
{
    vector<int> found(N + 1, 0);

    for (const auto& a : as)
        if (a >= 1 and a <= N)
            found[a] = 1;

    int total = 0;

    for (const auto& x : found)
        total += x;

    return N - total;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> as(N);

    for (int i = 0; i < N; ++i)
        cin >> as[i];

    cout << solve(N, as) << '\n';

    return 0;
}
