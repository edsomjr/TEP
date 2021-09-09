#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 200010 };

unordered_set<int> in[MAX], out[MAX];

vector<int> topological_sort(int N)
{
    vector<int> o;
    queue<int> q;

    for (int u = 1; u <= N; ++u)
        if (in[u].empty())
            q.push(u);
    
    while (not q.empty())
    {
        auto u = q.front();
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

int main()
{
    vector<ii> es { { 1, 3 }, { 2, 1 }, { 2, 3 }, { 2, 4 }, { 3, 4 }, { 3, 8 }, { 4, 5 }, { 4, 7 },
        { 4, 8 }, { 5, 6 }, { 6, 9 }, { 7, 8 }, { 7, 9 }, { 8, 9 } };

    for (auto [u, v] : es)
    {
        out[u].emplace(v);
        in[v].emplace(u);
    }

    auto o = topological_sort(9);

    for (auto u : o)
        cout << u << ' ';
    cout << '\n';

    return 0;
}
