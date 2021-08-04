#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 510 };
const ll oo { 1LL << 61 };

ll A[MAX][MAX], dist[MAX][MAX];

vector<ll> solve(int N, vector<int>& xs)
{
    reverse(xs.begin(), xs.end());

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            dist[i][j] = A[i][j];

    unordered_set<int> included;
    vector<ll> ans;

    for (auto x : xs)
    {
        included.insert(x);

         for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                    dist[u][v] = min(dist[u][v], dist[u][x] + dist[x][v]);

       ll sum = 0;
 
       for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                sum += (included.count(u) and included.count(v) ? dist[u][v] : 0);

        ans.emplace_back(sum);
    }

    reverse(ans.begin(), ans.end()); 

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> A[i][j];

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];
    
    auto ans = solve(N, xs);

    for (int i = 0; i < N; ++i)
        cout << ans[i] << (i + 1 == N ? '\n' : ' ');

    return 0;
}
