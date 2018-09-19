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

vp adj[MAX];
set< ii > q;
ll p[MAX];

int main () {
	int n, m, a, b, c;
	cin >> n >> m;

	ll dist[n+2]; 
	fle (i, 0, n) dist[i] = oo;

	flt (i, 0, m) {
		cin >> a >> b >> c;
		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}

	dist[1] = 0;
	q.insert({0, 1}); // primeiro peso, dps label

	while (not q.empty()) {
		int now = q.begin()->second;
		q.erase(q.begin());

		for (auto& v : adj[now]) {
			ll next = v.first, length = v.second;
			if (dist[next] > dist[now] + length) {
				q.erase({dist[next], next});
				dist[next] = dist[now] + length;
				p[next] = now;
				q.insert({dist[next], next});
			}
		}
	}
	if (dist[n] == oo) printf ("-1\n");
	else {
		vi ans;
		for (; n != 1; n = p[n]) 
			ans.pb(n);
		ans.pb(1);

		fge (i, ans.size() - 1, 0)
			printf("%lld%s", ans[i], i ? " " : "\n");
	}

	return 0;
}