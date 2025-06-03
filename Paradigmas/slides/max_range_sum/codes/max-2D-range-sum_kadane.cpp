#include <bits/stdc++.h>

using namespace std;

const int oo { 1000000010 };

int kadane(int N, const vector<int>& as)
{
    vector<int> s(N + 1);
    s[1] = as[1];

    for (size_t i = 2; i < as.size(); ++i)
        s[i] = max(as[i], s[i - 1] + as[i]);

    return *max_element(s.begin() + 1, s.end());
}

int MSR(int N, int M, const vector<vector<int>>& A)
{
    int ans = -oo;

    for (int i = 1; i <= M; ++i)
    {
        vector<int> r(N + 1, 0);

        for (int j = i; j <= M; ++j)
        {
            for (int k = 1; k <= N; ++k)
                r[k] += A[k][j]; 

            ans = max(ans, kadane(N, r));
        }
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
