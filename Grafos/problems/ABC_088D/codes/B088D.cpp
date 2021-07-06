// AtCoder Beginner Contest 088 - Problem C: Takahashi's Information (https://abc088.contest.atcoder.jp/tasks/abc088_d)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 60 };

int dist[MAX][MAX];

int solve(const vector<string>& S, int H, int W)
{
    memset(dist, -1, sizeof dist);
    int whites = 0;

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            whites += (S[i][j] == '.' ? 1 : 0);

    queue<ii> q;
    q.push(ii(0, 0));

    dist[0][0] = 1;

    while (not q.empty())
    {
        const vector<ii> dirs { ii(1, 0), ii(0, 1), ii(-1, 0), ii(0, -1) };
        auto [x, y] = q.front();
        q.pop();

        if (x == H - 1 and y == W - 1)
            break;

        for (auto [dx, dy] : dirs)
        {
            int u = x + dx, v = y + dy;

            if (u < 0 or u >= H or v < 0 or v >= W
                or dist[u][v] > -1 or S[u][v] == '#')
                    continue;

            dist[u][v] = dist[x][y] + 1;
            q.push(ii(u, v));
        }
    }

    return dist[H - 1][W - 1] == -1 ? -1 : whites - dist[H - 1][W - 1];
}

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> S(H);

    for (int i = 0; i < H; ++i)
        cin >> S[i];

    cout << solve(S, H, W) << endl;

    return 0;
}
