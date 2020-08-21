#include <bits/stdc++.h>

using namespace std;

const double PI { acos(-1.0) };

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

void fft(vector<complex<double>>& xs, bool invert = false)
{
    int N = (int) xs.size();

    if (N == 1)
        return;

    int bits = 1;

    while ((1 << bits) != N)
        ++bits;

    for (int i = 0; i < N; ++i)
    {
        auto j = reversed(i, bits);

        if (i < j)
            swap(xs[i], xs[j]);
    }

    for (int size = 2; size <= N; size *= 2)
    {
        auto signal = (invert ? 1 : -1);
        auto theta = 2 * signal * PI / size;
        complex<double> S1 { cos(theta), sin(theta) };

        for (int i = 0; i < N; i += size)
        {
            complex<double> S { 1 }, k { invert ? 2.0 : 1.0 };

            for (int j = 0; j < size / 2; ++j)
            {
                auto a { xs[i + j] }, b { xs[i + j + size/2] * S };

                xs[i + j] = (a + b) / k;
                xs[i + j + size/2] = (a - b) / k;
                S *= S1;
            }
        }
    }
}

int main()
{
    vector<complex<double>> xs { 2.5, -1.6, 4.5, 0.3, 9.0, 7.7, 1.1, -8.8 };

    cout << "Original = " << endl;
    for (auto x : xs)
        cout << x << endl;
 
    fft(xs);

    cout << "FFT = " << endl;
    for (auto x : xs)
        cout << x << endl;

    fft(xs, true);

    cout << "Signal = " << endl;
    for (auto x : xs)
        cout << x << endl;

    return 0;
}
