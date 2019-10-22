#include <bits/stdc++.h>

using namespace std;

void process_combinations(int n, int m,
                          function<void(const vector<int>&)> process)
{
    // ns = { 1, 1, ..., 1, 0, 0, ..., 0 }, m 1s, (n - m) zeros
    vector<int> ns(m, 1);
    ns.resize(n);

    // As combinações são geradas em ordem lexicográfica
    do {
        process(ns);
    } while (prev_permutation(ns.begin(), ns.end()));
}

int main()
{
    int N, M;
    cin >> N >> M;

    process_combinations(N, M, [N](const vector<int>& p) {
        cout << "( ";

        for (int i = 0; i < N; ++i)
            if (p[i])
                cout << i + 1 << " ";

        cout << ")\n";
    });

    return 0;
}
