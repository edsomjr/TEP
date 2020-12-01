#include <bits/stdc++.h>

using namespace std;

const int MAX { 17 }, oo { 2000000010 };

int dist[MAX][MAX];
int st[MAX][1 << MAX];

int tsp(int i, int mask, int N)
{
    if (mask == (1 << N) - 1)
        return dist[i][0];

    if (st[i][mask] != -1)
        return st[i][mask];

    int res = oo;

    for (int j = 0; j < N; ++j)
    {
        if (mask & (1 << j))
            continue;

        res = min(res, tsp(j, mask | (1 << j), N) + dist[i][j]);
    }

    st[i][mask] = res;
    return res;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> dist[i][j];

    memset(st, -1, sizeof st);

    cout << tsp(0, 1, N) << '\n';

    return 0;
}
