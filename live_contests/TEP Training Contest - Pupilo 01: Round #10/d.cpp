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
	string x;
	cin >> x;
	int init = 1, last_i = 0;
	while (init != x.npos) {
		init = x.find("WUB");
		if (init != x.npos) {
			x.erase(init, 3);
			if(x.substr(0, 3) != "WUB") {
				int flag = 0;
				for (; last_i < x.length();) {
					string wub = "";
					wub += x[last_i];
					wub += x[last_i+1];
					wub += x[last_i+2];

					if (wub != "WUB") {
						cout << x[last_i];
						last_i++;
						flag = 1;
					} else {
						break;
					}
				}
				if (flag && x.substr(last_i, last_i+3) != "WUB") cout << " ";
			}
		}
	}
	nl;
	//cout << x << endl;
	return 0;
}