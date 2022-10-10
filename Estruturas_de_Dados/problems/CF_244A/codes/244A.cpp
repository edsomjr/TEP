#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(size_t N, int K, const vector<int>& as)
{
    unordered_set<int> used(as.begin(), as.end());
    vector<vector<int>> ans(K);
    int nxt = 1;

    for (int i = 0; i < K; ++i)
    {
        ans[i].push_back(as[i]);

        while (ans[i].size() < N) {
            if (used.count(nxt) == 0)
            {
                ans[i].push_back(nxt);
                used.insert(nxt);
            }

            ++nxt;
        }
    }
        
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> as(K);

    for (int i = 0; i < K; ++i)
        cin >> as[i];

    auto ans = solve(N, K, as);

    for (const auto& xs : ans)
        for (int i = 0; i < N; ++i)
            cout << xs[i] << (i + 1 == N ? '\n' : ' ');

    return 0;
}
