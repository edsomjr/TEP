#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int solve(const vector<int>& vs, int N)
{
    map<int, int> hist[2];
    vector<ii> cost[2];

    for (int k = 0; k < 2; ++k)
    {
        for (int i = k; i < N; i += 2)
            ++hist[k][vs[i]];

        // Corner case: caso todos os elementos sejam iguais, devemos
        // ter uma segunda opção de escolha
        hist[k][100001] = 0;

        for (const auto& p : hist[k])
        {
            int v, n;
            tie(v, n) = p;

            cost[k].push_back(ii(N/2 - n, v));
        }

        sort(cost[k].begin(), cost[k].end());
    }

    enum { ODD = 0, EVEN = 1 };

    auto ans = cost[ODD][0].second == cost[EVEN][0].second ? 
        min(cost[ODD][0].first + cost[EVEN][1].first, 
            cost[ODD][1].first + cost[EVEN][0].first) 
        : cost[ODD][0].first + cost[EVEN][0].first;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> vs(N);

    for (int i = 0; i < N; ++i)
        cin >> vs[i];

    auto ans = solve(vs, N);

    cout << ans << '\n';

    return 0;
}
