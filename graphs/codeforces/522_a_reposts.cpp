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

map<string, bool> visited;
map<string, vector<string>> adj;
map<string, int> dist;

void bfs (string s) {
	queue<string> q;
	visited.clear();
	q.push(s);
	visited[s] = true;
	dist[s] = 0;

	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (const auto& v : adj[u]) {
			if (visited[v]) continue;
			visited[v] = true;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
}

int main () {
	int n; 
	cin >> n;
	string first, discard, second;

	while (n--) {
		//tourist reposted Polycarp
		cin >> first >> discard >> second;
		transform(first.begin(), first.end(), first.begin(), ::tolower);
		transform(second.begin(), second.end(), second.begin(), ::tolower);
		adj[second].pb(first);
	}

	bfs("polycarp");
	int max = 0;

	for (auto & [v, u] : dist) {
		if (u > max) max = u;
	}

	cout << max + 1 << endl;

	return 0;
}