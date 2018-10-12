#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int X, Y;

    while (cin >> X >> Y, X != -1 and Y != -1)
    {
        cout << X + Y << endl;
    }

    return 0;
}
