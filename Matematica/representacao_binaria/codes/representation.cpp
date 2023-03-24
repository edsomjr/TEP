#include <bits/stdc++.h>

using namespace std;

const string digits { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

string representation(int n, int b)
{
    string rep;

    do {
        rep.push_back(digits[n % b]);
        n /= b;
    } while (n);

    reverse(rep.begin(), rep.end());

    return rep;
}

int main()
{
    int n, base;

    // 2 <= base <= 36
    cin >> n >> base;

    cout << representation(n, base) << '\n';

    return 0;
}
