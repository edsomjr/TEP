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

int solve(int N, const vector<vector<int>>& A)
{
    vector<vector<int>> p(N + 1, vector<int>(N + 1, 0));
    int ans = -oo;

    for (int i = 1; i <= N; ++i)
    {
        vector<int> r(N + 1, 0);

        for (int j = i; j <= N; ++j)
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
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int>> A(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> A[i][j];

    auto ans = solve(N, A);

    cout << ans << endl;

    return 0;
}
