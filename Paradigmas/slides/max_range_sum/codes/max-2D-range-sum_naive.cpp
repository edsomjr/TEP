#include <bits/stdc++.h>

using namespace std;

const int oo { 1000000010 };

int MSR(int N, int M, const vector<vector<int>>& A)
{
    int ans = -oo;

    for (int a = 0; a < N; ++a)
        for (int b = 0; b < M; ++b)
            for (int c = a; c < N; ++c)
                for (int d = b; d < M; ++d)
                {
                    int sum = 0;

                    for (int i = a; i <= c; ++i)
                        for (int j = b; j <= d; ++j)
                            sum += A[i][j];

                    ans = max(ans, sum);
                }

    return ans;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];

    auto ans = MSR(N, M, A);

    cout << ans << endl;

    return 0;
}
