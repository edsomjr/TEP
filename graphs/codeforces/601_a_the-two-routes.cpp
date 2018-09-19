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
bool bus_visited, train_visited; 
vi bus[MAX], train[MAX], bus_visit_order, train_visit_order;
vp edges;
int n, m;
int dist[MAX];

int bfs_bus (int s) {
	queue<int> q;
	visited.reset();
	q.push(s);
	visited[s] = true;
	dist[s] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		bus_visit_order.pb(u);

		for (const auto& v : bus[u]) {
			if (visited[v]) continue;
			visited[v] = true;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}

	bus_visited = visited[n];

	return dist[n];		
}

int bfs_train (int s) {
	queue<int> q;
	visited.reset();
	q.push(s);
	visited[s] = true;
	dist[s] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		train_visit_order.pb(u);

		for (const auto& v : train[u]) {
			if (visited[v]) continue;
			visited[v] = true;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}

	train_visited = visited[n];

	return dist[n];		
}


int main () {
	scanf("%d %d", &n, &m);

	set< ii > q;
	
	flt (i, 0, m) {
		int a, b;
		cin >> a >> b;

		train[a].pb(b);
		train[b].pb(a);

		q.insert({a, b});
		q.insert({b, a});
	}
	
	fle (i, 1, n) {
		fle (j, 1, n) {
			if (i != j && !q.count({i, j}) && !q.count({j, i})) {
				bus[i].pb(j);
				bus[j].pb(i);
			}
		}
	}

	int bus_time = bfs_bus(1); //bus
	int train_time = bfs_train(1); //train

	if (bus_visited && train_visited) {
		int flag = 0;
		fle (i, 1, n) {
			if (bus_visit_order[i] == train_visit_order[i]) {
				++flag;
				break;
			}
		}

		cout << max(min(bus_time, train_time)+flag, max(bus_time, train_time)) << endl; 
	} else {
		cout << "-1\n";
	}

	return 0;
}