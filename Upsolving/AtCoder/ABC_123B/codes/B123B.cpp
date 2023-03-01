#include <bits/stdc++.h>

using namespace std;

const int oo { 1000000010 };

int solve(vector<int> xs)
{
    sort(xs.begin(), xs.end());
    int ans = oo;

    do {
        int t = xs.back();

        for (int i = 0; i < 4; ++i)
            t += 10 * ((xs[i] + 9)/10);

        ans = min(ans, t);
    } while (next_permutation(xs.begin(), xs.end()));

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    vector<int> xs(5);

    for (int i = 0; i < 5; ++i)
        cin >> xs[i];

    auto ans = solve(xs);

    cout << ans << '\n';

    return 0;
}

