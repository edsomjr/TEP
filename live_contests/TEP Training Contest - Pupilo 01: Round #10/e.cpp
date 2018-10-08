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
	int k; cin >> k;

	string x; cin >> x;

	map<char, int> alph;

	int flag = 1;

	for (auto& v : x) alph[v]++;
	for (auto& v : alph) {
		if (v.second % k != 0) 
			flag = 0;
	}
	if (flag) {
		flt (i, 0, k)
			for (auto & v : alph) 
				flt (i, 0, v.second / k) {
					cout << v.first;
				}
		nl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}