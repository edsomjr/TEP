#include <bits/stdc++.h>

using namespace std;

vector<int> coin_change(int M, const vector<int>& cs)
{
    int N = (int) cs.size();
    vector<int> xs(N);

    for (int i = N - 1; i >= 0; --i)
    {
        xs[i] = M / cs[i];
        M -= (xs[i] * cs[i]);
    }

    return xs;
}

int main()
{
    vector<int> cs { 1, 2, 5, 10, 25, 50 };
    int M;

    cin >> M;

    auto xs = coin_change(M, cs);

    for (size_t i = 0; i < cs.size(); ++i)
        cout << cs[i] << ": " << xs[i] << '\n';

    cout << accumulate(xs.begin(), xs.end(), 0) << " moedas\n";

    return 0;
}
