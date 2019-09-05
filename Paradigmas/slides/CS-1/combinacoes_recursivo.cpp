#include <bits/stdc++.h>

using namespace std;

void
process_combinations(size_t n, size_t m, int chosen, vector<int>& P,
                function<void(const vector<int>&)> process)
{
    if (P.size() == m)
        process(P);
    else
    {
        for (size_t i = P.empty() ? 1 : P.back() + 1; i <= n; ++i)
        {
            if (chosen & (1 << i))
                continue;

            chosen |= (1 << i);
            P.push_back(i);
            process_combinations(n, m, chosen, P, process);
            chosen &= ~(1 << i);
            P.pop_back();
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    // Lista todas as permutações de A = {1, 2, ..., N}
    vector<int> P;

    process_combinations(N, M, 0, P, [](const vector<int>& p) {
        cout << "[ ";

        for (const auto x : p)
            cout << x << " ";

        cout << "]\n";
    });

    return 0;
}
