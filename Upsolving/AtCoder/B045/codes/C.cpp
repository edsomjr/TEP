#include <bits/stdc++.h>

using namespace std;

int solve(int N, const vector<int>& xs)
{
    int m = (int) round(accumulate(xs.begin(), xs.end(), 0.0) / N);
    int res = 0;

    for (int i = 0; i < N; ++i)
        res += (xs[i] - m)*(xs[i] - m);

    return res;
}

int main()
{
    int N;
    cin >> N;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, xs);

    cout << ans << '\n';

    return 0;
}
