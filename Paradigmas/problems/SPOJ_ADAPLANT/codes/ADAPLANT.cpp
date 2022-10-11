#include <bits/stdc++.h>

using namespace std;

int solve(int N, int K, const vector<int>& xs)
{
    K = min(N - 1, K + 1);

    int L = 0, R;
    multiset<int> s;

    for (R = 0; R <= K; ++R)
        s.insert(xs[R]);

    int ans = *s.rbegin() - *s.begin();

    while (R < N) {
        auto it = s.find(xs[L]);
        s.erase(it);
        s.insert(xs[R]);

        ans = max(ans, *s.rbegin() - *s.begin());
        ++L;
        ++R;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int N, K;
        cin >> N >> K;

        vector<int> xs(N);

        for (int i = 0; i < N; ++i)
            cin >> xs[i];

        auto ans = solve(N, K, xs);

        cout << ans << endl;
    }

    return 0;
}
