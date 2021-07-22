#include <bits/stdc++.h>

const int N { 6 };
int A[N + 1][N + 1];

int main()
{
    A[1][2] = 2, A[1][3] = 1, A[1][4] = 8;
    A[2][1] = 5, A[2][4] = 7, A[2][5] = 2;
    A[3][1] = 3, A[3][4] = 9, A[3][6] = 4;
    A[4][3] = 1;
    A[5][2] = 3, A[5][6] = 6;
    A[6][4] = 5;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            std::cout << A[i][j] << (j == N ? '\n' : ' ');

    return 0;
}
