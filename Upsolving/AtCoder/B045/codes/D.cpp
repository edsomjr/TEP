#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

vector<ll> solve(ll H, ll W, const vector<ii>& ps)
{
    map<ii, int> hs;

    for (auto p : ps)
    {
        auto x = p.first, y = p.second;

        for (int i = -2; i <= 0; ++i)
        {
            for (int j = -2; j <= 0; ++j)
            {
                auto u = x + i, v = y + j;

                if (1 <= u and u <= H - 2 and 1 <= v and v <= W - 2)
                    ++hs[ii(u, v)]; 
            }
        }
    }

    vector<ll> ans(10, 0);

    for (auto p : hs)
        ans[p.second]++;

    ans[0] += (H - 2)*(W - 2) - hs.size();

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int H, W, N;
    cin >> H >> W >> N;

    vector<ii> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i].first >> xs[i].second;

    auto ans = solve(H, W, xs);

    for (auto x : ans)
        cout << x << '\n';

    return 0;
}
