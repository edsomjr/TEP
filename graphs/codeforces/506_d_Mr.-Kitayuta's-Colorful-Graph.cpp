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

bitset<MAX> visited;
vp adj[MAX];

pair<int, pair < int, bool > > par_uf[MAX], rank_uf[MAX];
 
void init (int n, int c) {
	flt (i, 0, n) {
		par_uf[i] = {i, c, false};
		rank_uf[i] = {0, c, false};
	}
}

int find (int x, int c) {
	if (par_uf[x].pf == x) 
		return x;
	else {
		par_uf[x].ps.pf = c;
		return par_uf[x].pf = find(par_uf[x].pf, c);
	}
}

int find (int x) {
	if (par_uf[x].pf == x) return x;
	else return par_uf[x].pf = find(par_uf[x].pf);
}

void unite (int x, int y, int c){
	x = find (x, c); 
	y = find (y, c);
	if (x == y) return;
	if (rank_uf[x].pf < rank_uf[y].pf) 
		par_uf[x].pf = y;
	else {
		par_uf[y].pf = x;
		if (rank_uf[x].pf == rank_uf[y].pf) 
			rank_uf[x].pf++;
	}
}

int main () {
	int n, m, q, c;
	int a[MAX], b[MAX];
	
	cin >> n >> m;
	
	map<int, set<int>> colors;

	flt (i, 0, m) {
		cin >> a >> b >> c;
		adj[c].pb({a, b});
	}

	cin >> q;

	flt (i, 0, q) {
		cin >> a[i] >> b[i];
		if (b[i] > a[i]) swap (a[i], b[i]);
	}

	for (auto & [c, v] : adj) {
		init (c);
		for (auto & k : v) {
			int x = v.first, y = v.second;
			unite (x, y, c);
		}
	}
	
	flt (i, 0, q) {
		ans = 0;
		if (find(a[i]) == find(b[i])) ans++;
	}		
	

	return 0;
}