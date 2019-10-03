#include <bits/stdc++.h>

using namespace std;

int solve(int N, int K, const string& c)
{
    int ans = 0, L = 0, len = 0;

    // Pinta de forma gulosa, em sequências de tamanho no máximo k
    while (L < N)
    {
        // Pinta na posição L
        ++ans;

        // No intervalo [L, R) todos tem mesma cor
        // Este intervalo deve ter no máximo K elementos
        int R = L + 1;

        while (R < N and R - L < K and c[R] == c[L])
            ++R;

        len = max(len, R - L);
        L = R;
    }

    // Deve existir ao menos uma sequência de tamanho K
    // (a última pincelada cria uma sequência de tamanho K)
    if (len < K)
        return -1;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int N, K;
        cin >> N >> K;

        string c;
        cin >> c;

        cout << solve(N, K, c) << '\n';
    }

    return 0;
}
