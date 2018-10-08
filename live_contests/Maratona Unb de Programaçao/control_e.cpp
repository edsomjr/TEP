#include <bits/stdc++.h>
#define fle(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define flt(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define fgt(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
#define fge(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
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
	ll n, m, x, ans = 0;
	cin >> n >> m;
	vp xd;

	fle (i, 1, n) {
		cin >> x;
		xd.pb(make_pair(x, i));
	}

	sort(xd.begin(), xd.end());

	vi ids;

	while (xd[xd.size()/2].pf != m) {
		ids.pb(xd[xd.size()/2].ps);	
		xd.erase(xd.begin() + xd.size()/2);
		ans++;
	}	

	cout << ans << endl;

	for (auto & v : ids) cout << v << (v == ids.back() ? '\n' : ' ');
	return 0;
}