#include <bits/stdc++.h>

using namespace std;

int solve(int N)
{
    vector<int> contests;

    for (int d = 1; d <= 9; ++d)
        contests.push_back(100*d + 10*d + d);

    auto it = lower_bound(contests.begin(), contests.end(), N);

    return *it;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    auto ans = solve(N);

    cout << ans << '\n';

    return 0;
}
