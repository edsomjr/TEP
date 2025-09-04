#include <bits/stdc++.h>

using namespace std;

struct Knight
{
    int p, c, idx;

    bool operator<(const Knight& k) const
    {
        return p < k.p;
    }
};
    
vector<long long> solve(vector<Knight>& ks, size_t K)
{
    vector<long long> ans(ks.size());
    priority_queue<int> coins;
    long long sum = 0;

    sort(ks.begin(), ks.end());

    for (auto& knight : ks)
    {
        ans[knight.idx] = (knight.c + sum);
        coins.push(-knight.c);
        sum += knight.c;

        if (coins.size() > K)
        {
            auto coin = coins.top();
            coins.pop();

            sum += coin;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> ps(n), cs(n);

    for (int i = 0; i < n; ++i)
        cin >> ps[i];

    for (int i = 0; i < n; ++i)
        cin >> cs[i];

    vector<Knight> ks(n);

    for (int i = 0; i < n; ++i)
        ks[i] = Knight { ps[i], cs[i], i };

    auto ans = solve(ks, k);

    for (int i = 0; i < n; ++i)
        cout << ans[i] << (i + 1 == n ? "\n" : " ");

    return 0;
}

