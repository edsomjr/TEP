#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int solve(int N, vector<int>& hs)
{
    // Compressão dos adjacentes iguais
    auto it = unique(hs.begin(), hs.end());

    N = (int) distance(hs.begin(), it);
    hs.resize(N);

    // Identificação dos pontos críticos
    vector<int> cs;
 
    for (int i = 1; i <= N - 2; ++i)
        if ((hs[i - 1] < hs[i] and hs[i] > hs[i + 1]) ||
            (hs[i - 1] > hs[i] and hs[i] < hs[i + 1]))
                cs.push_back(hs[i]);

    // Finaliza com um mínimo
    if (cs.size() % 2) 
        cs.push_back(0);

    // Geração dos eventos para o sweep line
    vector<ii> es;
    int OPEN = 1, CLOSE = -1, ans = 1, open = 0;

    for (size_t i = 0; i < cs.size(); i += 2)
    {
        es.push_back(ii(cs[i + 1], OPEN));
        es.push_back(ii(cs[i], CLOSE));
    }

    sort(es.begin(), es.end());

    for (auto e : es)
    {
        open += e.second;
        ans = max(ans, open);
    }

    return ans + 1;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> hs(N + 2, 0);

    for (int i = 1; i <= N; ++i)
        cin >> hs[i];

    cout << solve(N, hs) << '\n';

    return 0;
}
