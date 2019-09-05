#include <bits/stdc++.h>

using namespace std;

void
process_permutations(size_t n, function<void(const vector<int>&)> process)
{
    vector<int> ns(n);

    // ns = { 1, 2, 3, ..., n }
    iota(ns.begin(), ns.end(), 1);

    // Para gerar todas as permutações com next_permutation(), o
    // vector ns deve estar inicialmente ordenado
    do {
        process(ns);
    } while (next_permutation(ns.begin(), ns.end()));
}

int main()
{
    int N;
    cin >> N;

    process_permutations(N, [](const vector<int>& p) {
        cout << "( ";

        for (const auto x : p)
            cout << x << " ";

        cout << ")\n";
    });

    return 0;
}
