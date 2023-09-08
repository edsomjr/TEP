#include <bits/stdc++.h>

using namespace std;

pair<int, int> floyd(const vector<int>& succ)
{
    // Etapa 1: H é a lebre, T a tartaruga
    int L = 1, H = 1;

    do 
    {
        L = succ[L];
        H = succ[succ[H]];
    } while (L != H);

    L = 1;

    while (L != H)
    {
        L = succ[L];
        H = succ[H];
    }

    auto mu = L;
    auto lambda = 0;

    do {
        H = succ[H];
        ++lambda;
    } while (L != H);
    
    return { mu, lambda };
}

int main()
{
    int N;
    cin >> N;

    vector<int> succ(N + 1);

    for (int u = 1; u <= N; ++u)
        cin >> succ[u];

    auto [mu, lambda] = floyd(succ);

    cout << "mu = " << mu << '\n';
    cout << "lambda = " << lambda << '\n';

    return 0;
}
