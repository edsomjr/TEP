#include <bits/stdc++.h>

using namespace std;

const int oo { 2'000'000'007 };

vector<int> greedy(int x, int N, const vector<int>& xs)
{
    vector<int> res(N, 0);

    for (int i = 0; i < N; ++i)
    {
        auto q = x / xs[i];
        x -=  q*xs[i];

        res[i] = q;
    }

    return res;
}

int value(const vector<int>& M, int N, const vector<int>& xs)
{
    int res = 0;

    for (int i = 0; i < N; ++i)
        res += M[i]*xs[i];

    return res;
}

int min_counterexample(int N, const vector<int>& xs)
{
    if (N <= 2)
        return -1;

    int ans = oo;

    for (int i = N - 2; i >= 0; --i) {
        auto g = greedy(xs[i] - 1, N, xs);
        vector<int> M(N, 0);

        for (int j = 0; j < N; ++j)
        {
            M[j] = g[j] + 1;
            auto w = value(M, N, xs);
            auto G = greedy(w, N, xs);

            auto x = accumulate(M.begin(), M.end(), 0);
            auto y = accumulate(G.begin(), G.end(), 0);

            if (x < y)
                ans = min(ans, w);

            M[j]--;
        }
    }
   
    return ans == oo ? -1 : ans;
}

int main()
{
    int N;
    cin >> N;

    vector<int> cs(N);

    for (int i = 0; i < N; ++i)
        cin >> cs[i];

    cout << min_counterexample(N, cs) << '\n';

    return 0;
}
