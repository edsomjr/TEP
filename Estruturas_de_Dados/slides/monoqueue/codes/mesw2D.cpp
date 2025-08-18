#include <bits/stdc++.h>

using namespace std;

ostream& operator<<(ostream& os, const vector<vector<int>>& A)
{
    auto N = A.size(), M = A[0].size();

    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < M; ++j)
            os << A[i][j] << (j + 1 == M ? '\n' : ' ');

    return os;
}

auto mesw_2D(int NA, int MA, int H, int W, const vector<vector<int>>& A)
{
    // Aplica o mesw 1D em todas as linhas de A
    auto NC = NA, MC = MA - W + 1;
    vector<vector<int>> C(NC, vector<int>(MC));

    for (int row = 0; row < NA; ++row)
    {
        deque<int> q;

        for (int col = 0; col < W; ++col)
        {
            while (not q.empty() and A[row][q.back()] >= A[row][col])
                q.pop_back();

            q.emplace_back(col);
        }

        C[row][0] = A[row][q.front()];

        for (int L = 0, R = W; R < MA; ++L, ++R)
        {
            if (q.front() == L)
                q.pop_front();

            while (not q.empty() and A[row][q.back()] >= A[row][R])
                q.pop_back();

            q.emplace_back(R);
            C[row][L + 1] = A[row][q.front()];
        }
    }

    // Aplica o mesw 1D em todas as colunas de C
    auto NB = (NC - H + 1), MB = MC;
    vector<vector<int>> B(NB, vector<int>(MB));

    for (int col = 0; col < MC; ++col)
    {
        deque<int> q;

        for (int row = 0; row < H; ++row)
        {
            while (not q.empty() and C[q.back()][col] >= C[row][col])
                q.pop_back();

            q.emplace_back(row);
        }

        B[0][col] = C[q.front()][col];

        for (int L = 0, R = H; R < NC; ++L, ++R)
        {
            if (q.front() == L)
                q.pop_front();

            while (not q.empty() and C[q.back()][col] >= C[R][col])
                q.pop_back();

            q.emplace_back(R);
            B[L + 1][col] = C[q.front()][col];
        }
    }

    return B;
}

int main()
{
    int N = 5, M = 8, H = 2, W = 3;
    vector<vector<int>> A(N, vector<int>(M));

    srand(1234);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            A[i][j] = (rand() % 9) + 1;

    cout << A << "\n";

    auto B = mesw_2D(N, M, H, W, A);

    cout << B << "\n";

    return 0;
}
