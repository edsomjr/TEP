#include <bits/stdc++.h>

using namespace std;

vector<int> LIS(int N, const vector<int>& xs)
{
    vector<int> lis(N, 1), ps(N, -1);

    for (int i = 1; i < N; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (xs[i] > xs[j] and lis[j] + 1 > lis[i])
            {
                lis[i] = lis[j] + 1;
                ps[i] = j;
            }
        }
    }

    int best = 0, k = -1;

    for (int i = 0; i < N; ++i)
    {
        if (lis[i] > best)
        {
            best = lis[i];
            k = i;
        }
    }

    vector<int> ans;

    do {
        ans.push_back(xs[k]);
        k = ps[k];
    } while (k != -1);

    reverse(ans.begin(), ans.end());
        
    return ans;
}

int main()
{
    vector<int> xs { 4, 7, 1, 9, 3, 2, 6, 5, 8 };

    auto ans = LIS((int) xs.size(), xs);

    cout << ans.size() << '\n';

    for (size_t i = 0; i < ans.size(); ++i)
        cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');

    return 0;
}
