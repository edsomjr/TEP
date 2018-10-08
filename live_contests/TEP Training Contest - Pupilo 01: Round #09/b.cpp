#include <bits/stdc++.h>
#define fle(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define flt(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define fgt(i, a, b) for (int (i) = (a); (i) > (b); (i)--)
#define fge(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define log(var, sep) (cerr << #var << " = " << (var) << (sep))
#define pb push_back
#define nl (cout << endl)
#define pf first
#define ps second

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vp = vector< ii >;

const int MAX { 1000010 }; // 10^6 + 10
const ll oo { (1ll << 62) }; // 2^62
const ll MOD { 1000000007 }; // 10^9 + 7
const double PI = acos(-1.0); // 3.14

vi z_function(const string &s) {
    ll n = s.size();
    vi z(n, 0);
    ll L = 0, R = 0;
    for(ll i = 1; i < n; i++) {
        if(i <= R) {
            z[i] = min(z[i - L], R - i + 1);
        }
        while(z[i] + i < n && s[z[i] + i] == s[z[i]]) {
            z[i]++;
        }
        if(R < i + z[i] - 1) {
            L = i, R = i + z[i] - 1;
        }
    }
    return z;
}

int main () {
	string n;
	cin >> n;

	vi x = z_function("1#"+n);
	vi y = z_function("14#"+n);
	vi z = z_function("144#"+n);

	int ans = 0;

	for (auto& v : x)
		if (v == 1) ans++;
	for (auto& v : y)
		if (v == 2) ans++;
	for (auto& v : z)
		if (v == 3) ans++;

	string resp = ans == n.length() ? "YES\n" : "NO\n";
	cout << resp;
	return 0;
}