#include <bits/stdc++.h>

using namespace std;

bool solve(int N, const vector<int>& fs)
{
    for (int A = 1; A <= N; ++A)
    {
        auto B = fs[A];
        auto C = fs[B];

        if (fs[C] == A)
            return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> fs(N + 1);

    for (int i = 1; i <= N; ++i)
        cin >> fs[i];

    auto ans = solve(N, fs);

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
