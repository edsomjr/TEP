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

bitset<MAX> visited;
vi adj[MAX];
vp edges;

void dfs (int u, bool first) {
	if (first) visited.reset();
	if (visited[u]) return;
	visited[u] = true;
	for (const auto& v : adj[u]) dfs(v, false);
}

int main () {
	int n, m, x;
	cin >> n >> m;

	flt (i, 1, n) {
		cin >> x;
		adj[i].pb(x+i);
	}

	dfs(1, true);

	printf("%s\n", visited[m] ? "YES" : "NO");

	return 0;
}