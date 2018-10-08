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
vi A;

#define I for(i=n-1;i>=0;i--)
#define J for(i=0;i<256;i++)
#define R for(r=0;r<4;r++)
#define F(p,q,k) I p[--c[k][q[i]>>8*k&255]]=q[i]

void sort(int n) {
  int i,r,x,c[4][257],B[1<<20];
  R J c[r][i]=0;
  I {
    x=A[i]^=A[i]>>31|1<<31;
    R c[r][x>>8*r&255]++;
  }
  J R c[r][i+1]+=c[r][i];

  F(B,A,0);
  F(A,B,1);
  F(B,A,2);
  F(A,B,3)^(~B[i]>>31|1<<31);
}

int main (int argc, char* argv[]) {
	int n, x;
	if (argc < 2) {
		n = 94585981;
	} else cin >> n;

	flt (i, 0, n) {
		cin >> x;
		A.pb(x);
	}

	chrono::steady_clock::time_point begin = chrono::steady_clock::now();

	sort(A.size());
	if (argc >= 2){
		for (auto & v : A) cout << v << " ";
		nl;
	}
	chrono::steady_clock::time_point end= chrono::steady_clock::now();
	cout << "microseconds = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() <<endl;

	return 0;
}