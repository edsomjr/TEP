#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(int M, const vector<int>& ks)
{
    vector<vector<int>> hs(M);

    for (const auto& k : ks)
        hs[k % M].push_back(k);

    return hs;
}

int main()
{
    int N;
    cin >> N;

    for (int test = 0; test < N; ++test)
    {
        int M, C;
        cin >> M >> C;

        vector<int> ks(C);

        for (int i = 0; i < C; i++) 
            cin >> ks[i];

        auto hs = solve(M, ks);

        if (test)
            cout << '\n';

        for (int i = 0; i < M; i++)
        {
            cout << i << " -> ";

            for (auto x : hs[i])
                cout << x << " -> ";

            cout << "\\" << '\n';
        }
    }

    return 0;
}
