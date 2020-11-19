#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using ll = long long;

const int MAXN { 2010 }, MAXM { 2010 };

ll st[MAXN][MAXM];
char ps[MAXN][MAXM];

pair<ll, vector<int>> knapsack(int M, const vector<ii>& cs)
{
    int N = (int) cs.size() - 1;  // Os elementos começam em 1

    // Casos-base
    for (int i = 0; i <= N; ++i)
        st[i][0] = 0;

    for (int m = 0; m <= M; ++m)
        st[0][m] = 0;

    // Transições
    for (int i = 1; i <= N; ++i)
    {
        for (int m = 1; m <= M; ++m)
        {
            st[i][m] = st[i - 1][m];
            ps[i][m] = 0;

            auto [w, v] = cs[i];

            if (w <= m and st[i - 1][m - w] + v > st[i][m])
            {
                st[i][m] = st[i - 1][m - w] + v;
                ps[i][m] = 1;
            }
        }
    }

    // Recuperação dos elementos
    int m = M;
    vector<int> is;

    for (int i = N; i >= 0; --i)
    {
        if (ps[i][m])
        {
            is.push_back(i);
            m -= cs[i].first;
        }
    }

    reverse(is.begin(), is.end());

    return { st[N][M], is };
}

int main()
{
    vector<ii> cs { {}, { 2, 3 }, { 5, 5 }, { 3, 3 } };
    int M = 5;

    auto [ans, is] = knapsack(M, cs);

    cout << ans << '\n';

    for (auto i : is)
        cout << i << ' ';
    cout << '\n';

    return 0;
}
