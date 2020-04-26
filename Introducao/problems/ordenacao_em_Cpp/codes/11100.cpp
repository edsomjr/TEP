#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(vector<int>& ds)
{
    map<int, int> hist;
    int n = 0;

    for (const auto& d : ds)
    {
        hist[d]++;
        n = max(n, hist[d]);
    }

    sort(ds.begin(), ds.end(), greater<int>());

    vector<vector<int>> bags(n);

    int pos = 0;

    for (const auto& d : ds)
        bags[pos++ % n].push_back(d);

    return bags;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, test = 0;
    
    while (cin >> N, N)
    {
        vector<int> ds(N);

        for (int i = 0; i < N; ++i)
            cin >> ds[i];

        auto ans = solve(ds);

        if (test++)
            cout << endl;

        cout << ans.size() << endl;

        for (size_t i = 0; i < ans.size(); ++i)
            for (size_t j = 0; j < ans[i].size(); ++j)
                cout << ans[i][j] << (j + 1 == ans[i].size() ? "\n": " ");
    }

    return 0;
}
