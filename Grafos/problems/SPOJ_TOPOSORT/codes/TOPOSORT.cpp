// SPOJ TOPOSORT - Topological Sorting (https://www.spoj.com/problems/TOPOSORT/)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 200010 };

set<int> in[MAX], out[MAX];

vector<int> topological_sort(int N)
{
    vector<int> o;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int u = 1; u <= N; ++u)
        if (in[u].empty())
            q.push(u);
    
    while (not q.empty())
    {
        auto u = q.top();
        q.pop();

        o.emplace_back(u);

        for (auto v : out[u])
        {
            in[v].erase(u);

            if (in[v].empty())
                q.push(v);
        }
    }

    return (int) o.size() == N ? o : vector<int> { };
}

vector<int> solve(int N)
{
    return topological_sort(N);
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    while (M--)
    {
        int x, y;
        cin >> x >> y;
    
        out[x].emplace(y);
        in[y].emplace(x);
    }

    auto ans = solve(N);

    if (ans.empty())
        cout << "Sandro fails.\n";
    else
        for (int i = 0; i < N; ++i)
            cout << ans[i] << (i + 1 == N ? '\n' : ' ');

    return 0;
}
