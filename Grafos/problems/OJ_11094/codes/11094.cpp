#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 30 };

string A[MAX];
bool visited[MAX][MAX];
const vector<ii> dirs { ii(1, 0), ii(0, 1), ii(-1, 0), ii(0, -1) };

void dfs(int x, int y, int& total, int M, int N, char land)
{
    if (visited[x][y])
        return;

    visited[x][y] = true;
    ++total;

    for (auto [u, v] : dirs)
    {
        int a = x + u, b = (N + y + v) % N;

        if (a < 0 or a == M or A[a][b] != land)
            continue;

        dfs(a, b, total, M, N, land);
    }
}

int solve(int M, int N, int X, int Y)
{
    memset(visited, false, sizeof(visited));

    int total = 0, ans = 0;
    char land = A[X][Y];
    dfs(X, Y, total, M, N, land);

    for (int x = 0; x < M; ++x)
        for (int y = 0; y < N; ++y)
            if (not visited[x][y] and A[x][y] == land)  
            {
                total = 0;
                dfs(x, y, total, M, N, land);
                ans = max(ans, total);
            }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int M, N;

    while (cin >> M >> N)
    {
        for (int i = 0; i < M; ++i)
            cin >> A[i];

        int X, Y;
        cin >> X >> Y;

        cout << solve(M, N, X, Y) << '\n';
    }
 
    return 0;
}
