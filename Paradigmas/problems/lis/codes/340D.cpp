#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

#define REP(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define REPN(i, N) for (int (i) = 0; (i) < N; (i)++)

const int MAX { 2000010 };
const int oo { 2000000010 };

int as[MAX], lis[MAX];

// Não há arestas se os valores estão em ordem crescente
// Logo o conjunto procurado equivale a LIS
void solve(int N)
{
    lis[0] = 0;

    REP(i, 1, N)
        lis[i] = oo;

    int ans = 0;

    REPN(i, N)
    {
        int pos = lower_bound(lis, lis + ans + 1, as[i]) - lis;

        ans = max(ans, pos);
        lis[pos] = min(as[i], lis[pos]);
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    REPN(i, N)
        cin >> as[i];

    solve(N);

    return 0;
}
