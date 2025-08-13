#include <bits/stdc++.h>

using namespace std;

int solve(int N, const vector<int>& ps, const vector<int>& qs)
{
    int start = 0;

    while (start < N)
    {
        auto fuel = ps[start], stations = 0;
        auto now = start, next = (now + 1) % N;
 
        while (stations < N and qs[now] <= fuel)
        {
            ++stations;
            fuel -= qs[now];
            fuel += ps[next];

            now = next;
            next = (next + 1) % N;
        }

        if (stations == N)
            return start + 1;

        if (next <= start)
            break;

        start = next;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test)
    {
        int N;
        cin >> N;

        vector<int> ps(N), qs(N);

        for (int i = 0; i < N; ++i)
            cin >> ps[i];

        for (int i = 0; i < N; ++i)
            cin >> qs[i];

        auto ans = solve(N, ps, qs);

        cout << "Case " << test << ": ";

        if (ans > 0)
            cout << "Possible from station " << ans << '\n';
        else
            cout << "Not possible\n";
    }

    return 0;
}
