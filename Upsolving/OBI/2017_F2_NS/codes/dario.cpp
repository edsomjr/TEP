#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, D, X, dario = 0;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> D >> X;

        if (X == (D + 1) % 5 or X == (D + 2) % 5)
            ++dario;
    }

    cout << (dario > N / 2 ? "dario" : "xerxes") << '\n';

    return 0;
}
