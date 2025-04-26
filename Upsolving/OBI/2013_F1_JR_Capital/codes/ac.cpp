#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A[4];

    for (int i = 0; i < 4; ++i)
        cin >> A[i];

    sort(A, A + 4);

    cout << (A[0]*A[3] == A[1]*A[2] ? 'S' : 'N') << '\n';

    return 0;
}
