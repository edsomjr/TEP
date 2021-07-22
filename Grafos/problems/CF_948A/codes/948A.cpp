#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 510 };

char M[MAX][MAX];

bool solve(int R, int C) {
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            if (M[r][c] != 'S')
                continue;

            vector<ii> ps { {r-1, c},  {r+1, c}, {r, c-1}, {r, c+1} };

            for (auto [x, y] : ps) {
                if (M[x][y] == 'W')
                    return false;

                if (M[x][y] == '.')
                    M[x][y] = 'D';
            }
        }
    }

    return true;
}

int main()
{
    int R, C;
    scanf("%d %d", &R, &C);

    for (int r = 1; r <= R; ++r)
        scanf("%s", &M[r][1]);

    auto ans = solve(R, C);

    if (ans)
    {
        printf("Yes\n");

        for (int r = 1; r <= R; ++r)
            printf("%s\n", &M[r][1]);
    } else
        printf("No\n");

    return 0;
}
