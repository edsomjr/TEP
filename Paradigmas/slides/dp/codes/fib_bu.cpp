#include <bits/stdc++.h>

using namespace std;

const int MAX { 200010 };
long long fib[MAX];

void precomp()
{
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < MAX; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
}

long long F(int N)
{
    return fib[N];
}

int main()
{
    ios::sync_with_stdio(false);
    precomp();

    int N;
    cin >> N;

    cout << F(N) << endl;

    return 0;
}
