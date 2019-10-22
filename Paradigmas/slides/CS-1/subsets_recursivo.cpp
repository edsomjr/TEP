#include <bits/stdc++.h>

using namespace std;

void
process_subsets(int k, int n, vector<int>& S,
                function<void(const vector<int>&)> process)
{
    if (k == n)
        process(S);
    else
    {
        process_subsets(k + 1, n, S, process);
        S.push_back(k + 1);
        process_subsets(k + 1, n, S, process);
        S.pop_back();
    }
}

int main()
{
    int N;
    cin >> N;

    // Lista todos os subconjuntos de A = {1, 2, ..., N}
    vector<int> S;

    process_subsets(0, N, S, [](const vector<int>& s) {
        cout << "{ ";

        for (const auto x : s)
            cout << x << " ";

        cout << "}\n";
    });

    return 0;
}
