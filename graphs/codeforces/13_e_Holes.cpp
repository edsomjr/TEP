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
int last_visited, dist[MAX], adj[MAX], n, m, x, a, b;

void bfs (int s) {
	queue<int> q;
	visited.reset();
	q.push(s);
	visited[s] = true;
	dist[s] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		int v = adj[u];
		if (v >= n || !v) break;
		if (visited[v]) continue;
		last_visited = v;
		visited[v] = true;
		dist[v] = dist[u] + 1;
		q.push(v);
	}
}

int main () {
	cin >> n >> m;

	fle (i, 1, n) {
		cin >> x;
		adj[i] = x+i;
	}

	flt (i, 0, m) {
		cin >> x;
		if (!x) {
			cin >> a >> b;
			adj[a] = b;
		} else {
			cin >> a;
			bfs(a);
			cout << last_visited << " " << dist[last_visited] << '\n';
		}
	}

	return 0;
}
