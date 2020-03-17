#include <bits/stdc++.h>

using namespace std;

void process_subsets(int n, function<void(int)> process)
{
    // Cada inteiro s é um subconjunto: o i-ésimo bit de s
    // indica a presença ou ausência do elemento a_i
    for (int s = 0; s < (1 << n); ++s)
        process(s);
}

int main()
{
    int N;
    cin >> N;

    // Lista todos os subconjuntos de A = {1, 2, ..., N}
    process_subsets(N, [N](int s) {
        cout << "{ ";

        for (int i = 0; i < N; ++i)
            if (s & (1 << i))
                cout << (i + 1) << " ";

        cout << "}\n";
    });

    return 0;
}
