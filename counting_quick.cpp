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
int freq[MAX];
vi arr, A;

int main (int argc, char* argv[]) {
	int n, x, last = 0, first = 1;
	if (argc < 2) {
		n = 94585981;
	} else cin >> n;

	int *result = new int[n];

	flt (i, 0, n) {
		cin >> x;
		arr.pb(x);
		if (!visited[x])
			A.pb(x);
		visited[x] = true;
		freq[x]++;
	}

	chrono::steady_clock::time_point begin = chrono::steady_clock::now();

	sort(A.begin(), A.end());

	for (auto & v : A) {
		if (!first) {
			freq[v] += last;
		} else first = 0;
		last = freq[v];
	}

	for (auto & v : arr) {
		result[freq[v]-1] = v;
		freq[v]--;
	}

	if (argc >= 2){
		flt (i, 0, n) cout << result[i] << " ";
		nl;
	}

	chrono::steady_clock::time_point end= chrono::steady_clock::now();
	cout << "microseconds = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() <<endl;

	return 0;
}