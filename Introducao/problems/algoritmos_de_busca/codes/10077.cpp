#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

bool operator<(const ii& m, const ii& n)
{
    return m.first * n.second < m.second * n.first;
}

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

string stern_brocot(const ii& n)
{
    ii m(1, 1), L(0, 1), R(1, 0);

    ostringstream os;

    while (m != n)
    {
        if (n < m)
        {
            os << "L";
            R = m;
        } else
        {
            os << "R";
            L = m;
        }

        m = ii(L.first + R.first, L.second + R.second);

        ll d = gcd(m.first, m.second);
        m.first /= d;
        m.second /= d;
    }

    return os.str();
}

int main()
{
    int p, q;

    while (cin >> p >> q)
    {
        if (p == 1 and q == 1)
            break;

        auto ans = stern_brocot(ii(p, q));

        cout << ans << '\n';
    }

    return 0;
}
