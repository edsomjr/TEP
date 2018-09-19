#include <bits/stdc++.h>
#define fle(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define flt(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define fgt(i, a, b) for (int (i) = (a); (i) > (b); (i)--)
#define fge(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define log(var, sep) (cout << #var << " = " << (var) << (sep))
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
int dist[MAX];

void bfs (int s) {
	queue<int> q;
	visited.reset();
	q.push(s);
	visited[s] = true;
	dist[s] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (const auto& v : adj[u]) {
			if (visited[v]) continue;
			visited[v] = true;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
}

int n, m;

void build (int x) {
	if (visited[x]) return;
	visited[x] = true;

	int blue = x-1;
	int red = x*2;

	if (blue > 0) {
		adj[x].pb(blue);
		build(blue);
	}
	if (red < 2*m) {
		adj[x].pb(red);
		build(red);
	}
}

int main () {
	cin >> n >> m;

	build(n);
	bfs(n);
	cout << dist[m] << endl;

	return 0;
}