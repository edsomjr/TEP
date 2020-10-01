// OBI 2017 - Nìvel Universitário: Fase 2
// Cortando o Papel (https://olimpiada.ic.unicamp.br/pratique/pu/2017/f2/papel/) 
// Referência: https://noic.com.br/materiais-informatica/comentario-old/obi-2017/9695-2/ 
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int pieces(double x, int N, const vector<int>& hs)
{
    auto L = 0, res = 0;

    while (L < N)
    {
        if (hs[L] <= x)
        {
            ++L;
            continue;
        }

        auto R = L + 1;

        while (R < N and hs[R] > x)
            ++R;

        ++res;
        L = R;
    }

    return res + 1;
}

int solve(int N, const vector<int>& hs)
{
    // Compressão dos adjacentes iguais e adição de bordas
    vector<int> xs(1, 0);
 
    for (auto h : hs)
        if (xs.back() != h)
            xs.push_back(h);

    xs.push_back(0);
    
    N = (int) xs.size();

    // Identificação dos valores e picos
    map<int, int> ys;
    const int PICO = -1, VALE = 1;
 
    for (int i = 1; i < N - 1; ++i)
    {
        if (xs[i - 1] < xs[i] and xs[i] > xs[i + 1])
            ys[xs[i]] += PICO;

        if (xs[i - 1] > xs[i] and xs[i] < xs[i + 1])
            ys[xs[i]] += VALE;
    }

    // Processamento dos picos e valores
    int ans = 2, pieces = 2;

    for (auto y : ys)
    {
        auto delta = y.second;

        pieces += delta;
        ans = max(ans, pieces);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> hs(N);

    for (int i = 0; i < N; ++i)
        cin >> hs[i];

    auto ans = solve(N, hs);

    cout << ans << '\n';

    return 0;
}
