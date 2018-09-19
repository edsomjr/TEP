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
const ll MOD { 1000000007 }; // 10^9 + 7
const double PI = acos(-1.0); // 3.14

vector< pair <int, ii > > adj;
int facto[MAX] = {0};

int main () {
	int n, m, k;
	int a, b, l;
	ll ans = MOD;
	cin >> n >> m >> k;
	
	flt(i, 0, m) {
		cin >> a >> b >> l;
		adj.pb({a, {b, l}});
	}

	flt(i, 0, k) {
		cin >> a;
		facto[a] = 1;
	}

	flt(i, 0, m) {
		ll A = adj[i].pf;
		ll B = adj[i].ps.pf;
		ll dist = adj[i].ps.ps;

		if ((facto[A] && !facto[B]) || (!facto[A] && facto[B])) {
			ans = min(ans, dist);
		}
	}

	if (ans == MOD) cout << "-1\n";
	else cout << ans << endl; 

	return 0;
}