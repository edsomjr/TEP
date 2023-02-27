#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m)
{
    int ans = 1, _2s = 0, _5s = 0;

    for (int i = n; i > n - m; i--)
    {
        int x = i;

        while (x % 2 == 0)
        {
            _2s++;
            x /= 2;
        }

        while (x % 5 == 0)
        {
            _5s++;
            x /= 5;
        }

        ans = (ans * x) % 10;
    }

    auto _10s = min(_2s, _5s);
    
    _2s -= _10s;
    _5s -= _10s;

    for (int i = 0; i < _2s; i++)
        ans = (ans * 2) % 10;

    for (int i = 0; i < _5s; i++)
        ans = (ans * 5) % 10;

    return ans;
}

int main()
{
    int N, M;

    while (cin >> N >> M)
        cout << solve(N, M) << endl;

    return 0;
}

