#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Song { ll b, l; };

ll solve(vector<Song>& ms)
{
    sort(ms.begin(), ms.end(), [](const Song& x, const Song& y) {
        return x.l < y.l;
    });

    set<ll> bs;
    vector<Song> pending;
    ll ans = 0;

    for (const auto& m : ms)
    {
        if (bs.count(m.b) == 0)  
        {
            bs.insert(m.b);
            ans += (m.l * bs.size());
        } else
            pending.push_back(m);
    }

    for (const auto& m : pending)
        ans += (m.l * bs.size());

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<Song> ms(N);

        for (int i = 0; i < N; ++i)
           cin >> ms[i].b >> ms[i].l;

        cout << solve(ms) << '\n';
    }

    return 0;
}
