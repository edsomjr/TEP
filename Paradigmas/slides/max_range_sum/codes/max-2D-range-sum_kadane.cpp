#include <bits/stdc++.h>

using namespace std;

const int oo { 1000000010 };

int kadane(const vector<int>& as)
{
    vector<int> s(as.size());
    s[0] = as[0];

    for (size_t i = 1; i < as.size(); ++i)
        s[i] = max(as[i], s[i - 1] + as[i]);

    return *max_element(s.begin(), s.end());
}

int MSR(int N, int M, const vector<vector<int>>& A)
{
    vector<vector<int>> p(N + 1, vector<int>(M + 1, 0));
    int ans = -oo;

    for (int i = 1; i <= N; ++i)
    {
        vector<int> r(N + 1, 0);

        for (int j = i; j <= M; ++j)
        {
            for (int k = 1; k <= N; ++k)
                r[k] += A[k][j]; 

            ans = max(ans, kadane(r));
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
