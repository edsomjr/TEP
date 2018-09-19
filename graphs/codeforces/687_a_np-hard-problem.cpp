#include <bits/stdc++.h>
#define fle(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define flt(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define fgt(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
#define fge(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define log(var, sep) (cerr << #var << " = " << (var) << (sep))
#define pb push_back
#define nl (cout << endl)

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vp = vector< ii >;

const int MAX { 1000010 }; // 10^6 + 10
const ll oo { (1LL << 62) }; // 2^62
const ll MOD { 1000000007 }; // 10^9 + 7
const double PI = acos(-1.0); // 3.14

vi adj[MAX];
vi vc[3];
vp edges;

bool bipartite () {
	vi side(MAX, 0);
	queue<ll> q;
	side[0] = 1;
	q.push(0);
	while (!q.empty()) {
		auto node = q.front();
		vc[side[node]].pb(node);
		q.pop();
		for (auto &neighbour : adj[node]) {
			if (side[neighbour] == side[node]) return false;
			if (!side[neighbour]) {
				side[neighbour] = 3 - side[node];
				q.push(neighbour); 
			}
		}
	}
	return true; 
}

int main () {
	ll n, m, u, v;

	cin >> n >> m;

	flt (i, 0, m) {
		cin >> u >> v;
		edges.pb({u-1, v-1});
	}

	for (const auto& [u, v] : edges) {
		adj[u].pb(v);
		adj[v].pb(u);
	}

	if (bipartite()) {
		fle (i, 1, 2) {
			cout << vc[i].size() << endl;
			for(int v : vc[i])
				cout << v + 1 << " ";
			cout << endl;
		}
	} else {
		cout << -1 << endl;
	}
	return 0;
}