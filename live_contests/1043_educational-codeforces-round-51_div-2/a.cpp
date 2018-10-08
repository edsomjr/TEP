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
	int t;
	cin >> t;
	while (t--) {
		bool hl = false, ll = false, d = false;
		string s;
		cin >> s;
		int last_lower = -1001, last_higher = -1001, last_digit = -1001;
		ii ans = {100, 100}; // dist subst, idx changed

		for (int i = 0; s[i]; ++i) {
			if (s[i] >= 65 && s[i] <= 90) {
				hl = true;
				if (i - last_lower < ans.pf) {
					ans = {i - last_lower, last_lower};
				}
				last_lower = i;
			}
			if (s[i] >= 97 && s[i] <= 122) {
				ll = true;
				if (i - last_higher < ans.pf) {
					ans = {i - last_higher, last_higher};
				}
				last_higher = i;			
			}
			if (s[i] >= 48 && s[i] <= 57) {
				d = true;
				if (i - last_digit < ans.pf) {
					ans = {i - last_digit, last_digit};
				}
				last_digit = i;			
			}
			if (hl && ll && d) break;
		}

		if (hl && ll && d) {
			cout << s << endl;
			continue;
		} else if ((hl && ll) || (hl && d) || (ll && d)) {
			if (hl && ll) s[ans.ps] = '1';
			if (hl && d) s[ans.ps] = 'a';
			if (ll && d) s[ans.ps] = 'A';
		} else {
			if (hl) {
				s[0] = 'a';
				s[1] = '1';
			}
			if (ll) {
				s[0] = 'A';
				s[1] = '1';
			}
			if (d) {
				s[0] = 'a';
				s[1] = 'A';
			}
		}

		cout << s << endl;
	}
	return 0;
}