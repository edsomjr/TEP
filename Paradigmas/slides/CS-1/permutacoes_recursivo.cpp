#include <bits/stdc++.h>

using namespace std;

void
process_permutations(size_t n, int chosen, vector<int>& P,
                function<void(const vector<int>&)> process)
{
    if (P.size() == n)
        process(P);
    else
    {
        for (size_t i = 1; i <= n; ++i)
        {
            if (chosen & (1 << i))
                continue;

            chosen |= (1 << i);
            P.push_back(i);
            process_permutations(n, chosen, P, process);
            chosen &= ~(1 << i);
            P.pop_back();
        }
    }
}

int main()
{
    int N;
    cin >> N;

    // Lista todas as permutações de A = {1, 2, ..., N}
    vector<int> P;

    process_permutations(N, 0, P, [](const vector<int>& p) {
        cout << "( ";

        for (const auto x : p)
            cout << x << " ";

        cout << ")\n";
    });

    return 0;
}
