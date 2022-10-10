#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> combinations_with_repetition(int N, int M)
{
    vector<vector<int>> cs;
    vector<int> xs(M, 1);
    int pos = M - 1;

    while (true)
    {
        cs.push_back(xs);

        xs[pos]++;

        while (pos > 0 and xs[pos] > N) {
            --pos;
            xs[pos]++;
        }

        if (pos == 0 and xs[pos] > N)
            break; 

        for (int i = pos + 1; i < M; ++i)
            xs[i] = xs[pos];

        pos = M - 1;
    } 

    return cs;
}

int main() {
    int N = 5, M = 3;
    auto cs = combinations_with_repetition(N, M);

    for (auto xs : cs)
        for (int i = 0; i < M; ++i)
            cout << xs[i] << (i + 1 == M ? '\n' : ' ');
}
