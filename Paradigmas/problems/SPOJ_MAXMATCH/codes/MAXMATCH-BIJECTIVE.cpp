#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define MSOne(S) (1ull << (63 - __builtin_clzll(S)))
#define fastio ios_base::sync_with_stdio(0); \
               cin.tie(0); \
               cout.tie(0)

// FFT - CP Algorithm
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd& x : a)
            x /= n;
    }
}

string abc = "abc", acb = "acb";
int main() {
    fastio;

    string s;
    cin >> s;
    string r(s);

    int N = s.size();
    ll size = MSOne((N + N) << 1);

    vector<cd> fs(size, 0), fr(size, 0);
    for (int j = 0; j < N; j++) {
        int sh = abc.find(s[j]);
        double sp = (2 * PI * sh) / 3;
        fs[j] = cd(cos(sp), sin(sp));

        int rh = acb.find(s[N - j - 1]);
        double rp = (2 * PI * rh) / 3;
        fr[j] = cd(cos(rp), sin(rp));
    }
    fft(fs, false);
    fft(fr, false);

    for (int i = 0; i < size; i++) fs[i] *= fr[i];
    fft(fs, true);

    int mx = 0;
    vector<int> ms;
    for (int i = N; i < N + N; i++) {
        double t = fs[i].real();
        int tot = 2 * N - i - 1;
        double p = (tot + 2 * t) / 3.00;
        int k = (int)round(p);
        mx = max(mx, k);
        ms.push_back(k);
    }

    cout << mx << "\n";
    for (int i = 0; i < ms.size(); i++) if (ms[i] == mx) cout << i + 1 << " ";
    cout << "\n";

    return 0;
}