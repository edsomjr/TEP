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

int resn (int a, int b) {
	return (a*a)+b;
}

int resm (int a, int b) {
	return a+(b*b);
}

int main () {
	int n, m;
	cin >> n >> m;

	int ans = 0;

	fle (i, 0, 100)
		fle (j, 0, 100) {
			if (resm(i, j) == m && resn(i, j) == n) ans++;
		}

	cout << ans << endl;
	return 0;
}