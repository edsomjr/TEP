#include <bits/stdc++.h>

using namespace std;

int solve(int n)
{
    int x = 1, ans = 1;

    while (x % n)
    {
        x = (10*x + 1) % n;
        ans++;
    }

    return ans;
}

int main()
{
	int n;

	while (cin >> n)
	{
		cout << solve(n) << endl;
	}

	return 0;
}

