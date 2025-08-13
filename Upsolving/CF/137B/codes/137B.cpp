#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int>& as)
{
    vector<int> found(N + 1, 0);

    for (const auto& a : as)
        if (1 <= a and a <= N)
            found[a] = 1;

    int total = accumulate(found.begin(), found.end(), 0);

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
