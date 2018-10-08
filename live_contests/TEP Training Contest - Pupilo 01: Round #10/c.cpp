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

int main () {
	int n, x, ans = 0, tot = 0;
	vi haha;

	cin >> n;
	
	flt (i, 0, 12) {
		cin >> x;
		haha.pb(x);
	}

	sort(haha.rbegin(), haha.rend());

	for (int i = 0; ans < n && i < 12; ++i, ++tot) {
		ans += haha[i];
	}

	if (!n) cout << 0 << endl;
	else if (ans < n) cout << -1 << endl;
	else cout << tot << endl;

	return 0;
}