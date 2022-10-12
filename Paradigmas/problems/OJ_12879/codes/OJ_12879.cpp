#include <bits/stdc++.h>

using namespace std;

const double PI { acos(-1.0) }, EPS { 1e-6 };

void fft(vector<complex<double>>& xs, bool invert = false)
{
    int N = (int) xs.size();

    if (N == 1)
        return;

    vector<complex<double>> es(N/2), os(N/2);

    for (int i = 0; i < N/2; ++i)
        es[i] = xs[2*i];

    for (int i = 0; i < N/2; ++i)
        os[i] = xs[2*i + 1];

    fft(es, invert);
    fft(os, invert);

    auto signal = (invert ? 1 : -1);
    auto theta = 2 * signal * PI / N;
    complex<double> S { 1 }, S1 { cos(theta), sin(theta) };

    for (int i = 0; i < N/2; ++i)
    {
        xs[i] = (es[i] + S * os[i]);
        xs[i] /= (invert ? 2 : 1);

        xs[i + N/2] = (es[i] - S * os[i]);
        xs[i + N/2] /= (invert ? 2 : 1);

        S *= S1;
    }
}

int solve(const vector<int>& ks, const vector<int>& ds)
{
    auto K = *max_element(ks.begin(), ks.end());
    int size = 1;

    while (size < K + 1)
        size *= 2;

    size *= 2;

    vector<complex<double>> xs(size, 0);

    for (auto k : ks)
        xs[k] = 1;
 
    xs[0] = 1;
    fft(xs);

    for (int i = 0; i < size; ++i)
        xs[i] *= xs[i];

    fft(xs, true);

    int ans = 0;

    for (auto d : ds)
        ans += (d < size and fabs(xs[d].real()) > EPS ? 1 : 0);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N)
    {
        vector<int> ks(N);
    
        for (int i = 0; i < N; ++i)
            cin >> ks[i];
     
        int M;
        cin >> M;

        vector<int> ds(M);

        for (int i = 0; i < M; ++i)
            cin >> ds[i];

        auto ans = solve(ks, ds);

        cout << ans << '\n';
    }

    return 0;
}
