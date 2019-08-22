#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S = "bananada", P = "ana";

    auto x = S.find(P);         // x = 1

    x = S.find(P, 2);           // x = 3
    x = S.find(P, 4);           // x = npos

    x = S.rfind(P);             // x = 3

    return 0;
}

