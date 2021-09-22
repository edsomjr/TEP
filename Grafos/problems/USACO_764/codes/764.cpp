// USACO 2017 December Contest, Silver - Problem 3: The Bovine Shuffle (http://www.usaco.org/index.php?page=viewproblem2&cpid=764)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };

int in_degree[MAX], num[MAX];
bitset<MAX> found;

auto solve(int N, const vector<int>& as)
{
    for (int u = 1; u <= N; ++u)
        ++in_degree[as[u]];

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for (int u = 1; u <= N; ++u)
        pq.emplace(in_degree[u], u);

    auto ans = 0;

    while (not pq.empty())
    {
        auto [_, u] = pq.top();
        pq.pop();

        if (found[u])
            continue;

        auto next = 1, len = 0;
        set<int> s;

        while (num[u] == 0)
        {
            num[u] = next++;
            found[u] = true;

            s.insert(u);
            u = as[u];
        }

        if (s.count(u))
            len = next - num[u];

        ans += len;
    }
 
    return ans;
}

int main()
{
    ifstream in("shuffle.in");
    ofstream out("shuffle.out");

    int N;
    in >> N;

    vector<int> as(N + 1);

    for (int i = 1; i <= N; ++i)
        in >> as[i];

    auto ans = solve(N, as);

    out << ans << '\n';

    return 0;
}
