#include <bits/stdc++.h>
#define fle(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define flt(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define fgt(i, a, b) for (int (i) = (a); (i) > (b); (i)--)
#define fge(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define log(var, sep) (cerr << #var << " = " << (var) << (sep))
#define pb push_back
#define nl (cout << endl)

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vp = vector< ii >;

const int MAX { 1000010 }; // 10^6 + 10
const ll oo { (1ll << 62) }; // 2^62
const ll MOD { 1000000007 }; // 10^9 + 7
const double PI = acos(-1.0); // 3.14

int n, ans;
bitset<MAX> visited;
vi x[MAX], y[MAX];

void dfs (int u) {
	visited[u] = true;
	flt (i, 0, n)
		if ((x[i] == x[u] || y[i] == y[u]) && !visited[i]) 
			dfs(i);
}

int main () {
	int xis, yon;
	cin >> n;

	flt (i, 0, n) {
		cin >> xis >> yon;
		x[i].pb(xis);
		y[i].pb(yon);
	}

	flt (i, 0, n) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}

	printf("%d\n", ans-1);

	return 0;
}
