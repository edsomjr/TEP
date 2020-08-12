#include <bits/stdc++.h>

using namespace std;

// Retorna o mínimo de moedas, sem discriminar os valores ki
int coin_change(int Q, const vector<int>& cs)
{
    int ans = 0;

    // Processa as moedas da maior para a menor
    for (auto it = cs.rbegin(); it != cs.rend(); ++it)
    {
        int c = *it, k = Q / c;

        ans += k;
        Q -= k*c;
    }

    return ans;
}

int main()
{
    vector<int> cs { 1, 2, 5, 10, 25, 50 };

    int Q;
    cin >> Q;

    cout << coin_change(Q, cs) << '\n';

    return 0;
}
