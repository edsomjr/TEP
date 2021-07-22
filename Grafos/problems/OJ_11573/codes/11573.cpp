#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 1010 }, oo { 1000000010 };

int A[MAX][MAX], dist[MAX][MAX];

int solve(int x, int y, int u, int v, int R, int C)
{
    for (int i = 1; i <= R; ++i) 
        for (int j = 1; j <= C; ++j) 
            dist[i][j] = oo;

    dist[x][y] = 0;

    deque<ii> q;
    q.emplace_back(x, y);

    while (not q.empty())
    {
        auto [i, j] = q.front(); q.pop_front();

        if (i == u and j == v)
            break;

        const vector<ii> dirs { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 },
                                { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

        for (int k = 0; k < 8; ++k)
        {
            auto [dx, dy] = dirs[k];
            auto r = i + dx, c = j + dy;

            if (r < 1 or r > R or c < 1 or c > C)
                continue;

            auto w = A[i][j] == k ? 0 : 1;

            if (dist[r][c] > dist[i][j] + w)
            {
                dist[r][c] = dist[i][j] + w;
                w == 0 ? q.emplace_front(r, c) : q.emplace_back(r, c);
            }
        } 
    }

    return dist[u][v];
}

int main()
{
    ios::sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    for (int i = 1; i <= R; ++i)
    {
        string s;
        cin >> s;

        for (int j = 1; j <= C; ++j)
            A[i][j] = s[j - 1] - '0';
    }

    int N;
    cin >> N;

    while (N--)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;

        auto ans = solve(x, y, u, v, R, C);

        cout << ans << '\n';
    }

    return 0;
}
