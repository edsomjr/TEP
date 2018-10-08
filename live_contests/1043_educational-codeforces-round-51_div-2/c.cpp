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
	vi uniques;
	vi ord;
	int n, x;
	cin >> n;
	flt (i, 0, n) {
		cin >> x;
		ord.pb(x);
		uniques.pb(x);
	}

	vector<int>::iterator it;
	it = unique (uniques.begin(), uniques.end());
	uniques.resize(distance(uniques.begin(), it));


	if (uniques.size() % 2) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		int half = uniques.size() / 2, f = 0;
		string out = "AB";

		for (auto & v: ord) {
			if (!uniques.count(v)) {
				cout << 'A';
				
			} else {
				f = 1 - f;
				cout << out[f];
			}
		}

		nl;
	}

	return 0;
}