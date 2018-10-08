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
	ll n, m, x, ans = 0, idm = 0;
	cin >> n >> m;
	vp xd;

	fle (i, 1, n) {
		cin >> x;
		xd.pb(make_pair(x, i));
	}

	sort(xd.begin(), xd.end());
	
	ll dif = oo;
	fle (i, 1, n) {
		ll mid = xd.size()/2;
		if (xd[i-1].pf == m && abs(mid-i) < dif) {
			dif = abs(mid-i);
			idm = i;
		}
	}

	ll dist = idm - ((xd.size()/2) + 1);

	if (xd[xd.size()/2].pf != xd[idm-1].pf) {
		if (dist < 0) {
			dist = abs(dist) * 2;
			if (dist > 2) dist--;
			cout << dist << endl;
			flt (i, n-dist, n) 
				cout << xd[i].ps << ((i+1) == (n) ? '\n' : ' ');
		} else {
			if (dist > 0) {
				dist = ((dist+1)*2)-2;
			}
			if (dist == n-1) {
				dist--;
			}
			cout << dist << endl;
			flt (i, 0, dist) 
				cout << xd[i].ps << ((i+1) == (dist) ? '\n' : ' ');
		}
	} else {
		cout << 0 << endl;
	}

	return 0;
}

// 
// 1 1 2 [2] 3 6
