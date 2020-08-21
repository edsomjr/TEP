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

vector<double>
operator*(const vector<double>& fx, const vector<double>& gx)
{
    auto n = fx.size() - 1, m = gx.size() - 1;
    vector<double> xs(n + m + 1), ys(n + m + 1);

    copy(fx.begin(), fx.end(), xs.begin());
    copy(gx.begin(), gx.end(), ys.begin());

    auto Fk = dft(xs), Gk = dft(ys), Hk(Fk);

    for (size_t i = 0; i < Hk.size(); ++i)
        Hk[i] *= Gk[i];

    return idft(Hk);
}

int main()
{
    vector<double> fx { 6, -5, 1 }, gx { -1, 3, -2, 1 };
    auto hx = fx * gx;

    for (size_t i = 0; i < hx.size(); ++i)
        cout << hx[i] << (i + 1 == hx.size() ? '\n': ' ');

    return 0;
}
