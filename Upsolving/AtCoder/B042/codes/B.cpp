#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;

    vector<string> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    sort(xs.begin(), xs.end());

    for (int i = 0; i < N; ++i)
        cout << xs[i] << (i + 1 == N ? "\n" : "");

    return 0;
}
