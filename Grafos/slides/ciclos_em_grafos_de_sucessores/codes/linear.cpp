#include <bits/stdc++.h>

using namespace std;

pair<int, int> detect_cycle(int N, const vector<int>& succ)
{
    int u = 1;
    unordered_set<int> s;

    while (not s.count(u))
    {
        s.insert(u);
        u = succ[u];
    }

    auto mu = u;
    auto lambda = N - u + 1;

    return { mu, lambda };
}

int main()
{
    int N;
    cin >> N;

    vector<int> succ(N + 1);

    for (int u = 1; u <= N; ++u)
        cin >> succ[u];

    auto [mu, lambda] = detect_cycle(N, succ);

    cout << "mu = " << mu << '\n';
    cout << "lambda = " << lambda << '\n';

    return 0;
}
