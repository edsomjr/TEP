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
	vi x;
	x.pb(8);
	x.pb(0);
	flt(i, 0, 10) x.pb(i);
	x.pb(10);

	for (auto & v : x) cout << v << " ";
	nl;
	sort(x.begin(), x.end());
	auto it = unique(x.begin(), x.end());
	cout << x.size() << endl;
	cout << x.capacity() << endl;
	for (auto & v : x) cout << v << " ";

	nl;

	x.erase(it, x.end());
	cout << x.size() << endl;
	cout << x.capacity() << endl;
	for (auto & v : x) cout << v << " ";
	


	return 0;
}