#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int oo { 1000000010 };
const vector<ii> dirs { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

int solve(int N, int M, int R, int C, int X, int Y, const vector<string>& A)
{
    vector<vector<int>> dist(N + 1, vector<int>(M + 1, oo));
    dist[R][C] = 0;

    deque<ii> q;
    q.emplace_back(R, C);
    
    while (not q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();

        for (auto [dx, dy] : dirs) {
            auto u = x + dx, v = y + dy;

            if (u < 0 or u >= N or v < 0 or v >= M)
                continue;

            if (A[u][v] == '*')
                continue;

            auto w = dy == -1 ? 1 : 0;

            if (dist[u][v] > dist[x][y] + w) {
                dist[u][v] = dist[x][y] + w;
                w == 0 ? q.emplace_front(u, v) : q.emplace_back(u, v);
            }
        }
    }

    auto ans = 0, yi = C;

    for (int xj = 0; xj < N; ++xj)
        for (int yj = 0; yj < M; ++yj) {
            auto left = dist[xj][yj];
            auto right = left + yj - yi;
            ans += (left <= X and right <= Y ? 1 : 0);
        }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int R, C;
    cin >> R >> C;

    int X, Y;
    cin >> X >> Y;

    vector<string> A(N);

    for (int i = 0; i < N; ++i) 
        cin >> A[i];

    auto ans = solve(N, M, R - 1, C - 1, X, Y, A);

    cout << ans << '\n';

    return 0;
}
