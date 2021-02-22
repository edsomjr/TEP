#include <bits/stdc++.h>

using namespace std;

int LSB(int n) { return n & -n; }
int CLSB(int n) { return n & (n - 1); }

int bit_count(int n)
{
    int count = 0;

    while (n)
    {
        ++count;
        n &= (n - 1);
    }

    return count;
}

int main()
{
    int n = 14;

    cout << LSB(n) << '\n';         // 2
    cout << CLSB(n) << '\n';        // 12

    cout << bit_count(n) << '\n';   // 3
}
