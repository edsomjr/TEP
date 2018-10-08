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
	int n;
	cin >> n;
	string x[(n*2)+1];
	string z[(n*2)+1];
	fle (j, 0, n) {
		fle (i, 0, j) {z[j]+=(i+'0'); if(i != j) z[j]+=' ';}
		fge (i, j-1, 0) {z[j]+=' '; z[j]+=(i+'0');}
	}

	string spaces(2*n, ' ');
	fle (i, 1, n+1) {
		x[i] = spaces.substr(0, 2*(1+n-i)) + z[i-1];
		cout << x[i] << endl;
	}

	fgt (i, n, 0) {
		cout << x[i] << endl;
	}
	return 0;
}