#include <bits/stdc++.h>

using namespace std;

const int oo { 1000000010 };

int MSR(int N, int M, const vector<vector<int>>& A)
{
    vector<vector<int>> p(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            p[i][j] = p[i][j-1] + p[i-1][j] - p[i-1][j-1] + A[i][j];

    int ans = -oo, sum;

    for (int a = 0; a < N; ++a)
        for (int b = 0; b < M; ++b)
            for (int c = a; c < N; ++c)
                for (int d = b; d < M; ++d) {
                    sum = p[c][d] - p[a-1][d] - p[c][b-1] + p[a-1][b-1];
                    ans = max(ans, sum);
                }

    return ans;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> A[i][j];

    auto ans = MSR(N, M, A);

    cout << ans << endl;

    return 0;
}
