#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

#define MAX 15

char grid[MAX][MAX];
int dist[MAX][MAX];

const map<char, ii> dirs { { 'N', { -1, 0 } }, { 'S', { 1, 0 } },
    { 'W', { 0, -1 } }, { 'E', { 0, 1 } } };

ii solve(int start)
{
    auto steps = 0, x = 1, y = start;

    while (grid[x][y])
    {
        dist[x][y] = ++steps;
        auto [dx, dy] = dirs.at(grid[x][y]);

        grid[x][y] = 0;
        x += dx;
        y += dy;
    }

    return dist[x][y] == -1 ? ii(steps, 0) :
        ii(dist[x][y] - 1, steps - dist[x][y] + 1);
}

int main()
{
    int M, N, start;

    while (scanf("%d %d %d", &M, &N, &start), M | N | start)
    {
        memset(grid, 0, sizeof grid);
        memset(dist, -1, sizeof dist);

        for (int i = 1; i <= M; ++i)
            scanf("%s", &(grid[i][1]));

        auto [steps, loop] = solve(start); 
        
        if (not loop)
            printf("%d step(s) to exit\n", steps);
        else
            printf("%d step(s) before a loop of %d step(s)\n", steps, loop);
    }

    return 0;
}
