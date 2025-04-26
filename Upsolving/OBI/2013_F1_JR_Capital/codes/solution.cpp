#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A1, A2, A3, A4;
    cin >> A1 >> A2 >> A3 >> A4;

    if (A1*A2 == A3*A4 or A1*A3 == A2*A4 or A1*A4 == A3*A2)
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
