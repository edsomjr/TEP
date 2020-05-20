#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int solve(int N, int M)
{
    queue<ii> ns;
    set<int> found;

    ns.push(make_pair(N, 0));
    found.insert(N);

    while (not ns.empty())
    {
        auto p = ns.front();
        ns.pop();

        int n = p.first;
        int ops = p.second;
        
        if (n == M)
            return ops;

        vector<int> xs { n * 2, n * 3, n / 2, n / 3, n + 7, n - 7 };

        for (const auto& x : xs)
        {
            if (found.count(x) == 0)
            {
                ns.push(ii(x, ops + 1));
                found.insert(x);
            }
        }
    }

    return -1;
}

int main()
{
    int N, M;
    cin >> N >> M;

    auto ans = solve(N, M);

    cout << ans << endl;

    return 0;
}
