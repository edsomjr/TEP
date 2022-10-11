#include <bits/stdc++.h>

using namespace std;

vector<int> solve(const vector<int>& xs)
{
    vector<int> ans;

    for (auto x : xs)
        if (x > 0)
            ans.push_back(x);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N, N)
    {
        vector<int> xs(N);

        for (int i = 0; i < N; ++i)
            cin >> xs[i];

        auto ans = solve(xs);

        if (ans.empty())
            cout << 0 << '\n';
        else 
            for (size_t i = 0; i < ans.size(); ++i)
                cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
    }

    return 0;
}
