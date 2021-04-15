#include <bits/stdc++.h>

using namespace std;

struct Query { string c; int x, y; };

vector<int> solve(const vector<vector<int>>& A, int N, int M, const vector<Query>& qs)
{
    vector<int> rs(N + 1), cs(M + 1), ans;

    iota(rs.begin(), rs.end(), 0);
    iota(cs.begin(), cs.end(), 0);

    for (const auto& q : qs)
    {
        switch (q.c.front()) {
        case 'c':
            swap(cs[q.x], cs[q.y]);
            break;

        case 'r':
            swap(rs[q.x], rs[q.y]);
            break;

        default:
            ans.push_back(A[rs[q.x]][cs[q.y]]);
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> A(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> A[i][j];

    vector<Query> qs(K);

    for (int i = 0; i < K; ++i)
        cin >> qs[i].c >> qs[i].x >> qs[i].y;

    auto ans = solve(A, N, M, qs);

    for (auto x : ans)
        cout << x << '\n';

    return 0;
}
