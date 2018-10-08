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
using vp = vector< pair<int, int> >;

const int MAX { 1000010 }; // 10^6 + 10
const ll oo { (1ll << 62) }; // 2^62
const ll MOD { 1000000007 }; // 10^9 + 7
const double PI = acos(-1.0); // 3.14

vp adj[MAX];

int getSum(int BITree[], int index)
{
    int sum = 0; // Iniialize result
 
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse ancestors of BITree[index]
    while (index > 0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
    // Add 'val' to current node of BI Tree
    BITree[index] += val;
 
    // Update index to that of parent in update View
    index += index & (-index);
    }
}
 
// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(vi arr, int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
 
    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
 
    // Uncomment below lines to see contents of BITree[]
    // for (int i=1; i<=n; i++)
    // 	cout << BITree[i] << " ";
 
    return BITree;
}

int main () {
	int n, m, x;
	string numbers;
	cin >> n >> numbers;

	m = n;
	vi freq;

	flt (i, 0, m) {
		if (numbers[i] - '0')
			freq.pb(numbers[i] - '0');
		else
			n--;
	}

	int *BITree = constructBITree(freq, n);
	int flag = 0;

	if (n) {
		fle (i, 1, n) {
			fle(j, i, n) {
				adj[getSum(BITree, j-1) - (getSum(BITree, i-2))].pb({i, j});
			}
		}


		fle (i, 0, MAX) {
			if (adj[i].size() >= 2) {
				int lasty = -1, length = 0;
				for (auto & [v, w] : adj[i]) {
					if (v > lasty) {
						lasty = w;
						length += (w-v+1);
					}
				}
				if (length == n) {
					flag = 1;
				}
			}
		}
	} else flag = 1;

	if (flag) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}