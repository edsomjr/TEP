#include <bits/stdc++.h>
#include <complex>

using namespace std;

const double PI { acos(-1.0) };

template<typename T>
vector<complex<T>> dft(const vector<T>& xs)
{
    int N = (int) xs.size();
    vector<complex<T>> F(N, 0);

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            F[k] += xs[i]*exp(complex<T>(0, -2*PI*i*k/N));

    return F;
}

template<typename T>
vector<T> idft(const vector<complex<T>>& Fs)
{
    int N = (int) Fs.size();
    vector<T> f(N, 0);

    for (int x = 0; x < N; ++x)
        for (int k = 0; k < N; ++k)
            f[x] += (1.0/N)*(Fs[k]*exp(complex<T>(0, 2*PI*x*k/N))).real();

    return f;
}

int main()
{
    const vector<double> xs { 2.5, -1.6, 4.5, 0.3, 9.0, 7.7 };

    auto F = dft(xs);

    for (auto c : F)
        cout << c << endl;

    auto f = idft(F);

    for (auto x : f)
        cout << x << endl;

    return 0;
}
