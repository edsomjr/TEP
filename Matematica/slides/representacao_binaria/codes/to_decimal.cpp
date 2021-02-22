#include <bits/stdc++.h>

using namespace std;

const string digits { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

long long to_decimal(const string& rep, long long base)
{
    long long n = 0;

    for (auto c : rep)
    {
        n *= base;
        n += digits.find(c);
    }

    return n;
}

int main()
{
    ios::sync_with_stdio(false);

    string rep;
    int base;

    cin >> rep >> base;

    cout << rep << " (base " << base << ") -> " << to_decimal(rep, base) << '\n';

    return 0;
}
