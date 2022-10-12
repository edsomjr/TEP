#include <bits/stdc++.h>

using namespace std;

int reversed(int x, int bits)
{
    int res = 0;

    for (int i = 0; i < bits; ++i)
    {
        res <<= 1;
        res |= (x & 1);
        x >>= 1;
    }

    return res;
}

template<typename T> vector<T> sortByBits(const vector<T>& xs) {
    int N = (int) xs.size(), bits = 1;

    while ((1 << bits) != N)
        ++bits;

    vector<int> is(N);
    iota(is.begin(), is.end(), 0);

    sort(is.begin(), is.end(), [&bits](int x, int y) {
        return reversed(x, bits) < reversed(y, bits);
    });

    vector<T> ans(N);

    for (int i = 0; i < N; ++i)
        ans[i] = xs[is[i]];

    return ans;
} 

int main()
{
    int N;
    cin >> N;

    vector<int> xs(N);
    iota(xs.begin(), xs.end(), 0);

    auto ys = sortByBits(xs);

    for (int i = 0; i < N; ++i)
        cout << ys[i] << (i + 1 == N ? '\n' : ' ');

    return 0;
}
