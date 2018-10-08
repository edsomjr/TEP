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

int main () {
	int n, m, q;
	while (~scanf("%d %d %d", &n, &m, &q)) {
		vector<char> rows;
		char x;
		int startx, starty, ori;
		pair<string, int> oris[] = {{"N", 0}, {"L", 0}, {"S", 0}, {"O", 0}};
		flt(i, 0, n)
			flt(j, 0, m) {
				cin >> x;
				rows[i].pb(x);
				if (x >= 76 && x <= 83) {
					startx = i;
					starty = j;
					if (x == 'N') {
						oris[0].ps = 1;
						ori = 0;
					}
					if (x == 'L') {
						oris[1].ps = 1;
						ori = 1;
					}
					if (x == 'S') {
						oris[2].ps = 1;
						ori = 2;
					}
					if (x == 'O') {
						oris[3].ps = 1;
						ori = 3;
					}
				}
			}

		flt(i, 0, q) {
			cin >> x;
			if (x == 'D') {
				ori = ori+1 % 4;
			}
			if (x == 'E') {
				ori = ori ? ori-1 : 3;
			}
			if (x == 'F') {
				rows[startx][starty] = '.';
				
			}
		}


	}


	return 0;
}